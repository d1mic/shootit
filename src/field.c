#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <GL/glut.h>
#include "field.h"


#define PI 3.141592653589793

void draw_field(void){
    
    
    glPushMatrix();
    
        draw_freethrow(7);
    
        draw_floor();
        
        
    glPopMatrix();
}

void draw_floor(){
    glPushMatrix();
    
        fieldMaterialSetup();
        glTranslatef(10,-40,0);
        glRotatef(90,1,0,0);
        glScalef(2.5,2.5,0.1);
        glutSolidCube(70);
        
        
    glPopMatrix();
}


void fieldMaterialSetup(){
    
    GLfloat fieldAmbient[] = {0.913,0.71,0.51,1};
    GLfloat fieldDiffuse[] = {0.913,0.71,0.51,1};
    GLfloat fieldSpecular[] = {0.3,0.3,0.3,1};
    GLfloat shiness_field = 40;
   
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,fieldAmbient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,fieldDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,fieldSpecular);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiness_field);
        
    
}

void draw_freethrow(float r){
    
    glEnable(GL_COLOR_MATERIAL);
    float i;
    glPushMatrix();
    glColor3f(1,1,1);
  
    glTranslatef(-20,-35,0);
    glRotatef(90,0,1,0); 
    glScalef(3,0,3);
    
    glBegin(GL_LINES);
            glVertex3f(-r,0,-(r+5));
            glVertex3f(-r,0,0);
            glVertex3f(r,0,-(r+5));
            glVertex3f(r,0,0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
        for(i = 0 ; i <= PI + 0.01 ; i+= PI/100){ 
            glVertex3f(r*cos(i) ,0,  r*sin(i));
        }
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
}


