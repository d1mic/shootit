#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "hoop.h"



const static float PI = 3.141592653589793;
static int animation_active;
static float rotation_speed;
static float x_curr;
static float y_curr;
static float v_x;
static float v_y;
static float time;
static float hoop_position;

static float angle = 45;
static const float g = 0.5;
static int backboardFlag;


/* Callback functions */ 

static void on_keyboard(unsigned char key, int mouse_x,int mouse_y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void on_display(void);
static void on_mouse(int button, int state,int x, int y);


int main(int argc , char **argv){
    

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("ShootIT");
    
    hoop_position = -50;
    x_curr = 10;
    y_curr = 0;
    time = 0;
    
    
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(on_keyboard);
    glutMouseFunc(on_mouse);
    
   
    
    glClearColor(1,1,1,0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    
    return 0;
}

static void on_reshape(int width, int height){
    
    /* Setting up viewPort */
    glViewport(0,0,width,height);
    
   
    /* Setting up Projection matrix,itentity matrix for multiplication, pyramid */
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(float)width/height, 1, 120);
    
    
    
}

static void on_display(void){
    
    /* Clear buffers */ 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    float ball_rotation = 0;
    
    /* Initialize Modlview and LookAt */

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,100,0,0,0,0,1,0);
    
    
    /* Basketball */
    
    
    ball_rotation = 10 * rotation_speed;
    
    glPushMatrix();
        glTranslatef(x_curr, y_curr, 0);
        glRotatef(ball_rotation,0,0,1);
        glColor3f(1, 0.5, 0);
        glutSolidSphere(3,10,10);
    glPopMatrix();
    

    /* draw hoop */
    glTranslatef(-50,-10,0); 
    draw_hoop();

    glutSwapBuffers();
    


    
}
static void on_timer(int value){
    
    if(value!=0){
        return;
    }
    
    /* Update rotation */
    rotation_speed += 5;

    /* update coordinates of ball */
    
    time += 0.75;
    float angleDeg = 45* PI /180.0;
    
    if(!backboardFlag){
        v_x = (-4 * cos(angleDeg));
    }
    else{
        v_x = (4 * cos(angleDeg));
    }
        
    v_y =  (7 * sin(angleDeg) - g*time);
    
    x_curr += v_x;
    y_curr += v_y;
    
    if(x_curr <= hoop_position+5 && y_curr > 0 && y_curr < 20){
       backboardFlag = 1;
       printf("%f" , y_curr);
    }
    
    glutPostRedisplay();
    
    if(animation_active){
        glutTimerFunc(60,on_timer,0);
    }
    
    
}

static void on_keyboard(unsigned char key, int mouse_x, int mouse_y ){
    

    switch(key){
        case 'a':
        case 'A':
            if(!animation_active){
                animation_active = 1;
                backboardFlag = 0;
                glutTimerFunc(60,on_timer,0);
            }
            break;
        case 's':
            animation_active = 0;
            break;
        
        case 27:
            exit(0);
            break;
        
    }
    
}


static void on_mouse(int button, int state,int x, int y){
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){
              
                glutTimerFunc(60,on_timer,0);

            }
        break;



            
    }
}
