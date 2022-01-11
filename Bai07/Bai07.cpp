#include <windows.h>
#include <math.h>
#include <gl.h>
#include <glut.h>

#define     PI        3.1415926
#define    WIDTH        500
#define    HEIGHT       500

float    centerX = WIDTH / 2.0, centerY = HEIGHT / 2.0;
float    radius = 100;
float    alpha;
float    inc;

struct    Point2
{
    float    x, y;
};

Point2 v[15];

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

    glLineWidth(3);

    glColor3f(0.0, 0.0, 0.0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_QUADS);
    glColor3f(32.0 / 255, 52.0 / 255, 122.0 / 255);
    glVertex2f(v[0].x, v[0].y);
    glVertex2f(v[1].x, v[1].y);
    glVertex2f(v[7].x, v[7].y);
    glVertex2f(v[6].x, v[6].y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(30.0 / 255, 129.0 / 255, 180.0 / 255);
    glVertex2f(v[1].x, v[1].y);
    glVertex2f(v[2].x, v[2].y);
    glVertex2f(v[9].x, v[9].y);
    glVertex2f(v[8].x, v[8].y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(32.0 / 255, 52.0 / 255, 122.0 / 255);
    glVertex2f(v[2].x, v[2].y);
    glVertex2f(v[3].x, v[3].y);
    glVertex2f(v[10].x, v[10].y);
    glVertex2f(v[9].x, v[9].y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(30.0 / 255, 129.0 / 255, 180.0 / 255);
    glVertex2f(v[3].x, v[3].y);
    glVertex2f(v[4].x, v[4].y);
    glVertex2f(v[12].x, v[12].y);
    glVertex2f(v[11].x, v[11].y);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(32.0 / 255, 52.0 / 255, 122.0 / 255);
    glVertex2f(v[4].x, v[4].y);
    glVertex2f(v[5].x, v[5].y);
    glVertex2f(v[13].x, v[13].y);
    glVertex2f(v[12].x, v[12].y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(30.0 / 255, 129.0 / 255, 180.0 / 255);
    glVertex2f(v[5].x, v[5].y);
    glVertex2f(v[0].x, v[0].y);
    glVertex2f(v[6].x, v[6].y);
    glVertex2f(v[14].x, v[14].y);
    glEnd();
    glFlush();
}


float calculateXPosition(float x, float r, float alpha)
{
    return x + r * cos(alpha);
}
float calculateYPosition(float y, float r, float alpha)
{
    return y + r * sin(alpha);
}
void calCulatePoint(int i)
{
    alpha += inc;
    v[i].x = calculateXPosition(centerX, radius, alpha);
    v[i].y = calculateYPosition(centerY, radius, alpha);
}
void calVertex()
{
    

    alpha = PI / 2.0;
    inc = 2.0 * PI / 6.0;

    v[0].x = centerX;
    v[0].y = centerY + radius;

    for(int i = 1 ; i <= 5; i++)
    {
        alpha += inc;
	    v[i].x = calculateXPosition(centerX, radius, alpha);
        v[i].y = calculateYPosition(centerY, radius, alpha);

    }

    alpha = PI / 2.0;
    radius = radius * 2;
    inc = 2.0 * PI / 3.0;

    v[6].x = centerX;
    v[6].y = centerY + radius;

    calCulatePoint(9);
    calCulatePoint(12);

    radius = 100;
    v[7].x = v[1].x;
    v[7].y = v[1].y + radius;
    inc = 2.0 * PI / 6.0;

    radius = sqrt(pow(centerX - v[7].x, 2) + pow(v[7].y - centerY, 2));
    alpha = acos((v[7].y - centerY) / radius) + PI / 2;

    calCulatePoint(8);
    calCulatePoint(10);
    calCulatePoint(11);
    calCulatePoint(13);
    calCulatePoint(14);
}
int main(int argc, const char* argv[])
{
    calVertex();
    glutInit(&argc, (char**)argv); //initialize the tool kit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode
    glutInitWindowSize(WIDTH, HEIGHT); //set window size
    glutInitWindowPosition(0, 0); // set window position on screen
    glutCreateWindow("Logo BK - Bai 8 + 10 "); // open the screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
