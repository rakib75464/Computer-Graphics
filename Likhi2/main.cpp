#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float angle1=0.0f;
float ship1TranslationX = 0.0f;
float ship2TranslationX = 0.0f;
float ship1TranslationY = 0.0f;
float ship2TranslationY = 0.0f;
bool moveShip = false;

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
void sun2() {
    circle(1.5, 43.7, 36.0f, 252, 252, 3);
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
void ship1Window(float translationX, float translationY){
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
    ship1Window(0.0f+ translationX,0.0f+ translationY);
    ship1Window(-3.5f+ translationX,0.0f+ translationY);
    ship1Window(-7.0f+ translationX,0.0f+ translationY);
    ship1Window(-10.5f+ translationX,0.0f+ translationY);
    ship1Window(-14.0f+ translationX,0.0f+ translationY);
    ship1Window(-17.5f+ translationX,0.0f+ translationY);
    glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(25.0f + translationX, 2.0f + translationY);
    glVertex2f(25.0f + translationX, 6.0f + translationY);
    glVertex2f(23.8f + translationX, 6.0f + translationY);
    glVertex2f(22.4f + translationX, 2.0f + translationY);
    glEnd();
    //layer2
    ship1Window(-1.5f + translationX,8.0f+ translationY);
    ship1Window(-5.0f+ translationX,8.0f+ translationY);
    ship1Window(-8.5f+ translationX,8.0f+ translationY);
    ship1Window(-12.0f+ translationX,8.0f+ translationY);
    ship1Window(-15.5f+ translationX,8.0f+ translationY);
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
    ship1Window(0.0f+ translationX,0.0f+ translationY);
    ship1Window(-3.5f+ translationX,0.0f+ translationY);
    ship1Window(-7.0f+ translationX,0.0f+ translationY);
    ship1Window(-10.5f+ translationX,0.0f+ translationY);
    ship1Window(-14.0f+ translationX,0.0f+ translationY);
    ship1Window(-17.5f+ translationX,0.0f+ translationY);
    glBegin(GL_POLYGON);
    glColor3ub(216,237,240);
    glVertex2f(25.0f + translationX, 2.0f + translationY);
    glVertex2f(25.0f + translationX, 6.0f + translationY);
    glVertex2f(23.8f + translationX, 6.0f + translationY);
    glVertex2f(22.4f + translationX, 2.0f + translationY);
    glEnd();
    //layer2
    ship1Window(-1.5f + translationX,8.0f+ translationY);
    ship1Window(-5.0f+ translationX,8.0f+ translationY);
    ship1Window(-8.5f+ translationX,8.0f+ translationY);
    ship1Window(-12.0f+ translationX,8.0f+ translationY);
    ship1Window(-15.5f+ translationX,8.0f+ translationY);
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

void displayScene3Morning() {
    glClear(GL_COLOR_BUFFER_BIT);

        skyMorning();
        sun2();
     river1();

    ship1SideView(ship1TranslationX - 0.0f,ship1TranslationY-0.0f);
    ship2SideView(ship2TranslationX -0.0f, ship2TranslationY -0.0f);


    river2();
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
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
