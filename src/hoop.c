#include "hoop.h"


void draw_hoop(void){
    glPushMatrix();
    
    /* set hoop position */
    glTranslatef(-50,-10,0);
    
	/* ring */
	glPushMatrix();
        hoopMaterialSetup("ring");
        
        glTranslatef(6,20,0);
        glRotatef(90,1,0,0);
        glutSolidTorus(0.5,5,10,10);
    glPopMatrix();

    /* table */
    glPushMatrix();
    
        hoopMaterialSetup("table");
    
        glTranslatef(0,24,0);
        glScalef(2,19,19);
        glutSolidCube(1);
    glPopMatrix();
    
    /* bar 1*/
    glPushMatrix();
        hoopMaterialSetup("bars");
        
        glTranslatef(-10,0,6);
        glScalef(1,3*16,4);
        glutSolidCube(1);
    glPopMatrix();

    /* bar 2*/
    glPushMatrix();
        hoopMaterialSetup("bars");
        
        glTranslatef(-10,0,-6);
        glScalef(1,3*16,4);
        glutSolidCube(1);
    glPopMatrix();

    /* small bar 1 */
   glPushMatrix();
   
        hoopMaterialSetup("bars");
        
        glTranslatef(-5,24,6);
        glRotatef(90,0,0,1);
        glScalef(1,10,4);
        glutSolidCube(1);
    glPopMatrix();

    /* small bar 2 */
     glPushMatrix();
     
        hoopMaterialSetup("bars");
     
        glTranslatef(-5,24,-6);
        glRotatef(90,0,0,1);
        glScalef(1,10,4);
        glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();
}

void hoopMaterialSetup(char *name){
    
    
    GLfloat tableAmbient[] = {1,1,1,1};
    GLfloat tableDiffuse[] = {0.9,0.9,0.9,1};
    GLfloat tableSpecular[] = {0.8,0.8,0.8,1};
    GLfloat shiness_table = 40;
   
    GLfloat hoopAmbient[] = {0,0,0,1};
    GLfloat hoopDiffuse[] = {0.5,0.5,0.5,1};
    GLfloat hoopSpecular[] = {0,0,0,1};
    GLfloat shiness_hoop = 20;
    
    
    if(strcmp(name,"table") == 0){
        glMaterialfv(GL_FRONT,GL_AMBIENT,tableAmbient);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,tableDiffuse);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,tableSpecular);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiness_table);
        
    }
    else{
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,hoopAmbient);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,hoopDiffuse);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,hoopSpecular);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiness_hoop);
        
    }
        
   
    
}
