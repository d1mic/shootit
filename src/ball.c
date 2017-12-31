#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "ball.h"

void initBallPosition(){
    x_curr = rand()/(float)RAND_MAX * 60.0  - 20.0;
    y_curr = rand()/(float)RAND_MAX * 60  - 30.0;
}

void draw_ball(float x_curr , float y_curr,float ball_rotation){
    
    
    glPushMatrix();
        glTranslatef(x_curr, y_curr, 0);
        glRotatef(ball_rotation,0,0,1);
        glColor3f(1, 0.5, 0);
        glutSolidSphere(3,10,10);
    glPopMatrix();
    
    
}

void updateBallPosition(float time,float angle){
    
        
    float angleDeg = angle* PI /180.0;
    
    
    v_x =  (-4 * cos(angleDeg));
    v_y =  (7 * sin(angleDeg) - 0.5*time);
    
    if(backboardFlag){
        v_x *= -1;
    }
    x_curr += v_x;
    y_curr += v_y;    
}

void setBackboardFlag(int b){
    backboardFlag = b;
}
