#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 900.0, 0.0, 600.0);
}

void palestineFlag()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Black stripe
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // Black color
    glVertex2i(0, 400);
    glVertex2i(900, 400);
    glVertex2i(900, 600);
    glVertex2i(0, 600);
    glEnd();

    // White stripe
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);  // White color
    glVertex2i(0, 200);
    glVertex2i(900, 200);
    glVertex2i(900, 400);
    glVertex2i(0, 400);
    glEnd();

    // Green stripe
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.56, 0.31);  // Green color
    glVertex2i(0, 0);
    glVertex2i(900, 0);
    glVertex2i(900, 200);
    glVertex2i(0, 200);
    glEnd();

    // Red triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.05, 0.18);  // Red color
    glVertex2i(0, 600);
    glVertex2i(300, 300);
    glVertex2i(0, 0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Flag of Palestine");
    init();
    glutDisplayFunc(palestineFlag);
    glutMainLoop();
    return 0;
}
