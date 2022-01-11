#include <windows.h>	
#include <math.h>
#include <glut.h>
void setWindow(float l, float r, float b, float t)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
}

void myDisplay()
{
	//clear screen
	glClear(GL_COLOR_BUFFER_BIT);

	//Set windows
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLdouble)-6.2, (GLdouble)15, (GLdouble)-6, (GLdouble)6.0);
	
	glViewport(0, 0, 640, 480);
	
	 GLfloat x, y;
	glBegin(GL_LINE_STRIP);
	double i = -6;
	while (i < 8)
	{

		x = i + sin(2.0 * i);
		y =i + sin(3.0 * i);

		glVertex2f(x, y);

		GLfloat v[2] = { x,y };
		glVertex2fv(v);
		if (i == 0)
			glDisable(GL_POLYGON_STIPPLE);
		i += 0.001;
	}

	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(380, 500);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("LAB 2 -BAI 9.5");
	glutDisplayFunc(myDisplay);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.f, 0.f, 0.f);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glutMainLoop();
	return 0;
}
