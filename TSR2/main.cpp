#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float points[3][2];  // Array to store triangle points
float transformedPoints[3][2];  // Array for transformed points
int choice;  // User's choice for transformation
float tx, ty, sx, sy, angle;  // Transformation parameters

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original triangle
    glColor3f(0.0, 1.0, 0.0);  // Green color
    glBegin(GL_TRIANGLES);
    glVertex2f(points[0][0], points[0][1]);
    glVertex2f(points[1][0], points[1][1]);
    glVertex2f(points[2][0], points[2][1]);
    glEnd();

    // Transformed triangle
    glColor3f(1.0, 0.0, 0.0);  // Red color
    glBegin(GL_TRIANGLES);
    glVertex2f(transformedPoints[0][0], transformedPoints[0][1]);
    glVertex2f(transformedPoints[1][0], transformedPoints[1][1]);
    glVertex2f(transformedPoints[2][0], transformedPoints[2][1]);
    glEnd();

    glFlush();
}

// Perform translation
void translate(float tx, float ty) {
    for (int i = 0; i < 3; i++) {
        transformedPoints[i][0] = points[i][0] + tx;
        transformedPoints[i][1] = points[i][1] + ty;
    }
}

// Perform scaling
void scale(float sx, float sy) {
    for (int i = 0; i < 3; i++) {
        transformedPoints[i][0] = points[i][0] * sx;
        transformedPoints[i][1] = points[i][1] * sy;
    }
}

// Perform rotation
void rotate(float angle, char direction) {
    float radians = (angle * 3.1416) / 180.0;
    if (direction == 'c') radians = -radians;  // Clockwise rotation

    for (int i = 0; i < 3; i++) {
        transformedPoints[i][0] = points[i][0] * cos(radians) - points[i][1] * sin(radians);
        transformedPoints[i][1] = points[i][0] * sin(radians) + points[i][1] * cos(radians);
    }
}

// Initialize GLUT
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background
    glColor3f(1.0, 1.0, 1.0);          // White color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);  // Orthographic projection for a range
}

// Main function
int main(int argc, char** argv) {
    // Input points
    printf("Enter 3 points for the triangle (x and y coordinates):\n");
    for (int i = 0; i < 3; i++) {
        printf("Point %d (x y): ", i + 1);
        scanf("%f %f", &points[i][0], &points[i][1]);
        transformedPoints[i][0] = points[i][0];
        transformedPoints[i][1] = points[i][1];
    }

    // Transformation options
    printf("\nChoose an operation:\n");
    printf("1: Translation\n");
    printf("2: Scaling\n");
    printf("3: Rotation\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter translation factors (tx ty): ");
            scanf("%f %f", &tx, &ty);
            translate(tx, ty);
            break;

        case 2:
            printf("Enter scaling factors (sx sy): ");
            scanf("%f %f", &sx, &sy);
            scale(sx, sy);
            break;

        case 3:
            printf("Enter angle for rotation (in degrees): ");
            scanf("%f", &angle);
            char direction[3];
            printf("Clockwise (cw) or Anticlockwise (ac): ");
            scanf("%s", direction);
            if (direction[0] == 'c' && direction[1] == 'w') {
                rotate(angle, 'c');  // Clockwise
            } else if (direction[0] == 'a' && direction[1] == 'c') {
                rotate(angle, 'a');  // Anticlockwise
            } else {
                printf("Invalid direction! Defaulting to anticlockwise.\n");
                rotate(angle, 'a');
            }
            break;

        default:
            printf("Invalid choice. No transformation applied.\n");
            break;
    }

    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangle Transformation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
