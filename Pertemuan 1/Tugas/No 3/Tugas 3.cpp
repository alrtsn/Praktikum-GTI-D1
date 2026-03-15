// Nama/NIM  : Amelia Aristianti/24060124120008
// Deskripsi : membuat kubus bertingkat sekreatif mungkin

#include <GL/glut.h>

float s = 0.12;

void pixel(float x,float y,float r,float g,float b){
    glColor3f(r,g,b);

    glBegin(GL_QUADS);
        glVertex2f(x,y);
        glVertex2f(x+s,y);
        glVertex2f(x+s,y+s);
        glVertex2f(x,y+s);
    glEnd();
}

void drawHeart(){

    float y = 0;

    pixel(-0.24,y+0.24,1.0,0.65,0.85);
    pixel(-0.12,y+0.24,1.0,0.65,0.85);
    pixel(0.12,y+0.24,1.0,0.65,0.85);
    pixel(0.24,y+0.24,1.0,0.65,0.85);

    pixel(-0.36,y+0.12,1.0,0.55,0.80);
    pixel(-0.24,y+0.12,1.0,0.55,0.80);
    pixel(-0.12,y+0.12,1.0,0.55,0.80);
    pixel(0,y+0.12,1.0,0.55,0.80);
    pixel(0.12,y+0.12,1.0,0.55,0.80);
    pixel(0.24,y+0.12,1.0,0.55,0.80);
    pixel(0.36,y+0.12,1.0,0.55,0.80);

    pixel(-0.24,y,1.0,0.45,0.75);
    pixel(-0.12,y,1.0,0.45,0.75);
    pixel(0,y,1.0,0.45,0.75);
    pixel(0.12,y,1.0,0.45,0.75);
    pixel(0.24,y,1.0,0.45,0.75);

    pixel(-0.12,y-0.12,1.0,0.35,0.70);
    pixel(0,y-0.12,1.0,0.35,0.70);
    pixel(0.12,y-0.12,1.0,0.35,0.70);

    pixel(0,y-0.24,1.0,0.25,0.65);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawHeart();

    glFlush();
}

void init(){
    glClearColor(0.80,0.90,0.97,1.0); // biru pastel
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutCreateWindow("Heart Pink");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
