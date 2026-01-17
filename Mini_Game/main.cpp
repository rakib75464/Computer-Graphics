#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define NUM_ENEMIES 5
#define NUM_BULLETS 10
#define NUM_STARS 50

// Global variables
float playerX = 0.0f;
float playerSpeed = 0.05f;
int score = 0;
bool gameOver = false;

// Structure for Enemy
struct Enemy {
    float x, y;
    bool active;
};

Enemy enemies[NUM_ENEMIES];

// Structure for Bullet
struct Bullet {
    float x, y;
    bool active;
};

Bullet bullets[NUM_BULLETS];

// Structure for Stars
struct Star {
    float x, y;
    float size;
};

Star stars[NUM_STARS];

// Function to render player spaceship
void renderPlayer() {
    glPushMatrix();
    glTranslatef(playerX, -0.8f, 0.0f); // Position player
    glColor3f(0.0f, 1.0f, 0.0f); // Green color for the spaceship
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.1f);  // Tip of the spaceship
    glVertex2f(-0.05f, -0.1f); // Left side of the spaceship
    glVertex2f(0.05f, -0.1f);  // Right side of the spaceship
    glEnd();

    // Drawing spaceship's tail for more design
    glColor3f(1.0f, 0.0f, 0.0f); // Red tail
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, -0.2f);  // Tip of the tail
    glVertex2f(-0.05f, -0.3f); // Left side of the tail
    glVertex2f(0.05f, -0.3f);  // Right side of the tail
    glEnd();
    glPopMatrix();
}

// Function to render stars in the background
void renderStars() {
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < NUM_STARS; ++i) {
        glColor3f(1.0f, 1.0f, 1.0f); // White color for stars
        glVertex2f(stars[i].x, stars[i].y);
    }
    glEnd();
}

// Function to initialize stars
void initStars() {
    srand(time(0));
    for (int i = 0; i < NUM_STARS; ++i) {
        stars[i].x = (rand() % 200 - 100) / 100.0f; // Random x position
        stars[i].y = (rand() % 200 - 100) / 100.0f; // Random y position
        stars[i].size = (rand() % 2 + 1); // Random size
    }
}

void shootBullet() {
    for (int i = 0; i < NUM_BULLETS; ++i) {
        if (!bullets[i].active) {
            bullets[i].x = playerX;
            bullets[i].y = -0.7f;
            bullets[i].active = true;
            break;
        }
    }
}


// Function to move the player with keyboard input
void keyboard(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') playerX -= playerSpeed; // Move left
    if (key == 'd' || key == 'D') playerX += playerSpeed; // Move right
    if (key == 'q' || key == 'Q') exit(0); // Quit the game
    if (key == ' ') shootBullet(); // Shoot on space bar press
}

// Function to shoot bullets

// Function to update bullet positions
void updateBullets() {
    for (int i = 0; i < NUM_BULLETS; ++i) {
        if (bullets[i].active) {
            bullets[i].y += 0.05f; // Bullet moves upwards
            if (bullets[i].y > 1.0f) bullets[i].active = false; // Deactivate bullet when it leaves the screen
        }
    }
}

// Function to render bullets
// Function to render bullets
void renderBullets() {
    for (int i = 0; i < NUM_BULLETS; ++i) {
        if (bullets[i].active) {
            glPushMatrix();
            glTranslatef(bullets[i].x, bullets[i].y, 0.0f);
            glBegin(GL_QUADS); // Changed to GL_QUADS for a rectangular bullet
            glVertex2f(-0.02f, 0.0f);  // Left side of the bullet
            glVertex2f(0.02f, 0.0f);   // Right side of the bullet
            glVertex2f(0.02f, 0.1f);   // Top-right corner of the bullet
            glVertex2f(-0.02f, 0.1f);  // Top-left corner of the bullet
            glEnd();
            glPopMatrix();
        }
    }
}


// Function to initialize enemies
void initEnemies() {
    srand(time(0));
    for (int i = 0; i < NUM_ENEMIES; ++i) {
        enemies[i].x = (rand() % 200 - 100) / 100.0f; // Random x position
        enemies[i].y = 1.0f + (rand() % 200) / 100.0f; // Random y position
        enemies[i].active = true;
    }
}

// Function to update enemy positions
void updateEnemies() {
    for (int i = 0; i < NUM_ENEMIES; ++i) {
        if (enemies[i].active) {
            enemies[i].y -= 0.01f; // Move enemy down
            if (enemies[i].y < -1.0f) enemies[i].y = 1.0f; // Reset position when enemy moves off screen
        }
    }
}

// Function to render enemies
void renderEnemies() {
    for (int i = 0; i < NUM_ENEMIES; ++i) {
        if (enemies[i].active) {
            glPushMatrix();
            glTranslatef(enemies[i].x, enemies[i].y, 0.0f);
            glBegin(GL_QUADS);
            glVertex2f(-0.05f, 0.05f);
            glVertex2f(0.05f, 0.05f);
            glVertex2f(0.05f, -0.05f);
            glVertex2f(-0.05f, -0.05f);
            glEnd();
            glPopMatrix();
        }
    }
}

// Function to check for collisions between bullets and enemies
void checkCollisions() {
    for (int i = 0; i < NUM_BULLETS; ++i) {
        if (bullets[i].active) {
            for (int j = 0; j < NUM_ENEMIES; ++j) {
                if (enemies[j].active) {
                    if (bullets[i].x > enemies[j].x - 0.05f && bullets[i].x < enemies[j].x + 0.05f &&
                        bullets[i].y > enemies[j].y - 0.05f && bullets[i].y < enemies[j].y + 0.05f) {
                        bullets[i].active = false; // Deactivate bullet
                        enemies[j].active = false; // Deactivate enemy
                        score++; // Increase score
                    }
                }
            }
        }
    }
}

// Function to render score and game over message
void renderScore() {
    if (gameOver) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for game over message
        glRasterPos2f(-0.2f, 0.0f);
        std::string gameOverText = "GAME OVER!";
        for (char c : gameOverText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    } else {
        glColor3f(1.0f, 1.0f, 1.0f); // White color for score
        glRasterPos2f(-0.9f, 0.9f);
        std::string scoreText = "Score: " + std::to_string(score);
        for (char c : scoreText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }
}

// Function to update the game
void update() {
    if (gameOver) return; // Stop the game if it's over

    updateEnemies();
    updateBullets();
    checkCollisions();

    glutPostRedisplay(); // Refresh the screen
}

// Function to render the entire game scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    renderStars();  // Render stars in the background
    renderPlayer(); // Render the player spaceship
    renderEnemies(); // Render enemies
    renderBullets(); // Render bullets
    renderScore(); // Render score

    glutSwapBuffers(); // Swap buffers for double buffering
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Space Shooter");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black

    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutKeyboardFunc(keyboard); // Register keyboard function

    initEnemies(); // Initialize enemies
    initStars(); // Initialize stars
    glutMainLoop(); // Start the game loop

    return 0;
}
