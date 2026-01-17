#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float circleRotateAngle = 0.0f;

float carPosX = 50.0f;
float carPosX2 = -50.0f;

void circle(float radius, float x, float y, int r, int g, int b) {
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (int i = 0; i < 360; i++) {
        float angle = i * (3.1416 / 180);
        float px = x + radius * cos(angle);
        float py = y + radius * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}

void circleL(float radius, float x, float y, int r, int g, int b, float angle) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    circle(radius, 0.0f, 0.0f, r, g, b);
    glPopMatrix();
}

void skyMorning(){
    glBegin(GL_POLYGON);
    glColor3ub(216, 232, 240);
    glVertex2f(50.0f, 50.0f);
    glColor3ub(216, 232, 240);
    glVertex2f(-50.0f, 50.0f);
    glColor3ub(216, 232, 240);
    glVertex2f(-50.0f, -7.0f);
    glColor3ub(216, 232, 240);
    glVertex2f(50.0f, -7.0f);
    glEnd();
}

void drawSun(float x, float y) {
    circle(4.0f, x, y, 255, 255, 0);
}
void road() {

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-50, -10);
    glVertex2f(50, -10);
    glVertex2f(50, -17);
    glVertex2f(-50, -17);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glLineWidth(2);
    glColor3f(1, 1.0, 1.0);
    glVertex2f(-50, -10.155);
    glVertex2f(50, -10.155);
    glEnd();
    glLineWidth(1);

    glBegin(GL_LINES);
    glLineWidth(1);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(-50, -12.955);
    glVertex2i(50, -12.955);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(-50, -17);
    glVertex2i(50, -17);
    glEnd();
}

void car(float translationX, float translationY) {

    glBegin(GL_POLYGON);
    glColor3ub(163, 72, 104);
    glVertex2f(10.0f + translationX, 1.5f + translationY);
    glVertex2f(8.5f + translationX, 1.2f + translationY);
    glVertex2f(8.5f + translationX, -1.0f + translationY);
    glVertex2f(16.5f + translationX, -1.0f + translationY);
    glVertex2f(16.25f + translationX, 1.2f + translationY);
    glVertex2f(15.0f + translationX, 1.5f + translationY);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(156, 224, 247);
    glVertex2f(10.5f + translationX, 2.5f + translationY);
    glVertex2f(10.0f + translationX, 1.5f + translationY);
    glVertex2f(10.5f + translationX, -0.9f + translationY);
    glVertex2f(15.8f + translationX, -0.6f + translationY);
    glVertex2f(15.0f + translationX, 1.5f + translationY);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(11.0f + translationX, 0.0f + translationY);
    glVertex2f(10.0f + translationX, -1.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(12.0f + translationX, 0.0f + translationY);
    glVertex2f(12.0f + translationX, -1.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(14.0f + translationX, 0.0f + translationY);
    glVertex2f(14.0f + translationX, -1.0f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(14.2f + translationX, 0.0f + translationY);
    glVertex2f(15.0f + translationX, -0.8f + translationY);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(163, 72, 104);
    glVertex2f(11.0f + translationX, 0.0f + translationY);
    glVertex2f(15.0f + translationX, 0.0f + translationY);
    glVertex2f(14.0f + translationX, 2.5f + translationY);
    glVertex2f(10.5f + translationX, 2.5f + translationY);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 99);
    glVertex2f(8.5f + translationX, -1.0f + translationY);
    glVertex2f(16.5f + translationX, -1.0f + translationY);
    glVertex2f(16.5f + translationX, -2.5f + translationY);
    glVertex2f(8.5f + translationX, -2.5f + translationY);
    glEnd();

    circle(0.5, 10.5f + translationX, -2.5f + translationY, 0, 0, 0);
    circle(0.5, 14.5f + translationX, -2.5f + translationY, 0, 0, 0);
    circleL(0.3, 10.5f + translationX, -2.5f + translationY, 255, 255, 255, circleRotateAngle);
    circleL(0.3, 14.5f + translationX, -2.5f + translationY, 255, 255, 255, circleRotateAngle);
    circle(0.2, 10.5f + translationX, -2.5f + translationY, 255, 255, 255);
    circle(0.2, 14.5f + translationX, -2.5f + translationY, 255, 255, 255);
}

void car2(float translationX, float translationY) {

    glBegin(GL_POLYGON);
    glColor3ub(163, 72, 104);
    glVertex2f(10.0f + translationX, 1.5f + translationY);
    glVertex2f(8.5f + translationX, 1.2f + translationY);
    glVertex2f(8.5f + translationX, -1.0f + translationY);
    glVertex2f(16.5f + translationX, -1.0f + translationY);
    glVertex2f(16.25f + translationX, 1.2f + translationY);
    glVertex2f(15.0f + translationX, 1.5f + translationY);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(156, 224, 247);
    glVertex2f(10.5f + translationX, 2.5f + translationY);
    glVertex2f(10.0f + translationX, 1.5f + translationY);
    glVertex2f(10.5f + translationX, -0.9f + translationY);
    glVertex2f(15.8f + translationX, -0.6f + translationY);
    glVertex2f(15.0f + translationX, 1.5f + translationY);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(11.0f + translationX, 0.0f + translationY);
    glVertex2f(10.0f + translationX, -1.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(12.0f + translationX, 0.0f + translationY);
    glVertex2f(12.0f + translationX, -1.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(14.0f + translationX, 0.0f + translationY);
    glVertex2f(14.0f + translationX, -1.0f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(14.2f + translationX, 0.0f + translationY);
    glVertex2f(15.0f + translationX, -0.8f + translationY);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(163, 72, 104);
    glVertex2f(11.0f + translationX, 0.0f + translationY);
    glVertex2f(15.0f + translationX, 0.0f + translationY);
    glVertex2f(14.0f + translationX, 2.5f + translationY);
    glVertex2f(10.5f + translationX, 2.5f + translationY);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 99);
    glVertex2f(8.5f + translationX, -1.0f + translationY);
    glVertex2f(16.5f + translationX, -1.0f + translationY);
    glVertex2f(16.5f + translationX, -2.5f + translationY);
    glVertex2f(8.5f + translationX, -2.5f + translationY);
    glEnd();

    circle(0.5, 10.5f + translationX, -2.5f + translationY, 0, 0, 0);
    circle(0.5, 14.5f + translationX, -2.5f + translationY, 0, 0, 0);
    circleL(0.3, 10.5f + translationX, -2.5f + translationY, 255, 255, 255, circleRotateAngle);
    circleL(0.3, 14.5f + translationX, -2.5f + translationY, 255, 255, 255, circleRotateAngle);
    circle(0.2, 10.5f + translationX, -2.5f + translationY, 255, 255, 255);
    circle(0.2, 14.5f + translationX, -2.5f + translationY, 255, 255, 255);
}

 void river() {
    glBegin(GL_QUADS);
    glColor3ub(17, 109, 130);
    glVertex2f(-50.0f, -17.0f);
    glVertex2f(50.0f, -17.0f);
    glVertex2f(50.0f, -50.0f);
    glVertex2f(-50.0f, -50.0f);
    glEnd();
}

 void grass25() {
    glBegin(GL_QUADS);
    glColor3ub(89, 158, 79);
    glVertex2f(-50, -24);
    glVertex2f(50, -24);
    glVertex2f(50, -17);
    glVertex2f(-50, -17);
    glEnd();
}
 void building() {

    glBegin(GL_POLYGON);
    glColor3ub(82, 90, 99);
    glVertex2f(-0, -6.5);
    glVertex2f(-0, 8);
    glVertex2f(-15, 8);
    glVertex2f(-15, -6.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-2, -5.5);
    glVertex2f(-2, 6);
    glVertex2f(-13, 6);
    glVertex2f(-13, -5.5);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-2, -5.5);
    glVertex2f(-2, 6);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-13, 6);
    glVertex2f(-2, 6);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-13, 6);
    glVertex2f(-13, -5.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-2, -5.5);
    glVertex2f(-13, -5.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-2, -0.25);
    glVertex2f(-13, -0.25);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-6, -5.5);
    glVertex2f(-6, 6);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-9, -5.5);
    glVertex2f(-9, 6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(82, 90, 99);
    glVertex2f(-0, -6.5);
    glVertex2f(-0, 21.5);
    glVertex2f(15, 21.5);
    glVertex2f(15, -6.5);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(0, -6.5);
    glVertex2f(0, 21.5);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-16, 8);
    glVertex2f(15, 8);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(15, -6.5);
    glVertex2f(15, 21.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52, 67, 64);
    glVertex2f(13, 10);
    glVertex2f(13, 20);
    glVertex2f(2, 20);
    glVertex2f(2, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(12.5, 10.5);
    glVertex2f(12.5, 19.5);
    glVertex2f(2.5, 19.5);
    glVertex2f(2.5, 10.5);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(2.5, 17);
    glVertex2f(12.5, 17);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(2.5, 13);
    glVertex2f(12.5, 13);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(4, 19.5);
    glVertex2f(4, 10.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(7, 19.5);
    glVertex2f(7, 10.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(11, 19.5);
    glVertex2f(11, 10.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52, 67, 64);
    glVertex2f(7.25, -6.5);
    glVertex2f(7.25, 6);
    glVertex2f(4.25, 6);
    glVertex2f(4.25, -6.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    glVertex2f(7, -6.25);
    glVertex2f(7, 5.75);
    glVertex2f(4.5, 5.75);
    glVertex2f(4.5, -6.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52, 67, 64);
    glVertex2f(7.75, -6.5);
    glVertex2f(7.75, 6);
    glVertex2f(10.75, 6);
    glVertex2f(10.75, -6.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    glVertex2f(8, -6.25);
    glVertex2f(8, 5.75);
    glVertex2f(10.5, 5.75);
    glVertex2f(10.5, -6.25);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(8, -4.5);
    glVertex2f(10.5, -4.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(7, -4.5);
    glVertex2f(4.5, -4.5);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    skyMorning();

    drawSun(0.0f, 40.0f);
    road();
     river();
     grass25();
     building();

    car(carPosX, -12.0f);
    carPosX -= 0.02f;

     car2(carPosX2, -12.0f);
    carPosX2 += 0.02f;

    if (carPosX < -80.0f) {
        carPosX = 80.0f;
    }

    if (carPosX2 > 80.0f) {
        carPosX2 = -80.0f;
    }
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 800);
    glutCreateWindow("OpenGL Scene");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
    return 0;
}
