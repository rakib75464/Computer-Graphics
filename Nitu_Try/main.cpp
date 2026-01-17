#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include <thread>
#define PI 3.14159265358979323846
///Mail circle
void mainCircle(float x, float y, float r) {
    int numSegments = 100; // The number of triangles used to draw the circle
    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0); //Black color

    for (int i = 0; i < numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments; // Calculate angle
        float xOffset = r * cos(angle);
        float yOffset = r * sin(angle);
        glColor3ub(0,0,0);
        glVertex2f(x + xOffset, y + yOffset);
    }
    glEnd();
}
///This part is for only keyboard
bool isNight = false; // Toggle between day and night
float shipX = 0.0f;  ///Initial X position of the ships
float shipY = 0.0f;  ///Initial Y position of the ships
float ship2X = 50.0f;  /// Start from the right
float shipSpeed=2.0f;
bool shipMovingLeft = true; /// Controls direction
bool isWaiting = false; /// Indicates waiting state
bool shipRotated = false; /// Tracks rotation
float cloudOffsetX = 0.0f; // Controls cloud movement
float cloudSpeed = 0.05f;  // Adjust for faster/slower clouds
float resetPosition = 100.0f; // Reset point when clouds move past the screen
float M_PI=3.14159265358979323846;

void setBackgroundColor() {
    if (isNight) {
        glClearColor(0.0f, 0.1f, 0.2f, 1.0f); // Dark Water for Night
    } else {
        glClearColor(0.8f, 0.9f, 1.0f, 1.0f); // Light Water for Day
    }
}
///Bg color
void initGL() {
    setBackgroundColor(); /// Main BG water color
}

/// Function to draw a small circle (used for clouds & stars)
void drawSmallCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0f;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
///Sky day and Night
void drawSky() {
    glBegin(GL_POLYGON);
    if (isNight) {
        // Night sky colors
        glColor3ub(25, 25, 112); // Midnight Blue
        glVertex2f(-50, 40);
        glColor3ub(0, 0, 128); // Navy Blue
        glVertex2f(50, 40);
        glColor3ub(25, 25, 150); // Deep Blue
        glVertex2f(50, 28);
        glColor3ub(70, 130, 180); // Steel Blue
        glVertex2f(-50, 28);
    } else {
        // Day sky colors
        glColor3ub(216, 232, 240);
        glVertex2f(-50, 40);
        glColor3ub(204, 228, 240);
        glVertex2f(50, 40);
        glColor3ub(192, 224, 240);
        glVertex2f(50, 28);
        glColor3ub(125, 193, 227);
        glVertex2f(-50, 28);
    }
    glEnd();
}
/// Function to handle the sky
void handleKeyPress(unsigned char key, int x, int y) {
    if (key == 'v' || key == 'V') {
        isNight = !isNight;
        glutPostRedisplay();
    }
}
/// Function to draw small clouds
void drawSmallCloud(float x, float y) {
    glColor3ub(255, 255, 255); // White color for clouds
    drawSmallCircle(x, y, 2.0);   // Center
    drawSmallCircle(x + 2.0, y + 0.5, 2.5);
    drawSmallCircle(x - 2.0, y + 0.5, 2.5);
    drawSmallCircle(x + 4.0, y, 2.0);
    drawSmallCircle(x - 4.0, y, 2.0);
    drawSmallCircle(x, y + 1.5, 1.5);
}

/// Function to draw moving clouds
void drawSmallClouds() {
    drawSmallCloud(45 + cloudOffsetX, 37); // Left cloud
    drawSmallCloud(70 + cloudOffsetX, 34); // Center cloud
    drawSmallCloud(95 + cloudOffsetX, 38); // Right cloud
    drawSmallCloud(120 + cloudOffsetX, 33); // Far-right cloud
}

/// Function to draw stars at night
void drawStars() {
    glColor3ub(255, 255, 255); // White stars
    drawSmallCircle(29,38, 0.1);
    drawSmallCircle(12,36, 0.2);
    drawSmallCircle(2, 38, 0.1);
    drawSmallCircle(-18,37, 0.1);
    drawSmallCircle(-42,38, 0.005);
    drawSmallCircle(-29,35, 0.006);
}

/// Function to update cloud movement (only when day mode is active)
void updateClouds(int value) {
    if (!isNight) { // Move clouds only in day mode
        cloudOffsetX -= cloudSpeed;
        if (cloudOffsetX < -resetPosition) {
            cloudOffsetX = 0; // Reset cloud position
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateClouds, 0); // Call update every 16ms (~60 FPS)
}


///Circle for sun
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.1416 / 180.0f; /// Convert degrees to radians
        float x = r * cos(angle);         /// Calculate x-coordinate
        float y = r * sin(angle);         /// Calculate y-coordinate
        glVertex2f(cx + x, cy + y);       /// Add vertex
    }
    glEnd();
}
/// Function to draw the moon
void drawMoon(float cx, float cy, float r) {
    glColor3ub(220, 220, 220); // Light Gray Moon
    drawCircle(cx, cy, r);

    // Create a small shadow effect on the moon
    glColor3ub(169, 169, 169); // Dark Gray Shadow
    drawCircle(cx + 0.2f, cy + 0.2f, r * 0.6f); // Small shadow
}

/// Function to draw gradient water (Day/Night)
void drawGradientWater() {
    glBegin(GL_QUADS);

    if (isNight) {
        // Night Water Gradient (Darker Blue)
        glColor3f(0.0f, 0.1f, 0.2f); // Dark blue at the top
        glVertex2f(-50.0f, 40.0f);
        glVertex2f(50.0f, 40.0f);

        glColor3f(0.0f, 0.0f, 0.1f); // Almost black at the bottom
        glVertex2f(50.0f, -40.0f);
        glVertex2f(-50.0f, -40.0f);
    } else {
        // Day Water Gradient (Light Blue)
        glColor3f(0.7f, 0.9f, 1.0f); // Light blue at the top (Shallow Water)
        glVertex2f(-50.0f, 40.0f);
        glVertex2f(50.0f, 40.0f);

        glColor3f(0.0f, 0.3f, 0.6f); // Deep blue at the bottom
        glVertex2f(50.0f, -40.0f);
        glVertex2f(-50.0f, -40.0f);
    }

    glEnd();
}
/// 1st ship
void drawShip(float offsetX, float offsetY) {
    float scale = 0.7f; // Scaling factor to make the ship smaller

    glPushMatrix();
    glTranslatef(offsetX + shipX, offsetY + shipY, 0.0f); // Translate the ship based on offsets

    /// Upper side
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0); // Red color
    glVertex2f(scale * 17, scale * 20);
    glVertex2f(scale * 17, scale * 22);
    glVertex2f(scale * 15, scale * 22);
    glVertex2f(scale * 15, scale * 24);
    glVertex2f(scale * 28, scale * 24);
    glVertex2f(scale * 28, scale * 22);
    glVertex2f(scale * 26, scale * 22);
    glVertex2f(scale * 26, scale * 20);
    glEnd();

    /// Lower side
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0); // Red color
    glVertex2f(scale * -0.5, scale * 8.25);
    glVertex2f(scale * 31.25, scale * 8.25);
    glVertex2f(scale * 31, scale * 6);
    glVertex2f(scale * 2, scale * 6);
    glEnd();

    /// Dark Blue Base
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 77); // Dark blue color
    glVertex2f(scale * -4, scale * 12);
    glVertex2f(scale * 6, scale * 12);
    glVertex2f(scale * 7, scale * 11);
    glVertex2f(scale * 31.25, scale * 11);
    glVertex2f(scale * 31.25, scale * 8.25);
    glVertex2f(scale * -0.5, scale *8.25);
    glEnd();

    /// Boxes
    glBegin(GL_POLYGON);
    glColor3ub(237, 248, 237);
    glVertex2f(scale * 3, scale * 12);
    glVertex2f(scale * 3, scale * 14.5);
    glVertex2f(scale * 3, scale * 17);
    glVertex2f(scale * 13, scale * 17);
    glVertex2f(scale * 13, scale * 20);
    glVertex2f(scale * 17, scale * 20);
    glVertex2f(scale * 29, scale * 20);
    glVertex2f(scale * 29, scale * 11);
    glVertex2f(scale * 7, scale * 11);
    glVertex2f(scale * 6, scale * 12);
    glEnd();

    /// Upper side of the ship
    glBegin(GL_POLYGON);
    glColor3ub(237, 248, 237);
    glVertex2f(scale * 3, scale * 12);
    glVertex2f(scale * 3, scale * 14.5);
    glVertex2f(scale * 3, scale * 17);
    glVertex2f(scale * 13, scale * 17);
    glVertex2f(scale * 13, scale * 20);
    glVertex2f(scale * 17, scale * 20);
    glVertex2f(scale * 29, scale * 20);
    glVertex2f(scale * 29, scale * 11);
    glVertex2f(scale * 7, scale * 11);
    glVertex2f(scale * 6, scale * 12);
    glEnd();

    /// Window side
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // White color
    glVertex2f(scale * 23, scale * 20);
    glVertex2f(scale * 29, scale * 20);
    glVertex2f(scale * 29, scale * 11);
    glVertex2f(scale * 25, scale * 11);
    glVertex2f(scale * 25, scale * 17);
    glVertex2f(scale * 23, scale * 17);
    glEnd();

    /// Line
    glLineWidth(1.0f); // Set the line width
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Black color for the line
    glVertex2f(scale * 27, scale * 20);
    glVertex2f(scale * 27, scale * 11);
    glEnd();
    glLineWidth(1.0f); // Reset the line width to default

    glLineWidth(1.0f); // Set the line width
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Black color for the line
    glVertex2f(scale * 3, scale * 14.5);
    glVertex2f(scale * 15, scale * 14.5);
    glEnd();
    glLineWidth(1.0f);
    /// Windows upper side-
    for (int i = 0; i < 10; i++) {
        float offsetX = i * 0.75 * scale; // Adjusted spacing for smaller size
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0); // Black color
        glVertex2f(scale * 17.75 + offsetX, scale * 21.5);
        glVertex2f(scale * 18.25 + offsetX, scale * 21.5);
        glVertex2f(scale * 18.25 + offsetX, scale * 21.0);
        glVertex2f(scale * 17.75 + offsetX, scale * 21.0);
        glEnd();
    }

    for (int i = 0; i < 7; i++) {
        float offsetY = i * -0.75 * scale; // Adjusted vertical spacing
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0); // Black color
        glVertex2f(scale * 27.75, scale * 19.5 + offsetY);
        glVertex2f(scale * 28.25, scale * 19.5 + offsetY);
        glVertex2f(scale * 28.25, scale * 19.0 + offsetY);
        glVertex2f(scale * 27.75, scale * 19.0 + offsetY);
        glEnd();
    }

    glPopMatrix();
}
void seconship(float offsetX, bool rotated){

    glPushMatrix();
    glTranslatef(offsetX, 0.0f, 0.0f); // Move the ship horizontally

    if (rotated) {
        glTranslatef(0.0f, 0.0f, 0.0f); // Keep ship centered
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f); // Rotate 180 degrees
    }


    glBegin(GL_POLYGON);

   glColor3ub(216,232,240);
    glVertex2f(-8,-29);
    //glColor3ub(204,228,240);
    glVertex2f(-4,-29);
    glVertex2f(-4,-33);
    glEnd();

    glBegin(GL_POLYGON);

    glBegin(GL_POLYGON);
    glColor3ub(216,232,240);
    glVertex2f(-4,-29);
    glColor3ub(25,10,227);

    glVertex2f(-3,-30);
    glVertex2f(-3,-33);
    glVertex2f(-4,-33);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(216,232,240);
    glVertex2f(-3,-30);
    glColor3ub(25,10,227);
    glVertex2f(14,-30);
    glVertex2f(14,-33);
    glVertex2f(-3,-33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(216,232,240);
    glVertex2f(14,-29);
    glColor3ub(25,10,227);
    glVertex2f(15,-29);
    glVertex2f(15,-33);
    glVertex2f(14,-33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-3,-25);
    glVertex2f(3,-25);
    glVertex2f(3,-30);
    glVertex2f(-3,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(3,-26);
    //glColor3ub(204,228,240);
    glVertex2f(11,-26);
    glVertex2f(11,-30);
    glVertex2f(3,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(11,-25);
    //glColor3ub(204,228,240);
    glVertex2f(14,-25);
    glVertex2f(14,-30);
    glVertex2f(11,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(9,-24);
    //glColor3ub(204,228,240);
    glVertex2f(14,-24);
    glVertex2f(14,-25);
    glVertex2f(9,-25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(8,-23);
    //glColor3ub(204,228,240);
    glVertex2f(15,-23);
    glVertex2f(15,-24);
    glVertex2f(8,-24);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(10,-22);
    //glColor3ub(204,228,240);
    glVertex2f(13,-22);
    glVertex2f(13,-23);
    glVertex2f(10,-23);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(11,-21);
    //glColor3ub(204,228,240);
    glVertex2f(12,-21);
    glVertex2f(12,-22);
    glVertex2f(11,-22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-5,-26);
    //glColor3ub(204,228,240);
    glVertex2f(-3,-26);
    glVertex2f(-3,-30);
    glVertex2f(-4,-29);
    glVertex2f(-5,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(216,200,240);
    glVertex2f(-1,-24);
    //glColor3ub(204,228,240);
    glVertex2f(1,-24);
    glVertex2f(1,-25);
    glVertex2f(-1,-25);
    glEnd();

    ///boxes

    glBegin(GL_POLYGON);
    glColor3ub(180,0,0);
    glVertex2f(-5,-26);
    glColor3ub(177,0,0);
    glVertex2f(-4,-26);
    glColor3ub(160,0,0);
    glVertex2f(-4,-27);
    glColor3ub(162,0,0);
    glVertex2f(-5,-27);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 69, 0);
    glVertex2f(-5,-27);
    glColor3ub(255, 65, 0);
    glVertex2f(-4,-27);
    glColor3ub(255, 63, 0);
    glVertex2f(-4,-28);
    glColor3ub(255, 60, 0);
    glVertex2f(-5,-28);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 140, 0);
    glVertex2f(-5,-28);
    glVertex2f(-4,-28);
    glVertex2f(-4,-29);
    glVertex2f(-5,-29);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 215, 200);
    glVertex2f(-5,-29);
    glColor3ub(255, 215, 100);
    glVertex2f(-4,-29);
    glColor3ub(255, 215,150);
    glVertex2f(-4,-30);
    glColor3ub(255, 215, 120);
    glVertex2f(-5,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(31, 139, 34);
    glVertex2f(-4,-26);
    glColor3ub(32, 139, 34);
    glVertex2f(-3,-26);
    glColor3ub(34, 139, 34);
    glVertex2f(-3,-27);
    glColor3ub(33, 139, 34);
    glVertex2f(-4,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(46, 139, 87);
    glVertex2f(-4,-27);
    glVertex2f(-3,-27);
    glVertex2f(-3,-28);
    glVertex2f(-4,-28);
    glEnd();
    glBegin(GL_POLYGON);
     glColor3ub(60, 179, 113);
    glVertex2f(-4,-28);
    glVertex2f(-3,-28);
    glVertex2f(-3,-29);
    glVertex2f(-4,-29);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-4,-29);
    glVertex2f(-3,-29);
    glVertex2f(-3,-30);
    glVertex2f(-4,-30);
    glEnd();

    glBegin(GL_POLYGON);
   glColor3ub(30, 144, 255);
    glVertex2f(-3,-26);
    glVertex2f(-2,-26);
    glVertex2f(-2,-27);
    glVertex2f(-3,-27);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(200,200,230);
    glVertex2f(-3,-27);
    glVertex2f(-2,-27);
    glVertex2f(-2,-28);
    glVertex2f(-3,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 102);
    glVertex2f(-3,-28);
    glVertex2f(-2,-28);
    glVertex2f(-2,-29);
    glVertex2f(-3,-29);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(120,100,230);
    glVertex2f(-3,-29);
    glVertex2f(-2,-29);
    glVertex2f(-2,-30);
    glVertex2f(-3,-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(100,200,230);
    glVertex2f(-2,-26);
    glVertex2f(-1,-26);
    glVertex2f(-1,-27);
    glVertex2f(-2,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 153);
    glVertex2f(-2,-27);
    glVertex2f(-1,-27);
    glVertex2f(-1,-28);
    glVertex2f(-2,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 0);
    glVertex2f(-2,-28);
    glVertex2f(-1,-28);
    glVertex2f(-1,-29);
    glVertex2f(-2,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 153);
    glVertex2f(-2,-29);
    glVertex2f(-1,-29);
    glVertex2f(-1,-30);
    glVertex2f(-2,-30);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255, 255, 102);
    glVertex2f(-1,-26);
    glVertex2f(3,-26);
    glVertex2f(3,-27);
    glVertex2f(-1,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2f(-1,-27);
    glVertex2f(3,-27);
    glVertex2f(3,-28);
    glVertex2f(-1,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-1,-28);
    glVertex2f(3,-28);
    glVertex2f(3,-29);
    glVertex2f(-1,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex2f(-1,-29);
    glVertex2f(3,-29);
    glVertex2f(3,-30);
    glVertex2f(-1,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(101,101,101);
    glVertex2f(-3,-25);
    glVertex2f(-1,-25);
    glVertex2f(-1,-26);
    glVertex2f(-3,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(191,191,191);
    glVertex2f(-1,-25);
    glVertex2f(0,-25);
    glVertex2f(0,-26);
    glVertex2f(-1,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100,100,100);
    glVertex2f(0,-25);
    glVertex2f(2,-25);
    glVertex2f(2,-26);
    glVertex2f(0,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 255, 102);
    glVertex2f(2,-25);
    glVertex2f(3,-25);
    glVertex2f(3,-26);
    glVertex2f(2,-26);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(000,101,101);
    glVertex2f(-1,-24);
    glVertex2f(1,-24);
    glVertex2f(1,-25);
    glVertex2f(-1,-25);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255, 153, 51);
    glVertex2f(3,-26);
    glVertex2f(5,-26);
    glVertex2f(5,-27);
    glVertex2f(3,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 255, 102);
    glVertex2f(3,-27);
    glVertex2f(5,-27);
    glVertex2f(5,-28);
    glVertex2f(3,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 153, 153);
    glVertex2f(3,-28);
    glVertex2f(7,-28);
    glVertex2f(7,-29);
    glVertex2f(3,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex2f(3,-29);
    glVertex2f(7,-29);
    glVertex2f(7,-30);
    glVertex2f(3,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70, 130,0);
    glVertex2f(5,-26);
    glColor3ub(70, 130, 18);
    glVertex2f(6,-26);
    glColor3ub(70, 130, 15);
    glVertex2f(6,-27);
    glColor3ub(70, 130,0);
    glVertex2f(5,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51, 51, 204);
    glVertex2f(5,-27);
    glVertex2f(6,-27);
    glVertex2f(6,-28);
    glVertex2f(5,-28);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(6,-26);
    glVertex2f(7,-26);
    glVertex2f(7,-27);
    glVertex2f(6,-27);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 255);
    glVertex2f(6,-27);
    glVertex2f(7,-27);
    glVertex2f(7,-28);
    glVertex2f(6,-28);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255, 102, 0);
    glVertex2f(7,-26);
    glVertex2f(12,-26);
    glVertex2f(12,-27);
    glVertex2f(7,-27);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(7,-27);
    glVertex2f(12,-27);
    glVertex2f(12,-28);
    glVertex2f(7,-28);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex2f(7,-28);
    glVertex2f(12,-28);
    glVertex2f(12,-29);
    glVertex2f(7,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(7,-29);
    glVertex2f(12,-29);
    glVertex2f(12,-30);
    glVertex2f(7,-30);
    glEnd();

    /// Line
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(9,-25);
    glVertex2f(14,-25);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(12,-25);
    glVertex2f(12,-30);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(13,-25);
    glVertex2f(13,-30);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(14,-24);
    glVertex2f(14,-30);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(8,-24);
    glVertex2f(15,-24);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(10,-23);
    glVertex2f(13,-23);
    glEnd();
    glLineWidth(1.0f);

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(11,-22);
    glVertex2f(12,-22);
    glEnd();
    glLineWidth(1.0f);





    glPopMatrix();

}
void stopAndRestart() {
    isWaiting = true; // Indicate waiting state
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Wait for 30 seconds

    shipMovingLeft = !shipMovingLeft; // Reverse direction
    shipRotated = !shipRotated; // Flip ship rotation
    isWaiting = false; // Reset waiting state
}

void update(int value) {
    if (!isWaiting) {
        if (shipMovingLeft) {
            ship2X -= 0.1f; // Move left
            if (ship2X <= 0.0f) { // Stop at left side
                ship2X = 0.0f;
                std::thread(stopAndRestart).detach(); // Start wait time in a separate thread
            }
        } else {
            ship2X += 0.1f; // Move right
            if (ship2X >= 50.0f) { // Stop at right side
                ship2X = 50.0f;
                std::thread(stopAndRestart).detach(); // Start wait time
            }
        }
    }

    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(16, update, 0); // Call update every 16ms (~60 FPS)
}
///Trucks and some boxes
void Trucks(){
    ///1st truck
    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 51);
    glVertex2f(-46,-18);
    glVertex2f(-36,-18);
    glVertex2f(-36,-21);
    glVertex2f(-46,-21);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-36,-18);
    //glColor3ub(204,228,240);
    glVertex2f(-35,-19);
    glVertex2f(-35,-21);
    glVertex2f(-36,-21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-35,-19);
    //glColor3ub(204,228,240);
    glVertex2f(-34,-19);
    glVertex2f(-34,-21);
    glVertex2f(-35,-21);
    glEnd();

    ///2nd truck

    glBegin(GL_POLYGON);
    glColor3ub(102, 153, 153);
    glVertex2f(-32,-32);
    glVertex2f(-23,-32);
    glVertex2f(-23,-35);
    glVertex2f(-32,-35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2f(-23,-32);
    //glColor3ub(204,228,240);
    glVertex2f(-22,-32);
    glVertex2f(-22,-35);
    glVertex2f(-23,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2f(-22,-32);
    //glColor3ub(204,228,240);
    glVertex2f(-21,-33);
    glVertex2f(-21,-35);
    glVertex2f(-22,-35);
    glEnd();

}
///Boxes on the portside
void drawStackedBoxes(float startX, float startY,float spacing) {
    for (int i = 0; i <5; i++) {
        float offsetY = i * spacing; // Move each box downward
        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0); // Light purple color
        glVertex2f(startX, startY + offsetY);
        glColor3ub(216, 220, 240);
        glVertex2f(startX + 5, startY + offsetY);
        glColor3ub(0, 51, 0);
        glVertex2f(startX + 5, startY + offsetY + 1);
        glColor3ub(204, 255, 255);
        glVertex2f(startX, startY + offsetY + 1);
        glEnd();
    }
}
/// Function to draw the sunray
void drawSun(float cx, float cy, float r) {
    glColor3ub(255, 165, 0);
    drawCircle(cx, cy, r);

    /// Draw the sun's rays
    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) { ///12 rays
        float angle = 2.0f * M_PI * i / 12;
        float x1 = cx + cos(angle) * r;       ///Start of ray (edge of sun)
        float y1 = cy + sin(angle) * r;
        float x2 = cx + cos(angle) * (r + 0.5); ///End of ray (outside sun)
        float y2 = cy + sin(angle) * (r + 0.5);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}
/// Function to draw the ground (Day/Night)
void drawGround() {
    glBegin(GL_POLYGON);
    if (isNight) {
        glColor3ub(80, 70, 60); // Dark brownish-gray for night
    } else {
        glColor3ub(241, 231, 215); // Light sand color for day
    }
    glVertex2f(-50, 1);
    glVertex2f(-35, -5);
    glVertex2f(-30, -12);
    glVertex2f(-20, -19);
    glVertex2f(-6, -40);
    glVertex2f(-50, -40);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    ///watercolor function
    drawGradientWater();
    ///Second ship function
    seconship(ship2X, shipRotated);
    ///Ground color
    drawGround();
    ///boxes function
    drawStackedBoxes(-45, -6,0.8);

     glBegin(GL_POLYGON);
    glColor3ub(102, 0, 51);
    glVertex2f(-49,-23);
    glVertex2f(-46,-23);
    glVertex2f(-46,-24);
    glVertex2f(-49,-24);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(-49,-24);
    glVertex2f(-46,-24);
    glVertex2f(-46,-25);
    glVertex2f(-49,-25);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(-49,-25);
    glVertex2f(-45,-25);
    glVertex2f(-45,-26);
    glVertex2f(-49,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100,101,205);
    glVertex2f(-49,-26);
    glVertex2f(-45,-26);
    glVertex2f(-45,-27);
    glVertex2f(-49,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 0);
    glVertex2f(-49,-28);
    glVertex2f(-44,-28);
    glVertex2f(-44,-29);
    glVertex2f(-49,-29);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(51, 102, 255);
    glVertex2f(-46,-24);
    glVertex2f(-44,-24);
    glVertex2f(-44,-25);
    glVertex2f(-46,-25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241,201,100);
    glVertex2f(-45,-25);
    glVertex2f(-43,-25);
    glVertex2f(-43,-26);
    glVertex2f(-45,-26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-45,-26);
    glVertex2f(-42,-26);
    glVertex2f(-42,-27);
    glVertex2f(-45,-27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(200,201,205);
    glVertex2f(-45,-27);
    glVertex2f(-42,-27);
    glVertex2f(-42,-28);
    glVertex2f(-45,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-44,-28);
    glVertex2f(-41,-28);
    glVertex2f(-41,-29);
    glVertex2f(-44,-29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(200,201,205);
    glVertex2f(-41,-35);
    glVertex2f(-38,-35);
    glVertex2f(-38,-36);
    glVertex2f(-41,-36);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(200,201,205);
    glVertex2f(-41,-36);
    glVertex2f(-38,-36);
    glVertex2f(-38,-37);
    glVertex2f(-41,-37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(200,201,305);
    glVertex2f(-41,-37);
    glVertex2f(-38,-37);
    glVertex2f(-38,-38);
    glVertex2f(-41,-38);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(200,301,205);
    glVertex2f(-41,-38);
    glVertex2f(-37,-38);
    glVertex2f(-37,-39);
    glVertex2f(-41,-39);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-41,-39);
    glVertex2f(-37,-39);
    glVertex2f(-37,-40);
    glVertex2f(-41,-40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-37,-38);
    glVertex2f(-33,-38);
    glVertex2f(-33,-39);
    glVertex2f(-37,-39);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(211,201,205);
    glVertex2f(-37,-39);
    glVertex2f(-33,-39);
    glVertex2f(-33,-40);
    glVertex2f(-37,-40);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(102, 0, 51);
    glVertex2f(-38,-35);
    glVertex2f(-36,-35);
    glVertex2f(-36,-36);
    glVertex2f(-38,-36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-38,-36);
    glVertex2f(-35,-36);
    glVertex2f(-35,-37);
    glVertex2f(-38,-37);
    glEnd();
        glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(-38,-37);
    glVertex2f(-34,-37);
    glVertex2f(-34,-38);
    glVertex2f(-38,-38);
    glEnd();

      glBegin(GL_POLYGON);
    glColor3ub(100,200,300);
    glVertex2f(-35,-28);
    glVertex2f(-29,-28);
    glVertex2f(-29,-31);
    glVertex2f(-35,-31);
    glEnd();
      glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(-31,-25);
    glVertex2f(-25,-25);
    glVertex2f(-25,-28);
    glVertex2f(-31,-28);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(200,200,205);
    glVertex2f(-18,-37);
    glVertex2f(-13,-37);
    glVertex2f(-13,-40);
    glVertex2f(-18,-40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100,100,205);
    glVertex2f(-13,-37);
    glVertex2f(-8,-37);
    glVertex2f(-8,-40);
    glVertex2f(-13,-40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(300,300,305);
    glVertex2f(-14,-34);
    glVertex2f(-9,-34);
    glVertex2f(-9,-37);
    glVertex2f(-14,-37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(-35,-9);
    glVertex2f(-30,-9);
    glVertex2f(-30,-11);
    glVertex2f(-35,-11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 0, 51);
    glVertex2f(-35,-11);
    glVertex2f(-29,-11);
    glVertex2f(-29,-13);
    glVertex2f(-35,-13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51, 102, 255);
    glVertex2f(-38,-12);
    glVertex2f(-32,-12);
    glVertex2f(-32,-14);
    glVertex2f(-38,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 0);
    glVertex2f(-50,1);
    glVertex2f(-48,1);
    glVertex2f(-48,-0);
    glVertex2f(-50,-0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-50,-0);
    glVertex2f(-47,-0);
    glVertex2f(-47,-1);
    glVertex2f(-50,-1);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(51, 102, 255);
    glVertex2f(-50,-1);
    glVertex2f(-45,-1);
    glVertex2f(-45,-2);
    glVertex2f(-50,-2);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(-50,-2);
    glVertex2f(-45,-2);
    glVertex2f(-45,-3);
    glVertex2f(-50,-3);
    glEnd();




    /// Mail Draw Ships
    drawShip(0.0, 0.0);
    drawSky();
    if (isNight) {
        drawStars(); // Draw stars at night
    } else {
        drawSmallClouds(); // Draw clouds in day mode
    }
    /// Sun and moon
    if (isNight) {
        drawMoon(40.0f, 35.0f, 3.0f); // Draw moon at night
    } else {
        drawSun(40.0f, 35.0f, 3.0f); // Draw sun during the day
    }

    ///Truck
    Trucks();
    mainCircle(-24,-35,0.8);
    mainCircle(-30,-35,0.8);
    mainCircle(-35.5,-21,0.8);
    mainCircle(-40,-21,0.8);
    mainCircle(-44,-21,0.8);

    glFlush();
}
/// Function to move the ship with arrow keys
void handleSpecialKeypress(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            shipX -= shipSpeed; // Move left
            break;
        case GLUT_KEY_RIGHT:
            shipX += shipSpeed; // Move right
            break;
        case GLUT_KEY_UP:
            shipY += shipSpeed; // Move up
            break;
        case GLUT_KEY_DOWN:
            shipY -= shipSpeed; // Move down
            break;
    }
    glutPostRedisplay(); // Refresh the display after movement
}
///Mail Function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Port");
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyPress);
    glutSpecialFunc(handleSpecialKeypress); // Listen for arrow key input
    initGL();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutTimerFunc(16, update, 0); ///update function for 2nd ship
    glutTimerFunc(16, updateClouds, 0); ///update function for clude


    gluOrtho2D(-50.0, 50.0, -40.0, 40.0); // Adjusted Y range to match display
    glutMainLoop();
    return 0;
}
