#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "hoop.h"
#include "ball.h"
#include "field.h"
#include "numbers.h"
#include "light.h"


static int animation_active;
static float rotation_speed;
static const float g = 0.5;
static float timePassed;
static float angle;
static float lookAngle;
static float lightSwitch;
static time_t initial_time;
static int score;
static int scoreFlag;

/* Callback functions */ 

static void on_keyboard(unsigned char key, int mouse_x,int mouse_y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void on_timer2(int value);
static void on_display(void);
static void init(void);
static void restart(void);


int main(int argc , char **argv){
    

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("ShootIT");
    
    init();
    
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
    
    glLineWidth(5);

    /* Initialize Modlview and LookAt */
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
        
    headLightOn(lightSwitch);
    gluLookAt(100*cos(lookAngle),0,100*sin(lookAngle),0,0,0,0,1,0);

    /* Seting up light */
    setUpLight(lightSwitch);
    
    /* Drawing objects */
    
    drawSemaphore(initial_time,5);
    draw_field();
    draw_ball(x_curr , y_curr ,rotation_speed);
    draw_hoop();
    
    glTranslatef(-48,25,3);
    glRotatef(90,0,1,0);
    drawNumbers(score,5);

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
        scoreFlag = 1;
       /* printf("(%f, %f)" , x_curr, y_curr);*/
    } 

    
    /* check backboard collision */
    if(x_curr >= -55 && x_curr <= -45 && y_curr > 3 && y_curr < 25){
       setBackboardFlag(1);
    }
    if(y_curr <= -40){
        restart();
        
        if(scoreFlag && timeUp){
            score++;
            scoreFlag = 0;
        }
    }
    
    glutPostRedisplay();
    
    if(animation_active){
        glutTimerFunc(60,on_timer,0);
    }
    
    
}

static void on_timer2(int value){
    
    if(value != 1)
        return;
    if(timeUp){
        glutPostRedisplay();
        glutTimerFunc(60,on_timer2,1);
    }
}
static void init(){
    score = 0;
    scoreFlag =0;
    lookAngle = 90 * PI/180;
    lightSwitch = 0;
    initial_time = time(NULL);
    srand(time(NULL));    
    restart();
}
static void restart(){
    animation_active = 0;
    timePassed = 0;
    angle = 45;
    setBackboardFlag(0);
    initBallPosition();
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
            restart();
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




