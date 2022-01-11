// Bai2.cpp : Defines the entry point for the console application.
//
#include "tchar.h"

#include <math.h>
#include <iostream>
#include "supportClass.h"
#include "Mesh.h"
using namespace std;

int		screenWidth = 600;
int		screenHeight = 300;

Mesh    Platonic20;
Mesh    Platonic12;
Mesh    LapPhuongVatGoc;
Mesh    Cylinder;
Mesh    CylinderWithHole;
Mesh    MultiPoly;

int		nChoice = 1;

void myDisplay()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 4, 2, 0, 0, 0, 0, 1, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(100, 0, screenWidth /2 , screenHeight);

    glColor3f(0, 0, 0);

    if (nChoice == 1)
        Platonic20.DrawWireframe();
    else if (nChoice == 2)
        Platonic12.DrawWireframe();
    else if (nChoice == 3)
        LapPhuongVatGoc.DrawWireframe();
    else if (nChoice == 4)
        Cylinder.DrawWireframe();
    else if (nChoice == 5)
        CylinderWithHole.DrawWireframe();
    else if (nChoice == 6)
        MultiPoly.DrawWireframe();


    //glViewport(screenWidth / 2, 0, screenWidth / 2, screenHeight);

    if (nChoice == 1)
        Platonic20.DrawColor();
    else if (nChoice == 2)
        Platonic12.DrawColor();
    else if (nChoice == 3)
        LapPhuongVatGoc.DrawColor();
    else if (nChoice == 4)
        Cylinder.DrawColor();
    //else if (nChoice == 6)
    //    MultiPoly.DrawColor();

    glFlush();
    glutSwapBuffers();
}

void myInit()
{
    float	fHalfSize = 4;

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glFrontFace(GL_CCW);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}

int main(int argc, const char* argv[]) {
    cout << "Menu:" << endl;
    cout << "1. Platonic20" << endl;
    cout << "2. Platonic12" << endl;
    cout << "3. Cube8Corner" << endl;
    cout << "4. Cylinder" << endl;
    cout << "5. CylinderWithHole" << endl;
    //cin >> nChoice;
    nChoice = 6;
    glutInit(&argc, (char**)argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("LAB 05 - Bai 4 - 1833410"); 

    Platonic20.CreateIcosahedron();
    Platonic12.CreateDedocahedron();
    Cylinder.CreateCylinder(30, 3, 1);
    CylinderWithHole.CreateCylinderWithHole(16, 4, 2, 1);
    MultiPoly.CreateYPlane();
    myInit();

    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
