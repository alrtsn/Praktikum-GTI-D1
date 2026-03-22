// Nama/NIM  : Amelia Aristianti/24060124120008
// Deskripsi : Tugas nomor 2 membuat mobil dengan tambahan ornamen

#include <windows.h>
#include <gl/glut.h>
#include <math.h>

#define PI 3.1415926535898

float wheel_angle = 0.0f;
void drawCircle(float cx, float cy, float radius, int segments) {
    int i;
    float angle;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (i = 0; i <= segments; i++) {
            angle = 2 * PI * i / segments;
            glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
        }
    glEnd();
}

// Membuat roda
void drawWheel(float x, float y, float angle_rot) {
    int i;
    float angle;
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
        glColor3f(0.1f, 0.1f, 0.1f);
        drawCircle(0.0f, 0.0f, 0.12f, 40);
        glColor3f(0.6f, 0.6f, 0.6f);
        drawCircle(0.0f, 0.0f, 0.08f, 40);
        
        glPushMatrix();
        glRotatef(angle_rot, 0.0f, 0.0f, 1.0f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glLineWidth(2.5f);
        glBegin(GL_LINES);
            glVertex2f(-0.07f, 0.0f);  glVertex2f(0.07f, 0.0f);
            glVertex2f(0.0f, -0.07f);  glVertex2f(0.0f, 0.07f);
            glVertex2f(-0.05f, -0.05f); glVertex2f(0.05f, 0.05f);
            glVertex2f(-0.05f, 0.05f);  glVertex2f(0.05f, -0.05f);
        glEnd();
        glPopMatrix();
        
        glColor3f(0.9f, 0.7f, 0.1f);
        drawCircle(0.0f, 0.0f, 0.035f, 30);
        
    glPopMatrix();
}

// Membuat mobil
void drawCar(float x, float y, float wheelRot) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
        glColor3f(0.85f, 0.2f, 0.2f);
        glBegin(GL_QUADS);
            glVertex2f(-0.45f, -0.25f);
            glVertex2f( 0.45f, -0.25f);
            glVertex2f( 0.45f, -0.05f);
            glVertex2f(-0.45f, -0.05f);
        glEnd();
        glColor3f(0.65f, 0.12f, 0.12f);
        glBegin(GL_QUADS);
            glVertex2f(-0.28f, -0.05f);
            glVertex2f( 0.28f, -0.05f);
            glVertex2f( 0.24f,  0.12f);
            glVertex2f(-0.24f,  0.12f);
        glEnd();
        glColor3f(0.55f, 0.75f, 0.85f);
        glBegin(GL_QUADS);
            glVertex2f(0.05f, -0.04f);
            glVertex2f(0.26f, -0.04f);
            glVertex2f(0.23f,  0.10f);
            glVertex2f(0.05f,  0.10f);
        glEnd();
        glBegin(GL_QUADS);
            glVertex2f(-0.26f, -0.04f);
            glVertex2f(-0.05f, -0.04f);
            glVertex2f(-0.05f,  0.10f);
            glVertex2f(-0.23f,  0.10f);
        glEnd();
        glColor3f(1.0f, 0.85f, 0.3f);
        drawCircle(0.42f, -0.18f, 0.045f, 25);
        drawCircle(0.42f, -0.08f, 0.045f, 25);
        glColor3f(1.0f, 0.25f, 0.15f);
        drawCircle(-0.42f, -0.18f, 0.045f, 25);
        drawCircle(-0.42f, -0.08f, 0.045f, 25);
        glColor3f(0.1f, 0.1f, 0.1f);
        glLineWidth(2.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.15f, -0.18f);
            glVertex2f( 0.15f, -0.18f);
            glVertex2f(-0.15f, -0.12f);
            glVertex2f( 0.15f, -0.12f);
        glEnd();
        
        drawWheel(-0.32f, -0.32f, wheelRot);
        drawWheel( 0.32f, -0.32f, wheelRot);
        
    glPopMatrix();
}

// Membuat matahariw
void drawSun() {
    int i;
    float angle;
    glPushMatrix();
    glTranslatef(0.75f, 0.75f, 0.0f);
        glColor3f(1.0f, 0.85f, 0.3f);
        drawCircle(0.0f, 0.0f, 0.12f, 40);
        glColor3f(1.0f, 0.75f, 0.25f);
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        for (i = 0; i < 360; i += 30) {
            angle = i * PI / 180.0;
            glVertex2f(cos(angle) * 0.16f, sin(angle) * 0.16f);
            glVertex2f(cos(angle) * 0.24f, sin(angle) * 0.24f);
        }
        glEnd();
        
    glPopMatrix();
}

// Membuat awan
void drawCloud(float x, float y) {
    glColor3f(1.0f, 0.95f, 0.85f);
    drawCircle(x, y, 0.10f, 30);
    drawCircle(x + 0.09f, y - 0.03f, 0.11f, 30);
    drawCircle(x - 0.09f, y - 0.03f, 0.11f, 30);
    drawCircle(x + 0.03f, y + 0.06f, 0.09f, 30);
    drawCircle(x - 0.03f, y + 0.06f, 0.09f, 30);
}

// Membuat pohon pohon
void drawTree(float x, float y_base) {
    glColor3f(0.55f, 0.35f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(x - 0.055f, y_base);
        glVertex2f(x + 0.055f, y_base);
        glVertex2f(x + 0.055f, y_base + 0.38f);
        glVertex2f(x - 0.055f, y_base + 0.38f);
    glEnd();
    
    glColor3f(0.20f, 0.70f, 0.25f);
    drawCircle(x, y_base + 0.38f, 0.13f, 25);
    drawCircle(x - 0.10f, y_base + 0.28f, 0.12f, 25);
    drawCircle(x + 0.10f, y_base + 0.28f, 0.12f, 25);

    glColor3f(0.22f, 0.68f, 0.24f);
    drawCircle(x, y_base + 0.48f, 0.12f, 25);
    drawCircle(x - 0.08f, y_base + 0.42f, 0.10f, 25);
    drawCircle(x + 0.08f, y_base + 0.42f, 0.10f, 25);

    glColor3f(0.25f, 0.72f, 0.27f);
    drawCircle(x, y_base + 0.57f, 0.11f, 25);
    drawCircle(x - 0.05f, y_base + 0.54f, 0.08f, 25);
    drawCircle(x + 0.05f, y_base + 0.54f, 0.08f, 25);

    glColor3f(0.28f, 0.75f, 0.30f);
    drawCircle(x, y_base + 0.65f, 0.09f, 25);
}

// Membuat background pemandangannya
void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Background sunset
    glBegin(GL_QUADS);
        glColor3f(0.88f, 0.48f, 0.28f);
        glVertex2f(-1.0f,  1.0f);
        glVertex2f( 1.0f,  1.0f);
        glColor3f(1.0f, 0.72f, 0.38f);
        glVertex2f( 1.0f, -0.35f);
        glVertex2f(-1.0f, -0.35f);
    glEnd();
    
    // Jalan
    glColor3f(0.22f, 0.22f, 0.25f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.35f);
        glVertex2f( 1.0f, -0.35f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();
    
    // Garis jalan (putus-putus)
    glColor3f(0.95f, 0.85f, 0.55f);
    glLineWidth(3.0f);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(3, 0xAAAA);
    glBegin(GL_LINES);
        glVertex2f(-0.95f, -0.68f);
        glVertex2f( 0.95f, -0.68f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    
    // Garis pinggir jalan
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-1.0f, -0.35f);
        glVertex2f( 1.0f, -0.35f);
        glVertex2f(-1.0f, -0.95f);
        glVertex2f( 1.0f, -0.95f);
    glEnd();

    drawSun();                  
    drawCloud(-0.30f, 0.65f); 
    drawCloud(0.55f, 0.70f); 
    drawTree(-0.85f, -0.35f); 
    drawTree(0.85f, -0.35f); 
    drawTree(0.65f, -0.35f);    
    drawCar(0.0f, 0.05f, wheel_angle);
    
    glFlush();
}

// animasi roda
void timer(int value) {
    wheel_angle += 8.0f;
    if (wheel_angle > 360.0f) wheel_angle -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(40, timer, 0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Mudik dulu BOSHT");
    glutDisplayFunc(RenderScene);
    glutTimerFunc(0, timer, 0);
    glClearColor(0.95f, 0.55f, 0.20f, 1.0f);
    glutMainLoop();
    return 0;
}

