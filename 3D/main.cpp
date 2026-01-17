//  project aiub
//
//Press C/c for movement of cloud. Press C/c again to stop the movement.
//Press A/a for movement of airplane. Press A/a again to stop the movement. Press B/b to bring the airplane in its old position.
//Press S/s for movement of sun and change of morning, evening and night. Press S/s again to stop the movement.
//Press W/w for rotation of windmill blades. Press W/w again to stop the rotation.
//Press R/r for starting of rain. Press R/r again to stop the rain.

//Press 1 to change to scene1.
//Press 2 to change to scene2.
//Press 3 to change to scene3.

/********************************Scene 1***********************************************/
//Press C/c for movement of cloud. Press C/c again to stop the movement.
//Press M/m for movement of sun and change of morning, evening and night. Press M/m again to stop the movement.
//Press R/r for starting of rain. Press R/r again to stop the rain.
//Press P/p for making the speed of blue bus double.
// mouse right to start
/********************************Scene 2***********************************************/
//Press C/c for movement of cloud. Press C/c again to stop the movement.
//Press A/a for movement of airplane. Press A/a again to stop the movement. Press B/b to bring the airplane in its old position.
//Press S/s for movement of sun and change of morning, evening and night. Press S/s again to stop the movement.
//Press W/w for rotation of windmill blades. Press W/w again to stop the rotation.
//Press R/r for starting of rain. Press R/r again to stop the rain.
//Press D/d for rotating the bridge & moving the ship & Car moving.
//Press Z/z to reset activities of ship, bridge, car and airplanes.
/********************************Scene 3***********************************************/
//Press N/n for movement of sun and change of morning, evening and night. Press N/n again to stop the movement.
//Press R/r for starting of rain. Press R/r again to stop the rain.
//Press C/c for movement of cloud. Press C/c again to stop the movement.
//Press X/x for movement of ships. Press X/x again to stop the movement. Press Y/y to reset the positions of the ships.
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float cloudTranslationX = 0.0f;
bool moveClouds = false;
float initialAirplaneX = -55.0f;
float airplaneTranslationX = 0.0f;
bool moveAirplaneRight = false; float sunTranslationY = 0.0f;
float sun2TranslationY = 0.0f;
bool moveSunDown = false;
bool moveSun2Down = false;
float rotateAngle = 0.0f;
float rotationSpeed = 3.0f;
bool startRotation = false;

float circleRotateAngle=0.0f;
float carSpeed= 0.0f;
bool isRaining = false;
const int numRaindrops = 500;
float raindropX[numRaindrops];
float raindropY[numRaindrops];
float raindropY2[numRaindrops];
float wavePosition = -1.0f;
const float waveAmplitude = 0.1f;
const float waveFrequency = 0.5f;
const float waveWidth = 0.02f;

float X = 0.0f;
float Y = 0.0f;
float xrigth=0.0f;
float yright=0.0f;
float shipspeed=0.0f;
int rotatingBridge=0;
int rotateBridge=0;
int isShipMoved=0;
int isBridgeRotateStopped=0;
int isBridgeReversed=0;
bool BridgeRotate=false;
bool isTrafficLightRed = false;
int isShipMoving = 0; // 1 for moving, 0 for stopped
void circle(float radius, float xc, float yc, float r, float g, float b)
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

void circleL(float radius, float xc, float yc, float r, float g, float b, float angle)
{
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_LINES);
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();

    glPopMatrix();
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
/*
void updateRotationCircle(int value)
{
    circleRotateAngle += 2.0f;
    if (circleRotateAngle > 360.0)
    {
        circleRotateAngle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateRotationCircle, 0);
}
*/
void skyEvening(){
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

void skyNight(){
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

void skyMorning(){
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

void skyRain() {
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);  // Light gray color for a rainy sky
    glVertex2f(50.0f, 40.0f);
    glVertex2f(-50.0f, 40.0f);
    glVertex2f(-50.0f, 25.0f);
    glVertex2f(50.0f, 25.0f);
    glEnd();
}

void treeTriangle(float translationX, float translationY) {
    glBegin(GL_POLYGON);
    glColor3ub(71, 50, 41);
    glVertex2f(-48.0f + translationX, 30.0f + translationY);
    glColor3ub(82, 61, 52);
    glVertex2f(-48.0f + translationX, 31.5f + translationY);
    glColor3ub(168, 105, 77);
    glVertex2f(-48.3f + translationX, 31.5f + translationY);
    glColor3ub(191, 117, 84);
    glVertex2f(-48.3f + translationX, 30.0f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(7, 242, 142);
    glVertex2f(-47.3f + translationX, 31.2f + translationY);
    glColor3ub(4, 186, 108);
    glVertex2f(-48.1f + translationX, 32.5f + translationY);
    glColor3ub(5, 135, 79);
    glVertex2f(-49.0f + translationX, 31.2f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(7, 242, 142);
    glVertex2f(-47.5f + translationX, 32.0f + translationY);
    glColor3ub(4, 186, 108);
    glVertex2f(-48.1f + translationX, 33.3f + translationY);
    glColor3ub(5, 135, 79);
    glVertex2f(-48.8f + translationX, 32.0f + translationY);
    glEnd();
}

void treeCircle(float translationX, float translationY) {
    glBegin(GL_POLYGON);
    glColor3ub(71, 50, 41);
    glVertex2f(-44.0f + translationX, 30.0f + translationY);
    glColor3ub(82, 61, 52);
    glVertex2f(-44.0f + translationX, 31.5f + translationY);
    glColor3ub(168, 105, 77);
    glVertex2f(-44.3f + translationX, 31.5f + translationY);
    glColor3ub(191, 117, 84);
    glVertex2f(-44.3f + translationX, 30.0f + translationY);
    glEnd();
    circle(0.8, -44.15 + translationX, 32.1 + translationY, 5, 247, 146);
    circle(0.8, -44.25 + translationX, 32.1 + translationY, 5, 232, 137);
    circle(0.5, -44.15 + translationX, 32.9 + translationY, 5, 247, 146);
    circle(0.5, -44.25 + translationX, 32.9 + translationY, 5, 232, 137);
}

void land(){
    glBegin(GL_POLYGON);
    glColor3ub(88, 166, 106);
    glVertex2f(-45.0f, 25.0f);
    glVertex2f(-45.0f, 27.0f);
    glVertex2f(50.0f, 27.0f);
    glVertex2f(50.0f, 25.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(88, 166, 106);
    glVertex2f(-50.0f, 30.0f);
    glColor3ub(2, 250, 59);
    glVertex2f(-40.0f, 30.0f);
    glColor3ub(101, 158, 114);
    glVertex2f(-35.0f, 25.0f);
    glColor3ub(45, 117, 62);
    glVertex2f(-50.0f, 25.0f);
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

void bridge(){
    //pillar
    glBegin(GL_QUADS);
    glColor3ub(82, 55, 43);
    glVertex2f(-27.0f, -18.0f);
    glVertex2f(-23.0f, -18.0f);
    glVertex2f(-23.0f, -32.0f);
    glVertex2f(-27.0f, -32.0f);
glEnd();
    glBegin(GL_QUADS);
    glColor3ub(77, 52, 41);
    glVertex2f(-27.0f, -18.0f);
    glVertex2f(-30.0f, -18.0f);
    glVertex2f(-30.0f, -31.0f);
    glVertex2f(-27.0f, -32.0f);
glEnd();
    glBegin(GL_QUADS);
    glColor3ub(77, 52, 41);
    glVertex2f(-23.0f, -18.0f);
    glVertex2f(-20.0f, -18.0f);
    glVertex2f(-20.0f, -31.0f);
    glVertex2f(-23.0f, -32.0f);
glEnd();

    glBegin(GL_POLYGON);//road_left
    glColor3ub(71, 71, 71);
    glVertex2f(-50.0f, 0.0f);
    glVertex2f(-20.0f, 0.f);
    glVertex2f(-20.0f, -18.0f);
    glVertex2f(-50.0f, -18.0f);
    glEnd();
    glBegin(GL_POLYGON);//black_left
    glColor3ub(0,0,0);
    glVertex2f(-50.0f, 0.0f);
    glVertex2f(-20.0f, 0.0f);
    glVertex2f(-20.0f, 2.0f);
    glVertex2f(-50.0f, 2.0f);
    glEnd();
    glBegin(GL_POLYGON);//black_left
    glColor3ub(0,0,0);
    glVertex2f(-50.0f, -20.0f);
    glVertex2f(-20.0f, -20.0f);
    glVertex2f(-20.0f, -18.0f);
    glVertex2f(-50.0f, -18.0f);
    glEnd();
    glBegin(GL_LINES);//whiteLine_left
    glColor3ub(255,255,255);
    glVertex2f(-50.0f, -8.25f);
    glVertex2f(-20.0f, -8.25f);
    glEnd();
    glBegin(GL_LINES);//whiteLine_left
    glColor3ub(255,255,255);
    glVertex2f(-50.0f, -8.75f);
    glVertex2f(-20.0f, -8.75f);
    glEnd();
    glBegin(GL_LINES);//yellowLine_left
    glColor3ub(255,255,0);
    glVertex2f(-50.0f, -0.5f);
    glVertex2f(-20.1f, -0.5f);
    glEnd();
    glBegin(GL_LINES);//yellowLine_left
    glColor3ub(255,255,0);
    glVertex2f(-50.0f, -17.4f);
    glVertex2f(-20.1f, -17.4f);
    glEnd();

    // Mirrored code for the right side
    //pillar
    glBegin(GL_QUADS); // Pillar
    glColor3ub(82, 55, 43);
    glVertex2f(27.0f, -18.0f);
    glVertex2f(23.0f, -18.0f);
    glVertex2f(23.0f, -32.0f);
    glVertex2f(27.0f, -32.0f);
glEnd();
    glBegin(GL_QUADS);
    glColor3ub(77, 52, 41);
    glVertex2f(27.0f, -18.0f);
    glVertex2f(30.0f, -18.0f);
    glVertex2f(30.0f, -31.0f);
    glVertex2f(27.0f, -32.0f);
glEnd();
    glBegin(GL_QUADS);
    glColor3ub(77, 52, 41);
    glVertex2f(23.0f, -18.0f);
    glVertex2f(20.0f, -18.0f);
    glVertex2f(20.0f, -31.0f);
    glVertex2f(23.0f, -32.0f);
glEnd();

glBegin(GL_POLYGON); // road_right
    glColor3ub(71, 71, 71);
    glVertex2f(20.0f, 0.0f);
    glVertex2f(50.0f, 0.0f);
    glVertex2f(50.0f, -18.0f);
    glVertex2f(20.0f, -18.0f);
glEnd();

glBegin(GL_POLYGON); // black_right
    glColor3ub(0, 0, 0);
    glVertex2f(20.0f, 0.0f);
    glVertex2f(50.0f, 0.0f);
    glVertex2f(50.0f, 2.0f);
    glVertex2f(20.0f, 2.0f);
glEnd();

glBegin(GL_POLYGON); // black_right
    glColor3ub(0, 0, 0);
    glVertex2f(20.0f, -20.0f);
    glVertex2f(50.0f, -20.0f);
    glVertex2f(50.0f, -18.0f);
    glVertex2f(20.0f, -18.0f);
glEnd();

glBegin(GL_LINES); // whiteLine_right
    glColor3ub(255, 255, 255);
    glVertex2f(20.0f, -8.25f);
    glVertex2f(50.0f, -8.25f);
glEnd();

glBegin(GL_LINES); // whiteLine_right
    glColor3ub(255, 255, 255);
    glVertex2f(20.0f, -8.75f);
    glVertex2f(50.0f, -8.75f);
glEnd();

glBegin(GL_LINES); // yellowLine_right
    glColor3ub(255, 255, 0);
    glVertex2f(20.1f, -0.5f);
    glVertex2f(50.0f, -0.5f);
glEnd();

glBegin(GL_LINES); // yellowLine_right
    glColor3ub(255, 255, 0);
    glVertex2f(20.1f, -17.4f);
    glVertex2f(50.0f, -17.4f);
glEnd();
}

void rotationBridgeRight(){
    //Bridge line(down)....
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(82, 55, 43);
    glVertex2f(0.0f+xrigth, -19.9f+yright);
    glVertex2f(0.0f+xrigth, -21.0f+yright);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(82, 55, 43);
    glVertex2f(22.0f+xrigth, -23.0f+yright);
    glVertex2f(0.0f+xrigth, -21.0f+yright);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(0.0f+xrigth, -19.9f+yright);
    glVertex2f(3.0f+xrigth, -21.2f+yright);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(6.0f+xrigth, -19.9f+yright);
    glVertex2f(9.0f+xrigth, -21.6f+yright);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(12.0f+xrigth, -19.9f+yright);
    glVertex2f(9.0f+xrigth, -21.6f+yright);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(12.0f+xrigth, -19.9f+yright);
    glVertex2f(15.0f+xrigth, -22.1f+yright);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(18.0f+xrigth, -19.9f+yright);
    glVertex2f(15.0f+xrigth, -22.1f+yright);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(18.0f+xrigth, -19.9f+yright);
    glVertex2f(21.0f+xrigth, -22.5f+yright);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(6.0f+xrigth, -19.9f+yright);
    glVertex2f(3.0f+xrigth, -21.2f+yright);
    glEnd();
    glLineWidth(1.0f);

    glBegin(GL_POLYGON);//road Right
    glColor3ub(71, 71, 71);
    glVertex2f(0.0f+xrigth, 0.0f+yright);
    glVertex2f(20.0f, 0.0f);
    glVertex2f(20.0f, -18.0f);
    glVertex2f(0.0f+xrigth, -18.0f+yright);
    glEnd();

    glBegin(GL_POLYGON);//black Right
    glColor3ub(0,0,0);
    glVertex2f(0.0f+xrigth, 0.0f+yright);
    glVertex2f(0.0f+xrigth, 2.0f+yright);
    glVertex2f(20.0f, 2.0f);
    glVertex2f(20.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);//black Right
    glColor3ub(0,0,0);
    glVertex2f(0.0f+xrigth, -18.0f+yright);
    glVertex2f(0.0f+xrigth, -20.0f+yright);
    glVertex2f(20.0f, -20.0f);
    glVertex2f(20.0f, -18.0f);
    glEnd();

    glBegin(GL_LINES);//whiteLine Right
    glColor3ub(255,255,255);
    glVertex2f(0.0f+xrigth, -8.75f+yright);
    glVertex2f(20.0f, -8.75f);
    glEnd();

    glBegin(GL_LINES);//whiteLine Right
    glColor3ub(255,255,255);
    glVertex2f(0.0f+xrigth, -8.25f+yright);
    glVertex2f(20.0f, -8.25f);
    glEnd();

    glBegin(GL_LINES);//yellowLine Right
    glColor3ub(255,255,0);
    glVertex2f(0.1f+xrigth, -0.5f+yright);
    glVertex2f(20.1f, -0.5f);
    glEnd();

    glBegin(GL_LINES);//yellowLine Right
    glColor3ub(255,255,0);
    glVertex2f(0.1f+xrigth, -17.4f+yright);
    glVertex2f(20.1f, -17.4f);
    glEnd();
}

void rotatingBridgeLeft(){
//All ARe for pilar Stand..........
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(82, 55, 43);
    glVertex2f(0.0f+X, -19.9f+Y);
    glVertex2f(0.0f+X, -21.0f+Y);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(82, 55, 43);
    glVertex2f(-22.0f+X, -23.0f+Y);
    glVertex2f(0.0f+X, -21.0f+Y);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(0.0f+X, -19.9f+Y);
    glVertex2f(-3.0f+X, -21.2f+Y);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(-6.0f+X, -19.9f+Y);
    glVertex2f(-3.0f+X, -21.2f+Y);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(-6.0f+X, -19.9f+Y);
    glVertex2f(-9.0f+X, -21.6f+Y);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(-12.0f+X, -19.9f+Y);
    glVertex2f(-9.0f+X, -21.6f+Y);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(-12.0f+X, -19.9f+Y);
    glVertex2f(-15.0f+X, -22.1f+Y);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(-18.0f+X, -19.9f+Y);
    glVertex2f(-15.0f+X,-22.1f+Y);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(102, 68, 53);
    glVertex2f(-18.0f+X, -19.9f+Y);
    glVertex2f(-21.0f+X, -22.5f+Y);
    glEnd();
    glLineWidth(1.0f);

    glBegin(GL_POLYGON);//road left
    glColor3ub(71, 71, 71);
    glVertex2f(-20.0f, 0.0f);
    glVertex2f(-20.0f, -18.0f);
    glVertex2f(0.0f+X, -18.0f+Y);
    glVertex2f(0.0f+X, 0.0f+Y);
    glEnd();

    glBegin(GL_POLYGON);//black left
    glColor3ub(0,0,0);
    glVertex2f(-20.0f, 0.0f);
    glVertex2f(-20.0f, 2.0f);
    glVertex2f(0.0f+X, 2.0f+Y);
    glVertex2f(0.0f+X, 0.0f+Y);
    glEnd();

    glBegin(GL_POLYGON);//black left
    glColor3ub(0,0,0);
    glVertex2f(-20.0f, -18.0f);
    glVertex2f(-20.0f, -20.0f);
    glVertex2f(0.0f+X, -20.0f+Y);
    glVertex2f(0.0f+X, -18.0f+Y);
    glEnd();

    glBegin(GL_LINES);//whiteLine left
    glColor3ub(255,255,255);
    glVertex2f(-20.0f, -8.75f);
    glVertex2f(0.0f+X, -8.75f+Y);
    glEnd();

    glBegin(GL_LINES);//whiteLine left
    glColor3ub(255,255,255);
    glVertex2f(-20.0f, -8.25f);
    glVertex2f(0.0f+X, -8.25f+Y);
    glEnd();

    glBegin(GL_LINES);//yellowLine left
    glColor3ub(255,255,0);
    glVertex2f(-20.1f, -0.5f);
    glVertex2f(0.1f+X, -0.5f+Y);
    glEnd();

    glBegin(GL_LINES);//yellowLine left
    glColor3ub(255,255,0);
    glVertex2f(-20.1f, -17.4f);
    glVertex2f(0.1f+X, -17.4f+Y);
    glEnd();
}

void mountain(float translationX, float translationY) {
    glBegin(GL_TRIANGLES);
    glColor3ub(61, 69, 60);
    glVertex2f(-22.0f + translationX, 25.0f + translationY);
    glColor3ub(97, 112, 95);
    glVertex2f(-29.0f + translationX, 35.0f + translationY);
    glColor3ub(81, 92, 80);
    glVertex2f(-35.0f + translationX, 25.0f + translationY);
    glEnd();
}

void windmillBlades(float translationX, float translationY)
{
   glPushMatrix();
    glTranslatef(-14.9f + translationX, 34.0f + translationY, 0.0f); // Translate to the desired rotation point

    if (startRotation)
    {
        glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);
    }

    glTranslatef(14.9f - translationX, -34.0f - translationY, 0.0f); // Translate back to the original position


    glBegin(GL_TRIANGLES);
    glColor3ub(151, 153, 151);
    glVertex2f(-14.9f + translationX, 34.0f + translationY);
    glVertex2f(-17.0f + translationX, 37.0f + translationY);
    glVertex2f(-17.5f + translationX, 36.2f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(151, 153, 151);
    glVertex2f(-14.9f + translationX, 34.0f + translationY);
    glVertex2f(-12.0f + translationX, 37.0f + translationY);
    glVertex2f(-12.5f + translationX, 37.5f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(151, 153, 151);
    glVertex2f(-14.9f + translationX, 34.0f + translationY);
    glVertex2f(-14.1f + translationX, 30.0f + translationY);
    glVertex2f(-13.7f + translationX, 30.5f + translationY);
    glEnd();
    glPopMatrix();
}

void windmill(float translationX, float translationY){
    glBegin(GL_POLYGON);
    glColor3ub(151, 153, 151);
    glVertex2f(-15.0f + translationX, 25.0f + translationY);
    glVertex2f(-15.0f + translationX, 34.0f + translationY);
    glVertex2f(-14.8f + translationX, 34.0f + translationY);
    glVertex2f(-14.8f + translationX, 25.0f + translationY);
    glEnd();

    circle(0.3, -14.9 + translationX, 34.0 + translationY, 184, 186, 184);
    windmillBlades(0.0f,0.0f);
    windmillBlades(20.0f,0.0f);
}

void grass(float translationX, float translationY){
    circle(2.0, 45.0 + translationX, 28.0 + translationY, 35, 69, 35);
    circle(1.5, 42.5 + translationX, 27.5 + translationY, 35, 69, 35);
    circle(1.5, 47.5 + translationX, 27.5 + translationY, 35, 69, 35);
    circle(1.0, 41.0 + translationX, 27.0 + translationY, 35, 69, 35);
    circle(1.0, 49.0 + translationX, 27.0 + translationY, 35, 69, 35);
}

void cloud(float translationX, float translationY){
    circle(0.6, 45.0 + translationX, 35.0 + translationY, 255,255,255);
    circle(0.6, 45.0 + translationX, 34.2 + translationY, 255,255,255);
    circle(0.6, 43.8 + translationX, 35.0 + translationY, 255,255,255);
    circle(0.6, 43.8 + translationX, 34.2 + translationY, 255,255,255);
    circle(0.6, 43.0 + translationX, 34.6 + translationY, 255,255,255);
    circle(0.6, 46.0 + translationX, 34.6 + translationY, 255,255,255);
    circle(0.6, 44.0 + translationX, 34.6 + translationY, 255,255,255);

}

void sun(float translationX, float translationY)
{
    circle(1.5, 43.7 + translationX, 36.0f + translationY, 252, 252, 3);
}

void airplane(float translationX, float translationY){
    glBegin(GL_TRIANGLES);
    glColor3ub(112, 144, 145);
    glVertex2f(22.8f + translationX, 38.0f + translationY);
    glVertex2f(22.0f + translationX, 38.0f + translationY);
    glVertex2f(20.5f + translationX, 40.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(112, 144, 145);
    glVertex2f(20.0f + translationX, 37.0f + translationY);
    glColor3ub(147, 173, 173);
    glVertex2f(20.0f + translationX, 38.5f + translationY);
    glColor3ub(169, 196, 196);
    glVertex2f(23.0f + translationX, 38.5f + translationY);
    glColor3ub(186, 212, 212);
    glVertex2f(23.0f + translationX, 37.0f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(169, 196, 196);
    glVertex2f(23.0f + translationX, 37.0f + translationY);
    glColor3ub(186, 212, 212);
    glVertex2f(23.0f + translationX, 38.5f + translationY);
    glColor3ub(169, 196, 196);
    glVertex2f(24.7f + translationX, 37.0f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(196, 76, 65);
    glVertex2f(20.0f+ translationX, 37.35f+ translationY);
    glVertex2f(24.2f+ translationX, 37.35f+ translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(112, 144, 145);
    glVertex2f(22.8f + translationX, 37.2f + translationY);
    glVertex2f(22.3f + translationX, 37.7f + translationY);
    glVertex2f(20.3f + translationX, 35.2f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
    glVertex2f(23.0f + translationX, 37.5f + translationY);
    glVertex2f(23.0f + translationX, 38.2f + translationY);
    glVertex2f(23.7f + translationX, 37.5f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(112, 144, 145);
    glVertex2f(20.0f + translationX, 37.0f + translationY);
    glVertex2f(20.0f + translationX, 38.5f + translationY);
    glVertex2f(18.8f + translationX, 39.5f + translationY);
    glEnd();
}

void ship(float translationX, float translationY){
    glBegin(GL_POLYGON);
    glColor3ub(204, 157, 110);
    glVertex2f(-13.5f + translationX, 21.0f + translationY);
    glVertex2f(-12.0f + translationX, 10.0f + translationY);
    glVertex2f(-6.3f + translationX, 11.5f + translationY);
    glVertex2f(-9.0f + translationX, 21.0f + translationY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(204, 157, 110);
    glVertex2f(-12.0f + translationX, 10.0f + translationY);
    glVertex2f(-6.3f + translationX, 11.5f + translationY);
    glVertex2f(-7.0f + translationX, 7.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(232, 181, 130);
    glVertex2f(-12.8f + translationX, 21.7f + translationY);
    glVertex2f(-12.3f + translationX, 14.0f + translationY);
    glVertex2f(-7.0f + translationX, 15.0f + translationY);
    glVertex2f(-9.0f + translationX, 21.7f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(232, 181, 130);
    glVertex2f(-12.0f + translationX, 23.0f + translationY);
    glVertex2f(-9.0f + translationX, 23.5f + translationY);
    glVertex2f(-8.0f + translationX, 18.5f + translationY);
    glVertex2f(-11.0f + translationX, 18.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 157, 110);
    glVertex2f(-8.0f + translationX, 18.5f + translationY);
    glVertex2f(-11.0f + translationX, 18.0f + translationY);
    glVertex2f(-11.0f + translationX, 17.2f + translationY);
    glVertex2f(-8.0f + translationX, 17.7f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(219, 218, 217);
    glVertex2f(-11.8f + translationX, 22.4f + translationY);
    glVertex2f(-12.0f + translationX, 20.0f + translationY);
    glVertex2f(-11.5f + translationX, 15.5f + translationY);
    glVertex2f(-10.9f + translationX, 18.2f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-11.2f + translationX, 17.2f + translationY);
    glVertex2f(-11.5f + translationX, 15.5f + translationY);
    glVertex2f(-7.8f + translationX, 16.0f + translationY);
    glVertex2f(-8.0f + translationX, 17.7f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(30, 42, 87);
    glVertex2f(-8.0f + translationX, 17.7f + translationY);
    glVertex2f(-11.0f + translationX, 17.2f + translationY);
    glVertex2f(-10.9f + translationX, 16.2f + translationY);
    glVertex2f(-8.3f + translationX, 16.6f + translationY);
    glEnd();
    glBegin(GL_POLYGON);//
    glColor3ub(255,255,255);
    glVertex2f(-6.9f + translationX, 13.4f + translationY);
    glVertex2f(-6.5f + translationX, 12.0f + translationY);
    glVertex2f(-12.0f + translationX, 11.0f + translationY);
    glVertex2f(-12.0f + translationX, 12.3f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(219, 218, 217);
    glVertex2f(-7.5f + translationX, 14.8f + translationY);
    glVertex2f(-7.0f + translationX, 13.4f + translationY);
    glVertex2f(-12.0f + translationX, 12.3f + translationY);
    glVertex2f(-11.8f + translationX, 13.9f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(30, 42, 87);
    glVertex2f(-7.4f + translationX, 14.7f + translationY);
    glVertex2f(-7.2f + translationX, 13.5f + translationY);
    glVertex2f(-11.7f + translationX, 12.5f + translationY);
    glVertex2f(-11.7f + translationX, 13.8f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(138, 102, 66);
    glVertex2f(-13.5f + translationX, 21.0f + translationY);
    glVertex2f(-12.0f + translationX, 10.0f + translationY);
    glVertex2f(-12.5f + translationX, 9.0f + translationY);
    glVertex2f(-13.2f + translationX, 12.5f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(138, 102, 66);
    glVertex2f(-12.0f + translationX, 10.0f + translationY);
    glVertex2f(-12.5f + translationX, 9.0f + translationY);
    glVertex2f(-6.8f + translationX, 5.9f + translationY);
    glVertex2f(-7.0f + translationX, 7.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(138, 102, 66);
    glVertex2f(-6.8f + translationX, 5.9f + translationY);
    glVertex2f(-7.0f + translationX, 7.0f + translationY);
    glVertex2f(-6.4f + translationX, 11.0f + translationY);
    glVertex2f(-6.3f + translationX, 11.5f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-7.0f + translationX, 7.0f + translationY);
    glVertex2f(-7.2f + translationX, 7.8f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-12.0f + translationX, 10.0f + translationY);
    glVertex2f(-12.0f + translationX, 10.8f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-7.2f + translationX, 7.8f + translationY);
    glVertex2f(-12.0f + translationX, 10.8f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-7.2f + translationX, 7.8f + translationY);
    glVertex2f(-6.3f + translationX, 11.5f + translationY);
    glEnd();
}

void trafficLight(float translationX, float translationY){
    glBegin(GL_POLYGON);
    glColor3ub(33, 30, 27);
    glVertex2f(-20.0f + translationX, 0.0f + translationY);
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glColor3ub(54, 49, 45);
    glVertex2f(-21.0f + translationX, 10.0f + translationY);
    glVertex2f(-20.0f + translationX, 10.0f + translationY);
    glEnd();
    circle(0.3, -20.5 + translationX, 9.0 + translationY, 255,0,0);
    circle(0.3, -20.5 + translationX, 8.0 + translationY, 0,255,0);
     if (isTrafficLightRed) {
        circle(0.3, -20.5 + translationX, 9.0 + translationY, 0, 0, 0);  // Black circle
        circle(0.3, -20.5 + translationX, 8.0 + translationY, 255, 0, 0);  // Red circle
    } else {
        circle(0.3, -20.5 + translationX, 9.0 + translationY, 0, 255, 0);  // Green circle
        circle(0.3, -20.5 + translationX, 8.0 + translationY, 0, 0, 0);  // Black circle
    }
}

void streetLamp(float translationX, float translationY){
    glBegin(GL_POLYGON);
    glColor3ub(33, 30, 27);
    glVertex2f(-20.0f + translationX, 0.0f + translationY);
    glVertex2f(-20.5f + translationX, 0.0f + translationY);
    glColor3ub(54, 49, 45);
    glVertex2f(-20.5f + translationX, 11.0f + translationY);
    glVertex2f(-20.0f + translationX, 11.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(33, 30, 27);
    glVertex2f(-20.0f + translationX, 11.0f + translationY);
    glVertex2f(-20.5f + translationX, 11.0f + translationY);
    glColor3ub(54, 49, 45);
    glVertex2f(-19.2f + translationX, 9.0f + translationY);
    glVertex2f(-18.7f + translationX, 9.3f + translationY);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(247, 143, 7);
    glVertex2f(-19.2f + translationX, 9.0f + translationY);
    glVertex2f(-20.5f + translationX, 11.0f + translationY);
    glEnd();
}

void car(float translationX, float translationY){
    glBegin(GL_POLYGON);
    glColor3ub(163, 72, 104);
    glVertex2f(19.0f + translationX, 1.5f + translationY);
    glVertex2f(17.0f + translationX, 1.2f + translationY);
    glVertex2f(17.0f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -2.0f + translationY);
    glVertex2f(27.25f + translationX, 1.2f + translationY);
    glVertex2f(26.0f + translationX, 1.5f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(156, 224, 247);
    glVertex2f(20.0f + translationX, 3.0f + translationY);
    glVertex2f(19.0f + translationX, 1.5f + translationY);
    glVertex2f(19.7f + translationX, -1.9f + translationY);
    glVertex2f(26.8f + translationX, -1.4f + translationY);
    glVertex2f(26.0f + translationX, 1.5f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(21.0f + translationX, 0.0f + translationY);
    glVertex2f(19.7f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(23.0f + translationX, 0.0f + translationY);
    glVertex2f(23.0f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(25.7f + translationX, 0.0f + translationY);
    glVertex2f(25.7f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(25.9f + translationX, 0.0f + translationY);
    glVertex2f(26.8f + translationX, -1.8f + translationY);
    glEnd();
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(163, 72, 104);
    glVertex2f(21.0f + translationX, 0.0f + translationY);
    glVertex2f(26.0f + translationX, 0.0f + translationY);
    glVertex2f(25.0f + translationX, 3.0f + translationY);
    glVertex2f(20.0f + translationX, 3.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 99);
    glVertex2f(17.0f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -4.0f + translationY);
    glVertex2f(17.5f + translationX, -4.0f + translationY);
    glEnd();
    circle(1.0, 20.0f + translationX, -4.0f + translationY, 0,0,0);
    circle(1.0, 25.3f + translationX, -4.0f + translationY, 0,0,0);
    circleL(0.5, 20.0f + translationX, -4.0f + translationY, 255,255,255,circleRotateAngle );
    circleL(0.5, 25.3f + translationX, -4.0f + translationY, 255,255,255,circleRotateAngle);
    circle(0.3, 20.0f + translationX, -4.0f + translationY, 255,255,255);
    circle(0.3, 25.3f + translationX, -4.0f + translationY, 255,255,255);
}

void car2(float translationX, float translationY){
    glBegin(GL_POLYGON);
    glColor3ub(39, 179, 141);
    glVertex2f(19.0f + translationX, 1.5f + translationY);
    glVertex2f(17.0f + translationX, 1.2f + translationY);
    glVertex2f(17.0f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -2.0f + translationY);
    glVertex2f(27.25f + translationX, 1.2f + translationY);
    glVertex2f(26.0f + translationX, 1.5f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(156, 224, 247);
    glVertex2f(20.0f + translationX, 3.0f + translationY);
    glVertex2f(19.0f + translationX, 1.5f + translationY);
    glVertex2f(19.7f + translationX, -1.9f + translationY);
    glVertex2f(26.8f + translationX, -1.4f + translationY);
    glVertex2f(26.0f + translationX, 1.5f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(39, 179, 141);
    glVertex2f(21.0f + translationX, 0.0f + translationY);
    glVertex2f(19.7f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(39, 179, 141);
    glVertex2f(23.0f + translationX, 0.0f + translationY);
    glVertex2f(23.0f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(39, 179, 141);
    glVertex2f(25.7f + translationX, 0.0f + translationY);
    glVertex2f(25.7f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(39, 179, 141);
    glVertex2f(25.9f + translationX, 0.0f + translationY);
    glVertex2f(26.8f + translationX, -1.8f + translationY);
    glEnd();
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(39, 179, 141);
    glVertex2f(21.0f + translationX, 0.0f + translationY);
    glVertex2f(26.0f + translationX, 0.0f + translationY);
    glVertex2f(25.0f + translationX, 3.0f + translationY);
    glVertex2f(20.0f + translationX, 3.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(113, 201, 177);
    glVertex2f(17.0f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -4.0f + translationY);
    glVertex2f(17.5f + translationX, -4.0f + translationY);
    glEnd();
    circle(1.0, 20.0f + translationX, -4.0f + translationY, 0,0,0);
    circle(1.0, 25.3f + translationX, -4.0f + translationY, 0,0,0);
    circleL(0.5, 20.0f + translationX, -4.0f + translationY, 255,255,255,circleRotateAngle);
    circleL(0.5, 25.3f + translationX, -4.0f + translationY, 255,255,255,circleRotateAngle);
    circle(0.3, 20.0f + translationX, -4.0f + translationY, 255,255,255);
    circle(0.3, 25.3f + translationX, -4.0f + translationY, 255,255,255);
}
void mirrorCar(float translationX, float translationY) {
    glBegin(GL_POLYGON);
    glColor3ub(163, 72, 104);
    glVertex2f(-19.0f + translationX, 1.5f + translationY);
    glVertex2f(-17.0f + translationX, 1.2f + translationY);
    glVertex2f(-17.0f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -2.0f + translationY);
    glVertex2f(-27.25f + translationX, 1.2f + translationY);
    glVertex2f(-26.0f + translationX, 1.5f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(156, 224, 247);
    glVertex2f(-20.0f + translationX, 3.0f + translationY);
    glVertex2f(-19.0f + translationX, 1.5f + translationY);
    glVertex2f(-19.7f + translationX, -1.9f + translationY);
    glVertex2f(-26.8f + translationX, -1.4f + translationY);
    glVertex2f(-26.0f + translationX, 1.5f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glVertex2f(-19.7f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(-23.0f + translationX, 0.0f + translationY);
    glVertex2f(-23.0f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(-25.7f + translationX, 0.0f + translationY);
    glVertex2f(-25.7f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(163, 64, 99);
    glVertex2f(-25.9f + translationX, 0.0f + translationY);
    glVertex2f(-26.8f + translationX, -1.8f + translationY);
    glEnd();
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(163, 72, 104);
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glVertex2f(-26.0f + translationX, 0.0f + translationY);
    glVertex2f(-25.0f + translationX, 3.0f + translationY);
    glVertex2f(-20.0f + translationX, 3.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 99);
    glVertex2f(-17.0f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -4.0f + translationY);
    glVertex2f(-17.5f + translationX, -4.0f + translationY);
    glEnd();
    circle(1.0, -20.0f + translationX, -4.0f + translationY, 0, 0, 0);
    circle(1.0, -25.3f + translationX, -4.0f + translationY, 0, 0, 0);
    circleL(0.5, -20.0f + translationX, -4.0f + translationY, 255, 255, 255,circleRotateAngle);
    circleL(0.5, -25.3f + translationX, -4.0f + translationY, 255, 255, 255,circleRotateAngle);
    circle(0.3, -20.0f + translationX, -4.0f + translationY, 255, 255, 255);
    circle(0.3, -25.3f + translationX, -4.0f + translationY, 255, 255, 255);
}

void mirrorCar2(float translationX, float translationY) {
    glBegin(GL_POLYGON);
    glColor3ub(39, 179, 141);
    glVertex2f(-19.0f + translationX, 1.5f + translationY);
    glVertex2f(-17.0f + translationX, 1.2f + translationY);
    glVertex2f(-17.0f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -2.0f + translationY);
    glVertex2f(-27.25f + translationX, 1.2f + translationY);
    glVertex2f(-26.0f + translationX, 1.5f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(156, 224, 247);
    glVertex2f(-20.0f + translationX, 3.0f + translationY);
    glVertex2f(-19.0f + translationX, 1.5f + translationY);
    glVertex2f(-19.7f + translationX, -1.9f + translationY);
    glVertex2f(-26.8f + translationX, -1.4f + translationY);
    glVertex2f(-26.0f + translationX, 1.5f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(39, 179, 141);
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glVertex2f(-19.7f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(39, 179, 141);
    glVertex2f(-23.0f + translationX, 0.0f + translationY);
    glVertex2f(-23.0f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(39, 179, 141);
    glVertex2f(-25.7f + translationX, 0.0f + translationY);
    glVertex2f(-25.7f + translationX, -2.0f + translationY);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(39, 179, 141);
    glVertex2f(-25.9f + translationX, 0.0f + translationY);
    glVertex2f(-26.8f + translationX, -1.8f + translationY);
    glEnd();
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(39, 179, 141);
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glVertex2f(-26.0f + translationX, 0.0f + translationY);
    glVertex2f(-25.0f + translationX, 3.0f + translationY);
    glVertex2f(-20.0f + translationX, 3.0f + translationY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(113, 201, 177);
    glVertex2f(-17.0f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -4.0f + translationY);
    glVertex2f(-17.5f + translationX, -4.0f + translationY);
    glEnd();
    circle(1.0, -20.0f + translationX, -4.0f + translationY, 0, 0, 0);
    circle(1.0, -25.3f + translationX, -4.0f + translationY, 0, 0, 0);
    circleL(0.5, -20.0f + translationX, -4.0f + translationY, 255, 255, 255,circleRotateAngle);
    circleL(0.5, -25.3f + translationX, -4.0f + translationY, 255, 255, 255,circleRotateAngle);
    circle(0.3, -20.0f + translationX, -4.0f + translationY, 255, 255, 255);
    circle(0.3, -25.3f + translationX, -4.0f + translationY, 255, 255, 255);
}

void moon(float radius, float xc, float yc, float r, float g, float b)
{
    circle(radius, xc, yc, r, g, b);
    glColor3ub(0, 0, 0);
    circle(radius * 0.7, xc + radius * 0.4, yc, 8, 32, 64);
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

void pillar(float translateX, float translateY) {
    glLineWidth(8.0f);
     glBegin(GL_LINES); // Pillar
    glColor3ub(36, 12, 1); // Brown color for pillar
    glVertex2f(-22.0f, 14.0f); // Bottom-left
    glVertex2f(22.0f, 14.0f); // Bottom-right // Top-left
    glEnd();
    glLineWidth(5.0f);
     glBegin(GL_LINES); // Pillar
    glColor3ub(36, 12, 1); // Brown color for pillar
    glVertex2f(-22.0f, 13.2f); // Bottom-left
    glVertex2f(22.0f, 13.2f); // Bottom-right // Top-left
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(8.0f);
     glBegin(GL_LINES); // Pillar
    glColor3ub(36, 12, 1); // Brown color for pillar
    glVertex2f(-22.0f, 24.0f); // Bottom-left
    glVertex2f(22.0f, 24.0f); // Bottom-right // Top-left
    glEnd();
    glLineWidth(5.0f);
     glBegin(GL_LINES); // Pillar
    glColor3ub(36, 12, 1); // Brown color for pillar
    glVertex2f(-22.0f, 23.2f); // Bottom-left
    glVertex2f(22.0f, 23.2f); // Bottom-right // Top-left
    glEnd();
    glLineWidth(1.0f);

    //pillar
    glBegin(GL_QUADS); // Pillar
    glColor3ub(82, 55, 43); // Brown color for pillar
    glVertex2f(-26.0f + translateX, -18.0f + translateY); // Bottom-left
    glVertex2f(-24.0f + translateX, -18.0f + translateY); // Bottom-right
    glVertex2f(-24.0f + translateX, 15.0f + translateY); // Top-right
    glVertex2f(-26.0f + translateX, 15.0f + translateY); // Top-left
    glEnd();

    glBegin(GL_QUADS); // Pillar
    glColor3ub(77, 52, 41); // Brown color for pillar
    glVertex2f(-26.0f + translateX, -18.0f + translateY); // Bottom-left
    glVertex2f(-28.0f + translateX, -18.0f + translateY); // Bottom-right
    glVertex2f(-28.0f + translateX, 15.0f + translateY); // Top-right
    glVertex2f(-26.0f + translateX, 15.0f + translateY); // Top-left
    glEnd();

    glBegin(GL_QUADS); // Pillar
    glColor3ub(77, 52, 41); // Brown color for pillar
    glVertex2f(-24.0f + translateX, -18.0f + translateY); // Bottom-left
    glVertex2f(-22.0f + translateX, -18.0f + translateY); // Bottom-right
    glVertex2f(-22.0f + translateX, 15.0f + translateY); // Top-right
    glVertex2f(-24.0f + translateX, 15.0f + translateY); // Top-left
    glEnd();

    glBegin(GL_TRIANGLES); // Pillar
    glColor3ub(64, 22, 4); // Brown color for pillar
    glVertex2f(-25.0f + translateX, 22.0f + translateY); // Bottom-left
    glVertex2f(-27.0f + translateX, 15.0f + translateY); // Bottom-right
    glVertex2f(-23.0f + translateX, 15.0f + translateY); // Top-right
    glEnd();

    glBegin(GL_TRIANGLES); // Pillar
    glColor3ub(87, 30, 5); // Brown color for pillar
    glVertex2f(-27.5f + translateX, 20.0f + translateY); // Bottom-left
    glVertex2f(-26.0f + translateX, 15.0f + translateY); // Bottom-right
    glVertex2f(-28.0f + translateX, 15.0f + translateY); // Top-right
    glEnd();

    glBegin(GL_TRIANGLES); // Pillar
    glColor3ub(87, 30, 5); // Brown color for pillar
    glVertex2f(-22.5f + translateX, 20.0f + translateY); // Bottom-left
    glVertex2f(-24.0f + translateX, 15.0f + translateY); // Bottom-right
    glVertex2f(-22.0f + translateX, 15.0f + translateY); // Top-right
    glEnd();
}

void cloudsForRain(float translationX, float translationY){
    circle(0.6, 45.0 + translationX, 35.0 + translationY, 82, 74, 70);
    circle(0.6, 45.0 + translationX, 34.2 + translationY, 105, 95, 91);
    circle(0.6, 43.8 + translationX, 35.0 + translationY, 82, 74, 70);
    circle(0.6, 43.8 + translationX, 34.2 + translationY, 105, 95, 91);
    circle(0.6, 43.0 + translationX, 34.6 + translationY, 110, 103, 100);
    circle(0.6, 46.0 + translationX, 34.6 + translationY, 105, 95, 91);
    circle(0.6, 44.0 + translationX, 34.6 + translationY, 110, 103, 100);
}

void updateRotateBridge(int value){
    Y+=0.02f;
    X-=0.02f;
    yright+=0.02f;
    xrigth+=0.02f;

    // Set the traffic light to red as soon as the bridge starts going up
    isTrafficLightRed = true;

    if(Y > 7.0)
    {
        Y=7;
        isBridgeRotateStopped=1;
    }
    if(X<-7){
        X=-7;
    }
    if(yright > 7.0)
    {
        yright=7;
    }
    if(xrigth>7){

        xrigth=7;
    }
    glutPostRedisplay();

}

void bridgeRotate(){
    if(isBridgeRotateStopped==0){
        glutTimerFunc(0.000002, updateRotateBridge, 0);
        }
        rotatingBridge=1;

}


void updateBridgeRotateReverse(int value){
    Y-=0.02f;
    X+=0.02f;
    yright-=0.02f;
    xrigth-=0.02f;
    if(Y < 0.0)
    {
        Y=0.0;
        isBridgeReversed=1;

        // Reset the traffic light to green when the bridge is fully down
        isTrafficLightRed = false;
    }
    if(X>0.0){
        X=0.0;
    }
    if(yright <0.0)
    {
        yright=0.0;
    }
    if(xrigth<0.0){

        xrigth=0.0;
    }
    glutPostRedisplay();
}

void bridgeRotateReverse(){
    if(isBridgeReversed==0){
    glutTimerFunc(200, updateBridgeRotateReverse, 0);
    }
    rotatingBridge=1;
}
//Bridge rotation end.................

//CAR MOVING START.................

void carMove(){

        glPushMatrix();

        glTranslatef(carSpeed,0.0f , 0.0f);
        mirrorCar(-20.0f,-11.0f);
        mirrorCar2(-7.0f,-11.0f);
        glPopMatrix();

}
void carMove2(){

        glPushMatrix();

        glTranslatef(-carSpeed,0.0f , 0.0f);
        car(4.0f,0.0f);
        car2(20.0f,0.0f);
        glPopMatrix();

}
void updateCarMove(int value){
        carSpeed += .2;
        if(carSpeed > 90.3)
        {
        carSpeed = -50.0;
        }
        glutPostRedisplay();
}
void MoveCar(){
    glutTimerFunc(2, updateCarMove, 0);
}
void stopCar(){
    carSpeed=0;
}

//Car move ends......................................................

//SHIP MOVING START........................................................

void movingShip(){
    glPushMatrix();

        glTranslatef(0.0f ,-shipspeed, 0.0f);
        ship(8.0,0.0);
        glPopMatrix();
}

void updateShipMOve(int value){
    shipspeed += .1;
        if(shipspeed > 80.0)
        {
        shipspeed = 80.0;
        isShipMoved=1;
        }
        glutPostRedisplay();
}
void shipMOve(){
    rotateBridge=1;

    glutTimerFunc(0.002, updateShipMOve, 0);
}
void shipMoveStop(){
    shipspeed=0;
}

//SHIP MOVING END...............................................................

void prerequisideRotating(){
    rotatingBridgeLeft();
    rotationBridgeRight();
    bridge();

    movingShip();
    carMove();
    carMove2();
}
void Rotating_Moving_CarMoving(int){

    bridgeRotate();

    if(isBridgeRotateStopped==1){
        shipMOve();
    }
    if(isShipMoved==1 && isBridgeRotateStopped==1){
        bridgeRotateReverse();
    }


    if(X<0.0 && Y>0.0){
        stopCar();
    }
    else{
        MoveCar();

    }
    glutTimerFunc(20,Rotating_Moving_CarMoving,0);

}
/////////////////////////////////////////////////////////Scene1////////////////////////////////////////
float s= 10;                  //-310;
float p = -.4;
int i= -100;

float j= -57.85;
float k= -88.14;
float r=.5;
float l=7.14;
float  su= 0;
float  u= 0;
float ll=1.42;
bool dbus2=false;
void circle1(float radius, float cX, float cY, float r,float g,float b)
{
   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
}



void circle3(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_POLYGON);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();


}
void sky10Morning ()
{
    if(l<= 300)
        l = l+ .19;
    else
        l = -50;
    glBegin(GL_QUADS);
    glColor3ub(255, 255,l+ 147);
    glVertex2f(-50,-7);
    glVertex2f(50,-7);
    glColor3ub(l+102, 204,255); //sky
    glVertex2f(50,40);
    glVertex2f(-50,40);
    glEnd();

}

void sky10Evening ()
{
    glBegin(GL_QUADS);
    glColor3ub(209, 128, 84);
    glVertex2f(-50,-7);
    glColor3ub(122, 212, 240);
    glVertex2f(50,-7);
    glColor3ub(245, 202, 166);//sky
    glVertex2f(50,40);
    glColor3ub(160, 186, 222);
    glVertex2f(-50,40);
    glEnd();

}

void sky10Night ()
{
    glBegin(GL_QUADS);
    glColor3ub(8, 32, 64);
    glVertex2f(-50,-7);
    glColor3ub(50, 54, 59);
    glVertex2f(50,-7);
    glColor3ub(3, 30, 64);//sky
    glVertex2f(50,40);
    glColor3ub(2, 19, 41);
    glVertex2f(-50,40);
    glEnd();

}
void sky10Rain() {
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);  // Light gray color for a rainy sky
    glVertex2f(-50,-7);
    glVertex2f(50,-7);
    glVertex2f(50,40);
    glVertex2f(-50,40);
    glEnd();
}

void grass25(){
    glBegin(GL_QUADS);
    glColor3ub(89, 158, 79);
    glVertex2f(-50,-17);
    glVertex2f(50,-17);
    glVertex2f(50,-12);//grass
    glVertex2f(-50,-12);
    glEnd();
}
void road(){
    //////////////////////////////////////////////////// road
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex2f(-50,-7);
    glVertex2f(50,-7);
    glVertex2f(50,-12);
    glVertex2f(-50,-12);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);//Road top bar
    glLineWidth(2);
    glColor3f(1,1.0,1.0);
    glVertex2f(-50,-7.155);
    glVertex2f(50,-7.155);
    glEnd();
    glLineWidth(1);

    glBegin(GL_LINES);//Road middle bar
    glLineWidth(1);
    glColor3f(1.0,1.0,1.0);
    glVertex2i(-50,-9.955);
    glVertex2i(50,-9.955);
    glEnd();

    glBegin(GL_LINES);//Road Botom bar
    glColor3f(1.0,1.0,1.0);
    glVertex2i(-50,-12);
    glVertex2i(50,-12);
    glEnd();
}


void b_tree1(){
    glBegin(GL_POLYGON);  ///Bottom tree1   ///
    glColor3ub(75,35,5);
    glVertex2f(40,-17);
    glVertex2f(41,-17);
    glVertex2f(41,-15.5);
    glVertex2f(40,-15.5);
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(33, 117, 32);
    glVertex2f(41.5,-15.5);
    glVertex2f(40.25,-12);
    glVertex2f(39.5,-15.5);


    glEnd();

    glBegin(GL_POLYGON);  ///Bottom tree2  ///
    glColor3ub(75,35,5);
    glVertex2f(20,-17);
    glVertex2f(21,-17);
    glVertex2f(21,-15.5);
    glVertex2f(20,-15.5);
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(33, 117, 32);
    glVertex2f(19.5,-15.5);
    glVertex2f(20.25,-12);
    glVertex2f(21.5,-15.5);
    glEnd();

    glBegin(GL_POLYGON);  ///Bottom tree3   ///
    glColor3ub(75,35,5);
    glVertex2f(0,-17);
    glVertex2f(1,-17);
    glVertex2f(1,-15.5);
    glVertex2f(0,-15.5);
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(33, 117, 32);
    glVertex2f(-.5,-15.5);
    glVertex2f(.25,-12);
    glVertex2f(1.5,-15.5);


    glEnd();

    glBegin(GL_POLYGON);  ///Bottom tree1   ///
    glColor3ub(75,35,5);
    glVertex2f(-40,-17);
    glVertex2f(-41,-17);
    glVertex2f(-41,-15.5);
    glVertex2f(-40,-15.5);
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(33, 117, 32);
    glVertex2f(-41.5,-15.5);
    glVertex2f(-40.25,-12);
    glVertex2f(-39.5,-15.5);


    glEnd();

    glBegin(GL_POLYGON);  ///Bottom tree2  ///
    glColor3ub(75,35,5);
    glVertex2f(-20,-17);
    glVertex2f(-21,-17);
    glVertex2f(-21,-15.5);
    glVertex2f(-20,-15.5);
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(33, 117, 32);
    glVertex2f(-19.5,-15.5);
    glVertex2f(-20.25,-12);
    glVertex2f(-21.5,-15.5);
    glEnd();
//////////////////////////////////////////roaad up tree
    ///

    glBegin(GL_POLYGON);
  glColor3ub(75,35,5);
  glVertex2f(47,-6.5);
  glVertex2f(47,-5.5);         //body
  glVertex2f(46,-5.5);
    glVertex2f(46,-6.5);
  glEnd();

    glBegin(GL_POLYGON);
  glColor3ub(33, 117, 32);
  glVertex2f(47.5,-5.5);
  glVertex2f(46.5,-4);
  glVertex2f(45.5,-5.5);
  glEnd();
    glBegin(GL_POLYGON);
  glColor3ub(33, 117, 32);
  glVertex2f(47.5,-4.6);
  glVertex2f(46.5,-3);
  glVertex2f(45.5,-4.6);
  glEnd();


    glBegin(GL_POLYGON);
  glColor3ub(75,35,5);
  glVertex2f(-47,-6.5);
  glVertex2f(-47,-5.5);         //body
  glVertex2f(-46,-5.5);
    glVertex2f(-46,-6.5);
  glEnd();

    glBegin(GL_POLYGON);
  glColor3ub(33, 117, 32);
  glVertex2f(-47.5,-5.5);
  glVertex2f(-46.5,-4);
  glVertex2f(-45.5,-5.5);
  glEnd();

    glBegin(GL_POLYGON);
  glColor3ub(33, 117, 32);
  glVertex2f(-47.5,-4.6);
  glVertex2f(-46.5,-3);
  glVertex2f(-45.5,-4.6);
  glEnd();




}



void building1(){

    glBegin(GL_POLYGON);
    glColor3ub(250, 201, 77);
    glVertex2f(-28,11);
    glVertex2f(-28,14);

    glVertex2f(-45,18);
    glColor3ub( 237, 167, 114);
    //  up connector
    glVertex2f(-45,15);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250, 201, 77);
    glVertex2f(-35,-7);
    glColor3ub(69, 127, 150);
    glVertex2f(-35,24);      //  dan lomba
    glVertex2f(-30,24);
    glColor3ub( 237, 167, 114);
    glVertex2f(-30,-7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(250, 201, 77);
    glVertex2f(-27,-3);
    glVertex2f(-27,4);
    glVertex2f(-47,4);
    glVertex2f(-47,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(250, 201, 77);
    glVertex2f(-40,-7);
    glColor3ub(252, 181, 159);
    glVertex2f(-40,20);      //  bam lomba
    glVertex2f(-45,20);
    glColor3ub( 237, 167, 114);
    glVertex2f(-45,-7);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-33.5,24);
    glVertex2f(-33.5,-7);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-31.5,24);
    glVertex2f(-31.5,-7);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,22);
    glVertex2f(-30,22);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,20);
    glVertex2f(-30,20);
    glEnd();


    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,18);
    glVertex2f(-30,18);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,16);
    glVertex2f(-30,16);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,14);
    glVertex2f(-30,14);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,12);
    glVertex2f(-30,12);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,10);
    glVertex2f(-30,10);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,8);
    glVertex2f(-30,8);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,6);
    glVertex2f(-30,6);
    glEnd();


    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,4);
    glVertex2f(-30,4);
    glEnd();



    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,-4);
    glVertex2f(-30,-4);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-35,-6);
    glVertex2f(-30,-6);
    glEnd();




    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-43.5,20);
    glVertex2f(-43.5,-7);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-41.5,20);
    glVertex2f(-41.5,-7);
    glEnd();



    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,18);
    glVertex2f(-40,18);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,16);
    glVertex2f(-40,16);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,14);
    glVertex2f(-40,14);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,12);
    glVertex2f(-40,12);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,10);
    glVertex2f(-40,10);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,8);
    glVertex2f(-40,8);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,6);
    glVertex2f(-40,6);
    glEnd();


    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,4);
    glVertex2f(-40,4);
    glEnd();



    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-47,2);
    glVertex2f(-27,2);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-47,0);
    glVertex2f(-27,0);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-47,-2);
    glVertex2f(-27,-2);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,-4);
    glVertex2f(-40,-4);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(-45,-6);
    glVertex2f(-40,-6);
    glEnd();

    glColor3ub(18, 24, 255);
    glRasterPos2f(-32,2.9);

    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'T');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'E');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'N');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'C');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'E');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'N');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'T');

}
void building5() {

    glBegin(GL_POLYGON);
    glColor3ub(250, 100, 50);
    glVertex2f(28,11);
    glVertex2f(28,14);

    glVertex2f(45,18);
    glColor3ub( 237, 167, 114);
                                  //  up connector
    glVertex2f(45,15);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250, 100, 50);
    glVertex2f(35,-7);
    glColor3ub(69, 127, 150);
    glVertex2f(35,20);      //  dan lomba
    glVertex2f(30,20);
    glColor3ub( 237, 167, 114);
    glVertex2f(30,-7);
    glEnd();
    glColor3ub(102, 102, 102);
    circle3(.3,.6,33.9,24);
    glColor3ub(217, 217, 217);
    circle3(.25,.5,33.9,24);
    glColor3ub(102, 102, 102);
    circle3(.2,.4,33.3,21);
    glColor3ub(217, 217, 217);
    circle3(.15,.3,33.3,21);
    glBegin(GL_POLYGON);
    glColor3ub(240, 83, 31);
    glVertex2f(27,-3);
    glVertex2f(27,4);
    glVertex2f(47,4);
    glVertex2f(47,-3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(27, 142, 242);
    glVertex2f(40,-7);
    glColor3ub(252, 181, 159);
    glVertex2f(40,19);      //  bam lomba
    glVertex2f(45,19);
    glColor3ub( 237, 167, 114);
    glVertex2f(45,-7);
    glEnd();

   // glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(33.5,24);
    glVertex2f(33.5,-7);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(31.5,20);
    glVertex2f(31.5,-7);
    glEnd();



    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,20);
    glVertex2f(30,20);
    glEnd();


    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,18);
    glVertex2f(30,18);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,16);
    glVertex2f(30,16);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,14);
    glVertex2f(30,14);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,12);
    glVertex2f(30,12);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,10);
    glVertex2f(30,10);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,8);
    glVertex2f(30,8);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,6);
    glVertex2f(30,6);
    glEnd();


    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,4);
    glVertex2f(30,4);
    glEnd();




    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,-4);
    glVertex2f(30,-4);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(35,-6);
    glVertex2f(30,-6);
    glEnd();




    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(43.5,19);
    glVertex2f(43.5,-7);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(41.5,19);
    glVertex2f(41.5,-7);
    glEnd();



    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,18);
    glVertex2f(40,18);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,16);
    glVertex2f(40,16);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,14);
    glVertex2f(40,14);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,12);
    glVertex2f(40,12);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,10);
    glVertex2f(40,10);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,8);
    glVertex2f(40,8);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,6);
    glVertex2f(40,6);
    glEnd();


    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,4);
    glVertex2f(40,4);
    glEnd();



    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(47,2);
    glVertex2f(27,2);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(47,0);
    glVertex2f(27,0);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(47,-2);
    glVertex2f(27,-2);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,-4);
    glVertex2f(40,-4);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(138, 147, 148);
    glVertex2f(45,-6);
    glVertex2f(40,-6);
    glEnd();

    glColor3ub(18, 24, 255);
    glRasterPos2f(32,2.9);

    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'K');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'R');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'A');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'F');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'T');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'O');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'N');
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void riverScene1(){
    if(r<=100)
          r = r+ .3;
      else
          r = -0;
    glBegin(GL_QUADS);
    glColor3ub(115, 120,155);
    glVertex2f(50,-40);
    glColor3ub(50, 200, r+155);
    glVertex2f(50,-17);
    glColor3ub(r-19,101, r-255);
    glVertex2f(-50,-17);
    glColor3ub(50, 150, 255);
    glVertex2f(-50,-40);
    glEnd();

}
void ship4(){
    if(s<= 100 && isShipMoving)
        s = s + .9;  //.5
    else
        s = -55;
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(35, 25, 89);
    glVertex2f(-50+s,-38);  //botom
    glVertex2f(-15+s,-38);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(173, 224, 218);

    glVertex2f(-15.25+s,-37.7);  //body
    glColor3ub(5*s+173, 224, 28);
    glVertex2f(-6+s,-27);
    glColor3ub(5*s-273, 224, 218);
    glVertex2f(-48+s,-27);
    glColor3ub(173, 124, 218);
    glVertex2f(-50+s,-30);
    glColor3ub(179, 204, 5*s-118);
    glVertex2f(-50+s,-37.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(134, 171, 191);
    glVertex2f(-15.25+s,-37.7);  //triangle
        glColor3ub(134, 191, 191);
    glVertex2f(-7.6+s,-29);
        glColor3ub(134, 191, s+191);
    glVertex2f(-25+s,-37.7);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(134, 171, 191);
    glVertex2f(-38+s,-27);  //lez

    glVertex2f(-38+s,-20);
    glColor3ub(14, 191, s+291);
    glVertex2f(-43+s,-20);
    glColor3ub(s*134, 161, 191);
    glVertex2f(-47.5+s,-27);
    glEnd();

    glLineWidth(30.0f);
    glBegin(GL_LINES);
    glColor3ub(134, 171, 191);
    glVertex2f(-43+s, -19);
    glVertex2f(-38+s, -19); // luz up
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-42.2+s, -21.5);
    glVertex2f(-42.2+s, -19); // luz up window color
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-40.7+s, -21.5);
    glVertex2f(-40.7+s, -19); // luz up window color
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-39.3+s, -21.5);
    glVertex2f(-39.3+s, -19); // luz up window color
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-38.6+s, -22.5);
    glVertex2f(-38.6+s, -26); // luz down window color
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-40+s, -22.5);
    glVertex2f(-40+s, -26); // luz down window color
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-41.45+s, -22.5);
    glVertex2f(-41.45+s, -26); // luz down window color
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-42.85+s, -22.5);
    glVertex2f(-42.85+s, -26); // luz down window color
    glEnd();


    glLineWidth(9.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-44+s, -22.5);
    glVertex2f(-44+s, -26); // luz down window color
    glEnd();

    glLineWidth(9.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-46.15+s, -26.5);
    glVertex2f(-46.15+s, -25); // luz down window color
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-45+s, -26.5);
    glVertex2f(-45+s, -25); // luz down window color
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(139, 189, 217);
    glVertex2f(-11+s,-27);  // middle ship left top
    glVertex2f(-16+s,-19.75);
    glVertex2f(-37+s,-19.75);
    glVertex2f(-37+s,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 189, 217);
    glVertex2f(-16+s,-19.75);  // middle ship 2nd right top
    glVertex2f(-19.2+s,-15);
    glVertex2f(-25+s,-15);
    glVertex2f(-27+s,-19.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(59, 79, 117);
    glVertex2f(s+110,-95);  // middle ship 2nd right top
    glVertex2f(s+90,-55);
    glVertex2f(s+52,-55);
    glVertex2f(s+52,-95);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(59, 79, 117);
    glVertex2f(-30+s,-19.75);  // middle ship 2nd right top
    glVertex2f(-32+s,-16.75);
    glVertex2f(-37+s,-16.75);
    glVertex2f(-37+s,-19.75);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(139, 189, 217); // left middle top window
    glVertex2f(-37+s, -16.2);
    glVertex2f(-32+s,-16.2);
    glEnd();


    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61); // left middle top top w
    glVertex2f(-36.35+s, -17.2);
    glColor3ub(7, 92, 255);
    glVertex2f(-36.35+s,-19.4);
    glEnd();


    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61); // left middle top top w
    glVertex2f(-35.35+s, -17.2);
    glColor3ub(7, 92, 255);
    glVertex2f(-35.35+s,-19.4);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61); // left middle top top w
    glVertex2f(-34.35+s, -17.2);
    glColor3ub(7, 92, 255);
    glVertex2f(-34.35+s,-19.4);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61); // left middle top top w
    glVertex2f(-33.35+s, -17.2);
    glColor3ub(7, 92, 255);
    glVertex2f(-33.35+s,-19.4);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61); // left middle top top w
    glVertex2f(-32.25+s, -17.2);
    glColor3ub(7, 92, 255);
    glVertex2f(-32.25+s,-19.4);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); // left middle top top
    glVertex2f(-36.5+s, -15.5);
    glVertex2f(-36.5+s,-14.5);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); // left middle top top
    glVertex2f(-35.5+s, -15.5);
    glVertex2f(-35.5+s,-15);
    glEnd();
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); // left middle top top
    glVertex2f(-34.5+s, -15.5);
    glVertex2f(-34.5+s,-14.5);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); // left middle top top
    glVertex2f(-33.5+s, -15.5);
    glVertex2f(-33.5+s,-15);
    glEnd();
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); // left middle top top
    glVertex2f(-32.5+s, -15.5);
    glVertex2f(-32.5+s,-14.5);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61); //futa
    glVertex2f(-16.5+s, -37.5);
    glVertex2f(-16.5+s,-37);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine line
    glVertex2f(-48+s, -37);
    glVertex2f(-43+s,-37);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine line
    glVertex2f(-48+s, -36.5);
    glVertex2f(-43+s,-36.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine line
    glVertex2f(-48+s, -36);
    glVertex2f(-43+s,-36);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine line
    glVertex2f(-48+s, -35);
    glVertex2f(-43+s,-35);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine line
    glVertex2f(-48+s, -34.5);
    glVertex2f(-43+s,-34.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine line
    glVertex2f(-48+s, -34);
    glVertex2f(-43+s,-34);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine line
    glVertex2f(-48+s, -33.5);
    glVertex2f(-43+s,-33.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-45+s, -30.5);
    glVertex2f(-44+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-45.5+s, -30.5);
    glVertex2f(-46.5+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-43+s, -30.5);
    glVertex2f(-42+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-40.5+s, -30.5);
    glVertex2f(-41.5+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-40+s, -30.5);
    glVertex2f(-39+s,-30.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-38.5+s, -30.5);
    glVertex2f(-37.5+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-36+s, -30.5);
    glVertex2f(-37+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-36.5+s, -30.5);
    glVertex2f(-35.5+s,-30.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-35+s, -30.5);
    glVertex2f(-34+s,-30.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-33.5+s, -30.5);
    glVertex2f(-32.5+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-32+s, -30.5);
    glVertex2f(-31+s,-30.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-30.5+s, -30.5);
    glVertex2f(-29.5+s,-30.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-28+s, -30.5);
    glVertex2f(-29+s,-30.5);
    glEnd();



    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-27.5+s, -30.5);
    glVertex2f(-26.5+s,-30.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-26+s, -30.5);
    glVertex2f(-25+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-24.5+s, -30.5);
    glVertex2f(-23.5+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-23+s, -30.5);
    glVertex2f(-22+s,-30.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-21.5+s, -30.5);
    glVertex2f(-20.5+s,-30.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-20+s, -30.5);
    glVertex2f(-19+s,-30.5);
    glEnd();



    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-18.5+s, -30.5);
    glVertex2f(-17.5+s,-30.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-23+s, -32.5);
    glVertex2f(-22+s,-32.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-21.5+s, -32.5);
    glVertex2f(-20.5+s,-32.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-20+s, -32.5);
    glVertex2f(-19+s,-32.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-45+s, -32.5);
    glVertex2f(-44+s,-32.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-45.5+s, -32.5);
    glVertex2f(-46.5+s,-32.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-43+s, -32.5);
    glVertex2f(-42+s,-32.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-40.5+s, -32.5);
    glVertex2f(-41.5+s,-32.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-40+s, -32.5);
    glVertex2f(-39+s,-32.5);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-38.5+s, -32.5);
    glVertex2f(-37.5+s,-32.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-36+s, -32.5);
    glVertex2f(-37+s,-32.5);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-36.5+s, -32.5);
    glVertex2f(-35.5+s,-32.5);
    glEnd();



    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(105, 125, 138); //engine window
    glVertex2f(-18.5+s, -32.5);
    glVertex2f(-17.5+s,-32.5);
    glEnd();
    circle1(.3,-23.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-24.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-25.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-26.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-27.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-28.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-29.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-30.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-35.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-36.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-37.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-38.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-39.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    circle1(.3,-40.5+s,-35,105, 125, 138);  // engine window
    glEnd();


    circle1(.3,-41.5+s,-35,105, 125, 138);  // engine window
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(35, 25, 255); //body  line
    glVertex2f(-47.5+s, -27);
    glVertex2f(-13.5+s,-27);
    glEnd();


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(35, 25, 89); //body  life baloon
    glVertex2f(-47.5+s, -27.9);
    glVertex2f(-39+s,-27.9);
    glEnd();
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    circle1(.65,-46.5+s,-28,237, 179, 64);
    glEnd();

    circle1(.3,-46.5+s,-28,35, 25, 89);
    glEnd();


    circle1(.65,-44.5+s,-28,237, 179, 64);
    glEnd();

    circle1(.3,-44.5+s,-28,35, 25, 89);
    glEnd();



    circle1(.65,-42.5+s,-28,237, 179, 64);
    glEnd();

    circle1(.3,-42.5+s,-28,35, 25, 89);
    glEnd();


    circle1(.65,-40.5+s,-28,237, 179, 64);
    glEnd();

    circle1(.3,-40.5+s,-28,35, 25, 89);
    glEnd();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(35, 25, 89); //body  life baloon
    glVertex2f(-29.5+s, -27.9);
    glVertex2f(-38+s,-27.9);
    glEnd();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       circle1(.65,-30.5+s,-28,237, 179, 64);
       glEnd();

       circle1(.3,-30.5+s,-28,35, 25, 89);
       glEnd();


       circle1(.65,-32.5+s,-28,237, 179, 64);
       glEnd();

       circle1(.3,-32.5+s,-28,35, 25, 89);
       glEnd();



       circle1(.65,-34.5+s,-28,237, 179, 64);
       glEnd();

       circle1(.3,-34.5+s,-28,35, 25, 89);
       glEnd();


       circle1(.65,-36.5+s,-28,237, 179, 64);
       glEnd();

       circle1(.3,-36.5+s,-28,35, 25, 89);
       glEnd();

       ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(35, 25, 89); //body  life baloon
    glVertex2f(-23+s, -27.9);
    glVertex2f(-28+s,-27.9);
    glEnd();

       circle1(.65,-26.5+s,-28,237, 179, 64);
       glEnd();

       circle1(.3,-26.5+s,-28,35, 25, 89);
       glEnd();


       circle1(.65,-24.5+s,-28,237, 179, 64);
       glEnd();

       circle1(.3,-24.5+s,-28,35, 25, 89);
       glEnd();




    glLineWidth(30.0f);
    glBegin(GL_LINES);
    glColor3ub(35, 25, 89); //body  w
    glVertex2f(-23+s, -25.9);
    glVertex2f(-29.5+s,-25.9);
    glEnd();


    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64); //body w
    glVertex2f(-23.5+s, -25.9);
    glVertex2f(-24.5+s,-25.9);
    glEnd();


    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64); //body  w
    glVertex2f(-26+s, -25.9);
    glVertex2f(-25+s,-25.9);
    glEnd();


    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64); //body w
    glVertex2f(-27.5+s, -25.9);
    glVertex2f(-26.5+s,-25.9);
    glEnd();

    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64); //body  w
    glVertex2f(-28+s, -25.9);
    glVertex2f(-29+s,-25.9);
    glEnd();


    glLineWidth(30.0f);
    glBegin(GL_LINES);
    glColor3ub(35, 25, 89); //body  w
    glVertex2f(-22+s, -25.9);
    glVertex2f(-15.5+s,-25.9);
    glEnd();


    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64); //body w  orange
    glVertex2f(-16+s, -25.9);
    glVertex2f(-17+s,-25.9);
    glEnd();

    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64); //body w  orange
    glVertex2f(-18.5+s, -25.9);
    glVertex2f(-17.5+s,-25.9);
    glEnd();

    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64); //body w  orange
    glVertex2f(-19+s, -25.9);
    glVertex2f(-20+s,-25.9);
    glEnd();

    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64); //body w  orange
    glVertex2f(-20.5+s, -25.9);
    glVertex2f(-21.5+s,-25.9);
    glEnd();


    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-31+s, -25.9);
    glVertex2f(-30+s,-25.9);
    glEnd();


    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-31.5+s, -25.9);
    glVertex2f(-32.5+s,-25.9);
    glEnd();

    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-33+s, -25.9);
    glVertex2f(-34+s,-25.9);
    glEnd();


    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-34.5+s, -25.9);
    glVertex2f(-35.5+s,-25.9);
    glEnd();



    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-36+s, -25.9);
    glVertex2f(-37+s,-25.9);
    glEnd();





    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-31+s, -24);
    glVertex2f(-30+s,-24);
    glEnd();


    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-31.5+s, -24);
    glVertex2f(-32.5+s,-24);
    glEnd();

    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-33+s, -24);
    glVertex2f(-34+s,-24);
    glEnd();


    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-34.5+s, -24);
    glVertex2f(-35.5+s,-24);
    glEnd();



    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-36+s, -24);
    glVertex2f(-37+s,-24);
    glEnd();


    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-20+s, -24);
    glVertex2f(-21+s,-24);
    glEnd();

    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-21.5+s, -24);
    glVertex2f(-22.5+s,-24);
    glEnd();

    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-23+s, -24);
    glVertex2f(-24+s,-24);
    glEnd();


    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-24.5+s, -24);
    glVertex2f(-25.5+s,-24);
    glEnd();


    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-26+s, -24);
    glVertex2f(-27+s,-24);
    glEnd();



    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 235, 222); //line blue window
    glVertex2f(-27.5+s, -24);
    glVertex2f(-28.5+s,-24);
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(252,0,0); //liner ed  window
    glVertex2f(-15+s, -24);
    glVertex2f(-14+s,-24);
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(252,0,0); //liner ed  window
    glVertex2f(-15.5+s, -24);
    glVertex2f(-16.5+s,-24);
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(252,0,0); //liner ed  window
    glVertex2f(-17+s, -24);
    glVertex2f(-18+s,-24);
    glEnd();


    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-19.2+s, -16);
    glVertex2f(-20.2+s, -16); // right top
    glEnd();



    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-21.7+s, -16);
    glVertex2f(-20.7+s, -16); //right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-22.2+s, -16);
    glVertex2f(-23.2+s, -16); // right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-23.7+s, -16);
    glVertex2f(-24.7+s, -16); //right top
    glEnd();

    ///////////////////////////////////////////////////////////////
    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-18.7+s, -19);
    glVertex2f(-17.7+s, -19); //right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-19.2+s, -19);
    glVertex2f(-20.2+s, -19); // right top
    glEnd();



    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-21.7+s, -19);
    glVertex2f(-20.7+s, -19); //right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-22.2+s, -19);
    glVertex2f(-23.2+s, -19); // right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-23.7+s, -19);
    glVertex2f(-24.7+s, -19); //right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-25.2+s, -19);
    glVertex2f(-26.2+s, -19); // right top
    glEnd();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-15.2+s, -22);
    glVertex2f(-15.7+s, -22); //right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-17.2+s, -22);
    glVertex2f(-16.2+s, -22); // right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-18.7+s, -22);
    glVertex2f(-17.7+s, -22); //right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-19.2+s, -22);
    glVertex2f(-20.2+s, -22); // right top
    glEnd();



    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-21.7+s, -22);
    glVertex2f(-20.7+s, -22); //right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-22.2+s, -22);
    glVertex2f(-23.2+s, -22); // right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-23.7+s, -22);
    glVertex2f(-24.7+s, -22); //right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-25.2+s, -22);
    glVertex2f(-26.2+s, -22); // right top
    glEnd();


    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-27.7+s, -22);
    glVertex2f(-26.7+s, -22); // right top
    glEnd();


    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-27.2+s, -22);
    glVertex2f(-28.2+s, -22); // right top
    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-28.7+s, -22);
    glVertex2f(-29.7+s, -22); // right top
    glEnd();


    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-30.2+s, -22);
    glVertex2f(-31.2+s, -22); // right top
    glEnd();


    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-31.7+s, -22);
    glVertex2f(-32.7+s, -22); // right top
    glEnd();


    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-33.2+s, -22);
    glVertex2f(-34.2+s, -22); // right top
    glEnd();




    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-34.7+s, -22);
    glVertex2f(-35.7+s, -22); // right top
    glEnd();



    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-36.2+s, -22);
    glVertex2f(-37+s, -22); // right top
    glEnd();



   // front
    glBegin(GL_POLYGON);
    glColor3ub(70, 142, 179);
    glVertex2f(-8+s,-27);
    glVertex2f(-18+s,-13);
    glVertex2f(-20.6+s,-13);
    glVertex2f(-11+s,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70, 142, 179);
    glVertex2f(-19.2+s,-15);
    glVertex2f(-19.2+s,-13);
    glVertex2f(-23.5+s,-13);
    glVertex2f(-23.5+s,-15);
    glEnd();


    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(7, 42, 61);
    glVertex2f(-21+s, -12.5);
    glVertex2f(-22.5+s, -12.5); // right top
    glEnd();

    glLineWidth(11.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64);
    glVertex2f(-21+s, -12);
    glVertex2f(-22.5+s, -12); // right top
    glEnd();
    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glColor3ub(237, 179, 64);
    glVertex2f(-20.5+s, -12.2);
    glVertex2f(-18.5+s, -12.2); // right top
    glEnd();


    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 33);
    glVertex2f(-20.5+s, -11.5);
    glVertex2f(-18.5+s, -11.5); // right top
    glEnd();


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    glBegin(GL_POLYGON);
    glColor3ub(9, 15, 38);
    glVertex2f(-17.05+s,-14.5);    //shield
    glVertex2f(-18+s,-13.2);
    glVertex2f(-21.5+s,-13.2);
    glVertex2f(-21.5+s,-14.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(9, 15, 38);
    glVertex2f(-14.8+s,-17.5);    //shield
    glVertex2f(-15.8+s,-16.2);
    glVertex2f(-18.5+s,-16.2);
    glVertex2f(-17.5+s,-17.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(9, 15, 38);
    glVertex2f(-12.65+s,-20.5);    //shield
    glVertex2f(-13.5+s,-19.2);
    glVertex2f(-16.4+s,-19.2);
    glVertex2f(-15.5+s,-20.5);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(9, 15, 38);
    glVertex2f(-9.7+s,-24.5);    //shield
    glVertex2f(-10.7+s,-23.2);
    glVertex2f(-13.6+s,-23.2);
    glVertex2f(-12.6+s,-24.5);
    glEnd();

}

void building2(){


    glBegin(GL_POLYGON);
    glColor3ub(161, 191, 187);
    glVertex2f(-16,-7);
    glColor3ub(53, 240, 93);
    glVertex2f(-16,15);                   // main  body
    glVertex2f(-26,15);
    glVertex2f(-26,-7);
    glEnd();
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);
    glColor3ub(230, 162, 53);
    glVertex2f(-16.5,11);
    glColor3ub(244, 247, 57);
    glVertex2f(-16.6,14);                  //for window back
    glVertex2f(-25.5,14);
    glVertex2f(-25.5,11);
    glEnd();


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-25, 12.25);
    glVertex2f(-22,12.25);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-17, 12.25);//w
    glVertex2f(-20,12.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); ///////////////w
    glVertex2f(-17.2, 12.25);
    glVertex2f(-18.5,12.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128);
    glVertex2f(-24.8, 12.25);// w
    glVertex2f(-23.5,12.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); //wi
    glVertex2f(-22.1, 12.25);
    glVertex2f(-23.4,12.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); /////////////// window
    glVertex2f(-19.9, 12.25);
    glVertex2f(-18.6,12.25);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(91, 81, 97); /////////////// d
    glVertex2f(-25.5, 13);
    glVertex2f(-25.5,11);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); /////////////// d
    glVertex2f(-25.5, 12.5);
    glVertex2f(-25.5,11.7);
    glEnd();

    //////////////////////////////////////                                                       ////////////////////////////////////////////////////////////////////////////
    ///2

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);
    glColor3ub(230, 162, 53);
    glVertex2f(-16.5,7);
    glColor3ub(244, 247, 57);
    glVertex2f(-16.6,10);                  //for window back
    glVertex2f(-25.5,10);
    glVertex2f(-25.5,7);
    glEnd();


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-25, 8.25);
    glVertex2f(-22,8.25);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-17, 8.25);//w
    glVertex2f(-20,8.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); ///////////////w
    glVertex2f(-17.2, 8.25);
    glVertex2f(-18.5,8.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128);
    glVertex2f(-24.8, 8.25);// w
    glVertex2f(-23.5,8.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); //wi
    glVertex2f(-22.1, 8.25);
    glVertex2f(-23.4,8.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); /////////////// window
    glVertex2f(-19.9, 8.25);
    glVertex2f(-18.6,8.25);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(91, 81, 97); /////////////// d
    glVertex2f(-25.5, 9);
    glVertex2f(-25.5,7);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); /////////////// d
    glVertex2f(-25.5, 8.5);
    glVertex2f(-25.5,7.7);
    glEnd();

    //////////////////////////////////////                                                       ////////////////////////////////////////////////////////////////////////////
    ///

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);
    glColor3ub(230, 162, 53);
    glVertex2f(-16.5,3);
    glColor3ub(244, 247, 57);
    glVertex2f(-16.6,6);                  //for window back
    glVertex2f(-25.5,6);
    glVertex2f(-25.5,3);
    glEnd();


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-25, 4.25);
    glVertex2f(-22,4.25);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-17, 4.25);//w
    glVertex2f(-20,4.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); ///////////////w
    glVertex2f(-17.2, 4.25);
    glVertex2f(-18.5,4.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128);
    glVertex2f(-24.8, 4.25);// w
    glVertex2f(-23.5,4.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); //wi
    glVertex2f(-22.1, 4.25);
    glVertex2f(-23.4,4.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); /////////////// window
    glVertex2f(-19.9, 4.25);
    glVertex2f(-18.6,4.25);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(91, 81, 97); /////////////// d
    glVertex2f(-25.5, 5);
    glVertex2f(-25.5,3);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); /////////////// d
    glVertex2f(-25.5, 4.5);
    glVertex2f(-25.5,3.7);
    glEnd();

    //////////////////////////////////////                                                       ////////////////////////////////////////////////////////////////////////////
    ///

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);
    glColor3ub(230, 162, 53);
    glVertex2f(-16.5,-1);
    glColor3ub(244, 247, 57);
    glVertex2f(-16.6,2);            //for window back
    glVertex2f(-25.5,2);
    glVertex2f(-25.5,-1);
    glEnd();


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-25, .25);
    glVertex2f(-22,.25);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-17, .25);//w
    glVertex2f(-20,.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); ///////////////w
    glVertex2f(-17.2, .25);
    glVertex2f(-18.5,.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128);
    glVertex2f(-24.8, .25);       //w
    glVertex2f(-23.5,.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); //wi
    glVertex2f(-22.1, .25);
    glVertex2f(-23.4,.25);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); /////////////// window
    glVertex2f(-19.9, .25);
    glVertex2f(-18.6,.25);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(91, 81, 97); /////////////// d
    glVertex2f(-25.5, 1);
    glVertex2f(-25.5,-1);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); /////////////// d
    glVertex2f(-25.5, .5);
    glVertex2f(-25.5,-.3);
    glEnd();

    //////////////////////////////////////                                                       ////////////////////////////////////////////////////////////////////////////
    ///

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);
    glColor3ub(230, 162, 53);
    glVertex2f(-16.5,-5);
    glColor3ub(244, 247, 57);
    glVertex2f(-16.6,-2);                  //for window back
    glVertex2f(-25.5,-2);
    glVertex2f(-25.5,-5);
    glEnd();


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-25, -3.75);
    glVertex2f(-22,-3.75);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-17, -3.75);//w
    glVertex2f(-20,-3.75);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); ///////////////w
    glVertex2f(-17.2,-3.75);
    glVertex2f(-18.5,-3.75);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128);
    glVertex2f(-24.8,-3.75);// w
    glVertex2f(-23.5,-3.75);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); //wi
    glVertex2f(-22.1,-3.75);
    glVertex2f(-23.4,-3.75);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(47, 71, 128); /////////////// window
    glVertex2f(-19.9,-3.75);
    glVertex2f(-18.6,-3.75);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(91, 81, 97); /////////////// d
    glVertex2f(-25.5, -3);
    glVertex2f(-25.5,-5);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,255); /////////////// d
    glVertex2f(-25.5,-3.5);
    glVertex2f(-25.5,-4.3);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(50, 110, 69);
    glVertex2f(-50, -6.5);
    glVertex2f(50,-6.5); // grass
    glEnd();

    //////////////////////////////////////                                                       ////////////////////////////////////////////////////////////////////////////
}


void apple(){
    glBegin(GL_POLYGON);
    glColor3ub(82, 90, 99);
    glVertex2f(-0, -6.5);
    glVertex2f(-0, 8);  // ass
    glVertex2f(-15, 8);
    glVertex2f(-15, -6.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    glVertex2f(-2, -5.5);
    glVertex2f(-2, 6);   //white
    glVertex2f(-13, 6);
    glVertex2f(-13, -5.5);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-2, -5.5);
    glVertex2f(-2,6);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-13, 6);
    glVertex2f(-2,6);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-13, 6);
    glVertex2f(-13,-5.5);
    glEnd();


    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-2, -5.5);
    glVertex2f(-13,-5.5);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-2, -0.25); // middle divider
    glVertex2f(-13,-0.25);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-6, -5.5); // middle divider
    glVertex2f(-6,6);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-9, -5.5); // middle divider
    glVertex2f(-9,6);
    glEnd();


    //////////////////////////////////////////////////////////
    ///
    glBegin(GL_POLYGON);
    glColor3ub(82, 90, 99);
    glVertex2f(-0, -6.5);
    glVertex2f(-0, 21.5);  // ass
    glVertex2f(15, 21.5);
    glVertex2f(15, -6.5);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(0, -6.5); // lomba bam divider
    glVertex2f(0,21.5);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-16, 8); // lomba bam divider
    glVertex2f(15,8);
    glEnd();
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(15, -6.5); // lomba bam divider
    glVertex2f(15,21.5);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(52, 67, 64);
    glVertex2f(13, 10);
    glVertex2f(13,20);
    glVertex2f(2, 20);
    glVertex2f(2, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    glVertex2f(12.5, 10.5);
    glColor3ub(250, 245, 117);
    glVertex2f(12.5, 19.5); // white
    glVertex2f(2.5, 19.5);
    glVertex2f(2.5, 10.5);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(2.5,17); // lomba bam divider
    glVertex2f(12.5,17);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(2.5,13); // lomba bam divider
    glVertex2f(12.5,13);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(4,19.5); // lomba bam divider
    glVertex2f(4,10.5);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(7,19.5); // lomba bam divider
    glVertex2f(7,10.5);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(11,19.5); // lomba bam divider
    glVertex2f(11,10.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52, 67, 64);
    glVertex2f(7.25, -6.5);
    glVertex2f(7.25,6);
    glVertex2f(4.25, 6);
    glVertex2f(4.25, -6.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,204);
    glVertex2f(7, -6.25);
    glVertex2f(7,5.75);
    glVertex2f(4.5, 5.75);
    glVertex2f(4.5, -6.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52, 67, 64);
    glVertex2f(7.75, -6.5);
    glVertex2f(7.75,6);
    glVertex2f(10.75, 6);
    glVertex2f(10.75, -6.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,204);
    glVertex2f(8, -6.25);
    glVertex2f(8,5.75);
    glVertex2f(10.5, 5.75);
    glVertex2f(10.5, -6.25);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(8, -4.5); // lomba bam divider
    glVertex2f(10.5,-4.5);
    glEnd();
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(7, -4.5); // lomba bam divider
    glVertex2f(4.5,-4.5);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(0,6.5); // lomba bam divider
    glVertex2f(15,6.5);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(135, 133, 82);
    glVertex2f(2,9); // lomba bam divider
    glVertex2f(13,9);
    glEnd();
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(135, 133, 82);
    glVertex2f(2,8); // lomba bam divider
    glVertex2f(13,8);
    glEnd();
    glColor3ub(0,0,0);
    glRasterPos2i(5.5,8);

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'A');


    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'P');


    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'P');


    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'L');


     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'E');


    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,' ');


    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'S');


    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'T');


    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');


    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'R');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'E');
    //
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(0,6); // lomba bam divider
    glVertex2f(3.5,6);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(0,4); // lomba bam divider
    glVertex2f(3.5,4);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(0,4.5); // lomba bam divider
    glVertex2f(3.5,4.5);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(11.5,6); // lomba bam divider
    glVertex2f(15,6);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(11.5,4); // lomba bam divider
    glVertex2f(15,4);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(11.5,4.5); // lomba bam divider
    glVertex2f(15,4.5);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-.5,21.75); // lomba bam divider
    glVertex2f(15.5,21.75);
    glEnd();
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-1,22.2); // lomba bam divider
    glVertex2f(16,22.2);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-16,9); // lomba bam divider
    glVertex2f(0,9);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-16,10); // lomba bam divider
    glVertex2f(0,10);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-16,11); // lomba bam divider
    glVertex2f(0,11);
    glEnd();
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-15.8,11.2); // lomba bam divider
    glVertex2f(-15.8,7.8);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-11,11.2); // lomba bam divider
    glVertex2f(-11,7.8);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-7,11.2); // lomba bam divider
    glVertex2f(-7,7.8);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-3,11.2); // lomba bam divider
    glVertex2f(-3,7.8);
    glEnd();
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3ub(52, 67, 64);
    glVertex2f(-15.5,-6.5); // lomba bam divider
    glVertex2f(15.5,-6.5);
    glEnd();
}

void building4(){

    glBegin(GL_POLYGON);
    glColor3ub(230, 69, 163);
    glVertex2f(30, -6.5);
    glVertex2f(30,14);
    glVertex2f(16, 14);
    glVertex2f(16, -6.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(56, 115, 252);
    glVertex2f(29.5, -6);

    glVertex2f(29.5,13.5);
    glColor3ub(245, 160, 81);
    glVertex2f(16.5, 13.5);
    glColor3ub(245, 160, 81);
    glVertex2f(16.5, -6);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(20,-6.5); // lomba bam divider
    glVertex2f(20,14);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(24,-6.5); // lomba bam divider
    glVertex2f(24,14);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(27,-6.5); // lomba bam divider
    glVertex2f(27,14);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(16,-3); // lomba bam divider
    glVertex2f(30,-3);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(16,-0); // lomba bam divider
    glVertex2f(30,-0);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(16,3); // lomba bam divider
    glVertex2f(30,3);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(16,6); // lomba bam divider
    glVertex2f(30,6);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(16,9); // lomba bam divider
    glVertex2f(30,9);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,204);
    glVertex2f(16,12); // lomba bam divider
    glVertex2f(30,12);
    glEnd();


}

void tree10(){

}
void bus2(){


        if(k<= 100)
            k = k + 0.1;
        else
            k = -100;


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(43, 58, 139); // window body
    glVertex2f(k+0, -6.3);
    glVertex2f(k+10,-6.3);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(43, 58, 139);
    glVertex2f(k+0, -7.9);           //low
    glVertex2f(k+10.5,-7.9);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(43, 58, 139);  //low
    glVertex2f(k+0, -8.3);
    glVertex2f(k+10.5,-8.3);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(43, 58, 139); // mirror lnr
    glVertex2f(k+10.6, -5.45);
    glVertex2f(k+9,-5.45);
    glEnd();

    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(43, 58, 139); // mirror lnr
    glVertex2f(k+10.58, -5.45);
    glVertex2f(k+10.58,-6);
    glEnd();


    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(k+0.5, -6.1);
    glVertex2f(k+1.5,-6.1);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(k+2, -6.1);
    glVertex2f(k+3,-6.1);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(k+3.5, -6.1);
    glVertex2f(k+4.5,-6.1);
    glEnd();


    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(k+5, -6.1);
    glVertex2f(k+6,-6.1);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(k+6.5, -6.1);
    glVertex2f(k+7.5,-6.1);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //d
    glVertex2f(k+8, -6.9);
    glVertex2f(k+9,-6.9);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //d
    glVertex2f(k+8, -7.9);
    glVertex2f(k+9,-7.9);
    glEnd();


    glColor3ub(0,0,0);          //....chaka....back
    circle3(.5,.7,k+.9,-9);


    glColor3ub(255, 255, 204);
    circle3(.25,.29,k+.9,-9);



    glColor3ub(0,0,0);          //....chaka....back
    circle3(.5,.7,k+7.6,-9);


    glColor3ub(255, 255, 204);
    circle3(.25,.29,k+7.6,-9);



    glColor3ub(255, 255, 204);
    circle3(.25,.29,k+7.6,-7.3);

    glColor3ub(255, 255, 204);
    circle3(.4,.4,k+5,-7.5);

    glColor3ub(255, 255, 204);
    circle3(.6,.4,k+3,-8);

    glColor3ub(255, 255, 204);
    circle3(.6,.6,k+1,-7.3);


        glColor3ub(255, 2, 00);
        glRasterPos2i(k+1,-8);

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'P');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'R');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'O');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'J');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'A');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'P');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'O');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'T');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'I');
    }

void bus1(){


        if(j<= 100)
            j= j + 0.08;
        else
            j = -60;


    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 255, 0); // window body
    glVertex2f(j+0, -6.3);
    glVertex2f(j+10,-6.3);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 255, 0);
    glVertex2f(j+0, -7.9);           //low
    glVertex2f(j+10.5,-7.9);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 81, 76);  //low
    glVertex2f(j+0, -8.3);
    glVertex2f(j+10.5,-8.3);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 81, 76); // mirror lnr
    glVertex2f(j+10.6, -5.45);
    glVertex2f(j+9,-5.45);
    glEnd();

    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3ub(43, 58, 139); // mirror lnr
    glVertex2f(j+10.58, -5.45);
    glVertex2f(j+10.58,-6);
    glEnd();


    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(j+0.5, -6.1);
    glVertex2f(j+1.5,-6.1);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(j+2, -6.1);
    glVertex2f(j+3,-6.1);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(j+3.5, -6.1);
    glVertex2f(j+4.5,-6.1);
    glEnd();


    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(j+5, -6.1);
    glVertex2f(j+6,-6.1);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //w
    glVertex2f(j+6.5, -6.1);
    glVertex2f(j+7.5,-6.1);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //d
    glVertex2f(j+8, -6.9);
    glVertex2f(j+9,-6.9);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(136, 184, 235);  //d
    glVertex2f(j+8, -7.9);
    glVertex2f(j+9,-7.9);
    glEnd();


    glColor3ub(0,0,0);          //....chaka....back
    circle3(.5,.7,j+.9,-9);


    glColor3ub(255, 255, 204);
    circle3(.25,.29,j+.9,-9);



    glColor3ub(0,0,0);          //....chaka....back
    circle3(.5,.7,j+7.6,-9);


    glColor3ub(255, 255, 204);
    circle3(.25,.29,j+7.6,-9);



    glColor3ub(255, 255, 204);
    circle3(.25,.29,j+7.6,-7.3);

    glColor3ub(255, 255, 204);
    circle3(.4,.4,j+5,-7.5);

    glColor3ub(255, 255, 204);
    circle3(.6,.4,j+3,-8);

    glColor3ub(255, 255, 204);
    circle3(.6,.6,j+1,-7.3);


        glColor3ub(0, 41, 204);
        glRasterPos2i(j+2,-8);

    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'V');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'I');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'C');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'T');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'O');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'R');
glLineWidth(1.0f);
    }
bool moveSun3Down = false;
float sun3TranslationY = 0.0f;


void sun3(float translationX, float translationY)
{
    circle(1.5, 43.7 + translationX, 36.0f + translationY, 250, 240, 127);
}

void displayScene1Morning(){

    if (isRaining) {
        sky10Rain();
    } else {
        sky10Morning();
        sun3(0.0f, sun3TranslationY - 0.0f);
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


    grass25();
    road();
    b_tree1();
    building1();
    riverScene1();
    ship4();
    building2();
    apple();
    building4();
    building5();
    tree10;
    bus2();
    if (dbus2){

        bus2();
    }
    else{
       dbus2=false;
    }
    bus1();

    raindrops();

glutPostRedisplay();
glutSwapBuffers();

glFlush();
}

void displayScene1Evening(){

    if (isRaining) {
        sky10Rain();
    } else {
        sky10Evening();
        sun3(0.0f, sun3TranslationY - 0.0f);
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


    grass25();
    road();
    b_tree1();
    building1();
    riverScene1();
    ship4();
    building2();
    apple();
    building4();
    building5();
    tree10;
    bus2();
    if (dbus2){

        bus2();
    }
    else{
       dbus2=false;
    }
    bus1();

    raindrops();

glutPostRedisplay();
glutSwapBuffers();

glFlush();
}

void displayScene1Night(){
        sky10Night();
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

    moon(2.0, -40.0, 35.0, 255, 255, 255);
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


    grass25();
    road();
    b_tree1();
    building1();
    riverScene1();
    ship4();
    building2();
    apple();
    building4();
    building5();
    tree10;
    bus2();
    if (dbus2){

        bus2();
    }
    else{
       dbus2=false;
    }
    bus1();

    raindrops();

glutPostRedisplay();
glutSwapBuffers();

glFlush();
}

void updateSun3(int value)
{
    if (moveSun3Down)
    {
        sun3TranslationY -= 0.3f;             ///////////////////////////////sun update1
         if (sun3TranslationY < -18.0f)
        {
            glutDisplayFunc(displayScene1Evening);
            glutPostRedisplay();
        }
        if (sun3TranslationY < -36.0f)
        {
            glutDisplayFunc(displayScene1Night);
            glutPostRedisplay();
        }
        if (sun3TranslationY < -54.0f)
        {
            glutDisplayFunc(displayScene1Morning);
            glutPostRedisplay();
        }
        if (sun3TranslationY < -54.0f)
        {
            sun3TranslationY = 4.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateSun3, 0);
    }
}

void displayScene2Morning() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (isRaining) {
        skyRain();
    } else {
        skyMorning();
        sun(0.0f, sunTranslationY - 0.0f);
    }

    airplane(airplaneTranslationX-55.0f, 0.0f);

    treeTriangle(0.0f, 0.0f);
    treeTriangle(2.0f, 0.0f);
    treeTriangle(79.0f, -3.0f);
    treeTriangle(75.0f, -3.0f);
    treeTriangle(73.0f, -3.0f);
    treeTriangle(77.0f, -3.0f);
    treeTriangle(81.0f, -3.0f);

    treeCircle(0.0f, 0.0f);
    treeCircle(2.0f, 0.0f);

    mountain(0.0f, 0.0f);
    mountain(9.0f, -2.0f);
    mountain(24.0f, 0.0f);
    mountain(18.0f, -3.0f);
    mountain(28.0f, -1.0f);
    mountain(38.0f, -3.0f);
    mountain(45.0f, -1.0f);
    mountain(50.0f, -4.0f);

    windmill(0.0f,0.0f);
    windmill(20.0f,0.0f);

    land();

    grass(0.0f, -1.5f);
    grass(-5.0f, -1.5f);
    grass(-40.0f, -2.0f);
    grass(-44.0f, -2.0f);
    grass(-60.0f, -2.0f);
    grass(-70.0f, -2.0f);
    grass(-35.0f, -2.0f);
    grass(-80.0f, -2.0f);

    river();

    for (int i = -10; i <= 25; i=i+2) {
    wave(0.0f + i);
}
    for (int i = -40; i <-8; i=i+2) {
    wave2(0.0f + i);
}

    trafficLight(-12.0f,0.0f);
    trafficLight(53.0f,0.0f);

    streetLamp(-20.0f,0.0f);
    streetLamp(-28.0f,0.0f);
    streetLamp(60.0f,0.0f);
    streetLamp(68.0f,0.0f);

    prerequisideRotating();


    pillar(0.0f,10.0f);
    pillar(50.0f,10.0f);
    pillar(0.0f,0.0f);
    pillar(50.0f,0.0f);


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

void displayScene2Evening() {
    glClear(GL_COLOR_BUFFER_BIT);

     if (isRaining) {
              skyRain();

    } else {
         skyEvening();

    sun(0.0f,sunTranslationY - 0.0f);

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
    else{  cloud(cloudTranslationX, 0.0f);
    cloud(cloudTranslationX - 3.0f, 0.5f);
    cloud(cloudTranslationX - 30.0f, 2.0f);
    cloud(cloudTranslationX - 50.0f, 3.0f);
    cloud(cloudTranslationX - 70.0f, 3.0f);
    cloud(cloudTranslationX - 90.0f, 1.0f);
}


    airplane(airplaneTranslationX-55.0f, 0.0f);

    treeTriangle(0.0f, 0.0f);
    treeTriangle(2.0f, 0.0f);
    treeTriangle(79.0f, -3.0f);
    treeTriangle(75.0f, -3.0f);
    treeTriangle(73.0f, -3.0f);
    treeTriangle(77.0f, -3.0f);
    treeTriangle(81.0f, -3.0f);

    treeCircle(0.0f, 0.0f);
    treeCircle(2.0f, 0.0f);

    mountain(0.0f, 0.0f);
    mountain(9.0f, -2.0f);
    mountain(24.0f, 0.0f);
    mountain(18.0f, -3.0f);
    mountain(28.0f, -1.0f);
    mountain(38.0f, -3.0f);
    mountain(45.0f, -1.0f);
    mountain(50.0f, -4.0f);

    windmill(0.0f,0.0f);
    windmill(20.0f,0.0f);

    land();

    grass(0.0f, -1.5f);
    grass(-5.0f, -1.5f);
    grass(-40.0f, -2.0f);
    grass(-44.0f, -2.0f);
    grass(-60.0f, -2.0f);
    grass(-70.0f, -2.0f);
    grass(-35.0f, -2.0f);
    grass(-80.0f, -2.0f);

    river();
    for (int i = -10; i <= 25; i=i+2) {
    wave(0.0f + i);
}
    for (int i = -40; i <-8; i=i+2) {
    wave2(0.0f + i);
}

     trafficLight(-12.0f,0.0f);
    trafficLight(53.0f,0.0f);

    streetLamp(-20.0f,0.0f);
    streetLamp(-28.0f,0.0f);
    streetLamp(60.0f,0.0f);
    streetLamp(68.0f,0.0f);

    prerequisideRotating();

    pillar(0.0f,10.0f);
    pillar(50.0f,10.0f);
    pillar(0.0f,0.0f);
    pillar(50.0f,0.0f);

    raindrops();

    glFlush();
}

void displayScene2Night() {
    glClear(GL_COLOR_BUFFER_BIT);

    skyNight();

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

    moon(2.0, -40.0, 35.0, 255, 255, 255);

    airplane(airplaneTranslationX-55.0f, 0.0f);

    treeTriangle(0.0f, 0.0f);
    treeTriangle(2.0f, 0.0f);
    treeTriangle(79.0f, -3.0f);
    treeTriangle(75.0f, -3.0f);
    treeTriangle(73.0f, -3.0f);
    treeTriangle(77.0f, -3.0f);
    treeTriangle(81.0f, -3.0f);

    treeCircle(0.0f, 0.0f);
    treeCircle(2.0f, 0.0f);

    mountain(0.0f, 0.0f);
    mountain(9.0f, -2.0f);
    mountain(24.0f, 0.0f);
    mountain(18.0f, -3.0f);
    mountain(28.0f, -1.0f);
    mountain(38.0f, -3.0f);
    mountain(45.0f, -1.0f);
    mountain(50.0f, -4.0f);

    windmill(0.0f,0.0f);
    windmill(20.0f,0.0f);

    land();

    grass(0.0f, -1.5f);
    grass(-5.0f, -1.5f);
    grass(-40.0f, -2.0f);
    grass(-44.0f, -2.0f);
    grass(-60.0f, -2.0f);
    grass(-70.0f, -2.0f);
    grass(-35.0f, -2.0f);
    grass(-80.0f, -2.0f);

    river();
    for (int i = -10; i <= 25; i=i+2) {
    wave(0.0f + i);
}
    for (int i = -40; i <-8; i=i+2) {
    wave2(0.0f + i);
}

    trafficLight(-12.0f,0.0f);
    trafficLight(53.0f,0.0f);

    streetLamp(-20.0f,0.0f);
    streetLamp(-28.0f,0.0f);
    streetLamp(60.0f,0.0f);
    streetLamp(68.0f,0.0f);

    prerequisideRotating();

    pillar(0.0f,10.0f);
    pillar(50.0f,10.0f);
    pillar(0.0f,0.0f);
    pillar(50.0f,0.0f);

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



//***********************SCENE 3********************************
float ship1TranslationX = 0.0f;
float ship2TranslationX = 0.0f;
float ship1TranslationY = 0.0f;
float ship2TranslationY = 0.0f;
bool moveShip = false;
float angle1=0.0f;

void sun2(float translationX, float translationY)
{
    circle(1.5, 43.7 + translationX, 36.0f + translationY, 250, 240, 127);
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
        skyRain();
    } else {
        skyMorning();
        sun2(0.0f, sun2TranslationY - 0.0f);
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
              skyRain();

    } else {
         skyEvening();

    sun2(0.0f,sun2TranslationY - 0.0f);

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

    skyNight();

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

    moon(2.0, -40.0, 35.0, 255, 255, 255);

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

void updateSun(int value)
{
    if (moveSunDown)
    {
        sunTranslationY -= 0.01f;
         if (sunTranslationY < -4.0f)
        {
            glutDisplayFunc(displayScene2Evening);
            glutPostRedisplay();
        }
        if (sunTranslationY < -6.0f)
        {
            glutDisplayFunc(displayScene2Night);
            glutPostRedisplay();
        }
        if (sunTranslationY < -8.0f)
        {
            glutDisplayFunc(displayScene2Morning);
            glutPostRedisplay();
        }
        if (sunTranslationY < -8.0f)
        {
            sunTranslationY = 4.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateSun, 0);
    }
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

void updateAirplane(int value)
{
    if (moveAirplaneRight)
    {
        airplaneTranslationX += 0.1f;

        glutPostRedisplay();
        glutTimerFunc(16, updateAirplane, 0);
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

void resetAirplanePosition() {
    moveAirplaneRight = false;
    airplaneTranslationX = 0.0f;
}


void resetShipPosition() {
    moveShip = false;
    ship1TranslationX = 0.0f;
    ship2TranslationX = 0.0f;
    ship1TranslationY = 0.0f;
    ship2TranslationY = 0.0f;
}

// Reset function for updateRotateBridge
void resetUpdateRotateBridge() {
    Y = 0.0f;
    X = 0.0f;
    yright = 0.0f;
    xrigth = 0.0f;
    isBridgeRotateStopped = 0;
    rotatingBridge = 0;
    isTrafficLightRed = 0;
}

// Reset function for updateBridgeRotateReverse
void resetUpdateBridgeRotateReverse() {
    Y = 0.0f;
    X = 0.0f;
    yright = 0.0f;
    xrigth = 0.0f;
    isBridgeReversed = 0;
    isTrafficLightRed = 0;
}

// Reset function for carMove, carMove2, and updateCarMove
void resetCarMove() {
    carSpeed = 0.0f;
}

// Reset function for movingShip, updateShipMove
void resetShipMove() {
    shipspeed = 0.0f;
    isShipMoved = 0;
}

// Reset function for prerequisideRotating
void resetPrerequisideRotating() {
    rotateBridge = 0;
}

// Call this function when you want to reset everything
void resetScene() {
    resetPrerequisideRotating();
    resetUpdateRotateBridge();
    resetUpdateBridgeRotateReverse();
    resetCarMove();
    stopCar();
    resetShipMove();
    resetAirplanePosition();
    glutPostRedisplay();
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
    case 'a':
    case 'A':
       moveAirplaneRight = !moveAirplaneRight;
        if (moveAirplaneRight)
            glutTimerFunc(16, updateAirplane, 0);
        break;
    case 'b':
    case 'B':
        resetAirplanePosition();
        glutPostRedisplay();
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
    case 's':
    case 'S':
        moveSunDown = !moveSunDown;
        if (moveSunDown)
            glutTimerFunc(16, updateSun, 0);
            break;
    case 'n':
    case 'N':
        moveSun2Down = !moveSun2Down;
        if (moveSun2Down)
            glutTimerFunc(16, updateSun2, 0);
        break;
    case 'w':
    case 'W':
        startRotation = !startRotation;
        if (startRotation)
            glutTimerFunc(16, updateWindmill, 0);
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
    case 'd':
    case 'D':
        BridgeRotate = !BridgeRotate;
        if (BridgeRotate)
            glutTimerFunc(200,Rotating_Moving_CarMoving,0);
        break;
    case 'z':
    case 'Z':
          resetScene();

        break;
    case 'm':
    case 'M':
        moveSun3Down = !moveSun3Down;
        if (moveSun3Down)
            glutTimerFunc(16, updateSun3, 0);
        break;
    case 'p':
    case 'P':
            dbus2 = !dbus2 ; // Toggle the dbus2 flag
            glutPostRedisplay();
            break;
        default:
            break;
    case '1':
        moveSun3Down = false;
        sun3TranslationY = 0.0f;
          glutDisplayFunc(displayScene1Morning);
        glutPostRedisplay();
        break;
    case '2':
        moveSun2Down = false;
        sun2TranslationY = 0.0f;
          glutDisplayFunc(displayScene2Morning);
        glutPostRedisplay();
        break;
    case '3':
        moveSunDown = false;
        sunTranslationY = 0.0f;
          glutDisplayFunc(displayScene3Morning);
        glutPostRedisplay();
        break;
    }
}

void handleMouseClick(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        isShipMoving = 0;
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

        isShipMoving = 1;
        ship4();
    }
    glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Project");
    glutInitWindowSize(1400, 800);
    glutDisplayFunc(displayScene1Morning);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouseClick);
    glutTimerFunc(16, updateRain, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -40.0, 40.0);
    glutMainLoop();
    return 0;
}
