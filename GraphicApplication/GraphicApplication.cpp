
#include "tchar.h"
#include <windows.h>
#include <gl.h>
#include <glut.h>

GLfloat v0[2] = { 1,1 };
GLfloat v1[2] = { 2,3 };
GLfloat v2[2] = { 4,1 };
GLfloat v3[2] = { 6,2 };
GLfloat v4[2] = { 9,3 };
GLfloat v5[2] = { 7,5 };

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 9, 0.0, 6);
}
void drawGrid()
{
	glColor3f(0.6f, 0.6f, 0.6f);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	for (int i = 0; i < 9; i++)
	{
		glVertex2i(i, 0);
		glVertex2i(i, 6);
	}
	for (int i = 0; i < 6; i++)
	{
		glVertex2i(0, i);
		glVertex2i(9, i);
	}
	glEnd();
}
//Bai 02
//void myDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	drawGrid();
//
//	glLineWidth(4.0);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glColor3f(0.f, 0.f, 0.f);
//
//	glBegin(GL_TRIANGLE_STRIP);
//	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//	glVertex2fv(v0);
//	glVertex2fv(v1);
//	glVertex2fv(v2);
//	glVertex2fv(v5);
//	glVertex2fv(v3);
//	glVertex2fv(v4);
//	glEnd();
//
//	glFlush();
//}

//Bai 03
//void myDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	drawGrid();
//
//	glLineWidth(4.0);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glColor3f(0.f, 0.f, 0.f);
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2fv(v5);
//	glVertex2fv(v1);
//	glVertex2fv(v0);
//	glVertex2fv(v2);
//	glVertex2fv(v3);
//	glVertex2fv(v4);
//	glEnd();
//		
//	glFlush();
//}

//Bai04
//void myDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	drawGrid();
//
//	glLineWidth(4.0);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glColor3f(0.f, 0.f, 0.f);
//	glBegin(GL_TRIANGLE_STRIP);
//	glVertex2fv(v4);
//	glVertex2fv(v5);
//	glVertex2fv(v3);
//	glVertex2fv(v1);
//	glVertex2fv(v2);
//	glVertex2fv(v0);
//	glEnd();
//		
//	glFlush();
//}


//Bai 05
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();

	glLineWidth(4.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.f, 0.f, 0.f);
	glBegin(GL_QUAD_STRIP);
	glVertex2fv(v4);
	glVertex2fv(v5);
	glVertex2fv(v3);
	glVertex2fv(v1);

	glVertex2fv(v2);
	glVertex2fv(v0);
	glEnd();

	glFlush();
}


int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(600, 400); //set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("LAB 1 - (Bai 5)");//open the screen window

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
