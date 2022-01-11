
#include "supportClass.h"

class Canvas
{
public:
	Canvas(int width, int height, char* windowTitle);
	void setWindow(float l, float r, float b, float t);
	void setViewport(int l, int r, int b, int t);
	IntRect	  getViewport();
	RealRect getWindow();
	float  getWindowAspectRatio();
	void  clearScreen();
	void  setBackgroundColor(float r, float g, float b);
	void  setColor(float r, float g, float b);
	void lineTo(float x, float y);
	void lineTo(Point2 p);
	void moveTo(float x, float y);
	void moveTo(Point2 p);
	void moveRel(float dx, float dy);
	void lineRel(float dx, float dy);
	void setLineWidth(float width);
	void turnTo(float angle) { CD = angle; }
	void turn(float angle) { CD += angle; }
	void setCD(float angle) { CD = angle; }
	float getCD() { return CD; }
	void forward(float dist, int isVisible);
private:
	Point2   CP;  //current position in the world
	IntRect  viewport; // the current viewport
	RealRect window;// the current window	
	float	CD;//current direction
};
