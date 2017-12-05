#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "hoop.h"



void draw_hoop(void){

	/* ring */
	glPushMatrix();
        glTranslatef(6,20,0);
        glRotatef(90,1,0,0);
        glColor3f(0,0,0);
        glutSolidTorus(0.5,5,10,10);
    glPopMatrix();

    /* tabla */
    glPushMatrix();
        glTranslatef(0,24,0);
        glScalef(2,19,19);
        glColor3f(0.753,0.753,0.753);
        glutSolidCube(1);
    glPopMatrix();
    
    /* bar 1*/
    glPushMatrix();
        glTranslatef(-10,0,6);
        glScalef(1,3*16,4);
        glColor3f(0.412,0.412,0.412);
        glutSolidCube(1);
    glPopMatrix();

    /* bar 2*/
    glPushMatrix();
        glTranslatef(-10,0,-6);
        glScalef(1,3*16,4);
        glColor3f(0.412,0.412,0.412);
        glutSolidCube(1);
    glPopMatrix();

    /* small bar 1 */
   glPushMatrix();
        glTranslatef(-5,24,6);
        glRotatef(90,0,0,1);
        glScalef(1,10,4);
        glColor3f(0.412,0.412,0.412);
        glutSolidCube(1);
    glPopMatrix();

    /* small bar 2 */
     glPushMatrix();
        glTranslatef(-5,24,-6);
        glRotatef(90,0,0,1);
        glScalef(1,10,4);
        glColor3f(0.412,0.412,0.412);
        glutSolidCube(1);
    glPopMatrix();





}