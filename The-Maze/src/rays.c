#include "../headers/maze.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

/**
* drawRays2D - draws rays, and uses them to draw walls, floors and the ceiling.
*
*/

void drawRays2D()
{
 glColor3f(0,1,1); glBegin(GL_QUADS); glVertex2i(526,  0); glVertex2i(1006,  0); glVertex2i(1006,160); glVertex2i(526,160); glEnd();
 glColor3f(0,0,1); glBegin(GL_QUADS); glVertex2i(526,160); glVertex2i(1006,160); glVertex2i(1006,320); glVertex2i(526,320); glEnd();

 int r,mx,my,mp,dof,side; float vx,vy,rx,ry,ra,xo,yo,disV,disH;

 ra=FixAng(pa+30);                                                              /*ray set back 30 degrees*/

 for(r=0;r<60;r++)
 {
  int vmt=0,hmt=0;                                                              /*vertical and horizontal map texture number*/
  /*---Vertical---*/
  dof=0; side=0; disV=100000;
  float Tan=tan(degToRad(ra));
       if(cos(degToRad(ra))> 0.001){ rx=(((int)px>>6)<<6)+64;      ry=(px-rx)*Tan+py; xo= 64; yo=-xo*Tan;}/*looking left*/
  else if(cos(degToRad(ra))<-0.001){ rx=(((int)px>>6)<<6) -0.0001; ry=(px-rx)*Tan+py; xo=-64; yo=-xo*Tan;}/*looking right*/
  else { rx=px; ry=py; dof=8;}                                                  /*looking up or down. no hit*/

  while(dof<8)
  {
   mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
   if(mp>0 && mp<mapX*mapY && mapW[mp]>0){ vmt=mapW[mp]-1; dof=8; disV=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);}/*hit*/
   else{ rx+=xo; ry+=yo; dof+=1;}                                               /*check next horizontal*/
  }
  vx=rx; vy=ry;

  /*---Horizontal---*/
  dof=0; disH=100000;
  Tan=1.0/Tan;
       if(sin(degToRad(ra))> 0.001){ ry=(((int)py>>6)<<6) -0.0001; rx=(py-ry)*Tan+px; yo=-64; xo=-yo*Tan;}/*looking up*/
  else if(sin(degToRad(ra))<-0.001){ ry=(((int)py>>6)<<6)+64;      rx=(py-ry)*Tan+px; yo= 64; xo=-yo*Tan;}/*looking down*/
  else{ rx=px; ry=py; dof=8;}                                                   /*looking straight left or right*/

  while(dof<8)
  {
   mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
   if(mp>0 && mp<mapX*mapY && mapW[mp]>0){ hmt=mapW[mp]-1; dof=8; disH=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);}/*hit*/
   else{ rx+=xo; ry+=yo; dof+=1;}                                               /*check next horizontal*/
  }

  float shade=1;
  glColor3f(0,0.8,0);
  if(disV<disH){ hmt=vmt; shade=0.5; rx=vx; ry=vy; disH=disV; glColor3f(0,0.6,0);}/*horizontal hit first*/
  glLineWidth(2); glBegin(GL_LINES); glVertex2i(px,py); glVertex2i(rx,ry); glEnd();/*draw 2D ray*/

  int ca=FixAng(pa-ra); disH=disH*cos(degToRad(ca));                            /*fix fisheye*/
  int lineH = (mapS*320)/(disH);
  float ty_step=32.0/(float)lineH;
  float ty_off=0;
  if(lineH>320){ ty_off=(lineH-320)/2.0; lineH=320;}                            /*line height and limit*/
  int lineOff = 160 - (lineH>>1);                                               /*line offset*/

  /*---draw walls---*/
  int y;
  float ty=ty_off*ty_step+hmt*32;
  float tx;
  if(shade==1){ tx=(int)(rx/2.0)%32; if(ra>180){ tx=31-tx;}}
  else        { tx=(int)(ry/2.0)%32; if(ra>90 && ra<270){ tx=31-tx;}}
  for(y=0;y<lineH;y++)
  {
   float c=All_Textures[(int)(ty)*32 + (int)(tx)]*shade;
   if(hmt==0){ glColor3f(c    , c/2.0, c    );} /*checkerboard red*/
   if(hmt==1){ glColor3f(c    , c/2.5, c    );} /*Brick yellow*/
   if(hmt==2){ glColor3f(c    , c    , c    );} /*window blue*/
   if(hmt==3){ glColor3f(c/2.0, c    , c/2.0);} /*door green*/
   glPointSize(8);glBegin(GL_POINTS);glVertex2i(r*8+530,y+lineOff);glEnd();/*draw vertical wall*/
   ty+=ty_step;
  }

  /*---draw floors---*/
 for(y=lineOff+lineH;y<320;y++)
 {
  float dy=y-(320/2.0), deg=degToRad(ra), raFix=cos(degToRad(FixAng(pa-ra)));
  tx=px/2 + cos(deg)*158*32/dy/raFix;
  ty=py/2 - sin(deg)*158*32/dy/raFix;
  int mp=mapF[(int)(ty/32.0)*mapX+(int)(tx/32.0)]*32*32;
  float c=All_Textures[((int)(ty)&31)*32 + ((int)(tx)&31)+mp]*0.7;
  glColor3f(c,c/1.2,c);glPointSize(8);glBegin(GL_POINTS);glVertex2i(r*8+530,y);glEnd();

 /*---draw ceiling---*/
  mp=mapC[(int)(ty/32.0)*mapX+(int)(tx/32.0)]*32*32;
  c=All_Textures[((int)(ty)&31)*32 + ((int)(tx)&31)+mp]*0.7;
  glColor3f(c/1.5,c,c/2.0);glPointSize(8);glBegin(GL_POINTS);glVertex2i(r*8+530,320-y);glEnd();
 }

 ra=FixAng(ra-1);                                                               /*go to next ray, 60 total*/
 }
}
