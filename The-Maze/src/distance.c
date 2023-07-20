#include "../headers/maze.h"
#include <stdlib.h>
#include <math.h>

/**
*distance - calculates the distance between the player and the wall
*
*@ax: player's x coordinate
*@ay: player's y coordinate
*@bx: wall's x coordinate
*@by: wall's y coordinate
*@ang: Angle of the ray
*
*Return: distance
*/

float distance(float ax,float ay,float bx,float by,float ang)
{
    return cos(degToRad(ang))*(bx-ax)-sin(degToRad(ang))*(by-ay);
}
