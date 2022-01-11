#pragma once
class Point
{
public:
	Point();
	Point(float x1, float y1, float x2, float y2);
	virtual ~Point();
	void setFirstPoint(float x1, float y1);
	void setSecondPoint(float x2, float y2);
	float getX1();
	float getX2();
	float getY1();
	float getY2();
	void draw();
	void drawRectPoint();
private:
	float x1, x2, y1, y2;
};
