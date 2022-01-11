#include "tchar.h"
#include <windows.h>
#include <fstream>
#include <gl.h>
#include <glut.h>

using namespace std;
char fileName[] = "dinosaur.dat";


float	WINDOW_LEFT;
float	WINDOW_RIGHT;
float	WINDOW_BOTTOM;
float	WINDOW_TOP;

const	int picWidth = 780;
const	int picHeight = 600;

const	int	scrWidth = picWidth;
const	int	scrHeight = picHeight / 2;

void drawPolyLineFile(char* fileName)
{
	fstream inStream;
	inStream.open(fileName, ios::in);
	if (inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);
	GLint	numpolys, totalRows;
	GLfloat x, y;
	inStream >> numpolys;

	for (int j = 0; j < numpolys; j++)
	{
		inStream >> totalRows;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < totalRows; i++)
		{
			inStream >> x >> y;
			glVertex2d(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}
void findWindow(char* fileName)
{
	float minX = 0, minY = 0;
	float maxX = 0, maxY = 0;
	fstream inStream;
	inStream.open(fileName, ios::in);

	GLint	totalPolys, totalRows;
	GLfloat x, y;
	inStream >> totalPolys;

	for (int i = 0; i < totalPolys; i++)
	{
		inStream >> totalRows;
		for (int j = 0; j < totalRows;j++)
		{
			inStream >> x;
			inStream >> y;
			if (i == 0 && j == 0)
			{
				maxX = x;
				minX = x;
				maxY = y;
				minY = y;
			}
			else
			{

				if (x < minX)
				{
					minX = x;
				}

				if (y < minY)
				{
					minY = y;
				}

				if (y > maxY)
				{
					maxY = y;
				}
				if (x > maxX)
				{
					maxX = x;
				}
				
			}
		}
	}
	WINDOW_LEFT = minX - 100;
	WINDOW_RIGHT = maxX + 100;
	WINDOW_BOTTOM = minY - 100;
	WINDOW_TOP = maxY + 100;

	inStream.close();
}

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.1f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(WINDOW_LEFT, WINDOW_RIGHT, WINDOW_BOTTOM, WINDOW_TOP);
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawPolyLineFile(fileName);

	glFlush();
}

int _tmain(int argc, _TCHAR* argv[])
{
	findWindow(fileName);

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(WINDOW_RIGHT - WINDOW_LEFT, WINDOW_TOP - WINDOW_BOTTOM);
	glutInitWindowPosition(0, 0); // set window position on screen
	glutCreateWindow("LAB 4 - (Bai 3.2)");//open the screen window
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
