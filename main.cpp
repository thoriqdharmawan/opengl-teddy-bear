#include <GL/glut.h>
#include <math.h>

#define DEG2RAD 3.14159/180.0

void blackColor() {
    glColor3f(0.0, 0.0, 0.0);
}

void primaryColor() {
    float r = (float)0xB1 / 255.0f;
    float g = (float)0x7D / 255.0f;
    float b = (float)0x34 / 255.0f;

    glColor3f(r, g, b);
}

void secondaryColor() {
    float r = (float)0x9B / 255.0f;
    float g = (float)0x90 / 255.0f;
    float b = (float)0x70 / 255.0f;

    glColor3f(r, g, b);
}

void resetTranslation() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f);
}

void drawEgg(float radiusX, float radiusY) {
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 360; i++)
    {
        float angle = i * M_PI / 180;
        float cx = radiusX * cos(angle);
        float cy = radiusY * sin(angle);
        glVertex2f(cx, cy);
    }
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i <= 360; i++)
    {
        float angle = i * M_PI / 180;
        float cx = radiusX * cos(angle);
        float cy = radiusY * sin(angle);
        glVertex2f(cx, cy);
    }
    glEnd();
}

void drawCircle(float radius){
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        float degInRad = i*DEG2RAD;
        glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
    }
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++){
        float degInRad = i*DEG2RAD;
        glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
    }
    glEnd();
}

void drawCylinder(float radius, float height) {
    primaryColor();
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, height);
    glTranslatef(0.0, height, 0.0);
    for(int i = 0; i <= 180; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f((cos(degInRad) * radius) - radius, height + (sin(degInRad) * radius));
    }

    for(int i = 180; i <= 360; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * radius - radius,  sin(degInRad) * radius);
    }
    glEnd();

    blackColor();
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, height);
    glTranslatef(0.0, height, 0.0);
    for(int i = 0; i <= 180; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f((cos(degInRad) * radius) - radius, height + (sin(degInRad) * radius));
    }

    for(int i = 180; i <= 360; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * radius - radius,  sin(degInRad) * radius);
    }
    glEnd();
    resetTranslation();
}

void drawEar(){
    glTranslatef(0.3, 0.7, 0.0);
    primaryColor();
    drawCircle(0.125);

    secondaryColor();
    drawCircle(0.07);

    glTranslatef(-0.6, 0.0, 0.0);
    primaryColor();
    drawCircle(0.125);

    secondaryColor();
    drawCircle(0.06);

    resetTranslation();
}

void drawHead() {
    primaryColor();
    glTranslatef(0.0, 0.45, 0.0);
    drawEgg(0.4, 0.38);

    glTranslatef(0.0, -0.15, 0.0);
    secondaryColor();
    drawEgg(0.12, 0.09);

    glTranslatef(0.1, 0.15, 0.0);
    drawEgg(0.02, 0.03);

    glTranslatef(-0.2, 0.0, 0.0);
    drawEgg(0.02, 0.03);

    resetTranslation();
}

void drawBody() {
    glTranslatef(0.3, -0.3, 0.0);
    drawCylinder(0.3, 0.3);
    resetTranslation();

    secondaryColor();
    glTranslatef(0.0, -0.32, 0.0);
    drawEgg(0.2, 0.28);
    resetTranslation();
}

void drawArm() {
    glTranslatef(0.5, -0.15, 0.0);
    glRotatef(30, 0.0f, 0.0f, 1.0f);
    drawCylinder(0.1, 0.3);

    glTranslatef(-0.33, -0.25, 0.0);
    glRotatef(-30, 0.0f, 0.0f, 1.0f);
    drawCylinder(0.1, 0.3);

    resetTranslation();
}

void drawFoot() {
    glTranslatef(-0.03, -0.73, 0.0);
    drawCylinder(0.12, 0.2);

    glTranslatef(0.28, -0.73, 0.0);
    drawCylinder(0.12, 0.2);
}

void drawMouth() {
    float radius = 0.04;
    blackColor();
    glLineWidth(3);
    glRotatef(180, 0.0f, 0.0f, 1.0f);
    glTranslatef(2* radius, -0.3, 0.0);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 180; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f((cos(degInRad) * radius) - radius, (sin(degInRad) * radius));
    }
    glEnd();

    glTranslatef(-2 * radius, 0.0, 0.0);

    glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 180; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f((cos(degInRad) * radius) - radius, (sin(degInRad) * radius));
    }

    glEnd();

    resetTranslation();

    glBegin(GL_LINE_STRIP);
        glVertex2f(0.0, 0.3);
        glVertex2f(0.0, 0.34);
    glEnd();

    glTranslatef(0.0, 0.34, 0.0);
    drawEgg(0.022, 0.012);

    resetTranslation();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2); // Set line thickness

    drawEar();
    drawArm();
    drawFoot();
    drawBody();
    drawHead();
    drawMouth();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Teddy Bear");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set canvas color to white
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
