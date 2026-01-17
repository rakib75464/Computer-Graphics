#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <string.h>
#include <windows.h>

float tx = 0.0;
float rx = 0.0;
float bx = 0.0;
int isNight = 0; // Variable to toggle between day and night
 int isShipMoving = 1; // Variable to toggle ship movement (1 = moving, 0 = stopped)

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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background color black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
}

void sky()
{
    glBegin(GL_QUADS);
    if (isNight)
        glColor3f(0.0f, 0.0f, 0.1f); // Dark blue for night sky
    else
        glColor3f(0.5f, 0.8f, 1.0f); // Light blue for day sky
    glVertex2f(-50, 50);
    glVertex2f(50, 50);
    glVertex2f(50, 7);
    glVertex2f(-50, 7);
    glEnd();
}

 void building() {
    // Building body (rectangle)
    glColor3f(0.1, 0.1, 0); // Light gray color for the building
    glBegin(GL_QUADS);
    glVertex2f(-10, 7);  // Bottom left corner of the building
    glVertex2f(10, 7);   // Bottom right corner of the building
    glVertex2f(10, 30);  // Top right corner of the building
    glVertex2f(-10, 30); // Top left corner of the building
    glEnd();

    if (isNight)
    glColor3f( 1.0, 1.0, 0.0);
    else// Building windows (small rectangles)
    glColor3f( 1.0, 1.0, 1.0); // Blue color for the first set of windows
    glBegin(GL_QUADS);
    glVertex2f(-8, 20); // Left window
    glVertex2f(-4, 20);
    glVertex2f(-4, 25);
    glVertex2f(-8, 25);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(4, 20);  // Right window
    glVertex2f(8, 20);
    glVertex2f(8, 25);
    glVertex2f(4, 25);
    glEnd();

    // Adding more windows with yellow color
    // Yellow color for additional windows
    glBegin(GL_QUADS);
    glVertex2f(-8, 15); // Left window
    glVertex2f(-4, 15);
    glVertex2f(-4, 18);
    glVertex2f(-8, 18);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(4, 15);  // Right window
    glVertex2f(8, 15);
    glVertex2f(8, 18);
    glVertex2f(4, 18);
    glEnd();

    // Third row of yellow windows
    glBegin(GL_QUADS);
    glVertex2f(-8, 10); // Left window
    glVertex2f(-4, 10);
    glVertex2f(-4, 13);
    glVertex2f(-8, 13);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(4, 10);  // Right window
    glVertex2f(8, 10);
    glVertex2f(8, 13);
    glVertex2f(4, 13);
    glEnd();

    // Vertical line between the left and right windows
    glColor3f(0.0, 0.0, 0.0); // Black color for the line
    glBegin(GL_LINES);
    glVertex2f(0, 7);   // Bottom of the building
    glVertex2f(0, 30);  // Top of the building
    glEnd();
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
        glColor3f(0.5, 0.5, 0.5); // Gray color for clouds at night
    else
        glColor3f(1.0, 1.0, 1.0); // White color for clouds during the day

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
    if (rx > 70)
    {
        rx = -70;
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

    tx -= 0.04;
    if (tx < -70)
    {
        tx = 70;
    }

    glutPostRedisplay();
}

void river()
{
    glBegin(GL_QUADS);
    if (isNight)
        glColor3f(0.0, 0.0, 0.3); // Darker blue for the river at night
    else
        glColor3f(0.0, 0.5, 1.0); // Bright blue for the river during the day
    glVertex2f(-50, -17);
    glVertex2f(50, -17);
    glVertex2f(50, -50);
    glVertex2f(-50, -50);
    glEnd();
}

void grass()
{
    glBegin(GL_QUADS);
    if (isNight)
        glColor3f(0.0, 0.3, 0.0); // Darker green for grass at night
    else
        glColor3f(0.0, 0.5, 0.0); // Bright green for grass during the day
    glVertex2f(-50, -10);
    glVertex2f(50, -10);
    glVertex2f(50, -17);
    glVertex2f(-50, -17);
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

    clouds();
     building();
    road();
    car();
    grass();
    river();
    ship();
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
     if (key == 'n' || key == 'N')
    {
        isNight = 1; // Set to night view
    }
    else if (key == 'd' || key == 'D')
    {
        isNight = 0; // Set to day view
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        isShipMoving = !isShipMoving; // Toggle ship movement
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Day and Night Scene");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutMouseFunc(mouse); // Register mouse callback
    glutMainLoop();
    return 0;
}

