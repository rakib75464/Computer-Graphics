#include <windows.h>
#include<stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

void lines() {
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.92f, 0.25f, 0.97f);

    for (int x = 0; x <= 330; x += 10) { // Vertical Line
        glVertex2f(x, 0);
        glVertex2f(x, 240);
    }

    for (int y = 0; y <= 240; y += 10) { // Horizontal Line
        glVertex2f(0, y);
        glVertex2f(330, y);
    }

    glEnd();
}

void black() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    // Lower Upper big box
    glVertex2f(80, 20);
    glVertex2f(250, 20);
    glVertex2f(250, 230);
    glVertex2f(80, 230);

    // Left Right big box
    glVertex2f(10, 90);
    glVertex2f(320, 90);
    glVertex2f(320, 160);
    glVertex2f(10, 160);

    for (int x = 250, y = 30; x < 320; x += 10, y += 10) { // Right side Stair
        glVertex2f(x, y);
        glVertex2f(x + 10, y);
        glVertex2f(x + 10, 250 - y);
        glVertex2f(x, 250 - y);
    }

    for (int x = 80, y = 30; x > 10; x -= 10, y += 10) { // Left side Stair
        glVertex2f(x, y);
        glVertex2f(x - 10, y);
        glVertex2f(x - 10, 250 - y);
        glVertex2f(x, 250 - y);
    }

    glEnd();
}

void yellow() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);

    // Down bar
    glVertex2f(80, 30);
    glVertex2f(250, 30);
    glVertex2f(250, 40);
    glVertex2f(80, 40);

    // Upper bar
    glVertex2f(80, 210);
    glVertex2f(250, 210);
    glVertex2f(250, 220);
    glVertex2f(80, 220);

    // Left bar
    glVertex2f(20, 90);
    glVertex2f(30, 90);
    glVertex2f(30, 160);
    glVertex2f(20, 160);

    // Right bar
    glVertex2f(300, 90);
    glVertex2f(310, 90);
    glVertex2f(310, 160);
    glVertex2f(300, 160);

    // Lower portion
    glVertex2f(80, 40); // Left down most 2 box
    glVertex2f(100, 40);
    glVertex2f(100, 50);
    glVertex2f(80, 50);

    glVertex2f(110, 40); // Left down 5 box
    glVertex2f(160, 40);
    glVertex2f(160, 50);
    glVertex2f(110, 50);

    glVertex2f(110, 50); // Left down 4 box
    glVertex2f(150, 50);
    glVertex2f(150, 60);
    glVertex2f(110, 60);

    glVertex2f(120, 60); // Left down 3 box
    glVertex2f(150, 60);
    glVertex2f(150, 70);
    glVertex2f(120, 70);

    glVertex2f(130, 70); // Left down 1 box
    glVertex2f(140, 70);
    glVertex2f(140, 80);
    glVertex2f(130, 80);

    glVertex2f(170, 40); // Right down 5 box
    glVertex2f(220, 40);
    glVertex2f(220, 50);
    glVertex2f(170, 50);

    glVertex2f(180, 60); // Right down 4 box
    glVertex2f(220, 60);
    glVertex2f(220, 50);
    glVertex2f(180, 50);

    glVertex2f(180, 60); // Right down 3 box
    glVertex2f(210, 60);
    glVertex2f(210, 70);
    glVertex2f(180, 70);

    glVertex2f(190, 80); // Right down 1 box
    glVertex2f(200, 80);
    glVertex2f(200, 70);
    glVertex2f(190, 70);

    glVertex2f(230, 40); // Right down most 2 box
    glVertex2f(250, 40);
    glVertex2f(250, 50);
    glVertex2f(230, 50);

    // Top portion
    glVertex2f(80, 200); // Left side top short bar
    glVertex2f(140, 200);
    glVertex2f(140, 210);
    glVertex2f(80, 210);

    glVertex2f(110, 200); // Left side 16 box
    glVertex2f(140, 200);
    glVertex2f(140, 160);
    glVertex2f(110, 160);

    glVertex2f(110, 150); // Left side down 2 box
    glVertex2f(130, 150);
    glVertex2f(130, 160);
    glVertex2f(110, 160);

    glVertex2f(110, 160); // Left most side 3 box
    glVertex2f(100, 160);
    glVertex2f(100, 190);
    glVertex2f(110, 190);

    // Middle
    glVertex2f(150, 200);
    glVertex2f(180, 200);
    glVertex2f(180, 210);
    glVertex2f(150, 210);

    glVertex2f(190, 200); // Right side top short bar
    glVertex2f(250, 200);
    glVertex2f(250, 210);
    glVertex2f(190, 210);

    glVertex2f(190, 200); // Right side 16 box
    glVertex2f(220, 200);
    glVertex2f(220, 160);
    glVertex2f(190, 160);

    glVertex2f(200, 150); // Right side down 2 box
    glVertex2f(220, 150);
    glVertex2f(220, 160);
    glVertex2f(200, 160);

    glVertex2f(220, 160); // Right most side 3 box
    glVertex2f(230, 160);
    glVertex2f(230, 190);
    glVertex2f(220, 190);

    for (int x = 250, y = 40; x < 300; x += 10, y += 10) { // Right side down stair
        glVertex2f(x, y);
        glVertex2f(x + 10, y);
        glVertex2f(x + 10, y + 20);
        glVertex2f(x, y + 20);
    }

    for (int x = 80, y = 40; x > 30; x -= 10, y += 10) { // Left side down stair
        glVertex2f(x, y);
        glVertex2f(x - 10, y);
        glVertex2f(x - 10, y + 20);
        glVertex2f(x, y + 20);
    }

    for (int x = 250, y = 210; x < 310; x += 10, y -= 10) { // Right side top stair
        glVertex2f(x, y);
        glVertex2f(x + 10, y);
        glVertex2f(x + 10, y - 20);
        glVertex2f(x, y - 20);
    }

    for (int x = 80, y = 210; x > 30; x -= 10, y -= 10) { // Left side top stair
        glVertex2f(x, y);
        glVertex2f(x - 10, y);
        glVertex2f(x - 10, y - 20);
        glVertex2f(x, y - 20);
    }

    glEnd();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White
    glClear(GL_COLOR_BUFFER_BIT);

    black();
    yellow();
    lines();

    glFlush(); // Render now
}

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 330.0, 0.0, 240.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(660, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Batman Logo");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}
