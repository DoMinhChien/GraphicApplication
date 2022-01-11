#include <windows.h>
#include <math.h>
#include <glut.h>
#include "Point.h"

Point p(0, 0, 0, 0);
Point p1[100];
int count = 0;
void setWindow(float l, float r, float b, float t)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
}

void setViewport(int l, int r, int b, int t)
{
	glViewport(l, b, r - l, t - b);
}

void setBackgroundColor(float r, float g, float b)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	count = 0;
}

void myDisplay()
{

	clearScreen();
	glFlush();
}


void myInit()
{
	setBackgroundColor(1.0, 1.0, 0.0);
	glColor3f(0.f, 0.f, 0.f);
	glPointSize(9.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}
Point lineIntersection(Point p1, Point p2)
{
	Point t;

	float	A1, B1, A2, B2;

	A1 = (p1.getY2() - p1.getY1()) / (p.getX2() - p.getX1());
	B1 = p1.getY1() - A1 * p1.getX1();

	A2 = (p2.getY2() - p2.getY1()) / (p2.getX2()- p2.getX1());
	B2 = p2.getY1() - A2 * p2.getX1();

	
	float x =  (B2 - B1) / (A1 - A2);
	float y = A1 * x+ B1;

	t.setFirstPoint(x, y);
	
	
	return t;
}

void myMouse(int Button, int state, int x, int y)
{

	if (Button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		bool endPoint = false;
		int x1 = p.getX1();
		int y1 = p.getY1();
		if ((x1  ==0  && y1 == 0))
		{
			p.setFirstPoint(x, 480 - y);
		}
		else
		{
			p.setSecondPoint(x, 480 - y);
			p.draw();
			p1[count] = p;
			count++;
			if (count % 2 ==0)
			{
				Point tmp = lineIntersection(p1[count -1], p1[count -2]);
				tmp.drawRectPoint();
				glColor3f(0, 0, 0);

			}

			endPoint = true;
		}

		if (endPoint)
		{
			p.setFirstPoint(0, 0);
			p.setSecondPoint(0, 0);
		}

	}

	if (Button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		clearScreen();
		count = 0;
	}
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Lab03 - Bai 07");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
	return 0;
}
