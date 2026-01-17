#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position = 0.0f;
GLfloat speed = 0.1f;

void update(int value)
{

    if(position > 1.0)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

#include <windows.h>
#include <GL/glut.h>

GLfloat i = 0.0f;

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();//Reset the current matrix
    glTranslatef(.4f,.1f,0.0f);

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
        glRotatef(i,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis
        glLineWidth(5.0);
       // glTranslatef(0.f,0.0f,0.f);

        glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0, 0.0f);
        glVertex2f( 0.3, 0.1f);
        glEnd();

    glPopMatrix();
    i+=0.5f;
    glFlush();
}

void display_up()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();//Reset the current matrix
    glTranslatef(.4f,.1f,0.0f);

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
        glRotatef(i,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis
        glLineWidth(5.0);
        // glTranslatef(0.f,0.0f,0.f);

        glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0, 0.0f);
        glVertex2f( 0.3, 0.1f);
        glEnd();

    glPopMatrix();
    i+=0.9f;
    glFlush();
}

void display_down()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();//Reset the current matrix
    glTranslatef(.4f,.1f,0.0f);

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
        glRotatef(i,0.0,0.0,0.1);//i=how many degree you want to rotate around an axis
        glLineWidth(5.0);
       // glTranslatef(0.f,0.0f,0.f);

        glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0, 0.0f);
        glVertex2f( 0.3, 0.1f);
        glEnd();

    glPopMatrix();
    i+=0.1f;
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
    {
    case 'w':
        glutDisplayFunc(display_up);//
        break;
    case 'a':
        glutDisplayFunc(display_down);//
        break;

    glutPostRedisplay();

	}
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
        //do something here
            glutDisplayFunc(display_up);//
            break;

        case GLUT_KEY_DOWN:
            glutDisplayFunc(display_down);//
            break;

        case GLUT_KEY_LEFT:
            //do something here
            break;


        case GLUT_KEY_RIGHT:
            //do something here
            break;
    }
    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		glutDisplayFunc(display_up);
	}
	if (button == GLUT_RIGHT_BUTTON)
	{

		glutDisplayFunc(display_down);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(320, 320);
    glutCreateWindow("Model Transform");
    glutDisplayFunc(display);//

    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.
     glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
   glutMouseFunc(handleMouse);

    glutMainLoop();
    return 0;
}
