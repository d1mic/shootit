#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "hoop.h"
#include "ball.h"

static int animation_active;
static float rotation_speed;
static const float g = 0.5;
static float timePassed;
static float angle;

/* Callback functions */ 

static void on_keyboard(unsigned char key, int mouse_x,int mouse_y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void on_display(void);
static void on_mouse(int button, int state,int x, int y);
static void on_restart(void);


int main(int argc , char **argv){
    

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("ShootIT");
    
 
    
    
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(on_keyboard);
    glutMouseFunc(on_mouse);
    
    srand(time(NULL));
    
    on_restart();
   
    
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
    gluPerspective(60,(float)width/height, 1, 1200);
    
    
    
}

static void on_display(void){
    
    /* Clear buffers */ 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

    /* Initialize Modlview and LookAt */

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,100,0,0,0,0,1,0);
    
    /* Primitive field */
    glPushMatrix();
        glColor3f(0.8,0.4,0);
        glTranslatef(10,-38,0);
        glRotatef(89,1,0,0);
        glScalef(2.4,1,0.001);
        glutSolidCube(70);
    glPopMatrix();
    
    
    /* Basketball */
    draw_ball(x_curr , y_curr ,rotation_speed);
    
    
    /* draw hoop */
    glPushMatrix();
        glTranslatef(-50,-10,0); 
        draw_hoop();
    glPopMatrix();

    glutSwapBuffers();
    


    
}
static void on_timer(int value){
    
    if(value!=0){
        return;
    }
    

    /* update coordinates of ball */
    rotation_speed += 30;
    timePassed += 0.65;
    updateBallPosition(timePassed,angle);
    
    
    /* check backboard collision */
    
    if(x_curr >= -50 && x_curr <= -43 && y_curr > 3 && y_curr < 23){
       setBackboardFlag(1);
    }
    if(y_curr <= -40){
        on_restart();
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
        case 'S':
        case 's':
            animation_active = 0;
            break;
        case 'R' :
        case 'r' :
            on_restart();
            break;
        case '+':
            if(!animation_active){
                
                angle+=3;
                if(angle > 89){
                    angle = 89;
                }
            }
            break;
        case '-':
            if(!animation_active){
                
                angle-=3;
                if(angle < -89){
                    angle = -89;
                }
            }
            break;
        case 27:
            exit(0);
            break;
        
    }
    
}
static void on_restart(){
    animation_active = 0;
    timePassed = 0;
    angle = 45;
    setBackboardFlag(0);
    initBallPosition();
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
