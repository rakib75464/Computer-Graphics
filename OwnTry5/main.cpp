#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

enum ColorMode { BLACK, BLUE, YELLOW, GREEN };
ColorMode currentColor = BLACK;

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
            // Set color for "white" squares
            if ((row + col) % 2 == 0) {
                glColor3f(1.0f, 1.0f, 1.0f); // White square
            } else {
                // Set color based on current mode
                switch (currentColor) {
                    case BLACK:
                        glColor3f(0.0f, 0.0f, 0.0f);
                        break;
                    case BLUE:
                        glColor3f(0.0f, 0.0f, 1.0f);
                        break;
                    case YELLOW:
                        glColor3f(1.0f, 1.0f, 0.0f);
                        break;
                    case GREEN:
                        glColor3f(0.0f, 1.0f, 0.0f);
                        break;
                }
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

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'k':
        case 'K':
            currentColor = BLACK;
            break;
        case 'b':
        case 'B':
            currentColor = BLUE;
            break;
        case 'y':
        case 'Y':
            currentColor = YELLOW;
            break;
        case 'g':
        case 'G':
            currentColor = GREEN;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chessboard");
    init();
    glutDisplayFunc(drawChessboard);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}
