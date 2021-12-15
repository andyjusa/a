#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h> 
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32.lib")
double x,y = 0;
int i=0;

static void draw2dcube(void){
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, -0.5);
    glVertex3d(-0.5, 0.5, -0.5);
    glVertex3d(0.5, 0.5, -0.5);
    glVertex3d(0.5, -0.5, -0.5);
    glEnd();
}

void draw3dcube(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3d(1.0,0.0,0.0);
    draw2dcube();
    glPushMatrix();

    glTranslated(1.0, 0.0, 0.0);
    glColor3d(0.0,1.0,0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    draw2dcube();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.0, 0.0, 0.0);
    glRotated(-90.0, 0.0, 1.0, 0.0);
    draw2dcube();
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.0,0.0,1.0);
    glTranslated(0.0, 1.0, 0.0);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    draw2dcube();
    glPopMatrix();

    glPushMatrix();
    glColor3d(1.0,1.0,0.0);
    glTranslated(0.0, -1.0, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    draw2dcube();
    glPopMatrix();

    glColor3d(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, 0.5);
    glVertex3d(0.5, -0.5, 0.5);
    glVertex3d(0.5, 0.5, 0.5);
    glVertex3d(-0.5, 0.5, 0.5);
    glEnd();
    glPopMatrix();
    glFlush();
}
void Display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glTranslatef(0, 0, -4);
    glRotated((rand()%1800)/10.0,0.0,0.0,1.0);
    glRotated((rand()%1800)/10.0,0.0,1.0,0.0);
    glRotated((rand()%1800)/10.0,1.0,0.0,0.0);
    draw3dcube();
    glutSwapBuffers();
}
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
}
void timer(){
    glutPostRedisplay();
    glutTimerFunc(1000,timer,0);
}
void resharpe(GLsizei width, GLsizei height){
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    gluPerspective(45, (GLfloat)width / (GLfloat)height, 1.0, 100.0); 
    glMatrixMode(GL_MODELVIEW); 
}
int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("test");
    glutDisplayFunc(Display); 
    glPushMatrix();
    init();
    glutTimerFunc(0, timer, 0);
    glutReshapeFunc(resharpe);
    glutMainLoop(); 
    return 0;
}
