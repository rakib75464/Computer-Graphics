#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 880.0, 0.0, 587.0);
}

void rsaFlag()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Green strip
    glBegin(GL_QUADS);
    glColor3f(0, 0.46, 0.28);
    glVertex2i(0, 0);
    glVertex2i(880, 0);
    glVertex2i(880, 587);
    glVertex2i(0, 587);
    glEnd();

    // Blue strip
    glBegin(GL_QUADS);
    glColor3f(0, 0.137, 0.58);
    glVertex2i(220, 0);
    glVertex2i(880, 0);
    glVertex2i(880, 195);
    glVertex2i(495, 195);
    glEnd();

    // Red strip
    glBegin(GL_QUADS);
    glColor3f(0.87, 0.23, 0.19);
    glVertex2i(495, 392);
    glVertex2i(880, 392);
    glVertex2i(880, 587);
    glVertex2i(220, 587);
    glEnd();

    // Lower white strip
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2i(132, 0);
    glVertex2i(220, 0);
    glVertex2i(495, 195);
    glVertex2i(495, 234);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(495, 195);
    glVertex2i(880, 195);
    glVertex2i(880, 234);
    glVertex2i(495, 234);
    glEnd();

    // Upper white strip
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2i(495, 352);
    glVertex2i(880, 352);
    glVertex2i(880, 392);
    glVertex2i(495, 392);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(132, 587);
    glVertex2i(495, 352);
    glVertex2i(495, 392);
    glVertex2i(220, 587);
    glEnd();

    // Yellow triangle strip
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0.72, 0.10);
    glVertex2i(0, 76);
    glVertex2i(330, 293.5);
    glVertex2i(0, 511);
    glEnd();

    // Black triangle strip
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex2i(0, 128);
    glVertex2i(260, 293.5);
    glVertex2i(0, 460);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(880, 587);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("South African Flag");
    init();
    glutDisplayFunc(rsaFlag);
    glutMainLoop();
    return 0;
}
