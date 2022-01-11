#include <windows.h>
#include <math.h>
#include <gl.h>
#include <glut.h>
#include "tchar.h"

#define PI				3.1415926

#define	WIDTH			600
#define HEIGHT			600
#define OUTTERRADIUS	200
#define INNERRADIUS		30

float	fX[7], fY[7];

struct	Point2
{
	float	x, y;
};

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	//glColor3f(1.0, 0.0, 0.0);
	//glPointSize(5);
	//glBegin(GL_POINTS);
	// 
	//for (int i = 0; i < 7; i++)
	//{
	//	Point2 point2 = { fX[i], fY[i] };

	//	glVertex2f(point2.x, point2.y);
	//};

	//glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(fX[0], fY[0]);
	glVertex2f(fX[2], fY[2]);
	glVertex2f(fX[1], fY[1]);
	glVertex2f(fX[6], fY[6]);
	glVertex2f(fX[5], fY[5]);
	glVertex2f(fX[4], fY[4]);
	glVertex2f(fX[3], fY[3]);
	glVertex2f(fX[2], fY[2]);

	
	glEnd();

	glFlush();
}

void calVertex()
{
	float	centerX, centerY;
	float	radius, outRadius;
	float	alpha, beta;
	float	inc;
	float   outc;

	centerX = WIDTH / 2.0;
	centerY = HEIGHT / 2.0;

	fX[0] = centerX;
	fY[0] = centerY;

	radius = OUTTERRADIUS;

	alpha = PI / 2.0;
	inc = 2.0 * PI / 3.0;

	fX[1] = centerX;
	fY[1] = centerY + radius;

	alpha += inc;
	fX[5] = centerX + radius * cos(alpha);
	fY[5] = centerY + radius * sin(alpha);

	alpha += inc;
	fX[3] = centerX + radius * cos(alpha);
	fY[3] = centerY + radius * sin(alpha);

	outRadius = INNERRADIUS;
	beta = PI / 2.0;
	outc = 2.0 * PI / 3.0;

	fX[4] = centerX;
	fY[4] = centerY - outRadius;

	beta += outc;
	fX[2] = centerX - outRadius * cos(beta);
	fY[2] = centerY - outRadius * sin(beta);

	beta += inc;
	fX[6] = centerX - outRadius * cos(beta);
	fY[6] = centerY - outRadius * sin(beta);

}

int _tmain(int argc, _TCHAR* argv[])
{
	calVertex();

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode
	glutInitWindowSize(WIDTH, HEIGHT); //set window size
	glutInitWindowPosition(0, 0); // set window position on screen
	glutCreateWindow("Mercedes-Benz Logo"); // open the screen window

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
