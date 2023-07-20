#include "../headers/maze.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

/**
* display - creates the game's display
*
*/

ButtonKeys Keys;

void display()
{
     /*frames per second*/
     frame2=glutGet(GLUT_ELAPSED_TIME); fps=(frame2-frame1); frame1=glutGet(GLUT_ELAPSED_TIME);

     /*buttons*/
     if(Keys.a==1){ pa+=0.2*fps; pa=FixAng(pa); pdx=cos(degToRad(pa)); pdy=-sin(degToRad(pa));}
     if(Keys.d==1){ pa-=0.2*fps; pa=FixAng(pa); pdx=cos(degToRad(pa)); pdy=-sin(degToRad(pa));}

     int xo=0; if(pdx<0){ xo=-20;} else{ xo=20;}                                    /*x offset to check map*/
     int yo=0; if(pdy<0){ yo=-20;} else{ yo=20;}                                    /*y offset to check map*/
     int ipx=px/64.0, ipx_add_xo=(px+xo)/64.0, ipx_sub_xo=(px-xo)/64.0;             /*x position and offset*/
     int ipy=py/64.0, ipy_add_yo=(py+yo)/64.0, ipy_sub_yo=(py-yo)/64.0;             /*y position and offset*/
     if(Keys.w==1)                                                                  /*move forward*/
     {
          if(mapW[ipy*mapX        + ipx_add_xo]==0){ px+=pdx*0.2*fps;}
          if(mapW[ipy_add_yo*mapX + ipx       ]==0){ py+=pdy*0.2*fps;}
     }
     if(Keys.s==1)                                                                  /*move backward*/
     {
          if(mapW[ipy*mapX        + ipx_sub_xo]==0){ px-=pdx*0.2*fps;}
          if(mapW[ipy_sub_yo*mapX + ipx       ]==0){ py-=pdy*0.2*fps;}
     }

     glutPostRedisplay();

     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     drawMap2D();
     drawPlayer2D();
     drawRays2D();
     glutSwapBuffers();
}
