#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hoop.h"
#include "ball.h"

static int animation_active;
static float rotation_speed;
static const float g = 0.5;
static float time;
static float hoop_position;


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
    
    setBackboardFlag(0);
    initBallPosition(1,-20);
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
    

    /* Initialize Modlview and LookAt */

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,100,0,0,0,0,1,0);
    
    
    
    
    /* Basketball */
    
    draw_ball(x_curr , y_curr ,rotation_speed);
    
    
    
    /* draw hoop */
    glTranslatef(-50,-10,0); 
    draw_hoop();

    glutSwapBuffers();
    


    
}
static void on_timer(int value){
    
    if(value!=0){
        return;
    }
    

    /* update coordinates of ball */
    rotation_speed += 30;
    time += 0.65;
    updateBallPosition(time);
    
    
    /* check backboard collision */
    
    if(x_curr <= hoop_position+5 && y_curr > 0 && y_curr < 20){
       setBackboardFlag(1);
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
