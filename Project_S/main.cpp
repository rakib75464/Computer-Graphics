#include <windows.h>
#include <mmsystem.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#pragma comment(lib, "winmm.lib")
using namespace std;

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0, 1500.0, 0.0, 1000.0);
}

bool _sun = true;
bool isDay = true;

void setClearColor(float r, float g, float b, float a)
{
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}

void setColor(float r, float g, float b)
{
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
}

void drawCircle(double x, double y, double r)
{
    glBegin(GL_POLYGON);
    double D = 1 - r;
    double xv = 0, yv = r;

    while(xv < yv)
    {
        glVertex2i(x + xv, y + yv);
        glVertex2i(x + yv, y + xv);
        glVertex2i(x + yv, y - xv);
        glVertex2i(x + xv, y - yv);
        glVertex2i(x - xv, y - yv);
        glVertex2i(x - yv, y - xv);
        glVertex2i(x - yv, y + xv);
        glVertex2i(x - xv, y + yv);

        if(D < 0)
        {
            D = D + (2 * xv + 3);
            xv += 1;
        }
        else
        {
            D = D + 2 * (xv - yv) + 5;
            xv += 1;
            yv -= 1;
        }
    }
    glEnd();
}

void leftTree(int r, int g, int b)
{
    //main bark
    if(isDay)
    {
        setColor(139,69,19);
    }
    else if(!isDay)
    {
        setColor(70, 35, 10);
    }
    glBegin(GL_QUADS);
    glVertex2i(70, 565);
    glVertex2i(70, 625);
    glVertex2i(90, 625);
    glVertex2i(90, 565);
    glEnd();

    //left bark
    glBegin(GL_POLYGON);
    glVertex2i(70, 565);
    glVertex2i(50, 565);
    glVertex2i(70, 575);
    glEnd();

    //right bark
    glBegin(GL_POLYGON);
    glVertex2i(90, 565);
    glVertex2i(110, 565);
    glVertex2i(90, 575);
    glEnd();

    //lower bark
    glBegin(GL_POLYGON);
    glVertex2i(70, 565);
    glVertex2i(80, 555);
    glVertex2i(90, 565);
    glEnd();

    //leaf 01
    setColor(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2i(20, 625);
    glVertex2i(140, 625);
    glVertex2i(80, 695);
    glEnd();

    //leaf 02
    glBegin(GL_POLYGON);
    glVertex2i(30, 665);
    glVertex2i(130, 665);
    glVertex2i(80, 735);
    glEnd();

    //leaf 03
    glBegin(GL_POLYGON);
    glVertex2i(40, 715);
    glVertex2i(120, 715);
    glVertex2i(80, 785);
    glEnd();
}

void rightTree(int r, int g, int b)
{
    int moveRightTreeX = 1200;
    //main bark
    if(isDay)
    {
        setColor(139,69,19);
    }
    else if(!isDay)
    {
        setColor(70, 35, 10);
    }
    glBegin(GL_QUADS);
    glVertex2i(70+moveRightTreeX, 565);
    glVertex2i(70+moveRightTreeX, 625);
    glVertex2i(90+moveRightTreeX, 625);
    glVertex2i(90+moveRightTreeX, 565);
    glEnd();

    //left bark
    glBegin(GL_POLYGON);
    glVertex2i(70+moveRightTreeX, 565);
    glVertex2i(50+moveRightTreeX, 565);
    glVertex2i(70+moveRightTreeX, 575);
    glEnd();

    //right bark
    glBegin(GL_POLYGON);
    glVertex2i(90+moveRightTreeX, 565);
    glVertex2i(110+moveRightTreeX, 565);
    glVertex2i(90+moveRightTreeX, 575);
    glEnd();

    //lower bark
    glBegin(GL_POLYGON);
    glVertex2i(70+moveRightTreeX, 565);
    glVertex2i(80+moveRightTreeX, 555);
    glVertex2i(90+moveRightTreeX, 565);
    glEnd();

    //leaf 01
    setColor(r, g, b);
    drawCircle(1230, 630, 22);
    drawCircle(1235, 665, 18);
    drawCircle(1245, 690, 18);
    drawCircle(1265, 715, 20);
    drawCircle(1280, 704, 21);
    drawCircle(1310, 690, 20);
    drawCircle(1330, 665, 18);
    drawCircle(1320, 650, 12);
    drawCircle(1300, 665, 18);
    drawCircle(1325, 635, 15);
    drawCircle(1280, 630, 15);
    drawCircle(1302, 625, 18);
    drawCircle(1270, 680, 30);
    drawCircle(1270, 650, 30);
    drawCircle(1298, 650, 6);
    drawCircle(1309, 646, 10);
    drawCircle(1296, 723, 17);
}

void leftHouse()
{
    //front wall
    if(isDay)
    {
        setColor(184,134,11);
    }
    else if(!isDay)
    {
        setColor(130, 100, 20);
    }
    glBegin(GL_QUADS);
    glVertex2i(260, 545);
    glVertex2i(420, 545);
    glVertex2i(420, 615);
    glVertex2i(260, 615);
    glEnd();

    //front roof
    if(isDay)
    {
        setColor(139,69,19);
    }
    else if(!isDay)
    {
        setColor(90, 45, 15);
    }
    glBegin(GL_QUADS);
    glVertex2i(115, 615);
    glVertex2i(435, 615);
    glVertex2i(355, 695);
    glVertex2i(195, 695);
    glEnd();

    //side top wall
    if(isDay)
    {
        setColor(205,133,63);
    }
    else if(!isDay)
    {
        setColor(130, 80, 40);
    }
    glBegin(GL_TRIANGLES);
    glVertex2i(260, 615);
    glVertex2i(195, 680);
    glVertex2i(130, 615);
    glEnd();

    //side wall
    glBegin(GL_QUADS);
    glVertex2i(260, 615);
    glVertex2i(130, 615);
    glVertex2i(130, 565);
    glVertex2i(260, 545);
    glEnd();

    // side wall window
    if(isDay)
    {
        setColor(128,135,32);
    }
    else if(!isDay)
    {
        setColor(60, 65, 15);
    }
    glBegin(GL_QUADS);
    glVertex2i(177, 586);
    glVertex2i(207, 586);
    glVertex2i(207, 613);
    glVertex2i(177, 613);
    glEnd();

    //front wall door-frame
    if(isDay)
    {
        setColor(139,69,19);
    }
    else if(!isDay)
    {
        setColor(90, 45, 15);
    }
    glBegin(GL_QUADS);
    glVertex2i(260, 545);
    glVertex2i(420, 545);
    glVertex2i(435, 530);
    glVertex2i(260, 530);
    glEnd();

    //side wall door-frame
    glBegin(GL_QUADS);
    glVertex2i(130, 565);
    glVertex2i(260, 545);
    glVertex2i(260, 530);
    glVertex2i(115, 555);
    glEnd();

    //main door structure
    setColor(18,19,4);
    glBegin(GL_QUADS);
    glVertex2i(310, 602);
    glVertex2i(370, 602);
    glVertex2i(370, 545);
    glVertex2i(310, 545);
    glEnd();

    //left door
    if(isDay)
    {
        setColor(128,135,32);
    }
    else if(!isDay)
    {
        setColor(80, 85, 20);
    }
    glBegin(GL_QUADS);
    glVertex2i(310, 602);
    glVertex2i(337, 595);
    glVertex2i(337, 545);
    glVertex2i(310, 545);
    glEnd();

    //right door
    glBegin(GL_QUADS);
    glVertex2i(343, 595);
    glVertex2i(370, 602);
    glVertex2i(370, 545);
    glVertex2i(343, 545);
    glEnd();
}

void rightHouse(int r, int g, int b)
{
    int moveHouseX = 835;
    int moveHouseY = 50;
    //front wall
    if(isDay)
    {
        setColor(205,133,63);
    }
    else if(!isDay)
    {
        setColor(130, 85, 45);
    }
    glBegin(GL_QUADS);
    glVertex2i(260+moveHouseX, 545-moveHouseY);
    glVertex2i(420+moveHouseX, 545-moveHouseY);
    glVertex2i(420+moveHouseX, 615-moveHouseY);
    glVertex2i(260+moveHouseX, 615-moveHouseY);
    glEnd();

    //front roof
    setColor(r, g, b);
    glBegin(GL_QUADS);
    glVertex2i(115+moveHouseX, 615-moveHouseY);
    glVertex2i(435+moveHouseX, 615-moveHouseY);
    glVertex2i(355+moveHouseX, 695-moveHouseY);
    glVertex2i(195+moveHouseX, 695-moveHouseY);
    glEnd();

    //side top wall
    if(isDay)
    {
        setColor(184,134,11);
    }
    else if(!isDay)
    {
        setColor(100, 80, 10);
    }
    glBegin(GL_TRIANGLES);
    glVertex2i(260+moveHouseX, 615-moveHouseY);
    glVertex2i(195+moveHouseX, 680-moveHouseY);
    glVertex2i(130+moveHouseX, 615-moveHouseY);
    glEnd();

    //side wall
    glBegin(GL_QUADS);
    glVertex2i(260+moveHouseX, 615-moveHouseY);
    glVertex2i(130+moveHouseX, 615-moveHouseY);
    glVertex2i(130+moveHouseX, 565-moveHouseY);
    glVertex2i(260+moveHouseX, 545-moveHouseY);
    glEnd();

    // side wall window
    if(isDay)
    {
        setColor(160,82,45);
    }
    else if(!isDay)
    {
        setColor(80, 40, 20);
    }
    glBegin(GL_QUADS);
    glVertex2i(177+moveHouseX, 586-moveHouseY);
    glVertex2i(207+moveHouseX, 586-moveHouseY);
    glVertex2i(207+moveHouseX, 613-moveHouseY);
    glVertex2i(177+moveHouseX, 613-moveHouseY);
    glEnd();

    //front wall door-frame
    setColor(r,g,b);
    glBegin(GL_QUADS);
    glVertex2i(260+moveHouseX, 545-moveHouseY);
    glVertex2i(420+moveHouseX, 545-moveHouseY);
    glVertex2i(435+moveHouseX, 530-moveHouseY);
    glVertex2i(260+moveHouseX, 530-moveHouseY);
    glEnd();

    //side wall door-frame
    glBegin(GL_QUADS);
    glVertex2i(130+moveHouseX, 565-moveHouseY);
    glVertex2i(260+moveHouseX, 545-moveHouseY);
    glVertex2i(260+moveHouseX, 530-moveHouseY);
    glVertex2i(115+moveHouseX, 555-moveHouseY);
    glEnd();

    //main door structure
    setColor(31,16,9);
    glBegin(GL_QUADS);
    glVertex2i(310+moveHouseX, 602-moveHouseY);
    glVertex2i(370+moveHouseX, 602-moveHouseY);
    glVertex2i(370+moveHouseX, 545-moveHouseY);
    glVertex2i(310+moveHouseX, 545-moveHouseY);
    glEnd();

    //left door
    if(isDay)
    {
        setColor(160,82,45);
    }
    else if(!isDay)
    {
        setColor(80, 40, 20);
    }
    glBegin(GL_QUADS);
    glVertex2i(310+moveHouseX, 602-moveHouseY);
    glVertex2i(337+moveHouseX, 595-moveHouseY);
    glVertex2i(337+moveHouseX, 545-moveHouseY);
    glVertex2i(310+moveHouseX, 545-moveHouseY);
    glEnd();

    //right door
    glBegin(GL_QUADS);
    glVertex2i(343+moveHouseX, 595-moveHouseY);
    glVertex2i(370+moveHouseX, 602-moveHouseY);
    glVertex2i(370+moveHouseX, 545-moveHouseY);
    glVertex2i(343+moveHouseX, 545-moveHouseY);
    glEnd();
}

void hayMound(int r, int g, int b)
{
    setColor(r, g, b);
    //hay mound
    glBegin(GL_POLYGON);
    glVertex2i(420, 545);
    glVertex2i(520, 545);
    glVertex2i(510, 595);
    glVertex2i(480, 640);
    glVertex2i(425, 685);
    glVertex2i(370, 640);
    glEnd();

    //top
    glBegin(GL_QUADS);
    glVertex2i(428, 683);
    glVertex2i(428, 695);
    glVertex2i(422, 695);
    glVertex2i(422, 683);
    glEnd();
}

void leftSoilPortion(int r, int g, int b)
{
    setColor(r, g, b); // green
    //main portion
    glBegin(GL_QUADS);
    glVertex2i(0, 245);
    glVertex2i(705, 245);
    glVertex2i(495, 700);
    glVertex2i(0, 700);
    glEnd();

    //lower shadow
    setColor(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0, 245);
    glVertex2i(0, 235);
    glVertex2i(705, 235);
    glVertex2i(705, 245);
    glEnd();

    /// left tree ///
    if(isDay)
    {
        leftTree(75, 175, 75);
    }
    else if(!isDay)
    {
        leftTree(40, 90, 40);
    }

    /// hay mound ///
    if(isDay)
    {
        hayMound(255,219,77);
    }
    else if(!isDay)
    {
        hayMound(153, 122, 61);
    }

    /// left house ///
    leftHouse();
}

void day()
{
    setClearColor(51,204,255, 255);
}

void night()
{
    setClearColor(0,0,0,255);
}

float sunPosition = 825.0f;

void sun()
{
    glPushMatrix();
    glTranslatef(0.0f, sunPosition, 0.0f);

    setColor(255, 255, 0);
    drawCircle(1250, 0, 45);

    glPopMatrix();
}

void moon()
{
    setColor(248,248,248);
    drawCircle(240, 845, 40);
    setColor(0,0,0);
    drawCircle(247, 848, 40);
}

float birdPosition = 0.0f;

void bird()
{
    if(isDay)
    {
        setColor(238,241,241);
    }
    else
    {
        setColor(105,105,105);
    }
    glPushMatrix();
    glTranslatef(birdPosition, 0.0f, 0.0f);
    /// bird 01
    // middle body
    glBegin(GL_TRIANGLES);
    glVertex2i(400, 800);
    glVertex2i(400, 840);
    glVertex2i(375, 815);
    glEnd();

    // neck
    glBegin(GL_TRIANGLES);
    glVertex2i(400, 818);
    glVertex2i(420, 818);
    glVertex2i(400, 800);
    glEnd();

    // head
    glBegin(GL_TRIANGLES);
    glVertex2i(420, 818);
    glVertex2i(425, 810);
    glVertex2i(415, 812);
    glEnd();

    // tail portion
    glBegin(GL_TRIANGLES);
    glVertex2i(375, 815);
    glVertex2i(400, 800);
    glVertex2i(350, 800);
    glEnd();

    // right wing
    glBegin(GL_TRIANGLES);
    glVertex2i(375, 815);
    glVertex2i(400, 840);
    glVertex2i(400, 865);
    glEnd();

    // left wing
    glBegin(GL_TRIANGLES);
    glVertex2i(375, 815);
    glVertex2i(388, 845);
    glVertex2i(372, 855);
    glEnd();

    /// bird 02
    int moveBirdX = 142, moveBirdY = 70;
    // middle body
    glBegin(GL_TRIANGLES);
    glVertex2i(400+moveBirdX, 800+moveBirdY);
    glVertex2i(400+moveBirdX, 840+moveBirdY);
    glVertex2i(375+moveBirdX, 815+moveBirdY);
    glEnd();

    // neck
    glBegin(GL_TRIANGLES);
    glVertex2i(400+moveBirdX, 818+moveBirdY);
    glVertex2i(420+moveBirdX, 818+moveBirdY);
    glVertex2i(400+moveBirdX, 800+moveBirdY);
    glEnd();

    // head
    glBegin(GL_TRIANGLES);
    glVertex2i(420+moveBirdX, 818+moveBirdY);
    glVertex2i(425+moveBirdX, 810+moveBirdY);
    glVertex2i(415+moveBirdX, 812+moveBirdY);
    glEnd();

    // tail portion
    glBegin(GL_TRIANGLES);
    glVertex2i(375+moveBirdX, 815+moveBirdY);
    glVertex2i(400+moveBirdX, 800+moveBirdY);
    glVertex2i(350+moveBirdX, 800+moveBirdY);
    glEnd();

    // right wing
    glBegin(GL_TRIANGLES);
    glVertex2i(375+moveBirdX, 815+moveBirdY);
    glVertex2i(400+moveBirdX, 840+moveBirdY);
    glVertex2i(400+moveBirdX, 865+moveBirdY);
    glEnd();

    // left wing
    glBegin(GL_TRIANGLES);
    glVertex2i(375+moveBirdX, 815+moveBirdY);
    glVertex2i(388+moveBirdX, 845+moveBirdY);
    glVertex2i(372+moveBirdX, 855+moveBirdY);
    glEnd();

    /// bird 03
    moveBirdX = 165, moveBirdY = 40;
    // middle body
    glBegin(GL_TRIANGLES);
    glVertex2i(400-moveBirdX, 800+moveBirdY);
    glVertex2i(400-moveBirdX, 840+moveBirdY);
    glVertex2i(375-moveBirdX, 815+moveBirdY);
    glEnd();

    // neck
    glBegin(GL_TRIANGLES);
    glVertex2i(400-moveBirdX, 818+moveBirdY);
    glVertex2i(420-moveBirdX, 818+moveBirdY);
    glVertex2i(400-moveBirdX, 800+moveBirdY);
    glEnd();

    // head
    glBegin(GL_TRIANGLES);
    glVertex2i(420-moveBirdX, 818+moveBirdY);
    glVertex2i(425-moveBirdX, 810+moveBirdY);
    glVertex2i(415-moveBirdX, 812+moveBirdY);
    glEnd();

    // tail portion
    glBegin(GL_TRIANGLES);
    glVertex2i(375-moveBirdX, 815+moveBirdY);
    glVertex2i(400-moveBirdX, 800+moveBirdY);
    glVertex2i(350-moveBirdX, 800+moveBirdY);
    glEnd();

    // right wing
    glBegin(GL_TRIANGLES);
    glVertex2i(375-moveBirdX, 815+moveBirdY);
    glVertex2i(400-moveBirdX, 840+moveBirdY);
    glVertex2i(400-moveBirdX, 865+moveBirdY);
    glEnd();

    // left wing
    glBegin(GL_TRIANGLES);
    glVertex2i(375-moveBirdX, 815+moveBirdY);
    glVertex2i(388-moveBirdX, 845+moveBirdY);
    glVertex2i(372-moveBirdX, 855+moveBirdY);
    glEnd();

    glPopMatrix();
}

float cloudPosition = 0.0f;

void clouds(int r, int g, int b)
{
    setColor(r,g,b);

    glPushMatrix();
    glTranslatef(cloudPosition, 0.0f, 0.0f);

    // cloud 01
    drawCircle(750, 835, 28);
    drawCircle(715, 835, 28);
    drawCircle(750, 870, 28);
    drawCircle(715, 870, 28);
    drawCircle(680, 852, 28);
    drawCircle(785, 852, 28);

    // cloud 02
    int moveCloudX = 350, moveCloudY = 55;
    drawCircle(750+moveCloudX, 835+moveCloudY, 24);
    drawCircle(715+moveCloudX, 835+moveCloudY, 23);
    drawCircle(750+moveCloudX, 870+moveCloudY, 24);
    drawCircle(715+moveCloudX, 870+moveCloudY, 24);
    drawCircle(680+moveCloudX, 852+moveCloudY, 24);
    drawCircle(785+moveCloudX, 852+moveCloudY, 24);

    // cloud 03
    moveCloudX = 200, moveCloudY = 30;
    drawCircle(750-moveCloudX, 835+moveCloudY, 25);
    drawCircle(715-moveCloudX, 835+moveCloudY, 25);
    drawCircle(750-moveCloudX, 870+moveCloudY, 25);
    drawCircle(715-moveCloudX, 870+moveCloudY, 25);
    drawCircle(680-moveCloudX, 852+moveCloudY, 25);
    drawCircle(785-moveCloudX, 852+moveCloudY, 25);

    glPopMatrix();
}

void distantTrees(int r, int g, int b)
{
    setColor(r, g, b);
    // tree 01
    glBegin(GL_POLYGON);
    glVertex2i(0, 700);
    glVertex2i(20, 730);
    glVertex2i(45, 750);
    glVertex2i(70, 730);
    glVertex2i(90, 700);
    glEnd();

    // tree 02
    glBegin(GL_POLYGON);
    glVertex2i(90, 700);
    glVertex2i(105, 715);
    glVertex2i(135, 730);
    glVertex2i(165, 730);
    glVertex2i(195, 715);
    glVertex2i(210, 700);
    glEnd();

    // tree 03
    glBegin(GL_POLYGON);
    glVertex2i(210, 700);
    glVertex2i(240, 740);
    glVertex2i(280, 768);
    glVertex2i(310, 780);
    glVertex2i(340, 768);
    glVertex2i(380, 740);
    glVertex2i(410, 700);
    glEnd();

    // tree 04
    glBegin(GL_POLYGON);
    glVertex2i(410, 700);
    glVertex2i(420, 720);
    glVertex2i(440, 740);
    glVertex2i(460, 750);
    glVertex2i(480, 740);
    glVertex2i(500, 720);
    glVertex2i(510, 700);
    glEnd();

    // tree 05
    glBegin(GL_POLYGON);
    glVertex2i(510, 700);
    glVertex2i(535, 740);
    glVertex2i(570, 755);
    glVertex2i(585, 765);
    glVertex2i(600, 755);
    glVertex2i(635, 740);
    glVertex2i(660, 700);
    glEnd();

    // tree 06
    glBegin(GL_POLYGON);
    glVertex2i(660, 700);
    glVertex2i(690, 750);
    glVertex2i(705, 770);
    glVertex2i(760, 790);
    glVertex2i(815, 770);
    glVertex2i(830, 750);
    glVertex2i(860, 700);
    glEnd();

    // tree 07
    int moveDisTreeX = 200, moveDisTreeY = 5;
    glBegin(GL_POLYGON);
    glVertex2i(660+moveDisTreeX, 700);
    glVertex2i(690+moveDisTreeX, 750-moveDisTreeY);
    glVertex2i(705+moveDisTreeX, 770-moveDisTreeY);
    glVertex2i(760+moveDisTreeX, 785-moveDisTreeY);
    glVertex2i(815+moveDisTreeX, 770-moveDisTreeY);
    glVertex2i(830+moveDisTreeX, 750-moveDisTreeY);
    glVertex2i(860+moveDisTreeX, 700);
    glEnd();

    // tree 08
    glBegin(GL_POLYGON);
    glVertex2i(1060, 700);
    glVertex2i(1105, 760);
    glVertex2i(1125, 760);
    glVertex2i(1170, 700);
    glEnd();

    // tree 09
    glBegin(GL_POLYGON);
    glVertex2i(1170, 700);
    glVertex2i(1185, 730);
    glVertex2i(1210, 745);
    glVertex2i(1250, 745);
    glVertex2i(1275, 730);
    glVertex2i(1290, 700);
    glEnd();

    // tree 10
    glBegin(GL_POLYGON);
    glVertex2i(1290, 700);
    glVertex2i(1320, 730);
    glVertex2i(1360, 755);
    glVertex2i(1395, 770);
    glVertex2i(1430, 755);
    glVertex2i(1470, 730);
    glVertex2i(1500, 700);
    glEnd();
}

float solarPlateAngle = 0.0f;

void solarPlate()
{
    glPushMatrix();
    glTranslatef(1348, 690, 0);
    glRotatef(solarPlateAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1348, -690, 0);

    // solar holder
    if(isDay)
    {
        setColor(7,7,0);
    }
    else if(!isDay)
    {
        setColor(5, 5, 0);
    }
    drawCircle(1348, 690, 12);

    //yellow plate holder
    // 01
    if(isDay)
    {
        setColor(255,255,0);
    }
    else if(!isDay)
    {
        setColor(150, 150, 30);
    }
    glBegin(GL_QUADS);
    glVertex2i(1345, 692);
    glVertex2i(1213, 712);
    glVertex2i(1213, 706);
    glVertex2i(1345, 687);
    glEnd();

    //02
    glBegin(GL_QUADS);
    glVertex2i(1343, 690);
    glVertex2i(1363, 822);
    glVertex2i(1369, 822);
    glVertex2i(1349, 687);
    glEnd();

    //03
    glBegin(GL_QUADS);
    glVertex2i(1348, 689);
    glVertex2i(1328, 559);
    glVertex2i(1334, 559);
    glVertex2i(1354, 689);
    glEnd();

    //04
    glBegin(GL_QUADS);
    glVertex2i(1354, 689);
    glVertex2i(1484, 669);
    glVertex2i(1484, 663);
    glVertex2i(1354, 683);
    glEnd();

    // maroon plates
    //01
    if(isDay)
    {
        setColor(128,0,0);
    }
    else if(!isDay)
    {
        setColor(64, 0, 0);
    }
    glBegin(GL_TRIANGLES);
    glVertex2i(1345, 692);
    glVertex2i(1213, 712);
    glVertex2i(1225, 772);
    glEnd();

    //02
    glBegin(GL_TRIANGLES);
    glVertex2i(1349, 687);
    glVertex2i(1369, 822);
    glVertex2i(1429, 810);
    glEnd();

    //03
    glBegin(GL_TRIANGLES);
    glVertex2i(1348, 689);
    glVertex2i(1328, 559);
    glVertex2i(1268, 571);
    glEnd();

    //04
    glBegin(GL_TRIANGLES);
    glVertex2i(1354, 683);
    glVertex2i(1484, 663);
    glVertex2i(1472, 603);
    glEnd();

    glPopMatrix();
}

void windSolar()
{
    // solar base
    if(isDay)
    {
        setColor(192,192,192);
    }
    else if(!isDay)
    {
        setColor(140, 140, 140);
    }
    glBegin(GL_POLYGON);
    glVertex2i(1293, 420);
    glVertex2i(1318, 630);
    glVertex2i(1343, 700);
    glVertex2i(1353, 700);
    glVertex2i(1378, 630);
    glVertex2i(1403, 420);
    glEnd();
}

void grass()
{
    if(isDay)
    {
        setColor(1,105,0);
    }
    else if(!isDay)
    {
        setColor(0, 85, 0);
    }
    // grass 01
    glBegin(GL_TRIANGLES);
    glVertex2i(20, 400);
    glVertex2i(50, 400);
    glVertex2i(35, 420);
    glEnd();

    // grass 02
    int moveGrassX = 50, moveGrassY = 50;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400-moveGrassY);
    glVertex2i(50+moveGrassX, 400-moveGrassY);
    glVertex2i(35+moveGrassX, 420-moveGrassY);
    glEnd();

    // grass 03
    moveGrassX = 100, moveGrassY = 80;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400+moveGrassY);
    glVertex2i(50+moveGrassX, 400+moveGrassY);
    glVertex2i(35+moveGrassX, 420+moveGrassY);
    glEnd();

    // grass 04
    moveGrassX = 150, moveGrassY = 30;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400+moveGrassY);
    glVertex2i(50+moveGrassX, 400+moveGrassY);
    glVertex2i(35+moveGrassX, 420+moveGrassY);
    glEnd();

    // grass 05
    moveGrassX = 256, moveGrassY = 47;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400+moveGrassY);
    glVertex2i(50+moveGrassX, 400+moveGrassY);
    glVertex2i(35+moveGrassX, 420+moveGrassY);
    glEnd();

    // grass 06
    moveGrassX = 485, moveGrassY = 36;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400+moveGrassY);
    glVertex2i(50+moveGrassX, 400+moveGrassY);
    glVertex2i(35+moveGrassX, 420+moveGrassY);
    glEnd();

    // grass 07
    moveGrassX = 357, moveGrassY = 6;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400-moveGrassY);
    glVertex2i(50+moveGrassX, 400-moveGrassY);
    glVertex2i(35+moveGrassX, 420-moveGrassY);
    glEnd();

     // grass 08
    moveGrassX = 437, moveGrassY = 58;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400-moveGrassY);
    glVertex2i(50+moveGrassX, 400-moveGrassY);
    glVertex2i(35+moveGrassX, 420-moveGrassY);
    glEnd();

     // grass 09
    moveGrassX = 1188, moveGrassY = 58;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400-moveGrassY);
    glVertex2i(50+moveGrassX, 400-moveGrassY);
    glVertex2i(35+moveGrassX, 420-moveGrassY);
    glEnd();

     // grass 10
    moveGrassX = 1352, moveGrassY = 72;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400-moveGrassY);
    glVertex2i(50+moveGrassX, 400-moveGrassY);
    glVertex2i(35+moveGrassX, 420-moveGrassY);
    glEnd();

     // grass 11
    moveGrassX = 1423, moveGrassY = 36;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400+moveGrassY);
    glVertex2i(50+moveGrassX, 400+moveGrassY);
    glVertex2i(35+moveGrassX, 420+moveGrassY);
    glEnd();

    // grass 12
    moveGrassX = 1050, moveGrassY = 11;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400+moveGrassY);
    glVertex2i(50+moveGrassX, 400+moveGrassY);
    glVertex2i(35+moveGrassX, 420+moveGrassY);
    glEnd();

    // grass 13
    moveGrassX = 1177, moveGrassY = 29;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400+moveGrassY);
    glVertex2i(50+moveGrassX, 400+moveGrassY);
    glVertex2i(35+moveGrassX, 420+moveGrassY);
    glEnd();

     // grass 14
    moveGrassX = 220, moveGrassY = 37;
    glBegin(GL_TRIANGLES);
    glVertex2i(20+moveGrassX, 400-moveGrassY);
    glVertex2i(50+moveGrassX, 400-moveGrassY);
    glVertex2i(35+moveGrassX, 420-moveGrassY);
    glEnd();
}

void rightSoilPortion(int r, int g, int b)
{
    setColor(r, g, b); // green
    //main portion
    glBegin(GL_QUADS);
    glVertex2i(1500, 285);
    glVertex2i(1035, 285);
    glVertex2i(835, 700);
    glVertex2i(1500, 700);
    glEnd();

    //lower shadow
    setColor(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(1500, 285);
    glVertex2i(1500, 276);
    glVertex2i(1030, 276);
    glVertex2i(1035, 285);
    glEnd();

    //side shadow
    setColor(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(835, 700);
    glVertex2i(1035, 285);
    glVertex2i(1030, 275);
    glVertex2i(830, 700);
    glEnd();

    /// right tree
    if(isDay)
    {
        rightTree(75, 175, 75);
    }
    else if(!isDay)
    {
        rightTree(40, 90, 40);
    }

    /// right house ///
    if(isDay)
    {
        rightHouse(47,79,79);
    }
    else if(!isDay)
    {
        rightHouse(30, 50, 50);
    }

    /// solar base ///
    windSolar();
}

void seaPortion()
{
    if(isDay)
    {
        setColor(38,154,214);
    }
    else if(!isDay)
    {
        setColor(15, 77, 107);
    }
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(1500, 0);
    glVertex2i(1500, 700);
    glVertex2i(0, 700);
    glEnd();
}

float boat01_PositionX = 0.0f, boat02_PositionX = 0.0f, boat03_Position = 0.0f;
float boat01_PositionY = 0.0f, boat02_PositionY = 0.0f;

void boat()
{
    /// boat 02
    glPushMatrix();
    glTranslatef(boat02_PositionX, boat02_PositionY, 0.0f);

    int moveBoatX = 300, moveBoatY = 120;
    // bottom part
    setColor(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(450-moveBoatX, 20+moveBoatY);
    glVertex2i(630-moveBoatX, 20+moveBoatY);
    glVertex2i(630-moveBoatX, 35+moveBoatY);
    glVertex2i(450-moveBoatX, 35+moveBoatY);
    glEnd();

    //lifted edges
    //left edge
    glBegin(GL_TRIANGLES);
    glVertex2i(450-moveBoatX, 20+moveBoatY);
    glVertex2i(450-moveBoatX, 35+moveBoatY);
    glVertex2i(405-moveBoatX, 45+moveBoatY);
    glEnd();
    //right edge
    glBegin(GL_TRIANGLES);
    glVertex2i(630-moveBoatX, 20+moveBoatY);
    glVertex2i(630-moveBoatX, 35+moveBoatY);
    glVertex2i(675-moveBoatX, 45+moveBoatY);
    glEnd();

    //boat entrance
    glBegin(GL_TRIANGLES);
    glVertex2i(630-moveBoatX, 35+moveBoatY);
    glVertex2i(630-moveBoatX-44, 35+moveBoatY);
    glVertex2i(630-moveBoatX-22, 35+moveBoatY+40);
    glEnd();

    // shade
    if(isDay)
    {
        setColor(139,69,19);
    }
    else if(!isDay)
    {
        setColor(90, 45, 15);
    }
    glBegin(GL_QUADS);
    glVertex2i(630-moveBoatX-22, 35+moveBoatY+40);
    glVertex2i(630-moveBoatX-44, 35+moveBoatY);
    glVertex2i(450-moveBoatX, 35+moveBoatY);
    glVertex2i(450-moveBoatX+30, 35+moveBoatY+40);
    glEnd();

    glPopMatrix();

    /// boat 01
    glPushMatrix();
    glTranslatef(boat01_PositionX, boat01_PositionY, 0.0f);

    // bottom part
    setColor(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(450, 20);
    glVertex2i(630, 20);
    glVertex2i(630, 35);
    glVertex2i(450, 35);
    glEnd();

    //lifted edges
    //left edge
    glBegin(GL_TRIANGLES);
    glVertex2i(450, 20);
    glVertex2i(450, 35);
    glVertex2i(405, 45);
    glEnd();
    //right edge
    glBegin(GL_TRIANGLES);
    glVertex2i(630, 20);
    glVertex2i(630, 35);
    glVertex2i(675, 45);
    glEnd();

    //boat entrance
    glBegin(GL_TRIANGLES);
    glVertex2i(450, 35);
    glVertex2i(494, 35);
    glVertex2i(472, 75);
    glEnd();

    // shade
    if(isDay)
    {
        setColor(139,69,19);
    }
    else if(!isDay)
    {
        setColor(90, 45, 15);
    }
    glBegin(GL_QUADS);
    glVertex2i(472, 75);
    glVertex2i(494, 35);
    glVertex2i(630, 35);
    glVertex2i(600, 75);
    glEnd();

    //main sail
    if(isDay)
    {
        setColor(255,99,71);
    }
    else if(!isDay)
    {
        setColor(128, 50, 35);
    }
    glBegin(GL_QUADS);
    glVertex2i(492, 75);
    glVertex2i(580, 75);
    glVertex2i(595, 130);
    glVertex2i(507, 130);
    glEnd();

    //top stick
    if(isDay)
    {
        setColor(139,69,19);
    }
    else if(!isDay)
    {
        setColor(90, 45, 15);
    }
    glBegin(GL_QUADS);
    glVertex2i(549, 130);
    glVertex2i(554, 130);
    glVertex2i(554, 145);
    glVertex2i(549, 145);
    glEnd();

    //boat 01 human
    //head
    setColor(0, 0, 0);
    drawCircle(643, 78, 7);
    //body
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(643, 45);
    glVertex2i(643, 75);
    glEnd();
    //legs
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(634, 30);
    glVertex2i(643, 45);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(652, 35);
    glVertex2i(643, 45);
    glEnd();

    //hands
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(652, 50);
    glVertex2i(643, 65);
    glEnd();

    // right hand
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(630, 60);
    glVertex2i(643, 65);
    glEnd();

    //stick
    if(isDay)
    {
        setColor(139,69,19);
    }
    else if(!isDay)
    {
        setColor(90, 45, 15);
    }
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2i(631, 70);
    glVertex2i(631, 35);
    glEnd();

    glPopMatrix();

    /// boat 03
    // bottom part
    moveBoatX = 32;
    glPushMatrix();
    glTranslatef(boat03_Position, 0.0f, 0.0f);

    setColor(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(625-moveBoatX, 550);
    glVertex2i(725-moveBoatX, 550);
    glVertex2i(725-moveBoatX, 558);
    glVertex2i(625-moveBoatX, 558);
    glEnd();

    //lifted edges
    //left edge
    glBegin(GL_TRIANGLES);
    glVertex2i(625-moveBoatX, 550);
    glVertex2i(625-moveBoatX, 558);
    glVertex2i(595-moveBoatX, 567);
    glEnd();
    //right edge
    glBegin(GL_TRIANGLES);
    glVertex2i(725-moveBoatX, 550);
    glVertex2i(725-moveBoatX, 558);
    glVertex2i(755-moveBoatX, 567);
    glEnd();

    glPopMatrix();
}

void stars()
{
    setColor(255, 255, 255);
    drawCircle(750, 850, 1);
    drawCircle(670, 800, 1);
    drawCircle(790, 880, 1);

    drawCircle(1400, 820, 1);
    drawCircle(1286, 860, 1);
    drawCircle(1480, 840, 1);

    drawCircle(150, 855, 1);
    drawCircle(280, 810, 1);
    drawCircle(70, 790, 1);

    drawCircle(590, 805, 1);
    drawCircle(1111, 844, 1);
    drawCircle(240, 833, 1);
}

void bridge()
{
    // surface
    if(isDay)
    {
       setColor(153,153,102);
    }
    else if(!isDay)
    {
        setColor(70, 70, 50);
    }
    glBegin(GL_QUADS);
    glVertex2i(600, 435);
    glVertex2i(975, 435);
    glVertex2i(1015, 355);
    glVertex2i(640, 355);
    glEnd();

    //left stairs
    glBegin(GL_QUADS);
    glVertex2i(602, 432);
    glVertex2i(549, 390);
    glVertex2i(585, 313);
    glVertex2i(640, 357);
    glEnd();

    //right stairs
    glBegin(GL_QUADS);
    glVertex2i(975, 433);
    glVertex2i(1042, 390);
    glVertex2i(1070, 323);
    glVertex2i(1013, 357);
    glEnd();

    // surface borders
    setColor(105, 105, 105);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(600, 433);
    glVertex2i(975, 433);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(640, 355);
    glVertex2i(1015, 355);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(600, 435);
    glVertex2i(640, 355);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(975, 433);
    glVertex2i(1015, 355);
    glEnd();

    //surface strips
    glBegin(GL_LINES);
    glVertex2i(675, 435);
    glVertex2i(715, 355);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(750, 435);
    glVertex2i(790, 355);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(825, 435);
    glVertex2i(865, 355);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(900, 435);
    glVertex2i(940, 355);
    glEnd();

    //left stair strips
    // 1st stair
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(558, 398);
    glVertex2i(597, 323);
    glEnd();

    // 2nd stair
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(572, 410);
    glVertex2i(612, 336);
    glEnd();

    // 3rd stair
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(588, 420);
    glVertex2i(627, 348);
    glEnd();

    //right stair strips
    //1st stair
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(1025, 401);
    glVertex2i(1054, 334);
    glEnd();

    //2nd stair
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(1009, 412);
    glVertex2i(1039, 343);
    glEnd();

    //3rd stair
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(992, 423);
    glVertex2i(1026, 349);
    glEnd();

    //left upper stick
    setColor(40, 50, 60);
    glLineWidth(2);
    glBegin(GL_QUADS);
    glVertex2i(604, 433);
    glVertex2i(604, 515);
    glVertex2i(600, 515);
    glVertex2i(600, 430);
    glEnd();

    //left lower stick
    glBegin(GL_QUADS);
    glVertex2i(642, 335);
    glVertex2i(642, 455);
    glVertex2i(638, 455);
    glVertex2i(638, 335);
    glEnd();

    //right upper stick
    glBegin(GL_QUADS);
    glVertex2i(975, 433);
    glVertex2i(975, 515);
    glVertex2i(971, 515);
    glVertex2i(971, 433);
    glEnd();

    //right lower stick
    glBegin(GL_QUADS);
    glVertex2i(1015, 330);
    glVertex2i(1015, 455);
    glVertex2i(1011, 455);
    glVertex2i(1011, 330);
    glEnd();
}

void keyboard(unsigned char key, int x, int y)
{
   switch(key)
   {
       case 'D':
       case 'd':
            _sun = true;
            break;
       case 'N':
       case 'n':
            _sun = false;
            break;
       case 27:
            exit(0);
       default:
            break;
   }
}

bool boatLeft = true, boatRight = false;

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
      case GLUT_KEY_LEFT:
          boatLeft = true;
          boatRight = false;
          break;
      case GLUT_KEY_RIGHT:
          boatRight = true;
          boatLeft = false;
          break;
    }
}

bool isPlayingDayMusic = false;
bool isPlayingNightMusic = false;

void updateMusic()
{
    if (isDay && !isPlayingDayMusic)
    {
        sndPlaySound(NULL, SND_ASYNC);
        sndPlaySound("day.wav", SND_ASYNC | SND_LOOP);
        isPlayingDayMusic = true;
        isPlayingNightMusic = false;
    }
    else if (!isDay && !isPlayingNightMusic)
    {
        sndPlaySound(NULL, SND_ASYNC);
        sndPlaySound("night.wav", SND_ASYNC | SND_LOOP);
        isPlayingNightMusic = true;
        isPlayingDayMusic = false;
    }
}

void display()
{
    /// day or night ///
    if(isDay)
    {
        day();
    }
    else if(!isDay)
    {
        night();
    }

    glClear(GL_COLOR_BUFFER_BIT);

    /// sea ///
    seaPortion();

    /// sun ///
    sun();

    /// moon & starts ///
    if(!isDay)
    {
        stars();
        moon();
    }

    /// distant trees ///
    if(isDay)
    {
        distantTrees(34,139,34);
    }
    else if(!isDay)
    {
        distantTrees(30, 70, 30);
    }

    /// left soil ///
    if(isDay)
    {
        leftSoilPortion(102, 204, 51);
    }
    else if(!isDay)
    {
        leftSoilPortion(51, 102, 51);
    }

    /// right soil ///
    if(isDay)
    {
        rightSoilPortion(102, 204, 51);
    }
    else if(!isDay)
    {
        rightSoilPortion(51, 102, 51);
    }

    /// boats ///
    boat();

    /// grass ///
    grass();

    /// bridge ///
    bridge();

    /// clouds ///
    if(isDay)
    {
        clouds(255,255,255);
    }
    else
    {
        clouds(105,105,105);
    }

    /// birds ///
    bird();

    /// solar plates ///
    solarPlate();

    /// music ///
    updateMusic();

    glFlush();
    glutSwapBuffers();
}

void updateBirds(int value)
{
    if (isDay)
    {
        birdPosition += 4.5f;
        if (birdPosition > 1500.0f)
        {
            birdPosition = -1150.0f;
        }
    }
    else
    {
        // allowing to go out of screen.
        birdPosition += 4.5f;
        // stopping to reappear once go out of screen.
        if (birdPosition > 1500.0f)
        {
            birdPosition = 1500.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateBirds, 0);
}

void updateClouds(int value)
{
    cloudPosition += 1.5f;

    if (cloudPosition > 1500.0f)
    {
        cloudPosition = -1150.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(15, updateClouds, 0);
}

void updateSun(int value)
{
    if(_sun)
    {
        // sunrise
        if(sunPosition < 825.0f)
        {
            sunPosition += 1.0f;
            if(sunPosition == 692.0f)
            {
                isDay = true;
            }
            if(sunPosition > 825.0f)
            {
                sunPosition = 825.0f;
            }
        }
    }
    else
    {
        // sunset
        if(sunPosition > 620.0f)
        {
            sunPosition -= 1.0f;
            if(sunPosition == 690.0f)
            {
                isDay = false;
            }
            if(sunPosition < 620.0f)
            {
                sunPosition = 620.0f;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, updateSun, 0);
}

void updateBoats(int value)
{
    // boat 01 update
    if(isDay) // Day time.
    {
        // moving horizontally.
        boat01_PositionX -= 3.5f;
        if (boat01_PositionX < -680.0f)
        {
            boat01_PositionX = 1150.0f;
        }
        // lowering boat if it was raised last night.
        if (boat01_PositionY > 0.0f)
        {
            boat01_PositionY -= 2.0f;
            if (boat01_PositionY < 0.0f)
            {
                boat01_PositionY = 0.0f;
            }
        }
    }
    else if(!isDay) // Night time.
    {
        // moving horizontally and vertically until reaches +145 pixel.
        if (boat01_PositionY < 145.0f)
        {
            boat01_PositionX -= 1.5f;
            boat01_PositionY += 2.0f;

            // stopping boat once it reaches target.
            if (boat01_PositionY >= 145.0f)
            {
                boat01_PositionY = 145.0f;
                boat01_PositionX = boat01_PositionX; // keeping last position to continue from here.
            }
        }
    }

    // boat 02 update
    if(isDay) // day time.
    {
        // moving horizontally/
        boat02_PositionX += 2.0f;
        if (boat02_PositionX > 1500.0f)
        {
            boat02_PositionX = -400.0f;
        }

        // lowering boat if it was raised last night.
        if (boat02_PositionY > 0.0f)
        {
            boat02_PositionY -= 1.5f;
            if (boat02_PositionY < 0.0f)
            {
                boat02_PositionY = 0.0f;
            }
        }
    }
    else if(!isDay) // night time.
    {
        // moving horizontally and vertically until reaches +45 pixel.
        if (boat02_PositionY < 45.0f)
        {
            boat02_PositionX += 2.0f;
            boat02_PositionY += 1.5f;

            // stopping boat once it reaches target.
            if (boat02_PositionY >= 45.0f)
            {
                boat02_PositionY = 45.0f;
                boat02_PositionX = boat02_PositionX;  // keeping last position to continue from here.
            }
        }
    }

    // boat 03 update
    if (boatRight && !boatLeft)
    {
        boat03_Position += 1.8f;
        if (boat03_Position > 165.0f)
        {
            boat03_Position = 165.0f;
        }
    }
    else if (boatLeft && !boatRight)
    {
        boat03_Position -= 1.8f;
        if (boat03_Position < 0.0f)
        {
            boat03_Position = 0.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateBoats, 0);
}

void updateSolarPlate(int value)
{
    solarPlateAngle -= 1.0f;
    if (solarPlateAngle <= -360.0f)
    {
        solarPlateAngle += 360.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(25, updateSolarPlate, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1500, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Village");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(15, updateClouds, 0);
    glutTimerFunc(20, updateBirds, 0);
    glutTimerFunc(20, updateBoats, 0);
    glutTimerFunc(25, updateSolarPlate, 0);
    glutTimerFunc(25, updateSun, 0);
    glutMainLoop();
    return 0;
}
