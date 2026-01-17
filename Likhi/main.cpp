#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
#include<string.h>
#include<windows.h>
float  tx = 10, bx = 10, rx = 10;
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
   glBegin(GL_POLYGON);
   glVertex2f(cx, cy);
   for (int i = 0; i <= 360; i++)
   {
       float angle = i * 3.1416 / 180;
       float x = rx * cos(angle);
       float y = ry * sin(angle);
       glVertex2f((x + cx), (y + cy));
   }
   glEnd();
}
void round(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
   glBegin(GL_POLYGON);
   glVertex2f(cx, cy);
   for (int i = 0; i <= 360; i++)
   {
       float angle = i * 3.1416 / 180;
       float x = rx * cos(angle);
       float y = ry * sin(angle);
       glVertex2f((x + cx), (y + cy));
   }
   glEnd();
}
void init(void)
{
   glClearColor(0.0f, 0.90f, 0.90f, 0.0f);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0, 500, 0, 500);
}
void road()
{
   glColor3f(0.0f, 0.50f, 0.0f);
   glBegin(GL_POLYGON);
   glVertex2i(0, 0);
   glVertex2i(500, 0);
   glVertex2i(500, 75);
   glVertex2i(0, 75);
   glEnd();
   glColor3f(0.69f, 0.611f, 0.85f);
   glBegin(GL_POLYGON);
   glVertex2i(450, 75);
   glVertex2i(500, 75);
   glVertex2i(500, 300);
   glVertex2i(450, 300);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(460, 280);
   glVertex2i(465, 280);
   glVertex2i(465, 290);
   glVertex2i(460, 290);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(460, 260);
   glVertex2i(465, 260);
   glVertex2i(465, 270);
   glVertex2i(460, 270);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(460, 240);
   glVertex2i(465, 240);
   glVertex2i(465, 250);
   glVertex2i(460, 250);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(460, 220);
   glVertex2i(465, 220);
   glVertex2i(465, 230);
   glVertex2i(460, 230);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(460, 200);
   glVertex2i(465, 200);
   glVertex2i(465, 210);
   glVertex2i(460, 210);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(460, 180);
   glVertex2i(465, 180);
   glVertex2i(465, 190);
   glVertex2i(460, 190);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(460, 160);
   glVertex2i(465, 160);
   glVertex2i(465, 170);
   glVertex2i(460, 170);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(480, 280);
   glVertex2i(485, 280);
   glVertex2i(485, 290);
   glVertex2i(480, 290);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(480, 260);
   glVertex2i(485, 260);
   glVertex2i(485, 270);
   glVertex2i(480, 270);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(480, 240);
   glVertex2i(485, 240);
   glVertex2i(485, 250);
   glVertex2i(480, 250);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(480, 220);
   glVertex2i(485, 220);
   glVertex2i(485, 230);
   glVertex2i(480, 230);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(480, 200);
   glVertex2i(485, 200);
   glVertex2i(485, 210);
   glVertex2i(480, 210);
   glEnd();
    glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(480, 180);
   glVertex2i(485, 180);
   glVertex2i(485, 190);
   glVertex2i(480, 190);
   glEnd();
    glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(480, 180);
   glVertex2i(485, 180);
   glVertex2i(485, 190);
   glVertex2i(480, 190);
   glEnd();

   glColor3f(0.0f, 0.0f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2i(480, 160);
   glVertex2i(485, 160);
   glVertex2i(485, 170);
   glVertex2i(480, 170);
   glEnd();

   glColor3f(1.0f, 1.0f, 1.0f);
   glBegin(GL_POLYGON);
   glVertex2i(0, 0);
   glVertex2i(500, 0);
   glVertex2i(500, 55);
   glVertex2i(0, 55);
   glEnd();
   glColor3f(0.41f, 0.41f, 0.41f);
   glBegin(GL_POLYGON);
   glVertex2i(0, 0);
   glVertex2i(500, 0);
   glVertex2i(500, 50);
   glVertex2i(0, 50);
   glEnd();
}
void building()
{
   glColor3f(1.0f, 1.0f, 0.0f);
   circle(20, 30, 450, 450);
}
void tree()
{
 glColor3f(0.46f, 0.36f, 0.28f);
   glBegin(GL_POLYGON);
   glVertex2i(40,80);
   glVertex2i(50,80);
   glVertex2i(50, 250);
   glVertex2i(40,250);
   glEnd();
   glColor3f(0.0f, 0.27f, 0.0f);
   glBegin(GL_TRIANGLES);
   glVertex2i(10,230);
   glVertex2i(80,230);
   glVertex2i(45,275 );
   glColor3f(0.0f, 0.36f, 0.0f);
   glBegin(GL_TRIANGLES);
   glVertex2i(15,255);
   glVertex2i(75,255);
   glVertex2i(45,290 );
    glColor3f(0.0f, 0.48f, 0.0f);
   glBegin(GL_TRIANGLES);
   glVertex2i(23,280);
   glVertex2i(65,280);
   glVertex2i(45,305 );
}
void clouds2()
{
   glPushMatrix();
   glTranslatef(rx, 0, 0);
   glColor3f(0.86f, 0.86f, 0.86f);
   circle(20, 30, 460, 460);
   circle(15, 20, 445, 460);
   circle(15, 20, 475, 460);
   circle(20, 30, 390, 420);
   circle(15, 20, 405, 420);
   circle(15, 20, 375, 420);
   glPopMatrix();
   rx -= 0.01;
   if (rx > 500)
       rx = -500;
   glutPostRedisplay();
}
void car() {
   glPushMatrix();
   glTranslatef(tx, 0, 0);
   glColor3f(1.0f, 0.0f, 0.0f);
   glBegin(GL_POLYGON);
   glVertex2i(410, 40);
   glVertex2i(490, 40);
   glVertex2i(485, 70);
   glVertex2i(410, 70);
   glEnd();
   glColor3f(0.0f, 1.0f, 1.0f);
   glBegin(GL_POLYGON);
   glVertex2i(420, 70);
   glVertex2i(475, 70);
   glVertex2i(465, 100);
   glVertex2i(430, 100);
   glEnd();
   glColor3f(0.86f, 0.86f, 0.86f);
   glBegin(GL_POLYGON);
   glVertex2i(425, 70);
   glVertex2i(445, 70);
   glVertex2i(445, 90);
   glVertex2i(430, 90);
   glEnd();
   glColor3f(0.86f, 0.86f, 0.86f);
   glBegin(GL_POLYGON);
   glVertex2i(450, 70);
   glVertex2i(470, 70);
   glVertex2i(465, 90);
   glVertex2i(450, 90);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.0f);
   circle(10, 14, 435, 40);
   circle(10, 14, 465, 40);
   glColor3f(0.96f, 0.96f, 0.96f);
   circle(6, 10, 435, 40);
   circle(6, 10, 465, 40);
   glPopMatrix();
   tx += 0.3;
   if (tx > 500)
       tx = -500;
   glutPostRedisplay();
}
void roadLight()
{
   glColor3f(0.0f, 0.0f, 0.0f);
   glBegin(GL_POLYGON);
   glVertex2i(80, 50);
   glVertex2i(85, 50);
   glVertex2i(85, 200);
   glVertex2i(80, 200);
   glEnd();
   glBegin(GL_POLYGON);
   glVertex2i(85, 185);
   glVertex2i(125, 185);
   glVertex2i(125, 190);
   glVertex2i(85, 190);
   glEnd();
   glColor3f(1.0f, 1.0f, 1.0f);
   circle(10, 15, 130, 180);
   glColor3f(0.0f, 0.0f, 0.0f);
   glBegin(GL_POLYGON);
   glVertex2i(330, 50);
   glVertex2i(335, 50);
   glVertex2i(335, 190);
   glVertex2i(330, 190);
   glEnd();
   glColor3f(0.0f, 0.0f, 0.0f);
   glBegin(GL_POLYGON);
   glVertex2i(80, 50);
   glVertex2i(85, 50);
   glVertex2i(85, 180);
   glVertex2i(80, 180);
   glEnd();
   glBegin(GL_POLYGON);
   glVertex2i(330, 190);
   glVertex2i(375, 190);
   glVertex2i(375, 195);
   glVertex2i(330, 195);
   glColor3f(1.0f, 1.0f, 1.0f);
   circle(10, 15, 380, 150);
   glEnd();

}
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.12f, 0.56f, 1.0f);
   glBegin(GL_POLYGON);
   glVertex2i(0, 0);
   glVertex2i(500, 0);
   glVertex2i(500, 500);
   glVertex2i(0, 500);
   glEnd();
   glColor3f(0.0f, 1.0f, 0.0f);
   glBegin(GL_POLYGON);
   glVertex2i(0, 0);
   glVertex2i(500, 0);
   glVertex2i(500, 180);
   glVertex2i(0, 180);
   glEnd();
   road();
   tree();
   roadLight();
   car();
   clouds2();
   glFlush();
   glutSwapBuffers();
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(900, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Animation");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}

