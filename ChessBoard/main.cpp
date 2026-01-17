#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawChessboard() {
    glClear(GL_COLOR_BUFFER_BIT);

    const int gridSize = 8;
    const float squareSize = 50.0f;

    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {

            if ((row + col) % 2 == 0) {
                glColor3f(1.0f, 1.0f, 1.0f);
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);
            }


            float x = col * squareSize;
            float y = row * squareSize;


            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + squareSize, y);
            glVertex2f(x + squareSize, y + squareSize);
            glVertex2f(x, y + squareSize);
            glEnd();
        }
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Chessboard");
    init();
    glutDisplayFunc(drawChessboard);
    glutMainLoop();
    return 0;
}
