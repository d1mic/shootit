#ifndef BALL_H
#define BALL_H
#define PI 3.141592653589793
#define BASKET_BALL 1
#define BOWLING_BALL 2
#define VOLLEY_BALL 3
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>

float x_curr;
float y_curr;
float ball_rotation;
int ballType;
float v_x;
float v_y;
int backboardFlag;

void initBallPosition();
void draw_ball(float x_curr,float y_curr, float ball_rotation);
void updateBallPosition(float time,float angle);
void setBackboardFlag(int b);
int checkBackboardCollision();
int checkFloorCollision();

#endif

