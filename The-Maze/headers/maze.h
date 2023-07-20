#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define mapX 8 /*map width*/
#define mapY 8/*map height*/
#define mapS 64/*map cube size*/

float degToRad(float a);
float FixAng(float a);
float distance(float ax,float ay,float bx,float by,float ang);
float px,py,pdx,pdy,pa;
float frame1,frame2,fps;

/**
*struct - defines the keys needed for the player's movements
*
*@w: upward
*@a: lef
*@d: right
*@s: downard
*
*Return: nothing
*/

typedef struct
{
    int w,a,d,s;                     /*button state on off*/
} ButtonKeys;

int All_Textures[16500];

int mapW[100];

int mapF[100];

int mapC[100];

void resize(int w,int h);

void drawMap2D();

void drawPlayer2D();

void drawRays2D();

void init();

void display();

void ButtonUp(unsigned char key,int x,int y);

void ButtonDown(unsigned char key,int x,int y);

void resize(int w,int h);


#endif /* MAIN_H_INCLUDED*/

