 #include <GL/gl.h>
 #include <math.h>
#include <GL/glut.h>


float tx = 0.0;
float rx = 0.0;
float bx = 0.0;
float busTx = 0.0;

int isNight = 0;
int isShipMoving = 1;
int isCarMoving = 1;
int isBusMoving=1;
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
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

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -40.0, 40.0);
}

void sky()
{
    glBegin(GL_QUADS);
    if (isNight)
        glColor3f(0.0f, 0.0f, 0.1f);
    else
        glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(-50, 50);
    glVertex2f(50, 50);
    glVertex2f(50, 7);
    glVertex2f(-50, 7);
    glEnd();
}

 void building() {

    glColor3f(0.1, 0.1, 0);
    glBegin(GL_QUADS);
    glVertex2f(-10, 7);
    glVertex2f(10, 7);
    glVertex2f(10, 30);
    glVertex2f(-10, 30);
    glEnd();

    if (isNight)
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
 void sun()
 {



  if (isNight)

        {

        glColor3f(0.9, 0.9, 0.9);
        circle(5, 5, -35, 40);
    }
    else


    {

        glColor3f(1.0, 1.0, 0.0);
        circle(5, 5, 35, 40);
    }
}
void building2()
{

glColor3f(0.1, 0.1, 0);
glBegin(GL_QUADS);
glVertex2f(12, 7);
glVertex2f(25, 7);
glVertex2f(25, 35);
glVertex2f(12, 35);
glEnd();


if (isNight)
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
void blboard()
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




    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(26.5, 22.5);
    const char* text = "London Bridge";
    for (const char* c = text; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void road()
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

void clouds()
{
    glPushMatrix();
    glTranslatef(rx, 0, 0);

    if (isNight)
        glColor3f(0.5, 0.5, 0.5);
    else
        glColor3f(1.0, 1.0, 1.0);

    circle(4, 4, -30, 30);
    circle(5, 5, -26, 30);
    circle(4, 4, -22, 30);

    circle(4, 4, 10, 35);
    circle(5, 5, 14, 35);
    circle(4, 4, 18, 35);

    circle(3, 3, 30, 25);
    circle(4, 4, 33, 25);
    circle(3, 3, 36, 25);

    glPopMatrix();

    rx += 0.01;
    if (rx > 90)
    {
        rx = -90;
    }

    glutPostRedisplay();
}

void car()
{
    glPushMatrix();
    glTranslatef(tx, 0, 0);

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
    circle(3, 3, -6, -2.5);
    circle(3, 3, 6, -2.5);

    glColor3f(0.5, 0.5, 0.5);
    circle(1.5, 1.5, -6, -2.5);
    circle(1.5, 1.5, 6, -2.5);

    glPopMatrix();

if (isCarMoving)
{

    tx -= 0.04;
    if (tx < -70)
    {
        tx = 70;
    }
}
    glutPostRedisplay();
}



    void bus() {
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
    circle(3, 3, -10, 2);
    circle(3, 3, 10, 2);


    glColor3f(0.5, 0.5, 0.5);
    circle(1.5, 1.5, -10, 2);
    circle(1.5, 1.5, 10, 2);

    glPopMatrix();
if (isBusMoving)
{


    busTx += 0.02;
    if (busTx >70)
        {
        busTx =- 70;
      }
}
    glutPostRedisplay();
}




void river()
{
    glBegin(GL_QUADS);
    if (isNight)
        glColor3f(0.0, 0.0, 0.3);
    else
        glColor3f(0.0, 0.5, 1.0);
    glVertex2f(-50, -17);
    glVertex2f(50, -17);
    glVertex2f(50, -50);
    glVertex2f(-50, -50);
    glEnd();
}

void grass()
{

    if (isNight)
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


void tree()
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

void ship()
{
    glPushMatrix();
    glTranslatef(bx, 0, 0);
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
     if (isShipMoving)
    {
        bx += 0.01;
        if (bx > 70)
        {
            bx = -70;
        }
    }

    glutPostRedisplay();
}





void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    sun();
    clouds();
     building();
      building2();
      blboard();
    road();
    bus();
    car();
    grass();
    tree();
    river();
    ship();
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)

{


    if (key == 'n' || key == 'N')
    {
        isNight = 1;
    }
    else if (key == 'd' || key == 'D')
    {
        isNight = 0;
    }

 else if (key == 'c' || key == 'C')


    {
        isCarMoving =!isCarMoving ;
    }

else if (key=='b' || key=='B')
{
     {
        isBusMoving =!isBusMoving ;
    }
}

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        isShipMoving = !isShipMoving;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Day and Night Scene");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

