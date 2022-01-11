#include "Point.h"
#include <windows.h>
#include <glut.h>
Point::Point()
{

}

Point::Point(float x1, float y1, float x2, float y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
Point::~Point()
{

}

void Point::setFirstPoint(float x, float y)
{
	x1 = x;
	y1 = y;
}

void Point::setSecondPoint(float x, float y)
{
	x2 = x;
	y2 = y;
}

float Point::getX1()
{
	return x1;
}
float Point::getX2()
{
	return x2;
}

float Point::getY1()
{
	return y1;
}
float Point::getY2()
{
	return y2;
}
void Point::draw()
{
	glBegin(GL_LINE_STRIP);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
	glFlush();
}
void Point::drawRectPoint()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glColor3f(0, 0.0, 1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	 
	glVertex2f(x1, y1);
	
	glEnd();
	glFlush();

}
