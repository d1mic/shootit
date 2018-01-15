#include "light.h"

/* Seting up light */
void setUpLight(int lightSwitch){
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    
    GLfloat ambient_light[] = {0.45,0.45,0.45};
    GLfloat difuse_light[] = {0.7,0.7,0.7};
    GLfloat specular_light[] = {0.8,0.8,0.8};
    
    if(!lightSwitch){
        GLfloat light_position[] = {50,0,50,0};
        glLightfv(GL_LIGHT0 , GL_POSITION, light_position);
    }
    
    glLightfv(GL_LIGHT0 , GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0 , GL_DIFFUSE, difuse_light);
    glLightfv(GL_LIGHT0 , GL_SPECULAR, specular_light);
}

/* Function for turning headlight on */
void headLightOn(int lightSwitch){
    if(lightSwitch){
        GLfloat light_position[] = {100,0,0,1};
        glLightfv(GL_LIGHT0 , GL_POSITION, light_position);
    }
}
