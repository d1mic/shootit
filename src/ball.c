#include "ball.h"

/* Intialize new random position of the ball on the field and random ball type */
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

/* Draw the ball and set up material for ball */
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

/* Ball movement  */
void updateBallPosition(float time,float angle, float ball_strength){
    
        
    float angleDeg = angle* PI /180.0;
    float v0_x,v0_y;
    
    if(ballType == BASKET_BALL){
        v0_x =   ball_strength * -3.5;
        v0_y =  ball_strength * 7;
    }
    else if(ballType == BOWLING_BALL){
        v0_x = ball_strength * -2.75;
        v0_y = ball_strength * 5.5;
     }

    
    v_x =  (v0_x * cos(angleDeg));
    v_y =  (v0_y * sin(angleDeg) - 0.5*time);
    
    if(backboardFlag){
        v_x *= -1;
    }
    x_curr += v_x;
    y_curr += v_y;    
}

/* Setting up flag for colliding with the backboard */
void setBackboardFlag(int b){
    backboardFlag = b;
}

/* Checking collision with the backboard */
int checkBackboardCollision(){
    if(x_curr >= -55 && x_curr <= -45 && y_curr > 3 && y_curr < 25)
        return 1;
    else 
        return 0;
}

/* Checking collision with the floor */
int checkFloorCollision(){
    if(y_curr <= -40)
        return 1;
    else 
        return 0;
}
/* Drawing shot assistance balls, depending on angle and strength of the shot */
void drawShootAssistance(float ball_strength, float angle){
    glPushMatrix();
    
        GLfloat ShadowBallAmbiental[] = {0.9,0.9,0.9};
        GLfloat ShadowBallDiffuse[] = {0.7,0.7,0.7};
        GLfloat ShadowBallSpecular[] = {0.0,0.0,0.0};
        GLfloat shadow_shiness_ball = 10;
    
    
        glMaterialfv(GL_FRONT,GL_AMBIENT,ShadowBallAmbiental);
        glMaterialfv(GL_FRONT,GL_SPECULAR,ShadowBallDiffuse);
        glMaterialfv(GL_FRONT,GL_DIFFUSE,ShadowBallSpecular);
        glMaterialf(GL_FRONT,GL_SHININESS,shadow_shiness_ball);
        
        glTranslatef(x_curr,y_curr,0);
        glRotatef(90-angle,0,0,1);
        glTranslatef(0,5,0);
        glPushMatrix();
            int shadowNum = (int)(ball_strength*10 -5)/2;
            glutSolidSphere(1,50,50);
            
            for(int i = 0; i < shadowNum; i++ ){
                glTranslatef(0,3,0);
                glutSolidSphere(1,50,50);
            }
        glPopMatrix();
    glPopMatrix();
    
}
