// Nama/NIM  : Amelia Aristianti/24060124120008
// Deskripsi : Membuat mobil 3D menggunakan Depth dan Lighting OpenGL

#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>

// ================= CAMERA =================
float angle = 0.0f;
float deltaAngle = 0.0f;
float x = 0.0f, y = 2.0f, z = 18.0f; 
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0;

int h, w;
float ratio;

// ================= LIGHTING =================
const GLfloat light_ambient[]  = {0.4f, 0.4f, 0.4f, 1.0f};
const GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {0.0f, 12.0f, 8.0f, 1.0f};

const GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {80.0f};

// ================= RESHAPE =================
void Reshape(int w1, int h1)
{
    if(h1 == 0) h1 = 1;

    w = w1;
    h = h1;

    ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0,0,w,h);
    gluPerspective(45, ratio, 0.1, 1000);

    glMatrixMode(GL_MODELVIEW);
}

void orientMe(float ang)
{
    lx = sin(ang);
    lz = -cos(ang);

    glLoadIdentity();

    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f
    );
}

void moveMeFlat(int i)
{
    x = x + i * (lx) * 0.12f;
    z = z + i * (lz) * 0.12f;

    glLoadIdentity();

    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f
    );
}

// ================= GRID =================
void Grid()
{
    double i;
    const float Z_MIN = -50;
    const float Z_MAX = 50;
    const float X_MIN = -50;
    const float X_MAX = 50;
    const float gap = 2.0;

    glColor3f(0.8, 0.8, 0.8);

    glBegin(GL_LINES);

    for(i = Z_MIN; i <= Z_MAX; i += gap)
    {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }

    for(i = X_MIN; i <= X_MAX; i += gap)
    {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }

    glEnd();
}

// ================= ROAD =================
void Road()
{
    glDisable(GL_LIGHTING);

    glColor3f(0.2f, 0.2f, 0.2f);

    glBegin(GL_QUADS);

    glVertex3f(-4, 0.01, -50);
    glVertex3f( 4, 0.01, -50);
    glVertex3f( 4, 0.01,  50);
    glVertex3f(-4, 0.01,  50);

    glEnd();

    // garis jalan
    glColor3f(1.0f, 1.0f, 1.0f);

    for(int i=-50; i<50; i+=5)
    {
        glBegin(GL_QUADS);

        glVertex3f(-0.2, 0.02, i);
        glVertex3f( 0.2, 0.02, i);
        glVertex3f( 0.2, 0.02, i+2);
        glVertex3f(-0.2, 0.02, i+2);

        glEnd();
    }

    glEnable(GL_LIGHTING);
}

// ================= MOBIL =================
void BodyMobil()
{
    // bawah mobil
    glColor3f(1.0f, 0.72f, 0.82f);

    glBegin(GL_QUADS);

    // depan
    glNormal3f(0,0,1);
    glVertex3f(-2.8,0.5,1.2);
    glVertex3f( 2.8,0.5,1.2);
    glVertex3f( 2.8,1.7,1.2);
    glVertex3f(-2.8,1.7,1.2);

    // belakang
    glNormal3f(0,0,-1);
    glVertex3f(-2.8,0.5,-1.2);
    glVertex3f(-2.8,1.7,-1.2);
    glVertex3f( 2.8,1.7,-1.2);
    glVertex3f( 2.8,0.5,-1.2);

    // atas
    glNormal3f(0,1,0);
    glVertex3f(-2.8,1.7,-1.2);
    glVertex3f(-2.8,1.7, 1.2);
    glVertex3f( 2.8,1.7, 1.2);
    glVertex3f( 2.8,1.7,-1.2);

    // bawah
    glNormal3f(0,-1,0);
    glVertex3f(-2.8,0.5,-1.2);
    glVertex3f( 2.8,0.5,-1.2);
    glVertex3f( 2.8,0.5, 1.2);
    glVertex3f(-2.8,0.5, 1.2);

    // kanan
    glNormal3f(1,0,0);
    glVertex3f(2.8,0.5,-1.2);
    glVertex3f(2.8,1.7,-1.2);
    glVertex3f(2.8,1.7, 1.2);
    glVertex3f(2.8,0.5, 1.2);

    // kiri
    glNormal3f(-1,0,0);
    glVertex3f(-2.8,0.5,-1.2);
    glVertex3f(-2.8,0.5, 1.2);
    glVertex3f(-2.8,1.7, 1.2);
    glVertex3f(-2.8,1.7,-1.2);

    glEnd();
}

void TopMobil()
{
    glColor3f(0.92f, 0.55f, 0.72f);

    glBegin(GL_QUADS);

    // depan
    glNormal3f(0,0,1);
    glVertex3f(-1.6,1.7,1.0);
    glVertex3f( 1.5,1.7,1.0);
    glVertex3f( 1.0,3.0,1.0);
    glVertex3f(-1.1,3.0,1.0);

    // belakang
    glNormal3f(0,0,-1);
    glVertex3f(-1.6,1.7,-1.0);
    glVertex3f(-1.1,3.0,-1.0);
    glVertex3f( 1.0,3.0,-1.0);
    glVertex3f( 1.5,1.7,-1.0);

    // atas
    glNormal3f(0,1,0);
    glVertex3f(-1.1,3.0,-1.0);
    glVertex3f(-1.1,3.0, 1.0);
    glVertex3f( 1.0,3.0, 1.0);
    glVertex3f( 1.0,3.0,-1.0);

    // kanan
    glNormal3f(1,0,0);
    glVertex3f(1.5,1.7,-1.0);
    glVertex3f(1.0,3.0,-1.0);
    glVertex3f(1.0,3.0, 1.0);
    glVertex3f(1.5,1.7, 1.0);

    // kiri
    glNormal3f(-1,0,0);
    glVertex3f(-1.6,1.7,-1.0);
    glVertex3f(-1.6,1.7, 1.0);
    glVertex3f(-1.1,3.0, 1.0);
    glVertex3f(-1.1,3.0,-1.0);

    glEnd();
}

void KacaMobil()
{
    glColor3f(0.75f, 0.88f, 1.0f);

    glBegin(GL_QUADS);

    // kaca samping
    glVertex3f(-1.0,2.0,1.01);
    glVertex3f( 0.8,2.0,1.01);
    glVertex3f( 0.6,2.7,1.01);
    glVertex3f(-0.8,2.7,1.01);

    glVertex3f(-1.0,2.0,-1.01);
    glVertex3f(-0.8,2.7,-1.01);
    glVertex3f( 0.6,2.7,-1.01);
    glVertex3f( 0.8,2.0,-1.01);

    glEnd();
}

// ================= RODA =================
void Roda(float xPos, float zPos)
{
    glPushMatrix();

    glColor3f(0.15f, 0.15f, 0.15f); 
  
    glTranslatef(xPos, 0.3f, zPos);

    glutSolidTorus(0.15, 0.3, 10, 20);

    glPopMatrix();
}

void Mobil()
{
    BodyMobil();
    TopMobil();
    KacaMobil();

    Roda( 1.6f,  1.25f); // Kanan Depan
    Roda(-1.6f,  1.25f); // Kanan Belakang
    Roda( 1.6f, -1.25f); // Kiri Depan
    Roda(-1.6f, -1.25f); // Kiri Belakang
}

// ================= DISPLAY =================
void display()
{
    if(deltaMove)
        moveMeFlat(deltaMove);

    if(deltaAngle)
    {
        angle += deltaAngle;
        orientMe(angle);
    }

    glClearColor(0.65f, 0.85f, 0.95f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f
    );

    Grid();
    Road();

    glPushMatrix();
    glTranslatef(0,0,0);
    Mobil();
    glPopMatrix();

    glutSwapBuffers();
}

// ================= KEYBOARD =================
void pressKey(int key, int xx, int yy)
{
    switch(key)
    {
        case GLUT_KEY_LEFT :
            deltaAngle = -0.01f;
            break;

        case GLUT_KEY_RIGHT :
            deltaAngle = 0.01f;
            break;

        case GLUT_KEY_UP :
            deltaMove = 1;
            break;

        case GLUT_KEY_DOWN :
            deltaMove = -1;
            break;
    }
}

void releaseKey(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT :
            if(deltaAngle < 0.0f)
                deltaAngle = 0.0f;
            break;

        case GLUT_KEY_RIGHT :
            if(deltaAngle > 0.0f)
                deltaAngle = 0.0f;
            break;

        case GLUT_KEY_UP :
            if(deltaMove > 0)
                deltaMove = 0;
            break;

        case GLUT_KEY_DOWN :
            if(deltaMove < 0)
                deltaMove = 0;
            break;
    }
}

// ================= LIGHTING =================
void lighting()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

// ================= INIT =================
void init()
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

// ================= MAIN =================
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(900,600);

    glutCreateWindow("Mobil 3D PiNKiEE");

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutReshapeFunc(Reshape);

    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);

    glutIgnoreKeyRepeat(1);

    lighting();
    init();

    glutMainLoop();

    return 0;
}
