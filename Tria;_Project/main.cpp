#include<windows.h>
#include<mmsystem.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
# define PI 3.14159265358979323846
#define ESCAPE 27

#define HIGH 1
#define LOW 0.2

#define RED 0
#define YELLOW 1
#define GREEN 2

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

using namespace std;
int triangleAmount = 1000;
GLfloat twicePi = 2.0f * PI;
GLfloat position = 0.0f; /// boat position
GLfloat position2 = 0.0f;/// boat position
GLfloat position3 = 0.0f;/// boat position
GLfloat sunposition=0.0f;
GLfloat sunposition0=0.0f;
GLfloat moonposition1=0.0f;
GLfloat moonposition=0.0f;
GLfloat positionbus1=0.0f;
GLfloat positionbus2=0.0f;
GLfloat positionbus3=0.0f;
GLfloat positionbus4=0.0f;
GLfloat boatspeed1 = 0.02f;
GLfloat boatspeed = 0.01f;
GLfloat boatspeed2 = 0.014f;
GLfloat speed = 0.01f;  /// wave speed
GLfloat speed1 = 0.02f; /// vehicles speed
GLfloat speed2 = 0.012f;/// vehicles speed
GLfloat speed3=0.02f;/// vehicles speed
GLfloat speed5=0.02f;/// vehicles speed
GLfloat speed4 = 0.00f; ///  view shifting speed
GLfloat i = 0.0f;
GLfloat position11 = 0.0f; /// clouds & plane
GLfloat speed11 = 0.05f;
GLfloat speed44 = 0.00f; /// day night time update
GLfloat huposition1= 0.0f; /// human position
GLfloat huposition2= 0.0f;
GLfloat huspeed = 0.01f;
GLfloat sunspeed=0.000f;
GLfloat sunspeed0=0.0001f;
GLfloat moonspeed1=0.000f;
GLfloat moonspeed=0.000f;
GLfloat w=0.0f;
GLfloat wspeed=0.000f;
GLfloat mposition1=0.0f;
GLfloat mspeed1=0.00f;
GLfloat mposition2=0.0f;
GLfloat mspeed2=0.00f;
GLfloat positionboat1=0.0f;
GLfloat boatspeed0=0.0f;
GLfloat positionbus5= 0.0f;
GLfloat positionbus6= 0.0f;
GLfloat busspeed5 = 0.0f;
GLfloat busspeed6 = 0.0f;
GLfloat moonposition3=0.0f;
GLfloat moonspeed3=0.0f;
GLfloat mposition3=0.0f;
GLfloat mposition4=0.0f;
GLfloat mspeed3=0.00;
GLfloat mspeed4=0.00;


bool rl1[] = {false, false, true};
bool rl2[] = {false, false, true};

bool waveUp = true;

float c1 = 0.00;
float c2 = 0.00;
float c3 = 0.00;
float c4 = 0.00;
float c5 = 0.00;
float c6 = 0.00;
float c7 = 0.00;
float c8 = 0.00;
float c9 = 0.00;
float c10 = 0.00;
float c11 = 0.00;
float c12 = 0.00;
float c13 = 0.00;
float c14 = 0.00;
float c15 = 0.00;
float c16 = 0.00;
float c17 = 0.00;

void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void Cloud()
{
    glTranslatef(position11, 0.0, 0.0);
	GLfloat  x = -.97f; GLfloat y = 0.88; GLfloat radius = .035f;       //cloud1
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255, 255);
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

						  //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();

	x = -.92f; y = 0.88;  radius = .055f;       //cloud1
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	i;
	lineAmount = 100; //# of triangles used to draw circle

					  //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();


	x = -.86f; y = 0.88;  radius = .035f;       //cloud1
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	i;
	lineAmount = 100; //# of triangles used to draw circle

					  //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();



	x = -.57f; y = 0.88;  radius = .035f;       //cloud2
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	i;
	lineAmount = 100; //# of triangles used to draw circle

					  //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();


	x = -.52f; y = 0.88;  radius = .055f;       //cloud2
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	i;
	lineAmount = 100; //# of triangles used to draw circle

					  //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();

	x = -.46f; y = 0.88;  radius = .035f;       //cloud2
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	i;
	lineAmount = 100; //# of triangles used to draw circle

					  //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();



	x = .46f; y = 0.88;  radius = .035f;       //cloud3
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	i;
	lineAmount = 100; //# of triangles used to draw circle

					  //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();


	x = .52f; y = 0.88;  radius = .055f;       //cloud3
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	i;
	lineAmount = 100; //# of triangles used to draw circle

					  //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();

	x = .57f; y = 0.88;  radius = .035f;       //cloud3
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	i;
	lineAmount = 100; //# of triangles used to draw circle

					  //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
}

void sun()
{
    glPushMatrix();
glTranslatef(0.7, 0.0,0.0);
    glPushMatrix();
     glTranslatef(sunposition0, 0.0,0.0);
        glPushMatrix();
    glTranslatef(0.2, 0.9,0.0);
  // glRotatef(angle,0.0,0.0,1);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);

	for (int i = 0; i<100; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 100;
		float r = 0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	////Sunrays////
	glPushMatrix();
//    glRotatef();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.2, 0.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.1, 0.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.3, 0.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.2, 1.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.3, 1.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.1, 1.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.6, 1.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.5, 0.9);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(0.4, 0.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(-0.1, 0.8);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(-0.1, 0.6);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.2, 0.9);
	glVertex2f(-0.1, 1.0);
	glEnd();
glPopMatrix();
glPopMatrix();
}

void Star()
{

	glTranslatef(-.75, .68, 0.0);//star 1(from left)
	glScalef(0.2, 0.2, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(-.70, .74, 0.0);//star 2(from left)
	glScalef(0.1, 0.1, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(-.60, .80, 0.0);//star 3(from left)
	glScalef(0.1, 0.1, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(.60, .80, 0.0);//star 4(from left)
	glScalef(0.1, 0.1, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(.75, .85, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(.75, .85, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(.15, .71, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(.25, .73, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(.45, .78, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(-.35, .78, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(-.25, .80, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(-.45, .81, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
	glLoadIdentity();

	glTranslatef(.0, .81, 0.0);//star 5(from left)
	glScalef(0.15, 0.15, 0.0);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .98);
	glVertex2f(-.89, .88);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 102);
	glVertex2f(-.99, .88);
	glVertex2f(-.94, .80);
	glVertex2f(-.89, .88);
	glEnd();
}
void Moon()
{
glPushMatrix();
     glTranslatef(moonposition1,0.0,0.0);
	GLfloat x = -0.70f; GLfloat y = 0.88; GLfloat radius = .065f;       //moon
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 241, 213);
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

						  //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
	glPopMatrix();
}
void sky()
{

//-----------------------Blue Sky-------------------------------

    glBegin(GL_POLYGON); //Blue sky
    glColor4f(0.0f, 1.0f,1.0f, 1.0);
    glVertex2f(-1.0f, 0.60f);
    glVertex2f(1.0f, 0.60f);
    glVertex2f(1.0f, 1.0f);

    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void display()
{
//-----------------------Green Ground-------------------------------

    glBegin(GL_POLYGON); //Green Ground
    glColor3f(0.0f, 1.0f,0.0f);
    glVertex2f(-1.0f, .38f);
    glVertex2f(1.0f, 0.38f);
    glVertex2f(1.0f, 0.60f);
    glVertex2f(-1.0f, 0.60f);
    glEnd();


//-----------------------HILL-------------------------------

//--------------hill-1

    glPushMatrix();
    glTranslatef(0.3f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.2f,0.0f);
    glVertex2f(-1.0f, 0.60f);
    glVertex2f(-1.0f, 0.70f);


    glVertex2f(-1.0f, 0.70f);
    glVertex2f(-0.97f, 0.73f);

    glVertex2f(-0.97f, 0.73f);
    glVertex2f(-0.95f, 0.71f);

    glVertex2f(-0.95f, 0.71f);
    glVertex2f(-0.9f, 0.82f);

    glVertex2f(-0.9f, 0.82f);
    glVertex2f(-0.87f, 0.78f);

    glVertex2f(-0.87f, 0.78f);
    glVertex2f(-0.84f, 0.71f);

    glVertex2f(-0.84f, 0.71f);
    glVertex2f(-0.8f, 0.75f);

    glVertex2f(-0.8f, 0.75f);
    glVertex2f(-0.78f, 0.73f);

    glVertex2f(-0.78f, 0.73f);
    glVertex2f(-0.73f, 0.78f);

    glVertex2f(-0.73f, 0.78f);
    glVertex2f(-0.68f, 0.69f);

    glVertex2f(-0.68f, 0.69f);
    glVertex2f(-0.65f, 0.72f);

    glVertex2f(-0.65f, 0.72f);
    glVertex2f(-0.58f, 0.63f);

    glVertex2f(-0.58f, 0.63f);
    glVertex2f(-0.55f, 0.65f);

    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.5f, 0.6f);

    glEnd();
    glPopMatrix();

//-------------hill-2
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.4f,0.0f);

    glVertex2f(-1.0f, 0.60f);
    glVertex2f(-1.0f, 0.70f);


    glVertex2f(-1.0f, 0.70f);
    glVertex2f(-0.97f, 0.73f);

    glVertex2f(-0.97f, 0.73f);
    glVertex2f(-0.95f, 0.71f);

    glVertex2f(-0.95f, 0.71f);
    glVertex2f(-0.9f, 0.80f);

    glVertex2f(-0.9f, 0.80f);
    glVertex2f(-0.87f, 0.78f);

    glVertex2f(-0.87f, 0.78f);
    glVertex2f(-0.84f, 0.71f);

    glVertex2f(-0.84f, 0.71f);
    glVertex2f(-0.8f, 0.75f);

    glVertex2f(-0.8f, 0.75f);
    glVertex2f(-0.78f, 0.73f);

    glVertex2f(-0.78f, 0.73f);
    glVertex2f(-0.73f, 0.78f);

    glVertex2f(-0.73f, 0.78f);
    glVertex2f(-0.68f, 0.69f);

    glVertex2f(-0.68f, 0.69f);
    glVertex2f(-0.65f, 0.72f);

    glVertex2f(-0.65f, 0.72f);
    glVertex2f(-0.58f, 0.63f);

    glVertex2f(-0.58f, 0.63f);
    glVertex2f(-0.55f, 0.65f);

    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.5f, 0.6f);

    glEnd();


//-------------hill-5

    glPushMatrix();
    glTranslatef(0.8f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.2f,0.0f);


    glVertex2f(-0.65f, 0.6f);
    glVertex2f(-0.63f, 0.70f);

    glVertex2f(-0.63f, 0.60f);
    glVertex2f(-0.61f, 0.63f);

    glVertex2f(-0.61f, 0.63f);
    glVertex2f(-0.55f, 0.70f);

    glVertex2f(-0.55f, 0.70f);
    glVertex2f(-0.52f, 0.68f);

    glVertex2f(-0.52f, 0.68f);
    glVertex2f(-0.5f, 0.73f);

    glVertex2f(-0.5f, 0.73f);
    glVertex2f(-0.47f, 0.71f);

    glVertex2f(-0.47f, 0.71f);
    glVertex2f(-0.44f, 0.78f);

    glVertex2f(-0.44f, 0.78f);
    glVertex2f(-0.4f, 0.75f);

    glVertex2f(-0.4f, 0.75f);
    glVertex2f(-0.35f, 0.67f);

    glVertex2f(-0.35f, 0.67f);
    glVertex2f(-0.3f, 0.71f);

    glVertex2f(-0.3f, 0.71f);
    glVertex2f(-0.28f, 0.68f);

    glVertex2f(-0.28f, 0.68f);
    glVertex2f(-0.24f, 0.74f);

    glVertex2f(-0.24f, 0.74f);
    glVertex2f(-0.18f, 0.63f);

    glVertex2f(-0.18f, 0.63f);
    glVertex2f(-0.15f, 0.65f);

    glVertex2f(-0.15f, 0.65f);
    glVertex2f(-0.11f, 0.60f);

    glVertex2f(-0.11f, 0.60f);
    glVertex2f(-0.1f, 0.60f);

    glEnd();
    glPopMatrix();

//------------hill4

    glPushMatrix();
    glTranslatef(0.78f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.3f,0.0f);

    glVertex2f(-1.0f, 0.60f);
    glVertex2f(-1.0f, 0.70f);


    glVertex2f(-1.0f, 0.70f);
    glVertex2f(-0.97f, 0.73f);

    glVertex2f(-0.97f, 0.73f);
    glVertex2f(-0.95f, 0.71f);

    glVertex2f(-0.95f, 0.71f);
    glVertex2f(-0.9f, 0.80f);

    glVertex2f(-0.9f, 0.8f);
    glVertex2f(-0.87f, 0.78f);

    glVertex2f(-0.87f, 0.78f);
    glVertex2f(-0.84f, 0.71f);

    glVertex2f(-0.84f, 0.71f);
    glVertex2f(-0.8f, 0.75f);

    glVertex2f(-0.8f, 0.75f);
    glVertex2f(-0.78f, 0.73f);

    glVertex2f(-0.78f, 0.73f);
    glVertex2f(-0.73f, 0.78f);

    glVertex2f(-0.73f, 0.78f);
    glVertex2f(-0.68f, 0.69f);

    glVertex2f(-0.68f, 0.69f);
    glVertex2f(-0.65f, 0.72f);

    glVertex2f(-0.65f, 0.72f);
    glVertex2f(-0.58f, 0.63f);

    glVertex2f(-0.58f, 0.63f);
    glVertex2f(-0.55f, 0.65f);

    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.5f, 0.60f);

    glEnd();
    glPopMatrix();


//------------hill6

    glPushMatrix();
    glTranslatef(1.3f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.3f,0.0f);


    glVertex2f(-0.65f, 0.60f);
    glVertex2f(-0.63f, 0.65f);

    glVertex2f(-0.63f, 0.60f);
    glVertex2f(-0.61f, 0.63f);

    glVertex2f(-0.61f, 0.63f);
    glVertex2f(-0.55f, 0.7f);

    glVertex2f(-0.55f, 0.7f);
    glVertex2f(-0.52f, 0.68f);

    glVertex2f(-0.52f, 0.68f);
    glVertex2f(-0.5f, 0.73f);

    glVertex2f(-0.5f, 0.73f);
    glVertex2f(-0.47f, 0.71f);

    glVertex2f(-0.47f, 0.71f);
    glVertex2f(-0.44f, 0.78f);

    glVertex2f(-0.44f, 0.78f);
    glVertex2f(-0.4f, 0.75f);

    glVertex2f(-0.4f, 0.75f);
    glVertex2f(-0.35f, 0.67f);

    glVertex2f(-0.35f, 0.67f);
    glVertex2f(-0.3f, 0.71f);

    glVertex2f(-0.3f, 0.71f);
    glVertex2f(-0.28f, 0.68f);

    glVertex2f(-0.28f, 0.68f);
    glVertex2f(-0.24f, 0.74f);

    glVertex2f(-0.24f, 0.74f);
    glVertex2f(-0.18f, 0.63f);

    glVertex2f(-0.18f, 0.63f);
    glVertex2f(-0.15f, 0.65f);

    glVertex2f(-0.15f, 0.65f);
    glVertex2f(-0.11f, 0.65f);

    glVertex2f(-0.11f, 0.65f);
    glVertex2f(-0.1f, 0.60f);

    glEnd();
    glPopMatrix();

 //-----------------------Houses-------------------------------


 // -----1st House------
    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON); //(Square part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

    glVertex2f(-0.90f, 0.38f);
    glVertex2f(-0.70f, 0.38f);
    glVertex2f(-0.70f, 0.82f);
    glVertex2f(-0.90f, 0.82f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue-1 part)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.42f);
    glVertex2f(-0.72f, 0.42f);
    glVertex2f(-0.72f, 0.48f);
    glVertex2f(-0.88f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (left)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.42f);
    glVertex2f(-0.84f, 0.42f);
    glVertex2f(-0.84f, 0.48f);
    glVertex2f(-0.85f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.42f);
    glVertex2f(-0.80f, 0.42f);
    glVertex2f(-0.80f, 0.48f);
    glVertex2f(-0.81f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line Last-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.42f);
    glVertex2f(-0.75f, 0.42f);
    glVertex2f(-0.75f, 0.48f);
    glVertex2f(-0.76f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-2)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.52f);
    glVertex2f(-0.72f, 0.52f);
    glVertex2f(-0.72f, 0.58f);
    glVertex2f(-0.88f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.52f);
    glVertex2f(-0.84f, 0.52f);
    glVertex2f(-0.84f, 0.58f);
    glVertex2f(-0.85f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.52f);
    glVertex2f(-0.80f, 0.52f);
    glVertex2f(-0.80f, 0.58f);
    glVertex2f(-0.81f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.52f);
    glVertex2f(-0.75f, 0.52f);
    glVertex2f(-0.75f, 0.58f);
    glVertex2f(-0.76f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-3)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.62f);
    glVertex2f(-0.72f, 0.62f);
    glVertex2f(-0.72f, 0.68f);
    glVertex2f(-0.88f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.62f);
    glVertex2f(-0.84f, 0.62f);
    glVertex2f(-0.84f, 0.68f);
    glVertex2f(-0.85f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.62f);
    glVertex2f(-0.80f, 0.62f);
    glVertex2f(-0.80f, 0.68f);
    glVertex2f(-0.81f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.62f);
    glVertex2f(-0.75f, 0.62f);
    glVertex2f(-0.75f, 0.68f);
    glVertex2f(-0.76f, 0.68f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside blue part-4)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.72f);
    glVertex2f(-0.72f, 0.72f);
    glVertex2f(-0.72f, 0.78f);
    glVertex2f(-0.88f, 0.78f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside black line part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.72f);
    glVertex2f(-0.84f, 0.72f);
    glVertex2f(-0.84f, 0.78f);
    glVertex2f(-0.85f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line middle part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.72f);
    glVertex2f(-0.80f, 0.72f);
    glVertex2f(-0.80f, 0.78f);
    glVertex2f(-0.81f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.72f);
    glVertex2f(-0.75f, 0.72f);
    glVertex2f(-0.75f, 0.78f);
    glVertex2f(-0.76f, 0.78f);
    glEnd();

        glTranslatef(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON); //(Square part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

    glVertex2f(-0.90f, 0.38f);
    glVertex2f(-0.70f, 0.38f);
    glVertex2f(-0.70f, 0.82f);
    glVertex2f(-0.90f, 0.82f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue-1 part)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.42f);
    glVertex2f(-0.72f, 0.42f);
    glVertex2f(-0.72f, 0.48f);
    glVertex2f(-0.88f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (left)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.42f);
    glVertex2f(-0.84f, 0.42f);
    glVertex2f(-0.84f, 0.48f);
    glVertex2f(-0.85f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.42f);
    glVertex2f(-0.80f, 0.42f);
    glVertex2f(-0.80f, 0.48f);
    glVertex2f(-0.81f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line Last-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.42f);
    glVertex2f(-0.75f, 0.42f);
    glVertex2f(-0.75f, 0.48f);
    glVertex2f(-0.76f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-2)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.52f);
    glVertex2f(-0.72f, 0.52f);
    glVertex2f(-0.72f, 0.58f);
    glVertex2f(-0.88f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.52f);
    glVertex2f(-0.84f, 0.52f);
    glVertex2f(-0.84f, 0.58f);
    glVertex2f(-0.85f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.52f);
    glVertex2f(-0.80f, 0.52f);
    glVertex2f(-0.80f, 0.58f);
    glVertex2f(-0.81f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.52f);
    glVertex2f(-0.75f, 0.52f);
    glVertex2f(-0.75f, 0.58f);
    glVertex2f(-0.76f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-3)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.62f);
    glVertex2f(-0.72f, 0.62f);
    glVertex2f(-0.72f, 0.68f);
    glVertex2f(-0.88f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.62f);
    glVertex2f(-0.84f, 0.62f);
    glVertex2f(-0.84f, 0.68f);
    glVertex2f(-0.85f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.62f);
    glVertex2f(-0.80f, 0.62f);
    glVertex2f(-0.80f, 0.68f);
    glVertex2f(-0.81f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.62f);
    glVertex2f(-0.75f, 0.62f);
    glVertex2f(-0.75f, 0.68f);
    glVertex2f(-0.76f, 0.68f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside blue part-4)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.72f);
    glVertex2f(-0.72f, 0.72f);
    glVertex2f(-0.72f, 0.78f);
    glVertex2f(-0.88f, 0.78f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside black line part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.72f);
    glVertex2f(-0.84f, 0.72f);
    glVertex2f(-0.84f, 0.78f);
    glVertex2f(-0.85f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line middle part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.72f);
    glVertex2f(-0.80f, 0.72f);
    glVertex2f(-0.80f, 0.78f);
    glVertex2f(-0.81f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.72f);
    glVertex2f(-0.75f, 0.72f);
    glVertex2f(-0.75f, 0.78f);
    glVertex2f(-0.76f, 0.78f);
    glEnd();
    //////////////////////////////////////
        glTranslatef(0.13f,0.0f,0.0f);
    glBegin(GL_POLYGON); //(Square part)
    glColor4f(0.0f, 0.0f, 1.0f, 0.0f);

    glVertex2f(-0.90f, 0.38f);
    glVertex2f(-0.70f, 0.38f);
    glVertex2f(-0.70f, 0.82f);
    glVertex2f(-0.90f, 0.82f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue-1 part)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.42f);
    glVertex2f(-0.72f, 0.42f);
    glVertex2f(-0.72f, 0.48f);
    glVertex2f(-0.88f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (left)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.42f);
    glVertex2f(-0.84f, 0.42f);
    glVertex2f(-0.84f, 0.48f);
    glVertex2f(-0.85f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.42f);
    glVertex2f(-0.80f, 0.42f);
    glVertex2f(-0.80f, 0.48f);
    glVertex2f(-0.81f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line Last-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.42f);
    glVertex2f(-0.75f, 0.42f);
    glVertex2f(-0.75f, 0.48f);
    glVertex2f(-0.76f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-2)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.52f);
    glVertex2f(-0.72f, 0.52f);
    glVertex2f(-0.72f, 0.58f);
    glVertex2f(-0.88f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.52f);
    glVertex2f(-0.84f, 0.52f);
    glVertex2f(-0.84f, 0.58f);
    glVertex2f(-0.85f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.52f);
    glVertex2f(-0.80f, 0.52f);
    glVertex2f(-0.80f, 0.58f);
    glVertex2f(-0.81f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.52f);
    glVertex2f(-0.75f, 0.52f);
    glVertex2f(-0.75f, 0.58f);
    glVertex2f(-0.76f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-3)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.62f);
    glVertex2f(-0.72f, 0.62f);
    glVertex2f(-0.72f, 0.68f);
    glVertex2f(-0.88f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.62f);
    glVertex2f(-0.84f, 0.62f);
    glVertex2f(-0.84f, 0.68f);
    glVertex2f(-0.85f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.62f);
    glVertex2f(-0.80f, 0.62f);
    glVertex2f(-0.80f, 0.68f);
    glVertex2f(-0.81f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.62f);
    glVertex2f(-0.75f, 0.62f);
    glVertex2f(-0.75f, 0.68f);
    glVertex2f(-0.76f, 0.68f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside blue part-4)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(-0.88f, 0.72f);
    glVertex2f(-0.72f, 0.72f);
    glVertex2f(-0.72f, 0.78f);
    glVertex2f(-0.88f, 0.78f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside black line part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.85f, 0.72f);
    glVertex2f(-0.84f, 0.72f);
    glVertex2f(-0.84f, 0.78f);
    glVertex2f(-0.85f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line middle part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.81f, 0.72f);
    glVertex2f(-0.80f, 0.72f);
    glVertex2f(-0.80f, 0.78f);
    glVertex2f(-0.81f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.76f, 0.72f);
    glVertex2f(-0.75f, 0.72f);
    glVertex2f(-0.75f, 0.78f);
    glVertex2f(-0.76f, 0.78f);
    glEnd();
    glPopMatrix();


// ------2nd House------
glPushMatrix();
glTranslatef(0.13f,0.0f,0.0f);
    glBegin(GL_POLYGON); //(Square part)
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);//orange/brown

    glVertex2f(-0.50f, 0.38f);
    glVertex2f(-0.30f, 0.38f);
    glVertex2f(-0.30f, 0.82f);
    glVertex2f(-0.50f, 0.82f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.48f, 0.42f);
    glVertex2f(-0.32f, 0.42f);
    glVertex2f(-0.32f, 0.48f);
    glVertex2f(-0.48f, 0.48f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside white line (left)-1 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.45f, 0.42f);
    glVertex2f(-0.44f, 0.42f);
    glVertex2f(-0.44f, 0.48f);
    glVertex2f(-0.45f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line (1st middle)-1 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.41f, 0.42f);
    glVertex2f(-0.40f, 0.42f);
    glVertex2f(-0.40f, 0.48f);
    glVertex2f(-0.41f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line Last-1 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.36f, 0.42f);
    glVertex2f(-0.35f, 0.42f);
    glVertex2f(-0.35f, 0.48f);
    glVertex2f(-0.36f, 0.48f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside black-2 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.48f, 0.52f);
    glVertex2f(-0.32f, 0.52f);
    glVertex2f(-0.32f, 0.58f);
    glVertex2f(-0.48f, 0.58f);
    glEnd();


        glBegin(GL_POLYGON); //(Square inside white line (left)-2 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.45f, 0.52f);
    glVertex2f(-0.44f, 0.52f);
    glVertex2f(-0.44f, 0.58f);
    glVertex2f(-0.45f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line (1st middle)-2 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.41f, 0.52f);
    glVertex2f(-0.40f, 0.52f);
    glVertex2f(-0.40f, 0.58f);
    glVertex2f(-0.41f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line Last-2 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.36f, 0.52f);
    glVertex2f(-0.35f, 0.52f);
    glVertex2f(-0.35f, 0.58f);
    glVertex2f(-0.36f, 0.58f);
    glEnd();

     glBegin(GL_POLYGON); //(Square inside black-3 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.32f, 0.62f);
    glVertex2f(-0.32f, 0.68f);
    glVertex2f(-0.48f, 0.68f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside white line (left)-3 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.45f, 0.62f);
    glVertex2f(-0.44f, 0.62f);
    glVertex2f(-0.44f, 0.68f);
    glVertex2f(-0.45f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line (1st middle)-3 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.41f, 0.62f);
    glVertex2f(-0.40f, 0.62f);
    glVertex2f(-0.40f, 0.68f);
    glVertex2f(-0.41f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line Last-3 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.36f, 0.62f);
    glVertex2f(-0.35f, 0.62f);
    glVertex2f(-0.35f, 0.68f);
    glVertex2f(-0.36f, 0.68f);
    glEnd();


         glBegin(GL_POLYGON); //(Square inside black-4 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.48f, 0.72f);
    glVertex2f(-0.32f, 0.72f);
    glVertex2f(-0.32f, 0.78f);
    glVertex2f(-0.48f, 0.78f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside white line (left)-4 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.45f, 0.72f);
    glVertex2f(-0.44f, 0.72f);
    glVertex2f(-0.44f, 0.78f);
    glVertex2f(-0.45f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line (1st middle)-4 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.41f, 0.72f);
    glVertex2f(-0.40f, 0.72f);
    glVertex2f(-0.40f, 0.78f);
    glVertex2f(-0.41f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line Last-4 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.36f, 0.72f);
    glVertex2f(-0.35f, 0.72f);
    glVertex2f(-0.35f, 0.78f);
    glVertex2f(-0.36f, 0.78f);
    glEnd();
////////////////////////////
glTranslatef(0.13f,0.0f,0.0f);
    glBegin(GL_POLYGON); //(Square part)
    glColor3ub(153,51,0);

    glVertex2f(-0.50f, 0.38f);
    glVertex2f(-0.30f, 0.38f);
    glVertex2f(-0.30f, 0.82f);
    glVertex2f(-0.50f, 0.82f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.48f, 0.42f);
    glVertex2f(-0.32f, 0.42f);
    glVertex2f(-0.32f, 0.48f);
    glVertex2f(-0.48f, 0.48f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside white line (left)-1 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.45f, 0.42f);
    glVertex2f(-0.44f, 0.42f);
    glVertex2f(-0.44f, 0.48f);
    glVertex2f(-0.45f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line (1st middle)-1 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.41f, 0.42f);
    glVertex2f(-0.40f, 0.42f);
    glVertex2f(-0.40f, 0.48f);
    glVertex2f(-0.41f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line Last-1 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.36f, 0.42f);
    glVertex2f(-0.35f, 0.42f);
    glVertex2f(-0.35f, 0.48f);
    glVertex2f(-0.36f, 0.48f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside black-2 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.48f, 0.52f);
    glVertex2f(-0.32f, 0.52f);
    glVertex2f(-0.32f, 0.58f);
    glVertex2f(-0.48f, 0.58f);
    glEnd();


        glBegin(GL_POLYGON); //(Square inside white line (left)-2 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.45f, 0.52f);
    glVertex2f(-0.44f, 0.52f);
    glVertex2f(-0.44f, 0.58f);
    glVertex2f(-0.45f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line (1st middle)-2 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.41f, 0.52f);
    glVertex2f(-0.40f, 0.52f);
    glVertex2f(-0.40f, 0.58f);
    glVertex2f(-0.41f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line Last-2 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.36f, 0.52f);
    glVertex2f(-0.35f, 0.52f);
    glVertex2f(-0.35f, 0.58f);
    glVertex2f(-0.36f, 0.58f);
    glEnd();

     glBegin(GL_POLYGON); //(Square inside black-3 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.32f, 0.62f);
    glVertex2f(-0.32f, 0.68f);
    glVertex2f(-0.48f, 0.68f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside white line (left)-3 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.45f, 0.62f);
    glVertex2f(-0.44f, 0.62f);
    glVertex2f(-0.44f, 0.68f);
    glVertex2f(-0.45f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line (1st middle)-3 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.41f, 0.62f);
    glVertex2f(-0.40f, 0.62f);
    glVertex2f(-0.40f, 0.68f);
    glVertex2f(-0.41f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line Last-3 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.36f, 0.62f);
    glVertex2f(-0.35f, 0.62f);
    glVertex2f(-0.35f, 0.68f);
    glVertex2f(-0.36f, 0.68f);
    glEnd();


         glBegin(GL_POLYGON); //(Square inside black-4 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(-0.48f, 0.72f);
    glVertex2f(-0.32f, 0.72f);
    glVertex2f(-0.32f, 0.78f);
    glVertex2f(-0.48f, 0.78f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside white line (left)-4 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.45f, 0.72f);
    glVertex2f(-0.44f, 0.72f);
    glVertex2f(-0.44f, 0.78f);
    glVertex2f(-0.45f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line (1st middle)-4 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.41f, 0.72f);
    glVertex2f(-0.40f, 0.72f);
    glVertex2f(-0.40f, 0.78f);
    glVertex2f(-0.41f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white line Last-4 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(-0.36f, 0.72f);
    glVertex2f(-0.35f, 0.72f);
    glVertex2f(-0.35f, 0.78f);
    glVertex2f(-0.36f, 0.78f);
    glEnd();
glPopMatrix();

    // ------3rd House------

    glBegin(GL_POLYGON); //(Square part)
    glColor3f(2.0f, 0.5f, 1.0f);//Lilac

    glVertex2f(0.10f, 0.38f);
    glVertex2f(0.30f, 0.38f);
    glVertex2f(0.30f, 0.72f);
    glVertex2f(0.10f, 0.72f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white-1 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(0.12f, 0.42f);
    glVertex2f(0.28f, 0.42f);
    glVertex2f(0.28f, 0.48f);
    glVertex2f(0.12f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (left)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.16f, 0.42f);
    glVertex2f(0.15f, 0.42f);
    glVertex2f(0.15f, 0.48f);
    glVertex2f(0.16f, 0.48f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside black line middle-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.20f, 0.42f);
    glVertex2f(0.19f, 0.42f);
    glVertex2f(0.19f, 0.48f);
    glVertex2f(0.20f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black last line middle-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.25f, 0.42f);
    glVertex2f(0.24f, 0.42f);
    glVertex2f(0.24f, 0.48f);
    glVertex2f(0.25f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white-2 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(0.12f, 0.52f);
    glVertex2f(0.28f, 0.52f);
    glVertex2f(0.28f, 0.58f);
    glVertex2f(0.12f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black left line-2 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.16f, 0.52f);
    glVertex2f(0.15f, 0.52f);
    glVertex2f(0.15f, 0.58f);
    glVertex2f(0.16f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black middle line-2 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.20f, 0.52f);
    glVertex2f(0.19f, 0.52f);
    glVertex2f(0.19f, 0.58f);
    glVertex2f(0.20f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black last line-2 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.25f, 0.52f);
    glVertex2f(0.24f, 0.52f);
    glVertex2f(0.24f, 0.58f);
    glVertex2f(0.25f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside white-3 part)
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

    glVertex2f(0.12f, 0.62f);
    glVertex2f(0.28f, 0.62f);
    glVertex2f(0.28f, 0.68f);
    glVertex2f(0.12f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black left line-3 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.16f, 0.62f);
    glVertex2f(0.15f, 0.62f);
    glVertex2f(0.15f, 0.68f);
    glVertex2f(0.16f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black middle line-3 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.20f, 0.62f);
    glVertex2f(0.19f, 0.62f);
    glVertex2f(0.19f, 0.68f);
    glVertex2f(0.20f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black last line-3 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.25f, 0.62f);
    glVertex2f(0.24f, 0.62f);
    glVertex2f(0.24f, 0.68f);
    glVertex2f(0.25f, 0.68f);
    glEnd();

  // -----4th House------
glPushMatrix();
glTranslatef(0.0,0.0,0.0);
    glBegin(GL_POLYGON); //(Square part)
    glColor3ub(255,128,128);

    glVertex2f(0.50f, 0.38f);
    glVertex2f(0.70f, 0.38f);
    glVertex2f(0.70f, 0.82f);
    glVertex2f(0.50f, 0.82f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue-1 part)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(0.52f, 0.42f);
    glVertex2f(0.68f, 0.42f);
    glVertex2f(0.68f, 0.48f);
    glVertex2f(0.52f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (left)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.56f, 0.42f);
    glVertex2f(0.55f, 0.42f);
    glVertex2f(0.55f, 0.48f);
    glVertex2f(0.56f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.60f, 0.42f);
    glVertex2f(0.59f, 0.42f);
    glVertex2f(0.59f, 0.48f);
    glVertex2f(0.60f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line Last-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.65f, 0.42f);
    glVertex2f(0.64f, 0.42f);
    glVertex2f(0.64f, 0.48f);
    glVertex2f(0.65f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-2)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(0.52f, 0.52f);
    glVertex2f(0.68f, 0.52f);
    glVertex2f(0.68f, 0.58f);
    glVertex2f(0.52f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black left line part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.56f, 0.52f);
    glVertex2f(0.55f, 0.52f);
    glVertex2f(0.55f, 0.58f);
    glVertex2f(0.56f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.60f, 0.52f);
    glVertex2f(0.59f, 0.52f);
    glVertex2f(0.59f, 0.58f);
    glVertex2f(0.60f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.65f, 0.52f);
    glVertex2f(0.64f, 0.52f);
    glVertex2f(0.64f, 0.58f);
    glVertex2f(0.65f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-3)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(0.52f, 0.62f);
    glVertex2f(0.68f, 0.62f);
    glVertex2f(0.68f, 0.68f);
    glVertex2f(0.52f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.56f, 0.62f);
    glVertex2f(0.55f, 0.62f);
    glVertex2f(0.55f, 0.68f);
    glVertex2f(0.56f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.60f, 0.62f);
    glVertex2f(0.59f, 0.62f);
    glVertex2f(0.59f, 0.68f);
    glVertex2f(0.60f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.65f, 0.62f);
    glVertex2f(0.64f, 0.62f);
    glVertex2f(0.64f, 0.68f);
    glVertex2f(0.65f, 0.68f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside blue part-4)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(0.52f, 0.72f);
    glVertex2f(0.68f, 0.72f);
    glVertex2f(0.68f, 0.78f);
    glVertex2f(0.52f, 0.78f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside black line part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.56f, 0.72f);
    glVertex2f(0.55f, 0.72f);
    glVertex2f(0.55f, 0.78f);
    glVertex2f(0.56f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line middle part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.60f, 0.72f);
    glVertex2f(0.59f, 0.72f);
    glVertex2f(0.59f, 0.78f);
    glVertex2f(0.60f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.65f, 0.72f);
    glVertex2f(0.64f, 0.72f);
    glVertex2f(0.64f, 0.78f);
    glVertex2f(0.65f, 0.78f);
    glEnd();
    /////////////

    glTranslatef(-0.13,0.0,0.0);
    glBegin(GL_POLYGON); //(Square part)
    glColor3ub(255,204,0);

    glVertex2f(0.50f, 0.38f);
    glVertex2f(0.70f, 0.38f);
    glVertex2f(0.70f, 0.82f);
    glVertex2f(0.50f, 0.82f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue-1 part)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(0.52f, 0.42f);
    glVertex2f(0.68f, 0.42f);
    glVertex2f(0.68f, 0.48f);
    glVertex2f(0.52f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (left)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.56f, 0.42f);
    glVertex2f(0.55f, 0.42f);
    glVertex2f(0.55f, 0.48f);
    glVertex2f(0.56f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle)-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.60f, 0.42f);
    glVertex2f(0.59f, 0.42f);
    glVertex2f(0.59f, 0.48f);
    glVertex2f(0.60f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line Last-1 part)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.65f, 0.42f);
    glVertex2f(0.64f, 0.42f);
    glVertex2f(0.64f, 0.48f);
    glVertex2f(0.65f, 0.48f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-2)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(0.52f, 0.52f);
    glVertex2f(0.68f, 0.52f);
    glVertex2f(0.68f, 0.58f);
    glVertex2f(0.52f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black left line part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.56f, 0.52f);
    glVertex2f(0.55f, 0.52f);
    glVertex2f(0.55f, 0.58f);
    glVertex2f(0.56f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.60f, 0.52f);
    glVertex2f(0.59f, 0.52f);
    glVertex2f(0.59f, 0.58f);
    glVertex2f(0.60f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-2)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.65f, 0.52f);
    glVertex2f(0.64f, 0.52f);
    glVertex2f(0.64f, 0.58f);
    glVertex2f(0.65f, 0.58f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside blue part-3)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(0.52f, 0.62f);
    glVertex2f(0.68f, 0.62f);
    glVertex2f(0.68f, 0.68f);
    glVertex2f(0.52f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.56f, 0.62f);
    glVertex2f(0.55f, 0.62f);
    glVertex2f(0.55f, 0.68f);
    glVertex2f(0.56f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line (1st middle) part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.60f, 0.62f);
    glVertex2f(0.59f, 0.62f);
    glVertex2f(0.59f, 0.68f);
    glVertex2f(0.60f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-3)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.65f, 0.62f);
    glVertex2f(0.64f, 0.62f);
    glVertex2f(0.64f, 0.68f);
    glVertex2f(0.65f, 0.68f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside blue part-4)
    glColor3f(0.0f, 0.5f, 1.0f);

    glVertex2f(0.52f, 0.72f);
    glVertex2f(0.68f, 0.72f);
    glVertex2f(0.68f, 0.78f);
    glVertex2f(0.52f, 0.78f);
    glEnd();


    glBegin(GL_POLYGON); //(Square inside black line part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.56f, 0.72f);
    glVertex2f(0.55f, 0.72f);
    glVertex2f(0.55f, 0.78f);
    glVertex2f(0.56f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line middle part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.60f, 0.72f);
    glVertex2f(0.59f, 0.72f);
    glVertex2f(0.59f, 0.78f);
    glVertex2f(0.60f, 0.78f);
    glEnd();

    glBegin(GL_POLYGON); //(Square inside black line last part-4)
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glVertex2f(0.65f, 0.72f);
    glVertex2f(0.64f, 0.72f);
    glVertex2f(0.64f, 0.78f);
    glVertex2f(0.65f, 0.78f);
    glEnd();
    glPopMatrix();

}


 void Road()
  {


    /**........................................ Road ...........................................**/

    glBegin(GL_QUADS);//road
	glColor3f(0.33, 0.33, 0.33);

    glVertex2f(-1.0f, -0.02f);
    glVertex2f(1.0f, -0.02f);
    glVertex2f(1.0f, 0.38f);
    glVertex2f(-1.0f, 0.38f);

    glEnd();
  }
  void roadline()
  {
       glTranslatef(0.0f,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

   glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();

  glTranslatef(+0.20f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.00f, 1.00f, 1.00f);
      glVertex2f(-1.0f, 0.19f);
      glVertex2f( -0.90f, 0.19f);
      glVertex2f( -0.90f,  0.21f);
      glVertex2f(-1.00f,  0.21f);
   glEnd();
  }

void vehicles1()
{
    /**--------------------------Bus1-----------------------**/


   glPushMatrix();
    glTranslatef(positionbus1,0,0);
	 glColor3ub(81,242,0);
	glBegin(GL_POLYGON);
        glVertex2f(-0.79f, 0.24f);
        glVertex2f(-0.61f, 0.24f);
        glVertex2f(-0.61f, 0.30f);
        glVertex2f(-0.635f, 0.30f);
        glVertex2f(-0.65f, 0.36f);
         glVertex2f(-0.79f, 0.36f);
        glEnd();

	//windows
glColor3f(0.80f,0.40f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.78f, 0.30f);
        glVertex2f(-0.735f, 0.30f);
        glVertex2f(-0.735f, 0.34f);
        glVertex2f(-0.78f, 0.34f);
    glEnd();

glColor3f(0.80f,0.40f,0.0f);
	glBegin(GL_POLYGON);
         glVertex2f(-0.72f, 0.30f);
        glVertex2f(-0.69f, 0.30f);
        glVertex2f(-0.69f, 0.34f);
        glVertex2f(-0.72f, 0.34f);
    glEnd();

glColor3f(0.80f,0.40f,0.0f);
	glBegin(GL_POLYGON);
         glVertex2f(-0.68f, 0.30f);
        glVertex2f(-0.645f, 0.30f);
        glVertex2f(-0.655f, 0.34f);
        glVertex2f(-0.68f, 0.34f);
    glEnd();



glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.615f, 0.285f);
        glVertex2f(-0.608f, 0.285f);
        glVertex2f(-0.608f, 0.30f);
        glVertex2f(-0.615f, 0.30f);
    glEnd();
       //light
glColor3ub(255,255,153);
	glBegin(GL_POLYGON);
        glVertex2f(-0.615f, 0.29f);
        glVertex2f(-0.585f, 0.23f);
        glVertex2f(-0.545f, 0.23f);
        glVertex2f(-0.615f, 0.30f);
        glEnd();



// wheel 1
    GLfloat xc=-0.66f;
    GLfloat yc=0.25f;
    GLfloat radiusc =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc + (radiusc * cos(i *  twicePi / triangleAmount)),
                    yc+ (radiusc * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xc1=-0.66f;
    GLfloat yc1=0.25f;
    GLfloat radiusc3 =0.0125f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc1, yc1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc1 + (radiusc3 * cos(i *  twicePi / triangleAmount)),
                    yc1 + (radiusc3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();


	// wheel 2
    GLfloat xc2=-0.75f;
    GLfloat yc2=0.25f;
    GLfloat radiusc2 =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc2, yc2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc2 + (radiusc2 * cos(i *  twicePi / triangleAmount)),
                    yc2+ (radiusc2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat xc3=-0.75f;
    GLfloat yc3=0.25f;
    GLfloat radiusc4=0.0125f;

 glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc3, yc3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc3 + (radiusc3 * cos(i *  twicePi / triangleAmount)),
                    yc3+ (radiusc3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
 glPopMatrix();
}

void vehicles5()
{
    /**--------------------------Bus1-----------------------**/

   glPushMatrix();
    glTranslatef(positionbus1,0,0);
	 glColor3ub(81,242,0);
	glBegin(GL_POLYGON);
        glVertex2f(-0.79f, 0.24f);
        glVertex2f(-0.61f, 0.24f);
        glVertex2f(-0.61f, 0.30f);
        glVertex2f(-0.635f, 0.30f);
        glVertex2f(-0.65f, 0.36f);
         glVertex2f(-0.79f, 0.36f);
        glEnd();

	//windows
glColor3f(0.80f,0.40f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.78f, 0.30f);
        glVertex2f(-0.735f, 0.30f);
        glVertex2f(-0.735f, 0.34f);
        glVertex2f(-0.78f, 0.34f);
    glEnd();

glColor3f(0.80f,0.40f,0.0f);
	glBegin(GL_POLYGON);
         glVertex2f(-0.72f, 0.30f);
        glVertex2f(-0.69f, 0.30f);
        glVertex2f(-0.69f, 0.34f);
        glVertex2f(-0.72f, 0.34f);
    glEnd();

glColor3f(0.80f,0.40f,0.0f);
	glBegin(GL_POLYGON);
         glVertex2f(-0.68f, 0.30f);
        glVertex2f(-0.645f, 0.30f);
        glVertex2f(-0.655f, 0.34f);
        glVertex2f(-0.68f, 0.34f);
    glEnd();


glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.615f, 0.285f);
        glVertex2f(-0.608f, 0.285f);
        glVertex2f(-0.608f, 0.30f);
        glVertex2f(-0.615f, 0.30f);
    glEnd();

// wheel 1
    GLfloat xc=-0.66f;
    GLfloat yc=0.25f;
    GLfloat radiusc =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc + (radiusc * cos(i *  twicePi / triangleAmount)),
                    yc+ (radiusc * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xc1=-0.66f;
    GLfloat yc1=0.25f;
    GLfloat radiusc3 =0.0125f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc1, yc1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc1 + (radiusc3 * cos(i *  twicePi / triangleAmount)),
                    yc1 + (radiusc3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();


	// wheel 2
    GLfloat xc2=-0.75f;
    GLfloat yc2=0.25f;
    GLfloat radiusc2 =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc2, yc2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc2 + (radiusc2 * cos(i *  twicePi / triangleAmount)),
                    yc2+ (radiusc2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat xc3=-0.75f;
    GLfloat yc3=0.25f;
    GLfloat radiusc4=0.0125f;

 glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc3, yc3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc3 + (radiusc3 * cos(i *  twicePi / triangleAmount)),
                    yc3+ (radiusc3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
 glPopMatrix();
}

void vehicles2()
{


/**-------------------------------------------Car 1--------------------------------------**/
 glPushMatrix();
    glTranslatef(positionbus2,0.0,0.0);
	 glColor3ub(246,162,0);
	glBegin(GL_POLYGON);
        glVertex2f(-0.51f, 0.26f);
        glVertex2f(-0.29f, 0.26f);
        glVertex2f(-0.29f, 0.40f);
         glVertex2f(-0.51f, 0.40f);
        glEnd();

    glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.30f, 0.275f);
        glVertex2f(-0.29f, 0.275f);
        glVertex2f(-0.29f, 0.29f);
        glVertex2f(-0.30f, 0.29f);

    glEnd();


	//windows
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.30f, 0.30f);
        glVertex2f(-0.29f, 0.30f);
        glVertex2f(-0.29f, 0.375f);
        glVertex2f(-0.30f, 0.375f);
          glEnd();
glPushMatrix();
        glTranslatef(0.0f,0.0f, 0.0f);
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.49f, 0.33f);
        glVertex2f(-0.45f, 0.33f);
        glVertex2f(-0.45f, 0.375f);
        glVertex2f(-0.49f, 0.375f);

    glEnd();

         glTranslatef(0.05f,0.0f, 0.0f);
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.49f, 0.33f);
        glVertex2f(-0.45f, 0.33f);
        glVertex2f(-0.45f, 0.375f);
        glVertex2f(-0.49f, 0.375f);

    glEnd();
 glTranslatef(0.05f,0.0f, 0.0f);
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.49f, 0.33f);
        glVertex2f(-0.45f, 0.33f);
        glVertex2f(-0.45f, 0.375f);
        glVertex2f(-0.49f, 0.375f);

    glEnd();

glTranslatef(0.05f,0.0f, 0.0f);
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.49f, 0.33f);
        glVertex2f(-0.46f, 0.33f);
        glVertex2f(-0.46f, 0.375f);
        glVertex2f(-0.49f, 0.375f);

    glEnd();
glPopMatrix();


//light
glColor3ub(255,255,153);
	glBegin(GL_POLYGON);
        glVertex2f(-0.295f, 0.275f);
        glVertex2f(-0.28f, 0.24f);
        glVertex2f(-0.23f, 0.24f);
        glVertex2f(-0.295f, 0.29f);
        glEnd();


// wheel 1
  GLfloat x=-0.35f;
    GLfloat y=0.265f;
    GLfloat radius =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius* cos(i *  twicePi / triangleAmount)),
                    y+ (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat x1=-0.35f;
    GLfloat y1=0.265f;
    GLfloat radius3 =0.013f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();


	// wheel 2
    GLfloat x2=-0.46f;
    GLfloat y2=0.265f;
    GLfloat radius2 =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2+ (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat x3=-0.46f;
    GLfloat y3=0.265f;
    GLfloat radius4=0.013f;

 glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3+ (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
 glPopMatrix();
}

void vehicles6()
{



  glPushMatrix();
    glTranslatef(positionbus2,0.0,0.0);
	 glColor3ub(246,162,0);
	glBegin(GL_POLYGON);
        glVertex2f(-0.51f, 0.26f);
        glVertex2f(-0.29f, 0.26f);
        glVertex2f(-0.29f, 0.40f);
         glVertex2f(-0.51f, 0.40f);
        glEnd();

    glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.30f, 0.275f);
        glVertex2f(-0.29f, 0.275f);
        glVertex2f(-0.29f, 0.29f);
        glVertex2f(-0.30f, 0.29f);

    glEnd();


	//windows
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.30f, 0.30f);
        glVertex2f(-0.29f, 0.30f);
        glVertex2f(-0.29f, 0.375f);
        glVertex2f(-0.30f, 0.375f);
          glEnd();
glPushMatrix();
        glTranslatef(0.0f,0.0f, 0.0f);
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.49f, 0.33f);
        glVertex2f(-0.45f, 0.33f);
        glVertex2f(-0.45f, 0.375f);
        glVertex2f(-0.49f, 0.375f);

    glEnd();

         glTranslatef(0.05f,0.0f, 0.0f);
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.49f, 0.33f);
        glVertex2f(-0.45f, 0.33f);
        glVertex2f(-0.45f, 0.375f);
        glVertex2f(-0.49f, 0.375f);

    glEnd();
 glTranslatef(0.05f,0.0f, 0.0f);
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.49f, 0.33f);
        glVertex2f(-0.45f, 0.33f);
        glVertex2f(-0.45f, 0.375f);
        glVertex2f(-0.49f, 0.375f);

    glEnd();

glTranslatef(0.05f,0.0f, 0.0f);
glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.49f, 0.33f);
        glVertex2f(-0.46f, 0.33f);
        glVertex2f(-0.46f, 0.375f);
        glVertex2f(-0.49f, 0.375f);

    glEnd();
glPopMatrix();

// wheel 1
  GLfloat x=-0.35f;
    GLfloat y=0.265f;
    GLfloat radius =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius* cos(i *  twicePi / triangleAmount)),
                    y+ (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat x1=-0.35f;
    GLfloat y1=0.265f;
    GLfloat radius3 =0.013f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y1 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();


	// wheel 2
    GLfloat x2=-0.46f;
    GLfloat y2=0.265f;
    GLfloat radius2 =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2+ (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat x3=-0.46f;
    GLfloat y3=0.265f;
    GLfloat radius4=0.013f;

 glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3+ (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
 glPopMatrix();
  glPopMatrix();
}


void vehicles3()
{

 glPushMatrix();
    glTranslatef(positionbus3,0,0);
	 glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
        glVertex2f(0.75f, 0.045f);
        glVertex2f(0.95f, 0.045f);
        glVertex2f(0.95f, 0.09f);
        glVertex2f(0.83f, 0.09f);
         glVertex2f(0.83f, 0.16f);
          glVertex2f(0.79f, 0.16f);
          glVertex2f(0.77f, 0.09f);
          glVertex2f(0.75f, 0.09f);
        glEnd();

        GLfloat xa20=0.765f;
    GLfloat ya20=0.065f;
    GLfloat radiusa20 =0.026f;

 glColor3ub(255,69,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa20, ya20); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa20 + (radiusa20* cos(i *  twicePi / triangleAmount)),
                    ya20+ (radiusa20 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

        //windows
      glColor3ub(184,134,11);
	glBegin(GL_POLYGON);
        glVertex2f(0.775f, 0.09f);
        glVertex2f(0.82f, 0.09f);
        glVertex2f(0.82f, 0.14f);
        glVertex2f(0.79f, 0.14f);
        glEnd();

              glColor3ub(128,128,0);
	glBegin(GL_POLYGON);
        glVertex2f(0.83f, 0.09f);
        glVertex2f(0.95f, 0.09f);
        glVertex2f(0.95f, 0.12f);
        glVertex2f(0.83f, 0.12f);
        glEnd();

                      glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.74f, 0.0645);
        glVertex2f(0.75f, 0.0645f);
        glVertex2f(0.75f, 0.075f);
        glVertex2f(0.74f, 0.075f);
        glEnd();
 // light
          glColor3ub(255,255,153);
	glBegin(GL_POLYGON);
        glVertex2f(0.745f, 0.0645);
        glVertex2f(0.718f, 0.02f);
        glVertex2f(0.678f, 0.02f);
        glVertex2f(0.745f, 0.0745f);
        glEnd();


              glLineWidth(3.0);
              glColor3ub(170,169,173);
	glBegin(GL_LINES);
	      glVertex2f(0.947f, 0.09f);
        glVertex2f(0.947, 0.15f);
glEnd();

              glLineWidth(3.0);
             glColor3ub(170,169,173);
	glBegin(GL_LINES);
	      glVertex2f(0.95f, 0.15f);
        glVertex2f(0.83, 0.15f);
glEnd();

        glLineWidth(3.0);
              glColor3ub(170,169,173);
	glBegin(GL_LINES);
	      glVertex2f(0.87f, 0.09f);
        glVertex2f(0.87, 0.15f);
glEnd();

     glLineWidth(3.0);
              glColor3ub(170,169,173);
	glBegin(GL_LINES);
	      glVertex2f(0.91f, 0.09f);
        glVertex2f(0.91, 0.15f);
glEnd();

// wheel 1
  GLfloat xa10=0.80f;
    GLfloat ya10=0.04f;
    GLfloat radiusa10 =0.022f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa10, ya10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa10 + (radiusa10* cos(i *  twicePi / triangleAmount)),
                    ya10+ (radiusa10 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xb1=0.80f;
    GLfloat yb1=0.04f;
    GLfloat radiusb3 =0.011f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb1, yb1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb1 + (radiusb3 * cos(i *  twicePi / triangleAmount)),
                    yb1 + (radiusb3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();

         // wheel 2
  GLfloat xa11=0.90f;
    GLfloat ya11=0.04f;
    GLfloat radiusa11 =0.022f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa11, ya11); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa11 + (radiusa11* cos(i *  twicePi / triangleAmount)),
                    ya11+ (radiusa11 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xb2=0.90f;
    GLfloat yb2=0.04f;
    GLfloat radiusb13 =0.011f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb2, yb2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb2 + (radiusb13 * cos(i *  twicePi / triangleAmount)),
                    yb2 + (radiusb13 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();

 glPopMatrix();
}

void vehicles7()
{

   /**........................................ minibus 2 ...........................................**/

   glPushMatrix();
    glTranslatef(positionbus3,0,0);
	 glColor3ub(255,69,0);
	glBegin(GL_POLYGON);
        glVertex2f(0.75f, 0.045f);
        glVertex2f(0.95f, 0.045f);
        glVertex2f(0.95f, 0.09f);
        glVertex2f(0.83f, 0.09f);
         glVertex2f(0.83f, 0.16f);
          glVertex2f(0.79f, 0.16f);
          glVertex2f(0.77f, 0.09f);
          glVertex2f(0.75f, 0.09f);
        glEnd();

        GLfloat xa20=0.765f;
    GLfloat ya20=0.065f;
    GLfloat radiusa20 =0.026f;

 glColor3ub(255,69,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa20, ya20); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa20 + (radiusa20* cos(i *  twicePi / triangleAmount)),
                    ya20+ (radiusa20 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

        //windows
      glColor3ub(184,134,11);
	glBegin(GL_POLYGON);
        glVertex2f(0.775f, 0.09f);
        glVertex2f(0.82f, 0.09f);
        glVertex2f(0.82f, 0.14f);
        glVertex2f(0.79f, 0.14f);
        glEnd();

              glColor3ub(128,128,0);
	glBegin(GL_POLYGON);
        glVertex2f(0.83f, 0.09f);
        glVertex2f(0.95f, 0.09f);
        glVertex2f(0.95f, 0.12f);
        glVertex2f(0.83f, 0.12f);
        glEnd();

                      glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.74f, 0.0645);
        glVertex2f(0.75f, 0.0645f);
        glVertex2f(0.75f, 0.075f);
        glVertex2f(0.74f, 0.075f);
        glEnd();




              glLineWidth(3.0);
              glColor3ub(170,169,173);
	glBegin(GL_LINES);
	      glVertex2f(0.947f, 0.09f);
        glVertex2f(0.947, 0.15f);
glEnd();

              glLineWidth(3.0);
           glColor3ub(170,169,173);
	glBegin(GL_LINES);
	      glVertex2f(0.95f, 0.15f);
        glVertex2f(0.83, 0.15f);
glEnd();

        glLineWidth(3.0);
        glColor3ub(170,169,173);
	glBegin(GL_LINES);
	      glVertex2f(0.87f, 0.09f);
        glVertex2f(0.87, 0.15f);
glEnd();

     glLineWidth(3.0);
            glColor3ub(170,169,173);
	glBegin(GL_LINES);
	      glVertex2f(0.91f, 0.09f);
        glVertex2f(0.91, 0.15f);
glEnd();

// wheel 1
  GLfloat xa10=0.80f;
    GLfloat ya10=0.04f;
    GLfloat radiusa10 =0.022f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa10, ya10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa10 + (radiusa10* cos(i *  twicePi / triangleAmount)),
                    ya10+ (radiusa10 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xb1=0.80f;
    GLfloat yb1=0.04f;
    GLfloat radiusb3 =0.011f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb1, yb1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb1 + (radiusb3 * cos(i *  twicePi / triangleAmount)),
                    yb1 + (radiusb3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();

         // wheel 2
  GLfloat xa11=0.90f;
    GLfloat ya11=0.04f;
    GLfloat radiusa11 =0.022f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa11, ya11); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa11 + (radiusa11* cos(i *  twicePi / triangleAmount)),
                    ya11+ (radiusa11 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xb2=0.90f;
    GLfloat yb2=0.04f;
    GLfloat radiusb13 =0.011f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb2, yb2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb2 + (radiusb13 * cos(i *  twicePi / triangleAmount)),
                    yb2 + (radiusb13 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();

 glPopMatrix();
}

void vehicles4()
{

    /**--------------------------Car3-----------------------**/

   glPushMatrix();
    glTranslatef(positionbus4,0,0);

	 glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
              glVertex2f(0.36f, 0.09f);
        glVertex2f(0.55f, 0.09f);
        glVertex2f(0.55f, 0.13f);
        glVertex2f(0.53f, 0.13f);
         glVertex2f(0.49f, 0.17f);
          glVertex2f(0.41f, 0.17f);
          glVertex2f(0.37f, 0.13f);
          glVertex2f(0.36f, 0.13f);
        glEnd();
  GLfloat xr=0.54f;
    GLfloat yr=0.11f;
    GLfloat radiusr2 =0.02f;

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr, yr); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr + (radiusr2* cos(i *  twicePi / triangleAmount)),
                    yr+ (radiusr2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
         glRotatef(i,0,1,0);
  GLfloat xr1=0.365f;
    GLfloat yr1=0.11f;
    GLfloat radiusr21 =0.02f;

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr1, yr1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr1 + (radiusr21* cos(i *  twicePi / triangleAmount)),
                    yr1+ (radiusr21 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

 glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.38f, 0.125f);
        glVertex2f(0.44f, 0.125f);
        glVertex2f(0.44f, 0.16f);
        glVertex2f(0.415f, 0.16f);
        glEnd();

         glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.46f, 0.125f);
        glVertex2f(0.52f, 0.125f);
        glVertex2f(0.48f, 0.16f);
        glVertex2f(0.46f, 0.16f);
        glEnd();

    glLineWidth(2.0);
              glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	      glVertex2f(0.45f, 0.09f);
        glVertex2f(0.45, 0.165f);
glEnd();
   glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.345f, 0.102f);
        glVertex2f(0.355f, 0.102f);
        glVertex2f(0.355f, 0.112f);
        glVertex2f(0.345f, 0.112f);
        glEnd();

//light
glColor3ub(255,255,153);
	glBegin(GL_POLYGON);
        glVertex2f(0.293f, 0.075f);
        glVertex2f(0.333f, 0.075f);
        glVertex2f(0.345f, 0.10f);
        glVertex2f(0.345f, 0.11f);
        glEnd();


// wheel 1
 glRotatef(i,0,1,0);
  GLfloat xa=0.41f;
    GLfloat ya=0.09f;
    GLfloat radiusa =0.02f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa, ya); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa + (radiusa* cos(i *  twicePi / triangleAmount)),
                    ya+ (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xa1=0.41f;
    GLfloat ya1=0.09f;
    GLfloat radiusa3 =0.01f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa1, ya1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa1 + (radiusa3 * cos(i *  twicePi / triangleAmount)),
                    ya1 + (radiusa3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();


	// wheel 2
    GLfloat xa2=0.51f;
    GLfloat ya2=0.09f;
    GLfloat radiusa2 =0.02f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa2, ya2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa2 + (radiusa2 * cos(i *  twicePi / triangleAmount)),
                    ya2+ (radiusa2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat xa3=0.51f;
    GLfloat ya3=0.09f;
    GLfloat radiusa4=0.01f;

 glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa3, ya3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa3 + (radiusa3 * cos(i *  twicePi / triangleAmount)),
                    ya3+ (radiusa3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
glPopMatrix();

}

void vehicles8()
{

    /**--------------------------Car3-----------------------**/

   glPushMatrix();
    glTranslatef(positionbus4,0,0);
	 glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
              glVertex2f(0.36f, 0.09f);
        glVertex2f(0.55f, 0.09f);
        glVertex2f(0.55f, 0.13f);
        glVertex2f(0.53f, 0.13f);
         glVertex2f(0.49f, 0.17f);
          glVertex2f(0.41f, 0.17f);
          glVertex2f(0.37f, 0.13f);
          glVertex2f(0.36f, 0.13f);
        glEnd();

         glRotatef(i,0,1,0);
  GLfloat xr=0.54f;
    GLfloat yr=0.11f;
    GLfloat radiusr2 =0.02f;

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr, yr); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr + (radiusr2* cos(i *  twicePi / triangleAmount)),
                    yr+ (radiusr2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
         glRotatef(i,0,1,0);
  GLfloat xr1=0.365f;
    GLfloat yr1=0.11f;
    GLfloat radiusr21 =0.02f;

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr1, yr1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr1 + (radiusr21* cos(i *  twicePi / triangleAmount)),
                    yr1+ (radiusr21 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.345f, 0.102f);
        glVertex2f(0.355f, 0.102f);
        glVertex2f(0.355f, 0.112f);
        glVertex2f(0.345f, 0.112f);
        glEnd();


 glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.38f, 0.125f);
        glVertex2f(0.44f, 0.125f);
        glVertex2f(0.44f, 0.16f);
        glVertex2f(0.415f, 0.16f);
        glEnd();

         glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.46f, 0.125f);
        glVertex2f(0.52f, 0.125f);
        glVertex2f(0.48f, 0.16f);
        glVertex2f(0.46f, 0.16f);
        glEnd();

    glLineWidth(2.0);
              glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	      glVertex2f(0.45f, 0.09f);
        glVertex2f(0.45, 0.165f);
glEnd();


// wheel 1
 glRotatef(i,0,1,0);
  GLfloat xa=0.41f;
    GLfloat ya=0.09f;
    GLfloat radiusa =0.02f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa, ya); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa + (radiusa* cos(i *  twicePi / triangleAmount)),
                    ya+ (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xa1=0.41f;
    GLfloat ya1=0.09f;
    GLfloat radiusa3 =0.01f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa1, ya1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa1 + (radiusa3 * cos(i *  twicePi / triangleAmount)),
                    ya1 + (radiusa3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();


	// wheel 2
    GLfloat xa2=0.51f;
    GLfloat ya2=0.09f;
    GLfloat radiusa2 =0.02f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa2, ya2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa2 + (radiusa2 * cos(i *  twicePi / triangleAmount)),
                    ya2+ (radiusa2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat xa3=0.51f;
    GLfloat ya3=0.09f;
    GLfloat radiusa4=0.01f;

 glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa3, ya3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa3 + (radiusa3 * cos(i *  twicePi / triangleAmount)),
                    ya3+ (radiusa3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

 glPopMatrix();
}
void grass()
{
          glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);



    glVertex2f(-1.0f, -0.065f);
    glVertex2f(1.0f, -0.065f);
    glVertex2f(1.0f, -0.02f);
    glVertex2f(-1.0f, -0.02f);

    glEnd();
}

void beach()
{
/**........................................ Beach ...........................................**/
  glPushMatrix();
      glBegin(GL_POLYGON);
    glColor3f(0.96f,0.64f,0.38f);
    glVertex2f(-1.0f, -0.50f);
    glVertex2f(1.0f, -0.50f);
    glVertex2f(1.0f, -0.065f);
    glVertex2f(-1.0f, -0.065f);


    glEnd();
/////_____________bench_________________
    glTranslatef(0.0f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();

    glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();

 glTranslatef(0.45f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();

 glTranslatef(0.50f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
 glTranslatef(0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();

 glTranslatef(0.0f,-0.1f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();

glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.5f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();

glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.45f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();


glTranslatef(-0.04f,0.0f, 0.0f);
     glLineWidth(3.0);
     glBegin(GL_LINES);

           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.81f, -0.09f);
        glVertex2f(-0.84, -0.09f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.10f);
        glVertex2f(-0.843, -0.10f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.11f);
        glVertex2f(-0.845, -0.11f);

        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81, -0.123f);
        glVertex2f(-0.845f, -0.123f);

          glColor3f(1.0, 0.50, 0.50);
        glVertex2f(-0.81, -0.133f);
        glVertex2f(-0.845f, -0.133f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.143f);
        glVertex2f(-0.845f, -0.143f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.153f);
        glVertex2f(-0.845f, -0.153f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81, -0.163f);
        glVertex2f(-0.845f, -0.163f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81, -0.173f);
        glVertex2f(-0.845f, -0.173f);
glEnd();
glPopMatrix();

}
void sea()
{
    /**........................................ Sea ...........................................**/
      glPushMatrix();
    glTranslatef(0,-.1,0);
    glColor3f(0.808f,0.878f,0.949f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(-1.0f, -0.4f);
    glEnd();
    //c1..............................
    glPushMatrix();
    glTranslatef(0,c1,0);
    GLfloat xw1=-0.9f;
    GLfloat yw1=-0.61f;
    GLfloat radiusw1 =0.3f;
     glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw1, yw1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw1 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw1 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c2..............................
    glPushMatrix();
    glTranslatef(0,c2,0);
    GLfloat xw2=0.3f;
    GLfloat yw2=-0.61f;
   glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw2, yw2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw2 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw2 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c3..............................
    glPushMatrix();
    glTranslatef(0,c3,0);
    GLfloat xw3=0.2f;
    GLfloat yw3=-0.62f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw3, yw3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw3 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw3 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



     //c4..............................
    glPushMatrix();
    glTranslatef(0,c4,0);
    GLfloat xw4=0.1f;
    GLfloat yw4=-0.63f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw4, yw4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw4 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                      yw4 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c5..............................
    glPushMatrix();
    glTranslatef(0,c5,0);
    GLfloat xw5=-0.2f;
    GLfloat yw5=-0.62f;
  glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw5, yw5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw5 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw5 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c6..............................
    glPushMatrix();
    glTranslatef(0,c6,0);
    GLfloat xw6=-0.8f;
    GLfloat yw6=-0.62f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw6, yw6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw6 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw6 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c7..............................
    glPushMatrix();
    glTranslatef(0,c7,0);
    GLfloat xw7=-0.7f;
    GLfloat yw7=-0.63f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw7, yw7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw7 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw7 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }



    glEnd();
    glPopMatrix();



    //c8..............................
    glPushMatrix();
    glTranslatef(0,c8,0);
    GLfloat xw8=-0.6f;
    GLfloat yw8=-0.62f;
      glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw8, yw8);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw8 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw8 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c9..............................
    glPushMatrix();
    glTranslatef(0,c9,0);
    GLfloat xw9=-0.5f;
    GLfloat yw9=-0.61f;
      glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw9, yw9);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw9 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw9 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c10..............................
    glPushMatrix();
    glTranslatef(0,c10,0);
    GLfloat xw10=-0.4f;
    GLfloat yw10=-0.62f;
   glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw10, yw10);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw10 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw10 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c11..............................
    glPushMatrix();
    glTranslatef(0,c11,0);
    GLfloat xw11=-0.05f;
    GLfloat yw11=-0.63f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw11, yw11);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw11 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw11 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c12..............................
    glPushMatrix();
    glTranslatef(0,c12,0);
    GLfloat xw12=0.4f;
    GLfloat yw12=-0.61f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw12, yw12);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw12 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw12 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }



    glEnd();
    glPopMatrix();



    //c13..............................
    glPushMatrix();
    glTranslatef(0,c13,0);
    GLfloat xw13=0.5f;
    GLfloat yw13=-0.62f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw13, yw13);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw13 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw13 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c14..............................
    glPushMatrix();
    glTranslatef(0,c14,0);
    GLfloat xw14=0.6f;
    GLfloat yw14=-0.63f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw14, yw14);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw14 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw14 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c15..............................
    glPushMatrix();
    glTranslatef(0,c15,0);
    GLfloat xw15=0.7f;
    GLfloat yw15=-0.61f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw15, yw15);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw15 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw15 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }



    glEnd();
    glPopMatrix();



    //c16..............................
    glPushMatrix();
    glTranslatef(0,c16,0);
    GLfloat xw16=0.8f;
    GLfloat yw16=-0.62f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw16, yw16);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw16 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw16 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }



    glEnd();
    glPopMatrix();



    //c17..............................
    glPushMatrix();
    glTranslatef(0,c17,0);
    GLfloat xw17=0.9f;
    GLfloat yw17=-0.63f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw17, yw17);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw17 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                yw17 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glColor3f(0.808f,0.878f,0.949f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(-1.0f, -0.4f);
    glEnd();
    glPopMatrix();
}
void boat1()
{

    /**.................................... small boat-1 .......................................**/
       glPushMatrix();
        glTranslatef(position,0.0f,0.0f);
        glPushMatrix();
        glTranslatef(0.0,-0.05f,0.0f);
        glBegin(GL_POLYGON);
        glColor3f(0.4f,0.0f,0.0f);

        glVertex2f(-0.75f, -0.47f);
        glVertex2f(-0.65f, -0.47f);
        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.47f);
        glVertex2f(-0.8f, -0.4f);
        glVertex2f(-0.75f, -0.47f);
        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.65f, -0.44f);
        glVertex2f(-0.75f, -0.44f);
        glVertex2f(-0.8f, -0.4f);
        glVertex2f(-0.65f, -0.44f);
        glVertex2f(-0.75f, -0.44f);
        glEnd();

        glColor3f(0.98f,0.761f,0.192f);
        glBegin(GL_QUADS);
        glVertex2f(-0.74f, -0.38f);
        glVertex2f(-0.72f, -0.44f);
        glVertex2f(-0.66f, -0.44f);
        glVertex2f(-0.68f, -0.38f);
        glEnd();
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.74f, -0.38f);
        glVertex2f(-0.76f, -0.41f);
        glVertex2f(-0.726f, -0.42f);
        glEnd();
      glPopMatrix();
      glPopMatrix();
}
void boat2()
{

     /**.................................... small boat-2 .......................................**/
        glPushMatrix();
        glTranslatef(position2, 0.0f, 0.0f);
           glPushMatrix();
        glTranslatef(0.0f, -0.05f, 0.0f);
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.20f, -0.55f);
        glVertex2f(-0.20f, -0.60f);
        glVertex2f(-0.05f, -0.60f);
        glVertex2f(-0.0f, -0.55f);
        glEnd();
        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.18f, -0.51f);
        glVertex2f(-0.18f, -0.55f);
        glVertex2f(-0.04f, -0.55f);
        glVertex2f(-0.07f, -0.51f);
        glEnd();
        glColor3f(1.0f,1.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.17f, -0.52f);
        glVertex2f(-0.17f, -0.54f);
        glVertex2f(-0.15f, -0.54f);
        glVertex2f(-0.15f, -0.52f);
        glEnd();
        glPushMatrix();
        glTranslatef(0.037f, 0.0f, 0.0f);
        glColor3f(1.0f,1.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.17f, -0.52f);
        glVertex2f(-0.17f, -0.54f);
        glVertex2f(-0.15f, -0.54f);
        glVertex2f(-0.15f, -0.52f);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.074f, 0.0f, 0.0f);
        glColor3f(1.0f,1.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.17f, -0.52f);
        glVertex2f(-0.17f, -0.54f);
        glVertex2f(-0.15f, -0.54f);
        glVertex2f(-0.15f, -0.52f);
        glEnd();
        glPopMatrix();
        glColor3f(0.086f,0.922f,0.71f);
        glBegin(GL_QUADS);
        glVertex2f(-0.16f, -0.47f);
        glVertex2f(-0.16f, -0.51f);
        glVertex2f(-0.09f, -0.51f);
        glVertex2f(-0.12f, -0.47f);
        glEnd();
       glPopMatrix();
        glPopMatrix();
}
void boat3()
{
/**.................................... big boat-structure.......................................**/
    glPushMatrix();
    glTranslatef(position3,0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.1f, -0.8f);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(0.4f, -0.9f);
    glVertex2f(0.2f, -0.9f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.6f, -0.8f);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(0.4f, -0.9f);
    glVertex2f(0.5f, -0.9f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.18f, -0.88f);
    glVertex2f(0.2f, -0.9f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.9f);
    glVertex2f(0.42f, -0.88f);
    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.15f, -0.75f);
    glVertex2f(0.45f, -0.75f);
    glVertex2f(0.45f, -0.8f);
    glVertex2f(0.15f, -0.8f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.55f, -0.75f);
    glVertex2f(0.45f, -0.75f);
    glVertex2f(0.45f, -0.8f);
    glVertex2f(0.55f, -0.8f);
    glColor3f(0.851f,0.851f,0.851f);
    glBegin(GL_QUADS);
    glVertex2f(0.18f, -0.7f);
    glVertex2f(0.18f, -0.75f);
    glColor3f(0.200f,0.200f,0.200f);
    glBegin(GL_QUADS);
    glVertex2f(0.515f, -0.75f);
    glVertex2f(0.515f, -0.7f);
    glEnd();
    /**.................................... big boat-Pillar .......................................**/
    glColor3f(0.200f,0.200f,0.200f);
    glBegin(GL_QUADS);
    glVertex2f(0.21f, -0.65f);
    glVertex2f(0.24f, -0.65f);
    glVertex2f(0.24f, -0.7f);
    glVertex2f(0.21f, -0.7f);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.21f, -0.65f);
    glVertex2f(0.24f, -0.65f);
    glVertex2f(0.24f, -0.63f);
    glVertex2f(0.21f, -0.63f);
    glEnd();
   glColor3f(0.200f,0.200f,0.200f);
    glBegin(GL_QUADS);
    glVertex2f(0.31f, -0.65f);
    glVertex2f(0.34f, -0.65f);
    glVertex2f(0.34f, -0.7f);
    glVertex2f(0.31f, -0.7f);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.31f, -0.65f);
    glVertex2f(0.34f, -0.65f);
    glVertex2f(0.34f, -0.63f);
    glVertex2f(0.31f, -0.63f);
    glEnd();
    glColor3f(0.200f,0.200f,0.200f);
    glBegin(GL_QUADS);
    glVertex2f(0.41f, -0.65f);
    glVertex2f(0.44f, -0.65f);
    glVertex2f(0.44f, -0.7f);
    glVertex2f(0.41f, -0.7f);
    glEnd();
   glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.41f, -0.65f);
    glVertex2f(0.44f, -0.65f);
    glVertex2f(0.44f, -0.63f);
    glVertex2f(0.41f, -0.63f);
    glEnd();
    /**.................................... big boat-design .......................................**/
    glColor3f(0.0f,0.0f,0.0f);



    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();
    glPushMatrix();
    glTranslatef(0.05f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.15f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.25f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.16f, -0.79f);
    glVertex2f(0.19f, -0.79f);
    glVertex2f(0.19f, -0.76f);
    glVertex2f(0.16f, -0.76f);
    glEnd();
    glPopMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.46f, -0.79f);
    glVertex2f(0.54f, -0.79f);
    glVertex2f(0.54f, -0.76f);
    glVertex2f(0.46f, -0.76f);
    glEnd();
    GLfloat xboat1=0.175f;
    GLfloat yboat1=-0.84f;
    GLfloat radiusb =.015f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat1, yboat1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat1 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat1 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPushMatrix();
    glTranslatef(0.045f, 0.0f, 0.0f);
    GLfloat xboat2=0.18f;
    GLfloat yboat2=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat2, yboat2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat2 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat2 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.095f, 0.0f, 0.0f);
    GLfloat xboat3=0.18f;
    GLfloat yboat3=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat3, yboat3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat3 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat3 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.145f, 0.0f, 0.0f);
    GLfloat xboat4=0.18f;
    GLfloat yboat4=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat4, yboat4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat4 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat4 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.195f, 0.0f, 0.0f);
    GLfloat xboat5=0.18f;
    GLfloat yboat5=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat5, yboat5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat5 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat5 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.245f, 0.0f, 0.0f);
    GLfloat xboat6=0.18f;
    GLfloat yboat6=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat6, yboat6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat6 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat6 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.295f, 0.0f, 0.0f);
    GLfloat xboat7=0.18f;
    GLfloat yboat7=-0.84f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat7, yboat7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat7 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat7 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void boat5()
   {

      /**.................................... small boat-1 .......................................**/

        glBegin(GL_POLYGON);
        glColor3f(0.4f,0.0f,0.0f);
        glVertex2f(-0.95f, -0.55f);
        glVertex2f(-0.85f, -0.55f);
        glVertex2f(-0.80f, -0.48f);
        glVertex2f(-0.85f, -0.55f);
        glVertex2f(-1.00f, -0.48f);
        glVertex2f(-0.95f, -0.55f);
        glVertex2f(-0.80f, -0.48f);
        glVertex2f(-0.85f, -0.52f);
        glVertex2f(-0.95f, -0.52f);
        glVertex2f(-1.00f, -0.48f);
        glVertex2f(-0.85f, -0.52f);
        glVertex2f(-0.95f, -0.52f);
        glEnd();
        glColor3f(0.98f,0.761f,0.192f);
        glBegin(GL_QUADS);
        glVertex2f(-0.94f, -0.46f);
        glVertex2f(-0.92f, -0.52f);
        glVertex2f(-0.86f, -0.52f);
        glVertex2f(-0.88f, -0.46f);
        glEnd();
       glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.94f, -0.46f);
        glVertex2f(-0.96f, -0.49f);
        glVertex2f(-0.926f, -0.50f);
       glEnd();
     /**.................................... small boat-2 .......................................**/
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.75f, -0.50f);
        glVertex2f(-0.75f, -0.55f);
        glVertex2f(-0.60f, -0.55f);
        glVertex2f(-0.55f, -0.50f);
        glEnd();
        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.73f, -0.46f);
        glVertex2f(-0.73f, -0.50f);
        glVertex2f(-0.59f, -0.50f);
        glVertex2f(-0.62f, -0.46f);
        glEnd();
        glColor3f(1.0f,1.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.72f, -0.47f);
        glVertex2f(-0.72f, -0.49f);
        glVertex2f(-0.70f, -0.49f);
        glVertex2f(-0.70f, -0.47f);
        glEnd();
        glPushMatrix();
        glTranslatef(0.037f, 0.0f, 0.0f);
        glColor3f(1.0f,1.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.72f, -0.47f);
        glVertex2f(-0.72f, -0.49f);
        glVertex2f(-0.70f, -0.49f);
        glVertex2f(-0.70f, -0.47f);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.074f, 0.0f, 0.0f);
        glColor3f(1.0f,1.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.72f, -0.47f);
        glVertex2f(-0.72f, -0.49f);
        glVertex2f(-0.70f, -0.49f);
        glVertex2f(-0.70f, -0.47f);
        glEnd();
        glPopMatrix();
        glColor3f(0.086f,0.922f,0.71f);
        glBegin(GL_QUADS);
        glVertex2f(-0.71f, -0.42f);
        glVertex2f(-0.71f, -0.46f);
        glVertex2f(-0.64f, -0.46f);
        glVertex2f(-0.67f, -0.42f);
        glEnd();
/**.................................... big boat .......................................**/
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.4f, -0.6f);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(-0.1f, -0.5f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(-0.1f, -0.6f);
    glVertex2f(-0.0f, -0.5f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.42f, -0.58f);
    glVertex2f(-0.4f, -0.6f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(-0.18f, -0.58f);
    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, -0.45f);
    glVertex2f(-0.45f, -0.5f);
    glVertex2f(-0.15f, -0.5f);
    glVertex2f(-0.15f, -0.45f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.15f, -0.45f);
    glVertex2f(-0.15f, -0.5f);
    glVertex2f(-0.05f, -0.5f);
    glVertex2f(-0.05f, -0.45f);
    glColor3f(0.851f,0.851f,0.851f);
    glBegin(GL_QUADS);
    glVertex2f(-0.42f, -0.4f);
    glVertex2f(-0.42f, -0.45f);
    glColor3f(0.200f,0.200f,0.200f);
    glBegin(GL_QUADS);
    glVertex2f(-0.08f, -0.45f);
    glVertex2f(-0.08f, -0.4f);
    glEnd();
    /**.................................... big boat-Pillar .......................................**/
   glColor3f(0.200f,0.200f,0.200f);
    glBegin(GL_QUADS);
    glVertex2f(-0.39f, -0.35f);
    glVertex2f(-0.39f, -0.4f);
    glVertex2f(-0.36f, -0.4f);
    glVertex2f(-0.36f, -0.35f);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.39f, -0.33f);
    glVertex2f(-0.39f, -0.35f);
    glVertex2f(-0.36f, -0.35f);
    glVertex2f(-0.36f, -0.33f);
    glEnd();
    glColor3f(0.200f,0.200f,0.200f);
    glBegin(GL_QUADS);
    glVertex2f(-0.29f, -0.35f);
    glVertex2f(-0.29f, -0.4f);
    glVertex2f(-0.26f, -0.4f);
    glVertex2f(-0.26f, -0.35f);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.29f, -0.33f);
    glVertex2f(-0.29f, -0.35f);
    glVertex2f(-0.26f, -0.35f);
    glVertex2f(-0.26f, -0.33f);
    glEnd();
    glColor3f(0.200f,0.200f,0.200f);
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, -0.35f);
    glVertex2f(-0.19f, -0.4f);
    glVertex2f(-0.16f, -0.4f);
    glVertex2f(-0.16f, -0.35f);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, -0.33f);
    glVertex2f(-0.19f,-0.35f);
    glVertex2f(-0.16f,-0.35f);
    glVertex2f(-0.16f, -0.33f);
    glEnd();
    /**.................................... big boat-design .......................................**/
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.44f, -0.46f);
    glVertex2f(-0.44f, -0.49f);
    glVertex2f(-0.41f, -0.49f);
    glVertex2f(-0.41f, -0.46f);
    glEnd();
    glPushMatrix();
    glTranslatef(0.05f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.44f, -0.46f);
    glVertex2f(-0.44f, -0.49f);
    glVertex2f(-0.41f, -0.49f);
    glVertex2f(-0.41f, -0.46f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.1f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.44f, -0.46f);
    glVertex2f(-0.44f, -0.49f);
    glVertex2f(-0.41f, -0.49f);
    glVertex2f(-0.41f, -0.46f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.15f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.44f, -0.46f);
    glVertex2f(-0.44f, -0.49f);
    glVertex2f(-0.41f, -0.49f);
    glVertex2f(-0.41f, -0.46f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);
   glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.44f, -0.46f);
    glVertex2f(-0.44f, -0.49f);
    glVertex2f(-0.41f, -0.49f);
    glVertex2f(-0.41f, -0.46f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.25f, 0.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.44f, -0.46f);
    glVertex2f(-0.44f, -0.49f);
    glVertex2f(-0.41f, -0.49f);
    glVertex2f(-0.41f, -0.46f);
    glEnd();
    glPopMatrix();
   glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.14f, -0.46f);
    glVertex2f(-0.14f, -0.49f);
    glVertex2f(-0.06f, -0.49f);
    glVertex2f(-0.06f, -0.46f);
    glEnd();



    GLfloat xboat1=-0.424f;
    GLfloat yboat1=-0.54f;
    GLfloat radiusb =0.015f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat1, yboat1);



    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat1 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat1 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPushMatrix();
    glTranslatef(0.045f, 0.0f, 0.0f);
    GLfloat xboat2=-0.419f;
    GLfloat yboat2=-0.54f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat2, yboat2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat2 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat2 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.095f, 0.0f, 0.0f);
    GLfloat xboat3=-0.419f;
    GLfloat yboat3=-0.54f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat3, yboat3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat3 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat3 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.145f, 0.0f, 0.0f);
    GLfloat xboat4=-0.419f;
    GLfloat yboat4=-0.54f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat4, yboat4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat4 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat4 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.195f, 0.0f, 0.0f);
    GLfloat xboat5=-0.419f;
    GLfloat yboat5=-0.54f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat5, yboat5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat5 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat5 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.245f, 0.0f, 0.0f);
    GLfloat xboat6=-0.419f;
    GLfloat yboat6=-0.54f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat6, yboat6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat6 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat6 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.295f, 0.0f, 0.0f);
    GLfloat xboat7=-0.419f;
    GLfloat yboat7=-0.54f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat7, yboat7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat7 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat7 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
   }

   void checkpost1()
   {
       glPushMatrix();
           glTranslatef(0.0f,0.01f, 0.0f);
   glBegin(GL_POLYGON);
      glColor3ub(84,213,213);
      glVertex2f(-0.24f, 0.30f);
      glVertex2f( -0.20f, 0.30f);
      glVertex2f( -0.20f,  0.33f);
      glVertex2f(-0.22f,  0.34f);
      glVertex2f(-0.24f,  0.33f);

       glBegin(GL_POLYGON);
      glColor3ub(244,128,0);
      glVertex2f(-0.24f, 0.33f);
      glVertex2f( -0.22f, 0.34f);
      glVertex2f( -0.22f,  0.37f);
      glVertex2f(-0.24f,  0.36f);

        glBegin(GL_POLYGON);
     glColor3ub(244,128,0);
      glVertex2f(-0.22f, 0.34f);
      glVertex2f( -0.20f, 0.33f);
      glVertex2f( -0.20f,  0.36f);
      glVertex2f(-0.22f,  0.37f);
   glEnd();

            glTranslatef(0.5f,-0.19f, 0.0f);
   glBegin(GL_POLYGON);
      glColor3ub(84,213,213);
      glVertex2f(-0.24f, 0.30f);
      glVertex2f( -0.20f, 0.30f);
      glVertex2f( -0.20f,  0.33f);
      glVertex2f(-0.22f,  0.34f);
      glVertex2f(-0.24f,  0.33f);

       glBegin(GL_POLYGON);
      glColor3ub(0,255,0);
      glVertex2f(-0.24f, 0.33f);
      glVertex2f( -0.22f, 0.34f);
      glVertex2f( -0.22f,  0.37f);
      glVertex2f(-0.24f,  0.36f);

        glBegin(GL_POLYGON);
      glColor3ub(0,255,0);
      glVertex2f(-0.22f, 0.34f);
      glVertex2f( -0.20f, 0.33f);
      glVertex2f( -0.20f,  0.36f);
      glVertex2f(-0.22f,  0.37f);
   glEnd();

   glPopMatrix();

   }

   void checkpost2()
   {
       glPushMatrix();
    glTranslatef(0.10f,-0.07f, 0.0f);
   glBegin(GL_POLYGON);
      glColor3ub(84,213,213);
      glVertex2f(-0.24f, 0.30f);
      glVertex2f( -0.20f, 0.30f);
      glVertex2f( -0.20f,  0.33f);
      glVertex2f(-0.22f,  0.34f);
      glVertex2f(-0.24f,  0.33f);

       glBegin(GL_POLYGON);
      glColor3ub(255,0,0);
      glVertex2f(-0.24f, 0.33f);
      glVertex2f( -0.22f, 0.34f);
      glVertex2f( -0.22f,  0.37f);
      glVertex2f(-0.24f,  0.36f);

        glBegin(GL_POLYGON);
      glColor3ub(255,0,0);
      glVertex2f(-0.22f, 0.34f);
      glVertex2f( -0.20f, 0.33f);
      glVertex2f( -0.20f,  0.36f);
      glVertex2f(-0.22f,  0.37f);
   glEnd();

    glTranslatef(0.30f,-0.23f, 0.0f);
   glBegin(GL_POLYGON);
      glColor3ub(84,213,213);
      glVertex2f(-0.24f, 0.30f);
      glVertex2f( -0.20f, 0.30f);
      glVertex2f( -0.20f,  0.33f);
      glVertex2f(-0.22f,  0.34f);
      glVertex2f(-0.24f,  0.33f);

       glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      glVertex2f(-0.24f, 0.33f);
      glVertex2f( -0.22f, 0.34f);
      glVertex2f( -0.22f,  0.37f);
      glVertex2f(-0.24f,  0.36f);

        glBegin(GL_POLYGON);
       glColor3ub(255,255,255);
      glVertex2f(-0.22f, 0.34f);
      glVertex2f( -0.20f, 0.33f);
      glVertex2f( -0.20f,  0.36f);
      glVertex2f(-0.22f,  0.37f);
   glEnd();
   glPopMatrix();

   }


void man1()
{

    glPushMatrix;
    glTranslatef(0.0,mposition1,0.0);
glTranslatef(0.0,0.0,0.0);
      ////neck/////
       glBegin(GL_POLYGON);
          glColor3ub(232, 190, 123);
        glVertex2f(-0.44f, -0.40f);
        glVertex2f(-0.36f, -0.40f);
        glVertex2f(-0.36f, -0.50f);
        glVertex2f(-0.44f, -0.50f);

glEnd();
////////head////
       	 GLfloat x2=-0.40f;
    GLfloat y2=-0.42f;
    GLfloat radiusu2 =0.05f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x2+ (radiusu2* cos(i *  twicePi / 180)),
                    y2+ (radiusu2* sin(i * twicePi / 180)) );
    }
       glEnd();

   // glTranslatef(mposition1,0.0,0.0);
    	 GLfloat x1=-0.40f;
    GLfloat y1=-0.40f;
    GLfloat radiusu1 =0.05f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x1+ (radiusu1* cos(i *  twicePi / 180)),
                    y1+ (radiusu1* sin(i * twicePi / 180)) );
    }
       glEnd();
//////body/////
             glBegin(GL_POLYGON);
          glColor3ub(232, 0,0);
             glVertex2f(-0.45f, -0.70);
             glVertex2f(-0.35f, -0.70f);
               glVertex2f(-0.34f, -0.48f);
               glVertex2f(-0.46f, -0.48f);

glEnd();
/////right hand////
             glBegin(GL_POLYGON);
          glColor3ub(232, 0,0);
             glVertex2f(-0.34f, -0.66f);
             glVertex2f(-0.30f, -0.66f);
              glVertex2f(-0.33f, -0.48f);
               glVertex2f(-0.35f, -0.48f);

glEnd();

    	 GLfloat xh1=-0.32f;
    GLfloat yh1=-0.67f;
    GLfloat radiusuh1 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xh1, yh1); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xh1+ (radiusuh1* cos(i *  twicePi / 180)),
                    yh1+ (radiusuh1* sin(i * twicePi / 180)) );
    }
       glEnd();

       /////left hand////
             glBegin(GL_POLYGON);
          glColor3ub(232, 0,0);
glVertex2f(-0.50f, -0.66);
glVertex2f(-0.46f, -0.66f);
 glVertex2f(-0.44f, -0.48);
glVertex2f(-0.47f, -0.48f);
glEnd();

    	 GLfloat xh2=-0.48f;
    GLfloat yh2=-0.67f;
    GLfloat radiusuh2 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xh2, yh2); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xh2+ (radiusuh2* cos(i *  twicePi / 180)),
                    yh2+ (radiusuh2* sin(i * twicePi / 180)) );
    }
       glEnd();
//////left leg/////
             glBegin(GL_POLYGON);
          glColor3ub(0,0,0);
             glVertex2f(-0.45f, -0.87);
             glVertex2f(-0.415f, -0.87);
               glVertex2f(-0.405f, -0.70);
               glVertex2f(-0.45f, -0.70);
                   glEnd();

                       	 GLfloat xl2=-0.43f;
    GLfloat yl2=-0.88f;
    GLfloat radiusul2 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xl2, yl2); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xl2+ (radiusul2* cos(i *  twicePi / 180)),
                    yl2+ (radiusul2* sin(i * twicePi / 180)) );
    }
       glEnd();
                   //////right leg/////
             glBegin(GL_POLYGON);
          glColor3ub(0,0,0);
             glVertex2f(-0.35, -0.87);
             glVertex2f(-0.385f, -0.87);
               glVertex2f(-0.395f, -0.70);
               glVertex2f(-0.35f, -0.70);
                   glEnd();
                       	 GLfloat xl=-0.37f;
    GLfloat yl=-0.88f;
    GLfloat radiusul =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xl, yl); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xl+ (radiusul* cos(i *  twicePi / 180)),
                    yl+ (radiusul* sin(i * twicePi / 180)) );
    }
       glEnd();
       glPopMatrix();
}
void man2()
{


    glTranslatef(0.0,mposition2,0.0);
glTranslatef(0.80,0.0,0.0);
      ////neck/////
       glBegin(GL_POLYGON);
          glColor3ub(232, 190, 123);
        glVertex2f(-0.44f, -0.40f);
        glVertex2f(-0.36f, -0.40f);
        glVertex2f(-0.36f, -0.50f);
        glVertex2f(-0.44f, -0.50f);

glEnd();
////////head////
       	 GLfloat x12=-0.40f;
    GLfloat y12=-0.42f;
    GLfloat radiusu12 =0.05f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x12, y12); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x12+ (radiusu12* cos(i *  twicePi / 180)),
                    y12+ (radiusu12* sin(i * twicePi / 180)) );
    }
       glEnd();

   // glTranslatef(mposition1,0.0,0.0);
    	 GLfloat x11=-0.40f;
    GLfloat y11=-0.40f;
    GLfloat radiusu11 =0.05f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x11, y11); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x11+ (radiusu11* cos(i *  twicePi / 180)),
                    y11+ (radiusu11* sin(i * twicePi / 180)) );
    }
       glEnd();
//////body/////
             glBegin(GL_POLYGON);
          glColor3ub(255, 255,0);
             glVertex2f(-0.45f, -0.70);
             glVertex2f(-0.35f, -0.70f);
               glVertex2f(-0.34f, -0.48f);
               glVertex2f(-0.46f, -0.48f);

glEnd();
/////right hand////
             glBegin(GL_POLYGON);
       glColor3ub(255, 255,0);
             glVertex2f(-0.34f, -0.66f);
             glVertex2f(-0.30f, -0.66f);
              glVertex2f(-0.33f, -0.48f);
               glVertex2f(-0.35f, -0.48f);

glEnd();

    	 GLfloat xh11=-0.32f;
    GLfloat yh11=-0.67f;
    GLfloat radiusuh11 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xh11, yh11); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xh11+ (radiusuh11* cos(i *  twicePi / 180)),
                    yh11+ (radiusuh11* sin(i * twicePi / 180)) );
    }
       glEnd();

       /////left hand////
             glBegin(GL_POLYGON);
glColor3ub(255, 255,0);
glVertex2f(-0.50f, -0.66);
glVertex2f(-0.46f, -0.66f);
 glVertex2f(-0.44f, -0.48);
glVertex2f(-0.47f, -0.48f);
glEnd();

    	 GLfloat xh21=-0.48f;
    GLfloat yh21=-0.67f;
    GLfloat radiusuh21 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xh21, yh21); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xh21+ (radiusuh21* cos(i *  twicePi / 180)),
                    yh21+ (radiusuh21* sin(i * twicePi / 180)) );
    }
       glEnd();
//////left leg/////
             glBegin(GL_POLYGON);
          glColor3ub(0,0,0);
             glVertex2f(-0.45f, -0.87);
             glVertex2f(-0.415f, -0.87);
               glVertex2f(-0.405f, -0.70);
               glVertex2f(-0.45f, -0.70);
                   glEnd();

                       	 GLfloat xl21=-0.43f;
    GLfloat yl21=-0.88f;
    GLfloat radiusul21 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xl21, yl21); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xl21+ (radiusul21* cos(i *  twicePi / 180)),
                    yl21+ (radiusul21* sin(i * twicePi / 180)) );
    }
       glEnd();
                   //////right leg/////
             glBegin(GL_POLYGON);
          glColor3ub(0,0,0);
             glVertex2f(-0.35, -0.87);
             glVertex2f(-0.385f, -0.87);
               glVertex2f(-0.395f, -0.70);
               glVertex2f(-0.35f, -0.70);
                   glEnd();
                       	 GLfloat xl1=-0.37f;
    GLfloat yl1=-0.88f;
    GLfloat radiusul1=0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xl1, yl1); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xl1+ (radiusul1* cos(i *  twicePi / 180)),
                    yl1+ (radiusul1* sin(i * twicePi / 180)) );
    }
       glEnd();

glPopMatrix();

}

void sky1()
{

//-----------------------Blue Sky-------------------------------

    glBegin(GL_POLYGON); //yellow sky
    glColor3ub(255,153,0);
    glVertex2f(-1.0f, 0.50f);
    glVertex2f(1.0f, 0.50f);
    glVertex2f(1.0f, 1.0f);

    glColor3ub(255,102,0);//orange
    glVertex2f(-1.0f, 1.0f);
    glEnd();

}
void sun1()
{
glPushMatrix();
glTranslatef(-0.10, 0.0,0.0);
    glPushMatrix();
     glTranslatef(0.0, sunposition,0.0);
        glPushMatrix();
    glTranslatef(0.2, 0.9,0.0);
  // glRotatef(angle,0.0,0.0,1);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);

	for (int i = 0; i<100; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 100;
		float r = 0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();
	glPopMatrix();
glPopMatrix();

}
void sea1()
{
    /**........................................ Sea ...........................................**/
      glPushMatrix();

    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.20f);
    glVertex2f(1.0f, -0.20f);
    glColor3f(0.808f,0.878f,0.949f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 0.50f);
    glVertex2f(-1.0f, 0.50f);
    glEnd();

    //c1..............................
   glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw1=-0.9f;
    GLfloat yw1=0.08f;
    GLfloat radiusw1 =0.3f;
     glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw1, yw1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw1 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw1 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c2..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw2=0.3f;
    GLfloat yw2=0.09f;
   glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw2, yw2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw2 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw2 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c3..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw3=0.2f;
    GLfloat yw3=0.10f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw3, yw3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw3 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw3 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



     //c4..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw4=0.1f;
    GLfloat yw4=0.08f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw4, yw4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw4 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                      yw4 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c5..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw5=-0.2f;
    GLfloat yw5=0.1f;
  glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw5, yw5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw5 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw5 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c6..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw6=-0.8f;
    GLfloat yw6=0.1f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw6, yw6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw6 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw6 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c7..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw7=-0.7f;
    GLfloat yw7=0.09f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw7, yw7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw7 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw7 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }



    glEnd();
    glPopMatrix();



    //c8..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw8=-0.6f;
    GLfloat yw8=0.1f;
      glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw8, yw8);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw8 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw8 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c9..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw9=-0.5f;
    GLfloat yw9=0.09f;
      glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw9, yw9);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw9 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw9 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c10..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw10=-0.4f;
    GLfloat yw10=0.1f;
   glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw10, yw10);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw10 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw10 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c11..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw11=-0.05f;
    GLfloat yw11=0.11f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw11, yw11);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw11 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw11 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c12..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw12=0.4f;
    GLfloat yw12=0.09f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw12, yw12);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw12 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw12 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }



    glEnd();
    glPopMatrix();



    //c13..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw13=0.5f;
    GLfloat yw13=0.1f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw13, yw13);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw13 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw13 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c14..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw14=0.6f;
    GLfloat yw14=0.11f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw14, yw14);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw14 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw14 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();



    //c15..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw15=0.7f;
    GLfloat yw15=0.09f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw15, yw15);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw15 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw15 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }



    glEnd();
    glPopMatrix();



    //c16..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw16=0.8f;
    GLfloat yw16=0.1f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw16, yw16);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw16 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                    yw16 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }



    glEnd();
    glPopMatrix();



    //c17..............................
    glPushMatrix();
    glTranslatef(0,w,0);
    GLfloat xw17=0.9f;
    GLfloat yw17=0.11f;
    glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xw17, yw17);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xw17 + (radiusw1 * cos(i *  twicePi / triangleAmount)),
                yw17 + (radiusw1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

glColor3f(0.0f,0.35f,0.859f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.20f);
    glVertex2f(1.0f, 0.20f);
    glColor3f(0.808f,0.878f,0.949f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 0.50f);
    glVertex2f(-1.0f, 0.50f);
    glEnd();

    glPopMatrix();
}


void beach1()
{
    /**........................................ beach1 ...........................................**/
      glBegin(GL_POLYGON);
    glColor3f(0.96f,0.64f,0.38f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.20f);
    glVertex2f(-1.0f, -0.20f);
glEnd();
    //////bench//////////////////
    glPushMatrix();
glTranslatef(0.0f,0.0f,0.0f);
   glLineWidth(7.0);
     glBegin(GL_LINES);

        glColor3ub(51,51,53);
	      glVertex2f(-0.92f, -0.50f);
        glVertex2f(-0.905f, -0.54f);


 glColor3ub(51,51,53);
	      glVertex2f(-0.905f, -0.68f);
        glVertex2f(-0.92f, -0.72f);


        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.72f);
        glVertex2f(-0.905f, -0.72f);

        glColor3f(0.50, 0.100, 0.00);
        glVertex2f(-0.81, -0.70f);
        glVertex2f(-0.905f, -0.70f);

          glColor3f(1.0, 0.50, 0.150);
        glVertex2f(-0.81, -0.69f);
        glVertex2f(-0.905f, -0.69f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.67f);
        glVertex2f(-0.905f, -0.67f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.65f);
        glVertex2f(-0.905f, -0.65f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81f, -0.63f);
        glVertex2f(-0.905f, -0.63f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81f, -0.61f);
        glVertex2f(-0.905f, -0.61f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.59f);
        glVertex2f(-0.905f, -0.59f);

               glColor3ub(128,128,128);
	      glVertex2f(-0.81f, -0.57f);
        glVertex2f(-0.905f, -0.57f);

               glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.55f);
        glVertex2f(-0.905f, -0.55f);

          glColor3ub(51,153,102);
	      glVertex2f(-0.81f, -0.48f);
        glVertex2f(-0.905f, -0.48f);

               glColor3ub(51,51,153);
	      glVertex2f(-0.81f, -0.50f);
        glVertex2f(-0.905f, -0.50f);

             glColor3ub(151,151,153);
	      glVertex2f(-0.81f, -0.52f);
        glVertex2f(-0.905f, -0.52f);

        glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.54f);
        glVertex2f(-0.905f, -0.54f);



      glColor3ub(255,0,0);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.80f);
        glVertex2f(-0.903f, -0.80f);


      glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.807f, -0.78f);
        glVertex2f(-0.903f, -0.78f);


           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.807f, -0.76f);
        glVertex2f(-0.903f, -0.76f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

glEnd();
glTranslatef(0.13f,0.0f,0.0f);
  glLineWidth(7.0);
     glBegin(GL_LINES);

        glColor3ub(51,51,53);
	      glVertex2f(-0.92f, -0.50f);
        glVertex2f(-0.905f, -0.54f);


 glColor3ub(51,51,53);
	      glVertex2f(-0.905f, -0.68f);
        glVertex2f(-0.92f, -0.72f);


        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.72f);
        glVertex2f(-0.905f, -0.72f);

        glColor3f(0.50, 0.100, 0.00);
        glVertex2f(-0.81, -0.70f);
        glVertex2f(-0.905f, -0.70f);

          glColor3f(1.0, 0.50, 0.150);
        glVertex2f(-0.81, -0.69f);
        glVertex2f(-0.905f, -0.69f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.67f);
        glVertex2f(-0.905f, -0.67f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.65f);
        glVertex2f(-0.905f, -0.65f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81f, -0.63f);
        glVertex2f(-0.905f, -0.63f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81f, -0.61f);
        glVertex2f(-0.905f, -0.61f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.59f);
        glVertex2f(-0.905f, -0.59f);

               glColor3ub(128,128,128);
	      glVertex2f(-0.81f, -0.57f);
        glVertex2f(-0.905f, -0.57f);

               glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.55f);
        glVertex2f(-0.905f, -0.55f);

          glColor3ub(51,153,102);
	      glVertex2f(-0.81f, -0.48f);
        glVertex2f(-0.905f, -0.48f);

               glColor3ub(51,51,153);
	      glVertex2f(-0.81f, -0.50f);
        glVertex2f(-0.905f, -0.50f);

             glColor3ub(151,151,153);
	      glVertex2f(-0.81f, -0.52f);
        glVertex2f(-0.905f, -0.52f);

        glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.54f);
        glVertex2f(-0.905f, -0.54f);



      glColor3ub(255,0,0);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.80f);
        glVertex2f(-0.903f, -0.80f);


      glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.807f, -0.78f);
        glVertex2f(-0.903f, -0.78f);


           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.807f, -0.76f);
        glVertex2f(-0.903f, -0.76f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

glEnd();

glTranslatef(0.13f,0.0f,0.0f);
  glLineWidth(7.0);
     glBegin(GL_LINES);

        glColor3ub(51,51,53);
	      glVertex2f(-0.92f, -0.50f);
        glVertex2f(-0.905f, -0.54f);


 glColor3ub(51,51,53);
	      glVertex2f(-0.905f, -0.68f);
        glVertex2f(-0.92f, -0.72f);


        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.72f);
        glVertex2f(-0.905f, -0.72f);

        glColor3f(0.50, 0.100, 0.00);
        glVertex2f(-0.81, -0.70f);
        glVertex2f(-0.905f, -0.70f);

          glColor3f(1.0, 0.50, 0.150);
        glVertex2f(-0.81, -0.69f);
        glVertex2f(-0.905f, -0.69f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.67f);
        glVertex2f(-0.905f, -0.67f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.65f);
        glVertex2f(-0.905f, -0.65f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81f, -0.63f);
        glVertex2f(-0.905f, -0.63f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81f, -0.61f);
        glVertex2f(-0.905f, -0.61f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.59f);
        glVertex2f(-0.905f, -0.59f);

               glColor3ub(128,128,128);
	      glVertex2f(-0.81f, -0.57f);
        glVertex2f(-0.905f, -0.57f);

               glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.55f);
        glVertex2f(-0.905f, -0.55f);

          glColor3ub(51,153,102);
	      glVertex2f(-0.81f, -0.48f);
        glVertex2f(-0.905f, -0.48f);

               glColor3ub(51,51,153);
	      glVertex2f(-0.81f, -0.50f);
        glVertex2f(-0.905f, -0.50f);

             glColor3ub(151,151,153);
	      glVertex2f(-0.81f, -0.52f);
        glVertex2f(-0.905f, -0.52f);

        glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.54f);
        glVertex2f(-0.905f, -0.54f);



      glColor3ub(255,0,0);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.80f);
        glVertex2f(-0.903f, -0.80f);


      glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.807f, -0.78f);
        glVertex2f(-0.903f, -0.78f);


           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.807f, -0.76f);
        glVertex2f(-0.903f, -0.76f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

glEnd();

glTranslatef(0.53f,0.0f,0.0f);
  glLineWidth(7.0);
     glBegin(GL_LINES);

        glColor3ub(51,51,53);
	      glVertex2f(-0.92f, -0.50f);
        glVertex2f(-0.905f, -0.54f);


 glColor3ub(51,51,53);
	      glVertex2f(-0.905f, -0.68f);
        glVertex2f(-0.92f, -0.72f);


        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.72f);
        glVertex2f(-0.905f, -0.72f);

        glColor3f(0.50, 0.100, 0.00);
        glVertex2f(-0.81, -0.70f);
        glVertex2f(-0.905f, -0.70f);

          glColor3f(1.0, 0.50, 0.150);
        glVertex2f(-0.81, -0.69f);
        glVertex2f(-0.905f, -0.69f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.67f);
        glVertex2f(-0.905f, -0.67f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.65f);
        glVertex2f(-0.905f, -0.65f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81f, -0.63f);
        glVertex2f(-0.905f, -0.63f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81f, -0.61f);
        glVertex2f(-0.905f, -0.61f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.59f);
        glVertex2f(-0.905f, -0.59f);

               glColor3ub(128,128,128);
	      glVertex2f(-0.81f, -0.57f);
        glVertex2f(-0.905f, -0.57f);

               glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.55f);
        glVertex2f(-0.905f, -0.55f);

          glColor3ub(51,153,102);
	      glVertex2f(-0.81f, -0.48f);
        glVertex2f(-0.905f, -0.48f);

               glColor3ub(51,51,153);
	      glVertex2f(-0.81f, -0.50f);
        glVertex2f(-0.905f, -0.50f);

             glColor3ub(151,151,153);
	      glVertex2f(-0.81f, -0.52f);
        glVertex2f(-0.905f, -0.52f);

        glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.54f);
        glVertex2f(-0.905f, -0.54f);



      glColor3ub(255,0,0);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.80f);
        glVertex2f(-0.903f, -0.80f);


      glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.807f, -0.78f);
        glVertex2f(-0.903f, -0.78f);


           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.807f, -0.76f);
        glVertex2f(-0.903f, -0.76f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

glEnd();
glTranslatef(0.13f,0.0f,0.0f);
  glLineWidth(7.0);
     glBegin(GL_LINES);

        glColor3ub(51,51,53);
	      glVertex2f(-0.92f, -0.50f);
        glVertex2f(-0.905f, -0.54f);


 glColor3ub(51,51,53);
	      glVertex2f(-0.905f, -0.68f);
        glVertex2f(-0.92f, -0.72f);


        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.72f);
        glVertex2f(-0.905f, -0.72f);

        glColor3f(0.50, 0.100, 0.00);
        glVertex2f(-0.81, -0.70f);
        glVertex2f(-0.905f, -0.70f);

          glColor3f(1.0, 0.50, 0.150);
        glVertex2f(-0.81, -0.69f);
        glVertex2f(-0.905f, -0.69f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.67f);
        glVertex2f(-0.905f, -0.67f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.65f);
        glVertex2f(-0.905f, -0.65f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81f, -0.63f);
        glVertex2f(-0.905f, -0.63f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81f, -0.61f);
        glVertex2f(-0.905f, -0.61f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.59f);
        glVertex2f(-0.905f, -0.59f);

               glColor3ub(128,128,128);
	      glVertex2f(-0.81f, -0.57f);
        glVertex2f(-0.905f, -0.57f);

               glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.55f);
        glVertex2f(-0.905f, -0.55f);

          glColor3ub(51,153,102);
	      glVertex2f(-0.81f, -0.48f);
        glVertex2f(-0.905f, -0.48f);

               glColor3ub(51,51,153);
	      glVertex2f(-0.81f, -0.50f);
        glVertex2f(-0.905f, -0.50f);

             glColor3ub(151,151,153);
	      glVertex2f(-0.81f, -0.52f);
        glVertex2f(-0.905f, -0.52f);

        glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.54f);
        glVertex2f(-0.905f, -0.54f);



      glColor3ub(255,0,0);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.80f);
        glVertex2f(-0.903f, -0.80f);


      glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.807f, -0.78f);
        glVertex2f(-0.903f, -0.78f);


           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.807f, -0.76f);
        glVertex2f(-0.903f, -0.76f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

glEnd();

glTranslatef(0.63f,0.0f,0.0f);
  glLineWidth(7.0);
     glBegin(GL_LINES);

        glColor3ub(51,51,53);
	      glVertex2f(-0.92f, -0.50f);
        glVertex2f(-0.905f, -0.54f);


 glColor3ub(51,51,53);
	      glVertex2f(-0.905f, -0.68f);
        glVertex2f(-0.92f, -0.72f);


        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.72f);
        glVertex2f(-0.905f, -0.72f);

        glColor3f(0.50, 0.100, 0.00);
        glVertex2f(-0.81, -0.70f);
        glVertex2f(-0.905f, -0.70f);

          glColor3f(1.0, 0.50, 0.150);
        glVertex2f(-0.81, -0.69f);
        glVertex2f(-0.905f, -0.69f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.67f);
        glVertex2f(-0.905f, -0.67f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.65f);
        glVertex2f(-0.905f, -0.65f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81f, -0.63f);
        glVertex2f(-0.905f, -0.63f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81f, -0.61f);
        glVertex2f(-0.905f, -0.61f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.59f);
        glVertex2f(-0.905f, -0.59f);

               glColor3ub(128,128,128);
	      glVertex2f(-0.81f, -0.57f);
        glVertex2f(-0.905f, -0.57f);

               glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.55f);
        glVertex2f(-0.905f, -0.55f);

          glColor3ub(51,153,102);
	      glVertex2f(-0.81f, -0.48f);
        glVertex2f(-0.905f, -0.48f);

               glColor3ub(51,51,153);
	      glVertex2f(-0.81f, -0.50f);
        glVertex2f(-0.905f, -0.50f);

             glColor3ub(151,151,153);
	      glVertex2f(-0.81f, -0.52f);
        glVertex2f(-0.905f, -0.52f);

        glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.54f);
        glVertex2f(-0.905f, -0.54f);



      glColor3ub(255,0,0);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.80f);
        glVertex2f(-0.903f, -0.80f);


      glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.807f, -0.78f);
        glVertex2f(-0.903f, -0.78f);


           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.807f, -0.76f);
        glVertex2f(-0.903f, -0.76f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

glEnd();

glTranslatef(0.13f,0.0f,0.0f);
  glLineWidth(7.0);
     glBegin(GL_LINES);

        glColor3ub(51,51,53);
	      glVertex2f(-0.92f, -0.50f);
        glVertex2f(-0.905f, -0.54f);


 glColor3ub(51,51,53);
	      glVertex2f(-0.905f, -0.68f);
        glVertex2f(-0.92f, -0.72f);


        glColor3f(0.50, 0.00, 0.00);
        glVertex2f(-0.81f, -0.72f);
        glVertex2f(-0.905f, -0.72f);

        glColor3f(0.50, 0.100, 0.00);
        glVertex2f(-0.81, -0.70f);
        glVertex2f(-0.905f, -0.70f);

          glColor3f(1.0, 0.50, 0.150);
        glVertex2f(-0.81, -0.69f);
        glVertex2f(-0.905f, -0.69f);

           glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.81, -0.67f);
        glVertex2f(-0.905f, -0.67f);

               glColor3ub(244,128,0);
        glVertex2f(-0.81, -0.65f);
        glVertex2f(-0.905f, -0.65f);

               glColor3ub(245, 141, 26);
        glVertex2f(-0.81f, -0.63f);
        glVertex2f(-0.905f, -0.63f);

        glColor3ub(232, 128, 52);
        glVertex2f(-0.81f, -0.61f);
        glVertex2f(-0.905f, -0.61f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.81f, -0.59f);
        glVertex2f(-0.905f, -0.59f);

               glColor3ub(128,128,128);
	      glVertex2f(-0.81f, -0.57f);
        glVertex2f(-0.905f, -0.57f);

               glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.55f);
        glVertex2f(-0.905f, -0.55f);

          glColor3ub(51,153,102);
	      glVertex2f(-0.81f, -0.48f);
        glVertex2f(-0.905f, -0.48f);

               glColor3ub(51,51,153);
	      glVertex2f(-0.81f, -0.50f);
        glVertex2f(-0.905f, -0.50f);

             glColor3ub(151,151,153);
	      glVertex2f(-0.81f, -0.52f);
        glVertex2f(-0.905f, -0.52f);

        glColor3ub(128,0,0);
	      glVertex2f(-0.81f, -0.54f);
        glVertex2f(-0.905f, -0.54f);



      glColor3ub(255,0,0);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

               glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.80f);
        glVertex2f(-0.903f, -0.80f);


      glColor3f(1.0, .50, 0.50);
        glVertex2f(-0.807f, -0.78f);
        glVertex2f(-0.903f, -0.78f);


           glColor3f(1.00, 0.50, 0.00);
        glVertex2f(-0.807f, -0.76f);
        glVertex2f(-0.903f, -0.76f);

             glColor3f(0.33, 0.19, 0.19);
	      glVertex2f(-0.807f, -0.74f);
        glVertex2f(-0.903f, -0.74f);

glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.0, 0.0);
	 GLfloat xu1=-0.91f;
    GLfloat yu1=-0.72f;
    GLfloat radiusu1 =0.06f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xu1, yu1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xu1 + (radiusu1* cos(i *  twicePi / triangleAmount)),
                    yu1+ (radiusu1 * sin(i * twicePi / triangleAmount)) );
    }
       glEnd();
glTranslatef(0.13, 0.0, 0.0);
	 GLfloat xu2=-0.91f;
    GLfloat yu2=-0.72f;
    GLfloat radiusu2 =0.06f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xu2, yu2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xu2 + (radiusu2* cos(i *  twicePi / triangleAmount)),
                    yu2+ (radiusu2 * sin(i * twicePi / triangleAmount)) );
    }
       glEnd();

       glTranslatef(0.13, 0.0, 0.0);
	 GLfloat xu3=-0.91f;
    GLfloat yu3=-0.72f;
    GLfloat radiusu3 =0.06f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xu3, yu3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xu3 + (radiusu3* cos(i *  twicePi / triangleAmount)),
                    yu3+ (radiusu3 * sin(i * twicePi / triangleAmount)) );
    }
       glEnd();

       glTranslatef(0.53, 0.0, 0.0);
	 GLfloat xu5=-0.91f;
    GLfloat yu5=-0.72f;
    GLfloat radiusu5 =0.06f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xu5, yu5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xu5 + (radiusu5* cos(i *  twicePi / triangleAmount)),
                    yu5+ (radiusu5 * sin(i * twicePi / triangleAmount)) );
    }
       glEnd();

       glTranslatef(0.13, 0.0, 0.0);
	 GLfloat xu6=-0.91f;
    GLfloat yu6=-0.72f;
    GLfloat radiusu6 =0.06f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xu6, yu6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xu6 + (radiusu6* cos(i *  twicePi / triangleAmount)),
                    yu6+ (radiusu6 * sin(i * twicePi / triangleAmount)) );
    }
       glEnd();
       glTranslatef(0.63, 0.0, 0.0);
	 GLfloat xu7=-0.91f;
    GLfloat yu7=-0.72f;
    GLfloat radiusu7 =0.06f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xu7, yu7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xu7 + (radiusu7* cos(i *  twicePi / triangleAmount)),
                    yu7+ (radiusu7 * sin(i * twicePi / triangleAmount)) );
    }
       glEnd();
       glTranslatef(0.13, 0.0, 0.0);
	 GLfloat xu8=-0.91f;
    GLfloat yu8=-0.72f;
    GLfloat radiusu8 =0.06f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xu8, yu8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xu8+ (radiusu8* cos(i *  twicePi / triangleAmount)),
                    yu8+ (radiusu8* sin(i * twicePi / triangleAmount)) );
    }
       glEnd();
glPopMatrix();

}

void sky2()
{
glPushMatrix();
     glTranslatef(0.0,moonposition,0.0);
	GLfloat x = -0.85f; GLfloat y = 0.40; GLfloat radius = .065f;       //moon
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 241, 213);
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

						  //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
	glPopMatrix();
}

 void bigboat1()
   {



    /**.................................... big boat-structure .......................................**/
  glPushMatrix();
    glTranslatef( positionboat1,0.0f,0.0f);
    glPushMatrix();
    glTranslatef(-0.20f, 0.30f,0.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.25f, -0.05f);
    glVertex2f(0.1f, -0.05f);
    glVertex2f(0.25f, 0.1f);
    glEnd();





    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.27f, -0.03f);
    glVertex2f(-0.25f, -0.05f);
    glVertex2f(0.1f, -0.05f);
    glVertex2f(0.12f, -0.03f);
    glEnd();





    glColor3f(0.769f,0.067f,0.067f);
    glBegin(GL_QUADS);
    glVertex2f(-0.33f, 0.03f);
    glVertex2f(-0.27f, -0.03f);
    glVertex2f(0.12f, -0.03f);
    glVertex2f(0.18f, 0.03f);
    glEnd();





    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, 0.15f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.23f,0.1f);
    glVertex2f(-0.28f, 0.15f);
    glEnd();





    glColor3f(0.788f,0.761f,0.761f);
    glBegin(GL_QUADS);
    glVertex2f(-0.37f, 0.33f);
    glVertex2f(-0.37f, 0.15f);
    glVertex2f(-0.28f,0.15f);
    glVertex2f(-0.28f, 0.33f);
    glEnd();





    glColor3f(0.788f,0.761f,0.761f);
    glBegin(GL_QUADS);
    glVertex2f(-0.28f, 0.33f);
    glVertex2f(-0.28f, 0.15f);
    glVertex2f(-0.23f,0.10f);
    glVertex2f(-0.23f, 0.33f);
    glEnd();





    glColor3f(0.788f,0.761f,0.761f);
    glBegin(GL_QUADS);
    glVertex2f(-0.23f, 0.33f);
    glVertex2f(-0.23f, 0.1f);
    glVertex2f(-0.03f,0.1f);
    glVertex2f(-0.03f, 0.33f);
    glEnd();





    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.37f, 0.283f);
    glVertex2f(-0.37f, 0.26f);
    glVertex2f(-0.03f,0.26f);
    glVertex2f(-0.03f, 0.283f);
    glEnd();





    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.37f, 0.315f);
    glVertex2f(-0.37f, 0.30f);
    glVertex2f(-0.03f,0.30f);
    glVertex2f(-0.03f, 0.315f);
    glEnd();





    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.345f, 0.38f);
    glVertex2f(-0.345f, 0.33f);
    glVertex2f(-0.138f,0.33f);
    glVertex2f(-0.138f, 0.38f);
    glEnd();





    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.115f, 0.38f);
    glVertex2f(-0.115f, 0.33f);
    glVertex2f(-0.04f,0.33f);
    glVertex2f(-0.04f, 0.38f);
    glEnd();





    glColor3f(0.788f,0.761f,0.761f);
    glBegin(GL_QUADS);
    glVertex2f(-0.345f, 0.435f);
    glVertex2f(-0.345f, 0.38f);
    glVertex2f(-0.138f,0.38f);
    glVertex2f(-0.138f, 0.435f);
    glEnd();





    glColor3f(0.788f,0.761f,0.761f);
    glBegin(GL_QUADS);
    glVertex2f(-0.115f, 0.42f);
    glVertex2f(-0.115f, 0.38f);
    glVertex2f(-0.04f,0.38f);
    glVertex2f(-0.04f, 0.42f);
    glEnd();





   glColor3f(0.6f,0.588f,0.565f);
    glBegin(GL_QUADS);
    glVertex2f(-0.33f, 0.465f);
    glVertex2f(-0.345f, 0.435f);
    glVertex2f(-0.138f,0.435f);
    glVertex2f(-0.156f, 0.465f);
    glEnd();





    glColor3f(0.6f,0.588f,0.565f);
    glBegin(GL_QUADS);
    glVertex2f(-0.108f,0.444f);
    glVertex2f(-0.115f,0.42f);
    glVertex2f(-0.04f,0.42f);
    glVertex2f(-0.048f,0.444f);
    glEnd();
    /**.................................... big boat-design .......................................**/
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.335f, 0.42f);
    glVertex2f(-0.335f, 0.393f);
    glVertex2f(-0.31f,0.393f);
    glVertex2f(-0.31f, 0.42f);
    glEnd();





    glPushMatrix();
    glTranslatef(0.033f, 0.0f, 0.0f);
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.335f, 0.42f);
    glVertex2f(-0.335f, 0.393f);
    glVertex2f(-0.31f,0.393f);
    glVertex2f(-0.31f, 0.42f);
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.065f, 0.0f, 0.0f);
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.335f, 0.42f);
    glVertex2f(-0.335f, 0.393f);
    glVertex2f(-0.31f,0.393f);
    glVertex2f(-0.31f, 0.42f);
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.098f, 0.0f, 0.0f);
     glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.335f, 0.42f);
    glVertex2f(-0.335f, 0.393f);
    glVertex2f(-0.31f,0.393f);
    glVertex2f(-0.31f, 0.42f);
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.13f, 0.0f, 0.0f);
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.335f, 0.42f);
    glVertex2f(-0.335f, 0.393f);
    glVertex2f(-0.31f,0.393f);
    glVertex2f(-0.31f, 0.42f);
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.163f, 0.0f, 0.0f);
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.335f, 0.42f);
    glVertex2f(-0.335f, 0.393f);
    glVertex2f(-0.31f,0.393f);
    glVertex2f(-0.31f, 0.42f);
    glEnd();
    glPopMatrix();
    glLineWidth(3.0);
             glColor3ub(170,169,173);
glBegin(GL_LINES);
     glVertex2f(-0.355f, 0.365f);
       glVertex2f(-0.355, 0.33f);
glEnd();
             glLineWidth(3.0);
          glColor3ub(170,169,173);
glBegin(GL_LINES);
     glVertex2f(-0.355f, 0.365f);
       glVertex2f(-0.32, 0.365f);
glEnd();
       glLineWidth(3.0);
       glColor3ub(170,169,173);
glBegin(GL_LINES);
     glVertex2f(-0.32f, 0.365f);
       glVertex2f(-0.32, 0.33f);
glEnd();
     glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.32f, 0.365f);
       glVertex2f(-0.285, 0.365f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.285f, 0.365f);
       glVertex2f(-0.285, 0.33f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.285f, 0.365f);
       glVertex2f(-0.25, 0.365f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.25f, 0.365f);
       glVertex2f(-0.25, 0.33f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.25f, 0.365f);
       glVertex2f(-0.215, 0.365f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.215f, 0.365f);
       glVertex2f(-0.215, 0.33f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.215f, 0.365f);
       glVertex2f(-0.18, 0.365f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.18f, 0.365f);
       glVertex2f(-0.18, 0.33f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.18f, 0.365f);
       glVertex2f(-0.145, 0.365f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.145f, 0.365f);
       glVertex2f(-0.145, 0.33f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.145f, 0.365f);
       glVertex2f(-0.11, 0.365f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.11f, 0.365f);
       glVertex2f(-0.11, 0.33f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.11f, 0.365f);
       glVertex2f(-0.075, 0.365f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.075f, 0.365f);
       glVertex2f(-0.075, 0.33f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.075f, 0.365f);
       glVertex2f(-0.04, 0.365f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.04f, 0.365f);
       glVertex2f(-0.04, 0.33f);
glEnd();





glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.24f, 0.63f);
       glVertex2f(-0.24, 0.436f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.24f, 0.63f);
       glVertex2f(-0.138, 0.436f);
glEnd();
glLineWidth(3.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.24f, 0.63f);
       glVertex2f(-0.31, 0.465f);
glEnd();
glLineWidth(3.0);
            glColor3ub(120,120,120);
glBegin(GL_LINES);
    glVertex2f(-0.275f, 0.58f);
       glVertex2f(-0.2, 0.58f);
glEnd();
glLineWidth(3.0);
           glColor3ub(120,120,120);
glBegin(GL_LINES);
    glVertex2f(-0.3f, 0.53f);
       glVertex2f(-0.17, 0.53f);
glEnd();
glLineWidth(8.0);
           glColor3ub(90,90,90);
glBegin(GL_LINES);
    glVertex2f(-0.095f, 0.513f);
       glVertex2f(-0.095, 0.444f);
glEnd();
glLineWidth(8.0);
            glColor3ub(90,90,90);
glBegin(GL_LINES);
    glVertex2f(-0.10f, 0.51f);
       glVertex2f(-0.05, 0.51f);
glEnd();
glLineWidth(8.0);
            glColor3ub(90,90,90);
glBegin(GL_LINES);
    glVertex2f(-0.07f, 0.48f);
       glVertex2f(-0.07, 0.444f);
glEnd();
glLineWidth(7.0);
            glColor3ub(90,90,90);
glBegin(GL_LINES);
    glVertex2f(-0.07f, 0.473f);
       glVertex2f(-0.04, 0.473f);
glEnd();
//door.............
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.229f, 0.22f);
       glVertex2f(-0.229, 0.10f);
glEnd();
glLineWidth(3.0);
          glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.231f, 0.22f);
       glVertex2f(-0.178, 0.22f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.18f, 0.22f);
       glVertex2f(-0.18, 0.10f);
glEnd();
    glColor3f(0.788f,0.506f,0.039f);
    glBegin(GL_QUADS);
    glVertex2f(-0.227f, 0.215f);
    glVertex2f(-0.227f, 0.10f);
    glVertex2f(-0.182f,0.10f);
    glVertex2f(-0.182f, 0.215f);
    glEnd();
//window............
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.141f, 0.22f);
       glVertex2f(-0.141, 0.145f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.143f, 0.22f);
       glVertex2f(-0.09, 0.22f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.092f, 0.22f);
       glVertex2f(-0.092, 0.145f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.09f, 0.145f);
       glVertex2f(-0.143, 0.145f);
glEnd();
glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.139f, 0.217f);
    glVertex2f(-0.139f, 0.149f);
    glVertex2f(-0.094f,0.149f);
    glVertex2f(-0.094f, 0.217f);
    glEnd();





    GLfloat xboat1=0.01f;
    GLfloat yboat1=0.072f;
    GLfloat radiusb =0.021f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat1, yboat1);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat1 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat1 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();





    GLfloat xboat2=0.01f;
    GLfloat yboat2=0.072f;
    GLfloat radiusa =0.0135f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat2, yboat2);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat2 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat2 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();





    glPushMatrix();
    glTranslatef(0.048f, 0.0f, 0.0f);
    GLfloat xboat3=0.01f;
    GLfloat yboat3=0.072f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat3, yboat3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat3 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat3 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.048f, 0.0f, 0.0f);
    GLfloat xboat4=0.01f;
    GLfloat yboat4=0.072f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat4, yboat4);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat4 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat4 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.097f, 0.0f, 0.0f);
    GLfloat xboat5=0.01f;
    GLfloat yboat5=0.072f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat5, yboat5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat5 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat5 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.097f, 0.0f, 0.0f);
    GLfloat xboat6=0.01f;
    GLfloat yboat6=0.072f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat6, yboat6);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat6 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat6 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.147f, 0.0f, 0.0f);
    GLfloat xboat7=0.01f;
    GLfloat yboat7=0.072f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat7, yboat7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat7 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat7 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.147f, 0.0f, 0.0f);
    GLfloat xboat8=0.01f;
    GLfloat yboat8=0.072f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat8, yboat8);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat8 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat8 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    GLfloat xboat9=-0.29f;
    GLfloat yboat9=0.125f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat9, yboat9);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat9 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat9 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    GLfloat xboat10=-0.29f;
    GLfloat yboat10=0.125f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat10, yboat10);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat10 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat10 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();





    glPushMatrix();
    glTranslatef(-0.047f, 0.0f, 0.0f);
    GLfloat xboat11=-0.29f;
    GLfloat yboat11=0.125f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat11, yboat11);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat11 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat11 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(-0.047f,0.0f,0.0f);
    GLfloat xboat12=-0.29f;
    GLfloat yboat12=0.125f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat12, yboat12);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat12 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat12 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(-0.095f, 0.0f, 0.0f);
    GLfloat xboat13=-0.29f;
    GLfloat yboat13=0.125f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat13, yboat13);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat13 + (radiusb * cos(i *  twicePi / triangleAmount)),
                    yboat13 + (radiusb * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(-0.095f,0.0f,0.0f);
    GLfloat xboat14=-0.29f;
    GLfloat yboat14=0.125f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat14, yboat14);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat14 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat14 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();





    GLfloat xboat15=-0.205f;
    GLfloat yboat15=0.178f;
     glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat15, yboat15);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat15 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat15 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();





    GLfloat xboat16=-0.32f;
    GLfloat yboat16=0.248f;
     glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat16, yboat16);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat16 + (radiusa * cos(i * twicePi / triangleAmount)),
                    yboat16 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    GLfloat xboat17=-0.35f;
    GLfloat yboat17=0.248f;
     glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat17, yboat17);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat17 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat17 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();





    GLfloat xboat18=-0.29f;
    GLfloat yboat18=0.248f;
     glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xboat18, yboat18);





    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xboat18 + (radiusa * cos(i *  twicePi / triangleAmount)),
                    yboat18 + (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(0.056f, 0.10f);
       glVertex2f(0.056, 0.084f);
glEnd();





glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(0.01f, 0.10f);
       glVertex2f(0.01, 0.084f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(0.105f, 0.10f);
       glVertex2f(0.105, 0.084f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(0.155f, 0.10f);
       glVertex2f(0.155, 0.084f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.339f, 0.15f);
       glVertex2f(-0.339, 0.136f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.386f, 0.15f);
       glVertex2f(-0.386, 0.136f);
glEnd();
glLineWidth(3.0);
           glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINES);
    glVertex2f(-0.29f, 0.15f);
       glVertex2f(-0.29, 0.136f);
glEnd();



glPopMatrix();
glPopMatrix();

   }
void boat10()
{



/**.................................... small boat-1 .......................................**/




        glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(0.6f, -0.05f);
        glVertex2f(0.7f, -0.15f);
        glVertex2f(0.8f, -0.15f);
        glVertex2f(0.9f, -0.05f);
        glEnd();



        glColor3f(1.0f,0.984f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.71f, -0.03f);
        glVertex2f(0.74f, 0.05f);
        glVertex2f(0.74, -0.03f);
        glEnd();



        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.75f, -0.03f);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(0.75f, 0.15f);
        glVertex2f(0.8, -0.03f);
        glEnd();
        glLineWidth(4.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(0.86f, 0.25f);
       glVertex2f(0.86, -0.20f);
glEnd();
glLineWidth(4.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(0.83f, -0.05f);
       glVertex2f(0.86, 0.05f);
glEnd();
/**.................................... small boat-1 .......................................**/



glBegin(GL_QUADS);
        glColor3ub(51,51,0);
        glVertex2f(-0.6f, -0.05f);
        glVertex2f(-0.7f, -0.15f);
        glVertex2f(-0.8f, -0.15f);
        glVertex2f(-0.9f, -0.05f);
        glEnd();



        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.71f, -0.03f);
        glVertex2f(-0.74f, 0.05f);
        glVertex2f(-0.74, -0.03f);
        glEnd();



        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.75f, -0.03f);
        glColor3f(1.0f,0.0f,0.62f);
        glVertex2f(-0.75f, 0.15f);
        glVertex2f(-0.8, -0.03f);
        glEnd();
        glLineWidth(4.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.64f, 0.25f);
       glVertex2f(-0.64, -0.20f);
glEnd();
glLineWidth(4.0);
           glColor3ub(170,169,173);
glBegin(GL_LINES);
    glVertex2f(-0.67f, -0.05f);
       glVertex2f(-0.64, 0.05f);
glEnd();


   }

void display1() {
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
   // glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    renderBitmapString(0.0, 0.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Scenery of a Mountain");

//-----------------------Dark Ash Ground-------------------------------

    glBegin(GL_POLYGON); //Green Ground
    glColor3ub(128,128,128);
    glVertex2f(-1.0f, .38f);
    glVertex2f(1.0f, 0.38f);
    glVertex2f(1.0f, 0.60f);
    glVertex2f(-1.0f, 0.60f);
    glEnd();

    //-----------------------ASh Ground-------------------------------

    glBegin(GL_POLYGON); //ASh Ground
    glColor3ub(155,137,95);
    glVertex2f(-1.0f, -0.20f);
    glVertex2f(1.0f, -0.20f);
    glVertex2f(1.0f, 0.38f);
    glVertex2f(-1.0f, 0.38f);
    glEnd();


    //right blding 1

    glBegin(GL_QUADS);
     glColor3ub(163, 163, 194);
     glVertex2f(0.05,0.40);
     glVertex2f(0.05,0.90);
     glVertex2f(-0.05,0.90);
     glVertex2f(-0.05,0.40);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(179, 179, 204);
     glVertex2f(0.17,0.40);
     glVertex2f(0.17,0.90);
     glVertex2f(0.05,0.90);
     glVertex2f(0.05,0.40);
     glEnd();

//glass
     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.82);
     glVertex2f(0.16,0.83);
     glVertex2f(0.06,0.83);
     glVertex2f(0.06,0.82);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.82);
     glVertex2f(0.16,0.83);
     glVertex2f(0.06,0.83);
     glVertex2f(0.06,0.82);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.80);
     glVertex2f(0.16,0.81);
     glVertex2f(0.06,0.81);
     glVertex2f(0.06,0.80);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.78);
     glVertex2f(0.16,0.79);
     glVertex2f(0.06,0.79);
     glVertex2f(0.06,0.78);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.76);
     glVertex2f(0.16,0.77);
     glVertex2f(0.06,0.77);
     glVertex2f(0.06,0.76);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.74);
     glVertex2f(0.16,0.75);
     glVertex2f(0.06,0.75);
     glVertex2f(0.06,0.74);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.72);
     glVertex2f(0.16,0.73);
     glVertex2f(0.06,0.73);
     glVertex2f(0.06,0.72);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.70);
     glVertex2f(0.16,0.71);
     glVertex2f(0.06,0.71);
     glVertex2f(0.06,0.70);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.68);
     glVertex2f(0.16,0.69);
     glVertex2f(0.06,0.69);
     glVertex2f(0.06,0.68);
     glEnd();
 glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.66);
     glVertex2f(0.16,0.67);
     glVertex2f(0.06,0.67);
     glVertex2f(0.06,0.66);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.64);
     glVertex2f(0.16,0.65);
     glVertex2f(0.06,0.65);
     glVertex2f(0.06,0.64);
     glEnd();//
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.62);
     glVertex2f(0.16,0.63);
     glVertex2f(0.06,0.63);
     glVertex2f(0.06,0.62);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.60);
     glVertex2f(0.16,0.61);
     glVertex2f(0.06,0.61);
     glVertex2f(0.06,0.60);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.58);
     glVertex2f(0.16,0.59);
     glVertex2f(0.06,0.59);
     glVertex2f(0.06,0.58);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.56);
     glVertex2f(0.16,0.57);
     glVertex2f(0.06,0.57);
     glVertex2f(0.06,0.56);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.54);
     glVertex2f(0.16,0.55);
     glVertex2f(0.06,0.55);
     glVertex2f(0.06,0.54);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.52);
     glVertex2f(0.16,0.53);
     glVertex2f(0.06,0.53);
     glVertex2f(0.06,0.52);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.50);
     glVertex2f(0.16,0.51);
     glVertex2f(0.06,0.51);
     glVertex2f(0.06,0.50);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.48);
     glVertex2f(0.16,0.49);
     glVertex2f(0.06,0.49);
     glVertex2f(0.06,0.48);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.46);
     glVertex2f(0.16,0.47);
     glVertex2f(0.06,0.47);
     glVertex2f(0.06,0.46);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.44);
     glVertex2f(0.16,0.45);
     glVertex2f(0.06,0.45);
     glVertex2f(0.06,0.44);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.42);
     glVertex2f(0.16,0.43);
     glVertex2f(0.06,0.43);
     glVertex2f(0.06,0.42);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.40);
     glVertex2f(0.16,0.41);
     glVertex2f(0.06,0.41);
     glVertex2f(0.06,0.40);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.38);
     glVertex2f(0.16,0.39);
     glVertex2f(0.06,0.39);
     glVertex2f(0.06,0.38);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.36);
     glVertex2f(0.16,0.37);
     glVertex2f(0.06,0.37);
     glVertex2f(0.06,0.36);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.34);
     glVertex2f(0.16,0.35);
     glVertex2f(0.06,0.35);
     glVertex2f(0.06,0.34);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.32);
     glVertex2f(0.16,0.33);
     glVertex2f(0.06,0.33);
     glVertex2f(0.06,0.32);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(193, 215, 215);
     glVertex2f(0.16,0.30);
     glVertex2f(0.16,0.31);
     glVertex2f(0.06,0.31);
     glVertex2f(0.06,0.30);
     glEnd();


//Right blding 2

     glBegin(GL_QUADS);
     glColor3ub(117, 163, 163);
     glVertex2f(0.25,0.40);
     glVertex2f(0.25,0.82);
     glVertex2f(0.17,0.82);
     glVertex2f(0.17,0.40);
     glEnd();

//Right blding 3

     glBegin(GL_QUADS);
     glColor3ub(133, 173, 173);
     glVertex2f(0.37,0.50);
     glVertex2f(0.37,0.84);
     glVertex2f(0.25,0.84);
     glVertex2f(0.25,0.50);
     glEnd();

//GLASS
      glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.365,0.50);
     glVertex2f(0.365,0.835);
     glVertex2f(0.30,0.835);
     glVertex2f(0.30,0.50);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.29,0.50);
     glVertex2f(0.29,0.835);
     glVertex2f(0.255,0.835);
     glVertex2f(0.255,0.50);
     glEnd();



//Right blding 5

     glBegin(GL_QUADS);
     glColor3ub(117, 163, 163);
     glVertex2f(0.53,0.50);
     glVertex2f(0.53,0.85);
     glVertex2f(0.37,0.85);
     glVertex2f(0.37,0.50);
     glEnd();


//glass
glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.84);
     glVertex2f(0.525,0.83);
     glVertex2f(0.42,0.83);
     glVertex2f(0.42,0.84);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.82);
     glVertex2f(0.525,0.81);
     glVertex2f(0.42,0.81);
     glVertex2f(0.42,0.82);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.80);
     glVertex2f(0.525,0.79);
     glVertex2f(0.42,0.79);
     glVertex2f(0.42,0.80);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.78);
     glVertex2f(0.525,0.77);
     glVertex2f(0.42,0.77);
     glVertex2f(0.42,0.78);
     glEnd();



     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.76);
     glVertex2f(0.525,0.75);
     glVertex2f(0.42,0.75);
     glVertex2f(0.42,0.76);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.74);
     glVertex2f(0.525,0.73);
     glVertex2f(0.42,0.73);
     glVertex2f(0.42,0.74);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.72);
     glVertex2f(0.525,0.71);
     glVertex2f(0.42,0.71);
     glVertex2f(0.42,0.72);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.70);
     glVertex2f(0.525,0.61);
     glVertex2f(0.42,0.61);
     glVertex2f(0.42,0.70);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.68);
     glVertex2f(0.525,0.67);
     glVertex2f(0.42,0.67);
     glVertex2f(0.42,0.68);
     glEnd();



     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.66);
     glVertex2f(0.525,0.65);
     glVertex2f(0.42,0.65);
     glVertex2f(0.42,0.66);
     glEnd();

 glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.64);
     glVertex2f(0.525,0.63);
     glVertex2f(0.42,0.63);
     glVertex2f(0.42,0.64);
     glEnd();

 glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.62);
     glVertex2f(0.525,0.61);
     glVertex2f(0.42,0.61);
     glVertex2f(0.42,0.62);
     glEnd();

 glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.60);
     glVertex2f(0.525,0.59);
     glVertex2f(0.42,0.59);
     glVertex2f(0.42,0.60);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.58);
     glVertex2f(0.525,0.57);
     glVertex2f(0.42,0.57);
     glVertex2f(0.42,0.58);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.56);
     glVertex2f(0.525,0.55);
     glVertex2f(0.42,0.55);
     glVertex2f(0.42,0.56);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.54);
     glVertex2f(0.525,0.53);
     glVertex2f(0.42,0.53);
     glVertex2f(0.42,0.54);
     glEnd();

 glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.52);
     glVertex2f(0.525,0.51);
     glVertex2f(0.42,0.51);
     glVertex2f(0.42,0.52);
     glEnd();


 glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.50);
     glVertex2f(0.525,0.49);
     glVertex2f(0.42,0.49);
     glVertex2f(0.42,0.50);
     glEnd();

 glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.48);
     glVertex2f(0.525,0.47);
     glVertex2f(0.42,0.47);
     glVertex2f(0.42,0.48);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.46);
     glVertex2f(0.525,0.45);
     glVertex2f(0.42,0.45);
     glVertex2f(0.42,0.46);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.44);
     glVertex2f(0.525,0.43);
     glVertex2f(0.42,0.43);
     glVertex2f(0.42,0.44);
     glEnd();


    glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.42);
     glVertex2f(0.525,0.41);
     glVertex2f(0.42,0.41);
     glVertex2f(0.42,0.42);
     glEnd();

    glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.40);
     glVertex2f(0.525,0.39);
     glVertex2f(0.42,0.39);
     glVertex2f(0.42,0.40);
     glEnd();

    glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.38);
     glVertex2f(0.525,0.37);
     glVertex2f(0.42,0.37);
     glVertex2f(0.42,0.38);
     glEnd();


      glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.36);
     glVertex2f(0.525,0.35);
     glVertex2f(0.42,0.35);
     glVertex2f(0.42,0.36);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.34);
     glVertex2f(0.525,0.33);
     glVertex2f(0.42,0.33);
     glVertex2f(0.42,0.34);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.32);
     glVertex2f(0.525,0.31);
     glVertex2f(0.42,0.31);
     glVertex2f(0.42,0.32);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(0.525,0.25);
     glVertex2f(0.525,0.26);
     glVertex2f(0.42,0.26);
     glVertex2f(0.42,0.25);
     glEnd();



//LEFT SIDE BLDING 1  //************************


     glBegin(GL_QUADS);
     glColor3ub(204, 51, 0);
     glVertex2f(-.95,0.38);
     glVertex2f(-.95,0.85);
     glVertex2f(-1.0,0.85);
     glVertex2f(-1.0,0.38);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(230, 57, 0);
     glVertex2f(-.8,0.38);
     glVertex2f(-.8,0.85);
     glVertex2f(-.950,0.85);
     glVertex2f(-.950,0.38);
     glEnd();



//glass#####
glBegin(GL_QUADS);
     glColor3ub(255, 128, 0);
     glVertex2f(-.81,0.38);
     glVertex2f(-.81,0.83);
     glVertex2f(-.945,0.83);
     glVertex2f(-.945,0.38);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(230, 115, 0);
     glVertex2f(-.96,0.38);
     glVertex2f(-.96,0.83);
     glVertex2f(-.995,0.83);
     glVertex2f(-.995,0.38);
     glEnd();


//LEFT SIDE BLDING 2


glBegin(GL_QUADS);
     glColor3ub(102, 153, 153);
     glVertex2f(-.75,0.38);
     glVertex2f(-.75,0.81);
     glVertex2f(-0.8,0.81);
     glVertex2f(-.8,0.38);
     glEnd();
//LEFT SIDE BLDING 3

     glBegin(GL_QUADS);
     glColor3ub(117, 163, 163);
     glVertex2f(-.65,0.38);
     glVertex2f(-.65,0.76);
     glVertex2f(-0.75,0.76);
     glVertex2f(-.75,0.38);
     glEnd();

//LEFT SIDE BLDING 4


//bldingside
     glPushMatrix(); // Green goods
     glTranslatef(0.0f,0.0f, 0.0f);
     glBegin(GL_QUADS);
     glColor3ub(191, 191, 191);
     glVertex2f(-.6,0.38);
     glVertex2f(-.6,0.91);
     glVertex2f(-0.65,0.91);
     glVertex2f(-.65,0.38);
     glEnd();
//miror 1


glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(-.59,0.38);
     glVertex2f(-.59,0.89);
     glVertex2f(-0.64,0.89);
     glVertex2f(-.64,0.38);
     glEnd();

//blding

     glBegin(GL_QUADS);
     glColor3ub(204, 204, 204);
     glVertex2f(-.5,0.38);
     glVertex2f(-.5,0.91);
     glVertex2f(-0.6,0.91);
     glVertex2f(-.6,0.38);
     glEnd();

//miror 2
glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(-.51,0.38);
     glVertex2f(-.51,0.89);
     glVertex2f(-0.59,0.89);
     glVertex2f(-.59,0.38);
     glEnd();


     glTranslatef(1.50f,0.0f, 0.0f);
     glBegin(GL_QUADS);
     glColor3ub(191, 191, 191);
     glVertex2f(-.6,0.38);
     glVertex2f(-.6,0.91);
     glVertex2f(-0.65,0.91);
     glVertex2f(-.65,0.38);
     glEnd();
//miror 1


     glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(-.59,0.38);
     glVertex2f(-.59,0.89);
     glVertex2f(-0.64,0.89);
     glVertex2f(-.64,0.38);
     glEnd();

//blding

     glBegin(GL_QUADS);
     glColor3ub(204, 204, 204);
     glVertex2f(-.5,0.38);
     glVertex2f(-.5,0.91);
     glVertex2f(-0.6,0.91);
     glVertex2f(-.6,0.38);
     glEnd();

//miror 2
glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(-.51,0.38);
     glVertex2f(-.51,0.89);
     glVertex2f(-0.59,0.89);
     glVertex2f(-.59,0.38);
     glEnd();

     glPopMatrix();

//left blding 6

     glBegin(GL_QUADS);
     glColor3ub(204, 153, 102);
     glVertex2f(-.2,0.38);
     glVertex2f(-.2,0.84);
     glVertex2f(-0.3,0.84);
     glVertex2f(-0.3,0.38);
      glEnd();

     glBegin(GL_QUADS);
     glColor3ub(198, 140, 83);
     glVertex2f(-.3,0.38);
     glVertex2f(-.3,0.84);
     glVertex2f(-0.37,0.84);
     glVertex2f(-0.37,0.38);
      glEnd();
//Glass
glBegin(GL_QUADS);
     glColor3ub(214, 214, 194);
     glVertex2f(-.31,0.38);
     glVertex2f(-.31,0.85);
     glVertex2f(-0.365,0.85);
     glVertex2f(-0.365,0.38);
      glEnd();

glBegin(GL_QUADS);
     glColor3ub(224, 224, 209);
     glVertex2f(-.21,0.38);
     glVertex2f(-.21,0.85);
     glVertex2f(-0.29,0.85);
     glVertex2f(-0.29,0.38);
      glEnd();



//left blding 7

     glPushMatrix(); // Green goods
     glTranslatef(0.0f,0.0f, 0.0f);
     glBegin(GL_QUADS);
     glColor3ub(117, 163, 163);
     glVertex2f(-.1,0.38);
     glVertex2f(-.1,0.90);
     glVertex2f(-0.15,0.90);
     glVertex2f(-0.15,0.38);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(102, 153, 153);
     glVertex2f(-.15,0.38);
     glVertex2f(-.15,0.90);
     glVertex2f(-0.2,0.90);
    glVertex2f(-0.2,0.38);
      glEnd();
//Glass
glBegin(GL_QUADS);
     glColor3ub(224, 224, 209);
     glVertex2f(-.103,0.91);
     glVertex2f(-.103,0.92);
     glVertex2f(-0.145,0.92);
    glVertex2f(-0.145,0.91);
      glEnd();

glBegin(GL_QUADS);
     glColor3ub(224, 224, 209);
     glVertex2f(-.103,0.92);
     glVertex2f(-.103,0.93);
     glVertex2f(-0.145,0.93);
    glVertex2f(-0.145,0.92);
      glEnd();

glBegin(GL_QUADS);
     glColor3ub(224, 224, 209);
     glVertex2f(-.103,0.94);
     glVertex2f(-.103,0.95);
     glVertex2f(-0.145,0.95);
    glVertex2f(-0.145,0.94);
      glEnd();

    glTranslatef(0.90f,0.0f, 0.0f);
     glBegin(GL_QUADS);
     glColor3ub(117, 163, 163);
     glVertex2f(-.1,0.38);
     glVertex2f(-.1,0.90);
     glVertex2f(-0.15,0.90);
     glVertex2f(-0.15,0.38);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(102, 153, 153);
     glVertex2f(-.15,0.38);
     glVertex2f(-.15,0.90);
     glVertex2f(-0.2,0.90);
    glVertex2f(-0.2,0.38);
      glEnd();
//Glass
glBegin(GL_QUADS);
     glColor3ub(224, 224, 209);
     glVertex2f(-.103,0.91);
     glVertex2f(-.103,0.92);
     glVertex2f(-0.145,0.92);
    glVertex2f(-0.145,0.91);
      glEnd();

glBegin(GL_QUADS);
     glColor3ub(224, 224, 209);
     glVertex2f(-.103,0.92);
     glVertex2f(-.103,0.93);
     glVertex2f(-0.145,0.93);
    glVertex2f(-0.145,0.92);
      glEnd();

glBegin(GL_QUADS);
     glColor3ub(224, 224, 209);
     glVertex2f(-.103,0.94);
     glVertex2f(-.103,0.95);
     glVertex2f(-0.145,0.95);
    glVertex2f(-0.145,0.94);
      glEnd();
      glPopMatrix();

    //-----------------------black Ground-------------------------------

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f, -0.16f);
    glVertex2f(1.0f, -0.16f);
    glVertex2f(1.0f, -0.19f);
    glVertex2f(-1.0f, -0.19f);
    glEnd();



//-----------------------MARKETPLACE RIGHT-SIDE-3-------------------------------

    //HOUSE SQUARE
 glPushMatrix();
glTranslatef(0.0f,0.0f,0.0f);

    glBegin(GL_POLYGON); //Yellow part
    glColor3ub(240, 240,109);
    glVertex2f(0.58f, 0.04f);
    glVertex2f(0.90f, 0.04f);
    glVertex2f(0.90f, 0.46f);
    glVertex2f(0.58f, 0.46f);
    glEnd();

    glBegin(GL_POLYGON); //Light Blue part
    glColor3ub(204, 255,255);
    glVertex2f(0.60f, 0.06f);
    glVertex2f(0.88f, 0.06f);
    glVertex2f(0.88f, 0.44f);
    glVertex2f(0.60f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-1
    glColor3ub(0,51,0);
    glVertex2f(0.60f, 0.06f);
    glVertex2f(0.61f, 0.06f);
    glVertex2f(0.61, 0.44f);
    glVertex2f(0.60f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-2
    glColor3ub(0,51,0);
    glVertex2f(0.60f, 0.06f);
    glVertex2f(0.88f, 0.06f);
    glVertex2f(0.88f, 0.10f);
    glVertex2f(0.60f, 0.10f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-3
    glColor3ub(0,51,0);
    glVertex2f(0.86f, 0.06f);
    glVertex2f(0.88f, 0.06f);
    glVertex2f(0.88f, 0.44f);
    glVertex2f(0.86f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-4
    glColor3ub(0,51,0);
    glVertex2f(0.88f, 0.44f);
    glVertex2f(0.60f, 0.44f);
    glVertex2f(0.60f, 0.42f);
    glVertex2f(0.88f, 0.42f);
    glEnd();

        //HOUSE SQUARE UPPER-PART-1
    glBegin(GL_POLYGON); // Bottle Green
    glColor3ub(0, 128,128);
    glVertex2f(0.58f, 0.46f);
    glVertex2f(0.91f, 0.46f);
    glVertex2f(0.91f, 0.51f);
    glVertex2f(0.58f, 0.51f);
    glEnd();

    //HOUSE SQUARE UPPER-PART-2
    glBegin(GL_POLYGON); // Green
    glColor3ub(0, 128,0);
    glVertex2f(0.58f, 0.51f);
    glVertex2f(0.90f, 0.51f);
    glVertex2f(0.90f, 0.59f);
    glVertex2f(0.58f, 0.59f);
    glEnd();


    //HOUSE SQUARE UPPER-PART-2
    glBegin(GL_POLYGON); // Bottle Green
    glColor3ub(0, 128,128);
    glVertex2f(0.58f, 0.59f);
    glVertex2f(0.91f, 0.59f);
    glVertex2f(0.91f, 0.64f);
    glVertex2f(0.58f, 0.64f);
    glEnd();

    //Inside Goods------------

    glPushMatrix(); // BROWN goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();

    glPopMatrix();


    glPushMatrix(); // Pink goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();

    glPopMatrix();


    glPushMatrix(); // blue goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();

    glPopMatrix();


    glPushMatrix(); // Brown goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();


    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glPopMatrix();


//----Windows Upper Black Line------
    glBegin(GL_POLYGON);
    glColor3ub(0,51,0);
    glVertex2f(0.69f, 0.06f);
    glVertex2f(0.70f, 0.06f);
    glVertex2f(0.70f, 0.44f);
    glVertex2f(0.69f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,51,0);
    glVertex2f(0.77f, 0.06f);
    glVertex2f(0.78f, 0.06f);
    glVertex2f(0.78f, 0.44f);
    glVertex2f(0.77f, 0.44f);
    glEnd();

///(2)
glTranslatef(-1.48f,0.0f,0.0f);

    glBegin(GL_POLYGON); //Yellow part
    glColor3ub(240, 240,109);
    glVertex2f(0.58f, 0.04f);
    glVertex2f(0.90f, 0.04f);
    glVertex2f(0.90f, 0.46f);
    glVertex2f(0.58f, 0.46f);
    glEnd();

    glBegin(GL_POLYGON); //Light Blue part
    glColor3ub(204, 255,255);
    glVertex2f(0.60f, 0.06f);
    glVertex2f(0.88f, 0.06f);
    glVertex2f(0.88f, 0.44f);
    glVertex2f(0.60f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-1
    glColor3ub(0,51,0);
    glVertex2f(0.60f, 0.06f);
    glVertex2f(0.61f, 0.06f);
    glVertex2f(0.61, 0.44f);
    glVertex2f(0.60f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-2
    glColor3ub(0,51,0);
    glVertex2f(0.60f, 0.06f);
    glVertex2f(0.88f, 0.06f);
    glVertex2f(0.88f, 0.10f);
    glVertex2f(0.60f, 0.10f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-3
    glColor3ub(0,51,0);
    glVertex2f(0.86f, 0.06f);
    glVertex2f(0.88f, 0.06f);
    glVertex2f(0.88f, 0.44f);
    glVertex2f(0.86f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-4
    glColor3ub(0,51,0);
    glVertex2f(0.88f, 0.44f);
    glVertex2f(0.60f, 0.44f);
    glVertex2f(0.60f, 0.42f);
    glVertex2f(0.88f, 0.42f);
    glEnd();

        //HOUSE SQUARE UPPER-PART-1
    glBegin(GL_POLYGON); // Bottle Green
    glColor3ub(0, 128,128);
    glVertex2f(0.58f, 0.46f);
    glVertex2f(0.91f, 0.46f);
    glVertex2f(0.91f, 0.51f);
    glVertex2f(0.58f, 0.51f);
    glEnd();

    //HOUSE SQUARE UPPER-PART-2
    glBegin(GL_POLYGON); // Green
    glColor3ub(0, 128,0);
    glVertex2f(0.58f, 0.51f);
    glVertex2f(0.90f, 0.51f);
    glVertex2f(0.90f, 0.59f);
    glVertex2f(0.58f, 0.59f);
    glEnd();


    //HOUSE SQUARE UPPER-PART-2
    glBegin(GL_POLYGON); // Bottle Green
    glColor3ub(0, 128,128);
    glVertex2f(0.58f, 0.59f);
    glVertex2f(0.91f, 0.59f);
    glVertex2f(0.91f, 0.64f);
    glVertex2f(0.58f, 0.64f);
    glEnd();

    //Inside Goods------------

    glPushMatrix(); // BROWN goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153, 153,255);
    glVertex2f(0.61f, 0.10f);
    glVertex2f(0.64f, 0.10f);
    glVertex2f(0.64f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.15f);
    glEnd();

    glPopMatrix();


    glPushMatrix(); // Pink goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 125,195);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.64f, 0.15f);
    glVertex2f(0.64f, 0.20f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.20f);
    glEnd();

    glPopMatrix();


    glPushMatrix(); // blue goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 102,204);
    glVertex2f(0.61f, 0.20f);
    glVertex2f(0.64f, 0.20f);
    glVertex2f(0.64f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.61f, 0.25f);
    glEnd();

    glPopMatrix();


    glPushMatrix(); // Brown goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();


    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glTranslatef(0.0f,0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(0.72f, 0.10f);
    glVertex2f(0.86f, 0.10f);
    glColor3ub(0,0,0);

    glVertex2f(0.86f, 0.17f);
    glVertex2f(0.72f, 0.17f);
    glEnd();

    glPopMatrix();


//----Windows Upper Black Line------
    glBegin(GL_POLYGON);
    glColor3ub(0,51,0);
    glVertex2f(0.69f, 0.06f);
    glVertex2f(0.70f, 0.06f);
    glVertex2f(0.70f, 0.44f);
    glVertex2f(0.69f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,51,0);
    glVertex2f(0.77f, 0.06f);
    glVertex2f(0.78f, 0.06f);
    glVertex2f(0.78f, 0.44f);
    glVertex2f(0.77f, 0.44f);
    glEnd();


    glPopMatrix();



//-----------------------MARKETPLACE RIGHT-SIDE-2-------------------------------

    //HOUSE SQUARE
glPushMatrix();
glTranslatef(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON); //Yellow part
    glColor3ub(255, 255,153);
    glVertex2f(0.30f, 0.00f);
    glVertex2f(0.58f, 0.00f);
    glVertex2f(0.58, 0.42f);
    glVertex2f(0.30f, 0.42f);
    glEnd();

    glBegin(GL_POLYGON); //Light Blue part
    glColor3ub(204,255, 255);
    glVertex2f(0.32f, 0.04f);
    glVertex2f(0.56f, 0.04f);
    glVertex2f(0.56f, 0.40f);
    glVertex2f(0.32f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-1
    glColor3ub(0,51,0);
    glVertex2f(0.32f, 0.04f);
    glVertex2f(0.33f, 0.04f);
    glVertex2f(0.33f, 0.40f);
    glVertex2f(0.32f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-2
    glColor3ub(0,51,0);
    glVertex2f(0.32f, 0.04f);
    glVertex2f(0.56f, 0.04f);
    glVertex2f(0.56f, 0.07f);
    glVertex2f(0.32f, 0.07f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-3
    glColor3ub(0,51,0);
    glVertex2f(0.54f, 0.04f);
    glVertex2f(0.56f, 0.04f);
    glVertex2f(0.56f, 0.40f);
    glVertex2f(0.54f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-4
    glColor3ub(0,51,0);
    glVertex2f(0.32f, 0.40f);
    glVertex2f(0.56f, 0.40f);
    glVertex2f(0.56, 0.38f);
    glVertex2f(0.32f, 0.38f);
    glEnd();


    //HOUSE SQUARE UPPER-PART-1
    glBegin(GL_POLYGON); // Bottle Green
    glColor3ub(0, 128,128);
    glVertex2f(0.30f, 0.42f);
    glVertex2f(0.59f, 0.42f);
    glVertex2f(0.59, 0.47f);
    glVertex2f(0.30f, 0.47f);
    glEnd();

    //HOUSE SQUARE UPPER-PART-2
    glBegin(GL_POLYGON); // Green
    glColor3ub(0, 128,0);
    glVertex2f(0.30f, 0.47f);
    glVertex2f(0.58f, 0.47f);
    glVertex2f(0.58, 0.55f);
    glVertex2f(0.30f, 0.55f);
    glEnd();


    //HOUSE SQUARE UPPER-PART-2
    glBegin(GL_POLYGON); // Bottle Green
    glColor3ub(0, 128,128);
    glVertex2f(0.30f, 0.55f);
    glVertex2f(0.59f, 0.55f);
    glVertex2f(0.59, 0.60f);
    glVertex2f(0.30f, 0.60f);
    glEnd();

    //Inside Goods---------------
    glPushMatrix(); // Blue goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();
    glPopMatrix();

    //Inside Goods
    glPushMatrix(); // Orange goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();



    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();
    glPopMatrix();

    //Inside Goods
    glPushMatrix(); // Green goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

    glPopMatrix();


    //Inside Goods
    glPushMatrix(); // Purple goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();
    glPopMatrix();


//----Windows Upper Black Line------

    glBegin(GL_POLYGON);
    glColor3ub(0,51,0);
    glVertex2f(0.40f, 0.04f);
    glVertex2f(0.42f, 0.04f);
    glVertex2f(0.42f, 0.40f);
    glVertex2f(0.40f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,51,0);
    glVertex2f(0.48f, 0.04f);
    glVertex2f(0.49f, 0.04f);
    glVertex2f(0.49f, 0.40f);
    glVertex2f(0.48f, 0.40f);
    glEnd();

    glTranslatef(-0.88f,0.0f,0.0f);
    glBegin(GL_POLYGON); //Yellow part
    glColor3ub(255, 255,153);
    glVertex2f(0.30f, 0.00f);
    glVertex2f(0.58f, 0.00f);
    glVertex2f(0.58, 0.42f);
    glVertex2f(0.30f, 0.42f);
    glEnd();

    glBegin(GL_POLYGON); //Light Blue part
    glColor3ub(204,255, 255);
    glVertex2f(0.32f, 0.04f);
    glVertex2f(0.56f, 0.04f);
    glVertex2f(0.56f, 0.40f);
    glVertex2f(0.32f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-1
    glColor3ub(0,51,0);
    glVertex2f(0.32f, 0.04f);
    glVertex2f(0.33f, 0.04f);
    glVertex2f(0.33f, 0.40f);
    glVertex2f(0.32f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-2
    glColor3ub(0,51,0);
    glVertex2f(0.32f, 0.04f);
    glVertex2f(0.56f, 0.04f);
    glVertex2f(0.56f, 0.07f);
    glVertex2f(0.32f, 0.07f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-3
    glColor3ub(0,51,0);
    glVertex2f(0.54f, 0.04f);
    glVertex2f(0.56f, 0.04f);
    glVertex2f(0.56f, 0.40f);
    glVertex2f(0.54f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-4
    glColor3ub(0,51,0);
    glVertex2f(0.32f, 0.40f);
    glVertex2f(0.56f, 0.40f);
    glVertex2f(0.56, 0.38f);
    glVertex2f(0.32f, 0.38f);
    glEnd();


    //HOUSE SQUARE UPPER-PART-1
    glBegin(GL_POLYGON); // Bottle Green
    glColor3ub(0, 128,128);
    glVertex2f(0.30f, 0.42f);
    glVertex2f(0.59f, 0.42f);
    glVertex2f(0.59, 0.47f);
    glVertex2f(0.30f, 0.47f);
    glEnd();

    //HOUSE SQUARE UPPER-PART-2
    glBegin(GL_POLYGON); // Green
    glColor3ub(0, 128,0);
    glVertex2f(0.30f, 0.47f);
    glVertex2f(0.58f, 0.47f);
    glVertex2f(0.58, 0.55f);
    glVertex2f(0.30f, 0.55f);
    glEnd();


    //HOUSE SQUARE UPPER-PART-2
    glBegin(GL_POLYGON); // Bottle Green
    glColor3ub(0, 128,128);
    glVertex2f(0.30f, 0.55f);
    glVertex2f(0.59f, 0.55f);
    glVertex2f(0.59, 0.60f);
    glVertex2f(0.30f, 0.60f);
    glEnd();

    //Inside Goods---------------
    glPushMatrix(); // Blue goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,204,255);
    glVertex2f(0.33f, 0.07f);
    glVertex2f(0.36f, 0.07f);
    glVertex2f(0.36f, 0.12f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.12f);
    glEnd();
    glPopMatrix();

    //Inside Goods
    glPushMatrix(); // Orange goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();



    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,102,0);
    glVertex2f(0.33f, 0.12f);
    glVertex2f(0.36f, 0.12f);
    glVertex2f(0.36f, 0.17f);

    glColor3ub(255,204,0);
    glVertex2f(0.33f, 0.17f);
    glEnd();
    glPopMatrix();

    //Inside Goods
    glPushMatrix(); // Green goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(155,204,0);
    glVertex2f(0.33f, 0.17f);
    glVertex2f(0.36f, 0.17f);
    glVertex2f(0.36f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.22f);
    glEnd();

    glPopMatrix();


    //Inside Goods
    glPushMatrix(); // Purple goods
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();


    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();

        glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(108,0,128);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.36f, 0.22f);
    glVertex2f(0.36f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.33f, 0.27f);
    glEnd();
    glPopMatrix();


//----Windows Upper Black Line------

    glBegin(GL_POLYGON);
    glColor3ub(0,51,0);
    glVertex2f(0.40f, 0.04f);
    glVertex2f(0.42f, 0.04f);
    glVertex2f(0.42f, 0.40f);
    glVertex2f(0.40f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,51,0);
    glVertex2f(0.48f, 0.04f);
    glVertex2f(0.49f, 0.04f);
    glVertex2f(0.49f, 0.40f);
    glVertex2f(0.48f, 0.40f);
    glEnd();

glPopMatrix();
    //-----------------------MARKETPLACE-------------------------------

    //HOUSE SQUARE

    glBegin(GL_POLYGON);
    glColor3ub(240, 240,109);
    glVertex2f(-0.30f, -0.02f);
    glVertex2f(0.30f, -0.02f);
    glVertex2f(0.30, 0.38f);
    glVertex2f(-0.30f, 0.38f);
    glEnd();


    //HOUSE UNDER LINE-1 SQUARE
    glBegin(GL_POLYGON);
    glColor3ub(51,51,0);
    glVertex2f(-0.32f, -0.04f);
    glVertex2f(0.32f, -0.04f);
    glVertex2f(0.32, -0.02f);
    glVertex2f(-0.32f, -0.02f);
    glEnd();

    //HOUSE UNDER LINE-2 SQUARE
    glBegin(GL_POLYGON);
    glColor3ub(51,51,0);
    glVertex2f(-0.33f, -0.06f);
    glVertex2f(0.33f, -0.06f);
    glVertex2f(0.33, -0.04f);
    glVertex2f(-0.33f, -0.04f);
    glEnd();

    //HOUSE DOOR SQUARE

    glBegin(GL_POLYGON);
    glColor3ub(0,128,128); //BOTTLE GREEN
    glVertex2f(-0.10f, -0.02f);
    glVertex2f(0.10f, -0.02f);

    glColor3ub(255,255,255);  // WHITE
    glVertex2f(0.10, 0.38f);
    glVertex2f(-0.10f, 0.38f);
    glEnd();

    //HOUSE DOOR SQUARE inside under line

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);  // BLACK
    glVertex2f(-0.10f, -0.02);
    glVertex2f(0.10f, -0.02f);
    glVertex2f(0.10, 0.00f);
    glVertex2f(-0.10f,0.00f);
    glEnd();

    //HOUSE DOOR SQUARE inside upper line

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);  // BLACK
    glVertex2f(-0.10f, 0.36);
    glVertex2f(0.10f, 0.36f);
    glVertex2f(0.10, 0.38f);
    glVertex2f(-0.10f,0.38f);
    glEnd();

        //HOUSE DOOR SQUARE inside left line

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);  // BLACK
    glVertex2f(-0.10f, 0.00);
    glVertex2f(-0.08f, 0.00f);
    glVertex2f(-0.08, 0.38f);
    glVertex2f(-0.10f,0.38f);
    glEnd();

    //HOUSE DOOR SQUARE inside Right line

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);  // BLACK
    glVertex2f(0.08f, 0.00);
    glVertex2f(0.10f, 0.00f);
    glVertex2f(0.10, 0.37f);
    glVertex2f(0.08f,0.37f);
    glEnd();


    //HOUSE DOOR SQUARE inside middle line

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);  // BLACK
    glVertex2f(-0.01f, 0.00);
    glVertex2f(0.00f, 0.00f);
    glVertex2f(0.00, 0.37f);
    glVertex2f(-0.01f,0.37f);
    glEnd();

    //HOUSE DOOR SQUARE inside middle (left short part) line

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);  // BLACK
    glVertex2f(-0.04f, 0.10);
    glVertex2f(-0.02f, 0.10f);
    glVertex2f(-0.02, 0.20f);
    glVertex2f(-0.04f,0.20f);
    glEnd();

    //HOUSE DOOR SQUARE inside middle (left short part) line

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);  // BLACK
    glVertex2f(0.02f, 0.10);
    glVertex2f(0.04f, 0.10f);
    glVertex2f(0.04f, 0.20f);
    glVertex2f(0.02f,0.20f);
    glEnd();



    //HOUSE SQUARE UPPER-PART-1

    glBegin(GL_POLYGON);
    glColor3ub(0,128,128);
    glVertex2f(-0.32f, 0.38f);
    glVertex2f(0.32f, 0.38f);
    glVertex2f(0.32, 0.41f);
    glVertex2f(-0.32f, 0.41f);
    glEnd();


    //HOUSE SQUARE UPPER-PART-2

    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2f(-0.30f, 0.41f);
    glVertex2f(0.30f, 0.41f);
    glVertex2f(0.30, 0.43f);
    glVertex2f(-0.30f, 0.43f);
    glEnd();

    //HOUSE SQUARE UPPER-PART-BIG

    glBegin(GL_POLYGON);
    glColor3ub(0,128,128);
    glVertex2f(-0.33f, 0.43f);
    glVertex2f(0.33f, 0.43f);
    glVertex2f(0.33f, 0.68f);
    glVertex2f(-0.33f, 0.68f);
    glEnd();

    //HOUSE SQUARE UPPER-PART- left side RED PART

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.32f, 0.45f);
    glVertex2f(-0.18f, 0.45f);
    glVertex2f(-0.18, 0.66f);
    glVertex2f(-0.32f, 0.66f);
    glEnd();

    glColor3ub(255,204,0);
    renderBitmapString(-0.30, 0.60, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SUPER");
    renderBitmapString(-0.29, 0.55, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SALE");
    renderBitmapString(-0.32, 0.50, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Upto-35%");

    glColor3ub(255,255,255);
    renderBitmapString(-0.31, 0.46, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Discount");


    //HOUSE SQUARE UPPER-PART- RIGHT side RED PART

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.18f, 0.45f);
    glVertex2f(0.32f, 0.45f);
    glVertex2f(0.32, 0.66f);
    glVertex2f(0.18f, 0.66f);
    glEnd();

    glColor3ub(255,204,0);
    renderBitmapString(0.20, 0.60, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SUPER");
    renderBitmapString(0.21, 0.55, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SALE");
    renderBitmapString(0.18, 0.50, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Upto-35%");

    glColor3ub(255,255,255);
    renderBitmapString(0.19, 0.46, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Discount");
    //HOUSE SQUARE UPPER-PART- MIDDLE RED PART

    glBegin(GL_POLYGON);
    glColor3ub(204,255,255);
    glVertex2f(-0.16f, 0.45f);
    glVertex2f(0.16f, 0.45f);

    glColor3ub(0,128,128);
    glVertex2f(0.16, 0.72f);
    glVertex2f(-0.16f, 0.72f);
    glEnd();
//------------------TEXT ADD------------------------
    glColor3ub(255,204,0);
    renderBitmapString(-0.12, 0.62, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SUPER MARKET");
    renderBitmapString(-0.14, 0.58, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "_________________");
    renderBitmapString(-0.14, 0.47, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "We Believe in Service");


    // Right side window

    glPushMatrix();
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(204,255,255);
    glVertex2f(0.14f, 0.04f);
    glVertex2f(0.26f, 0.04f);
    glVertex2f(0.26, 0.34f);
    glVertex2f(0.14f, 0.34f);
    glEnd();

    glBegin(GL_POLYGON);// Inside red Table
    glColor3ub(255,0,0);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.20f, 0.07f);
    glVertex2f(0.20, 0.13f);
    glVertex2f(0.15f, 0.13f);
    glEnd();

    glBegin(GL_POLYGON);// Inside red Table brown part
    glColor3ub(51,51,51);
    glVertex2f(0.15f, 0.13f);
    glVertex2f(0.205f, 0.13f);
    glVertex2f(0.205, 0.15f);
    glVertex2f(0.15f, 0.15f);
    glEnd();

    glBegin(GL_POLYGON);// Inside REK
    glColor3ub(255,255,204);
    glVertex2f(0.21f, 0.07f);
    glVertex2f(0.215f, 0.07f);
    glVertex2f(0.215f, 0.34f);
    glVertex2f(0.21f, 0.34f);
    glEnd();

    glBegin(GL_POLYGON);// Inside REK LINE-1
    glColor3ub(255,255,204);
    glVertex2f(0.215f, 0.11f);
    glVertex2f(0.26f, 0.11f);
    glVertex2f(0.26f, 0.12f);
    glVertex2f(0.215f, 0.12f);
    glEnd();

    glBegin(GL_POLYGON);// Inside REK good-1
    glColor3ub(153,153,255);
    glVertex2f(0.215f, 0.075f);
    glVertex2f(0.25f, 0.075f);
    glVertex2f(0.25f, 0.115f);
    glVertex2f(0.215f, 0.115f);
    glEnd();

    glBegin(GL_POLYGON);// Inside REK good-2
    glColor3ub(153,153,255);
    glVertex2f(0.215f, 0.125f);
    glVertex2f(0.25f, 0.125f);
    glVertex2f(0.25f, 0.155f);
    glVertex2f(0.215f, 0.155f);
    glEnd();

    glBegin(GL_POLYGON);// Inside REK good-3
    glColor3ub(153,153,255);
    glVertex2f(0.215f, 0.165f);
    glVertex2f(0.25f, 0.165f);
    glVertex2f(0.25f, 0.225f);
    glVertex2f(0.215f, 0.225f);
    glEnd();

    glBegin(GL_POLYGON);// Inside REK good-3
    glColor3ub(153,153,255);
    glVertex2f(0.215f, 0.225f);
    glVertex2f(0.25f, 0.225f);
    glVertex2f(0.25f, 0.275f);
    glVertex2f(0.215f, 0.275f);
    glEnd();

    glBegin(GL_POLYGON);// Inside REK LINE-2
    glColor3ub(255,255,204);
    glVertex2f(0.215f, 0.16f);
    glVertex2f(0.26f, 0.16f);
    glVertex2f(0.26f, 0.17f);
    glVertex2f(0.215f, 0.17f);
    glEnd();

    glBegin(GL_POLYGON);// Inside REK LINE-3
    glColor3ub(255,255,204);
    glVertex2f(0.215f, 0.22f);
    glVertex2f(0.26f, 0.22f);
    glVertex2f(0.26f, 0.23f);
    glVertex2f(0.215f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON);// Window Rod-1
    glColor3ub(0,51,0);
    glVertex2f(0.18f, 0.07f);
    glVertex2f(0.185f, 0.07f);
    glVertex2f(0.185f, 0.34f);
    glVertex2f(0.18f, 0.34f);
    glEnd();


    glBegin(GL_POLYGON);// Window Rod-2
    glColor3ub(0,51,0);
    glVertex2f(0.22f, 0.07f);
    glVertex2f(0.225f, 0.07f);
    glVertex2f(0.225f, 0.34f);
    glVertex2f(0.22f, 0.34f);
    glEnd();


    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-1
    glColor3ub(0,51,0);
    glVertex2f(0.14f, 0.04f);
    glVertex2f(0.15f, 0.04f);
    glVertex2f(0.15, 0.34f);
    glVertex2f(0.14f, 0.34f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-2
    glColor3ub(0,51,0);
    glVertex2f(0.14f, 0.04f);
    glVertex2f(0.26f, 0.04f);
    glVertex2f(0.26, 0.07f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-3
    glColor3ub(0,51,0);
    glVertex2f(0.25f, 0.04f);
    glVertex2f(0.26f, 0.04f);
    glVertex2f(0.26, 0.34f);
    glVertex2f(0.25f, 0.34f);
    glEnd();

    //Left side window

    glTranslatef(-0.40f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(204,255,255);
    glVertex2f(0.14f, 0.04f);
    glVertex2f(0.26f, 0.04f);
    glVertex2f(0.26, 0.34f);
    glVertex2f(0.14f, 0.34f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-1
    glColor3ub(0,51,0);
    glVertex2f(0.14f, 0.04f);
    glVertex2f(0.15f, 0.04f);
    glVertex2f(0.15, 0.34f);
    glVertex2f(0.14f, 0.34f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-2
    glColor3ub(0,51,0);
    glVertex2f(0.14f, 0.04f);
    glVertex2f(0.26f, 0.04f);
    glVertex2f(0.26, 0.07f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    glBegin(GL_POLYGON); //WINDOW INSIDE LINE-3
    glColor3ub(0,51,0);
    glVertex2f(0.25f, 0.04f);
    glVertex2f(0.26f, 0.04f);
    glVertex2f(0.26, 0.34f);
    glVertex2f(0.25f, 0.34f);
    glEnd();

    glPopMatrix();

    // Right side window (RED-WHITE PART)
    glPushMatrix();
    glTranslatef(0.0f,0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255); //white
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0); //Red
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255); //white
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0); //Red
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255); //white
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();
glPopMatrix();


  glPushMatrix();
    glTranslatef(-0.40f,0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255); //white
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0); //Red
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255); //white
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0); //Red
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();

    glTranslatef(0.02f,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255); //white
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.14f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.14f, 0.28f);
    glEnd();
glPopMatrix();
glPopMatrix();

//-----------------Right side FLAG -1------------------
    //FLAG GROUND
    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.40f, -0.05f);
    glVertex2f(0.43f, -0.05f);
    glVertex2f(0.43f, -0.04f);
    glVertex2f(0.40f, -0.04f);
    glEnd();

    //FLAG BAMBO
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.41f, -0.05f);
    glVertex2f(0.42f, -0.05f);
    glVertex2f(0.42f, 0.61f);
    glVertex2f(0.41f, 0.61f);
    glEnd();

    //FLAG
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.425f, 0.20f);
    glVertex2f(0.50f, 0.20f);
    glVertex2f(0.50f, 0.58f);
    glVertex2f(0.425f, 0.58f);
    glEnd();

    //FLAG Text
    glColor3ub(255,204,0);
    renderBitmapString(0.45, 0.25, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "E");
    renderBitmapString(0.45, 0.33, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "L");
    renderBitmapString(0.45, 0.42, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "A");
    renderBitmapString(0.45, 0.50, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "S");

       glTranslatef(-0.882f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.40f, -0.05f);
    glVertex2f(0.43f, -0.05f);
    glVertex2f(0.43f, -0.04f);
    glVertex2f(0.40f, -0.04f);
    glEnd();

    //FLAG BAMBO
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.41f, -0.05f);
    glVertex2f(0.42f, -0.05f);
    glVertex2f(0.42f, 0.61f);
    glVertex2f(0.41f, 0.61f);
    glEnd();

    //FLAG
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.425f, 0.20f);
    glVertex2f(0.50f, 0.20f);
    glVertex2f(0.50f, 0.58f);
    glVertex2f(0.425f, 0.58f);
    glEnd();

    //FLAG Text
    glColor3ub(255,204,0);
    renderBitmapString(0.45, 0.25, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "E");
    renderBitmapString(0.45, 0.33, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "L");
    renderBitmapString(0.45, 0.42, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "A");
    renderBitmapString(0.45, 0.50, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "S");
    glPopMatrix();

 /*   //FLAG Roof-1
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.22f);
    glVertex2f(0.425f, 0.22f);
    glEnd();

    //FLAG Roof-2
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.26f);
    glVertex2f(0.425f, 0.26f);
    glEnd();

    //FLAG Roof-3
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.30f);
    glVertex2f(0.425f, 0.30f);
    glEnd();

    //FLAG Roof-4
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.30f);
    glVertex2f(0.425f, 0.30f);
    glEnd();

    //FLAG Roof-5
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.34f);
    glVertex2f(0.425f, 0.34f);
    glEnd();

    //FLAG Roof-6
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.38f);
    glVertex2f(0.425f, 0.38f);
    glEnd();

    //FLAG Roof-7
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.42f);
    glVertex2f(0.425f, 0.42f);
    glEnd();

    //FLAG Roof-8
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.46f);
    glVertex2f(0.425f, 0.46f);
    glEnd();

    //FLAG Roof-9
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.50f);
    glVertex2f(0.425f, 0.50f);
    glEnd();

    //FLAG Roof-10
    glBegin(GL_LINE);
    glColor3ub(255,255,255);
    glVertex2f(0.42f, 0.54f);
    glVertex2f(0.425f, 0.54f);
    glEnd();*/

//-----------------Right Side FLAG-2------------------
    //FLAG GROUND
    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.70f, 0.01f);
    glVertex2f(0.73f, 0.01f);
    glVertex2f(0.73f, -0.01f);
    glVertex2f(0.70f, -0.01f);
    glEnd();

    //FLAG BAMBO
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.71f, 0.01f);
    glVertex2f(0.72f, 0.01f);
    glVertex2f(0.72f, 0.66f);
    glVertex2f(0.71f, 0.66f);
    glEnd();

    //FLAG
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.725f, 0.28f);
    glVertex2f(0.80f, 0.28f);
    glVertex2f(0.80f, 0.63f);
    glVertex2f(0.725f, 0.63f);
    glEnd();

    //FLAG Text
    glColor3ub(255,204,0);
    renderBitmapString(0.75, 0.32, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "E");
    renderBitmapString(0.75, 0.40, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "L");
    renderBitmapString(0.75, 0.48, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "A");
    renderBitmapString(0.75, 0.56, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "S");

     glTranslatef(-1.48f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.70f, 0.01f);
    glVertex2f(0.73f, 0.01f);
    glVertex2f(0.73f, -0.01f);
    glVertex2f(0.70f, -0.01f);
    glEnd();

    //FLAG BAMBO
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.71f, 0.01f);
    glVertex2f(0.72f, 0.01f);
    glVertex2f(0.72f, 0.66f);
    glVertex2f(0.71f, 0.66f);
    glEnd();

    //FLAG
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.725f, 0.28f);
    glVertex2f(0.80f, 0.28f);
    glVertex2f(0.80f, 0.63f);
    glVertex2f(0.725f, 0.63f);
    glEnd();

    //FLAG Text
    glColor3ub(255,204,0);
    renderBitmapString(0.75, 0.32, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "E");
    renderBitmapString(0.75, 0.40, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "L");
    renderBitmapString(0.75, 0.48, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "A");
    renderBitmapString(0.75, 0.56, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "S");
    glPopMatrix();

}
void sky3()
{
glPushMatrix();
     glTranslatef(moonposition3,0.0,0.0);
	GLfloat x = 0.2f; GLfloat y = 0.90; GLfloat radius = .065f;       //moon
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 241, 213);
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

						  //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / lineAmount)),
			y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
	glPopMatrix();
}
void road1()
{

     glBegin(GL_POLYGON);
    glColor3ub(128,128,128);
    glVertex2f(-1.0f, -0.20f);
    glVertex2f(1.0f, -0.20f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(-1.0f, -0.70f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0f, -0.20f);
    glVertex2f(1.0f, -0.20f);
    glVertex2f(1.0f, -0.215f);
    glVertex2f(-1.0f, -0.215f);
    glEnd();

         glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(1.0f, -0.685f);
    glVertex2f(-1.0f, -0.685);
    glEnd();
glPushMatrix();
glTranslatef(0.0f,0.0f,0.0f);
        glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.90f, -0.45f);
    glVertex2f(-0.70f, -0.45f);
    glVertex2f(-0.70f, -0.42f);
    glVertex2f(-0.90f, -0.42f);
    glEnd();
    glTranslatef(0.27f,0.0f,0.0f);
        glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.90f, -0.45f);
    glVertex2f(-0.70f, -0.45f);
    glVertex2f(-0.70f, -0.42f);
    glVertex2f(-0.90f, -0.42f);
    glEnd();

        glTranslatef(0.27f,0.0f,0.0f);
        glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.90f, -0.45f);
    glVertex2f(-0.70f, -0.45f);
    glVertex2f(-0.70f, -0.42f);
    glVertex2f(-0.90f, -0.42f);
    glEnd();

       glTranslatef(0.50f,0.0f,0.0f);
        glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.90f, -0.45f);
    glVertex2f(-0.70f, -0.45f);
    glVertex2f(-0.70f, -0.42f);
    glVertex2f(-0.90f, -0.42f);
    glEnd();

    glTranslatef(0.27f,0.0f,0.0f);
        glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.90f, -0.45f);
    glVertex2f(-0.70f, -0.45f);
    glVertex2f(-0.70f, -0.42f);
    glVertex2f(-0.90f, -0.42f);
    glEnd();
    glTranslatef(0.27f,0.0f,0.0f);
        glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.90f, -0.45f);
    glVertex2f(-0.70f, -0.45f);
    glVertex2f(-0.70f, -0.42f);
    glVertex2f(-0.90f, -0.42f);
    glEnd();
    glTranslatef(0.27f,0.0f,0.0f);
        glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.90f, -0.45f);
    glVertex2f(-0.70f, -0.45f);
    glVertex2f(-0.70f, -0.42f);
    glVertex2f(-0.90f, -0.42f);
    glEnd();


    glTranslatef(0.0f,0.0f,0.0f);
      glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.10f, -0.49f);
    glVertex2f(0.10f, -0.49f);
    glVertex2f(0.10f, -0.38f);
    glVertex2f(-0.10f, -0.38f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
 glTranslatef(0.0f,0.0f,0.0f);
      glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.10f, -0.50f);
    glVertex2f(0.10f, -0.50f);
    glVertex2f(0.10f, -0.39f);
    glVertex2f(-0.10f, -0.39f);
    glEnd();

     glTranslatef(0.0f,0.15f,0.0f);
       glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.10f, -0.50f);
    glVertex2f(0.10f, -0.50f);
    glVertex2f(0.10f, -0.39f);
    glVertex2f(-0.10f, -0.39f);
    glEnd();

      glTranslatef(0.0f,0.15f,0.0f);
       glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.10f, -0.50f);
    glVertex2f(0.10f, -0.50f);
    glVertex2f(0.10f, -0.48f);
    glVertex2f(-0.10f, -0.48);
    glEnd();

    glTranslatef(0.0f,-0.45f,0.0f);
       glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
     glVertex2f(-0.10f, -0.50f);
    glVertex2f(0.10f, -0.50f);
    glVertex2f(0.10f, -0.39f);
    glVertex2f(-0.10f, -0.39f);
    glEnd();

         glTranslatef(0.0f,-0.15f,0.0f);
       glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.10f, -0.50f);
    glVertex2f(0.10f, -0.50f);
    glVertex2f(0.10f, -0.48f);
    glVertex2f(-0.10f, -0.48);
    glEnd();
  glPopMatrix();
}

void grass1()
{

        glBegin(GL_POLYGON);
    glColor3ub(184,115,51);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();


}
void vehicles9()
{
glPushMatrix();
    glTranslatef(positionbus5,0,0);
    glPushMatrix();
      glScalef(1.5,2,0); // increase x right and y
    glTranslatef(0.15f,-0.42f,0);
	 glColor3ub(102,184,31);
	glBegin(GL_POLYGON);
        glVertex2f(-0.79f, 0.24f);
        glVertex2f(-0.61f, 0.24f);
        glVertex2f(-0.61f, 0.30f);
        glVertex2f(-0.635f, 0.30f);
        glVertex2f(-0.65f, 0.36f);
         glVertex2f(-0.79f, 0.36f);
        glEnd();

	//windows
glColor3ub(192,192,192);
	glBegin(GL_POLYGON);
        glVertex2f(-0.78f, 0.30f);
        glVertex2f(-0.735f, 0.30f);
        glVertex2f(-0.735f, 0.34f);
        glVertex2f(-0.78f, 0.34f);
    glEnd();
glColor3ub(192,192,192);
	glBegin(GL_POLYGON);
         glVertex2f(-0.72f, 0.30f);
        glVertex2f(-0.69f, 0.30f);
        glVertex2f(-0.69f, 0.34f);
        glVertex2f(-0.72f, 0.34f);
    glEnd();

glColor3ub(192,192,192);
	glBegin(GL_POLYGON);
         glVertex2f(-0.68f, 0.30f);
        glVertex2f(-0.645f, 0.30f);
        glVertex2f(-0.655f, 0.34f);
        glVertex2f(-0.68f, 0.34f);
    glEnd();



glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(-0.615f, 0.285f);
        glVertex2f(-0.608f, 0.285f);
        glVertex2f(-0.608f, 0.30f);
        glVertex2f(-0.615f, 0.30f);
    glEnd();
       //light
glColor3ub(255,255,153);
	glBegin(GL_POLYGON);
        glVertex2f(-0.615f, 0.29f);
        glVertex2f(-0.585f, 0.23f);
        glVertex2f(-0.545f, 0.23f);
        glVertex2f(-0.615f, 0.30f);
        glEnd();



// wheel 1
    GLfloat xc=-0.66f;
    GLfloat yc=0.25f;
    GLfloat radiusc =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc + (radiusc * cos(i *  twicePi / triangleAmount)),
                    yc+ (radiusc * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xc1=-0.66f;
    GLfloat yc1=0.25f;
    GLfloat radiusc3 =0.0125f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc1, yc1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc1 + (radiusc3 * cos(i *  twicePi / triangleAmount)),
                    yc1 + (radiusc3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();


	// wheel 2
    GLfloat xc2=-0.75f;
    GLfloat yc2=0.25f;
    GLfloat radiusc2 =0.025f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc2, yc2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc2 + (radiusc2 * cos(i *  twicePi / triangleAmount)),
                    yc2+ (radiusc2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat xc3=-0.75f;
    GLfloat yc3=0.25f;
    GLfloat radiusc4=0.0125f;

 glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc3, yc3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc3 + (radiusc3 * cos(i *  twicePi / triangleAmount)),
                    yc3+ (radiusc3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
 glPopMatrix();
}

void vehicles10()
{

    /**--------------------------Car3-----------------------**/

   glPushMatrix();
    glTranslatef(positionbus6,0,0);
 glPushMatrix();
        glScalef(1.5,2,0); // increase x right and y
    glTranslatef(0.05f,-0.40f,0);
	 glColor3ub(48,16,107);
	glBegin(GL_POLYGON);
              glVertex2f(0.36f, 0.09f);
        glVertex2f(0.55f, 0.09f);
        glVertex2f(0.55f, 0.13f);
        glVertex2f(0.53f, 0.13f);
         glVertex2f(0.49f, 0.17f);
          glVertex2f(0.41f, 0.17f);
          glVertex2f(0.37f, 0.13f);
          glVertex2f(0.36f, 0.13f);
        glEnd();
  GLfloat xr=0.54f;
    GLfloat yr=0.11f;
    GLfloat radiusr2 =0.02f;

glColor3ub(48,16,107);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr, yr); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr + (radiusr2* cos(i *  twicePi / triangleAmount)),
                    yr+ (radiusr2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

  GLfloat xr1=0.365f;
    GLfloat yr1=0.11f;
    GLfloat radiusr21 =0.02f;

    glColor3ub(48,16,107);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr1, yr1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr1 + (radiusr21* cos(i *  twicePi / triangleAmount)),
                    yr1+ (radiusr21 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

 glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.38f, 0.125f);
        glVertex2f(0.44f, 0.125f);
        glVertex2f(0.44f, 0.16f);
        glVertex2f(0.415f, 0.16f);
        glEnd();

         glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.46f, 0.125f);
        glVertex2f(0.52f, 0.125f);
        glVertex2f(0.48f, 0.16f);
        glVertex2f(0.46f, 0.16f);
        glEnd();

    glLineWidth(2.0);
              glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);
	      glVertex2f(0.45f, 0.09f);
        glVertex2f(0.45, 0.165f);
glEnd();
   glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
        glVertex2f(0.345f, 0.102f);
        glVertex2f(0.355f, 0.102f);
        glVertex2f(0.355f, 0.112f);
        glVertex2f(0.345f, 0.112f);
        glEnd();

//light
glColor3ub(255,255,153);
	glBegin(GL_POLYGON);
        glVertex2f(0.293f, 0.075f);
        glVertex2f(0.333f, 0.075f);
        glVertex2f(0.345f, 0.10f);
        glVertex2f(0.345f, 0.11f);
        glEnd();


// wheel 1

  GLfloat xa=0.41f;
    GLfloat ya=0.09f;
    GLfloat radiusa =0.02f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa, ya); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa + (radiusa* cos(i *  twicePi / triangleAmount)),
                    ya+ (radiusa * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xa1=0.41f;
    GLfloat ya1=0.09f;
    GLfloat radiusa3 =0.01f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa1, ya1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa1 + (radiusa3 * cos(i *  twicePi / triangleAmount)),
                    ya1 + (radiusa3 * sin(i * twicePi / triangleAmount)) );
    }
         glEnd();


	// wheel 2
    GLfloat xa2=0.51f;
    GLfloat ya2=0.09f;
    GLfloat radiusa2 =0.02f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa2, ya2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa2 + (radiusa2 * cos(i *  twicePi / triangleAmount)),
                    ya2+ (radiusa2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat xa3=0.51f;
    GLfloat ya3=0.09f;
    GLfloat radiusa4=0.01f;

 glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xa3, ya3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xa3 + (radiusa3 * cos(i *  twicePi / triangleAmount)),
                    ya3+ (radiusa3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
glPopMatrix();
glPopMatrix();

}
void traffic()
{
    glPushMatrix();
    glTranslatef(0.0f,0.53f,0.0f);
    glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
        glVertex2f(-0.03f, -0.98f);
        glVertex2f(0.03f, -0.98f);
        glVertex2f(0.03f, -0.94f);
        glVertex2f(-0.03f, -0.94f);
        glEnd();

           glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
        glVertex2f(-0.015f, -0.67f);
        glVertex2f(0.015f, -0.67f);
        glVertex2f(0.015f, -0.94f);
        glVertex2f(-0.015f, -0.94f);
        glEnd();

                  glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
        glVertex2f(-0.10f, -0.67f);
        glVertex2f(-0.01f, -0.67f);
        glVertex2f(-0.01f, -0.30f);
        glVertex2f(-0.10f, -0.30f);
        glEnd();

          glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
        glVertex2f(0.10f, -0.67f);
        glVertex2f(0.01f, -0.67f);
        glVertex2f(0.01f, -0.30f);
        glVertex2f(0.10f, -0.30f);
        glEnd();
        glPopMatrix();

}

void traffic_light()
{

    ///red light 1
     glPushMatrix();
     if(rl1[RED]){
       GLfloat xr1=-0.05f;
    GLfloat yr1=0.15f;
    GLfloat radiusr1=0.03f;

 glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr1, yr1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr1 + (radiusr1 * cos(i *  twicePi / triangleAmount)),
                    yr1+ (radiusr1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

    	else{
       GLfloat xr1=-0.05f;
    GLfloat yr1=0.15f;
    GLfloat radiusr1=0.03f;

 glColor3f(0.2, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr1, yr1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr1 + (radiusr1 * cos(i *  twicePi / triangleAmount)),
                    yr1+ (radiusr1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

	glPopMatrix();


	///yellow light 1
	  glPushMatrix();
  if(rl1[YELLOW]){
       GLfloat xy1=-0.05f;
    GLfloat yy1=0.06f;
    GLfloat radiusy1=0.03f;

 glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy1, yy1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xy1 + (radiusy1 * cos(i *  twicePi / triangleAmount)),
                    yy1+ (radiusy1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

    	else{
       GLfloat xy1=-0.05f;
    GLfloat yy1=0.06f;
    GLfloat radiusy1=0.03f;

 glColor3f(0.2, 0.2, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy1, yy1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xy1 + (radiusy1 * cos(i *  twicePi / triangleAmount)),
                    yy1+ (radiusy1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

	glPopMatrix();

  ///green light 1
	  glPushMatrix();
     if(rl1[GREEN]){
       GLfloat xy1=-0.05f;
    GLfloat yy1=-0.04f;
    GLfloat radiusy1=0.03f;

 glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy1, yy1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xy1 + (radiusy1 * cos(i *  twicePi / triangleAmount)),
                    yy1+ (radiusy1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

    	else{
       GLfloat xy1=-0.05f;
    GLfloat yy1=-0.04f;
    GLfloat radiusy1=0.03f;

 glColor3f(0.0, 0.2, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy1, yy1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xy1 + (radiusy1 * cos(i *  twicePi / triangleAmount)),
                    yy1+ (radiusy1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

	glPopMatrix();

	  ///red light 2
     glPushMatrix();
     if(rl2[RED]){
       GLfloat xr1=0.05f;
    GLfloat yr1=0.15f;
    GLfloat radiusr1=0.03f;

 glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr1, yr1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr1 + (radiusr1 * cos(i *  twicePi / triangleAmount)),
                    yr1+ (radiusr1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

    	else{
       GLfloat xr1=0.05f;
    GLfloat yr1=0.15f;
    GLfloat radiusr1=0.03f;

 glColor3f(0.2, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xr1, yr1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xr1 + (radiusr1 * cos(i *  twicePi / triangleAmount)),
                    yr1+ (radiusr1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

	glPopMatrix();


	///yellow light 2
	  glPushMatrix();
  if(rl2[YELLOW]){
       GLfloat xy1=0.05f;
    GLfloat yy1=0.06f;
    GLfloat radiusy1=0.03f;

 glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy1, yy1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xy1 + (radiusy1 * cos(i *  twicePi / triangleAmount)),
                    yy1+ (radiusy1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

    	else{
       GLfloat xy1=0.05f;
    GLfloat yy1=0.06f;
    GLfloat radiusy1=0.03f;

 glColor3f(0.2, 0.2, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy1, yy1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xy1 + (radiusy1 * cos(i *  twicePi / triangleAmount)),
                    yy1+ (radiusy1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

	glPopMatrix();

  ///green light 2
	  glPushMatrix();
     if(rl2[GREEN]){
       GLfloat xy1=0.05f;
    GLfloat yy1=-0.04f;
    GLfloat radiusy1=0.03f;

 glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy1, yy1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xy1 + (radiusy1 * cos(i *  twicePi / triangleAmount)),
                    yy1+ (radiusy1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

    	else{
       GLfloat xy1=0.05f;
    GLfloat yy1=-0.04f;
    GLfloat radiusy1=0.03f;

 glColor3f(0.0, 0.2, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xy1, yy1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xy1 + (radiusy1 * cos(i *  twicePi / triangleAmount)),
                    yy1+ (radiusy1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();}

	glPopMatrix();

}


void man3()
{

    glPushMatrix;
    glTranslatef(0.0,mposition3,0.0);
glTranslatef(0.32,0.0,0.0);
      ////neck/////
       glBegin(GL_POLYGON);
          glColor3ub(232, 190, 123);
        glVertex2f(-0.44f, -0.40f);
        glVertex2f(-0.36f, -0.40f);
        glVertex2f(-0.36f, -0.50f);
        glVertex2f(-0.44f, -0.50f);

glEnd();
////////head////
       	 GLfloat x2=-0.40f;
    GLfloat y2=-0.42f;
    GLfloat radiusu2 =0.05f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x2+ (radiusu2* cos(i *  twicePi / 180)),
                    y2+ (radiusu2* sin(i * twicePi / 180)) );
    }
       glEnd();


    	 GLfloat x1=-0.40f;
    GLfloat y1=-0.40f;
    GLfloat radiusu1 =0.05f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x1+ (radiusu1* cos(i *  twicePi / 180)),
                    y1+ (radiusu1* sin(i * twicePi / 180)) );
    }
       glEnd();

           	 GLfloat x3=-0.40f;
    GLfloat y3=-0.47f;
    GLfloat radiusu3 =0.02f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x3+ (radiusu3* cos(i *  twicePi / 180)),
                    y3+ (radiusu3* sin(i * twicePi / 180)) );
    }
       glEnd();
//////body/////
             glBegin(GL_POLYGON);
          glColor3ub(232, 0,0);
             glVertex2f(-0.44f, -0.70);
             glVertex2f(-0.36f, -0.70f);
               glVertex2f(-0.34f, -0.48f);
               glVertex2f(-0.46f, -0.48f);

glEnd();
/////right hand////
             glBegin(GL_POLYGON);
          glColor3ub(232, 0,0);
             glVertex2f(-0.34f, -0.66f);
             glVertex2f(-0.30f, -0.66f);
              glVertex2f(-0.33f, -0.48f);
               glVertex2f(-0.35f, -0.48f);

glEnd();

    	 GLfloat xh1=-0.32f;
    GLfloat yh1=-0.67f;
    GLfloat radiusuh1 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xh1, yh1); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xh1+ (radiusuh1* cos(i *  twicePi / 180)),
                    yh1+ (radiusuh1* sin(i * twicePi / 180)) );
    }
       glEnd();

       /////left hand////
             glBegin(GL_POLYGON);
          glColor3ub(232, 0,0);
glVertex2f(-0.50f, -0.66);
glVertex2f(-0.46f, -0.66f);
 glVertex2f(-0.44f, -0.48);
glVertex2f(-0.47f, -0.48f);
glEnd();

    	 GLfloat xh2=-0.48f;
    GLfloat yh2=-0.67f;
    GLfloat radiusuh2 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xh2, yh2); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xh2+ (radiusuh2* cos(i *  twicePi / 180)),
                    yh2+ (radiusuh2* sin(i * twicePi / 180)) );
    }
       glEnd();
//////left leg/////
glBegin(GL_POLYGON);
          glColor3ub(0,0,232);
             glVertex2f(-0.44f, -0.71);
             glVertex2f(-0.36f, -0.71);
               glVertex2f(-0.36f, -0.69);
               glVertex2f(-0.44f, -0.69);
                   glEnd();


             glBegin(GL_POLYGON);
          glColor3ub(232,0,0);
             glVertex2f(-0.46f, -0.87);
             glVertex2f(-0.34f, -0.87);
               glVertex2f(-0.36f, -0.70);
               glVertex2f(-0.44f, -0.70);
                   glEnd();

                       	 GLfloat xl2=-0.43f;
    GLfloat yl2=-0.88f;
    GLfloat radiusul2 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xl2, yl2); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xl2+ (radiusul2* cos(i *  twicePi / 180)),
                    yl2+ (radiusul2* sin(i * twicePi / 180)) );
    }
       glEnd();

                       	 GLfloat xl=-0.37f;
    GLfloat yl=-0.88f;
    GLfloat radiusul =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xl, yl); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xl+ (radiusul* cos(i *  twicePi / 180)),
                    yl+ (radiusul* sin(i * twicePi / 180)) );
    }
       glEnd();
       glPopMatrix();
}
void man4()
{


    glTranslatef(0.0,mposition4,0.0);
glTranslatef(0.48,0.0,0.0);
      ////neck/////
       glBegin(GL_POLYGON);
          glColor3ub(232, 190, 123);
        glVertex2f(-0.44f, -0.40f);
        glVertex2f(-0.36f, -0.40f);
        glVertex2f(-0.36f, -0.50f);
        glVertex2f(-0.44f, -0.50f);

glEnd();
////////head////
       	 GLfloat x12=-0.40f;
    GLfloat y12=-0.42f;
    GLfloat radiusu12 =0.05f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x12, y12); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x12+ (radiusu12* cos(i *  twicePi / 180)),
                    y12+ (radiusu12* sin(i * twicePi / 180)) );
    }
       glEnd();

   // glTranslatef(mposition1,0.0,0.0);
    	 GLfloat x11=-0.40f;
    GLfloat y11=-0.40f;
    GLfloat radiusu11 =0.05f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x11, y11); // center of circle
    for(int i = 90; i <= 270; i++)
    {
        glVertex2f( x11+ (radiusu11* cos(i *  twicePi / 180)),
                    y11+ (radiusu11* sin(i * twicePi / 180)) );
    }
       glEnd();
//////body/////
             glBegin(GL_POLYGON);
          glColor3ub(255, 255,0);
             glVertex2f(-0.45f, -0.70);
             glVertex2f(-0.35f, -0.70f);
               glVertex2f(-0.34f, -0.48f);
               glVertex2f(-0.46f, -0.48f);

glEnd();
/////right hand////
             glBegin(GL_POLYGON);
       glColor3ub(255, 255,0);
             glVertex2f(-0.34f, -0.66f);
             glVertex2f(-0.30f, -0.66f);
              glVertex2f(-0.33f, -0.48f);
               glVertex2f(-0.35f, -0.48f);

glEnd();

    	 GLfloat xh11=-0.32f;
    GLfloat yh11=-0.67f;
    GLfloat radiusuh11 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xh11, yh11); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xh11+ (radiusuh11* cos(i *  twicePi / 180)),
                    yh11+ (radiusuh11* sin(i * twicePi / 180)) );
    }
       glEnd();

       /////left hand////
             glBegin(GL_POLYGON);
glColor3ub(255, 255,0);
glVertex2f(-0.50f, -0.66);
glVertex2f(-0.46f, -0.66f);
 glVertex2f(-0.44f, -0.48);
glVertex2f(-0.47f, -0.48f);
glEnd();

    	 GLfloat xh21=-0.48f;
    GLfloat yh21=-0.67f;
    GLfloat radiusuh21 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xh21, yh21); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xh21+ (radiusuh21* cos(i *  twicePi / 180)),
                    yh21+ (radiusuh21* sin(i * twicePi / 180)) );
    }
       glEnd();
//////left leg/////
             glBegin(GL_POLYGON);
          glColor3ub(0,0,0);
             glVertex2f(-0.45f, -0.87);
             glVertex2f(-0.415f, -0.87);
               glVertex2f(-0.405f, -0.70);
               glVertex2f(-0.45f, -0.70);
                   glEnd();

                       	 GLfloat xl21=-0.43f;
    GLfloat yl21=-0.88f;
    GLfloat radiusul21 =0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xl21, yl21); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xl21+ (radiusul21* cos(i *  twicePi / 180)),
                    yl21+ (radiusul21* sin(i * twicePi / 180)) );
    }
       glEnd();
                   //////right leg/////
             glBegin(GL_POLYGON);
          glColor3ub(0,0,0);
             glVertex2f(-0.35, -0.87);
             glVertex2f(-0.385f, -0.87);
               glVertex2f(-0.395f, -0.70);
               glVertex2f(-0.35f, -0.70);
                   glEnd();
                       	 GLfloat xl1=-0.37f;
    GLfloat yl1=-0.88f;
    GLfloat radiusul1=0.02f;

            glColor3ub(232, 190, 123);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xl1, yl1); // center of circle
    for(int i = 0; i <= 1000; i++)
    {
        glVertex2f( xl1+ (radiusul1* cos(i *  twicePi / 180)),
                    yl1+ (radiusul1* sin(i * twicePi / 180)) );
    }
       glEnd();

glPopMatrix();

}

//update------------------------------Cloud and plane----------------------------------------
void update11(int value) {
	if (position11<-1.3)
		position11 = 1.0f;
			if (sunposition0<-1.0)
		sunposition0 = 1.0f;


	sunposition0-= sunspeed0;
	position11 -= speed11; //clouds and plane going -x axis

	glutPostRedisplay();


	glutTimerFunc(100, update11, 0);
}


void handleMouse(int button, int state, int x, int y) {
if (button == GLUT_LEFT_BUTTON)
{

    speed11 += 0.05f;
sunspeed0+=0.0005f;

    speed44+=0.1f;
}
if(button == GLUT_RIGHT_BUTTON)
    {

        speed11 = 0.0f;
sunspeed0=0.0f;
        speed44 = 0.0f;
    }
glutPostRedisplay();
}

void details() {
glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

glColor3f(1.0,0.0,0.0);
    renderBitmapString(-0.20, 0.90, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Marine Drive Road Scenario");
    renderBitmapString(-0.20, 0.80, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Computer Graphics [E]");
    renderBitmapString(-0.20, 0.70, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Group Information :");
glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.80, 0.66);
    glVertex2f(0.80, 0.66);
    glEnd();
renderBitmapString(-0.80, 0.60, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "ID");
    renderBitmapString(-0.30, 0.60, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Name");
 //   renderBitmapString(0.50, 0.60, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Contribution");
glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.80, 0.57);
    glVertex2f(0.80, 0.57);
    glEnd();
    renderBitmapString(-0.80, 0.50, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-45817-3");
    renderBitmapString(-0.30, 0.50, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Mridul Chowhan");
 //   renderBitmapString(0.50, 0.50, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Mridul Chowhan");


    renderBitmapString(-0.80, 0.40, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-44920-2");
    renderBitmapString(-0.30, 0.40, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Tama Saha");
  //  renderBitmapString(0.50, 0.40, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Tama Saha");

    renderBitmapString(-0.80, 0.30, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-45834-3");
    renderBitmapString(-0.30, 0.30, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Morshed Al-Jaber Bishal");
  //  renderBitmapString(0.50, 0.30, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Morshed Al-Jaber Bishal");


    renderBitmapString(-0.80, 0.20, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-45837-3");
    renderBitmapString(-0.30, 0.20, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Sanviraj Aynul Siam");
  //  renderBitmapString(0.50, 0.20, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Sanviraj Aynul Siam");


    renderBitmapString(-0.80, 0.10, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-45556-3");
    renderBitmapString(-0.30, 0.10, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Sarowar Jahan Protik");
//renderBitmapString(0.50, 0.10, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Sarowar Jahan Protik");


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.80,0.08);
    glVertex2f(0.80, 0.08);
    glEnd();

    renderBitmapString(-0.20, 0.00, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Supervised by :");
    renderBitmapString(-0.23, -0.10, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Mahfujur Rahman");
    renderBitmapString(-0.18, -0.20, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Lecturer");
    renderBitmapString(-0.35, -0.30, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Department of Computer Science");
    renderBitmapString(-0.36, -0.40, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Faculty of Science and Technology");
    renderBitmapString(-0.47, -0.50, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University-Bangladesh(AIUB)");

    renderBitmapString(-0.47, -0.70, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "PRESS SPACE TO CONTINUE OUR PROJECT");



 glFlush(); // Render now
}

void day()
{
	glClear(GL_COLOR_BUFFER_BIT);


  sky();

         glPushMatrix();
    sun();
	glPopMatrix();


    glPushMatrix();
	display();
    glPopMatrix();

	glPushMatrix();
	Cloud();
    glPopMatrix();

Road();

 	glPushMatrix();
roadline();
    glPopMatrix();

    glPushMatrix();
checkpost1();
glPopMatrix();


    glPushMatrix();
 vehicles5();
	glPopMatrix();

  glPushMatrix();
 vehicles6();
	glPopMatrix();

	    glPushMatrix();
 vehicles7();
	glPopMatrix();

	    glPushMatrix();
 vehicles8();
	glPopMatrix();

	    glPushMatrix();
checkpost2();
glPopMatrix();


grass();
	glPushMatrix();
beach();
glPopMatrix();

glPushMatrix();
 sea();
glPopMatrix();
	glPushMatrix();
boat1();
    glPopMatrix();

	glPushMatrix();
boat2();
    glPopMatrix();

    	glPushMatrix();
boat3();
    glPopMatrix();

	glFlush();
}

void night2()
{

glColor3f(0.518f,0.518f,0.541f);
glColor3f(0.663,0.663f,0.69f);
       glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(1.0f, 0.5f);
    glColor3f(0.263f,0.247f,0.459f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();


    glPushMatrix();
    Moon();
	glPopMatrix();

	glPushMatrix();
	Star();
    glPopMatrix();
       glPushMatrix();
	display();
    glPopMatrix();
Road();

 	glPushMatrix();
roadline();
    glPopMatrix();

glPushMatrix();
checkpost1();
glPopMatrix();

    glPushMatrix();
 vehicles1();
	glPopMatrix();

    glPushMatrix();
 vehicles2();
	glPopMatrix();

	    glPushMatrix();
 vehicles3();
	glPopMatrix();

	    glPushMatrix();
 vehicles4();
	glPopMatrix();


	    glPushMatrix();
checkpost2();
glPopMatrix();
	grass();
	glPushMatrix();
beach();
glPopMatrix();
 sea();

    	glPushMatrix();
boat5();
    glPopMatrix();
//sound1();
glFlush();
}


void evening()
{
	glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.518f,0.518f,0.541f);
       glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(1.0f, 0.5f);
    glColor3f(0.031f,0.059f,0.212f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();


    sky1();
    glPushMatrix();
    sun1();
    glPopMatrix();
      glPushMatrix();
    beach1();
    glPopMatrix();
      glPushMatrix();
    sea1();
    glPopMatrix();

     glPushMatrix();
    man1();
    glPopMatrix();
     glPushMatrix();
    man2();
    glPopMatrix();

glFlush();
}

void night1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.518f,0.518f,0.541f);
       glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(1.0f, 0.5f);
    glColor3f(0.031f,0.059f,0.212f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();


    glPushMatrix();
 sky2();
    glPopMatrix();
    glPushMatrix();
Star();
    glPopMatrix();

glPushMatrix();
    beach1();
    glPopMatrix();
      glPushMatrix();
    sea1();
    glPopMatrix();
     glPushMatrix();
    bigboat1();
    glPopMatrix();
    glPushMatrix();
    boat10();
    glPopMatrix();
     glPushMatrix();
    man1();
    glPopMatrix();
     glPushMatrix();
    man2();
    glPopMatrix();

glFlush();
}

void night3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.518f,0.518f,0.541f);
       glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(1.0f, 0.5f);
    glColor3f(0.031f,0.059f,0.212f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

sky3();
   glPushMatrix();
Star();
    glPopMatrix();
   glPushMatrix();
    display1();
	glPopMatrix();

	    glPushMatrix();
    road1();
	glPopMatrix();
grass1();

   glPushMatrix();
    vehicles9();
	glPopMatrix();
   glPushMatrix();
    vehicles10();
	glPopMatrix();
	 glPushMatrix();
    man3();
	glPopMatrix();
	 glPushMatrix();
    man4();
	glPopMatrix();

	 glPushMatrix();
    traffic();
	glPopMatrix();
	 glPushMatrix();
    traffic_light();
	glPopMatrix();
	glFlush();

}
void update111(int value)
{
    if(positionbus1 < -1.7)
            positionbus1 = 1.7f;

                if(positionbus2 < -1.7)
            positionbus2 = 1.7f;

           if(positionbus3 > 1.7)
            positionbus3  = -1.7f;


           if(positionbus4 > 1.7)
            positionbus4  = -1.7f;

        positionbus1 -= speed1;
       positionbus2 -= speed2;
        positionbus3+= speed3;
            positionbus4+= speed5;
         huposition1 -= huspeed;
    huposition2+= huspeed;

	glutPostRedisplay();
	glutTimerFunc(110, update111, 0);
}

void update22(int value)
{
    if(positionbus1 > 1.7)
            positionbus1 = -1.7f;

              if(positionbus2 > 1.7)
            positionbus2 = -1.7f;

   if(positionbus3 <- 1.7)
            positionbus3 = 1.7f;

   if(positionbus4 <- 1.7)
            positionbus4 = 1.7f;


    positionbus1 += speed1;
    positionbus2 += speed2;
   positionbus3 -= speed3;
   positionbus4 -= speed5;

	glutPostRedisplay();
	glutTimerFunc(110, update22, 0);
}
void updateA(int value)
{
    if(mposition2 >0.67 )
        mposition2 = -1.0f;
    mposition2 += mspeed2;
    glutPostRedisplay();
    glutTimerFunc(100, updateA, 0);
}
void updateB(int value)
{
    if(mposition1 >0.67 )
        mposition1 = -1.0f;
    mposition1 += mspeed1;
    glutPostRedisplay();
    glutTimerFunc(100, updateB, 0);
}
void updateC(int value)
{

    if (moonposition > 0.90)
		moonposition = -0.90f;


		moonposition += moonspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateC, 0);
}

void updateD(int value)
{

            if(moonposition1 > 0.8)
            moonposition1 = -0.8f;
  moonposition1 +=moonspeed1;
    glutPostRedisplay();
    glutTimerFunc(100, updateD, 0);
}
void updateE(int value)
{
			if (sunposition>1.0)
		sunposition = -1.0f;

  sunposition -=sunspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateE, 0);
}
void updateF(int value)
{

 if(w < -0.01)
            w = 0.01f;

   w -= wspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateF, 0);
    }
    void updateG(int value)
{

 if(positionboat1 <- 1.3)
            positionboat1 = 1.3f;
   positionboat1 -= boatspeed0;
    glutPostRedisplay();
    glutTimerFunc(100, updateG, 0);
}

   void updateH(int value)
{

            if(positionbus5 > 1.7)
            positionbus5 = -1.7f;
   positionbus5 += busspeed5;
    glutPostRedisplay();
    glutTimerFunc(100, updateH, 0);
}
   void updateI(int value)
{

 if(positionbus6 <- 1.7)
            positionbus6 = 1.7f;
   positionbus6 -= busspeed6;
    glutPostRedisplay();
    glutTimerFunc(100, updateI, 0);
}
   void updateJ(int value)
{

 if(moonposition3 >0.8)
            moonposition3 = -1.3f;
   moonposition3 += moonspeed3;
    glutPostRedisplay();
    glutTimerFunc(100, updateJ, 0);
}

void updateL(int value)
{
    if(mposition4 >0.70 )
        mposition4 = -1.0f;
    mposition4 += mspeed4;
    glutPostRedisplay();
    glutTimerFunc(100, updateL, 0);
}
void updateK(int value)
{
    if(mposition3 >0.70 )
        mposition3 = -1.0f;
    mposition3 += mspeed3;
    glutPostRedisplay();
    glutTimerFunc(100, updateK, 0);
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
            speed1 = speed1 + 0.01;
            speed2 = speed2 + 0.01;
            speed3 = speed3 + 0.01;
            speed5 = speed5 + 0.01;

            break;

        case 's':
            speed1 = speed1 - 0.01;
            speed2 = speed2 - 0.01;
              speed3=speed3 - 0.01;
            speed5=speed5 - 0.01;
            break;

                    case 'z':
            speed1 = 0.0f;
            break;


                    case 'x':
            speed2 = 0.0f;
            break;


                    case 'c':
            speed3 = 0.0f;
            break;


                    case 'v':
            speed5 = 0.0f;
            break;

                     case 'r':
           sunspeed=0.0009f;
            break;

                     case 't':
            sunspeed=0.0f;
            break;

                         case 'm':
                         moonspeed1=0.0009f;
                         break;

                      case 'n':
                           moonspeed1=0.0f;
                         break;
        case 'o':
                         moonspeed=0.0009f;
                         break;

                      case 'p':
                           moonspeed=0.0f;
                         break;

                                            case 'k':
                         mspeed1=0.005f;
                         break;

                      case 'l':
                           mspeed1=0.0f;
                         break;
                        case 'h':
                         mspeed2=0.005f;
                         break;

                      case 'j':
                           mspeed2=0.0f;
                         break;
                     case 'e':
                         wspeed=0.0f;
                         break;
                         case 'q':
                         wspeed=0.0003f;
                         break;
                        case 'G':
                          boatspeed0 = 0.01f;
                         break;
                      case 'H':
                     boatspeed0 =0.0f;
                     break;

                        case '[':
                         mspeed3=0.005f;
                         break;

                      case ']':
                           mspeed3=0.0f;
                         break;
                        case ';':
                         mspeed4=0.005f;
                         break;

                      case ':':
                           mspeed4=0.0f;
                         break;
		case 'Q':
			cout<<"Red light 1 to RED"<<endl;
			rl1[RED] = true;
			rl1[YELLOW] = false;
			rl1[GREEN] = false;
			busspeed5 = 0.0f;
			break;
		case 'W':
			cout<<"Red light 1 to YELLOW"<<endl;
			rl1[RED] = false;
			rl1[YELLOW] = true;
			rl1[GREEN] = false;
			break;

		case 'E':
			cout<<"Red light 1 to GREEN"<<endl;
			rl1[RED] = false;
			rl1[YELLOW] = false;
			rl1[GREEN] = true;
			busspeed5 = 0.02f;
			break;

		case 'A':
			cout<<"Red light 2 to RED"<<endl;
			rl2[RED] = true;
			rl2[YELLOW] = false;
			rl2[GREEN] = false;
			busspeed6 = 0.0f;
			break;

		case 'S':
			cout<<"Red light 2 to YELLOW"<<endl;
			rl2[RED] = false;
			rl2[YELLOW] = true;
			rl2[GREEN] = false;
			break;

		case 'D':
			cout<<"Red light 2 to GREEN"<<endl;
			rl2[RED] = false;
			rl2[YELLOW] = false;
			rl2[GREEN] = true;
			 busspeed6 = 0.02f;
			break;
			   case '<':
                         moonspeed3=0.0009f;
                         break;

                      case '>':
                           moonspeed3=0.0f;
                         break;


            case '_':
    glutDisplayFunc(details);
    glutPostRedisplay();
    break;
case ' ':
    glutDisplayFunc(day);
    sndPlaySound("sound0.wav", SND_ASYNC);

    glutPostRedisplay();
    break;

    case '1':
    glutDisplayFunc(evening);
    sndPlaySound("sound2.wav", SND_ASYNC);
    glutPostRedisplay();
    break;

case '2':
    glutDisplayFunc(night1);
    glutPostRedisplay();
    break;

case '3':
    glutDisplayFunc(night2);
    sndPlaySound("sound3.wav", SND_ASYNC);
    glutPostRedisplay();
    break;
    case '4':
    glutDisplayFunc(night3);
    sndPlaySound("sound4.wav", SND_ASYNC);
    glutPostRedisplay();
    break;
        case 'a':
            glutTimerFunc(110, update111, 0);
            break;

        case 'd':
            glutTimerFunc(110, update22, 0);
            break;
            glutPostRedisplay();
}
}


void update(int value)
{
    if(position < -1.5)
            position = 1.5f;
    if(position3 < -1.5)
            position3 = 1.5f;
    if(position2 < -1.5)
            position2 = 1.5;

        if(waveUp)
        {
            c1 += .00042;
            c2 += .00042;
            c3 += .00042;
            c4 += .00042;
            c5 += .00042;
            c6 += .00042;
            c7 += .00042;
            c8 += .00042;
            c9 += .00042;
            c10 += .00042;
            c11 += .00042;
            c12 += .00042;
            c13 += .00042;
            c14 += .00042;
            c15 += .00042;
            c16 += .00042;
            c17 += .00042;
        }
        else
        {
            c1 -= .00032;
            c2 -= .00032;
            c3 -= .00032;
            c4 -= .00032;
            c5 -= .00032;
            c6 -= .00032;
            c7 -= .00032;
            c8 -= .00032;
            c9 -= .00032;
            c10 -= .00032;
            c11 -= .00032;
            c12 -= .00032;
            c13 -= .00032;
            c14 -= .00032;
            c15 -= .00032;
            c16 -= .00032;
            c17 -= .00032;
        }
         if (c1 >= .08)
    {
        waveUp = false;
    }
    if (c1 < 0.0)
    {
        waveUp = true;
    }

    if (c2 >= .08)
    {
        waveUp = false;
    }
    if (c2 < 0.0)
    {
        waveUp = true;
    }
    if (c3 >= .08)
    {
        waveUp = false;
    }
    if (c3 < 0.0)
    {
        waveUp = true;
    }
    if (c4 >= .08)
    {
        waveUp = false;
    }
    if (c4 < 0.0)
    {
        waveUp = true;
    }
    if (c5 >= .08)
    {
        waveUp = false;
    }
    if (c5 < 0.0)
    {
        waveUp = true;
    }
    if (c6 >= .08)
    {
        waveUp = false;
    }
    if (c6 < 0.0)
    {
        waveUp = true;
    }
    if (c7 >= .08)
    {
        waveUp = false;
    }
    if (c7 < 0.0)
    {
        waveUp = true;
    }
    if (c8 >= .08)
    {
                waveUp = false;
    }
    if (c8 < 0.0)
    {
        waveUp = true;
    }
    if (c9 >= .08)
    {
        waveUp = false;
    }
    if (c9 < 0.0)
    {
        waveUp = true;
    }
    if (c10 >= .08)
    {
        waveUp = false;
    }
    if (c10 < 0.0)
    {
        waveUp = true;
    }
    if (c11 >= .08)
    {
        waveUp = false;
    }
    if (c11 < 0.0)
    {
    waveUp = true;
    }
    if (c12 >= .08)
    {
        waveUp = false;
    }
    if (c12 < 0.0)
    {
        waveUp = true;
    }
    if (c13 >= .08)
    {
        waveUp = false;
    }
    if (c13 < 0.0)
    {
        waveUp = true;
    }
    if (c14 >= .08)
    {
        waveUp = false;
    }
    if (c14 < 0.0)
    {
        waveUp = true;
    }
    if (c15 >= .08)

    {
        waveUp = false;
    }
    if (c15 < 0.0)
    {
        waveUp = true;
    }
    if (c16 >= .08)
    {
        waveUp = false;
    }
    if (c16 < 0.0)
    {
        waveUp = true;
    }
    if (c17 >= .08)
    {
        waveUp = false;
    }
    if (c17 < 0.0)
    {
        waveUp = true;
    }

    position -= boatspeed;
    position2 -= boatspeed1;
    position3 -= boatspeed2;
    glutPostRedisplay();
    glutTimerFunc(110, update, 0);
}
void update2(int value)
{
    if(position > 1.5)
            position = -1.5f;
    if(position3 > 1.5)
            position3 = -1.5f;
    if(position2 > 1.5)
            position2 = -1.5f;



    position += boatspeed;
    position2 += boatspeed1;
    position3 += boatspeed2;
    glutPostRedisplay();
    glutTimerFunc(110, update2, 0);
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            boatspeed = boatspeed + 0.01;
             boatspeed1 = boatspeed1 + 0.01;
              boatspeed2 = boatspeed2 + 0.01;

            break;
        case GLUT_KEY_DOWN:
            boatspeed = boatspeed - 0.01;
              boatspeed1 = boatspeed1 - 0.01;
                boatspeed2 = boatspeed2 - 0.01;
            break;
        case GLUT_KEY_LEFT:
              glutTimerFunc(110, update, 0);

            break;
        case GLUT_KEY_RIGHT:
          glutTimerFunc(110, update2, 0);

            break;
    }
    glutPostRedisplay();
}



int main(int argc, char** argv)
{
    cout << "Press d : For car and bus move in forward" << endl << endl;
    cout << "Press a : For car and bus move in backward " << endl << endl;
    cout << "Press w : For car and bus start  " << endl << endl;
    cout << "Press s : For car and bus decrease speed " << endl << endl;
    cout << "Press z : For stop 1st car " << endl << endl;
    cout << "Press x : For stop 2nd car" << endl << endl;
    cout << "Press c : For stop 3rd car " << endl << endl;
    cout << "Press v : For stop 4th car " << endl << endl;
    cout << "Press m : in night2 for increase moon speed " << endl << endl;
    cout << "Press n : in night2 for decrease moon speed " << endl << endl;
       cout << "Press k and h : for move man in beach " << endl << endl;
    cout << "Press l and j : for stop the man move in beach " << endl << endl;
    cout << "Press KEY_UP : For boat move in forward " << endl << endl;
    cout << "Press KEY_DOWN : For boat move in backward " << endl << endl;
    cout << "Press KEY_RIGHT :  For boat increase speed " << endl << endl;
    cout << "Press KEY_LEFT :  For boat decrease speed " << endl << endl;
    cout << "Press KEY_LEFT_BOTTOM_MOUSE :  For Cloud increase speed " << endl << endl;
    cout << "Press KEY_RIGHT_BOTTOM_MOUSE :  For Cloud decrease speed " << endl << endl;
     cout << "Press d : For car and bus move vehicles in market" << endl << endl;
    cout << "Press a : For car and bus stop vehicles in market " << endl << endl;
     cout << "Press g : For car and bus increase speed vehicles in market" << endl << endl;
    cout << "Press h : For car and bus decrease speed vehicles in market " << endl << endl;
    cout << "Press 1 : For Details our Group " << endl << endl;
    cout << "Press 2 : For the first or day view " << endl << endl;
    cout << "Press 3 : For 2nd or evening view " << endl << endl;
    cout << "Press 4 : For 3rd view or 1st night view " << endl << endl;
    cout << "Press 5 : For 4th view or 2nd night view " << endl << endl;
    cout << "Press 6 : For last and 5th view or 3rd night view " << endl << endl;


    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(1200, 600);   // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Marine Drive Road"); // Create a window with the given title
 glutDisplayFunc(details);

      glutTimerFunc(110, update, 0);
      glutTimerFunc(110, update2, 0);
	    glutTimerFunc(100, update11, 0);
		glutTimerFunc(110, update111, 0);
			glutTimerFunc(110, update22, 0);
 glutTimerFunc(100, updateA, 0);
 glutTimerFunc(100, updateB, 0);
 glutTimerFunc(100, updateC, 0);
 glutTimerFunc(100, updateD, 0);
    glutTimerFunc(100, updateE, 0);
    glutTimerFunc(100, updateF, 0);
    glutTimerFunc(100, updateG, 0);
       glutTimerFunc(100, updateH, 0);
   glutTimerFunc(100, updateI, 0);
      glutTimerFunc(100, updateJ, 0);
        glutTimerFunc(100, updateK, 0);
      glutTimerFunc(100, updateL, 0);
		glutKeyboardFunc(handleKeypress);
 glutMouseFunc(handleMouse);
   glutSpecialFunc(SpecialInput);

    glutMainLoop();
    return 0;
}

