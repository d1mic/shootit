#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

static int animation_active;
static float rotation_speed;
static float move_up;


/* Callback functions */ 

static void on_keyboard(unsigned char key, int mouse_x,int mouse_y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void on_display(void);




int main(int argc , char **argv){
    

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("ShootIT");
    
    
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(on_keyboard);
    /*glutTimerFunc(60,on_timer,0); */
    
    rotation_speed = 0;
    animation_active = 0;
    move_up = 0;
    
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
    
    
    
    float ball_rotation = 0;
    
    /* Initialize Modlview and LookAt */

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,1000,0,0,0,0,1,0);
    
    
    /* Basketball */
            
    
    ball_rotation = 30 * rotation_speed;
    
    glTranslatef(0,move_up,0);
    
    glPushMatrix();
        glColor3f(1, 0.5, 0);
        glRotatef(ball_rotation,0,0,1);
        glutWireSphere(100,10,10);
    glPopMatrix();
    
    
    
    glutSwapBuffers();
    
}
static void on_timer(int value){
    
    if(value!=0){
        return;
    }
    
    /* Update rotation */
    rotation_speed += 5;
    
    /* move up */
    move_up += 5;
    
    
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
