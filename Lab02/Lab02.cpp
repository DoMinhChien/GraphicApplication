#include "Canvas.h"
#include <tchar.h>
char title[] = "Draw Figure - Bai 07";

#define		PI	3.1415926
float deg = 6 * PI / 180;
Canvas	cvs(400, 400, title);
void drawArcs() {
	cvs.setColor(0, 0, 0);
	cvs.setLineWidth(1);

	float	R = 0.5;
	for (int i = 0; i <= 90; i++) {
		float		x = R * cos(i * PI / 180.0);
		float		y = R * sin(i * PI / 180.0);
		if (i == 0)		cvs.moveTo(x, y);
		else			cvs.lineTo(x, y);
	}

	for (int i = 180; i <= 270; i++) {
		float		x = R * cos(i * PI / 180.0) + 1;
		float		y = R * sin(i * PI / 180.0) + 1;
		if (i == 180)	cvs.moveTo(x, y);
		else			cvs.lineTo(x, y);
	}
}

void myDisplay()
{
	cvs.clearScreen();
	cvs.setWindow(0, 1, 0, 1);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
		{
			int r = 1 + rand() % (4 + 1 - 1);
			if (r == 1) { cvs.setWindow(0, 1, 0, 1); }
			if (r == 2) { cvs.setWindow(1, 0, 0, 1); }
			if (r == 3) { cvs.setWindow(0, 1, 1, 0); }
			if (r == 4) { cvs.setWindow(1, 0, 1, 0); }

			int L = 50;
			cvs.setViewport(i * L, i * L + L, j * L, j * L + L);
			drawArcs();
		}
}

int main(int argc, const char* argv[]) {
	cvs.setBackgroundColor(1.0, 1.0, 1.0);
	cvs.setColor(0.0, 0.0, 0.0);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
