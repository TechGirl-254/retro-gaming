#include "../headers/maze.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

/**
*main - converts degrees to radian
*
*@argc: an int representing the number of command line arguments
*@argv: a list of commandline arguements
*
*Return: an int
*/

int main(int argc, char* argv[])
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(1024,510);
     glutInitWindowPosition(200,200);
     glutCreateWindow("Wammy's Maze");
     init();
     glutDisplayFunc(display);
     glutReshapeFunc(resize);
     glutKeyboardFunc(ButtonDown);
     glutKeyboardUpFunc(ButtonUp);
     glutMainLoop();
}
