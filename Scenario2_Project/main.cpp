#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float X = 0.0f;
float Y = 0.0f;
bool moveClouds = false;
float circleRotateAngle=0.0f;
float carSpeed= 0.0f;
float airplanePositionX = 0.0f;
bool moveAirplaneRight = true;
bool isTrafficLightRed = false;
float rotateAngle = 0.0f;
float rotationSpeed = 3.0f;
bool startRotation = false;
bool isRaining = false;
const int numRaindrops = 500;
float raindropX[numRaindrops];
float raindropY[numRaindrops];
float raindropY2[numRaindrops];
float wavePosition = -1.0f;
bool moveSunDown = false;
const float waveAmplitude = 0.1f;
const float waveFrequency = 0.5f;
const float waveWidth = 0.02f;
float xrigth=0.0f;
float yright=0.0f;
float shipspeed=0.0f;
int rotatingBridge=0;
int rotateBridge=0;
int isShipMoved=0;
int isBridgeRotateStopped=0;
int isBridgeReversed=0;
bool moveShip = false;
bool BridgeRotate=false;
bool moveSun2Down = false;

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

void sun2(float X, float Y)
{
    circle(1.5, 43.7 + X, 36.0f + Y, 250, 240, 127);
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


void grass(float translationX, float translationY){
    circle(2.0, 45.0 + translationX, 28.0 + translationY, 35, 69, 35);
    circle(1.5, 42.5 + translationX, 27.5 + translationY, 35, 69, 35);
    circle(1.5, 47.5 + translationX, 27.5 + translationY, 35, 69, 35);
    circle(1.0, 41.0 + translationX, 27.0 + translationY, 35, 69, 35);
    circle(1.0, 49.0 + translationX, 27.0 + translationY, 35, 69, 35);
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


void mountain(float X, float Y) {
    glBegin(GL_TRIANGLES);
    glColor3ub(61, 69, 60);
    glVertex2f(-22.0f + X, 25.0f + Y);
    glColor3ub(97, 112, 95);
    glVertex2f(-29.0f + X, 35.0f + Y);
    glColor3ub(81, 92, 80);
    glVertex2f(-35.0f + X, 25.0f + Y);
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
    glColor3ub(143, 143, 142);
    glVertex2f(-27.0f, -18.0f);
    glVertex2f(-23.0f, -18.0f);
    glVertex2f(-23.0f, -32.0f);
    glVertex2f(-27.0f, -32.0f);
glEnd();
    glBegin(GL_QUADS);
    glColor3ub(106, 108, 109);
    glVertex2f(-27.0f, -18.0f);
    glVertex2f(-30.0f, -18.0f);
    glVertex2f(-30.0f, -31.0f);
    glVertex2f(-27.0f, -32.0f);
glEnd();
    glBegin(GL_QUADS);
    glColor3ub(106, 108, 109);
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
    glColor3ub(143, 143, 142);
    glVertex2f(27.0f, -18.0f);
    glVertex2f(23.0f, -18.0f);
    glVertex2f(23.0f, -32.0f);
    glVertex2f(27.0f, -32.0f);
glEnd();
    glBegin(GL_QUADS);
    glColor3ub(106, 108, 109);
    glVertex2f(27.0f, -18.0f);
    glVertex2f(30.0f, -18.0f);
    glVertex2f(30.0f, -31.0f);
    glVertex2f(27.0f, -32.0f);
glEnd();
    glBegin(GL_QUADS);
    glColor3ub(106, 108, 109);
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


void treeTriangle(float X, float Y) {
    glBegin(GL_POLYGON);
    glColor3ub(71, 50, 41);
    glVertex2f(-48.0f + X, 30.0f + Y);
    glColor3ub(82, 61, 52);
    glVertex2f(-48.0f + X, 31.5f + Y);
    glColor3ub(168, 105, 77);
    glVertex2f(-48.3f + X, 31.5f + Y);
    glColor3ub(191, 117, 84);
    glVertex2f(-48.3f + X, 30.0f + Y);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(7, 242, 142);
    glVertex2f(-47.3f + X, 31.2f + Y);
    glColor3ub(4, 186, 108);
    glVertex2f(-48.1f + X, 32.5f + Y);
    glColor3ub(5, 135, 79);
    glVertex2f(-49.0f + X, 31.2f + Y);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(7, 242, 142);
    glVertex2f(-47.5f + X, 32.0f + Y);
    glColor3ub(4, 186, 108);
    glVertex2f(-48.1f + X, 33.3f + Y);
    glColor3ub(5, 135, 79);
    glVertex2f(-48.8f + X, 32.0f + Y);
    glEnd();
}

void treeCircle(float X, float Y) {
    glBegin(GL_POLYGON);
    glColor3ub(71, 50, 41);
    glVertex2f(-44.0f + X, 30.0f + Y);
    glColor3ub(82, 61, 52);
    glVertex2f(-44.0f + X, 31.5f + Y);
    glColor3ub(168, 105, 77);
    glVertex2f(-44.3f + X, 31.5f + Y);
    glColor3ub(191, 117, 84);
    glVertex2f(-44.3f + X, 30.0f + Y);
    glEnd();
    circle(0.8, -44.15 + X, 32.1 + Y, 5, 247, 146);
    circle(0.8, -44.25 + X, 32.1 + Y, 5, 232, 137);
    circle(0.5, -44.15 + X, 32.9 + Y, 5, 247, 146);
    circle(0.5, -44.25 + X, 32.9 + Y, 5, 232, 137);
}

void airplane() {
    // Nose of the airplane
    glBegin(GL_TRIANGLES);
    glColor3ub(112, 144, 145);
    glVertex2f(22.8f, 38.0f);
    glVertex2f(22.0f, 38.0f);
    glVertex2f(20.5f, 40.0f);
    glEnd();

    // Body of the airplane
    glBegin(GL_POLYGON);
    glColor3ub(112, 144, 145);
    glVertex2f(20.0f, 37.0f);
    glColor3ub(147, 173, 173);
    glVertex2f(20.0f, 38.5f);
    glColor3ub(169, 196, 196);
    glVertex2f(23.0f, 38.5f);
    glColor3ub(186, 212, 212);
    glVertex2f(23.0f, 37.0f);
    glEnd();

    // Right wing
    glBegin(GL_TRIANGLES);
    glColor3ub(169, 196, 196);
    glVertex2f(23.0f, 37.0f);
    glColor3ub(186, 212, 212);
    glVertex2f(23.0f, 38.5f);
    glColor3ub(169, 196, 196);
    glVertex2f(24.7f, 37.0f);
    glEnd();

    // Line detail on the body
    glBegin(GL_LINES);
    glColor3ub(196, 76, 65);
    glVertex2f(20.0f, 37.35f);
    glVertex2f(24.2f, 37.35f);
    glEnd();

    // Left wing
    glBegin(GL_TRIANGLES);
    glColor3ub(112, 144, 145);
    glVertex2f(22.8f, 37.2f);
    glVertex2f(22.3f, 37.7f);
    glVertex2f(20.3f, 35.2f);
    glEnd();

    // Tail
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(23.0f, 37.5f);
    glVertex2f(23.0f, 38.2f);
    glVertex2f(23.7f, 37.5f);
    glEnd();

    // Fin
    glBegin(GL_TRIANGLES);
    glColor3ub(112, 144, 145);
    glVertex2f(20.0f, 37.0f);
    glVertex2f(20.0f, 38.5f);
    glVertex2f(18.8f, 39.5f);
    glEnd();
}

void trafficLight(float X, float Y){
    glBegin(GL_POLYGON);
    glColor3ub(33, 30, 27);
    glVertex2f(-20.0f + X, 0.0f + Y);
    glVertex2f(-21.0f + X, 0.0f + Y);
    glColor3ub(54, 49, 45);
    glVertex2f(-21.0f + X, 10.0f + Y);
    glVertex2f(-20.0f + X, 10.0f + Y);
    glEnd();

    if (isTrafficLightRed) {
        circle(0.3, -20.5 + X, 9.0 + Y, 0, 0, 0);  // Black circle
        circle(0.3, -20.5 + X, 8.0 + Y, 255, 0, 0);  // Red circle
    } else {
        circle(0.3, -20.5 + X, 9.0 + Y, 0, 255, 0);  // Green circle
        circle(0.3, -20.5 + X, 8.0 + Y, 0, 0, 0);  // Black circle
    }
}

void streetLamp(float X, float Y){
    glBegin(GL_POLYGON);
    glColor3ub(33, 30, 27);
    glVertex2f(-20.0f + X, 0.0f + Y);
    glVertex2f(-20.5f + X, 0.0f + Y);
    glColor3ub(54, 49, 45);
    glVertex2f(-20.5f + X, 11.0f + Y);
    glVertex2f(-20.0f + X, 11.0f + Y);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(33, 30, 27);
    glVertex2f(-20.0f + X, 11.0f + Y);
    glVertex2f(-20.5f + X, 11.0f + Y);
    glColor3ub(54, 49, 45);
    glVertex2f(-19.2f + X, 9.0f + Y);
    glVertex2f(-18.7f + X, 9.3f + Y);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(247, 143, 7);
    glVertex2f(-19.2f + X, 9.0f + Y);
    glVertex2f(-20.5f + X, 11.0f + Y);
    glEnd();
}

void pillar(float X, float Y) {
    glLineWidth(8.0f);
    glBegin(GL_LINES);
    glColor3ub(36, 12, 1);
    glVertex2f(-22.0f, 14.0f);
    glVertex2f(22.0f, 14.0f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(36, 12, 1);
    glVertex2f(-22.0f, 13.2f);
    glVertex2f(22.0f, 13.2f);
    glEnd();

    glLineWidth(8.0f);
    glBegin(GL_LINES);
    glColor3ub(36, 12, 1);
    glVertex2f(-22.0f, 24.0f);
    glVertex2f(22.0f, 24.0f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(36, 12, 1);
    glVertex2f(-22.0f, 23.2f);
    glVertex2f(22.0f, 23.2f);
    glEnd();

    glLineWidth(1.0f);

    glBegin(GL_QUADS);
    glColor3ub(143, 143, 142);
    glVertex2f(-26.0f + X, -18.0f + Y);
    glVertex2f(-24.0f + X, -18.0f + Y);
    glVertex2f(-24.0f + X, 15.0f + Y);
    glVertex2f(-26.0f + X, 15.0f + Y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(106, 108, 109);
    glVertex2f(-26.0f + X, -18.0f + Y);
    glVertex2f(-28.0f + X, -18.0f + Y);
    glVertex2f(-28.0f + X, 15.0f + Y);
    glVertex2f(-26.0f + X, 15.0f + Y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(106, 108, 109);
    glVertex2f(-24.0f + X, -18.0f + Y);
    glVertex2f(-22.0f + X, -18.0f + Y);
    glVertex2f(-22.0f + X, 15.0f + Y);
    glVertex2f(-24.0f + X, 15.0f + Y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(195, 201, 205);
    glVertex2f(-25.0f + X, 22.0f + Y);
    glVertex2f(-27.0f + X, 15.0f + Y);
    glVertex2f(-23.0f + X, 15.0f + Y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(175, 177, 169);
    glVertex2f(-27.5f + X, 20.0f + Y);
    glVertex2f(-26.0f + X, 15.0f + Y);
    glVertex2f(-28.0f + X, 15.0f + Y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(175, 177, 169);
    glVertex2f(-22.5f + X, 20.0f + Y);
    glVertex2f(-24.0f + X, 15.0f + Y);
    glVertex2f(-22.0f + X, 15.0f + Y);
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


void cloud(float X, float Y){
    circle(0.6, 45.0 + X, 35.0 + Y, 255,255,255);
    circle(0.6, 45.0 + X, 34.2 + Y, 255,255,255);
    circle(0.6, 43.8 + X, 35.0 + Y, 255,255,255);
    circle(0.6, 43.8 + X, 34.2 + Y, 255,255,255);
    circle(0.6, 43.0 + X, 34.6 + Y, 255,255,255);
    circle(0.6, 46.0 + X, 34.6 + Y, 255,255,255);
    circle(0.6, 44.0 + X, 34.6 + Y, 255,255,255);

}

void cloudsForRain(float X, float Y){
    circle(0.6, 45.0 + X, 35.0 + Y, 82, 74, 70);
    circle(0.6, 45.0 + X, 34.2 + Y, 105, 95, 91);
    circle(0.6, 43.8 + X, 35.0 + Y, 82, 74, 70);
    circle(0.6, 43.8 + X, 34.2 + Y, 105, 95, 91);
    circle(0.6, 43.0 + X, 34.6 + Y, 110, 103, 100);
    circle(0.6, 46.0 + X, 34.6 + Y, 105, 95, 91);
    circle(0.6, 44.0 + X, 34.6 + Y, 110, 103, 100);
}

void windmillBlades(float X, float Y)
{
   glPushMatrix();
    glTranslatef(-14.9f + X, 34.0f + Y, 0.0f); // Translate to the desired rotation point

    if (startRotation)
    {
        glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);
    }

    glTranslatef(14.9f - X, -34.0f - Y, 0.0f); // Translate back to the original position


    glBegin(GL_TRIANGLES);
    glColor3ub(151, 153, 151);
    glVertex2f(-14.9f + X, 34.0f + Y);
    glVertex2f(-17.0f + X, 37.0f + Y);
    glVertex2f(-17.5f + X, 36.2f + Y);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(151, 153, 151);
    glVertex2f(-14.9f + X, 34.0f + Y);
    glVertex2f(-12.0f + X, 37.0f + Y);
    glVertex2f(-12.5f + X, 37.5f + Y);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(151, 153, 151);
    glVertex2f(-14.9f + X, 34.0f + Y);
    glVertex2f(-14.1f + X, 30.0f + Y);
    glVertex2f(-13.7f + X, 30.5f + Y);
    glEnd();
    glPopMatrix();
}

void windmill(float X, float Y){
    glBegin(GL_POLYGON);
    glColor3ub(151, 153, 151);
    glVertex2f(-15.0f + X, 25.0f + Y);
    glVertex2f(-15.0f + X, 34.0f + Y);
    glVertex2f(-14.8f + X, 34.0f + Y);
    glVertex2f(-14.8f + X, 25.0f + Y);
    glEnd();

    circle(0.3, -14.9 + X, 34.0 + Y, 184, 186, 184);
    windmillBlades(0.0f,0.0f);
    windmillBlades(20.0f,0.0f);
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


void resetAirplanePosition() {
    moveAirplaneRight = false;
    X = 0.0f;
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
void updateClouds(int value)
{
    if (moveClouds)
    {
        X += 0.02f;
        if (X > 50.0f)
        {
            X = -50.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateClouds, 0);
    }
}
void updateAirplane(int value) {
    airplanePositionX += 0.1f;

    if (airplanePositionX > 100.0f) {
        airplanePositionX = -50.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateAirplane, 0);
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

void resetShipPosition() {
    moveShip = false;
    X = 0.0f;
    Y = 0.0f;
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

void displayScene2Morning() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (isRaining) {
        skyRain();
    } else {
        skyMorning();
        sun2(0.0f, Y - 0.0f);
    }

    airplane();

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

    cloudsForRain(X, 0.0f);
cloudsForRain(X - 3.0f, 0.5f);
cloudsForRain(X - 30.0f, 2.0f);
cloudsForRain(X - 50.0f, 3.0f);
cloudsForRain(X - 70.0f, 3.0f);
cloudsForRain(X - 90.0f, 1.0f);
cloudsForRain(X - 93.0f, 4.0f);
cloudsForRain(X - 10.0f, 3.5f);
cloudsForRain(X, 2.0f);
cloudsForRain(X - 20.0f, 10.0f);
cloudsForRain(X - 3.0f, -0.5f);
cloudsForRain(X - 30.0f, 12.0f);
cloudsForRain(X - 50.0f, 23.0f);
cloudsForRain(X - 74.0f, 3.0f);
cloudsForRain(X - 80.0f, 1.0f);
cloudsForRain(X - 95.0f, 4.0f);
cloudsForRain(X - 30.0f, 3.5f);
cloudsForRain(X - 5.0f , 2.9f);
cloudsForRain(X - 74.0f, 3.0f);
cloudsForRain(X - 60.0f, 1.0f);
cloudsForRain(X - 45.0f, 4.0f);
cloudsForRain(X - 50.0f, 3.5f);
cloudsForRain(X - 65.0f , 2.9f);
cloudsForRain(X - 4.0f, 3.0f);
cloudsForRain(X - 8.0f, 1.0f);
cloudsForRain(X - 15.0f, 4.0f);
cloudsForRain(X - 7.0f, 3.5f);
cloudsForRain(X - 6.0f , 2.9f);
} else {
cloud(X, 0.0f);
cloud(X - 3.0f, 0.5f);
cloud(X - 30.0f, 2.0f);
cloud(X - 50.0f, 3.0f);
cloud(X - 70.0f, 3.0f);
cloud(X - 90.0f, 1.0f);}

raindrops();

glFlush();
}

void displayScene2Evening() {
glClear(GL_COLOR_BUFFER_BIT);

if (isRaining) {
    skyRain();
} else {
    skyEvening();
     sun2(0.0f, Y - 0.0f);
}

if(isRaining){
    cloudsForRain(X, 0.0f);
    cloudsForRain(X - 3.0f, 0.5f);
    cloudsForRain(X - 30.0f, 2.0f);
    cloudsForRain(X - 50.0f, 3.0f);
    cloudsForRain(X - 70.0f, 3.0f);
    cloudsForRain(X - 90.0f, 1.0f);
    cloudsForRain(X - 93.0f, 4.0f);
    cloudsForRain(X - 10.0f, 3.5f);
    cloudsForRain(X, 2.0f);
    cloudsForRain(X - 20.0f, 10.0f);
    cloudsForRain(X - 3.0f, -0.5f);
    cloudsForRain(X - 30.0f, 12.0f);
    cloudsForRain(X - 50.0f, 23.0f);
    cloudsForRain(X - 74.0f, 3.0f);
    cloudsForRain(X - 80.0f, 1.0f);
    cloudsForRain(X - 95.0f, 4.0f);
    cloudsForRain(X - 30.0f, 3.5f);
    cloudsForRain(X - 5.0f , 2.9f);
    cloudsForRain(X - 74.0f, 3.0f);
    cloudsForRain(X - 60.0f, 1.0f);
    cloudsForRain(X - 45.0f, 4.0f);
    cloudsForRain(X - 50.0f, 3.5f);
    cloudsForRain(X - 65.0f , 2.9f);
    cloudsForRain(X - 4.0f, 3.0f);
    cloudsForRain(X - 8.0f, 1.0f);
    cloudsForRain(X - 15.0f, 4.0f);
    cloudsForRain(X - 7.0f, 3.5f);
    cloudsForRain(X - 6.0f , 2.9f);
} else {
    cloud(X, 0.0f);
    cloud(X - 3.0f, 0.5f);
    cloud(X - 30.0f, 2.0f);
    cloud(X - 50.0f, 3.0f);
    cloud(X - 70.0f, 3.0f);
    cloud(X - 90.0f, 1.0f);
}


    airplane();

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

    airplane();

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
    cloudsForRain(X, 0.0f);
cloudsForRain(X - 3.0f, 0.5f);
cloudsForRain(X - 30.0f, 2.0f);
cloudsForRain(X - 50.0f, 3.0f);
cloudsForRain(X - 70.0f, 3.0f);
cloudsForRain(X - 90.0f, 1.0f);
cloudsForRain(X - 93.0f, 4.0f);
cloudsForRain(X - 10.0f, 3.5f);
cloudsForRain(X, 2.0f);
cloudsForRain(X - 20.0f, 10.0f);
cloudsForRain(X - 3.0f, -0.5f);
cloudsForRain(X - 30.0f, 12.0f);
cloudsForRain(X - 50.0f, 23.0f);
cloudsForRain(X - 74.0f, 3.0f);
cloudsForRain(X - 80.0f, 1.0f);
cloudsForRain(X - 95.0f, 4.0f);
cloudsForRain(X - 30.0f, 3.5f);
cloudsForRain(X - 5.0f , 2.9f);
cloudsForRain(X - 74.0f, 3.0f);
cloudsForRain(X - 60.0f, 1.0f);
cloudsForRain(X - 45.0f, 4.0f);
cloudsForRain(X - 50.0f, 3.5f);
cloudsForRain(X - 65.0f , 2.9f);
cloudsForRain(X - 4.0f, 3.0f);
cloudsForRain(X - 8.0f, 1.0f);
cloudsForRain(X - 15.0f, 4.0f);
cloudsForRain(X - 7.0f, 3.5f);
cloudsForRain(X - 6.0f , 2.9f);
    }
    raindrops();

    glFlush();
}

void updateSun2(int value)
{
    if (moveSun2Down)
    {
        Y -= 0.01f;
         if (Y < -4.0f)
        {
            glutDisplayFunc(displayScene2Evening);
            glutPostRedisplay();
        }
        if (Y < -6.0f)
        {
            glutDisplayFunc(displayScene2Night);
            glutPostRedisplay();
        }
        if (Y < -8.0f)
        {
            glutDisplayFunc(displayScene2Morning);
            glutPostRedisplay();
        }
        if (Y < -8.0f)
        {
            Y = 4.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateSun2, 0);
    }
}

void updateSun(int value)
{
    if (moveSunDown)
    {
        Y -= 0.3f;             ///////////////////////////////sun update1
         if (Y < -18.0f)
        {
            glutDisplayFunc(displayScene2Evening);
            glutPostRedisplay();
        }
        if (Y < -36.0f)
        {
            glutDisplayFunc(displayScene2Night);
            glutPostRedisplay();
        }
        if (Y < -54.0f)
        {
            glutDisplayFunc(displayScene2Morning);
            glutPostRedisplay();
        }
        if (Y < -54.0f)
        {
            Y = 4.0f;
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateSun, 0);
    }
}


void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -40.0, 40.0);
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
        moveSun2Down = !moveSun2Down;
        if (moveSun2Down)
            glutTimerFunc(16, updateSun2, 0);
        break;


    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Scenario 2");
    glutDisplayFunc(displayScene2Morning);
    myInit();
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(0, updateAirplane, 0);
    glutTimerFunc(0, updateWindmill, 0);
    glutMainLoop();
    return 0;
}
