#include <GL/gl.h>
#include <math.h>
#include <GL/glut.h>


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

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -40.0, 40.0);
}

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

void keyboard(unsigned char key, int x, int y)

{


    if (key == 'n' || key == 'N')
    {
        isNightr = 1;
    }
    else if (key == 'd' || key == 'D')
    {
        isNightr = 0;
    }

 else if (key == 'c' || key == 'C')


    {
        isCarMovingr =!isCarMovingr ;
    }

else if (key=='b' || key=='B')

     {
        isBusMovingr =!isBusMovingr ;
    }

else if (key=='s' || key=='S')

     {
        isSunMovingr =!isSunMovingr ;
    }
    glutPostRedisplay();
}






void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        isShipMovingr = !isShipMovingr;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Day and Night Scene");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}


