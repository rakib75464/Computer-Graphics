#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    /*glPointSize(20.0);
    glBegin(GL_POINTS);

    // Red point
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(20, 20);

    // Yellow point
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(250, 250);

    // Blue point
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(480, 480);



    glEnd();*/

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(250,0);
    glVertex2f(250,500);


    glVertex2f(0,250);
    glVertex2f(500,250);

    glEnd();

    glBegin(GL_TRIANGLES);

    // Red point
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(30, 280);
    glVertex2f(150, 280);
    glVertex2f(90, 420);



    glEnd();

    glBegin(GL_QUADS);

    // Red point
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(30, 30);
    glVertex2f(80, 30);
    glVertex2f(80, 100);
    glVertex2f(30, 100);



    glEnd();


    glFlush(); // Render now
}

void init() {
    // Set up the 2D orthographic projection with coordinates 0,500,0,500
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position on the screen
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title

    init(); // Initialize after the window is created

    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
