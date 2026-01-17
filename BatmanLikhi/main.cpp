#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

//DRAW LINES
void lines()
{
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.70f, 0.0f, 0.0f);

     //VERTICAL LINES
    for(int x = 0; x<=330; x+=10)
    {
        glVertex2f(x,0);
        glVertex2f(x,250);
    }

    //HORIZONTAL LINE
    for(int y = 0; y<=250; y+=10)
    {
        glVertex2f(0,y);
        glVertex2f(330,y);
    }

    glEnd();

}

//DRAW CENTRAL BLACKBOX OF BATBODY
void blackbox()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    // MIDDLE BLACKBOX
    glVertex2f(80, 10);
    glVertex2f(260, 10);
    glVertex2f(260, 240);
    glVertex2f(80, 240);

   // RIGHT SIDE
    for (int x = 250, y = 10; x < 320; x += 10, y += 10)
    {
        glVertex2f(x, y);
        glVertex2f(x + 10, y);
        glVertex2f(x + 10, 250 - y);
        glVertex2f(x, 250 - y);
    }

    // LEFT SIDE
    for (int x = 80, y = 10; x > 10; x -= 10, y += 10)
    {
        glVertex2f(x, 250 - y);
        glVertex2f(x - 10, 250 - y);
        glVertex2f(x - 10, y);
        glVertex2f(x, y);
    }

    glEnd();
}

    //YELLOW DETAILS

void yellow()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);

    // LEFT SIDE UP
    for (int x = 20, y = 160; x < 80; x += 10, y += 10)
    {
        glVertex2f(x, y);
        glVertex2f(x + 10, y);
        glVertex2f(x + 10, y + 20);
        glVertex2f(x, y + 20);
    }

    // LEFT SIDE DOWN

    for (int x = 80, y = 20; x > 20; x -= 10, y += 10)
    {
        glVertex2f(x, y);
        glVertex2f(x - 10, y);
        glVertex2f(x - 10, y + 20);
        glVertex2f(x, y + 20);
    }

    // RIGHT SIDE UP
    for (int x = 310, y = 160; x > 250; x -= 10, y += 10)
    {
        glVertex2f(x, y);
        glVertex2f(x - 10, y);
        glVertex2f(x - 10, y + 20);
        glVertex2f(x, y + 20);
    }

    // RIGHT SIDE DOWN

    for (int x = 300, y = 70; x > 240; x -= 10, y -= 10)
    {
        glVertex2f(x, y);
        glVertex2f(x + 10, y);
        glVertex2f(x + 10, y + 20);
        glVertex2f(x, y + 20);
    }

    // RIGHT LINE
    glVertex2f(300, 160);
    glVertex2f(310, 160);
    glVertex2f(310, 80);
    glVertex2f(300, 80);

     // LEFT LINE
    glVertex2f(20, 160);
    glVertex2f(30, 160);
    glVertex2f(30, 80);
    glVertex2f(20, 80);

    // LOWER LINE
    glVertex2f(80, 30);
    glVertex2f(80, 20);
    glVertex2f(250, 20);
    glVertex2f(250, 30);

    // UPPER LINE
    glVertex2f(80, 220);
    glVertex2f(80, 230);
    glVertex2f(250, 230);
    glVertex2f(250, 220);



     //YELLLOW 2 LOW-RIGHT
    glVertex2f(160, 40);
    glVertex2f(160, 30);
    glVertex2f(100, 30);
    glVertex2f(100, 40);


    glVertex2f(150, 40);
    glVertex2f(150, 50);
    glVertex2f(100, 50);
    glVertex2f(100, 40);

    glVertex2f(150,60);
    glVertex2f(150, 50);
    glVertex2f(110, 50);
    glVertex2f(110, 60);

    glVertex2f(130,60);
    glVertex2f(130, 70);
    glVertex2f(120, 70);
    glVertex2f(120, 60);


    //YELLOW 3
    glVertex2f(170, 40);
    glVertex2f(170, 30);
    glVertex2f(230, 30);
    glVertex2f(230, 40);

    glVertex2f(180, 40);
    glVertex2f(180, 50);
    glVertex2f(230, 50);
    glVertex2f(230, 40);

    glVertex2f(180,60);
    glVertex2f(180, 50);
    glVertex2f(220, 50);
    glVertex2f(220, 60);

    glVertex2f(210,60);
    glVertex2f(210, 70);
    glVertex2f(200, 70);
    glVertex2f(200, 60);

     glVertex2f(250, 40);
    glVertex2f(250, 30);
    glVertex2f(240, 30);
    glVertex2f(240, 40);



    //UPPER YELLOW BOXES 1
    glVertex2f(80, 220);
    glVertex2f(80, 210);
    glVertex2f(140, 210);
    glVertex2f(140, 220);


    glVertex2f(110, 210);
    glVertex2f(110, 200);
    glVertex2f(140, 200);
    glVertex2f(140, 210);

    glVertex2f(90, 200);
    glVertex2f(90, 170);
    glVertex2f(140, 170);
    glVertex2f(140, 200);

    glVertex2f(100, 170);
    glVertex2f(100, 160);
    glVertex2f(130, 160);
    glVertex2f(130, 170);

    //UPPER MID
    glVertex2f(180, 220);
    glVertex2f(180, 210);
    glVertex2f(150, 210);
    glVertex2f(150, 220);


    glVertex2f(190, 220);
    glVertex2f(190, 210);
    glVertex2f(260, 210);
    glVertex2f(260, 220);

    glVertex2f(190, 200);
    glVertex2f(190, 210);
    glVertex2f(220, 210);
    glVertex2f(220, 200);

    glVertex2f(240, 200);
    glVertex2f(240, 170);
    glVertex2f(190, 170);
    glVertex2f(190, 200);

    glVertex2f(230, 160);
    glVertex2f(230, 170);
    glVertex2f(200, 170);
    glVertex2f(200, 160);



    glEnd();


}


void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    gluOrtho2D(0, 330, 0, 250);

    blackbox();
    yellow();

    lines();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(30, 20);
    glutCreateWindow("BatMan Logo");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
