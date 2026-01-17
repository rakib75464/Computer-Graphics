#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float angle1 = 0.0f;
float ship1TranslationX = 0.0f;
float ship2TranslationX = 0.0f;
float ship1TranslationY = 0.0f;
float ship2TranslationY = 0.0f;
bool moveShip = false;

void circle(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void skyMorning() {
    glBegin(GL_POLYGON);
    glColor3ub(216, 232, 240);
    glVertex2f(50.0f, 40.0f);
    glVertex2f(-50.0f, 40.0f);
    glVertex2f(-50.0f, 25.0f);
    glVertex2f(50.0f, 25.0f);
    glEnd();
}

void sun2() {
    circle(1.5, 43.7, 36.0f, 252, 252, 3);
}

void river1() {
    glBegin(GL_POLYGON);
    glColor3ub(17, 109, 130);
    glVertex2f(-50.0f, 25.0f);
    glColor3ub(38, 136, 158);
    glVertex2f(50.0f, 25.0f);
    glColor3ub(101, 181, 199);
    glVertex2f(50.0f, -9.0f);
    glColor3ub(129, 198, 214);
    glVertex2f(-50.0f, -9.0f);
    glEnd();
}

void river2() {
    glBegin(GL_POLYGON);
    glColor3ub(101, 181, 199);
    glVertex2f(-50.0f, -9.0f);
    glColor3ub(129, 198, 214);
    glVertex2f(50.0f, -9.0f);
    glVertex2f(50.0f, -40.0f);
    glVertex2f(-50.0f, -40.0f);
    glEnd();
}

void ship1Window() {
    glBegin(GL_POLYGON);
    glColor3ub(216, 237, 240);
    glVertex2f(46.0f, 2.0f);
    glVertex2f(46.0f, 6.0f);
    glVertex2f(43.0f, 6.0f);
    glVertex2f(43.0f, 2.0f);
    glEnd();
}

void ship1SideView() {
    if (angle1 == 0.0f) {
        //body
        glBegin(GL_POLYGON);
        glColor3ub(204, 157, 110);
        glVertex2f(48.0f, -9.0f);
        glVertex2f(50.0f, 1.0f);
        glVertex2f(15.0f, 1.0f);
        glVertex2f(18.0f, -9.0f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub(194, 150, 107);
        glVertex2f(22.0f, -9.0f);
        glVertex2f(15.0f, 1.0f);
        glVertex2f(18.0f, -9.0f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(17.5f, -7.0f);
        glVertex2f(48.4f, -7.0f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(17.6f, -7.5f);
        glVertex2f(48.3f, -7.5f);
        glEnd();
        //layer1
        glBegin(GL_POLYGON);
        glColor3ub(219, 212, 193);
        glVertex2f(47.0f, 1.0f);
        glVertex2f(47.0f, 7.0f);
        glVertex2f(24.0f, 7.0f);
        glVertex2f(22.0f, 1.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(204, 157, 110);
        glVertex2f(48.0f, 9.0f);
        glVertex2f(48.0f, 7.0f);
        glVertex2f(24.0f, 7.0f);
        glVertex2f(24.0f, 9.0f);
        glEnd();
        //layer2
        glBegin(GL_POLYGON);
        glColor3ub(219, 212, 193);
        glVertex2f(46.0f, 9.0f);
        glVertex2f(46.0f, 15.0f);
        glVertex2f(27.0f, 15.0f);
        glVertex2f(25.0f, 9.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(204, 157, 110);
        glVertex2f(47.0f, 17.0f);
        glVertex2f(47.0f, 15.0f);
        glVertex2f(27.0f, 15.0f);
        glVertex2f(27.0f, 17.0f);
        glEnd();
        ship1Window();

        glBegin(GL_POLYGON);
        glColor3ub(216, 237, 240);
        glVertex2f(25.0f, 2.0f);
        glVertex2f(25.0f, 6.0f);
        glVertex2f(23.8f, 6.0f);
        glVertex2f(22.4f, 2.0f);
        glEnd();
        //layer2

        glBegin(GL_POLYGON);
        glColor3ub(216, 237, 240);
        glVertex2f(27.0f, 10.0f);
        glVertex2f(27.0f, 14.0f);
        glVertex2f(26.7f, 14.0f);
        glVertex2f(25.4f, 10.0f);
        glEnd();
        //railings
        glLineWidth(5.0f);
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
glVertex2f(25.2f, 3.0f);
glVertex2f(15.0f, 3.0f);

glVertex2f(15.15f, 3.0f);
glVertex2f(15.15f, 1.0f);

glVertex2f(25.15f, 3.0f);
glVertex2f(26.0f, 1.0f);
glEnd();
glLineWidth(3.0f);
glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(16.2f, 3.0f);
glVertex2f(16.2f, 1.0f);

glVertex2f(17.2f, 3.0f);
glVertex2f(17.2f, 1.0f);

glVertex2f(18.2f, 3.0f);
glVertex2f(18.2f, 1.0f);

glVertex2f(19.2f, 3.0f);
glVertex2f(19.2f, 1.0f);

glVertex2f(20.2f, 3.0f);
glVertex2f(20.2f, 1.0f);

glVertex2f(21.2f, 3.0f);
glVertex2f(21.2f, 1.0f);

glVertex2f(22.2f, 3.0f);
glVertex2f(22.2f, 1.0f);

glVertex2f(23.2f, 3.0f);
glVertex2f(23.2f, 1.0f);

glVertex2f(24.2f, 3.0f);
glVertex2f(24.2f, 1.0f);
glEnd();
glLineWidth(1.0f);
    } else {
        glPushMatrix();
        glTranslatef(18.0f, 5.0f, 0.0f);
        glRotatef(angle1, 0.0f, 0.0f, 1.0f);
        glTranslatef(-18.0f, -5.0f, 0.0f);
        // ... (rest of the ship1SideView code with translations)
        glPopMatrix();
    }
}


void ship2SideView() {
    if (angle1 == 0.0f) {
        //body
        glBegin(GL_POLYGON);
        glColor3ub(237, 221, 236);
        glVertex2f(-50.0f, -9.0f);
        glVertex2f(-50.0f, 1.0f);
        glVertex2f(-16.0f, 1.0f);
        glVertex2f(-22.0f, -9.0f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub(209, 199, 208);
        glVertex2f(-16.0f, 1.0f);
        glVertex2f(-22.0f, -9.0f);
        glVertex2f(-28.0f, -9.0f);
        glEnd();
        glPointSize(8.0);
        glBegin(GL_POINTS);
        glColor3ub(4, 130, 73);
        for (float x = 0.0f; x <= 22.0f; x++) {
            glVertex2f(-49.0f + x, -7.0f);
        }
        glEnd();
        glPointSize(5.0);
        glBegin(GL_POINTS);
        glColor3ub(161, 181, 172);
        for (float x = 0.0f; x <= 20.0f; x++) {
            glVertex2f(-49.0f + x, -3.0f);
        }
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-32.0f, 1.0f);
        glVertex2f(-20.0f, 1.0f);
        glVertex2f(-23.0f, 15.0f);
        glVertex2f(-30.0f, 15.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-45.0f, 1.0f);
        glVertex2f(-23.0f, 1.0f);
        glVertex2f(-23.0f, 10.0f);
        glVertex2f(-45.0f, 10.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-45.0f, 15.0f);
        glVertex2f(-40.0f, 15.0f);
        glVertex2f(-40.0f, 10.0f);
        glVertex2f(-45.0f, 10.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-50.0f, 1.0f);
        glVertex2f(-45.5f, 1.0f);
        glVertex2f(-45.5f, 9.0f);
        glVertex2f(-48.0f, 9.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-48.0f, 11.0f);
        glVertex2f(-45.5f, 11.0f);
        glVertex2f(-45.5f, 7.0f);
        glVertex2f(-48.0f, 7.0f);
        glEnd();
        //window
        glPointSize(38.0);
        glBegin(GL_POINTS);
        glColor3ub(42, 99, 163);
        glVertex2f(-28.5f, 12.0f);
        glEnd();
        glPointSize(38.0);
        glBegin(GL_POINTS);
        glColor3ub(42, 99, 163);
        glVertex2f(-25.5f, 12.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(42, 99, 163);
        glVertex2f(-23.8f, 14.0f);
        glVertex2f(-22.75f, 14.0f);
        glVertex2f(-21.9f, 10.0f);
        glVertex2f(-23.8f, 10.0f);
        glEnd();
        for (float x = 0.0f; x <= 18.0f; x = x + 3) {
            glPointSize(38.0);
            glBegin(GL_POINTS);
            glColor3ub(71, 91, 158);
            glVertex2f(-25.5f - x, 6.0f);
            glEnd();
        }
        glBegin(GL_POLYGON);
        glColor3ub(71, 91, 158);
        glVertex2f(-23.8f, 8.0f);
        glVertex2f(-21.4f, 8.0f);
        glVertex2f(-20.6f, 4.0f);
        glVertex2f(-23.8f, 4.0f);
        glEnd();
    } else {
        glPushMatrix();
        glTranslatef(-18.0f, -5.0f, 0.0f);
        glRotatef(-angle1, 0.0f, 0.0f, 1.0f);
        glTranslatef(18.0f, 5.0f, 0.0f);
        //body
        glBegin(GL_POLYGON);
        glColor3ub(237, 221, 236);
        glVertex2f(-50.0f, -9.0f);
        glVertex2f(-50.0f, 1.0f);
        glVertex2f(-16.0f, 1.0f);
        glVertex2f(-22.0f, -9.0f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub(209, 199, 208);
        glVertex2f(-16.0f, 1.0f);
        glVertex2f(-22.0f, -9.0f);
        glVertex2f(-28.0f, -9.0f);
        glEnd();
        glPointSize(8.0);
        glBegin(GL_POINTS);
        glColor3ub(4, 130, 73);
        for (float x = 0.0f; x <= 22.0f; x++) {
            glVertex2f(-49.0f + x, -7.0f);
        }
        glEnd();
        glPointSize(5.0);
        glBegin(GL_POINTS);
        glColor3ub(161, 181, 172);
        for (float x = 0.0f; x <= 20.0f; x++) {
            glVertex2f(-49.0f + x, -3.0f);
        }
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-32.0f, 1.0f);
        glVertex2f(-20.0f, 1.0f);
        glVertex2f(-23.0f, 15.0f);
        glVertex2f(-30.0f, 15.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-45.0f, 1.0f);
        glVertex2f(-23.0f, 1.0f);
        glVertex2f(-23.0f, 10.0f);
        glVertex2f(-45.0f, 10.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-45.0f, 15.0f);
        glVertex2f(-40.0f, 15.0f);
        glVertex2f(-40.0f, 10.0f);
        glVertex2f(-45.0f, 10.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-50.0f, 1.0f);
        glVertex2f(-45.5f, 1.0f);
        glVertex2f(-45.5f, 9.0f);
        glVertex2f(-48.0f, 9.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(187, 232, 240);
        glVertex2f(-48.0f, 11.0f);
        glVertex2f(-45.5f, 11.0f);
        glVertex2f(-45.5f, 7.0f);
        glVertex2f(-48.0f, 7.0f);
        glEnd();
        //window
        glPointSize(38.0);
        glBegin(GL_POINTS);
        glColor3ub(42, 99, 163);
        glVertex2f(-28.5f, 12.0f);
        glEnd();
        glPointSize(38.0);
        glBegin(GL_POINTS);
        glColor3ub(42, 99, 163);
        glVertex2f(-25.5f, 12.0f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(42, 99, 163);
        glVertex2f(-23.8f, 14.0f);
        glVertex2f(-22.75f, 14.0f);
        glVertex2f(-21.9f, 10.0f);
        glVertex2f(-23.8f, 10.0f);
        glEnd();
        for (float x = 0.0f; x <= 18.0f; x = x + 3) {
            glPointSize(38.0);
            glBegin(GL_POINTS);
            glColor3ub(71, 91, 158);
            glVertex2f(-25.5f - x, 6.0f);
            glEnd();
        }
        glBegin(GL_POLYGON);
        glColor3ub(71, 91, 158);
        glVertex2f(-23.8f, 8.0f);
        glVertex2f(-21.4f, 8.0f);
        glVertex2f(-20.6f, 4.0f);
        glVertex2f(-23.8f, 4.0f);
        glEnd();
        glPopMatrix();
    }
}
void updateShip(int value) {
    if (moveShip) {
            if(ship1TranslationX>-18.0f){
        ship1TranslationX -= 0.1f;}

        else{
            ship1TranslationX = -18.0f;
            ship2TranslationX = 18.0f;
            ship1TranslationY -= 0.04f;
            if(ship1TranslationY<-2.0f){
            ship2TranslationY -= 0.02f;
            }
        if (angle1 < 5.0f) {
            angle1 += 0.8f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateShip, 0);
    }
}
}

void displayScene3Morning() {
    glClear(GL_COLOR_BUFFER_BIT);

    skyMorning();
    sun2();
    river1();

    ship1SideView();
    ship2SideView();
    river2();
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
    case 'a':
        moveShip = !moveShip;
        if (moveShip)
            glutTimerFunc(16, updateShip, 0);
        break;
    }
}

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -40.0, 40.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Scenario 3");
    glutKeyboardFunc(handleKeypress);
    glutDisplayFunc(displayScene3Morning);
    myInit();
    glutMainLoop();
    return 0;
}
