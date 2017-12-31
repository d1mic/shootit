#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "ball.h"

void initBallPosition(){
    
    if( rand()/(float)RAND_MAX <= 0.66){
        ballType = BASKET_BALL;
    }
    else{
        ballType = BOWLING_BALL;
    }
    
    x_curr = rand()/(float)RAND_MAX * 60.0  - 20.0;
    y_curr = rand()/(float)RAND_MAX * 60  - 30.0;
}

void draw_ball(float x_curr , float y_curr,float ball_rotation){
    
    glPushMatrix();
    
        if(ballType == BASKET_BALL){
            glColor3f(1, 0.5, 0);
        }
        else if(ballType == BOWLING_BALL){
            glColor3f(0, 0, 0);
        }
    
        glTranslatef(x_curr, y_curr, 0);
        glRotatef(ball_rotation,0,0,1);
        glutSolidSphere(3,10,10);
    glPopMatrix();
    
    
}

void updateBallPosition(float time,float angle){
    
        
    float angleDeg = angle* PI /180.0;
    float v0_x,v0_y;
    
    if(ballType == BASKET_BALL){
        v0_x = -4;
        v0_y =  7;
    }
    else if(ballType == BOWLING_BALL){
        v0_x = -3;
        v0_y = 6;
    }

    
    v_x =  (v0_x * cos(angleDeg));
    v_y =  (v0_y * sin(angleDeg) - 0.5*time);
    
    if(backboardFlag){
        v_x *= -1;
    }
    x_curr += v_x;
    y_curr += v_y;    
}

void setBackboardFlag(int b){
    backboardFlag = b;
}
