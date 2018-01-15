#ifndef NUMBERS_H
#define NUMBERS_H

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

/* End of game flag */
int timeUp;

/* Semaphore functions */
void drawNum(int number, float size);
void drawNumbers(int number , float size);
void drawTime(time_t start,float size);
void drawSemaphore(time_t start ,float size);
void drawScore(int score);
#endif
