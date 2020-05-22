#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <cmath>
#include <time.h>
//PROFE LES CAMBIABA LAS COORDENADAS PARA HACER LA CARA Y NO SE MOVIAN:(
using namespace std;
#define PI 3.1415926535
#define PI2 3.1415926535*2
float x, y;
void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}
float dt;

void circle(float posX, float posY, float size) {
	float x, y;
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glBegin(GL_POLYGON);
	for (float x_val = -PI; x_val < PI; x_val += PI2 / 30) {
		x = cos(x_val);
		y = sin(x_val);
		glVertex2f((x * size), (y * size));
	}
	glEnd();
	glPopMatrix();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(-0.5, 0.5);
			glColor3f(0.8, 1, 0.5);
			glVertex2f(0, 0.7);
		glColor3f(0, 1, 0);
		glVertex2f(0.5, 0.5);
		glColor3f(0, 0, 1);
		glVertex2f(0.5, -0.5);
		glColor3f(0.8, 1, 0.5);
		glVertex2f(-0.5, -0.5);
	glEnd();
	//Ctlr + k +c 


	glBegin(GL_POINTS);

	for (float x_val = -PI; x_val < PI; x_val += 0.01) {
			glColor3f(0, 1, 0);
			x = x_val;
			y = cos(x_val);
			glVertex2f(x * 0.1, y*0.1);

			y = sin(x_val);
			glColor3f(1, 0, 0);
			glVertex2f(x * 0.1, y * 0.1);
		}
	glEnd();

	glBegin(GL_POLYGON);

	for (float x_val = -PI; x_val < PI; x_val += PI / 5) {
		glColor3f(0, 1, 0);
		x = cos(x_val);
		y = sin(x_val);
		glVertex2f(x * 0.5, y * 0.5);
	}
	glEnd();

	glutSwapBuffers();
	dt += 0.01;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);


	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}


void display() 
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	//rectangulo
	glBegin(GL_QUADS);
	glColor3f(0, 1.0, 0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();
	glFlush();

	//triangulo
	glBegin(GL_POLYGON);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();

	//circulo
	glColor3ub(255, 255, 255);  // Color Red
	circle(0, 0, 0.2f);
	glColor3ub(255, 0, 0);  // Color Red
	glFlush();

	glColor3ub(255, 255, 255);  // Color Red
	circle(0, 0, -0.2f);
	glColor3ub(255, 0, 0);  // Color Red
	glFlush();

}
 

int main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Rectangle Shape");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}