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

void kuwaitFlag()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//Red strip
	glBegin(GL_QUADS);
	glColor3f(0, 0.47, 0.24);
	glVertex2i(0, 0);
	glVertex2i(880, 0);
	glVertex2i(880, 213);
    glVertex2i(0, 213);
    glEnd();

    //White strip
    glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i(0, 213);
	glVertex2i(880, 213);
	glVertex2i(880, 426);
    glVertex2i(0, 426);
    glEnd();

    //Red strip
    glBegin(GL_QUADS);
	glColor3f(0.80, 0.06, 0.14);
	glVertex2i(0, 426);
	glVertex2i(880, 426);
	glVertex2i(880, 640);
    glVertex2i(0, 640);
    glEnd();

    //Black strip
    glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(0, 0);
	glVertex2i(220, 213);
	glVertex2i(220, 426);
    glVertex2i(0, 640);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(880, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("KUWAIT");
    init();
    glutDisplayFunc(kuwaitFlag);
    glutMainLoop();
    return 0;
}
