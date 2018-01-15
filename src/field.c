#include "field.h"


#define PI 3.141592653589793

/* Draw the whole field */
void draw_field(void){
    
    glPushMatrix();
        draw_lines(7);
        draw_floor();
    glPopMatrix();
}


/* Floor drawing */
void draw_floor(void){
    glPushMatrix();
        fieldMaterialSetup();
        glTranslatef(10,-40,0);
        glRotatef(90,1,0,0);
        glScalef(2.5,2.5,0.1);
        glutSolidCube(70);
    glPopMatrix();
}

/* Seting up field material */
void fieldMaterialSetup(){

    GLfloat fieldAmbient[] = {0.913,0.71,0.51,1};
    GLfloat fieldDiffuse[] = {0.1,0.1,0.1,1};
    GLfloat fieldSpecular[] = {0,0,0,1};
    GLfloat shiness_field = 20;
   
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,fieldAmbient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,fieldDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,fieldSpecular);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiness_field);
        
    
}
/* Drawing lines on the field */
void draw_lines(float r){
    
glDisable(GL_LIGHTING);
glPushMatrix();
    
    float i;
    glColor3f(0.9,0.9,0.9);
  
    glTranslatef(-20,-36,0);
    glRotatef(90,0,1,0); 
    glScalef(3,0,3);
    
    /*three point half circle */
     glBegin(GL_LINE_STRIP);
        for(i = 0 ; i <=  PI + 0.01 ; i+= PI/100){ 
            glVertex3f(3.2*r*cos(i) ,0,  3.2*r*sin(i));
        }
    glEnd();
    
    /* three point lines */
    glBegin(GL_LINES);
            glVertex3f(-3.2*r,0,-(r+5));
            glVertex3f(-3.2*r,0,0);
            glVertex3f(3.2*r,0,-(r+5));
            glVertex3f(3.2*r,0,0);
    glEnd();
    
    /* draw inbound lines */
    glBegin(GL_LINES);
            glVertex3f(-4.1*r,0,-(r+5));
            glVertex3f(4.1*r,0,-(r+5));
    glEnd();
    
    
    /*lines for freethrow */
    glBegin(GL_LINES);
            glVertex3f(-r,0,-(r+5));
            glVertex3f(-r,0,5);
            glVertex3f(r,0,-(r+5));
            glVertex3f(r,0,5);
    glEnd();
    
    glTranslatef(0,0,5);
    /*half circle for freethrow */
    glBegin(GL_LINE_LOOP);
        for(i = 0 ; i <= PI + 0.01 ; i+= PI/100){ 
            glVertex3f(r*cos(i) ,0,  r*sin(i));
        }
    glEnd();
    
glEnable(GL_LIGHTING);
glPopMatrix();
}


