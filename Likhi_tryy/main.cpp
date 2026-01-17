#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float cloudTranslationXLK = 0.0f;
bool moveCloudsLK = false;
float ship1TranslationXLK = 0.0f;
float ship2TranslationXLK = 0.0f;
float ship1TranslationYLK = 0.0f;
float ship2TranslationYLK = 0.0f;
bool moveShipLK = false;
float angle1LK = 0.0f;
float sun2TranslationYLK = 0.0f;
bool moveSun2DownLK = false;
bool isRainingLK = false;
const int numRaindropsLK = 500;
float raindropXLK[numRaindropsLK];
float raindropYLK[numRaindropsLK];
float wavePositionLK = -1.0f;
const float waveAmplitudeLK = 0.1f;
const float waveFrequencyLK = 0.5f;
const float waveWidthLK = 0.02f;

void circleLK(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void updateRainLK(int value) {
    if (isRainingLK) {
        for (int i = 0; i < numRaindropsLK; ++i) {
            raindropYLK[i] -= 0.5f;
            if (raindropYLK[i] < -30.0f) {
                raindropYLK[i] = 30.0f;
            }
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateRainLK, 0);
    }
}

void raindropsLK() {
    if (!isRainingLK) return;
    glColor3ub(135, 206, 250);
    for (int i = 0; i < numRaindropsLK; ++i) {
        glBegin(GL_LINE_STRIP);
        glVertex2f(raindropXLK[i], raindropYLK[i]);
        glVertex2f(raindropXLK[i], raindropYLK[i] - 0.5f);
        glEnd();
    }
}

void resetRainLK() {
    isRainingLK = false;
    for (int i = 0; i < numRaindropsLK; ++i) {
        raindropXLK[i] = 100.0f;
        raindropYLK[i] = 100.0f;
    }
}

void skyEveningLK() {
    glBegin(GL_POLYGON);
    glColor3ub(209, 128, 84);
    glVertex2f(50.0f, 40.0f);
    glColor3ub(122, 212, 240);
    glVertex2f(-50.0f, 40.0f);
    glColor3ub(245, 202, 166);
    glVertex2f(-50.0f, 25.0f);
    glColor3ub(160, 186, 222);
    glVertex2f(50.0f, 25.0f);
    glEnd();
}

void skyNightLK() {
    glBegin(GL_POLYGON);
    glColor3ub(8, 32, 64);
    glVertex2f(50.0f, 40.0f);
    glColor3ub(50, 54, 59);
    glVertex2f(-50.0f, 40.0f);
    glColor3ub(3, 30, 64);
    glVertex2f(-50.0f, 25.0f);
    glColor3ub(2, 19, 41);
    glVertex2f(50.0f, 25.0f);
    glEnd();
}

void skyMorningLK() {
    glBegin(GL_POLYGON);
    glColor3ub(216, 232, 240);
    glVertex2f(50.0f, 40.0f);
    glColor3ub(204, 228, 240);
    glVertex2f(-50.0f, 40.0f);
    glColor3ub(192, 224, 240);
    glVertex2f(-50.0f, 25.0f);
    glColor3ub(125, 193, 227);
    glVertex2f(50.0f, 25.0f);
    glEnd();
}

void skyRainLK() {
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);
    glVertex2f(50.0f, 40.0f);
    glVertex2f(-50.0f, 40.0f);
    glVertex2f(-50.0f, 25.0f);
    glVertex2f(50.0f, 25.0f);
    glEnd();
}

void waveLK(float yOffset) {
    glBegin(GL_QUADS);
    glColor3ub(31, 132, 156);
    for (float i = -50.0f; i < 50.0f; i += waveWidthLK) {
        float xOffset = fmod(wavePositionLK + i, 2.0f);
        float waveYOffset = waveAmplitudeLK * sin(2 * 3.14159 * waveFrequencyLK * xOffset);
        glVertex2f(i, -0.5f + yOffset);
        glVertex2f(i, waveYOffset + yOffset);
        glVertex2f(i + waveWidthLK, waveYOffset + yOffset);
        glVertex2f(i + waveWidthLK, -0.5f + yOffset);
    }
    glEnd();
}

void wave2LK(float yOffset) {
    glBegin(GL_QUADS);
    glColor3ub(78, 170, 191);
    for (float i = -50.0f; i < 50.0f; i += waveWidthLK) {
        float xOffset = fmod(wavePositionLK + i, 2.0f);
        float waveYOffset = waveAmplitudeLK * sin(2 * 3.14159 * waveFrequencyLK * xOffset);
        glVertex2f(i, -0.5f + yOffset);
        glVertex2f(i, waveYOffset + yOffset);
        glVertex2f(i + waveWidthLK, waveYOffset + yOffset);
        glVertex2f(i + waveWidthLK, -0.5f + yOffset);
    }
    glEnd();
}

void riverLK() {
    glBegin(GL_POLYGON);
    glColor3ub(17, 109, 130);
    glVertex2f(-50.0f, 25.0f);
    glColor3ub(38, 136, 158);
    glVertex2f(50.0f, 25.0f);
    glColor3ub(101, 181, 199);
    glVertex2f(50.0f, -40.0f);
    glColor3ub(129, 198, 214);
    glVertex2f(-50.0f, -40.0f);
    glEnd();
}

void cloudLK(float translationX, float translationY) {
    circleLK(0.6, 45.0 + translationX, 35.0 + translationY, 255, 255, 255);
    circleLK(0.6, 45.0 + translationX, 34.2 + translationY, 255, 255, 255);
    circleLK(0.6, 43.8 + translationX, 35.0 + translationY, 255, 255, 255);
    circleLK(0.6, 43.8 + translationX, 34.2 + translationY, 255, 255, 255);
    circleLK(0.6, 43.0 + translationX, 34.6 + translationY, 255, 255, 255);
    circleLK(0.6, 46.0 + translationX, 34.6 + translationY, 255, 255, 255);
    circleLK(0.6, 44.0 + translationX, 34.6 + translationY, 255, 255, 255);
}

void sun2LK(float translationX, float translationY) {
    circleLK(1.5, 43.7 + translationX, 36.0f + translationY, 252, 252, 3);
}

void moonLK(float radius, float xc, float yc, float r, float g, float b) {
    circleLK(radius, xc, yc, r, g, b);
    glColor3ub(0, 0, 0);
    circleLK(radius * 0.7, xc + radius * 0.4, yc, 8, 32, 64);
}

void starLK(float x, float y, float size) {
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    for (int i = 0; i < 5; ++i) {
        float angle1 = i * 2.0 * 3.14159 / 5;
        float angle2 = (i + 2) * 2.0 * 3.14159 / 5;
        glVertex2f(x, y);
        glVertex2f(x + size * cos(angle1), y + size * sin(angle1));
        glVertex2f(x + size * cos(angle2), y + size * sin(angle2));
    }
    glEnd();
}

void cloudsForRainLK(float translationX, float translationY) {
    circleLK(0.6, 45.0 + translationX, 35.0 + translationY, 82, 74, 70);
    circleLK(0.6, 45.0 + translationX, 34.2 + translationY, 105, 95, 91);
    circleLK(0.6, 43.8 + translationX, 35.0 + translationY, 82, 74, 70);
    circleLK(0.6, 43.8 + translationX, 34.2 + translationY, 105, 95, 91);
    circleLK(0.6, 43.0 + translationX, 34.6 + translationY, 110, 103, 100);
    circleLK(0.6, 46.0 + translationX, 34.6 + translationY, 105, 95, 91);
    circleLK(0.6, 44.0 + translationX, 34.6 + translationY, 110, 103, 100);
}

void shipWindowLK(float translationX, float translationY) {
    glBegin(GL_POLYGON);
    glColor3ub(216, 237, 240);
    glVertex2f(46.0f + translationX, 2.0f + translationY);
    glVertex2f(46.0f + translationX, 6.0f + translationY);
    glVertex2f(43.0f + translationX, 6.0f + translationY);
    glVertex2f(43.0f + translationX, 2.0f + translationY);
    glEnd();
}

void ship1SideViewLK(float translationX, float translationY) {
     if(translationX==-18){
            glPushMatrix();
        glTranslatef(18.0f, 5.0f, 0.0f);
        glRotatef(angle1LK, 0.0f, 0.0f, 1.0f);
        glTranslatef(-18.0f, -5.0f, 0.0f);
    //body
    glBegin(GL_POLYGON);
    glColor3ub(204, 157, 110);
    glVertex2f(48.0f + translationX, -9.0f + translationY);
    glVertex2f(50.0f + translationX, 1.0f + translationY);
    glVertex2f(15.0f + translationX, 1.0f + translationY);
    glVertex2f(18.0f + translationX, -9.0f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(194,150,107);
    glVertex2f(22.0f + translationX, -9.0f + translationY);
    glVertex2f(15.0f + translationX, 1.0f + translationY);
    glVertex2f(18.0f + translationX, -9.0f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(17.5f + translationX, -7.0f + translationY);
    glVertex2f(48.4f + translationX, -7.0f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(17.6f + translationX, -7.5f + translationY);
    glVertex2f(48.3f + translationX, -7.5f + translationY);
    glEnd();
    //layer1
    glBegin(GL_POLYGON);
    glColor3ub(219,212,193);
    glVertex2f(47.0f + translationX, 1.0f + translationY);
    glVertex2f(47.0f + translationX, 7.0f + translationY);
    glVertex2f(24.0f + translationX, 7.0f + translationY);
    glVertex2f(22.0f + translationX, 1.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 157, 110);
    glVertex2f(48.0f + translationX, 9.0f + translationY);
    glVertex2f(48.0f + translationX, 7.0f + translationY);
    glVertex2f(24.0f + translationX, 7.0f + translationY);
    glVertex2f(24.0f + translationX, 9.0f + translationY);
    glEnd();
    //layer2
    glBegin(GL_POLYGON);
    glColor3ub(219,212,193);
    glVertex2f(46.0f + translationX, 9.0f + translationY);
    glVertex2f(46.0f + translationX, 15.0f + translationY);
    glVertex2f(27.0f + translationX, 15.0f + translationY);
    glVertex2f(25.0f + translationX, 9.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 157, 110);
    glVertex2f(47.0f + translationX, 17.0f + translationY);
    glVertex2f(47.0f + translationX, 15.0f + translationY);
    glVertex2f(27.0f + translationX, 15.0f + translationY);
    glVertex2f(27.0f + translationX, 17.0f + translationY);
    glEnd();
    //window
    //layer1
    shipWindowLK(0.0f+ translationX,0.0f+ translationY);
    shipWindowLK(-3.5f+ translationX,0.0f+ translationY);
    shipWindowLK(-7.0f+ translationX,0.0f+ translationY);
    shipWindowLK(-10.5f+ translationX,0.0f+ translationY);
    shipWindowLK(-14.0f+ translationX,0.0f+ translationY);
    shipWindowLK(-17.5f+ translationX,0.0f+ translationY);
    glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(25.0f + translationX, 2.0f + translationY);
    glVertex2f(25.0f + translationX, 6.0f + translationY);
    glVertex2f(23.8f + translationX, 6.0f + translationY);
    glVertex2f(22.4f + translationX, 2.0f + translationY);
    glEnd();
    //layer2
    shipWindowLK(-1.5f + translationX,8.0f+ translationY);
    shipWindowLK(-5.0f+ translationX,8.0f+ translationY);
    shipWindowLK(-8.5f+ translationX,8.0f+ translationY);
    shipWindowLK(-12.0f+ translationX,8.0f+ translationY);
    shipWindowLK(-15.5f+ translationX,8.0f+ translationY);
    glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(27.0f + translationX, 10.0f + translationY);
    glVertex2f(27.0f + translationX, 14.0f + translationY);
    glVertex2f(26.7f + translationX, 14.0f + translationY);
    glVertex2f(25.4f + translationX, 10.0f + translationY);
    glEnd();
    //railings
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(25.2f + translationX, 3.0f + translationY);
    glVertex2f(15.0f + translationX, 3.0f + translationY);

    glVertex2f(15.15f + translationX, 3.0f + translationY);
    glVertex2f(15.15f + translationX, 1.0f + translationY);

    glVertex2f(25.15f + translationX, 3.0f + translationY);
    glVertex2f(26.0f + translationX, 1.0f + translationY);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(16.2f + translationX, 3.0f + translationY);
    glVertex2f(16.2f + translationX, 1.0f + translationY);

    glVertex2f(17.2f + translationX, 3.0f + translationY);
    glVertex2f(17.2f + translationX, 1.0f + translationY);

    glVertex2f(18.2f + translationX, 3.0f + translationY);
    glVertex2f(18.2f + translationX, 1.0f + translationY);

    glVertex2f(19.2f + translationX, 3.0f + translationY);
    glVertex2f(19.2f + translationX, 1.0f + translationY);

    glVertex2f(20.2f + translationX, 3.0f + translationY);
    glVertex2f(20.2f + translationX, 1.0f + translationY);

    glVertex2f(21.2f + translationX, 3.0f + translationY);
    glVertex2f(21.2f + translationX, 1.0f + translationY);

    glVertex2f(22.2f + translationX, 3.0f + translationY);
    glVertex2f(22.2f + translationX, 1.0f + translationY);

    glVertex2f(23.2f + translationX, 3.0f + translationY);
    glVertex2f(23.2f + translationX, 1.0f + translationY);

    glVertex2f(24.2f + translationX, 3.0f + translationY);
    glVertex2f(24.2f + translationX, 1.0f + translationY);
    glEnd();
    glLineWidth(1.0f);
            glPopMatrix();
    }
    else{
         glBegin(GL_POLYGON);
    glColor3ub(204, 157, 110);
    glVertex2f(48.0f + translationX, -9.0f + translationY);
    glVertex2f(50.0f + translationX, 1.0f + translationY);
    glVertex2f(15.0f + translationX, 1.0f + translationY);
    glVertex2f(18.0f + translationX, -9.0f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(194,150,107);
    glVertex2f(22.0f + translationX, -9.0f + translationY);
    glVertex2f(15.0f + translationX, 1.0f + translationY);
    glVertex2f(18.0f + translationX, -9.0f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(17.5f + translationX, -7.0f + translationY);
    glVertex2f(48.4f + translationX, -7.0f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(17.6f + translationX, -7.5f + translationY);
    glVertex2f(48.3f + translationX, -7.5f + translationY);
    glEnd();
    //layer1
    glBegin(GL_POLYGON);
    glColor3ub(219,212,193);
    glVertex2f(47.0f + translationX, 1.0f + translationY);
    glVertex2f(47.0f + translationX, 7.0f + translationY);
    glVertex2f(24.0f + translationX, 7.0f + translationY);
    glVertex2f(22.0f + translationX, 1.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 157, 110);
    glVertex2f(48.0f + translationX, 9.0f + translationY);
    glVertex2f(48.0f + translationX, 7.0f + translationY);
    glVertex2f(24.0f + translationX, 7.0f + translationY);
    glVertex2f(24.0f + translationX, 9.0f + translationY);
    glEnd();
    //layer2
    glBegin(GL_POLYGON);
    glColor3ub(219,212,193);
    glVertex2f(46.0f + translationX, 9.0f + translationY);
    glVertex2f(46.0f + translationX, 15.0f + translationY);
    glVertex2f(27.0f + translationX, 15.0f + translationY);
    glVertex2f(25.0f + translationX, 9.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 157, 110);
    glVertex2f(47.0f + translationX, 17.0f + translationY);
    glVertex2f(47.0f + translationX, 15.0f + translationY);
    glVertex2f(27.0f + translationX, 15.0f + translationY);
    glVertex2f(27.0f + translationX, 17.0f + translationY);
    glEnd();
    //window
    //layer1
    shipWindowLK(0.0f+ translationX,0.0f+ translationY);
    shipWindowLK(-3.5f+ translationX,0.0f+ translationY);
    shipWindowLK(-7.0f+ translationX,0.0f+ translationY);
    shipWindowLK(-10.5f+ translationX,0.0f+ translationY);
    shipWindowLK(-14.0f+ translationX,0.0f+ translationY);
    shipWindowLK(-17.5f+ translationX,0.0f+ translationY);
    glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(25.0f + translationX, 2.0f + translationY);
    glVertex2f(25.0f + translationX, 6.0f + translationY);
    glVertex2f(23.8f + translationX, 6.0f + translationY);
    glVertex2f(22.4f + translationX, 2.0f + translationY);
    glEnd();
    //layer2
    shipWindowLK(-1.5f + translationX,8.0f+ translationY);
    shipWindowLK(-5.0f+ translationX,8.0f+ translationY);
    shipWindowLK(-8.5f+ translationX,8.0f+ translationY);
    shipWindowLK(-12.0f+ translationX,8.0f+ translationY);
    shipWindowLK(-15.5f+ translationX,8.0f+ translationY);
    glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(27.0f + translationX, 10.0f + translationY);
    glVertex2f(27.0f + translationX, 14.0f + translationY);
    glVertex2f(26.7f + translationX, 14.0f + translationY);
    glVertex2f(25.4f + translationX, 10.0f + translationY);
    glEnd();
    //railings
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(25.2f + translationX, 3.0f + translationY);
    glVertex2f(15.0f + translationX, 3.0f + translationY);

    glVertex2f(15.15f + translationX, 3.0f + translationY);
    glVertex2f(15.15f + translationX, 1.0f + translationY);

    glVertex2f(25.15f + translationX, 3.0f + translationY);
    glVertex2f(26.0f + translationX, 1.0f + translationY);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(16.2f + translationX, 3.0f + translationY);
    glVertex2f(16.2f + translationX, 1.0f + translationY);

    glVertex2f(17.2f + translationX, 3.0f + translationY);
    glVertex2f(17.2f + translationX, 1.0f + translationY);

    glVertex2f(18.2f + translationX, 3.0f + translationY);
    glVertex2f(18.2f + translationX, 1.0f + translationY);

    glVertex2f(19.2f + translationX, 3.0f + translationY);
    glVertex2f(19.2f + translationX, 1.0f + translationY);

    glVertex2f(20.2f + translationX, 3.0f + translationY);
    glVertex2f(20.2f + translationX, 1.0f + translationY);

    glVertex2f(21.2f + translationX, 3.0f + translationY);
    glVertex2f(21.2f + translationX, 1.0f + translationY);

    glVertex2f(22.2f + translationX, 3.0f + translationY);
    glVertex2f(22.2f + translationX, 1.0f + translationY);

    glVertex2f(23.2f + translationX, 3.0f + translationY);
    glVertex2f(23.2f + translationX, 1.0f + translationY);

    glVertex2f(24.2f + translationX, 3.0f + translationY);
    glVertex2f(24.2f + translationX, 1.0f + translationY);
    glEnd();
    glLineWidth(1.0f);
}
}

void ship2SideViewLK(float translationX, float translationY) {
    if(ship1TranslationXLK==-18){
            glPushMatrix();
        glTranslatef(-18.0f, -5.0f, 0.0f);
        glRotatef(-angle1LK, 0.0f, 0.0f, 1.0f);
        glTranslatef(18.0f, 5.0f, 0.0f);
    //body
    glBegin(GL_POLYGON);
    glColor3ub(237, 221, 236);
    glVertex2f(-50.0f + translationX, -9.0f + translationY);
    glVertex2f(-50.0f + translationX, 1.0f + translationY);
    glVertex2f(-16.0f + translationX, 1.0f + translationY);
    glVertex2f(-22.0f + translationX, -9.0f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(209, 199, 208);
    glVertex2f(-16.0f + translationX, 1.0f + translationY);
    glVertex2f(-22.0f + translationX, -9.0f + translationY);
    glVertex2f(-28.0f + translationX, -9.0f + translationY);
    glEnd();
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glColor3ub(4, 130, 73);
    for (float x = 0.0f; x <= 22.0f; x++) {
    glVertex2f(-49.0f + x + translationX, -7.0f + translationY);
    }
    glEnd();
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3ub(161, 181, 172);
    for (float x = 0.0f; x <= 20.0f; x++) {
    glVertex2f(-49.0f + x + translationX, -3.0f + translationY);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-32.0f + translationX, 1.0f + translationY);
    glVertex2f(-20.0f + translationX, 1.0f + translationY);
    glVertex2f(-23.0f + translationX, 15.0f + translationY);
    glVertex2f(-30.0f + translationX, 15.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-45.0f + translationX, 1.0f + translationY);
    glVertex2f(-23.0f + translationX, 1.0f + translationY);
    glVertex2f(-23.0f + translationX, 10.0f + translationY);
    glVertex2f(-45.0f + translationX, 10.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-45.0f + translationX, 15.0f + translationY);
    glVertex2f(-40.0f + translationX, 15.0f + translationY);
    glVertex2f(-40.0f + translationX, 10.0f + translationY);
    glVertex2f(-45.0f + translationX, 10.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-50.0f + translationX, 1.0f + translationY);
    glVertex2f(-45.5f + translationX, 1.0f + translationY);
    glVertex2f(-45.5f + translationX, 9.0f + translationY);
    glVertex2f(-48.0f + translationX, 9.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-48.0f + translationX, 11.0f + translationY);
    glVertex2f(-45.5f + translationX, 11.0f + translationY);
    glVertex2f(-45.5f + translationX, 7.0f + translationY);
    glVertex2f(-48.0f + translationX, 7.0f + translationY);
    glEnd();
    //window
    glPointSize(38.0);
    glBegin(GL_POINTS);
    glColor3ub(42, 99, 163);
    glVertex2f(-28.5f + translationX, 12.0f + translationY);
    glEnd();
    glPointSize(38.0);
    glBegin(GL_POINTS);
    glColor3ub(42, 99, 163);
    glVertex2f(-25.5f + translationX, 12.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(42, 99, 163);
    glVertex2f(-23.8f + translationX, 14.0f + translationY);
    glVertex2f(-22.75f + translationX, 14.0f + translationY);
    glVertex2f(-21.9f + translationX, 10.0f + translationY);
    glVertex2f(-23.8f + translationX, 10.0f + translationY);
    glEnd();
    for (float x = 0.0f; x <= 18.0f; x=x+3) {
    glPointSize(38.0);
    glBegin(GL_POINTS);
    glColor3ub(71, 91, 158);
    glVertex2f(-25.5f - x + translationX, 6.0f + translationY);
    glEnd();
    }
    glBegin(GL_POLYGON);
    glColor3ub(71, 91, 158);
    glVertex2f(-23.8f + translationX, 8.0f + translationY);
    glVertex2f(-21.4f + translationX, 8.0f + translationY);
    glVertex2f(-20.6f + translationX, 4.0f + translationY);
    glVertex2f(-23.8f + translationX, 4.0f + translationY);
    glEnd();

    glPopMatrix();

    }


    else{

    glBegin(GL_POLYGON);
    glColor3ub(237, 221, 236);
    glVertex2f(-50.0f + translationX, -9.0f + translationY);
    glVertex2f(-50.0f + translationX, 1.0f + translationY);
    glVertex2f(-16.0f + translationX, 1.0f + translationY);
    glVertex2f(-22.0f + translationX, -9.0f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(209, 199, 208);
    glVertex2f(-16.0f + translationX, 1.0f + translationY);
    glVertex2f(-22.0f + translationX, -9.0f + translationY);
    glVertex2f(-28.0f + translationX, -9.0f + translationY);
    glEnd();
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glColor3ub(4, 130, 73);
    for (float x = 0.0f; x <= 22.0f; x++) {
    glVertex2f(-49.0f + x + translationX, -7.0f + translationY);
    }
    glEnd();
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3ub(161, 181, 172);
    for (float x = 0.0f; x <= 20.0f; x++) {
    glVertex2f(-49.0f + x + translationX, -3.0f + translationY);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-32.0f + translationX, 1.0f + translationY);
    glVertex2f(-20.0f + translationX, 1.0f + translationY);
    glVertex2f(-23.0f + translationX, 15.0f + translationY);
    glVertex2f(-30.0f + translationX, 15.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-45.0f + translationX, 1.0f + translationY);
    glVertex2f(-23.0f + translationX, 1.0f + translationY);
    glVertex2f(-23.0f + translationX, 10.0f + translationY);
    glVertex2f(-45.0f + translationX, 10.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-45.0f + translationX, 15.0f + translationY);
    glVertex2f(-40.0f + translationX, 15.0f + translationY);
    glVertex2f(-40.0f + translationX, 10.0f + translationY);
    glVertex2f(-45.0f + translationX, 10.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-50.0f + translationX, 1.0f + translationY);
    glVertex2f(-45.5f + translationX, 1.0f + translationY);
    glVertex2f(-45.5f + translationX, 9.0f + translationY);
    glVertex2f(-48.0f + translationX, 9.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(187, 232, 240);
    glVertex2f(-48.0f + translationX, 11.0f + translationY);
    glVertex2f(-45.5f + translationX, 11.0f + translationY);
    glVertex2f(-45.5f + translationX, 7.0f + translationY);
    glVertex2f(-48.0f + translationX, 7.0f + translationY);
    glEnd();
    //window
    glPointSize(38.0);
    glBegin(GL_POINTS);
    glColor3ub(42, 99, 163);
    glVertex2f(-28.5f + translationX, 12.0f + translationY);
    glEnd();
    glPointSize(38.0);
    glBegin(GL_POINTS);
    glColor3ub(42, 99, 163);
    glVertex2f(-25.5f + translationX, 12.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(42, 99, 163);
    glVertex2f(-23.8f + translationX, 14.0f + translationY);
    glVertex2f(-22.75f + translationX, 14.0f + translationY);
    glVertex2f(-21.9f + translationX, 10.0f + translationY);
    glVertex2f(-23.8f + translationX, 10.0f + translationY);
    glEnd();
    for (float x = 0.0f; x <= 18.0f; x=x+3) {
    glPointSize(38.0);
    glBegin(GL_POINTS);
    glColor3ub(71, 91, 158);
    glVertex2f(-25.5f - x + translationX, 6.0f + translationY);
    glEnd();
    }
    glBegin(GL_POLYGON);
    glColor3ub(71, 91, 158);
    glVertex2f(-23.8f + translationX, 8.0f + translationY);
    glVertex2f(-21.4f + translationX, 8.0f + translationY);
    glVertex2f(-20.6f + translationX, 4.0f + translationY);
    glVertex2f(-23.8f + translationX, 4.0f + translationY);
    glEnd();
}
}

void river1LK() {
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

void river2LK() {
    glBegin(GL_POLYGON);
    glColor3ub(101, 181, 199);
    glVertex2f(-50.0f, -9.0f);
    glColor3ub(129, 198, 214);
    glVertex2f(50.0f, -9.0f);
    glVertex2f(50.0f, -40.0f);
    glVertex2f(-50.0f, -40.0f);
    glEnd();
}

void displayScene3MorningLK() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (isRainingLK) skyRainLK();
    else skyMorningLK();

    if (!isRainingLK) sun2LK(0.0f, sun2TranslationYLK);
    river1LK();

    for (int i = -10; i <= 25; i += 2) waveLK(i);
    ship1SideViewLK(ship1TranslationXLK, ship1TranslationYLK);
    ship2SideViewLK(ship2TranslationXLK, ship2TranslationYLK);

    river2LK();
    for (int i = -40; i < -8; i += 2) wave2LK(i);

    if (isRainingLK) {
        for (int i = 0; i < 20; i++) cloudsForRainLK(cloudTranslationXLK - i*5, i%4);
    } else {
        cloudLK(cloudTranslationXLK, 0.0f);
        cloudLK(cloudTranslationXLK - 30.0f, 2.0f);
    }

    raindropsLK();
    glFlush();
}


void displayScene3Evening() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (isRainingLK) {
              skyRainLK();

    } else {
         skyEveningLK();

    sun2LK(0.0f,sun2TranslationYLK - 0.0f);

    }

    river1LK();

    for (int i = -10; i <= 25; i=i+2) {
    waveLK(0.0f + i);
}
    ship1SideViewLK(ship1TranslationXLK - 0.0f,ship1TranslationYLK-0.0f);
    ship2SideViewLK(ship2TranslationXLK -0.0f, ship2TranslationYLK -0.0f);

    river2LK();

    for (int i = -40; i <-8; i=i+2) {
    wave2LK(0.0f + i);
    }

    if(isRainingLK){

    cloudsForRainLK(cloudTranslationXLK, 0.0f);
cloudsForRainLK(cloudTranslationXLK - 3.0f, 0.5f);
cloudsForRainLK(cloudTranslationXLK - 30.0f, 2.0f);
cloudsForRainLK(cloudTranslationXLK - 50.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 70.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 90.0f, 1.0f);
cloudsForRainLK(cloudTranslationXLK - 93.0f, 4.0f);
cloudsForRainLK(cloudTranslationXLK - 10.0f, 3.5f);
cloudsForRainLK(cloudTranslationXLK, 2.0f);
cloudsForRainLK(cloudTranslationXLK - 20.0f, 10.0f);
cloudsForRainLK(cloudTranslationXLK - 3.0f, -0.5f);
cloudsForRainLK(cloudTranslationXLK - 30.0f, 12.0f);
cloudsForRainLK(cloudTranslationXLK - 50.0f, 23.0f);
cloudsForRainLK(cloudTranslationXLK - 74.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 80.0f, 1.0f);
cloudsForRainLK(cloudTranslationXLK - 95.0f, 4.0f);
cloudsForRainLK(cloudTranslationXLK - 30.0f, 3.5f);
cloudsForRainLK(cloudTranslationXLK - 5.0f , 2.9f);
cloudsForRainLK(cloudTranslationXLK - 74.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 60.0f, 1.0f);
cloudsForRainLK(cloudTranslationXLK - 45.0f, 4.0f);
cloudsForRainLK(cloudTranslationXLK - 50.0f, 3.5f);
cloudsForRainLK(cloudTranslationXLK - 65.0f , 2.9f);
cloudsForRainLK(cloudTranslationXLK - 4.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 8.0f, 1.0f);
cloudsForRainLK(cloudTranslationXLK - 15.0f, 4.0f);
cloudsForRainLK(cloudTranslationXLK - 7.0f, 3.5f);
cloudsForRainLK(cloudTranslationXLK - 6.0f , 2.9f);
} else {
cloudLK(cloudTranslationXLK, 0.0f);
cloudLK(cloudTranslationXLK - 3.0f, 0.5f);
cloudLK(cloudTranslationXLK - 30.0f, 2.0f);
cloudLK(cloudTranslationXLK - 50.0f, 3.0f);
cloudLK(cloudTranslationXLK - 70.0f, 3.0f);
cloudLK(cloudTranslationXLK - 90.0f, 1.0f);
}

    raindropsLK();

    glFlush();
}

void displayScene3Night() {
    glClear(GL_COLOR_BUFFER_BIT);

    skyNightLK();

    starLK(-30.0, 38.0, 0.3);
    starLK(-20.0, 35.0, 0.3);
    starLK(-25.0, 33.0, 0.3);
    starLK(30.0, 38.0, 0.3);
    starLK(20.0, 35.0, 0.3);
    starLK(25.0, 33.0, 0.3);
    starLK(0.0, 38.0, 0.3);
    starLK(10.0, 35.0, 0.3);
    starLK(15.0, 33.0, 0.3);
    starLK(-10.0, 38.0, 0.3);
    starLK(-15.0, 35.0, 0.3);
    starLK(-22.0, 33.0, 0.3);
    starLK(50.0, 38.0, 0.3);
    starLK(40.0, 35.0, 0.3);
    starLK(35.0, 33.0, 0.3);

    moonLK(2.0, -40.0, 35.0, 255, 255, 255);

   river1LK();

    for (int i = -10; i <= 25; i=i+2) {
    waveLK(0.0f + i);
}
    ship1SideViewLK(ship1TranslationXLK - 0.0f,ship1TranslationYLK-0.0f);
    ship2SideViewLK(ship2TranslationXLK -0.0f, ship2TranslationYLK -0.0f);

    river2LK();

    for (int i = -40; i <-8; i=i+2) {
    wave2LK(0.0f + i);
    }

    if(isRainingLK){
     cloudsForRainLK(cloudTranslationXLK, 0.0f);
cloudsForRainLK(cloudTranslationXLK - 3.0f, 0.5f);
cloudsForRainLK(cloudTranslationXLK - 30.0f, 2.0f);
cloudsForRainLK(cloudTranslationXLK - 50.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 70.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 90.0f, 1.0f);
cloudsForRainLK(cloudTranslationXLK - 93.0f, 4.0f);
cloudsForRainLK(cloudTranslationXLK - 10.0f, 3.5f);
cloudsForRainLK(cloudTranslationXLK, 2.0f);
cloudsForRainLK(cloudTranslationXLK - 20.0f, 10.0f);
cloudsForRainLK(cloudTranslationXLK - 3.0f, -0.5f);
cloudsForRainLK(cloudTranslationXLK - 30.0f, 12.0f);
cloudsForRainLK(cloudTranslationXLK - 50.0f, 23.0f);
cloudsForRainLK(cloudTranslationXLK - 74.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 80.0f, 1.0f);
cloudsForRainLK(cloudTranslationXLK - 95.0f, 4.0f);
cloudsForRainLK(cloudTranslationXLK - 30.0f, 3.5f);
cloudsForRainLK(cloudTranslationXLK - 5.0f , 2.9f);
cloudsForRainLK(cloudTranslationXLK - 74.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 60.0f, 1.0f);
cloudsForRainLK(cloudTranslationXLK - 45.0f, 4.0f);
cloudsForRainLK(cloudTranslationXLK - 50.0f, 3.5f);
cloudsForRainLK(cloudTranslationXLK - 65.0f , 2.9f);
cloudsForRainLK(cloudTranslationXLK - 4.0f, 3.0f);
cloudsForRainLK(cloudTranslationXLK - 8.0f, 1.0f);
cloudsForRainLK(cloudTranslationXLK - 15.0f, 4.0f);
cloudsForRainLK(cloudTranslationXLK - 7.0f, 3.5f);
cloudsForRainLK(cloudTranslationXLK - 6.0f , 2.9f);
}
    raindropsLK();

    glFlush();
}
void resetShipPosition() {
    moveShipLK = false;
    ship1TranslationXLK = 0.0f;
    ship2TranslationXLK = 0.0f;
    ship1TranslationYLK = 0.0f;
    ship2TranslationYLK = 0.0f;
}

void updateSun2(int value)
{
    if (moveSun2DownLK)
    {
        sun2TranslationYLK -= 0.01f;
         if (sun2TranslationYLK < -4.0f)
        {
            glutDisplayFunc(displayScene3Evening);
            glutPostRedisplay();
        }
        if (sun2TranslationYLK < -6.0f)
        {
            glutDisplayFunc(displayScene3Night);
            glutPostRedisplay();
        }
        if (sun2TranslationYLK < -8.0f)
        {
            glutDisplayFunc(displayScene3MorningLK);
            glutPostRedisplay();
        }
        if (sun2TranslationYLK < -8.0f)
        {
            sun2TranslationYLK = 4.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateSun2, 0);
    }
}

void updateCloudsLK(int value) {
    if (moveCloudsLK) {
        cloudTranslationXLK += 0.02f;
        if (cloudTranslationXLK > 50.0f) cloudTranslationXLK = -50.0f;
        glutPostRedisplay();
        glutTimerFunc(16, updateCloudsLK, 0);
    }
}

void updateShipLK(int value) {
    if (moveShipLK) {
        //if (ship1TranslationXLK > -18.0f)
            ship1TranslationXLK -= 0.1f;
    }
        else {
            ship1TranslationXLK = -18.0f;
            ship2TranslationXLK = 18.0f;
            ship1TranslationYLK -= 0.04f;
            if (ship1TranslationYLK < -2.0f) ship2TranslationYLK -= 0.02f;
            if (angle1LK < 5.0f) angle1LK += 0.8f;
        }
        ship2TranslationXLK += 0.1f;
        glutPostRedisplay();
        glutTimerFunc(16, updateShipLK, 0);

}

void handleKeypressLK(unsigned char key, int x, int y) {
    switch (key) {
    case 'i':
    case 'I':
        moveCloudsLK = !moveCloudsLK;
        if (moveCloudsLK) glutTimerFunc(16, updateCloudsLK, 0);
        break;
    case 'x':
    case 'X':
       moveShipLK = !moveShipLK;
        if (moveShipLK)
            glutTimerFunc(16, updateShipLK, 0);
        break;
    case 'H':
    case 'h':
        isRainingLK = !isRainingLK;
        if (isRainingLK) {
            for (int i = 0; i < numRaindropsLK; ++i) {
                raindropXLK[i] = rand()%100-50;
                raindropYLK[i] = rand()%70;
            }
            glutTimerFunc(16, updateRainLK, 0);
        }
        break;
         case 'p':
    case 'P':
        moveSun2DownLK = !moveSun2DownLK;
        if (moveSun2DownLK)
            glutTimerFunc(16, updateSun2, 0);
        break;
        case 'y':
    case 'Y':
        resetShipPosition();
        glutPostRedisplay();
        break;

    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 800);
    glutCreateWindow("Project Part LK");
    gluOrtho2D(-50, 50, -40, 40);
    glutDisplayFunc(displayScene3MorningLK);
    glutKeyboardFunc(handleKeypressLK);
    glutTimerFunc(0, updateRainLK, 0);
    glutMainLoop();
    return 0;
}
