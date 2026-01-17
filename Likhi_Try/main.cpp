#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float cloudTranslationX = 0.0f;
bool moveClouds = false;
float ship1TranslationX = 0.0f;
float ship2TranslationX = 0.0f;
float ship1TranslationY = 0.0f;
float ship2TranslationY = 0.0f;
bool moveShip = false;
float angle1=0.0f;
float sun2TranslationY = 0.0f;
bool moveSun2Down = false;
float rotateAngle = 0.0f;
float rotationSpeed = 3.0f;
bool startRotation = false;

float circleRotateAngle=0.0f;
bool isRaining = false;
const int numRaindrops = 500;
float raindropX[numRaindrops];
float raindropY[numRaindrops];
float raindropY2[numRaindrops];
float wavePosition = -1.0f;
const float waveAmplitude = 0.1f;
const float waveFrequency = 0.5f;
const float waveWidth = 0.02f;

void circleLK(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
glEnd();
}

void updateRain(int value) {
    if (isRaining) {
        for (int i = 0; i < numRaindrops; ++i) {
            raindropY[i] -= 0.5f;
            if (raindropY[i] < -30.0f) {
                raindropY[i] = 30.0f;
            }
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateRain, 0);
    }
}

void raindrops() {
    if (!isRaining) {
        return; // Skip drawing raindrops when it's not raining
    }
    glColor3ub(135, 206, 250);
    for (int i = 0; i < numRaindrops; ++i) {
        glBegin(GL_LINE_STRIP);
        glVertex2f(raindropX[i], raindropY[i]);
        glVertex2f(raindropX[i], raindropY[i] - 0.5f); // Length of raindrop line
        glEnd();
    }
}

void resetRain() {
    isRaining = false;
    for (int i = 0; i < numRaindrops; ++i) {
        raindropX[i] = 100.0f;
        raindropY[i] = 100.0f;
    }
}

void skyEveningL(){
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

void skyNightL(){
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

void skyMorningL(){
    glBegin(GL_POLYGON);
    glColor3ub(216,232,240);
    glVertex2f(50.0f, 40.0f);
    glColor3ub(204,228,240);
    glVertex2f(-50.0f, 40.0f);
    glColor3ub(192,224,240);
    glVertex2f(-50.0f, 25.0f);
    glColor3ub(125,193,227);
    glVertex2f(50.0f, 25.0f);
    glEnd();
}

void skyRainL() {
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);  // Light gray color for a rainy sky
    glVertex2f(50.0f, 40.0f);
    glVertex2f(-50.0f, 40.0f);
    glVertex2f(-50.0f, 25.0f);
    glVertex2f(50.0f, 25.0f);
    glEnd();
}
void wave(float yOffset) {
    glBegin(GL_QUADS);
    glColor3ub(31, 132, 156);

    for (float i = -50.0f; i < 50.0f; i += waveWidth) {
        float xOffset = fmod(wavePosition + i, 2.0f);
        float waveYOffset = waveAmplitude * sin(2 * 3.14159 * waveFrequency * xOffset);

        glVertex2f(i, -0.5f + yOffset);
        glVertex2f(i, waveYOffset + yOffset);
        glVertex2f(i + waveWidth, waveYOffset + yOffset);
        glVertex2f(i + waveWidth, -0.5f + yOffset);
    }
    glEnd();
}

void wave2(float yOffset) {
    glBegin(GL_QUADS);
    glColor3ub(78, 170, 191);

    const float waveAmplitude = 0.1f;
    const float waveFrequency = 0.5f;
    const float waveWidth = 0.02f;

    for (float i = -50.0f; i < 50.0f; i += waveWidth) {
        float xOffset = fmod(wavePosition + i, 2.0f);
        float waveYOffset = waveAmplitude * sin(2 * 3.14159 * waveFrequency * xOffset);

        glVertex2f(i, -0.5f + yOffset);
        glVertex2f(i, waveYOffset + yOffset);
        glVertex2f(i + waveWidth, waveYOffset + yOffset);
        glVertex2f(i + waveWidth, -0.5f + yOffset);
    }
    glEnd();
}

void river(){
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
void cloud(float translationX, float translationY){
    circleLK(0.6, 45.0 + translationX, 35.0 + translationY, 255,255,255);
    circleLK(0.6, 45.0 + translationX, 34.2 + translationY, 255,255,255);
    circleLK(0.6, 43.8 + translationX, 35.0 + translationY, 255,255,255);
    circleLK(0.6, 43.8 + translationX, 34.2 + translationY, 255,255,255);
    circleLK(0.6, 43.0 + translationX, 34.6 + translationY, 255,255,255);
    circleLK(0.6, 46.0 + translationX, 34.6 + translationY, 255,255,255);
    circleLK(0.6, 44.0 + translationX, 34.6 + translationY, 255,255,255);

}

void sun2L(float translationX, float translationY)
{
    circleLK(1.5, 43.7 + translationX, 36.0f + translationY, 252, 252, 3);
}
void moonL(float radius, float xc, float yc, float r, float g, float b)
{
    circleLK(radius, xc, yc, r, g, b);
    glColor3ub(0, 0, 0);
    circleLK(radius * 0.7, xc + radius * 0.4, yc, 8, 32, 64);
}

void star(float x, float y, float size)
{
    glBegin(GL_TRIANGLES);

    glColor3ub(255, 255, 255);

    for (int i = 0; i < 5; ++i)
    {
        float angle1 = i * 2.0 * 3.14159 / 5;
        float angle2 = (i + 2) * 2.0 * 3.14159 / 5;

        glVertex2f(x, y); // Center of the star

        glVertex2f(x + size * cos(angle1), y + size * sin(angle1));
        glVertex2f(x + size * cos(angle2), y + size * sin(angle2));
    }

    glEnd();
}
void cloudsForRain(float translationX, float translationY){
    circleLK(0.6, 45.0 + translationX, 35.0 + translationY, 82, 74, 70);
    circleLK(0.6, 45.0 + translationX, 34.2 + translationY, 105, 95, 91);
    circleLK(0.6, 43.8 + translationX, 35.0 + translationY, 82, 74, 70);
    circleLK(0.6, 43.8 + translationX, 34.2 + translationY, 105, 95, 91);
    circleLK(0.6, 43.0 + translationX, 34.6 + translationY, 110, 103, 100);
    circleLK(0.6, 46.0 + translationX, 34.6 + translationY, 105, 95, 91);
    circleLK(0.6, 44.0 + translationX, 34.6 + translationY, 110, 103, 100);
}

void shipWindow(float translationX, float translationY){
glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(46.0f + translationX, 2.0f + translationY);
    glVertex2f(46.0f + translationX, 6.0f + translationY);
    glVertex2f(43.0f + translationX, 6.0f + translationY);
    glVertex2f(43.0f + translationX, 2.0f + translationY);
    glEnd();
}

void ship1SideView(float translationX, float translationY){
    if(translationX==-18){
            glPushMatrix();
        glTranslatef(18.0f, 5.0f, 0.0f);
        glRotatef(angle1, 0.0f, 0.0f, 1.0f);
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
    shipWindow(0.0f+ translationX,0.0f+ translationY);
    shipWindow(-3.5f+ translationX,0.0f+ translationY);
    shipWindow(-7.0f+ translationX,0.0f+ translationY);
    shipWindow(-10.5f+ translationX,0.0f+ translationY);
    shipWindow(-14.0f+ translationX,0.0f+ translationY);
    shipWindow(-17.5f+ translationX,0.0f+ translationY);
    glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(25.0f + translationX, 2.0f + translationY);
    glVertex2f(25.0f + translationX, 6.0f + translationY);
    glVertex2f(23.8f + translationX, 6.0f + translationY);
    glVertex2f(22.4f + translationX, 2.0f + translationY);
    glEnd();
    //layer2
    shipWindow(-1.5f + translationX,8.0f+ translationY);
    shipWindow(-5.0f+ translationX,8.0f+ translationY);
    shipWindow(-8.5f+ translationX,8.0f+ translationY);
    shipWindow(-12.0f+ translationX,8.0f+ translationY);
    shipWindow(-15.5f+ translationX,8.0f+ translationY);
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
    shipWindow(0.0f+ translationX,0.0f+ translationY);
    shipWindow(-3.5f+ translationX,0.0f+ translationY);
    shipWindow(-7.0f+ translationX,0.0f+ translationY);
    shipWindow(-10.5f+ translationX,0.0f+ translationY);
    shipWindow(-14.0f+ translationX,0.0f+ translationY);
    shipWindow(-17.5f+ translationX,0.0f+ translationY);
    glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(25.0f + translationX, 2.0f + translationY);
    glVertex2f(25.0f + translationX, 6.0f + translationY);
    glVertex2f(23.8f + translationX, 6.0f + translationY);
    glVertex2f(22.4f + translationX, 2.0f + translationY);
    glEnd();
    //layer2
    shipWindow(-1.5f + translationX,8.0f+ translationY);
    shipWindow(-5.0f+ translationX,8.0f+ translationY);
    shipWindow(-8.5f+ translationX,8.0f+ translationY);
    shipWindow(-12.0f+ translationX,8.0f+ translationY);
    shipWindow(-15.5f+ translationX,8.0f+ translationY);
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

void ship2SideView(float translationX, float translationY){
    if(ship1TranslationX==-18){
            glPushMatrix();
        glTranslatef(-18.0f, -5.0f, 0.0f);
        glRotatef(-angle1, 0.0f, 0.0f, 1.0f);
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

void river1(){
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

void river2(){
    glBegin(GL_POLYGON);
    glColor3ub(101, 181, 199);
    glVertex2f(-50.0f, -9.0f);
    glColor3ub(129, 198, 214);
    glVertex2f(50.0f, -9.0f);
    glVertex2f(50.0f, -40.0f);
    glVertex2f(-50.0f, -40.0f);
    glEnd();
}

void displayScene3Morning() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (isRaining) {
        skyRainL();
    } else {
        skyMorningL();
        sun2L(0.0f, sun2TranslationY - 0.0f);
    }

     river1();

    for (int i = -10; i <= 25; i=i+2) {
    wave(0.0f + i);
}
    ship1SideView(ship1TranslationX - 0.0f,ship1TranslationY-0.0f);
    ship2SideView(ship2TranslationX -0.0f, ship2TranslationY -0.0f);

    river2();

    for (int i = -40; i <-8; i=i+2) {
    wave2(0.0f + i);
    }

    if(isRaining){
    cloudsForRain(cloudTranslationX, 0.0f);
    cloudsForRain(cloudTranslationX - 3.0f, 0.5f);
    cloudsForRain(cloudTranslationX - 30.0f, 2.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 70.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 90.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 93.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 10.0f, 3.5f);
    cloudsForRain(cloudTranslationX, 2.0f);
    cloudsForRain(cloudTranslationX - 20.0f, 10.0f);
    cloudsForRain(cloudTranslationX - 3.0f, -0.5f);
    cloudsForRain(cloudTranslationX - 30.0f, 12.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 23.0f);
    cloudsForRain(cloudTranslationX - 74.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 80.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 95.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 30.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 5.0f , 2.9f);
    cloudsForRain(cloudTranslationX - 74.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 60.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 45.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 65.0f , 2.9f);
    cloudsForRain(cloudTranslationX - 4.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 8.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 15.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 7.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 6.0f , 2.9f);
    } else {
    cloud(cloudTranslationX, 0.0f);
    cloud(cloudTranslationX - 3.0f, 0.5f);
    cloud(cloudTranslationX - 30.0f, 2.0f);
    cloud(cloudTranslationX - 50.0f, 3.0f);
    cloud(cloudTranslationX - 70.0f, 3.0f);
    cloud(cloudTranslationX - 90.0f, 1.0f);}

    raindrops();

    glFlush();
}

void displayScene3Evening() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (isRaining) {
              skyRainL();

    } else {
         skyEveningL();

    sun2L(0.0f,sun2TranslationY - 0.0f);

    }

    river1();

    for (int i = -10; i <= 25; i=i+2) {
    wave(0.0f + i);
}
    ship1SideView(ship1TranslationX - 0.0f,ship1TranslationY-0.0f);
    ship2SideView(ship2TranslationX -0.0f, ship2TranslationY -0.0f);

    river2();

    for (int i = -40; i <-8; i=i+2) {
    wave2(0.0f + i);
    }

    if(isRaining){

    cloudsForRain(cloudTranslationX, 0.0f);
    cloudsForRain(cloudTranslationX - 3.0f, 0.5f);
    cloudsForRain(cloudTranslationX - 30.0f, 2.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 70.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 90.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 93.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 10.0f, 3.5f);
    cloudsForRain(cloudTranslationX, 2.0f);
    cloudsForRain(cloudTranslationX - 20.0f, 10.0f);
    cloudsForRain(cloudTranslationX - 3.0f, -0.5f);
    cloudsForRain(cloudTranslationX - 30.0f, 12.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 23.0f);
    cloudsForRain(cloudTranslationX - 74.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 80.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 95.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 30.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 5.0f , 2.9f);
    cloudsForRain(cloudTranslationX - 74.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 60.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 45.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 65.0f , 2.9f);
    cloudsForRain(cloudTranslationX - 4.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 8.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 15.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 7.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 6.0f , 2.9f);
    } else {
    cloud(cloudTranslationX, 0.0f);
    cloud(cloudTranslationX - 3.0f, 0.5f);
    cloud(cloudTranslationX - 30.0f, 2.0f);
    cloud(cloudTranslationX - 50.0f, 3.0f);
    cloud(cloudTranslationX - 70.0f, 3.0f);
    cloud(cloudTranslationX - 90.0f, 1.0f);}


    raindrops();

    glFlush();
}

void displayScene3Night() {
    glClear(GL_COLOR_BUFFER_BIT);

    skyNightL();

    star(-30.0, 38.0, 0.3);
    star(-20.0, 35.0, 0.3);
    star(-25.0, 33.0, 0.3);
    star(30.0, 38.0, 0.3);
    star(20.0, 35.0, 0.3);
    star(25.0, 33.0, 0.3);
    star(0.0, 38.0, 0.3);
    star(10.0, 35.0, 0.3);
    star(15.0, 33.0, 0.3);
    star(-10.0, 38.0, 0.3);
    star(-15.0, 35.0, 0.3);
    star(-22.0, 33.0, 0.3);
    star(50.0, 38.0, 0.3);
    star(40.0, 35.0, 0.3);
    star(35.0, 33.0, 0.3);

    moonL(2.0, -40.0, 35.0, 255, 255, 255);

   river1();

    for (int i = -10; i <= 25; i=i+2) {
    wave(0.0f + i);
}
    ship1SideView(ship1TranslationX - 0.0f,ship1TranslationY-0.0f);
    ship2SideView(ship2TranslationX -0.0f, ship2TranslationY -0.0f);

    river2();

    for (int i = -40; i <-8; i=i+2) {
    wave2(0.0f + i);
    }

    if(isRaining){
    cloudsForRain(cloudTranslationX, 0.0f);
    cloudsForRain(cloudTranslationX - 3.0f, 0.5f);
    cloudsForRain(cloudTranslationX - 30.0f, 2.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 70.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 90.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 93.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 10.0f, 3.5f);
    cloudsForRain(cloudTranslationX, 2.0f);
    cloudsForRain(cloudTranslationX - 20.0f, 10.0f);
    cloudsForRain(cloudTranslationX - 3.0f, -0.5f);
    cloudsForRain(cloudTranslationX - 30.0f, 12.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 23.0f);
    cloudsForRain(cloudTranslationX - 74.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 80.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 95.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 30.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 5.0f , 2.9f);
    cloudsForRain(cloudTranslationX - 74.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 60.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 45.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 50.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 65.0f , 2.9f);
    cloudsForRain(cloudTranslationX - 4.0f, 3.0f);
    cloudsForRain(cloudTranslationX - 8.0f, 1.0f);
    cloudsForRain(cloudTranslationX - 15.0f, 4.0f);
    cloudsForRain(cloudTranslationX - 7.0f, 3.5f);
    cloudsForRain(cloudTranslationX - 6.0f , 2.9f);
    }

    raindrops();

    glFlush();
}



void updateWindmill(int value)
{if (startRotation)
    {
        rotateAngle += rotationSpeed;
        if (rotateAngle > 360.0f)
        {
            rotateAngle -= 360.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateWindmill, 0);
}

void updateSun2(int value)
{
    if (moveSun2Down)
    {
        sun2TranslationY -= 0.01f;
         if (sun2TranslationY < -4.0f)
        {
            glutDisplayFunc(displayScene3Evening);
            glutPostRedisplay();
        }
        if (sun2TranslationY < -6.0f)
        {
            glutDisplayFunc(displayScene3Night);
            glutPostRedisplay();
        }
        if (sun2TranslationY < -8.0f)
        {
            glutDisplayFunc(displayScene3Morning);
            glutPostRedisplay();
        }
        if (sun2TranslationY < -8.0f)
        {
            sun2TranslationY = 4.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateSun2, 0);
    }
}

void updateClouds(int value)
{
    if (moveClouds)
    {
        cloudTranslationX += 0.02f;
        if (cloudTranslationX > 50.0f)
        {
            cloudTranslationX = -50.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateClouds, 0);
    }
}

void updateShip(int value)
{
   if (moveShip)
    {
            if(ship1TranslationX>-18.0f){
        ship1TranslationX -= 0.1f;}

        else{
            ship1TranslationX = -18.0f;
            ship2TranslationX = 18.0f;
            ship1TranslationY -= 0.04f;
            if(ship1TranslationY<-2.0f){
            ship2TranslationY -= 0.02f;
            }

            if (ship1TranslationX == -18.0f) {
                angle1 += 0.8f;
                if(angle1>5){
                    angle1=5;
                }
            }
        }
        ship2TranslationX += 0.1f;
        glutPostRedisplay();
        glutTimerFunc(16, updateShip, 0);
    }
}




void resetShipPosition() {
    moveShip = false;
    ship1TranslationX = 0.0f;
    ship2TranslationX = 0.0f;
    ship1TranslationY = 0.0f;
    ship2TranslationY = 0.0f;
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'c':
    case 'C':
        moveClouds = !moveClouds;
        if (moveClouds)
            glutTimerFunc(16, updateClouds, 0);
        break;

    case 'x':
    case 'X':
       moveShip = !moveShip;
        if (moveShip)
            glutTimerFunc(16, updateShip, 0);
        break;
    case 'y':
    case 'Y':
        resetShipPosition();
        glutPostRedisplay();
        break;
    case 'n':
    case 'N':
        moveSun2Down = !moveSun2Down;
        if (moveSun2Down)
            glutTimerFunc(16, updateSun2, 0);
        break;

    case 'r':
    case 'R':
        isRaining = !isRaining;
        if (isRaining) {
            // Initialize raindrop positions when rain starts
            for (int i = 0; i < numRaindrops; ++i) {
                raindropX[i] = static_cast<float>(rand() % 100 - 50);
                raindropY[i] = static_cast<float>(rand() % 70);
            }
            glutTimerFunc(16, updateRain, 0);
        } else {
            // Reset raindrop positions when rain stops
            resetRain();
        }
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Project_part3");
    glutInitWindowSize(1400, 800);
    glutDisplayFunc(displayScene3Morning);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(16, updateRain, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -40.0, 40.0);
    glutMainLoop();
    return 0;
}

