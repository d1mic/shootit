#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "hoop.h"
#include "ball.h"
#include "field.h"
#include "numbers.h"


static int animation_active;
static float rotation_speed;
static const float g = 0.5;
static float timePassed;
static float angle;
static float lookAngle;
static float lightSwitch;
static time_t now;


/* Callback functions */ 

static void on_keyboard(unsigned char key, int mouse_x,int mouse_y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void on_display(void);
static void on_restart(void);
static void setUpLight(void);
static void on_timer2(int value);


int main(int argc , char **argv){
    

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("ShootIT");
    
    lookAngle = 90 * PI/180;
    lightSwitch = 0;
    now = time(NULL);
    srand(time(NULL));    
    on_restart();
    
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutTimerFunc(30,on_timer2,1);
    glutKeyboardFunc(on_keyboard);
    

    glClearColor(1,1,1,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
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
    
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    /*glEnable(GL_COLOR_MATERIAL);*/
    glShadeModel(GL_SMOOTH);
    glLineWidth(5);

    /* Initialize Modlview and LookAt */
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
        
    if(lightSwitch){
        GLfloat light_position[] = {70,0,0,1};
        glLightfv(GL_LIGHT0 , GL_POSITION, light_position);
    }
    gluLookAt(100*cos(lookAngle),0,100*sin(lookAngle),0,0,0,0,1,0);
    

    /* Seting up light */
    setUpLight();
    
    /* draw time */
    drawSemaphore(now,5);
    
    /* Field */
    draw_field();
    
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
    
    
    
    /* TODO: implement beter collision for rim */
    if(x_curr >= -50 && x_curr <= -40 && y_curr <= 15 && y_curr >= 8){
        angle = 90;
       /* printf("(%f, %f)" , x_curr, y_curr);*/
    } 
    
    

    
    /* check backboard collision */
    if(x_curr >= -55 && x_curr <= -45 && y_curr > 3 && y_curr < 25){
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
        case 32:
            if(!animation_active){
                animation_active = 1;
                glutTimerFunc(60,on_timer,0);
            }
            break;
        case 'p':
        case 'P':
            animation_active = 0;
            break;
        case 'R' :
        case 'r' :
            on_restart();
            break;
        case 'w':
        case 'W':
            if(!animation_active){
                angle+=3;
                if(angle > 89){
                    angle = 89;
                }
            }
            break;
        case 's':
        case 'S':
            if(!animation_active){
                
                angle-=3;
                if(angle < -89){
                    angle = -89;
                }
            }
            break;
        case 'd':
        case 'D':
            lookAngle += (5 * PI/180);
            glutPostRedisplay();
            break;
        case 'a':
        case 'A':
            lookAngle -= (5 * PI/180);
            glutPostRedisplay();
            break;
        case 'l':
        case 'L':
            lightSwitch = lightSwitch? 0 : 1;  
            glutPostRedisplay();
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



static void setUpLight(void){
    
     /* Seting up light */
    
    GLfloat ambient_light[] = {0.45,0.45,0.45};
    GLfloat difuse_light[] = {0.7,0.7,0.7};
    GLfloat specular_light[] = {0.8,0.8,0.8};
    
    if(!lightSwitch){
        GLfloat light_position[] = {50,0,50,0};
        glLightfv(GL_LIGHT0 , GL_POSITION, light_position);
    }
    
    glLightfv(GL_LIGHT0 , GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0 , GL_DIFFUSE, difuse_light);
    glLightfv(GL_LIGHT0 , GL_SPECULAR, specular_light);
}



static void on_timer2(int value){
    
    if(value != 1)
        return;
    glutPostRedisplay();
    glutTimerFunc(60,on_timer2,1);
}
