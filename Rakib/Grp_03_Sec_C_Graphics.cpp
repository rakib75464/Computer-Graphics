#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>

//////////////NITU///////////////
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include <thread>
#define PI 3.14159265358979323846

//////////////////NITU////////////


///This part is for only keyboard
bool isNight = false; // Toggle between day and night
float shipX = 0.0f;  ///Initial X position of the ships
float shipY = 0.0f;  ///Initial Y position of the ships
float ship2X = 50.0f;  /// Start from the right
float shipSpeed=2.0f;
bool shipMovingLeft = true; /// Controls direction
bool isWaiting = false; /// Indicates waiting state
bool shipRotated = false; /// Tracks rotation
float cloudOffsetX = 0.0f; // Controls cloud movement
float cloudSpeed = 0.05f;  // Adjust for faster/slower clouds
float resetPosition = 100.0f; // Reset point when clouds move past the screen
float M_PI=3.14159265358979323846;

////////////////////////NITU//////////////////////

//Ruddro
float cartx = 0.0;
float cloudrx = 0.0;
float shipbx = 0.0;
float busTx = 0.0;
float sunty=0.0;
int isNightr = 0;
int isDayr=1;
int isShipMovingr = 1;
int isCarMovingr = 1;
int isBusMovingr=1;
bool isSunMovingr=false;
//Ruddro

//Likhi
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

//LIkhiii


float cloudTranslationX = 0.0f;
bool moveClouds = false;
float initialAirplaneX = -55.0f;
float airplaneTranslationX = 0.0f;
bool moveAirplaneRight = false;
float sunTranslationY = 0.0f;
bool moveSunDown = false;
float rotateAngle = 0.0f;
float rotationSpeed = 3.0f;
bool startRotation = false;
bool carsMoving = false;
bool isNightMode = false;
int currentScene = 1;

float circleRotateAngle=0.0f;
float carSpeed= 0.0f;
bool isRaining = false;
const int numRaindrops = 500;
float raindropX[numRaindrops];
float raindropY[numRaindrops];
float raindropY2[numRaindrops];

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
bool carTimerActive = false;
int isShipMoving = 0; // 1 for moving, 0 for stopped

//Ruddro
void circler(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}




//Ruddro
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


//RUDDRO


void skyr()
{
    glBegin(GL_QUADS);
    if (isNightr)
        glColor3f(0.0f, 0.0f, 0.1f);
    else
        glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(-50, 50);
    glVertex2f(50, 50);
    glVertex2f(50, 7);
    glVertex2f(-50, 7);
    glEnd();
}

 void buildingr() {

    glColor3f(0.1, 0.1, 0);
    glBegin(GL_QUADS);
    glVertex2f(-10, 7);
    glVertex2f(10, 7);
    glVertex2f(10, 30);
    glVertex2f(-10, 30);
    glEnd();

    if (isNightr)
    glColor3f( 1.0, 1.0, 0.0);
    else
    glColor3f( 1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-8, 20);
    glVertex2f(-4, 20);
    glVertex2f(-4, 25);
    glVertex2f(-8, 25);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(4, 20);
    glVertex2f(8, 20);
    glVertex2f(8, 25);
    glVertex2f(4, 25);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2f(-8, 15);
    glVertex2f(-4, 15);
    glVertex2f(-4, 18);
    glVertex2f(-8, 18);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(4, 15);
    glVertex2f(8, 15);
    glVertex2f(8, 18);
    glVertex2f(4, 18);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-8, 10);
    glVertex2f(-4, 10);
    glVertex2f(-4, 13);
    glVertex2f(-8, 13);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(4, 10);
    glVertex2f(8, 10);
    glVertex2f(8, 13);
    glVertex2f(4, 13);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0, 7);
    glVertex2f(0, 30);
    glEnd();
}
    void sunmoonr()
{
    if (isNightr)
    {
        glColor3f(0.9, 0.9, 0.9);
        circler(3.5, 3.5, -35, 30);
        glEnd;
    }
    else
    {
       glPushMatrix();
    glTranslatef(0,sunty, 0);

        glColor3f(1.0, 1.0, 0.0);
        circler(3.5, 3.5, 35, 2);

  glPopMatrix();
if(isSunMovingr)
{


    sunty += 0.01;
    if (sunty > 33)
    {
        sunty = 33;
    }

    glutPostRedisplay();

    }
}
}


void buildingr2()
{

glColor3f(0.1, 0.1, 0);
glBegin(GL_QUADS);
glVertex2f(12, 7);
glVertex2f(25, 7);
glVertex2f(25, 35);
glVertex2f(12, 35);
glEnd();


if (isNightr)
    glColor3f(1.0, 1.0, 0.0);
else
    glColor3f(1.0, 1.0, 1.0);



    glBegin(GL_QUADS);
    glVertex2f(14, 10);
    glVertex2f(18, 10);
    glVertex2f(18, 16);
    glVertex2f(14, 16);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(20, 10);
    glVertex2f(24, 10);
    glVertex2f(24, 16);
    glVertex2f(20, 16);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(14, 18);
    glVertex2f(18, 18);
    glVertex2f(18, 24);
    glVertex2f(14, 24);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(20, 18);
    glVertex2f(24, 18);
    glVertex2f(24, 24);
    glVertex2f(20, 24);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(14, 26);
    glVertex2f(18, 26);
    glVertex2f(18, 32);
    glVertex2f(14, 32);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(20, 26);
    glVertex2f(24, 26);
    glVertex2f(24, 32);
    glVertex2f(20, 32);
    glEnd();

}
void blboardr()
{

    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(33, 7);
    glVertex2f(34, 7);
    glVertex2f(34, 20);
    glVertex2f(33, 20);
    glEnd();

    glColor3f(0.2, 0.2, 0.6);
    glBegin(GL_QUADS);
    glVertex2f(26, 20);
    glVertex2f(40, 20);
    glVertex2f(40, 27);
    glVertex2f(26, 27);
    glEnd();


    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(39.5, 20);
    glVertex2f(40, 20);
    glVertex2f(40, 27);
    glVertex2f(39.5, 27);
    glEnd();

    glColor3f(0.2, 0.2, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex2f(40, 20);
    glVertex2f(45, 23.5);
    glVertex2f(40,27 ) ;
    glEnd();





}

void roadr()
{
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-50, 7);
    glVertex2f(50, 7);
    glVertex2f(50, -10);
    glVertex2f(-50, -10);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(1);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(-50, 1.4);
    glVertex2i(50, 1.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(-50, -1.4);
    glVertex2i(50, -1.4);
    glEnd();
}

void cloudsr()
{
    glPushMatrix();
    glTranslatef(cloudrx, 0, 0);

    if (isNightr)
        glColor3f(0.5, 0.5, 0.5);
    else
        glColor3f(1.0, 1.0, 1.0);

    circler(4, 4, -30, 30);
    circler(5, 5, -26, 30);
    circler(4, 4, -22, 30);

    circler(4, 4, 10, 35);
    circler(5, 5, 14, 35);
    circler(4, 4, 18, 35);

    circler(3, 3, 30, 25);
    circler(4, 4, 33, 25);
    circler(3, 3, 36, 25);

    glPopMatrix();

    cloudrx += 0.01;
    if (cloudrx > 90)
    {
        cloudrx = -90;
    }

    glutPostRedisplay();
}

void carr()
{
    glPushMatrix();
    glTranslatef(cartx, 0, 0);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-10, 4);
    glVertex2f(10, 4);
    glVertex2f(10, -2);
    glVertex2f(-10, -2);
    glEnd();

    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-6, 8);
    glVertex2f(6, 8);
    glVertex2f(8, 4);
    glVertex2f(-8, 4);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-5, 7);
    glVertex2f(-2, 7);
    glVertex2f(-2, 5);
    glVertex2f(-5, 5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(2, 7);
    glVertex2f(5, 7);
    glVertex2f(5, 5);
    glVertex2f(2, 5);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    circler(3, 3, -6, -2.5);
    circler(3, 3, 6, -2.5);

    glColor3f(0.5, 0.5, 0.5);
    circler(1.5, 1.5, -6, -2.5);
    circler(1.5, 1.5, 6, -2.5);

    glPopMatrix();

if (isCarMovingr)
{

    cartx -= 0.04;
    if (cartx < -70)
    {
        cartx = 70;
    }
}
    glutPostRedisplay();
}



    void busr() {
    glPushMatrix();
    glTranslatef(busTx, 0, 0);

     // Bus body
    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_QUADS);

   glVertex2f(15, 1);
    glVertex2f(-15, 1);
     glVertex2f(-15, 10);
    glVertex2f(15, 10);
    glEnd();

    // Bus windows
    glColor3f(1.0, 0, 0);
    glBegin(GL_QUADS);
     glVertex2f(-4, 6);
    glVertex2f(-12, 6);
    glVertex2f(-12, 8);
    glVertex2f(-4, 8);

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(4, 6);
    glVertex2f(12, 6);
    glVertex2f(12, 8);
    glVertex2f(4, 8);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    circler(3, 3, -10, 2);
    circler(3, 3, 10, 2);


    glColor3f(0.5, 0.5, 0.5);
    circler(1.5, 1.5, -10, 2);
    circler(1.5, 1.5, 10, 2);

    glPopMatrix();
if (isBusMovingr)
{


    busTx += 0.02;
    if (busTx >70)
        {
        busTx =- 70;
      }
}
    glutPostRedisplay();
}




void riverr()
{
    glBegin(GL_QUADS);
    if (isNightr)
        glColor3f(0.0, 0.0, 0.3);
    else
        glColor3f(0.0, 0.5, 1.0);
    glVertex2f(-50, -17);
    glVertex2f(50, -17);
    glVertex2f(50, -50);
    glVertex2f(-50, -50);
    glEnd();
}

void grassr()
{

    if (isNightr)
        glColor3f(0.0, 0.3, 0.0);
    else
        glColor3f(0.0, 0.5, 0.0);
         glBegin(GL_QUADS);
    glVertex2f(-50, -10);
    glVertex2f(50, -10);
    glVertex2f(50, -17);
    glVertex2f(-50, -17);
    glEnd();
}


void treer()
{

    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(-30, -10);
    glVertex2f(-28, -10);
    glVertex2f(-28, -5);
    glVertex2f(-30, -5);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-31, -5);
    glVertex2f(-27, -5);
    glVertex2f(-29, 0);
    glEnd();


    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(-5, -10);
    glVertex2f(-3, -10);
    glVertex2f(-3, -5);
    glVertex2f(-5, -5);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-6, -5);
    glVertex2f(-2, -5);
    glVertex2f(-4, 0);
    glEnd();


    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(20, -10);
    glVertex2f(22, -10);
    glVertex2f(22, -5);
    glVertex2f(20, -5);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(19, -5);
    glVertex2f(23, -5);
    glVertex2f(21, 0);
    glEnd();
}

void shiprr()
{
    glPushMatrix();
    glTranslatef(shipbx, 0, 0);
    glColor3f(0.6, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-10, -30);
    glVertex2f(10, -30);
    glVertex2f(15, -25);
    glVertex2f(-15, -25);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-8, -25);
    glVertex2f(8, -25);
    glVertex2f(8, -20);
    glVertex2f(-8, -20);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2, -20);
    glVertex2f(2, -20);
    glVertex2f(2, -15);
    glVertex2f(-2, -15);
    glEnd();

 glPopMatrix();
     if (isShipMovingr)
    {
        shipbx += 0.01;
        if (shipbx > 70)
        {
            shipbx = -70;
        }
    }

    glutPostRedisplay();
}



//RUDDRO
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
    // Trunk (a quadrilateral with gradient colors)
    glBegin(GL_POLYGON);
        if (isNightMode) {
            glColor3ub(35, 25, 20); // Darker version of (71, 50, 41)
        } else {
            glColor3ub(71, 50, 41);
        }
        glVertex2f(-48.0f + translationX, 30.0f + translationY);

        if (isNightMode) {
            glColor3ub(41, 30, 26); // Darker version of (82, 61, 52)
        } else {
            glColor3ub(82, 61, 52);
        }
        glVertex2f(-48.0f + translationX, 31.5f + translationY);

        if (isNightMode) {
            glColor3ub(84, 52, 38); // Darker version of (168, 105, 77)
        } else {
            glColor3ub(168, 105, 77);
        }
        glVertex2f(-48.3f + translationX, 31.5f + translationY);

        if (isNightMode) {
            glColor3ub(95, 58, 42); // Darker version of (191, 117, 84)
        } else {
            glColor3ub(191, 117, 84);
        }
        glVertex2f(-48.3f + translationX, 30.0f + translationY);
    glEnd();

    // Lower triangle (first set of leaves)
    glBegin(GL_TRIANGLES);
        if (isNightMode) {
            glColor3ub(3, 121, 71); // Darker version of (7, 242, 142)
        } else {
            glColor3ub(7, 242, 142);
        }
        glVertex2f(-47.3f + translationX, 31.2f + translationY);

        if (isNightMode) {
            glColor3ub(2, 93, 54); // Darker version of (4, 186, 108)
        } else {
            glColor3ub(4, 186, 108);
        }
        glVertex2f(-48.1f + translationX, 32.5f + translationY);

        if (isNightMode) {
            glColor3ub(2, 67, 39); // Darker version of (5, 135, 79)
        } else {
            glColor3ub(5, 135, 79);
        }
        glVertex2f(-49.0f + translationX, 31.2f + translationY);
    glEnd();

    // Upper triangle (second set of leaves)
    glBegin(GL_TRIANGLES);
        if (isNightMode) {
            glColor3ub(3, 121, 71); // Darker version of (7, 242, 142)
        } else {
            glColor3ub(7, 242, 142);
        }
        glVertex2f(-47.5f + translationX, 32.0f + translationY);

        if (isNightMode) {
            glColor3ub(2, 93, 54); // Darker version of (4, 186, 108)
        } else {
            glColor3ub(4, 186, 108);
        }
        glVertex2f(-48.1f + translationX, 33.3f + translationY);

        if (isNightMode) {
            glColor3ub(2, 67, 39); // Darker version of (5, 135, 79)
        } else {
            glColor3ub(5, 135, 79);
        }
        glVertex2f(-48.8f + translationX, 32.0f + translationY);
    glEnd();
}

void treeCircle(float translationX, float translationY) {
    // Trunk (a quadrilateral with gradient colors)
    glBegin(GL_POLYGON);
        if (isNightMode) {
            glColor3ub(35, 25, 20); // Darker version of (71, 50, 41)
        } else {
            glColor3ub(71, 50, 41);
        }
        glVertex2f(-44.0f + translationX, 30.0f + translationY);

        if (isNightMode) {
            glColor3ub(41, 30, 26); // Darker version of (82, 61, 52)
        } else {
            glColor3ub(82, 61, 52);
        }
        glVertex2f(-44.0f + translationX, 31.5f + translationY);

        if (isNightMode) {
            glColor3ub(84, 52, 38); // Darker version of (168, 105, 77)
        } else {
            glColor3ub(168, 105, 77);
        }
        glVertex2f(-44.3f + translationX, 31.5f + translationY);

        if (isNightMode) {
            glColor3ub(95, 58, 42); // Darker version of (191, 117, 84)
        } else {
            glColor3ub(191, 117, 84);
        }
        glVertex2f(-44.3f + translationX, 30.0f + translationY);
    glEnd();

    // Foliage circles:
    // For the circles, we assume the colors are passed as parameters.
    // Here we choose darker leaf colors if night mode is on.
    if (isNightMode) {
        circle(0.8, -44.15f + translationX, 32.1f + translationY, 2, 123, 73); // Darker version of (5,247,146)
        circle(0.8, -44.25f + translationX, 32.1f + translationY, 2, 116, 68); // Darker version of (5,232,137)
        circle(0.5, -44.15f + translationX, 32.9f + translationY, 2, 123, 73); // Darker version
        circle(0.5, -44.25f + translationX, 32.9f + translationY, 2, 116, 68); // Darker version
    } else {
        circle(0.8, -44.15f + translationX, 32.1f + translationY, 5, 247, 146);
        circle(0.8, -44.25f + translationX, 32.1f + translationY, 5, 232, 137);
        circle(0.5, -44.15f + translationX, 32.9f + translationY, 5, 247, 146);
        circle(0.5, -44.25f + translationX, 32.9f + translationY, 5, 232, 137);
    }
}

void land(){
    // First polygon of land
    glBegin(GL_POLYGON);
        if (isNightMode) {
            glColor3ub(44, 83, 53); // Darker version of (88,166,106)
        } else {
            glColor3ub(88, 166, 106);
        }
        glVertex2f(-45.0f, 25.0f);

        if (isNightMode) {
            glColor3ub(44, 83, 53); // Use same darkened color for uniformity
        } else {
            glColor3ub(88, 166, 106);
        }
        glVertex2f(-45.0f, 27.0f);

        if (isNightMode) {
            glColor3ub(44, 83, 53);
        } else {
            glColor3ub(88, 166, 106);
        }
        glVertex2f(50.0f, 27.0f);

        if (isNightMode) {
            glColor3ub(44, 83, 53);
        } else {
            glColor3ub(88, 166, 106);
        }
        glVertex2f(50.0f, 25.0f);
    glEnd();

    // Second polygon of land (with gradient)
    glBegin(GL_POLYGON);
        if (isNightMode) {
            glColor3ub(44, 83, 53); // Darker version of (88,166,106)
        } else {
            glColor3ub(88, 166, 106);
        }
        glVertex2f(-50.0f, 30.0f);

        if (isNightMode) {
            glColor3ub(1, 125, 29); // Darker version of (2,250,59)
        } else {
            glColor3ub(2, 250, 59);
        }
        glVertex2f(-40.0f, 30.0f);

        if (isNightMode) {
            glColor3ub(50, 79, 57); // Darker version of (101,158,114)
        } else {
            glColor3ub(101, 158, 114);
        }
        glVertex2f(-35.0f, 25.0f);

        if (isNightMode) {
            glColor3ub(22, 58, 31); // Darker version of (45,117,62)
        } else {
            glColor3ub(45, 117, 62);
        }
        glVertex2f(-50.0f, 25.0f);
    glEnd();
}

void river(){
    glBegin(GL_POLYGON);
    if (isNightMode) {
        // Darker colors for night mode
        glColor3ub(10, 70, 90);    // Darker shade for first vertex
        glVertex2f(-50.0f, 25.0f);
        glColor3ub(20, 80, 100);   // Darker shade for second vertex
        glVertex2f(50.0f, 25.0f);
        glColor3ub(50, 100, 120);  // Darker shade for third vertex
        glVertex2f(50.0f, -40.0f);
        glColor3ub(70, 110, 130);  // Darker shade for fourth vertex
        glVertex2f(-50.0f, -40.0f);
    } else {
        // Original colors for day mode
        glColor3ub(17, 109, 130);
        glVertex2f(-50.0f, 25.0f);
        glColor3ub(38, 136, 158);
        glVertex2f(50.0f, 25.0f);
        glColor3ub(101, 181, 199);
        glVertex2f(50.0f, -40.0f);
        glColor3ub(129, 198, 214);
        glVertex2f(-50.0f, -40.0f);
    }
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

// Sample Mountain Function
void mountain(float translationX, float translationY) {
    glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(50, 50, 50);   // Darker mountain color for night
    } else {
        glColor3ub(120, 120, 120); // Lighter mountain color for day
    }
    glVertex2f(-22.0f + translationX, 25.0f + translationY);
    glVertex2f(-29.0f + translationX, 35.0f + translationY);
    glVertex2f(-35.0f + translationX, 25.0f + translationY);
    glEnd();
}

void windmillBlades(float translationX, float translationY)
{
    glPushMatrix();
    // Translate to the rotation point.
    glTranslatef(-14.9f + translationX, 34.0f + translationY, 0.0f);

    if (startRotation)
    {
        glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);
    }

    // Translate back.
    glTranslatef(14.9f - translationX, -34.0f - translationY, 0.0f);

    // Choose color based on mode.
    GLuint bladeR, bladeG, bladeB;
    if (isNightMode) {
        bladeR = 80; bladeG = 80; bladeB = 80; // Darker shade
    } else {
        bladeR = 151; bladeG = 153; bladeB = 151;
    }

    glBegin(GL_TRIANGLES);
      glColor3ub(bladeR, bladeG, bladeB);
      glVertex2f(-14.9f + translationX, 34.0f + translationY);
      glVertex2f(-17.0f + translationX, 37.0f + translationY);
      glVertex2f(-17.5f + translationX, 36.2f + translationY);
    glEnd();

    glBegin(GL_TRIANGLES);
      glColor3ub(bladeR, bladeG, bladeB);
      glVertex2f(-14.9f + translationX, 34.0f + translationY);
      glVertex2f(-12.0f + translationX, 37.0f + translationY);
      glVertex2f(-12.5f + translationX, 37.5f + translationY);
    glEnd();

    glBegin(GL_TRIANGLES);
      glColor3ub(bladeR, bladeG, bladeB);
      glVertex2f(-14.9f + translationX, 34.0f + translationY);
      glVertex2f(-14.1f + translationX, 30.0f + translationY);
      glVertex2f(-13.7f + translationX, 30.5f + translationY);
    glEnd();

    glPopMatrix();
}

void windmill(float translationX, float translationY){
    GLuint millR, millG, millB;
    if (isNightMode) {
        millR = 80; millG = 80; millB = 80;
    } else {
        millR = 151; millG = 153; millB = 151;
    }

    // Windmill stand
    glBegin(GL_POLYGON);
      glColor3ub(millR, millG, millB);
      glVertex2f(-15.0f + translationX, 25.0f + translationY);
      glVertex2f(-15.0f + translationX, 34.0f + translationY);
      glVertex2f(-14.8f + translationX, 34.0f + translationY);
      glVertex2f(-14.8f + translationX, 25.0f + translationY);
    glEnd();

    // Windmill center (circle)
    if (isNightMode) {
        circle(0.3, -14.9f + translationX, 34.0f + translationY, 120, 120, 120);
    } else {
        circle(0.3, -14.9f + translationX, 34.0f + translationY, 184, 186, 184);
    }

    // Draw the blades. They use the same translation values as before.
    windmillBlades(0.0f, 0.0f);
    windmillBlades(20.0f, 0.0f);
}

void grass(float translationX, float translationY){
    // For grass, we use a darker green at night.
    if (isNightMode) {
        circle(2.0, 45.0f + translationX, 28.0f + translationY, 20, 40, 20);
        circle(1.5, 42.5f + translationX, 27.5f + translationY, 20, 40, 20);
        circle(1.5, 47.5f + translationX, 27.5f + translationY, 20, 40, 20);
        circle(1.0, 41.0f + translationX, 27.0f + translationY, 20, 40, 20);
        circle(1.0, 49.0f + translationX, 27.0f + translationY, 20, 40, 20);
    } else {
        circle(2.0, 45.0f + translationX, 28.0f + translationY, 35, 69, 35);
        circle(1.5, 42.5f + translationX, 27.5f + translationY, 35, 69, 35);
        circle(1.5, 47.5f + translationX, 27.5f + translationY, 35, 69, 35);
        circle(1.0, 41.0f + translationX, 27.0f + translationY, 35, 69, 35);
        circle(1.0, 49.0f + translationX, 27.0f + translationY, 35, 69, 35);
    }
}

void cloud(float translationX, float translationY){
    // For clouds, we use a slightly darker (grayer) white in night mode.
    if (isNightMode) {
        circle(0.6, 45.0f + translationX, 35.0f + translationY, 200, 200, 200);
        circle(0.6, 45.0f + translationX, 34.2f + translationY, 200, 200, 200);
        circle(0.6, 43.8f + translationX, 35.0f + translationY, 200, 200, 200);
        circle(0.6, 43.8f + translationX, 34.2f + translationY, 200, 200, 200);
        circle(0.6, 43.0f + translationX, 34.6f + translationY, 200, 200, 200);
        circle(0.6, 46.0f + translationX, 34.6f + translationY, 200, 200, 200);
        circle(0.6, 44.0f + translationX, 34.6f + translationY, 200, 200, 200);
    } else {
        circle(0.6, 45.0f + translationX, 35.0f + translationY, 255, 255, 255);
        circle(0.6, 45.0f + translationX, 34.2f + translationY, 255, 255, 255);
        circle(0.6, 43.8f + translationX, 35.0f + translationY, 255, 255, 255);
        circle(0.6, 43.8f + translationX, 34.2f + translationY, 255, 255, 255);
        circle(0.6, 43.0f + translationX, 34.6f + translationY, 255, 255, 255);
        circle(0.6, 46.0f + translationX, 34.6f + translationY, 255, 255, 255);
        circle(0.6, 44.0f + translationX, 34.6f + translationY, 255, 255, 255);
    }
}

void sun(float translationX, float translationY)
{
    circle(1.5, 43.7 + translationX, 36.0f + translationY, 252, 252, 3);
}

void airplane(float translationX, float translationY) {
    // First triangle (nose or top detail)
    glBegin(GL_TRIANGLES);
        if (isNightMode)
            glColor3ub(70, 90, 90);       // Darker version of (112,144,145)
        else
            glColor3ub(112, 144, 145);
        glVertex2f(22.8f + translationX, 38.0f + translationY);
        glVertex2f(22.0f + translationX, 38.0f + translationY);
        glVertex2f(20.5f + translationX, 40.0f + translationY);
    glEnd();

    // Main body (Polygon with gradient colors)
    glBegin(GL_POLYGON);
        // Vertex 1
        if (isNightMode)
            glColor3ub(70, 90, 90);        // Darker version of (112,144,145)
        else
            glColor3ub(112, 144, 145);
        glVertex2f(20.0f + translationX, 37.0f + translationY);

        // Vertex 2
        if (isNightMode)
            glColor3ub(110, 130, 130);      // Darker version of (147,173,173)
        else
            glColor3ub(147, 173, 173);
        glVertex2f(20.0f + translationX, 38.5f + translationY);

        // Vertex 3
        if (isNightMode)
            glColor3ub(130, 160, 160);      // Darker version of (169,196,196)
        else
            glColor3ub(169, 196, 196);
        glVertex2f(23.0f + translationX, 38.5f + translationY);

        // Vertex 4
        if (isNightMode)
            glColor3ub(140, 170, 170);      // Darker version of (186,212,212)
        else
            glColor3ub(186, 212, 212);
        glVertex2f(23.0f + translationX, 37.0f + translationY);
    glEnd();

    // Right wing (Triangle)
    glBegin(GL_TRIANGLES);
        if (isNightMode)
            glColor3ub(130, 160, 160);      // Darker version of (169,196,196)
        else
            glColor3ub(169, 196, 196);
        glVertex2f(23.0f + translationX, 37.0f + translationY);

        if (isNightMode)
            glColor3ub(140, 170, 170);      // Darker version of (186,212,212)
        else
            glColor3ub(186, 212, 212);
        glVertex2f(23.0f + translationX, 38.5f + translationY);

        if (isNightMode)
            glColor3ub(130, 160, 160);
        else
            glColor3ub(169, 196, 196);
        glVertex2f(24.7f + translationX, 37.0f + translationY);
    glEnd();

    // Horizontal line detail across the fuselage
    glBegin(GL_LINES);
        if (isNightMode)
            glColor3ub(140, 50, 45);       // Darker version of (196,76,65)
        else
            glColor3ub(196, 76, 65);
        glVertex2f(20.0f + translationX, 37.35f + translationY);
        glVertex2f(24.2f + translationX, 37.35f + translationY);
    glEnd();

    // Left wing or lower detail (Triangle)
    glBegin(GL_TRIANGLES);
        if (isNightMode)
            glColor3ub(70, 90, 90);       // Darker version of (112,144,145)
        else
            glColor3ub(112, 144, 145);
        glVertex2f(22.8f + translationX, 37.2f + translationY);
        glVertex2f(22.3f + translationX, 37.7f + translationY);
        glVertex2f(20.3f + translationX, 35.2f + translationY);
    glEnd();

    // Small triangle detail (originally white, becomes yellow at night)
    glBegin(GL_TRIANGLES);
        if (isNightMode)
            glColor3ub(255, 255, 0);       // Yellow instead of white
        else
            glColor3ub(255, 255, 255);
        glVertex2f(23.0f + translationX, 37.5f + translationY);
        glVertex2f(23.0f + translationX, 38.2f + translationY);
        glVertex2f(23.7f + translationX, 37.5f + translationY);
    glEnd();

    // Left wing (Triangle)
    glBegin(GL_TRIANGLES);
        if (isNightMode)
            glColor3ub(70, 90, 90);
        else
            glColor3ub(112, 144, 145);
        glVertex2f(20.0f + translationX, 37.0f + translationY);
        glVertex2f(20.0f + translationX, 38.5f + translationY);
        glVertex2f(18.8f + translationX, 39.5f + translationY);
    glEnd();
}

void ship(float translationX, float translationY) {
    // Hull, main body (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(150, 120, 80);  // Darker version of (204, 157, 110)
      } else {
          glColor3ub(204, 157, 110);
      }
      glVertex2f(-13.5f + translationX, 21.0f + translationY);
      glVertex2f(-12.0f + translationX, 10.0f + translationY);
      glVertex2f(-6.3f + translationX, 11.5f + translationY);
      glVertex2f(-9.0f + translationX, 21.0f + translationY);
    glEnd();

    // Lower hull (Triangle)
    glBegin(GL_TRIANGLES);
      if (isNightMode) {
          glColor3ub(150, 120, 80);
      } else {
          glColor3ub(204, 157, 110);
      }
      glVertex2f(-12.0f + translationX, 10.0f + translationY);
      glVertex2f(-6.3f + translationX, 11.5f + translationY);
      glVertex2f(-7.0f + translationX, 7.0f + translationY);
    glEnd();

    // Upper deck or cabin (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(180, 140, 100);  // Darker version of (232, 181, 130)
      } else {
          glColor3ub(232, 181, 130);
      }
      glVertex2f(-12.8f + translationX, 21.7f + translationY);
      glVertex2f(-12.3f + translationX, 14.0f + translationY);
      glVertex2f(-7.0f + translationX, 15.0f + translationY);
      glVertex2f(-9.0f + translationX, 21.7f + translationY);
    glEnd();

    // Superstructure (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(180, 140, 100);
      } else {
          glColor3ub(232, 181, 130);
      }
      glVertex2f(-12.0f + translationX, 23.0f + translationY);
      glVertex2f(-9.0f + translationX, 23.5f + translationY);
      glVertex2f(-8.0f + translationX, 18.5f + translationY);
      glVertex2f(-11.0f + translationX, 18.0f + translationY);
    glEnd();

    // Detail on the superstructure (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(150, 120, 80);  // Darker version of (204, 157, 110)
      } else {
          glColor3ub(204, 157, 110);
      }
      glVertex2f(-8.0f + translationX, 18.5f + translationY);
      glVertex2f(-11.0f + translationX, 18.0f + translationY);
      glVertex2f(-11.0f + translationX, 17.2f + translationY);
      glVertex2f(-8.0f + translationX, 17.7f + translationY);
    glEnd();

    // Metal panel detail (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(160, 160, 160);  // Darker version of (219, 218, 217)
      } else {
          glColor3ub(219, 218, 217);
      }
      glVertex2f(-11.8f + translationX, 22.4f + translationY);
      glVertex2f(-12.0f + translationX, 20.0f + translationY);
      glVertex2f(-11.5f + translationX, 15.5f + translationY);
      glVertex2f(-10.9f + translationX, 18.2f + translationY);
    glEnd();

    // Windows (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(200, 200, 200);  // Dimmed white instead of pure white
      } else {
          glColor3ub(255, 255, 255);
      }
      glVertex2f(-11.2f + translationX, 17.2f + translationY);
      glVertex2f(-11.5f + translationX, 15.5f + translationY);
      glVertex2f(-7.8f + translationX, 16.0f + translationY);
      glVertex2f(-8.0f + translationX, 17.7f + translationY);
    glEnd();

    // Window frames or accents (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(255, 215, 0);  // Darker version of (30, 42, 87)
      } else {
          glColor3ub(30, 42, 87);
      }
      glVertex2f(-8.0f + translationX, 17.7f + translationY);
      glVertex2f(-11.0f + translationX, 17.2f + translationY);
      glVertex2f(-10.9f + translationX, 16.2f + translationY);
      glVertex2f(-8.3f + translationX, 16.6f + translationY);
    glEnd();

    // Additional white detail (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(200, 200, 200);
      } else {
          glColor3ub(255, 255, 255);
      }
      glVertex2f(-6.9f + translationX, 13.4f + translationY);
      glVertex2f(-6.5f + translationX, 12.0f + translationY);
      glVertex2f(-12.0f + translationX, 11.0f + translationY);
      glVertex2f(-12.0f + translationX, 12.3f + translationY);
    glEnd();

    // More metal panel detail (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(160, 160, 160);
      } else {
          glColor3ub(219, 218, 217);
      }
      glVertex2f(-7.5f + translationX, 14.8f + translationY);
      glVertex2f(-7.0f + translationX, 13.4f + translationY);
      glVertex2f(-12.0f + translationX, 12.3f + translationY);
      glVertex2f(-11.8f + translationX, 13.9f + translationY);
    glEnd();

    // Additional window accent (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(255,215,0);
      } else {
          glColor3ub(30, 42, 87);
      }
      glVertex2f(-7.4f + translationX, 14.7f + translationY);
      glVertex2f(-7.2f + translationX, 13.5f + translationY);
      glVertex2f(-11.7f + translationX, 12.5f + translationY);
      glVertex2f(-11.7f + translationX, 13.8f + translationY);
    glEnd();

    // Front lower detail, hull extension (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(100, 70, 40);  // Darker version of (138, 102, 66)
      } else {
          glColor3ub(138, 102, 66);
      }
      glVertex2f(-13.5f + translationX, 21.0f + translationY);
      glVertex2f(-12.0f + translationX, 10.0f + translationY);
      glVertex2f(-12.5f + translationX, 9.0f + translationY);
      glVertex2f(-13.2f + translationX, 12.5f + translationY);
    glEnd();

    // Mid-hull extension (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(100, 70, 40);
      } else {
          glColor3ub(138, 102, 66);
      }
      glVertex2f(-12.0f + translationX, 10.0f + translationY);
      glVertex2f(-12.5f + translationX, 9.0f + translationY);
      glVertex2f(-6.8f + translationX, 5.9f + translationY);
      glVertex2f(-7.0f + translationX, 7.0f + translationY);
    glEnd();

    // Front bow extension (Polygon)
    glBegin(GL_POLYGON);
      if (isNightMode) {
          glColor3ub(100, 70, 40);
      } else {
          glColor3ub(138, 102, 66);
      }
      glVertex2f(-6.8f + translationX, 5.9f + translationY);
      glVertex2f(-7.0f + translationX, 7.0f + translationY);
      glVertex2f(-6.4f + translationX, 11.0f + translationY);
      glVertex2f(-6.3f + translationX, 11.5f + translationY);
    glEnd();

    // Decorative white lines (Line segments)
    glBegin(GL_LINES);
      if (isNightMode) {
          glColor3ub(200, 200, 200);
      } else {
          glColor3ub(255, 255, 255);
      }
      glVertex2f(-7.0f + translationX, 7.0f + translationY);
      glVertex2f(-7.2f + translationX, 7.8f + translationY);
    glEnd();

    glBegin(GL_LINES);
      if (isNightMode) {
          glColor3ub(200, 200, 200);
      } else {
          glColor3ub(255, 255, 255);
      }
      glVertex2f(-12.0f + translationX, 10.0f + translationY);
      glVertex2f(-12.0f + translationX, 10.8f + translationY);
    glEnd();

    glBegin(GL_LINES);
      if (isNightMode) {
          glColor3ub(200, 200, 200);
      } else {
          glColor3ub(255, 255, 255);
      }
      glVertex2f(-7.2f + translationX, 7.8f + translationY);
      glVertex2f(-12.0f + translationX, 10.8f + translationY);
    glEnd();

    glBegin(GL_LINES);
      if (isNightMode) {
          glColor3ub(200, 200, 200);
      } else {
          glColor3ub(255, 255, 255);
      }
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

void car(float translationX, float translationY) {
    // Main body
     glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(81, 36, 52);  // Darker body color for night
    } else {
        glColor3ub(163, 72, 104);
    }
    glVertex2f(19.0f + translationX, 1.5f + translationY);
    glVertex2f(17.0f + translationX, 1.2f + translationY);
    glVertex2f(17.0f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -2.0f + translationY);
    glVertex2f(27.25f + translationX, 1.2f + translationY);
    glVertex2f(26.0f + translationX, 1.5f + translationY);
    glEnd();

    // Upper section (e.g., windshield/roof)
    glBegin(GL_POLYGON);
    if (isNightMode) {
        // Change window color to yellow in night mode (light turned on)
        glColor3ub(255, 255, 102);  // A warm yellow
    } else {
        glColor3ub(156, 224, 247);
    }

    glVertex2f(20.0f + translationX, 3.0f + translationY);
    glVertex2f(19.0f + translationX, 1.5f + translationY);
    glVertex2f(19.7f + translationX, -1.9f + translationY);
    glVertex2f(26.8f + translationX, -1.4f + translationY);
    glVertex2f(26.0f + translationX, 1.5f + translationY);
    glEnd();

    // First diagonal line detail
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(81, 32, 49);  // Darker version of (163, 64, 99)
    } else {
        glColor3ub(163, 64, 99);
    }

    glVertex2f(21.0f + translationX, 0.0f + translationY);
    glVertex2f(19.7f + translationX, -2.0f + translationY);
    glEnd();

    // Vertical line detail 1
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(81, 32, 49);
    } else {
        glColor3ub(163, 64, 99);
    }
    glVertex2f(23.0f + translationX, 0.0f + translationY);
    glVertex2f(23.0f + translationX, -2.0f + translationY);
    glEnd();

    // Vertical line detail 2
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(81, 32, 49);
    } else {
        glColor3ub(163, 64, 99);
    }

    glVertex2f(25.7f + translationX, 0.0f + translationY);
    glVertex2f(25.7f + translationX, -2.0f + translationY);
    glEnd();

    // Second diagonal line detail
    glLineWidth(5.0f);
   if (isNightMode) {
        glColor3ub(81, 32, 49);
    } else {
        glColor3ub(163, 64, 99);
    }

    glVertex2f(25.9f + translationX, 0.0f + translationY);
    glVertex2f(26.8f + translationX, -1.8f + translationY);
    glEnd();

    // Front window (or detail polygon) – becomes yellow in night mode
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
   if (isNightMode) {
        glColor3ub(81, 36, 52);
    } else {
        glColor3ub(163, 72, 104);
    }

    glVertex2f(21.0f + translationX, 0.0f + translationY);
    glVertex2f(26.0f + translationX, 0.0f + translationY);
    glVertex2f(25.0f + translationX, 3.0f + translationY);
    glVertex2f(20.0f + translationX, 3.0f + translationY);
    glEnd();

    // Base of the car
    glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(81, 32, 49);  // Darker version of (163, 64, 99)
    } else {
        glColor3ub(163, 64, 99);
    }

    glVertex2f(17.0f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -4.0f + translationY);
    glVertex2f(17.5f + translationX, -4.0f + translationY);
    glEnd();

    // Wheels – remain unchanged (black rims with white highlights)
    circle(1.0, 20.0f + translationX, -4.0f + translationY, 0, 0, 0);
    circle(1.0, 25.3f + translationX, -4.0f + translationY, 0, 0, 0);
    circleL(0.5, 20.0f + translationX, -4.0f + translationY, 255, 255, 255, circleRotateAngle);
    circleL(0.5, 25.3f + translationX, -4.0f + translationY, 255, 255, 255, circleRotateAngle);
    circle(0.3, 20.0f + translationX, -4.0f + translationY, 255, 255, 255);
    circle(0.3, 25.3f + translationX, -4.0f + translationY, 255, 255, 255);
}

void car2(float translationX, float translationY) {
    // Main body
    glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(19, 89, 70);   // Darker green for night
    } else {
        glColor3ub(39, 179, 141);
    }

    glVertex2f(19.0f + translationX, 1.5f + translationY);
    glVertex2f(17.0f + translationX, 1.2f + translationY);
    glVertex2f(17.0f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -2.0f + translationY);
    glVertex2f(27.25f + translationX, 1.2f + translationY);
    glVertex2f(26.0f + translationX, 1.5f + translationY);
    glEnd();

    // Upper section (windshield/roof)
    glBegin(GL_POLYGON);
    if (isNightMode) {
        // Change window color to yellow in night mode (light turned on)
        glColor3ub(255, 255, 102);  // A warm yellow
    } else {
        glColor3ub(156, 224, 247);
    }

    glVertex2f(20.0f + translationX, 3.0f + translationY);
    glVertex2f(19.0f + translationX, 1.5f + translationY);
    glVertex2f(19.7f + translationX, -1.9f + translationY);
    glVertex2f(26.8f + translationX, -1.4f + translationY);
    glVertex2f(26.0f + translationX, 1.5f + translationY);
    glEnd();

    // First diagonal line detail
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(19, 89, 70);  // Darker, matching the main body for night
    } else {
        glColor3ub(39, 179, 141);
    }

    glVertex2f(21.0f + translationX, 0.0f + translationY);
    glVertex2f(19.7f + translationX, -2.0f + translationY);
    glEnd();

    // Vertical line detail 1
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(19, 89, 70);
    } else {
        glColor3ub(39, 179, 141);
    }
    glVertex2f(23.0f + translationX, 0.0f + translationY);
    glVertex2f(23.0f + translationX, -2.0f + translationY);
    glEnd();

    // Vertical line detail 2
    glLineWidth(4.0f);
    glBegin(GL_LINES);
     if (isNightMode) {
        glColor3ub(19, 89, 70);
    } else {
        glColor3ub(39, 179, 141);
    }

    glVertex2f(25.7f + translationX, 0.0f + translationY);
    glVertex2f(25.7f + translationX, -2.0f + translationY);
    glEnd();

    // Second diagonal line detail
    glLineWidth(5.0f);
    glBegin(GL_LINES);
     if (isNightMode) {
        glColor3ub(19, 89, 70);
    } else {
        glColor3ub(39, 179, 141);
    }

    glVertex2f(25.9f + translationX, 0.0f + translationY);
    glVertex2f(26.8f + translationX, -1.8f + translationY);
    glEnd();

    // Front window (or detail polygon) – becomes yellow in night mode
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
     if (isNightMode) {
        glColor3ub(19, 89, 70);
    } else {
        glColor3ub(39, 179, 141);
    }
    glVertex2f(21.0f + translationX, 0.0f + translationY);
    glVertex2f(26.0f + translationX, 0.0f + translationY);
    glVertex2f(25.0f + translationX, 3.0f + translationY);
    glVertex2f(20.0f + translationX, 3.0f + translationY);
    glEnd();

    // Base of the car
    glBegin(GL_POLYGON);
     if (isNightMode) {
        // Darker version of (113, 201, 177)
        glColor3ub(56, 100, 88);
    } else {
        glColor3ub(113, 201, 177);
    }
    glVertex2f(17.0f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -2.0f + translationY);
    glVertex2f(27.5f + translationX, -4.0f + translationY);
    glVertex2f(17.5f + translationX, -4.0f + translationY);
    glEnd();

    // Wheels – remain unchanged
    circle(1.0, 20.0f + translationX, -4.0f + translationY, 0, 0, 0);
    circle(1.0, 25.3f + translationX, -4.0f + translationY, 0, 0, 0);
    circleL(0.5, 20.0f + translationX, -4.0f + translationY, 255, 255, 255, circleRotateAngle);
    circleL(0.5, 25.3f + translationX, -4.0f + translationY, 255, 255, 255, circleRotateAngle);
    circle(0.3, 20.0f + translationX, -4.0f + translationY, 255, 255, 255);
    circle(0.3, 25.3f + translationX, -4.0f + translationY, 255, 255, 255);
}

void mirrorCar(float translationX, float translationY) {
    // Main body of the car
    glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(81, 36, 52);  // Darker body color for night
    } else {
        glColor3ub(163, 72, 104);
    }
    glVertex2f(-19.0f + translationX, 1.5f + translationY);
    glVertex2f(-17.0f + translationX, 1.2f + translationY);
    glVertex2f(-17.0f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -2.0f + translationY);
    glVertex2f(-27.25f + translationX, 1.2f + translationY);
    glVertex2f(-26.0f + translationX, 1.5f + translationY);
    glEnd();

    // Upper section (e.g., windshield/roof)
    glBegin(GL_POLYGON);
    if (isNightMode) {
        // Change window color to yellow in night mode (light turned on)
        glColor3ub(255, 255, 102);  // A warm yellow
    } else {
        glColor3ub(156, 224, 247);
    }
    glVertex2f(-20.0f + translationX, 3.0f + translationY);
    glVertex2f(-19.0f + translationX, 1.5f + translationY);
    glVertex2f(-19.7f + translationX, -1.9f + translationY);
    glVertex2f(-26.8f + translationX, -1.4f + translationY);
    glVertex2f(-26.0f + translationX, 1.5f + translationY);
    glEnd();

    // Diagonal line detail 1
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(81, 32, 49);  // Darker version of (163, 64, 99)
    } else {
        glColor3ub(163, 64, 99);
    }
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glVertex2f(-19.7f + translationX, -2.0f + translationY);
    glEnd();

    // Vertical line detail 1
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(81, 32, 49);
    } else {
        glColor3ub(163, 64, 99);
    }
    glVertex2f(-23.0f + translationX, 0.0f + translationY);
    glVertex2f(-23.0f + translationX, -2.0f + translationY);
    glEnd();

    // Vertical line detail 2
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(81, 32, 49);
    } else {
        glColor3ub(163, 64, 99);
    }
    glVertex2f(-25.7f + translationX, 0.0f + translationY);
    glVertex2f(-25.7f + translationX, -2.0f + translationY);
    glEnd();

    // Diagonal line detail 2
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(81, 32, 49);
    } else {
        glColor3ub(163, 64, 99);
    }
    glVertex2f(-25.9f + translationX, 0.0f + translationY);
    glVertex2f(-26.8f + translationX, -1.8f + translationY);
    glEnd();

    // Front detail polygon (e.g., front window) remains the same
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(81, 36, 52);
    } else {
        glColor3ub(163, 72, 104);
    }
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glVertex2f(-26.0f + translationX, 0.0f + translationY);
    glVertex2f(-25.0f + translationX, 3.0f + translationY);
    glVertex2f(-20.0f + translationX, 3.0f + translationY);
    glEnd();

    // Base of the car
    glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(81, 32, 49);  // Darker version of (163, 64, 99)
    } else {
        glColor3ub(163, 64, 99);
    }
    glVertex2f(-17.0f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -4.0f + translationY);
    glVertex2f(-17.5f + translationX, -4.0f + translationY);
    glEnd();

    // Wheels (remain unchanged)
    circle(1.0, -20.0f + translationX, -4.0f + translationY, 0, 0, 0);
    circle(1.0, -25.3f + translationX, -4.0f + translationY, 0, 0, 0);
    circleL(0.5, -20.0f + translationX, -4.0f + translationY, 255, 255, 255, circleRotateAngle);
    circleL(0.5, -25.3f + translationX, -4.0f + translationY, 255, 255, 255, circleRotateAngle);
    circle(0.3, -20.0f + translationX, -4.0f + translationY, 255, 255, 255);
    circle(0.3, -25.3f + translationX, -4.0f + translationY, 255, 255, 255);
}


void mirrorCar2(float translationX, float translationY) {
    // Main body of the car
    glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(19, 89, 70);   // Darker green for night
    } else {
        glColor3ub(39, 179, 141);
    }
    glVertex2f(-19.0f + translationX, 1.5f + translationY);
    glVertex2f(-17.0f + translationX, 1.2f + translationY);
    glVertex2f(-17.0f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -2.0f + translationY);
    glVertex2f(-27.25f + translationX, 1.2f + translationY);
    glVertex2f(-26.0f + translationX, 1.5f + translationY);
    glEnd();

    // Upper section (e.g., windshield/roof)
    glBegin(GL_POLYGON);
    if (isNightMode) {
        // Change window color to yellow in night mode (light turned on)
        glColor3ub(255, 255, 102);  // A warm yellow
    } else {
        glColor3ub(156, 224, 247);
    }
    glVertex2f(-20.0f + translationX, 3.0f + translationY);
    glVertex2f(-19.0f + translationX, 1.5f + translationY);
    glVertex2f(-19.7f + translationX, -1.9f + translationY);
    glVertex2f(-26.8f + translationX, -1.4f + translationY);
    glVertex2f(-26.0f + translationX, 1.5f + translationY);
    glEnd();

    // Diagonal line detail 1
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(19, 89, 70);  // Darker, matching the main body for night
    } else {
        glColor3ub(39, 179, 141);
    }
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glVertex2f(-19.7f + translationX, -2.0f + translationY);
    glEnd();

    // Vertical line detail 1
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(19, 89, 70);
    } else {
        glColor3ub(39, 179, 141);
    }
    glVertex2f(-23.0f + translationX, 0.0f + translationY);
    glVertex2f(-23.0f + translationX, -2.0f + translationY);
    glEnd();

    // Vertical line detail 2
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(19, 89, 70);
    } else {
        glColor3ub(39, 179, 141);
    }
    glVertex2f(-25.7f + translationX, 0.0f + translationY);
    glVertex2f(-25.7f + translationX, -2.0f + translationY);
    glEnd();

    // Diagonal line detail 2
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    if (isNightMode) {
        glColor3ub(19, 89, 70);
    } else {
        glColor3ub(39, 179, 141);
    }
    glVertex2f(-25.9f + translationX, 0.0f + translationY);
    glVertex2f(-26.8f + translationX, -1.8f + translationY);
    glEnd();

    // Front detail polygon (e.g., front window) remains the same
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    if (isNightMode) {
        glColor3ub(19, 89, 70);
    } else {
        glColor3ub(39, 179, 141);
    }
    glVertex2f(-21.0f + translationX, 0.0f + translationY);
    glVertex2f(-26.0f + translationX, 0.0f + translationY);
    glVertex2f(-25.0f + translationX, 3.0f + translationY);
    glVertex2f(-20.0f + translationX, 3.0f + translationY);
    glEnd();

    // Base of the car
    glBegin(GL_POLYGON);
    if (isNightMode) {
        // Darker version of (113, 201, 177)
        glColor3ub(56, 100, 88);
    } else {
        glColor3ub(113, 201, 177);
    }
    glVertex2f(-17.0f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -2.0f + translationY);
    glVertex2f(-27.5f + translationX, -4.0f + translationY);
    glVertex2f(-17.5f + translationX, -4.0f + translationY);
    glEnd();

    // Wheels (unchanged)
    circle(1.0, -20.0f + translationX, -4.0f + translationY, 0, 0, 0);
    circle(1.0, -25.3f + translationX, -4.0f + translationY, 0, 0, 0);
    circleL(0.5, -20.0f + translationX, -4.0f + translationY, 255, 255, 255, circleRotateAngle);
    circleL(0.5, -25.3f + translationX, -4.0f + translationY, 255, 255, 255, circleRotateAngle);
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

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // Set color to white

    // Outer vertex 1 (top)
    glVertex2f(x + 0.0000f * size, y + 1.0000f * size);
    // Inner vertex 1
    glVertex2f(x + 0.2245f * size, y + 0.3090f * size);
    // Outer vertex 2
    glVertex2f(x + 0.9511f * size, y + 0.3090f * size);
    // Inner vertex 2
    glVertex2f(x + 0.3620f * size, y - 0.1180f * size);
    // Outer vertex 3
    glVertex2f(x + 0.5878f * size, y - 0.8090f * size);
    // Inner vertex 3
    glVertex2f(x + 0.0000f * size, y - 0.3820f * size);
    // Outer vertex 4
    glVertex2f(x - 0.5878f * size, y - 0.8090f * size);
    // Inner vertex 4
    glVertex2f(x - 0.3620f * size, y - 0.1180f * size);
    // Outer vertex 5
    glVertex2f(x - 0.9511f * size, y + 0.3090f * size);
    // Inner vertex 5
    glVertex2f(x - 0.2245f * size, y + 0.3090f * size);

    glEnd();
}

void pillar(float X, float Y) {
    // Draw horizontal support lines
    glLineWidth(8.0f);
    glBegin(GL_LINES);
      if (isNightMode)
          glColor3ub(20, 5, 0); // Darker version for night
      else
          glColor3ub(36, 12, 1);
      glVertex2f(-22.0f, 14.0f);
      glVertex2f(22.0f, 14.0f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
      if (isNightMode)
          glColor3ub(20, 5, 0);
      else
          glColor3ub(36, 12, 1);
      glVertex2f(-22.0f, 13.2f);
      glVertex2f(22.0f, 13.2f);
    glEnd();

    glLineWidth(8.0f);
    glBegin(GL_LINES);
      if (isNightMode)
          glColor3ub(20, 5, 0);
      else
          glColor3ub(36, 12, 1);
      glVertex2f(-22.0f, 24.0f);
      glVertex2f(22.0f, 24.0f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
      if (isNightMode)
          glColor3ub(20, 5, 0);
      else
          glColor3ub(36, 12, 1);
      glVertex2f(-22.0f, 23.2f);
      glVertex2f(22.0f, 23.2f);
    glEnd();

    glLineWidth(1.0f);

    // Left support panel (Quad)
    glBegin(GL_QUADS);
      if (isNightMode)
          glColor3ub(100, 100, 100); // Darker gray
      else
          glColor3ub(143, 143, 142);
      glVertex2f(-26.0f + X, -18.0f + Y);
      glVertex2f(-24.0f + X, -18.0f + Y);
      glVertex2f(-24.0f + X, 15.0f + Y);
      glVertex2f(-26.0f + X, 15.0f + Y);
    glEnd();

    // Middle support panel (Quad)
    glBegin(GL_QUADS);
      if (isNightMode)
          glColor3ub(70, 75, 75); // Darker version of the original gray
      else
          glColor3ub(106, 108, 109);
      glVertex2f(-26.0f + X, -18.0f + Y);
      glVertex2f(-28.0f + X, -18.0f + Y);
      glVertex2f(-28.0f + X, 15.0f + Y);
      glVertex2f(-26.0f + X, 15.0f + Y);
    glEnd();

    // Right support panel (Quad)
    glBegin(GL_QUADS);
      if (isNightMode)
          glColor3ub(70, 75, 75);
      else
          glColor3ub(106, 108, 109);
      glVertex2f(-24.0f + X, -18.0f + Y);
      glVertex2f(-22.0f + X, -18.0f + Y);
      glVertex2f(-22.0f + X, 15.0f + Y);
      glVertex2f(-24.0f + X, 15.0f + Y);
    glEnd();

    // Top three triangles (bridge lights)
    if (isNightMode) {
        // When night mode is active, three different light colors will turn on.
        // First triangle: red light
        glBegin(GL_TRIANGLES);
          glColor3ub(120, 0, 0);
          glVertex2f(-25.0f + X, 22.0f + Y);
          glVertex2f(-27.0f + X, 15.0f + Y);
          glVertex2f(-23.0f + X, 15.0f + Y);
        glEnd();

        // Second triangle: green light
        glBegin(GL_TRIANGLES);
          glColor3ub(0, 120, 0);
          glVertex2f(-27.5f + X, 20.0f + Y);
          glVertex2f(-26.0f + X, 15.0f + Y);
          glVertex2f(-28.0f + X, 15.0f + Y);
        glEnd();

        // Third triangle: blue light
        glBegin(GL_TRIANGLES);
          glColor3ub(0, 0, 120);
          glVertex2f(-22.5f + X, 20.0f + Y);
          glVertex2f(-24.0f + X, 15.0f + Y);
          glVertex2f(-22.0f + X, 15.0f + Y);
        glEnd();
    } else {
        // Day mode: use the original colors for the triangles
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
void updateCarMove(int value) {
    if (carsMoving) {
        carSpeed += 0.2;
        if (carSpeed > 90.3) {
            carSpeed = -50.0; // Reset to starting position
        }
        glutPostRedisplay();
        glutTimerFunc(10, updateCarMove, 0); // Ensure consistent updates
    } else {
        carTimerActive = false; // Stop the timer when carsMoving is false
    }
}

void MoveCar() {
    if (!carTimerActive) { // Prevent multiple timers
        carTimerActive = true;
        glutTimerFunc(10, updateCarMove, 0);
    }
}

void stopCar() {
    carsMoving = false;
    carSpeed = 0; // Stop the car and reset speed
}
//Car move ends......................................................

//SHIP MOVING START........................................................

void movingShip(){
    glPushMatrix();
    glTranslatef(0.0f ,-shipspeed, 0.0f); // Move the ship downward
    // Calculate scale factor based on shipspeed (0 to 80 results in 1.0 to 1.2 scale)
    float scaleFactor = 1.0 + (shipspeed / 60.0f) * 0.7;
    // Scale the ship around its original position (8.0, 0.0)
    glTranslatef(16.0f, 0.0f, 0.0f); // Move to ship's original position
    glScalef(scaleFactor, scaleFactor, 1.0f); // Apply scaling
    glTranslatef(-8.0f, 0.0f, 0.0f); // Move back to original coordinate system
    ship(8.0, 0.0); // Draw the scaled ship
    glPopMatrix();
}

void updateShipMOve(int value){
    shipspeed += .1;
        if(shipspeed > 90.0)
        {
        shipspeed = 90.0;
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
    movingShip();
    rotatingBridgeLeft();
    rotationBridgeRight();
    bridge();

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


///////////////////////////////////////////LIKHI/////////////////////////////////////////



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

void resetShipPosition() {
    moveShipLK = false;
    ship1TranslationXLK = 0.0f;
    ship2TranslationXLK = 0.0f;
    ship1TranslationYLK = 0.0f;
    ship2TranslationYLK = 0.0f;
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

////////////////////////////////////////////LIKHI////////////////////////////////////


///////////////////////////////////////////NITU/////////////////////////////////////


///Mail circle
void mainCircle(float x, float y, float r) {
    int numSegments = 100; // The number of triangles used to draw the circle
    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0); //Black color

    for (int i = 0; i < numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments; // Calculate angle
        float xOffset = r * cos(angle);
        float yOffset = r * sin(angle);
        glColor3ub(0,0,0);
        glVertex2f(x + xOffset, y + yOffset);
    }
    glEnd();
}

void setBackgroundColor() {
    if (isNight) {
        glClearColor(0.0f, 0.1f, 0.2f, 1.0f); // Dark Water for Night
    } else {
        glClearColor(0.8f, 0.9f, 1.0f, 1.0f); // Light Water for Day
    }
}
///Bg color
void initGL() {
    setBackgroundColor(); /// Main BG water color
}

/// Function to draw a small circle (used for clouds & stars)
void drawSmallCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0f;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
///Sky day and Night
void drawSky() {
    glBegin(GL_POLYGON);
    if (isNight) {
        // Night sky colors
        glColor3ub(25, 25, 112); // Midnight Blue
        glVertex2f(-50, 40);
        glColor3ub(0, 0, 128); // Navy Blue
        glVertex2f(50, 40);
        glColor3ub(25, 25, 150); // Deep Blue
        glVertex2f(50, 28);
        glColor3ub(70, 130, 180); // Steel Blue
        glVertex2f(-50, 28);
    } else {
        // Day sky colors
        glColor3ub(216, 232, 240);
        glVertex2f(-50, 40);
        glColor3ub(204, 228, 240);
        glVertex2f(50, 40);
        glColor3ub(192, 224, 240);
        glVertex2f(50, 28);
        glColor3ub(125, 193, 227);
        glVertex2f(-50, 28);
    }
    glEnd();
}

/// Function to draw small clouds
void drawSmallCloud(float x, float y) {
    glColor3ub(255, 255, 255); // White color for clouds
    drawSmallCircle(x, y, 2.0);   // Center
    drawSmallCircle(x + 2.0, y + 0.5, 2.5);
    drawSmallCircle(x - 2.0, y + 0.5, 2.5);
    drawSmallCircle(x + 4.0, y, 2.0);
    drawSmallCircle(x - 4.0, y, 2.0);
    drawSmallCircle(x, y + 1.5, 1.5);
}

/// Function to draw moving clouds
void drawSmallClouds() {
    drawSmallCloud(45 + cloudOffsetX, 37); // Left cloud
    drawSmallCloud(70 + cloudOffsetX, 34); // Center cloud
    drawSmallCloud(95 + cloudOffsetX, 38); // Right cloud
    drawSmallCloud(120 + cloudOffsetX, 33); // Far-right cloud
}

/// Function to draw stars at night
void drawStars() {
    glColor3ub(255, 255, 255); // White stars
    drawSmallCircle(29,38, 0.1);
    drawSmallCircle(12,36, 0.2);
    drawSmallCircle(2, 38, 0.1);
    drawSmallCircle(-18,37, 0.1);
    drawSmallCircle(-42,38, 0.005);
    drawSmallCircle(-29,35, 0.006);
}

/// Function to update cloud movement (only when day mode is active)
void updateCloudss(int value) {
    if (!isNight) { // Move clouds only in day mode
        cloudOffsetX -= cloudSpeed;
        if (cloudOffsetX < -resetPosition) {
            cloudOffsetX = 0; // Reset cloud position
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateCloudss, 0); // Call update every 16ms (~60 FPS)
}


///Circle for sun
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.1416 / 180.0f; /// Convert degrees to radians
        float x = r * cos(angle);         /// Calculate x-coordinate
        float y = r * sin(angle);         /// Calculate y-coordinate
        glVertex2f(cx + x, cy + y);       /// Add vertex
    }
    glEnd();
}
/// Function to draw the moon
void drawMoon(float cx, float cy, float r) {
    glColor3ub(220, 220, 220); // Light Gray Moon
    drawCircle(cx, cy, r);

    // Create a small shadow effect on the moon
    glColor3ub(169, 169, 169); // Dark Gray Shadow
    drawCircle(cx + 0.2f, cy + 0.2f, r * 0.6f); // Small shadow
}

/// Function to draw gradient water (Day/Night)
void drawGradientWater() {
    glBegin(GL_QUADS);

    if (isNight) {
        // Night Water Gradient (Darker Blue)
        glColor3f(0.0f, 0.1f, 0.2f); // Dark blue at the top
        glVertex2f(-50.0f, 40.0f);
        glVertex2f(50.0f, 40.0f);

        glColor3f(0.0f, 0.0f, 0.1f); // Almost black at the bottom
        glVertex2f(50.0f, -40.0f);
        glVertex2f(-50.0f, -40.0f);
    } else {
        // Day Water Gradient (Light Blue)
        glColor3f(0.7f, 0.9f, 1.0f); // Light blue at the top (Shallow Water)
        glVertex2f(-50.0f, 40.0f);
        glVertex2f(50.0f, 40.0f);

        glColor3f(0.0f, 0.3f, 0.6f); // Deep blue at the bottom
        glVertex2f(50.0f, -40.0f);
        glVertex2f(-50.0f, -40.0f);
    }

    glEnd();
}
/// 1st ship
void drawShip(float offsetX, float offsetY) {
    float scale = 0.7f; // Scaling factor to make the ship smaller

    glPushMatrix();
    glTranslatef(offsetX + shipX, offsetY + shipY, 0.0f); // Translate the ship based on offsets

    /// Upper side
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0); // Red color
    glVertex2f(scale * 17, scale * 20);
    glVertex2f(scale * 17, scale * 22);
    glVertex2f(scale * 15, scale * 22);
    glVertex2f(scale * 15, scale * 24);
    glVertex2f(scale * 28, scale * 24);
    glVertex2f(scale * 28, scale * 22);
    glVertex2f(scale * 26, scale * 22);
    glVertex2f(scale * 26, scale * 20);
    glEnd();

    /// Lower side
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0); // Red color
    glVertex2f(scale * -0.5, scale * 8.25);
    glVertex2f(scale * 31.25, scale * 8.25);
    glVertex2f(scale * 31, scale * 6);
    glVertex2f(scale * 2, scale * 6);
    glEnd();

    /// Dark Blue Base
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 77); // Dark blue color
    glVertex2f(scale * -4, scale * 12);
    glVertex2f(scale * 6, scale * 12);
    glVertex2f(scale * 7, scale * 11);
    glVertex2f(scale * 31.25, scale * 11);
    glVertex2f(scale * 31.25, scale * 8.25);
    glVertex2f(scale * -0.5, scale *8.25);
    glEnd();

    /// Boxes
    glBegin(GL_POLYGON);
    glColor3ub(237, 248, 237);
    glVertex2f(scale * 3, scale * 12);
    glVertex2f(scale * 3, scale * 14.5);
    glVertex2f(scale * 3, scale * 17);
    glVertex2f(scale * 13, scale * 17);
    glVertex2f(scale * 13, scale * 20);
    glVertex2f(scale * 17, scale * 20);
    glVertex2f(scale * 29, scale * 20);
    glVertex2f(scale * 29, scale * 11);
    glVertex2f(scale * 7, scale * 11);
    glVertex2f(scale * 6, scale * 12);
    glEnd();

    /// Upper side of the ship
    glBegin(GL_POLYGON);
    glColor3ub(237, 248, 237);
    glVertex2f(scale * 3, scale * 12);
    glVertex2f(scale * 3, scale * 14.5);
    glVertex2f(scale * 3, scale * 17);
    glVertex2f(scale * 13, scale * 17);
    glVertex2f(scale * 13, scale * 20);
    glVertex2f(scale * 17, scale * 20);
    glVertex2f(scale * 29, scale * 20);
    glVertex2f(scale * 29, scale * 11);
    glVertex2f(scale * 7, scale * 11);
    glVertex2f(scale * 6, scale * 12);
    glEnd();

    /// Window side
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // White color
    glVertex2f(scale * 23, scale * 20);
    glVertex2f(scale * 29, scale * 20);
    glVertex2f(scale * 29, scale * 11);
    glVertex2f(scale * 25, scale * 11);
    glVertex2f(scale * 25, scale * 17);
    glVertex2f(scale * 23, scale * 17);
    glEnd();

    /// Line
    glLineWidth(1.0f); // Set the line width
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Black color for the line
    glVertex2f(scale * 27, scale * 20);
    glVertex2f(scale * 27, scale * 11);
    glEnd();
    glLineWidth(1.0f); // Reset the line width to default

    glLineWidth(1.0f); // Set the line width
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Black color for the line
    glVertex2f(scale * 3, scale * 14.5);
    glVertex2f(scale * 15, scale * 14.5);
    glEnd();
    glLineWidth(1.0f);
    /// Windows upper side-
    for (int i = 0; i < 10; i++) {
        float offsetX = i * 0.75 * scale; // Adjusted spacing for smaller size
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0); // Black color
        glVertex2f(scale * 17.75 + offsetX, scale * 21.5);
        glVertex2f(scale * 18.25 + offsetX, scale * 21.5);
        glVertex2f(scale * 18.25 + offsetX, scale * 21.0);
        glVertex2f(scale * 17.75 + offsetX, scale * 21.0);
        glEnd();
    }

    for (int i = 0; i < 7; i++) {
        float offsetY = i * -0.75 * scale; // Adjusted vertical spacing
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0); // Black color
        glVertex2f(scale * 27.75, scale * 19.5 + offsetY);
        glVertex2f(scale * 28.25, scale * 19.5 + offsetY);
        glVertex2f(scale * 28.25, scale * 19.0 + offsetY);
        glVertex2f(scale * 27.75, scale * 19.0 + offsetY);
        glEnd();
    }

    glPopMatrix();
}
void seconship(float offsetX, bool rotated){

    glPushMatrix();
    glTranslatef(offsetX, 0.0f, 0.0f); // Move the ship horizontally

    if (rotated) {
        glTranslatef(0.0f, 0.0f, 0.0f); // Keep ship centered
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f); // Rotate 180 degrees
    }


    glBegin(GL_POLYGON);

   glColor3ub(216,232,240);
    glVertex2f(-8,-29);
    //glColor3ub(204,228,240);
    glVertex2f(-4,-29);
    glVertex2f(-4,-33);
    glEnd();

    glBegin(GL_POLYGON);

    glBegin(GL_POLYGON);
    glColor3ub(216,232,240);
    glVertex2f(-4,-29);
    glColor3ub(25,10,227);

    glVertex2f(-3,-30);
    glVertex2f(-3,-33);
    glVertex2f(-4,-33);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(216,232,240);
    glVertex2f(-3,-30);
    glColor3ub(25,10,227);
    glVertex2f(14,-30);
    glVertex2f(14,-33);
    glVertex2f(-3,-33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(216,232,240);
    glVertex2f(14,-29);
    glColor3ub(25,10,227);
    glVertex2f(15,-29);
    glVertex2f(15,-33);
    glVertex2f(14,-33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-3,-25);
    glVertex2f(3,-25);
    glVertex2f(3,-30);
    glVertex2f(-3,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(3,-26);
    //glColor3ub(204,228,240);
    glVertex2f(11,-26);
    glVertex2f(11,-30);
    glVertex2f(3,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(11,-25);
    //glColor3ub(204,228,240);
    glVertex2f(14,-25);
    glVertex2f(14,-30);
    glVertex2f(11,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(9,-24);
    //glColor3ub(204,228,240);
    glVertex2f(14,-24);
    glVertex2f(14,-25);
    glVertex2f(9,-25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(8,-23);
    //glColor3ub(204,228,240);
    glVertex2f(15,-23);
    glVertex2f(15,-24);
    glVertex2f(8,-24);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(10,-22);
    //glColor3ub(204,228,240);
    glVertex2f(13,-22);
    glVertex2f(13,-23);
    glVertex2f(10,-23);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(11,-21);
    //glColor3ub(204,228,240);
    glVertex2f(12,-21);
    glVertex2f(12,-22);
    glVertex2f(11,-22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-5,-26);
    //glColor3ub(204,228,240);
    glVertex2f(-3,-26);
    glVertex2f(-3,-30);
    glVertex2f(-4,-29);
    glVertex2f(-5,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(216,200,240);
    glVertex2f(-1,-24);
    //glColor3ub(204,228,240);
    glVertex2f(1,-24);
    glVertex2f(1,-25);
    glVertex2f(-1,-25);
    glEnd();

    ///boxes

    glBegin(GL_POLYGON);
    glColor3ub(180,0,0);
    glVertex2f(-5,-26);
    glColor3ub(177,0,0);
    glVertex2f(-4,-26);
    glColor3ub(160,0,0);
    glVertex2f(-4,-27);
    glColor3ub(162,0,0);
    glVertex2f(-5,-27);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 69, 0);
    glVertex2f(-5,-27);
    glColor3ub(255, 65, 0);
    glVertex2f(-4,-27);
    glColor3ub(255, 63, 0);
    glVertex2f(-4,-28);
    glColor3ub(255, 60, 0);
    glVertex2f(-5,-28);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 140, 0);
    glVertex2f(-5,-28);
    glVertex2f(-4,-28);
    glVertex2f(-4,-29);
    glVertex2f(-5,-29);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 215, 200);
    glVertex2f(-5,-29);
    glColor3ub(255, 215, 100);
    glVertex2f(-4,-29);
    glColor3ub(255, 215,150);
    glVertex2f(-4,-30);
    glColor3ub(255, 215, 120);
    glVertex2f(-5,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(31, 139, 34);
    glVertex2f(-4,-26);
    glColor3ub(32, 139, 34);
    glVertex2f(-3,-26);
    glColor3ub(34, 139, 34);
    glVertex2f(-3,-27);
    glColor3ub(33, 139, 34);
    glVertex2f(-4,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(46, 139, 87);
    glVertex2f(-4,-27);
    glVertex2f(-3,-27);
    glVertex2f(-3,-28);
    glVertex2f(-4,-28);
    glEnd();
    glBegin(GL_POLYGON);
     glColor3ub(60, 179, 113);
    glVertex2f(-4,-28);
    glVertex2f(-3,-28);
    glVertex2f(-3,-29);
    glVertex2f(-4,-29);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-4,-29);
    glVertex2f(-3,-29);
    glVertex2f(-3,-30);
    glVertex2f(-4,-30);
    glEnd();

    glBegin(GL_POLYGON);
   glColor3ub(30, 144, 255);
    glVertex2f(-3,-26);
    glVertex2f(-2,-26);
    glVertex2f(-2,-27);
    glVertex2f(-3,-27);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(200,200,230);
    glVertex2f(-3,-27);
    glVertex2f(-2,-27);
    glVertex2f(-2,-28);
    glVertex2f(-3,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 102);
    glVertex2f(-3,-28);
    glVertex2f(-2,-28);
    glVertex2f(-2,-29);
    glVertex2f(-3,-29);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(120,100,230);
    glVertex2f(-3,-29);
    glVertex2f(-2,-29);
    glVertex2f(-2,-30);
    glVertex2f(-3,-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(100,200,230);
    glVertex2f(-2,-26);
    glVertex2f(-1,-26);
    glVertex2f(-1,-27);
    glVertex2f(-2,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 153);
    glVertex2f(-2,-27);
    glVertex2f(-1,-27);
    glVertex2f(-1,-28);
    glVertex2f(-2,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 0);
    glVertex2f(-2,-28);
    glVertex2f(-1,-28);
    glVertex2f(-1,-29);
    glVertex2f(-2,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 153);
    glVertex2f(-2,-29);
    glVertex2f(-1,-29);
    glVertex2f(-1,-30);
    glVertex2f(-2,-30);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255, 255, 102);
    glVertex2f(-1,-26);
    glVertex2f(3,-26);
    glVertex2f(3,-27);
    glVertex2f(-1,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2f(-1,-27);
    glVertex2f(3,-27);
    glVertex2f(3,-28);
    glVertex2f(-1,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-1,-28);
    glVertex2f(3,-28);
    glVertex2f(3,-29);
    glVertex2f(-1,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex2f(-1,-29);
    glVertex2f(3,-29);
    glVertex2f(3,-30);
    glVertex2f(-1,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(101,101,101);
    glVertex2f(-3,-25);
    glVertex2f(-1,-25);
    glVertex2f(-1,-26);
    glVertex2f(-3,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(191,191,191);
    glVertex2f(-1,-25);
    glVertex2f(0,-25);
    glVertex2f(0,-26);
    glVertex2f(-1,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100,100,100);
    glVertex2f(0,-25);
    glVertex2f(2,-25);
    glVertex2f(2,-26);
    glVertex2f(0,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 255, 102);
    glVertex2f(2,-25);
    glVertex2f(3,-25);
    glVertex2f(3,-26);
    glVertex2f(2,-26);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(000,101,101);
    glVertex2f(-1,-24);
    glVertex2f(1,-24);
    glVertex2f(1,-25);
    glVertex2f(-1,-25);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255, 153, 51);
    glVertex2f(3,-26);
    glVertex2f(5,-26);
    glVertex2f(5,-27);
    glVertex2f(3,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 255, 102);
    glVertex2f(3,-27);
    glVertex2f(5,-27);
    glVertex2f(5,-28);
    glVertex2f(3,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 153, 153);
    glVertex2f(3,-28);
    glVertex2f(7,-28);
    glVertex2f(7,-29);
    glVertex2f(3,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex2f(3,-29);
    glVertex2f(7,-29);
    glVertex2f(7,-30);
    glVertex2f(3,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70, 130,0);
    glVertex2f(5,-26);
    glColor3ub(70, 130, 18);
    glVertex2f(6,-26);
    glColor3ub(70, 130, 15);
    glVertex2f(6,-27);
    glColor3ub(70, 130,0);
    glVertex2f(5,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51, 51, 204);
    glVertex2f(5,-27);
    glVertex2f(6,-27);
    glVertex2f(6,-28);
    glVertex2f(5,-28);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(6,-26);
    glVertex2f(7,-26);
    glVertex2f(7,-27);
    glVertex2f(6,-27);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 255);
    glVertex2f(6,-27);
    glVertex2f(7,-27);
    glVertex2f(7,-28);
    glVertex2f(6,-28);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255, 102, 0);
    glVertex2f(7,-26);
    glVertex2f(12,-26);
    glVertex2f(12,-27);
    glVertex2f(7,-27);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(7,-27);
    glVertex2f(12,-27);
    glVertex2f(12,-28);
    glVertex2f(7,-28);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex2f(7,-28);
    glVertex2f(12,-28);
    glVertex2f(12,-29);
    glVertex2f(7,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(7,-29);
    glVertex2f(12,-29);
    glVertex2f(12,-30);
    glVertex2f(7,-30);
    glEnd();

    /// Line
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(9,-25);
    glVertex2f(14,-25);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(12,-25);
    glVertex2f(12,-30);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(13,-25);
    glVertex2f(13,-30);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(14,-24);
    glVertex2f(14,-30);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(8,-24);
    glVertex2f(15,-24);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(10,-23);
    glVertex2f(13,-23);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(11,-22);
    glVertex2f(12,-22);
    glEnd();
    glLineWidth(1.0f);





    glPopMatrix();

}
void stopAndRestart() {
    isWaiting = true; // Indicate waiting state
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Wait for 30 seconds

    shipMovingLeft = !shipMovingLeft; // Reverse direction
    shipRotated = !shipRotated; // Flip ship rotation
    isWaiting = false; // Reset waiting state
}

void update(int value) {
    if (!isWaiting) {
        if (shipMovingLeft) {
            ship2X -= 0.1f; // Move left
            if (ship2X <= 0.0f) { // Stop at left side
                ship2X = 0.0f;
                std::thread(stopAndRestart).detach(); // Start wait time in a separate thread
            }
        } else {
            ship2X += 0.1f; // Move right
            if (ship2X >= 50.0f) { // Stop at right side
                ship2X = 50.0f;
                std::thread(stopAndRestart).detach(); // Start wait time
            }
        }
    }

    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(16, update, 0); // Call update every 16ms (~60 FPS)
}
///Trucks and some boxes
void Trucks(){
    ///1st truck
    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 51);
    glVertex2f(-46,-18);
    glVertex2f(-36,-18);
    glVertex2f(-36,-21);
    glVertex2f(-46,-21);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-36,-18);
    //glColor3ub(204,228,240);
    glVertex2f(-35,-19);
    glVertex2f(-35,-21);
    glVertex2f(-36,-21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-35,-19);
    //glColor3ub(204,228,240);
    glVertex2f(-34,-19);
    glVertex2f(-34,-21);
    glVertex2f(-35,-21);
    glEnd();

    ///2nd truck

    glBegin(GL_POLYGON);
    glColor3ub(102, 153, 153);
    glVertex2f(-32,-32);
    glVertex2f(-23,-32);
    glVertex2f(-23,-35);
    glVertex2f(-32,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2f(-23,-32);
    //glColor3ub(204,228,240);
    glVertex2f(-22,-32);
    glVertex2f(-22,-35);
    glVertex2f(-23,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2f(-22,-32);
    //glColor3ub(204,228,240);
    glVertex2f(-21,-33);
    glVertex2f(-21,-35);
    glVertex2f(-22,-35);
    glEnd();

}
///Boxes on the portside
void drawStackedBoxes(float startX, float startY,float spacing) {
    for (int i = 0; i <5; i++) {
        float offsetY = i * spacing; // Move each box downward
        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0); // Light purple color
        glVertex2f(startX, startY + offsetY);
        glColor3ub(216, 220, 240);
        glVertex2f(startX + 5, startY + offsetY);
        glColor3ub(0, 51, 0);
        glVertex2f(startX + 5, startY + offsetY + 1);
        glColor3ub(204, 255, 255);
        glVertex2f(startX, startY + offsetY + 1);
        glEnd();
    }
}
/// Function to draw the sunray
void drawSun(float cx, float cy, float r) {
    glColor3ub(255, 165, 0);
    drawCircle(cx, cy, r);

    /// Draw the sun's rays
    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) { ///12 rays
        float angle = 2.0f * M_PI * i / 12;
        float x1 = cx + cos(angle) * r;       ///Start of ray (edge of sun)
        float y1 = cy + sin(angle) * r;
        float x2 = cx + cos(angle) * (r + 0.5); ///End of ray (outside sun)
        float y2 = cy + sin(angle) * (r + 0.5);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}
/// Function to draw the ground (Day/Night)
void drawGround() {
    glBegin(GL_POLYGON);
    if (isNight) {
        glColor3ub(80, 70, 60); // Dark brownish-gray for night
    } else {
        glColor3ub(241, 231, 215); // Light sand color for day
    }
    glVertex2f(-50, 1);
    glVertex2f(-35, -5);
    glVertex2f(-30, -12);
    glVertex2f(-20, -19);
    glVertex2f(-6, -40);
    glVertex2f(-50, -40);
    glEnd();
}
void displayNitu() {
    glClear(GL_COLOR_BUFFER_BIT);

    ///watercolor function
    drawGradientWater();
    ///Second ship function
    seconship(ship2X, shipRotated);
    ///Ground color
    drawGround();
    ///boxes function
    drawStackedBoxes(-45, -6,0.8);

     glBegin(GL_POLYGON);
    glColor3ub(102, 0, 51);
    glVertex2f(-49,-23);
    glVertex2f(-46,-23);
    glVertex2f(-46,-24);
    glVertex2f(-49,-24);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(-49,-24);
    glVertex2f(-46,-24);
    glVertex2f(-46,-25);
    glVertex2f(-49,-25);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(-49,-25);
    glVertex2f(-45,-25);
    glVertex2f(-45,-26);
    glVertex2f(-49,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100,101,205);
    glVertex2f(-49,-26);
    glVertex2f(-45,-26);
    glVertex2f(-45,-27);
    glVertex2f(-49,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 0);
    glVertex2f(-49,-28);
    glVertex2f(-44,-28);
    glVertex2f(-44,-29);
    glVertex2f(-49,-29);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(51, 102, 255);
    glVertex2f(-46,-24);
    glVertex2f(-44,-24);
    glVertex2f(-44,-25);
    glVertex2f(-46,-25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241,201,100);
    glVertex2f(-45,-25);
    glVertex2f(-43,-25);
    glVertex2f(-43,-26);
    glVertex2f(-45,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-45,-26);
    glVertex2f(-42,-26);
    glVertex2f(-42,-27);
    glVertex2f(-45,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(200,201,205);
    glVertex2f(-45,-27);
    glVertex2f(-42,-27);
    glVertex2f(-42,-28);
    glVertex2f(-45,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-44,-28);
    glVertex2f(-41,-28);
    glVertex2f(-41,-29);
    glVertex2f(-44,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(200,201,205);
    glVertex2f(-41,-35);
    glVertex2f(-38,-35);
    glVertex2f(-38,-36);
    glVertex2f(-41,-36);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(200,201,205);
    glVertex2f(-41,-36);
    glVertex2f(-38,-36);
    glVertex2f(-38,-37);
    glVertex2f(-41,-37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(200,201,305);
    glVertex2f(-41,-37);
    glVertex2f(-38,-37);
    glVertex2f(-38,-38);
    glVertex2f(-41,-38);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(200,301,205);
    glVertex2f(-41,-38);
    glVertex2f(-37,-38);
    glVertex2f(-37,-39);
    glVertex2f(-41,-39);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-41,-39);
    glVertex2f(-37,-39);
    glVertex2f(-37,-40);
    glVertex2f(-41,-40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-37,-38);
    glVertex2f(-33,-38);
    glVertex2f(-33,-39);
    glVertex2f(-37,-39);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(211,201,205);
    glVertex2f(-37,-39);
    glVertex2f(-33,-39);
    glVertex2f(-33,-40);
    glVertex2f(-37,-40);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(102, 0, 51);
    glVertex2f(-38,-35);
    glVertex2f(-36,-35);
    glVertex2f(-36,-36);
    glVertex2f(-38,-36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-38,-36);
    glVertex2f(-35,-36);
    glVertex2f(-35,-37);
    glVertex2f(-38,-37);
    glEnd();
        glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(-38,-37);
    glVertex2f(-34,-37);
    glVertex2f(-34,-38);
    glVertex2f(-38,-38);
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(100,200,300);
    glVertex2f(-35,-28);
    glVertex2f(-29,-28);
    glVertex2f(-29,-31);
    glVertex2f(-35,-31);
    glEnd();
      glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-31,-25);
    glVertex2f(-25,-25);
    glVertex2f(-25,-28);
    glVertex2f(-31,-28);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(200,200,205);
    glVertex2f(-18,-37);
    glVertex2f(-13,-37);
    glVertex2f(-13,-40);
    glVertex2f(-18,-40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100,100,205);
    glVertex2f(-13,-37);
    glVertex2f(-8,-37);
    glVertex2f(-8,-40);
    glVertex2f(-13,-40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(300,300,305);
    glVertex2f(-14,-34);
    glVertex2f(-9,-34);
    glVertex2f(-9,-37);
    glVertex2f(-14,-37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(-35,-9);
    glVertex2f(-30,-9);
    glVertex2f(-30,-11);
    glVertex2f(-35,-11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 0, 51);
    glVertex2f(-35,-11);
    glVertex2f(-29,-11);
    glVertex2f(-29,-13);
    glVertex2f(-35,-13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51, 102, 255);
    glVertex2f(-38,-12);
    glVertex2f(-32,-12);
    glVertex2f(-32,-14);
    glVertex2f(-38,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 0);
    glVertex2f(-50,1);
    glVertex2f(-48,1);
    glVertex2f(-48,-0);
    glVertex2f(-50,-0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-50,-0);
    glVertex2f(-47,-0);
    glVertex2f(-47,-1);
    glVertex2f(-50,-1);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(51, 102, 255);
    glVertex2f(-50,-1);
    glVertex2f(-45,-1);
    glVertex2f(-45,-2);
    glVertex2f(-50,-2);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(-50,-2);
    glVertex2f(-45,-2);
    glVertex2f(-45,-3);
    glVertex2f(-50,-3);
    glEnd();




    /// Mail Draw Ships
    drawShip(0.0, 0.0);
    drawSky();
    if (isNight) {
        drawStars(); // Draw stars at night
    } else {
        drawSmallClouds(); // Draw clouds in day mode
    }
    /// Sun and moon
    if (isNight) {
        drawMoon(40.0f, 35.0f, 3.0f); // Draw moon at night
    } else {
        drawSun(40.0f, 35.0f, 3.0f); // Draw sun during the day
    }

    ///Truck
    Trucks();
    mainCircle(-24,-35,0.8);
    mainCircle(-30,-35,0.8);
    mainCircle(-35.5,-21,0.8);
    mainCircle(-40,-21,0.8);
    mainCircle(-44,-21,0.8);

    glFlush();
}


///////////////////////////////////////////NITU//////////////////////////////////////////////////


//Ruddro


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    skyr();

    sunmoonr();
    cloudsr();
     buildingr();
      buildingr2();
      blboardr();
    roadr();
    busr();
    carr();
    grassr();
    treer();
    riverr();
    shiprr();
    glFlush();
    glutSwapBuffers();
}



//Ruddro



void displayScene2Morning() {
    glClear(GL_COLOR_BUFFER_BIT);
    isNightMode = false;
    if (isRaining) {
        skyRain();
    } else {
        skyMorning();
        sun(0.0f, sunTranslationY - 0.0f);
    }

    //airplane(airplaneTranslationX-55.0f, 0.0f);

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

    isNightMode = false;

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


    //airplane(airplaneTranslationX-55.0f, 0.0f);

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

    isNightMode = true;

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


///////////////////////////////////////LIKHI////////////////////////////////////

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
        if (ship1TranslationXLK > -18.0f) ship1TranslationXLK -= 0.1f;
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
}

//////////////////////////////////////////////////////////LIKHI////////////////////////////////////

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
        sunTranslationY -= 0.02f;
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


void resetAirplanePosition() {
    moveAirplaneRight = false;
    airplaneTranslationX = 0.0f;
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
    case 's':
    case 'S':
        moveSunDown = !moveSunDown;
        if (moveSunDown)
            glutTimerFunc(16, updateSun, 0);
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
          case '1':
        currentScene = 1;
        moveSunDown = false;
        sunTranslationY = 0.0f;
          glutDisplayFunc(display);
        glutPostRedisplay();
        break;
    case '2':
        currentScene = 2;
        moveSunDown = false;
        sunTranslationY = 0.0f;
          glutDisplayFunc(displayScene2Morning);
        glutPostRedisplay();
        break;
        case '3':
        moveSunDown = false;
        sunTranslationY = 0.0f;
          glutDisplayFunc(displayScene3MorningLK);
        glutPostRedisplay();
        break;
        case '4':
        moveSunDown = false;
        sunTranslationY = 0.0f;
          glutDisplayFunc(displayNitu);
        glutPostRedisplay();
        break;

        //Ruddro

       case 'n':
    case 'N':
        isNightr = 1;
        glutPostRedisplay();
        break;

    case 'M':
    case 'm':
        isNightr = 0;
        glutPostRedisplay();
        break;

    case 'T':
    case 't':
        isCarMovingr = !isCarMovingr;
        glutPostRedisplay();
        break;

    case 'U':
    case 'u':
        isBusMovingr = !isBusMovingr;
        glutPostRedisplay();
        break;

    case 'K':
    case 'k':
        isSunMovingr = !isSunMovingr;
        glutPostRedisplay();
        break;
//Ruddro

///////////////////////////////////////////////LIKHI////////////////////////////////////

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

//////////////////////////////////LIKHI////////////////////////////

/////////////////////////////////NITU///////////////////////////

    case 'v':
    case 'V':
        isNight = !isNight;
        glutPostRedisplay();

        default:
            break;
    }
}

//Ruddro

///////////////////////////////////////NITU/////////////////////////////

void handleSpecialKeypress(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            shipX -= shipSpeed; // Move left
            break;
        case GLUT_KEY_RIGHT:
            shipX += shipSpeed; // Move right
            break;
        case GLUT_KEY_UP:
            shipY += shipSpeed; // Move up
            break;
        case GLUT_KEY_DOWN:
            shipY -= shipSpeed; // Move down
            break;
    }
    glutPostRedisplay(); // Refresh the display after movement
}

//////////////////////////NITU///////////////////////////////

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        if (currentScene == 1) {
            // Scene 1: Ship movement
            isShipMovingr = !isShipMovingr;
            glutPostRedisplay();
        } else if (currentScene == 2) {
            // Scene 2: Car movement
            carsMoving = !carsMoving;
            if (carsMoving) {
                glutTimerFunc(2, updateCarMove, 0);
            } else {
                carSpeed = 0.0f;
                glutPostRedisplay();
            }
        }
    }
}

int main(int argc, char** argv) {

    printf("  Click-1(For scene-1) \n");
    printf("  Scene-1 (Done By RUDDRO) \n");
    printf("  Key Works: \n");
    printf("  N= Night View \n");
    printf("  M= Day View \n");
    printf("  T= Car Moving \n");
    printf("  U= Bus Moving \n");
    printf("  K= Sun Moving \n");
    printf("  Mouse Right Button= Ship Moving \n");

    printf("==========================================\n\n");

    printf("  Click-2(For scene-2) \n");
    printf("  Scene-2 (Done By RAKIB) \n");
    printf("  Key Works: \n");
    printf("  S= Sun moving to see evening and night view(Again S to stop Sun moving) \n");
    printf("  R= Rain Theme(On and Off) \n");
    printf("  C= Cloud move(Start and Stop) \n");
    printf("  W= Windmill moving (start and stop) \n");
    printf("  A= Airplane move(Start and Stop) \n");
    printf("  D= Bridge animation and ship crossing bridge \n");
    printf("  Mouse Right Button= Car Move(start and stop) \n");
    printf("  B= Airplane Reset \n");
    printf("  Z=Reset the bridge animation scene. \n");

    printf("==========================================\n\n");

    printf("  Click-3(For scene-3) \n");
    printf("  Scene-3 (Done By LIKHI) \n");
    printf("  Key Works: \n");
    printf("  X= Ship Animation Start and Stop \n");
    printf("  I= Move cloud \n");
    printf("  H= Rain Theme \n");
    printf("  P= Sun Moving \n");

    printf("==========================================\n\n");

    printf("  Click-4(For scene-4) \n");
    printf("  Scene-4 (Done By NITU) \n");
    printf("  - Press 'V' to change Day/Night mode\n");
    printf("  - Arrow Keys to Move the  1st Ship \n");
    printf("  - The second ship moves automatically and also in can rotate\n");
    printf("  - Clouds move automatically from left to right and right to left\n");
    printf("  - In the night sides there are some stars and a moon \n ");
    printf("==========================================\n\n");


    glutInit(&argc, argv);
    glutCreateWindow("Project");
    glutInitWindowSize(1400, 800);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    //glutMouseFunc(handleMouseClick);
    glutMouseFunc(handleMouse);
    glutTimerFunc(16, updateRain, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    ///////////////////////////Nitu///////////////////////////////
    glutSpecialFunc(handleSpecialKeypress);
    glutTimerFunc(16, update, 0); // Update function for 2nd ship
    glutTimerFunc(16, updateCloudss, 0); // Update function for clouds
    /////////////////////////////Nitu///////////////////////////
    gluOrtho2D(-50.0, 50.0, -40.0, 40.0);
    glutMainLoop();
    return 0;
}
