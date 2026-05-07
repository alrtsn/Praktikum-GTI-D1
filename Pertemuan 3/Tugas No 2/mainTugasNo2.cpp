// Nama/NIM  : Amelia Aristianti/24060124120008
// Deskripsi : menambahkan jari dan telapak tangan

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

// Sudut untuk sendi lengan
static int shoulder = 0;      // Rotasi bahu (sumbu Z)
static int shoulderY = 0;     // Rotasi bahu (sumbu Y)
static int elbow = 0;         // Rotasi siku

// Sudut untuk jari
// jari: 0=jempol, 1=telunjuk, 2=tengah, 3=manis, 4=kelingking
// ruas: 0=ruas dekat telapak, 1=ruas ujung
static float fingerAngles[5][2] = {0};

// Fungsi inisialisasi
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

// Fungsi menggambar balok dengan ukuran tertentu (x,y,z)
void drawBox(float sx, float sy, float sz) {
    glPushMatrix();
    glScalef(sx, sy, sz);
    glutWireCube(1.0);
    glPopMatrix();
}

// Fungsi menggambar satu jari dengan 2 ruas
// idx: indeks jari
// tx, ty, tz: posisi pangkal jari relatif terhadap telapak
// spread: sudut penyebaran jari (untuk jempol agak ke samping)
void drawFinger(int idx, float tx, float ty, float tz, float spread) {
    float len = 0.4;    // panjang per ruas
    float thick = 0.15; // ketebalan jari
    
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glRotatef(spread, 0.0, 1.0, 0.0);
    
    // Ruas 1 (dekat telapak)
    glRotatef(fingerAngles[idx][0], 0.0, 0.0, 1.0);
    glTranslatef(len/2.0, 0.0, 0.0);
    drawBox(len, thick, thick);
    
    // Ruas 2 (ujung)
    glTranslatef(len/2.0, 0.0, 0.0);
    glRotatef(fingerAngles[idx][1], 0.0, 0.0, 1.0);
    glTranslatef(len/2.0, 0.0, 0.0);
    drawBox(len, thick, thick);
    
    glPopMatrix();
}

// Fungsi display utama
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    
    // ========== LENGAN ATAS ==========
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);  // rotasi di sumbu Z
    glRotatef((GLfloat)shoulderY, 0.0, 1.0, 0.0); // rotasi di sumbu Y
    glTranslatef(1.0, 0.0, 0.0);
    
    glPushMatrix();
        glScalef(2.0, 0.4, 0.8);
        glutWireCube(1.0);
    glPopMatrix();
    
    // ========== LENGAN BAWAH ==========
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    glPushMatrix();
        glScalef(1.8, 0.35, 0.7);
        glutWireCube(1.0);
    glPopMatrix();
    
    // ========== TELAPAK TANGAN ==========
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.8, 0.4, 0.9);
        glutWireCube(1.0);
    glPopMatrix();
    
    // ========== JARI-JARI ==========
    // Jempol (agak ke samping dan bawah)
    drawFinger(0, 0.3, 0.15, 0.45, -30.0);
    
    // Telunjuk
    drawFinger(1, 0.45, 0.18, 0.25, 0.0);
    
    // Jari tengah (paling panjang)
    glPushMatrix();
        glTranslatef(0.5, 0.18, 0.0);
        glRotatef(fingerAngles[2][0], 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0);
        drawBox(0.45, 0.15, 0.15);
        
        glTranslatef(0.25, 0.0, 0.0);
        glRotatef(fingerAngles[2][1], 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0);
        drawBox(0.45, 0.15, 0.15);
    glPopMatrix();
    
    // Jari manis
    drawFinger(3, 0.45, 0.15, -0.25, 0.0);
    
    // Kelingking (paling pendek)
    drawFinger(4, 0.4, 0.12, -0.45, 0.0);
    
    glPopMatrix();
    
    glutSwapBuffers();
}

// Fungsi reshape (mengatur proyeksi)
void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
}

// Fungsi keyboard untuk menggerakkan semua sendi
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Lengan atas (bahu)
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'z': shoulderY = (shoulderY + 5) % 360; break;
        case 'Z': shoulderY = (shoulderY - 5) % 360; break;
        
        // Lengan bawah (siku)
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        
        // Jempol (menekuk/meluruskan)
        case '1': if(fingerAngles[0][0] < 120) fingerAngles[0][0] += 10;
                  if(fingerAngles[0][1] < 120) fingerAngles[0][1] += 10; break;
        case '!': if(fingerAngles[0][0] > 0) fingerAngles[0][0] -= 10;
                  if(fingerAngles[0][1] > 0) fingerAngles[0][1] -= 10; break;
        
        // Telunjuk
        case '2': if(fingerAngles[1][0] < 120) fingerAngles[1][0] += 10;
                  if(fingerAngles[1][1] < 120) fingerAngles[1][1] += 10; break;
        case '@': if(fingerAngles[1][0] > 0) fingerAngles[1][0] -= 10;
                  if(fingerAngles[1][1] > 0) fingerAngles[1][1] -= 10; break;
        
        // Jari tengah
        case '3': if(fingerAngles[2][0] < 120) fingerAngles[2][0] += 10;
                  if(fingerAngles[2][1] < 120) fingerAngles[2][1] += 10; break;
        case '#': if(fingerAngles[2][0] > 0) fingerAngles[2][0] -= 10;
                  if(fingerAngles[2][1] > 0) fingerAngles[2][1] -= 10; break;
        
        // Jari manis
        case '4': if(fingerAngles[3][0] < 120) fingerAngles[3][0] += 10;
                  if(fingerAngles[3][1] < 120) fingerAngles[3][1] += 10; break;
        case '$': if(fingerAngles[3][0] > 0) fingerAngles[3][0] -= 10;
                  if(fingerAngles[3][1] > 0) fingerAngles[3][1] -= 10; break;
        
        // Kelingking
        case '5': if(fingerAngles[4][0] < 120) fingerAngles[4][0] += 10;
                  if(fingerAngles[4][1] < 120) fingerAngles[4][1] += 10; break;
        case '%': if(fingerAngles[4][0] > 0) fingerAngles[4][0] -= 10;
                  if(fingerAngles[4][1] > 0) fingerAngles[4][1] -= 10; break;
        
        // Reset semua jari ke posisi lurus
        case 'r':
        case 'R':
            for(int i = 0; i < 5; i++)
                for(int j = 0; j < 2; j++)
                    fingerAngles[i][j] = 0;
            break;
        
        // Keluar program
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

// Program utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan + Telapak Tangan + Jari");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}
