// Nama/NIM  : Amelia Aristianti / 24060124120008
// Deskripsi : rumah gambaran anak sd dengan berbagai primitive 

#include <GL/glut.h>

void drawHouseScene(){

    // rumput (QUAD_STRIP)
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.35,0.75,0.35);
    glVertex2f(-1,-0.6); glVertex2f(-1,-1);
    glVertex2f( 1,-0.6); glVertex2f( 1,-1);
    glEnd();

    // badan rumah (QUADS)
    glBegin(GL_QUADS);
    glColor3f(0.95,0.82,0.65);
    glVertex2f(-0.35,-0.25);
    glVertex2f( 0.35,-0.25);
    glVertex2f( 0.35, 0.20);
    glVertex2f(-0.35, 0.20);
    glEnd();

    // atap (TRIANGLES)
    glBegin(GL_TRIANGLES);
    glColor3f(0.75,0.20,0.20);
    glVertex2f(-0.40,0.20);
    glVertex2f( 0.40,0.20);
    glVertex2f( 0.00,0.45);
    glEnd();
    
    // sisi depan atap (TRIANGLE_STRIP)
	glBegin(GL_TRIANGLE_STRIP);
	
	glColor3f(0.65,0.15,0.15);
	glVertex2f(-0.40,0.20);
	glVertex2f(-0.32,0.12);
	
	glColor3f(0.70,0.18,0.18);
	glVertex2f(0.00,0.45);
	glVertex2f(0.00,0.32);
	
	glColor3f(0.65,0.15,0.15);
	glVertex2f(0.40,0.20);
	glVertex2f(0.32,0.12);
	
	glEnd();

    // cerobong (QUADS)
    glBegin(GL_QUADS);
    glColor3f(0.55,0.15,0.15);
    glVertex2f(0.12,0.28);
    glVertex2f(0.20,0.28);
    glVertex2f(0.20,0.45);
    glVertex2f(0.12,0.45);
    glEnd();

    // pintu (QUADS)
    glBegin(GL_QUADS);
    glColor3f(0.55,0.30,0.10);
    glVertex2f(-0.06,-0.25);
    glVertex2f( 0.06,-0.25);
    glVertex2f( 0.06, 0.05);
    glVertex2f(-0.06, 0.05);
    glEnd();

    // gagang pintu (TRIANGLE_FAN kecil sebagai lingkaran)
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.95,0.85,0.20);
    glVertex2f(0.03,-0.10);
    glVertex2f(0.04,-0.10);
    glVertex2f(0.035,-0.09);
    glVertex2f(0.025,-0.09);
    glVertex2f(0.02,-0.10);
    glVertex2f(0.025,-0.11);
    glVertex2f(0.035,-0.11);
    glVertex2f(0.04,-0.10);
    glEnd();

    // jendela kiri (LINE_LOOP)
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex2f(-0.28,-0.02);
    glVertex2f(-0.15,-0.02);
    glVertex2f(-0.15, 0.10);
    glVertex2f(-0.28, 0.10);
    glEnd();

    // kisi jendela kiri (LINES)
    glBegin(GL_LINES);
    glVertex2f(-0.215,-0.02); glVertex2f(-0.215,0.10);
    glVertex2f(-0.28, 0.04);  glVertex2f(-0.15, 0.04);
    glEnd();

    // jendela kanan (LINE_LOOP)
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.15,-0.02);
    glVertex2f(0.28,-0.02);
    glVertex2f(0.28, 0.10);
    glVertex2f(0.15, 0.10);
    glEnd();

    // kisi jendela kanan (LINES)
    glBegin(GL_LINES);
    glVertex2f(0.215,-0.02); glVertex2f(0.215,0.10);
    glVertex2f(0.15, 0.04);  glVertex2f(0.28, 0.04);
    glEnd();

    // jalan setapak (QUADS)
    glBegin(GL_QUADS);
    glColor3f(0.70,0.70,0.70);
    glVertex2f(-0.08,-0.60);
    glVertex2f( 0.08,-0.60);
    glVertex2f( 0.05,-0.25);
    glVertex2f(-0.05,-0.25);
    glEnd();

	// matahari bulat
	glBegin(GL_TRIANGLE_FAN);
	
	glColor3f(1.0,0.9,0.1);
	glVertex2f(0.75,0.70); // pusat
	
	glVertex2f(0.70,0.65);
	glVertex2f(0.80,0.65);
	glVertex2f(0.85,0.70);
	glVertex2f(0.80,0.75);
	glVertex2f(0.70,0.75);
	glVertex2f(0.65,0.70);
	glVertex2f(0.70,0.65);
	
	glEnd();

	// rumput detail (LINE_STRIP dari ujung ke ujung)
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.20,0.60,0.20);
	
	glVertex2f(-1.0,-0.6);
	glVertex2f(-0.8,-0.55);
	glVertex2f(-0.6,-0.6);
	glVertex2f(-0.4,-0.55);
	glVertex2f(-0.2,-0.6);
	glVertex2f(0.0,-0.55);
	glVertex2f(0.2,-0.6);
	glVertex2f(0.4,-0.55);
	glVertex2f(0.6,-0.6);
	glVertex2f(0.8,-0.55);
	glVertex2f(1.0,-0.6);
	
	glEnd();
	
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawHouseScene();
    glFlush();
}

void init(){
    glClearColor(0.75,0.88,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutCreateWindow("Rumah Bocah SD :> ");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
