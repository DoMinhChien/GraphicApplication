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

	glFlush();
}

void calVertex()
{
	float	centerX, centerY;
	float	radius;
	float	alpha;
	float	inc;

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


}
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	calVertex();
//
//	glutInit(&argc, (char**)argv); //initialize the tool kit
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode
//	glutInitWindowSize(WIDTH, HEIGHT); //set window size
//	glutInitWindowPosition(0, 0); // set window position on screen
//	glutCreateWindow("Mercedes-Benz Logo"); // open the screen window
//
//	glutDisplayFunc(myDisplay);
//	myInit();
//	glutMainLoop();
//	return 0;
//}
//
