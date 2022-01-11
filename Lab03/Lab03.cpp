#include <windows.h>
#include <gl.h>
#include <glut.h>

int width = 600;
int height = 400;

class GLintPoint
{
public:
    GLint	x, y;
};

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int random(int m)
{
    return rand() % m;
}
void drawDot(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void Sierpinski(GLintPoint corner[3])
{
    GLintPoint  T[3] = { {corner[0].x,corner[0].y} ,{corner[1].x,corner[1].y} ,{corner[2].x,corner[2].y} };

    int 		index = random(3);
    GLintPoint	lintPoint = T[index];

    glClear(GL_COLOR_BUFFER_BIT);
    drawDot(lintPoint.x, lintPoint.y);
    for (int i = 0; i < 5000; i++)
    {
        index = random(3);
        lintPoint.x = (lintPoint.x + T[index].x) / 2;
        lintPoint.y = (lintPoint.y + T[index].y) / 2;
        drawDot(lintPoint.x, lintPoint.y);
    }
    glFlush();
}


void myMouse(int button, int state, int x, int y)
{
    static GLintPoint corner[3];
    static int	numCorners = 0;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        corner[numCorners].x = x;
        corner[numCorners].y = height - y;
        numCorners++;
        if (numCorners == 3)
        {
            Sierpinski(corner);
            numCorners = 0;
        }
    }

}


int main(int argc, const char* argv[]) {

    glutInit(&argc, (char**)argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("LAB3 - BAI 05");

    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    myInit();


    glutMainLoop();
    return 0;
}
