#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 880.0, 0.0, 640.0);
}

void guyanaFlag()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//Green strip
	glBegin(GL_QUADS);
	glColor3f(0, 0.59, 0.22);
    glVertex2i(0, 0);
	glVertex2i(880, 0);
    glVertex2i(880, 640);
	glVertex2i(0, 640);
	glEnd();

    //White strip
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
    glVertex2i(0, 0);
	glVertex2i(880, 320);
    glVertex2i(0, 640);
	glEnd();

	//Yellow strip
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0.81, 0);
    glVertex2i(0, 34);
	glVertex2i(835, 320);
    glVertex2i(0, 606);
	glEnd();

	//Black strip
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
    glVertex2i(0, 0);
	glVertex2i(440, 320);
    glVertex2i(0, 640);
	glEnd();

	//Red strip
	glBegin(GL_TRIANGLES);
	glColor3f(0.93, 0.2, 0.25);
    glVertex2i(0, 32);
	glVertex2i(408, 320);
    glVertex2i(0, 608);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(880, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GUYANA");
    init();
    glutDisplayFunc(guyanaFlag);
    glutMainLoop();
    return 0;
}
