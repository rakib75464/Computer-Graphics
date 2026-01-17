#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

float x1, y1, x2, y2, x3, y3; // Triangle vertices
float tx, ty, sx, sy, theta;  // Transformation variables
int choice;

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // Black triangle

    switch (choice) {
        case 1: // Translation
            glPushMatrix();
            glTranslatef(tx, ty, 0.0f);
            drawTriangle(x1, y1, x2, y2, x3, y3);
            glPopMatrix();
            break;

        case 2: // Scaling
            glPushMatrix();
            glTranslatef(x1, y1, 0.0f);    // Move to origin
            glScalef(sx, sy, 1.0f);
            glTranslatef(-x1, -y1, 0.0f);  // Move back
            drawTriangle(x1, y1, x2, y2, x3, y3);
            glPopMatrix();
            break;

        case 3: // Rotation
            glPushMatrix();
            glTranslatef(x1, y1, 0.0f);             // Move to origin
            glRotatef(theta, 0.0f, 0.0f, 1.0f);     // Rotate around Z-axis
            glTranslatef(-x1, -y1, 0.0f);           // Move back
            drawTriangle(x1, y1, x2, y2, x3, y3);
            glPopMatrix();
            break;

        default:
            drawTriangle(x1, y1, x2, y2, x3, y3); // Original triangle
            break;
    }

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    cout << "Enter the vertices of the triangle:\n";
    cout << "Point 1 (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Point 2 (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Point 3 (x3, y3): ";
    cin >> x3 >> y3;

    cout << "Choose an option:\n";
    cout << "1. Translate\n";
    cout << "2. Scale\n";
    cout << "3. Rotate\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter translation factors (tx, ty): ";
        cin >> tx >> ty;
    } else if (choice == 2) {
        cout << "Enter scaling factors (sx, sy): ";
        cin >> sx >> sy;
    } else if (choice == 3) {
        char dir;
        cout << "Enter rotation angle (theta): ";
        cin >> theta;
        cout << "Clockwise (C) or Anti-clockwise (A)? ";
        cin >> dir;
        if (dir == 'C' || dir == 'c') {
            theta = -theta; // Negative for clockwise
        }
    }

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle Transformations");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
