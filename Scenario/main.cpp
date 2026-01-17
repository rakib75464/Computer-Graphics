#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init() {
    glClearColor(0.0f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void scene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Grass field
    glColor3f(0.3f, 0.9f, 0.3f);  // Grass color
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 300);
    glVertex2i(0, 300);
    glEnd();

    // House base (side view)
    glColor3f(1.0f, 0.9f, 0.3f);  // House base color
    glBegin(GL_QUADS);
    glVertex2i(300, 200);
    glVertex2i(500, 200);
    glVertex2i(500, 350);
    glVertex2i(300, 350);
    glEnd();

    // Roof (side view)
    glColor3f(0.6f, 0.3f, 0.1f);  // Roof color
    glBegin(GL_TRIANGLES);
    glVertex2i(290, 350);
    glVertex2i(510, 350);
    glVertex2i(400, 450);
    glEnd();

    /*glColor3f(0.6f, 0.1f, 0.1f);  // Roof color
    glBegin(GL_QUADS);
    glVertex2i(400, 450);
    glVertex2i(280, 435);
    glVertex2i(200, 350);
    glVertex2i(290, 350);
    glEnd();

    glColor3f(1.0f, 0.9f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2i(200, 350);
    glVertex2i(200, 250);
    glVertex2i(300, 350);
    glVertex2i(300, 350);*/


    // Door (side view)
    glColor3f(0.5f, 0.0f, 0.0f);  // Door color
    glBegin(GL_QUADS);
    glVertex2i(330, 200);
    glVertex2i(370, 200);
    glVertex2i(370, 300);
    glVertex2i(330, 300);
    glEnd();

    // Window (side view)
    glColor3f(0.6f, 0.3f, 0.1f);  // Window color
    glBegin(GL_QUADS);
    glVertex2i(420, 250);
    glVertex2i(460, 250);
    glVertex2i(460, 290);
    glVertex2i(420, 290);
    glEnd();

    // Window panes (side view)
    glColor3f(1.0f, 1.0f, 1.0f);  // Window panes color
    glBegin(GL_LINES);
    glVertex2i(440, 250);
    glVertex2i(440, 290);
    glVertex2i(420, 270);
    glVertex2i(460, 270);
    glEnd();

    // River with curvy shape
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(80, 25);
    glVertex2i(160, 50);
    glVertex2i(240, 75);
    glVertex2i(320, 100);
    glVertex2i(400, 125);
    glVertex2i(480, 150);
    glVertex2i(560, 175);
    glVertex2i(640, 200);
    glVertex2i(720, 250);
    glVertex2i(800, 300);
    glVertex2i(800, 0);
    glEnd();

    // River border with brown/muddy color
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2i(10, 0);
    glVertex2i(800, 300);
    glVertex2i(800, 280);
    glVertex2i(20, 20);
    glEnd();

    // Curved tree trunk using offset rectangles
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2i(150, 200);
    glVertex2i(170, 200);
    glVertex2i(165, 250);
    glVertex2i(145, 250);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(145, 250);
    glVertex2i(165, 250);
    glVertex2i(160, 300);
    glVertex2i(140, 300);
    glEnd();

    // Tree leaves using polygons
    glColor3f(0.0f, 0.5f, 0.0f);

    // Bottom layer of leaves
    glBegin(GL_POLYGON);
    glVertex2i(120, 300);
    glVertex2i(180, 300);
    glVertex2i(190, 340);
    glVertex2i(150, 360);
    glVertex2i(110, 340);
    glEnd();

    // Middle layer of leaves
    glBegin(GL_POLYGON);
    glVertex2i(130, 340);
    glVertex2i(170, 340);
    glVertex2i(180, 380);
    glVertex2i(150, 400);
    glVertex2i(120, 380);
    glEnd();

    // Top layer of leaves
    glBegin(GL_POLYGON);
    glVertex2i(140, 380);
    glVertex2i(160, 380);
    glVertex2i(170, 410);
    glVertex2i(150, 430);
    glVertex2i(130, 410);
    glEnd();

    glFlush();  // Finish drawing
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scenario");
    init();
    glutDisplayFunc(scene);
    glutMainLoop();

    return 0;
}
