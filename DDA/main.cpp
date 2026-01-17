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

void dda(double x1, double y1, double x2, double y2, double m)
{
    glBegin(GL_POINTS);

    if (m < 1)
    {
   while (x1 <= x2)
        {
            glVertex2i(roundOff(x1), roundOff(y1));
            cout << "x1 = " << x1 << ", y1 = " << roundOff(y1) << endl;

            x1 += 1;
            y1 = y1 + m;

            if (roundOff(x1) > roundOff(x2) && roundOff(y1) > roundOff(y2))
                break;
        }
    }

    else if (m == 1)
    {
        cout << "x1 = " << x1 << ", y1 = " << y1 << endl;

        while (x1 <= x2 && y1 <= y2)
        {
            glVertex2i(roundOff(x1), roundOff(y1));
            cout << "x1 = " << x1 << ", y1 = " << y1 << endl;

            x1 += 1;
            y1 += 1;
            if (roundOff(x1) > roundOff(x2) && roundOff(y1) > roundOff(y2))
                break;
        }
    }

    else
    {
        cout << "x1 = " << x1 << ", y1 = " << y1 << endl;

        while (y1 <= y2)
        {
            glVertex2i(roundOff(x1), roundOff(y1));
            cout << "x1 = " << roundOff(x1) << ", y1 = " << y1 << endl;

            y1 += 1;
            x1 = x1 + (1 / m);

            if (roundOff(x1) > roundOff(x2) && roundOff(y1) > roundOff(y2))
                break;
        }
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(3.0);

    double m = (y2 - y1) / (x2 - x1);
    dda(x1, y1, x2, y2, m);

    glFlush();
}

int main(int argc, char** argv)
{
    cout << "DDA Enter starting points (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending points (x2, y2): ";
    cin >> x2 >> y2;
    cout << endl;

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Algorithm");
    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
