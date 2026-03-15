// Nama/NIM  : Amelia Aristianti/24060124120008
// Deskripsi : membuat titik pakai GL_Lines

#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5);

    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);

        // titik 1
        glVertex2f(-0.3, 0.2);
        glVertex2f(-0.29, 0.2);

        // titik 2
        glVertex2f(0.0, -0.1);
        glVertex2f(0.01, -0.1);

    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.96, 0.90, 0.75, 1.0); 

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Titik dengan GL_LINES");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
