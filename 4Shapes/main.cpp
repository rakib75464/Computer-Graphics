#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;
float points[3][2];
float transformedPoints[3][2];
void setPoints(float x1, float y1, float x2, float y2, float x3, float y3) {
    points[0][0] = x1; points[0][1] = y1;
     points[1][0] = x2; points[1][1] = y2;
points[2][0] = x3; points[2][1] = y3;
}

void translate(float tx, float ty) {
    for (int i = 0; i < 3; i++) {
        transformedPoints[i][0] = points[i][0] + tx;
        transformedPoints[i][1] = points[i][1] + ty;
    }
}

void scale(float sx, float sy) {
    for (int i = 0; i < 3; i++) {
        transformedPoints[i][0] = points[i][0] * sx;
        transformedPoints[i][1] = points[i][1] * sy;
    }
}
void rotate(float angle, char direction) {
     float radians = angle * 3.1416 / 180.0;
  if (direction == 'c') radians = -radians;

    for (int i = 0; i < 3; i++) {
        float x = points[i][0];
        float y = points[i][1];
        transformedPoints[i][0] = x * cos(radians) - y * sin(radians);
        transformedPoints[i][1] = x * sin(radians) + y * cos(radians);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(transformedPoints[i][0], transformedPoints[i][1]);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char** argv) {
    float x1, y1, x2, y2, x3, y3;
    int choice;
    float tx, ty, sx, sy, angle;
    char direction[3];

    cout << "Enter the 3 points of the triangle (x y):" << endl;
    cout << "Point 1 (x y): ";
    cin >> x1 >> y1;
    cout << "Point 2 (x y): ";
    cin >> x2 >> y2;
    cout << "Point 3 (x y): ";
    cin >> x3 >> y3;

    setPoints(x1, y1, x2, y2, x3, y3);

    cout << "\nChoose a Transformation:\n";
    cout << "1: Translation\n";
    cout << "2: Scaling\n";
    cout << "3: Rotation\n";
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter translation factors (tx ty): ";
            cin >> tx >> ty;
            translate(tx, ty);
            break;
        case 2:
            cout << "Enter scaling factors (sx sy): ";
            cin >> sx >> sy;
            scale(sx, sy);
            break;
        case 3:
            cout << "Enter rotation angle (degrees): ";
            cin >> angle;
            cout << "Clockwise (cw) or Anticlockwise (ac): ";
            cin >> direction;
            if (direction[0] == 'c' && direction[1] == 'w') {
                rotate(angle, 'c');
            } else if (direction[0] == 'a' && direction[1] == 'c') {
                rotate(angle, 'a');
            } else {
                cout << "Invalid direction! Defaulting to anticlockwise.\n";
                rotate(angle, 'a');
            }
            break;
        default:
            cout << "Invalid choice! No transformation applied.\n";
            break;
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
