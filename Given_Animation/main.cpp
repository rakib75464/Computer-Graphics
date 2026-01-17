#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;

float _move= 0.0f;

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
	glTranslatef(_move,0.0f, 0.0f); //moving along x-axis
	//glTranslatef(0.0f, _move, 0.0f); //will move along y-axis
	//glTranslatef(_move, _move, 0.0f); //will move diagonally along x&y-axis
    glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(.30f, 0.0f, 0.0f);
        glVertex3f(.30f, 0.2f, 0.0f);
        glVertex3f(0.0f, 0.2f, 0.0f);
	glEnd();
    glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {

    _move += .01;

    if(_move > 1.3){
        _move = -1.3; //when object goes out of display while incrementing its position,
                      //set the coordinate to the opposite position so that it feels like the object is continuously moving
    }

	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(10, update, 0); //Notify GLUT to call update again in 10 milliseconds
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Transformation");
	glutDisplayFunc(drawScene);
	glutTimerFunc(20, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}
