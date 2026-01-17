  #include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
#include<string.h>
#include<windows.h>

float  tx = 10, rx = 10;

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void round(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void init(void)
{
    glClearColor(0.0f, 0.90f, 0.90f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void road()
{
    glColor3f(0.0f, 0.50f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(500, 0);
    glVertex2i(500, 75);
    glVertex2i(0, 75);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(500, 0);
    glVertex2i(500, 55);
    glVertex2i(0, 55);
    glEnd();

    glColor3f(0.41f, 0.41f, 0.41f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(500, 0);
    glVertex2i(500, 50);
    glVertex2i(0, 50);
    glEnd();
}

void sun()
{
    glColor3f(1.0f, 1.0f, 0.0f);
    circle(20, 30, 450, 450);
}

 void tree() {

    glColor3f(0.0f, 0.39f, 0.0f);


    glBegin(GL_TRIANGLES);
    glVertex2i(30, 150);
    glVertex2i(70, 150);
    glVertex2i(50, 200);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2i(20, 120);
    glVertex2i(80, 120);
    glVertex2i(50, 170);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2i(10, 90);
    glVertex2i(90, 90);
    glVertex2i(50, 130);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2i(0, 60);
    glVertex2i(100, 60);
    glVertex2i(50, 100);
    glEnd();


    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2i(45, 50);
    glVertex2i(55, 50);
    glVertex2i(55, 100);
    glVertex2i(45, 100);
    glEnd();
}


void hut() {
    // Hut base
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2i(250, 180);
    glVertex2i(350, 180);
    glVertex2i(350, 250);
    glVertex2i(250, 250);
    glEnd();

    // Hut roof (Triangle)
    glColor3f(0.8f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2i(240, 250);
    glVertex2i(360, 250);
    glVertex2i(300, 300);
    glEnd();

    // Door
    glColor3f(0.45f, 0.23f, 0.12f);
    glBegin(GL_POLYGON);
    glVertex2i(290, 180);
    glVertex2i(310, 180);
    glVertex2i(310, 220);
    glVertex2i(290, 220);
    glEnd();
}


void clouds2()
{
    glPushMatrix();
    glTranslatef(rx, 0, 0);

    glColor3f(0.86f, 0.86f, 0.86f);
    circle(20, 30, 460, 460);
    circle(15, 20, 445, 460);
    circle(15, 20, 475, 460);
    circle(20, 30, 390, 420);
    circle(15, 20, 405, 420);
    circle(15, 20, 375, 420);

    glPopMatrix();

    rx += 0.2;
    if (rx > 475)
        rx = -475;

    glutPostRedisplay();
}

void car() {
    glPushMatrix();
    glTranslatef(tx, 0, 0);


    glColor3f(0.2f, 0.2f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(150, 40);
    glVertex2i(250, 40);
    glVertex2i(250, 80);
    glVertex2i(150, 80);
    glEnd();


    glColor3f(0.2f, 0.2f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(160, 80);
    glVertex2i(240, 80);
    glVertex2i(230, 100);
    glVertex2i(170, 100);
    glEnd();


    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2i(170, 80);
    glVertex2i(210, 80);
    glVertex2i(210, 100);
    glVertex2i(170, 100);
    glEnd();


    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2i(210, 80);
    glVertex2i(230, 80);
    glVertex2i(230, 100);
    glVertex2i(210, 100);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    circle(12, 12, 170, 40);
    circle(12, 12, 230, 40);


    glColor3f(0.7f, 0.7f, 0.7f);
    circle(6, 6, 170, 40);
    circle(6, 6, 230, 40);


    glColor3f(1.0f, 1.0f, 0.0f);
    circle(4, 4, 245, 60);
    circle(4, 4, 155, 60);

    glPopMatrix();

    tx -= 0.2;
    if (tx < -250) {
        tx = 500;
    }

    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.12f, 0.56f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(500, 0);
    glVertex2i(500, 500);
    glVertex2i(0, 500);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(500, 0);
    glVertex2i(500, 180);
    glVertex2i(0, 180);
    glEnd();

    road();
    sun();
    tree();
    hut();
    car();
    clouds2();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Moving cars project");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
