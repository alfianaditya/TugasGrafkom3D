#include <GL/glut.h>
#include <cmath>


GLfloat light_position[] = { 2.0, 2.0, 1.0, 1.0 }; // Posisi cahaya
GLfloat light_position2[] = { -2.0, 2.0, -1.0, 1.0 }; // Posisi cahaya
GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 }; // Warna cahaya putih
GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // Warna ambient light

int lastX = 0;
int lastY = 0;
bool leftMouseButtonDown = false;
bool middleMouseButtonDown = false;
bool rightMouseButtonDown = false;

float rotateX = 0.0;
float rotateY = 0.0;
float translateX = 0.0;
float translateY = -0.7;
float translateZ = -6.0; // Jarak awal kamera dari objek


void drawVertex()
{
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.2f, 5.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.2f, 5.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-1.0f, 0.0f, -0.2f);
    glVertex3f(-0.2f, 5.0f, -0.2f);
    glVertex3f(1.0f, 0.0f, -0.2f);
    glVertex3f(0.2f, 5.0f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.2f, 5.0f, 0.0f);
    glVertex3f(-0.2f, 5.0f, -0.2f);
    glVertex3f(-1.0f, 0.0f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.2f, 5.0f, 0.0f);
    glVertex3f(0.2f, 5.0f, -0.2f);
    glVertex3f(1.0f, 0.0f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-0.2f, 5.0f, 0.0f);
    glVertex3f(-0.2f, 5.0f, -0.2f);
    glVertex3f(0.2f, 5.0f, -0.2f);
    glVertex3f(0.2f, 5.0f, 0.0f);
    
    glEnd();


}

void drawCustomCube(float x, float y, float z, float scaleX, float scaleY, float scaleZ) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scaleX, scaleY, scaleZ);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawTorus( float innerRadius, float outerRadius, int sides, int rings) {
    glPushMatrix();
    glutSolidTorus(innerRadius, outerRadius, sides, rings);
    glPopMatrix();
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.3, 0.3, 0.3, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(translateX, translateY, translateZ);

    glRotatef(rotateX, 1.0, 0.0, 0.0);
    glRotatef(rotateY, 0.0, 1.0, 0.0);

    // Menetapkan pencahayaan
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white_light);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white_light);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50.0);

    // //kaki tv
    // glPushMatrix();
    // glTranslatef(1.0, 0.53, 0.0);
    // glRotatef(90.0, 80.0, 2.0, 0.0);
    // glScalef(0.2, -0.05, 1.3);
    // drawVertex();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-1.0, 0.53, 0.0);
    // glRotatef(90.0, 0.0, 1.0, 0.0);
    // glScalef(0.3, 0.05, 0.3);
    // drawVertex();
    // glPopMatrix();

    
    glPushMatrix();
        glColor3f(1.0, 1.0, 0.8);
    //papan atas
        drawCustomCube(0.0, 0.475, 0.1, 3.5, 0.05, 1.35);
    //papan belakang kiri kanan
        drawCustomCube(-1.0, 0.0, -0.6, 1.9, 1.0, 0.05); 
        drawCustomCube(1.0, 0.0, -0.6, 1.9, 1.0, 0.05);

        glColor3f(1.0, 1.0, 1.0);
    //putih bawah
        drawCustomCube(-1.0, -0.65, -0.6, 1.9, 0.3, 0.05);
        drawCustomCube(1.0, -0.65, -0.6, 1.9, 0.3, 0.05);

    //sekat putih belakang
        drawCustomCube(1.0, 0.51, -0.6, 1.9, 0.03, 0.05);
        drawCustomCube(-1.0, 0.51, -0.6, 1.9, 0.03, 0.05);

        drawCustomCube(1.0, 0.75, -0.6, 1.9, 0.03, 0.05);
        drawCustomCube(-1.0, 0.75, -0.6, 1.9, 0.03, 0.05);

        drawCustomCube(1.0, 1.185, -0.6, 1.9, 0.03, 0.05);
        drawCustomCube(-1.0, 1.185, -0.6, 1.9, 0.03, 0.05);

    //putih sekat atas bawah
        drawCustomCube(0.0, 1.185, 0.08, 0.05, 0.03, 1.3);
        drawCustomCube(0.0, -0.785, 0.08, 0.05, 0.03, 1.3);
        

    //papan belakang bawah
        glColor3f(0.81, 0.69, 0.38);
        drawCustomCube(-1.0, 0.63, -0.6, 1.9, 0.22, 0.05);
        drawCustomCube(1.0, 0.63, -0.6, 1.9, 0.22, 0.05);

    //papan belakang atas
        glColor3f(0.8, 0.84, 0.85);
        drawCustomCube(-1.0, 0.97, -0.6, 1.9, 0.42, 0.05);
        drawCustomCube(1.0, 0.97, -0.6, 1.9, 0.42, 0.05);
           
    //papan sekat
        glColor3f(0.81, 0.69, 0.38);
        drawCustomCube(0.0, 0.2, 0.08, 0.05, 1.95, 1.3);

    //outline sekat tengah
        glColor3f(1.3, 1.3, 1.3);
        drawCustomCube(0.0, 0.2, 0.755, 0.05, 2.0, 0.05);
        drawCustomCube(0.0, 0.2, -0.6, 0.1, 2.0, 0.06);

        drawCustomCube(-1.97, 0.2, -0.6, 0.05, 2.0, 0.05);
        drawCustomCube(1.97, 0.2, -0.6, 0.05, 2.0, 0.05);
    glPopMatrix();


    
    glPushMatrix();
    // Gambar Kaki meja kanan
        glColor3f(1.0, 1.0, 1.0);
    //kotak besar samping
        drawCustomCube(1.5, -0.175, -0.4, 0.05, 1.25, 0.4);
    //kotak kecil samping
        drawCustomCube(1.5, -0.125, -0.2, 0.05, 0.5, 0.02);

    //sanggah an meja atas
        drawCustomCube(1.5, 0.44, 0.08, 0.05, 0.02, 0.6); 
    //sanggah an meja bawah
        drawCustomCube(1.5, -0.8, 0.08, 0.05, 0.02, 0.85);
    glPopMatrix();

    glPushMatrix();
    //miringan atas
        glRotatef(152.0, 1.0, 0.0, 0.0);
        drawCustomCube(1.5, -0.20, 0.0, 0.05, 0.02, 1.1);
    glPopMatrix();

    glPushMatrix();
    //miringan bawah
        glRotatef(30.0, 1.0, 0.0, 0.0);
        drawCustomCube(1.5, -0.43, 0.22, 0.05, 0.02, 1.3); 
    glPopMatrix();



    glPushMatrix();
    // Gambar Kaki meja kiri
        glColor3f(1.0, 1.0, 1.0);
    //kotak besar samping
        drawCustomCube(-1.5, -0.175, -0.4, 0.05, 1.25, 0.4);
    //kotak kecil samping
        drawCustomCube(-1.5, -0.125, -0.2, 0.05, 0.5, 0.02);

    //sanggah an meja atas
        drawCustomCube(-1.5, 0.44, 0.08, 0.05, 0.02, 0.6); 
    //sanggah an meja bawah
        drawCustomCube(-1.5, -0.8, 0.08, 0.05, 0.02, 0.85);
    glPopMatrix();

    glPushMatrix();
    //miringan atas
        glRotatef(152.0, 1.0, 0.0, 0.0);
        drawCustomCube(-1.5, -0.20, 0.0, 0.05, 0.02, 1.1);
    glPopMatrix();

    glPushMatrix();
    //miringan bawah
        glRotatef(30.0, 1.0, 0.0, 0.0);
        drawCustomCube(-1.5, -0.43, 0.22, 0.05, 0.02, 1.3); 
    glPopMatrix();


    //AREA PC

    
    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
    //monitor
        drawCustomCube(0.9, 1.075, -0.3, 1.0, 0.5, 0.05);
    //outline
        glColor3f(0.5, 0.5, 0.5);
    //monitor bawah
        
    
        drawCustomCube(0.9, 0.7, -0.3, 1.05, 0.145, 0.04);
        drawCustomCube(0.365, 0.71, -0.3, 0.025, 0.12, 0.04);
        drawCustomCube(1.435, 0.71, -0.3, 0.025, 0.12, 0.04);
    //sangga
        drawCustomCube(0.9, 0.5, -0.4, 0.3, 0.01, 0.35);
    //outline
        glColor3f(0.0, 0.0, 0.0);
    //monitor abkk
        drawCustomCube(0.375, 1.067, -0.3, 0.05, 0.6, 0.05);
        drawCustomCube(1.425, 1.067, -0.3, 0.05, 0.6, 0.05);
        drawCustomCube(0.9, 1.35, -0.3, 1.0, 0.05, 0.05);
        drawCustomCube(0.9, 0.8, -0.3, 1.0, 0.05, 0.05);

    //keyboard
        glColor3f(0.0, 0.0, 0.0);
        drawCustomCube(0.85, 0.5, 0.0, 1, 0.08, 0.3); 
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.5, 0.5, 0.5);
    //lingkaran samping kiri
        glTranslatef(0.39, 0.665, -0.3);
        drawTorus(0.02, 0.02, 30, 20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.5, 0.5, 0.5);
    //lingkaran samping    
        glTranslatef(1.405, 0.665, -0.3);
        drawTorus(0.02, 0.02, 30, 20);
    glPopMatrix();


    glPushMatrix();
        glRotatef(45.0, 1.0, 0.0, 0.0);
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.0, 0.15, 0.25);
        drawCustomCube(0.9, -0.05, -1.0, 0.3, 0.4, 0.02);
    glPopMatrix();





    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
    //monitor
        drawCustomCube(-0.9, 1.075, -0.3, 1.0, 0.5, 0.05);
    //outline
        glColor3f(0.5, 0.5, 0.5);
    //monitor bawah
        
    
        drawCustomCube(-0.9, 0.7, -0.3, 1.05, 0.145, 0.04);
        drawCustomCube(-0.365, 0.71, -0.3, 0.025, 0.12, 0.04);
        drawCustomCube(-1.435, 0.71, -0.3, 0.025, 0.12, 0.04);
    //sangga
        drawCustomCube(-0.9, 0.5, -0.4, 0.3, 0.01, 0.35);
    //outline
        glColor3f(0.0, 0.0, 0.0);
    //monitor abkk
        drawCustomCube(-0.375, 1.067, -0.3, 0.05, 0.6, 0.05);
        drawCustomCube(-1.425, 1.067, -0.3, 0.05, 0.6, 0.05);
        drawCustomCube(-0.9, 1.35, -0.3, 1.0, 0.05, 0.05);
        drawCustomCube(-0.9, 0.8, -0.3, 1.0, 0.05, 0.05);

    //keyboard
        glColor3f(0.0, 0.0, 0.0);
        drawCustomCube(-0.85, 0.5, 0.0, 1, 0.08, 0.3); 
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.5, 0.5, 0.5);
    //lingkaran samping kiri
        glTranslatef(-0.39, 0.665, -0.3);
        drawTorus(0.02, 0.02, 30, 20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.5, 0.5, 0.5);
    //lingkaran samping    
        glTranslatef(-1.405, 0.665, -0.3);
        drawTorus(0.02, 0.02, 30, 20);
    glPopMatrix();


    glPushMatrix();
        glRotatef(45.0, 1.0, 0.0, 0.0);
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(-0.0, 0.15, 0.25);
        drawCustomCube(-0.9, -0.05, -1.0, 0.3, 0.4, 0.02);
    glPopMatrix();



    glDisable(GL_LIGHTING);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / h, 1, 10);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
    lastX = x;
    lastY = y;

    if (button == GLUT_LEFT_BUTTON) {
        leftMouseButtonDown = (state == GLUT_DOWN);
    }
    else if (button == GLUT_MIDDLE_BUTTON) {
        middleMouseButtonDown = (state == GLUT_DOWN);
    }
    else if (button == GLUT_RIGHT_BUTTON) {
        rightMouseButtonDown = (state == GLUT_DOWN);
    }
}

void motion(int x, int y) {
    int deltaX = x - lastX;
    int deltaY = y - lastY;

    if (leftMouseButtonDown) {
        rotateX += deltaY * 0.5;
        rotateY += deltaX * 0.5;

        if (rotateX > 360.0) rotateX = 360.0;
        if (rotateX < -360.0) rotateX = -360.0;
    }
    else if (middleMouseButtonDown) {
        translateX += deltaX * 0.01;
        translateY -= deltaY * 0.01;
    }
    else if (rightMouseButtonDown) {
        translateZ += deltaY * 0.03;
    }

    lastX = x;
    lastY = y;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(720, 720);
    glutCreateWindow("OpenGL 3D Cylinder Example with Blender-like Camera");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glutMainLoop();
    return 0;
}