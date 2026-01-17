#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 880.0, 0.0, 528.0);
}

void togoFlag()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Green strip
    glBegin(GL_QUADS);
    glColor3f(0, 0.41, 0.29);
    glVertex2i(0, 0);
    glVertex2i(880, 0);
    glVertex2i(880, 528);
    glVertex2i(0, 528);
    glEnd();

    // Yellow strip
    glBegin(GL_QUADS);
    glColor3f(1, 0.80, 0);
    glVertex2i(0, 106);
    glVertex2i(880, 106);
    glVertex2i(880, 212);
    glVertex2i(0, 212);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 0.80, 0);
    glVertex2i(0, 318);
    glVertex2i(880, 318);
    glVertex2i(880, 424);
    glVertex2i(0, 424);
    glEnd();

    // Red strip
    glBegin(GL_QUADS);
    glColor3f(0.82, 0.06, 0.21);
    glVertex2i(0, 528);
    glVertex2i(330, 528);
    glVertex2i(330, 212);
    glVertex2i(0, 212);
    glEnd();

    // Star using triangles and polygons
    // 1st triangle
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(90, 290);
    glVertex2i(165, 335);
    glVertex2i(124, 376);
    glEnd();

    // 2nd triangle
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(165, 335);
    glVertex2i(240, 290);
    glVertex2i(206, 376);
    glEnd();

    // 3rd triangle
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(206, 376);
    glVertex2i(268, 422);
    glVertex2i(187, 422);
    glEnd();

    // 4th triangle
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(191, 422);
    glVertex2i(165, 496);
    glVertex2i(139, 422);
    glEnd();

    // 5th triangle
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(143, 422);
    glVertex2i(62, 422);
    glVertex2i(124, 376);
    glEnd();

    // Middle polygon
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(165, 335);
    glVertex2i(206, 376);
    glVertex2i(187, 422);
    glVertex2i(68, 422);
    glVertex2i(124, 376);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(880, 528);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("TOGO");
    init();
    glutDisplayFunc(togoFlag);
    glutMainLoop();
    return 0;
}
