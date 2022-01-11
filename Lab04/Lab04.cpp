#include "tchar.h"
#include <windows.h>
#include <gl.h>
#include <glut.h>

#define	WINDOW_LEFT		-10
#define	WINDOW_RIGHT		 10
#define	WINDOW_BOTTOM		-10
#define	WINDOW_TOP		 10

void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(WINDOW_LEFT, WINDOW_RIGHT, WINDOW_BOTTOM, WINDOW_TOP);
}
void drawGrid() {
	glColor3f(0.0f, 0.1f, 0.0f);
	glLineWidth(1.0);

	glBegin(GL_LINES);
	for (int i = WINDOW_LEFT; i <= WINDOW_RIGHT; i++) {
		glVertex2i(i, WINDOW_BOTTOM);
		glVertex2i(i, WINDOW_TOP);
	}
	for (int i = WINDOW_BOTTOM; i < WINDOW_TOP; i++) {
		glVertex2i(WINDOW_LEFT, i);
		glVertex2i(WINDOW_RIGHT, i);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glVertex2i(WINDOW_LEFT, 0);
	glVertex2i(WINDOW_RIGHT, 0);
	glVertex2i(0, WINDOW_BOTTOM);
	glVertex2i(0, WINDOW_TOP);
	glEnd();
}
void drawHouse(float red = 0, float green = 0, float blue = 0, float Sx = 1, float Sy = 1, float Tx = 0, float Ty = 0, float angle = 0, float x = 0, float y = 0, float z = 0) {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glScalef(Sx, Sy, 1);
		glTranslatef(Tx, Ty, 0);
		glRotatef(angle, x, y, z);
		glColor3f(red, green, blue);
		glLineWidth(3.0);

		if (Sx== -1 && Sy ==-1)
		{
			glBegin(GL_LINE_LOOP);
			glVertex2f(0, 0);
			glVertex2f(6, 0);
			glVertex2f(6, 3);
			glVertex2f(3, 6);
			glVertex2f(0, 3);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2f(0.5, 3.5);
			glVertex2f(0.5, 5);
			glVertex2f(1.5, 5);
			glVertex2f(1.5, 4.5);
			glEnd();
		}
		else
		{


			glBegin(GL_LINE_LOOP);
			glVertex2f(0, 0);
			glVertex2f(4, 0);
			glVertex2f(4, 2);
			glVertex2f(2, 4);
			glVertex2f(0, 2);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2f(0.5, 2.5);
			glVertex2f(0.5, 4);
			glVertex2f(1.5, 4);
			glVertex2f(1.5, 3.5);
			glEnd();
		}


}



void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();

	drawHouse(1, 0, 0);
	drawHouse(0, 0, 1, 1, 1, 4, 3);
	drawHouse(1, 0, 1, 1, 1.5, 2, -3);
	drawHouse(0, 1, 1, 1, 1, 2, 0, 90, 0, 0, 1);
	drawHouse(0, 0, 0, -1, -1, 0, 0);


	glFlush();
}

int _tmain(int argc, _TCHAR* argv[]) {
	glutInit(&argc, (char**)argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600); 
	glutInitWindowPosition(0, 0); 
	glutCreateWindow("LAB 4 - (Bai 1 - Hinh 05)");

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
