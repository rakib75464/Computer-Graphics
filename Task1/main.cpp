#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
    glClearColor(0.50f, 0.50f, 0.50f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Horizontal green line.
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(0,500);
    glVertex2i(1000,500);
    glEnd();

    //Vertical green line.
    glBegin(GL_LINES);
    glLineWidth(2);
    glVertex2i(500,0);
    glVertex2i(500,1000);
    glEnd();

    //Green Quad.
    glBegin(GL_QUADS);
    glVertex2i(150,150);
    glVertex2i(350,150);
    glVertex2i(350,350);
    glVertex2i(150,350);
    glEnd();

    //Orange triangle.
    glColor3f(1.0, 0.64, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(700,150);
    glVertex2i(800,150);
    glVertex2i(750, 350);

    //Red triangle.
    glColor3f(1.0,0.0,0.0);
    glVertex2i(150,650);
    glVertex2i(350,650);
    glVertex2i(250,850);
    glEnd();

    //Yellow polygon.
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(700,650);
    glVertex2i(800,650);
    glVertex2i(850,750);
    glVertex2i(800,850);
    glVertex2i(700,850);
    glVertex2i(650,750);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
