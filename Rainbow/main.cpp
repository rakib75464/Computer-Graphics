#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 480.0);
}

void rainbowFlag()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Red stripe
    glBegin(GL_QUADS);
    glColor3f(0.89, 0.0, 0.13);  // Red color
    glVertex2i(0, 400);
    glVertex2i(800, 400);
    glVertex2i(800, 480);
    glVertex2i(0, 480);
    glEnd();

    // Orange stripe
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.35, 0.0);  // Orange color
    glVertex2i(0, 320);
    glVertex2i(800, 320);
    glVertex2i(800, 400);
    glVertex2i(0, 400);
    glEnd();

    // Yellow stripe
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.84, 0.0);  // Yellow color
    glVertex2i(0, 240);
    glVertex2i(800, 240);
    glVertex2i(800, 320);
    glVertex2i(0, 320);
    glEnd();

    // Green stripe
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.56, 0.31);  // Green color
    glVertex2i(0, 160);
    glVertex2i(800, 160);
    glVertex2i(800, 240);
    glVertex2i(0, 240);
    glEnd();

    // Blue stripe
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.2, 0.69);  // Blue color
    glVertex2i(0, 80);
    glVertex2i(800, 80);
    glVertex2i(800, 160);
    glVertex2i(0, 160);
    glEnd();

    // Purple stripe
    glBegin(GL_QUADS);
    glColor3f(0.56, 0.0, 1.0);  // Purple color
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 80);
    glVertex2i(0, 80);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rainbow Flag");
    init();
    glutDisplayFunc(rainbowFlag);
    glutMainLoop();
    return 0;
}
