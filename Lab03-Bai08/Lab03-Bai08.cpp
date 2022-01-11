#include "Canvas.h"
#define		PI	3.1415926
int		height = 600;
int		width = 600;
char title[] = "Lab03 - Bai 08";
Canvas	cvs(width, height, title);

Point2	p[3];
int		pointNum = 0;

Point2	center;
float	radius;
bool	flag = false;

Vector x, y, z;

void drawCircle(Point2 center, float radius)
{
	const int numVerts = 50;
	double angle = 0 * PI / 180;
	double angleInc = 2 * PI / numVerts;
	cvs.moveTo(radius * cos(angle) + center.getX(), radius * sin(angle) + center.getY());
	for (int k = 0; k < numVerts; k++)
	{
		angle += angleInc;
		cvs.lineTo(radius * cos(angle) + center.getX(), radius * sin(angle) + center.getY());
	}
}

void myDisplay()
{
	cvs.clearScreen();

	glLineWidth(1.0);
	cvs.setColor(0.0, 0.0, 0.0);
	if (pointNum >= 2)
	{
		cvs.moveTo(p[0]);
		cvs.lineTo(p[1]);
	}
	if (pointNum >= 3)
	{
		cvs.lineTo(p[2]);
		cvs.lineTo(p[0]);
	}

	if (flag)
	{
		glLineWidth(2.0);
		drawCircle(center, radius);
	}

	glFlush();
}
void setVectorVal()
{
	x.set(p[1].x - p[0].x, p[1].y - p[0].y);
	y.set(p[2].x - p[1].x, p[2].y - p[1].y);
	z.set(p[0].x - p[2].x, p[0].y - p[2].y);
}
void findExCircle()
{
	Vector	 perp, tempVal;
	setVectorVal();
	perp.set(-x.y, x.x);
	float	factor = y.dotProduct(z) / perp.dotProduct(z);
	tempVal = x.add(perp.scale(factor));
	tempVal = tempVal.scale(0.5);

	center = p[0].add(tempVal);
	float firstVal = (y.dotProduct(z) / perp.dotProduct(z));
	float secondVal = (y.dotProduct(z) / perp.dotProduct(z));
	radius = (x.length() / 2) *
		sqrt(1.0 + firstVal * secondVal);

	flag = true;
}
void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (pointNum < 3)
		{
			p[pointNum].x = x;
			p[pointNum].y = height - y;
			pointNum++;

		}
		if (pointNum ==3)
		{
			for (int i = 0; i < pointNum; i++)
				p[i].draw();
			findExCircle();
		}
		myDisplay();
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		pointNum = 0;
		flag = false;
		myDisplay();
	}
}

int main(int argc, char* argv[])
{
	cvs.setBackgroundColor(1.0, 1.0, 1.0);
	cvs.setColor(0.0, 0.0, 0.0);

	glutMouseFunc(myMouse);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
