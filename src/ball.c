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

    GLfloat BasketballAmbiental[] = {0.9,0.45,0};
    GLfloat BasketballDiffuse[] = {1,0.5,0.1};
    GLfloat BasketballSpecular[] = {0.4,0.4,0.4};
    
    
    GLfloat BowlingballAmbiental[] = {0.6,0.6,0.6};
    GLfloat BowlingballDiffuse[] = {0.1,0.1,0.1};
    GLfloat BowlingballSpecular[] = {0.4,0.4,0.4};
    

    GLfloat shiness_ball = 20;
    
    glPushMatrix();
        
        if(ballType == BASKET_BALL){
            glMaterialfv(GL_FRONT,GL_AMBIENT,BasketballAmbiental);
            glMaterialfv(GL_FRONT,GL_SPECULAR,BasketballSpecular);
            glMaterialfv(GL_FRONT,GL_DIFFUSE,BasketballDiffuse);
            glMaterialf(GL_FRONT,GL_SHININESS,shiness_ball);
        }
        else if(ballType == BOWLING_BALL){
            glMaterialfv(GL_FRONT,GL_AMBIENT,BowlingballAmbiental);
            glMaterialfv(GL_FRONT,GL_SPECULAR,BowlingballSpecular);
            glMaterialfv(GL_FRONT,GL_DIFFUSE,BowlingballDiffuse);
            glMaterialf(GL_FRONT,GL_SHININESS,shiness_ball);
        }
        
        glTranslatef(x_curr, y_curr, 0);
        glRotatef(ball_rotation,0,0,1);
        glutSolidSphere(3,50,50);
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
        v0_x = -2.75;
        v0_y = 5.5;
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
