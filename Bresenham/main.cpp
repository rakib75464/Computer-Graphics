#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

int roundOff(double value)
{
    if (value > 0)
        return (int)(value + 0.5);
    else
        return (int)(value - 0.5);
}

double x1, y1, x2, y2;

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void bresenham(double x1, double y1, double x2, double y2)
{
    glBegin(GL_POINTS);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int dstart = 2 * dy - dx;

    int x = roundOff(x1);
    int y = roundOff(y1);
    int xEnd = roundOff(x2);

    glVertex2i(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    if (x1 < x2)
    {
        while (x < xEnd)
        {
            x++;
            if (dstart <= 0)
            {
                dstart = dstart + 2 * dy;
            }
            else
            {
                y++;
                dstart = dstart + 2 * (dy - dx);
            }

            glVertex2i(x, y);
            cout << "x = " << x << ", y = " << y << endl;
        }
    }
    else
    {
        while (x > xEnd)
        {
            y++;

            if (dstart <= 0)
            {
                dstart = dstart + 2 * dx;
            }
            else
            {
                x++;
                dstart = dstart + 2 * (dx - dy);
            }

            glVertex2i(x, y);
            cout << "x = " << x << ", y = " << y << endl;
        }
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(3.0);

    bresenham(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Bresenham Enter starting points (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending points (x2, y2): ";
    cin >> x2 >> y2;
    cout << endl;

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Algorithm");
    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
