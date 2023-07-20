#include "../headers/maze.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

/**
*resize - fixes the angle of the rays relative to the player
*
*@w: int value for the desired screen width size
*@h: int value for the desired screen width size
*
*/

void resize(int w,int h)                                        /*screen window rescaled, snap back*/
{
 glutReshapeWindow(1024,512);
}
