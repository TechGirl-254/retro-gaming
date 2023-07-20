#include "../headers/maze.h"
#include <stdlib.h>
#include <math.h>

/**
*FixAng - fixes the angle of the rays relative to the player
*
*@a: a float argument
*
*Return: a fixed angle
*/

float FixAng(float a)
{
    if(a>359){ a-=360;}
    if(a<0){ a+=360;}
    return a;
}
