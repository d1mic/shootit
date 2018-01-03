#include "numbers.h"


void drawNum(int number, float size){
    
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0,0,1);
    glPushMatrix();
        glBegin(GL_LINE_STRIP);
        
        
            /* drawing numbers is done this way:
             * 
             * (0,s)   *------* (s/2,s)
             *         |      |
             * (0,s/2) *------* (s/2,s/2)
             *         |      |
             * (0,s/2) *------* (s/2,0)
             * 
             * then you pick the dots that are needed for the number
            */
        
            switch(number){
                
                case 1:
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size,0);
                    break;
                case 2:
                    glVertex3f(size/2,0,0);
                    glVertex3f(0,0,0);
                    glVertex3f(0,size/2,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(size/2,size,0);
                    glVertex3f(0,size,0);
                    break;
                case 3:
                    glVertex3f(0,0,0);
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(0,size/2,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(size/2,size,0);
                    glVertex3f(0,size,0);
                    break;
                case 4:
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(0,size/2,0);
                    glVertex3f(0,size,0);
                    break;
                case 5:
                    glVertex3f(0,0,0);
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(0,size/2,0);
                    glVertex3f(0,size,0);
                    glVertex3f(size/2,size,0);
                    break;
                case 6:
                    glVertex3f(0,size/2,0);
                    glVertex3f(0,0,0);
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(0,size/2,0);
                    glVertex3f(0,size,0);
                    glVertex3f(size/2,size,0);
                    break;
                 case 7:
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(size/2,size,0);
                    glVertex3f(0,size,0);
                    break;
                case 8:
                    glVertex3f(0,size/2,0);
                    glVertex3f(0,0,0);
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(0,size/2,0);
                    glVertex3f(0,size,0);
                    glVertex3f(size/2,size,0);
                    glVertex3f(size/2,size/2,0);
                    break;
                case 9:
                    glVertex3f(0,0,0);
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size/2,0);
                    glVertex3f(0,size/2,0);
                    glVertex3f(0,size,0);
                    glVertex3f(size/2,size,0);
                    glVertex3f(size/2,size/2,0);
                   break;
                case 0:
                    glVertex3f(0,0,0);
                    glVertex3f(size/2,0,0);
                    glVertex3f(size/2,size,0);
                    glVertex3f(0,size,0); 
                    glVertex3f(0,0,0);
                    
                   break;
                    
                
                
            }
        
            
        glEnd();
    glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);
    
}
/* too slow 
void drawNumbers(int number , float size){
    
    glPushMatrix();
    int num;
    while(number > 0){
        num = number%10;
        glTranslatef(-4,0,0);
        drawNum(num,size);
        number = number/10;
    }
    glPopMatrix();
}
*/
void drawNumbers(int number , float size){
    
    glPushMatrix();
        drawNum(number/10,size);
        glTranslatef(size-1,0,0);
        drawNum(number%10,size);
    glPopMatrix();
}

void drawTime(time_t start,float size){
    
    time_t current_time = time(NULL);
    time_t passed_time = difftime(current_time,start);
    struct tm *info = localtime(&passed_time);
    
    int counter = 90 - 60*info->tm_min - info->tm_sec;
    if(counter < 0){
        timeUp = 0;
        counter = 0;
    }
    else{
        timeUp = 1;
    }
    
    drawNumbers(counter,size);
    
    
}

void drawSemaphore(time_t start,float size){
    glPushMatrix();
        
        GLfloat tableAmbient[] = {0.8,0.8,0.8,1};
        GLfloat tableDiffuse[] = {0.7,0.7,0.7,1};
        GLfloat tableSpecular[] = {1,1,1,1};
        GLfloat shiness_table = 40;
        
        glMaterialfv(GL_FRONT,GL_AMBIENT,tableAmbient);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,tableDiffuse);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,tableSpecular);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiness_table);
        
        glTranslatef(0,40,-20);
        glPushMatrix();
          glScalef(1,0.6,1);
          glutSolidCube(4*size-1);
        glPopMatrix();
        
        
        /* left timer */
        glPushMatrix();
            glRotatef(90,0,1,0);
            glScalef(-1,1,1);
            glTranslatef(-size/1.5,-size/2,-size*2);
            drawTime(start,size);
        glPopMatrix();
        
        /* right timer */
        glPushMatrix();
            glRotatef(90,0,1,0);
            glTranslatef(-size/1.5,-size/2,size*2);
            drawTime(start,size);
        glPopMatrix();
        
        
        /* back timer */
        glPushMatrix();
            glScalef(-1,1,1);
            glTranslatef(-size/1.5,-size/2,-size*2);
            drawTime(start,size);
        glPopMatrix();
        
        /* front timer */
        glPushMatrix();
            glTranslatef(-size/1.5,-size/2,size*2);
            drawTime(start,size);
        glPopMatrix();
    
    
    glPopMatrix();
}

