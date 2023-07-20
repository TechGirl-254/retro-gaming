#include "../headers/maze.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

/**
* drawPlayer2D - draws a 2D map based on the values MapX and MapY
*
*/

void drawPlayer2D()
{
     glColor3f(1,1,0);   glPointSize(8);    glLineWidth(4);
     glBegin(GL_POINTS); glVertex2i(px,py); glEnd();
     glBegin(GL_LINES);  glVertex2i(px,py); glVertex2i(px+pdx*20,py+pdy*20); glEnd();
}
