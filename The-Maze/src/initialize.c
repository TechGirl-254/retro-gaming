#include "../headers/maze.h"
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

/**
* init - it initializes the game by creating the background color and setting player's postion
*
*/

void init()
{
 glClearColor(0.5,0.2,0.5,0);
 gluOrtho2D(0,1024,510,0);
 px=150; py=400; pa=90;
 pdx=cos(degToRad(pa)); pdy=-sin(degToRad(pa));                                 //init player
}
