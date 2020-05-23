#include<GL/freeglut.h>
#define RED 0.9003f, 0.7260f, 0.0643f
#define GREEN 0.9803f, 0.7960f, 0.0743f
#define BLUE 0.9960f, 0.8509f, 0.2862f
#define WHITE 1.0f,1.0f,1.0f

bool bfScrn = false;
GLfloat angleTri = 0.0f;
GLfloat angleSquare = 0.0f;

int main(int argc, char** argv)
{
	void initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GLUT: GANESHA ");

	initialize();
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);
	glutMainLoop();
	return(0);
}

void initialize(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void resize(int width, int height)
{
	if (height <= 0)
		height = 1;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.3f, 0.0f);
	glScalef(0.11f, 0.15f, 0.11f);
	//triangle 1
	glBegin(GL_TRIANGLES);
		glColor3f(GREEN);
		glVertex3f(0.0f, 3.0f, 0.0f);
		glVertex3f(-1.0f, 2.0f, 0.0f);
		glVertex3f(1.0f, 2.0f, 0.0f);
	glEnd();

	//triangle 2
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, 2.0f, 0.0f);
		glVertex3f(1.0f, 2.0f, 0.0f);
	glEnd();

	//triangle 3
	glBegin(GL_TRIANGLES);
		glColor3f(GREEN);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 2.0f, 0.0f);
	glEnd();

	//triangle 4
	glBegin(GL_TRIANGLES);
		glColor3f(BLUE);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle 5
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, -2.0f, 0.0f);
		glVertex3f(1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle 6
	glBegin(GL_TRIANGLES);
		glColor3f(GREEN);
		glVertex3f(0.0f, -5.0f, 0.0f);
		glVertex3f(-1.0f, -2.0f, 0.0f);
		glVertex3f(1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle 7
	glBegin(GL_TRIANGLES);
		glColor3f(GREEN);
		glVertex3f(0.0f, -5.0f, 0.0f);
		glVertex3f(-1.0f, -7.0f, 0.0f);
		glVertex3f(1.0f, -7.0f, 0.0f);
	glEnd();

	//triangle 8
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(0.0f, -8.0f, 0.0f);
		glVertex3f(-1.0f, -7.0f, 0.0f);
		glVertex3f(1.0f, -7.0f, 0.0f);
	glEnd();

	//triangle 9
	glBegin(GL_TRIANGLES);
		glColor3f(BLUE);
		glVertex3f(0.0f, -5.0f, 0.0f);
		glVertex3f(1.0f, -5.0f, 0.0f);
		glVertex3f(1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle 10
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(0.0f, -5.0f, 0.0f);
		glVertex3f(1.0f, -5.0f, 0.0f);
		glVertex3f(1.0f, -7.0f, 0.0f);
	glEnd();

	//triangle 11
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(0.0f, 3.0f, 0.0f);
		glVertex3f(2.0f, 3.0f, 0.0f);
		glVertex3f(1.0f, 2.0f, 0.0f);
	glEnd();

	//triangle 12
	glBegin(GL_TRIANGLES);
		glColor3f(BLUE);
		glVertex3f(2.0f, 2.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 2.0f, 0.0f);
	glEnd();

	//triangle 13
	glBegin(GL_TRIANGLES);
		glColor3f(GREEN);
		glVertex3f(2.0f, -2.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle 14
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(2.0f, -2.0f, 0.0f);
		glVertex3f(1.0f, -5.0f, 0.0f);
		glVertex3f(1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle 15
	glBegin(GL_TRIANGLES);
		glColor3f(BLUE);
		glVertex3f(2.0f, 3.0f, 0.0f);
		glVertex3f(1.0f, 2.0f, 0.0f);
		glVertex3f(6.0f, 4.0f, 0.0f);
	glEnd();

	//triangle 16
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(2.0f, 2.0f, 0.0f);
		glVertex3f(1.0f, 2.0f, 0.0f);
		glVertex3f(6.0f, 4.0f, 0.0f);
	glEnd();

	//triangle 17
	glBegin(GL_TRIANGLES);
		glColor3f(GREEN);
		glVertex3f(2.0f, 2.0f, 0.0f);
		glVertex3f(2.5f, -0.5f, 0.0f);
		glVertex3f(5.0f, 4.5f, 0.0f);
	glEnd();

	//triangle 18
	glBegin(GL_TRIANGLES);
		glColor3f(BLUE);
		glVertex3f(7.0f, -1.0f, 0.0f);
		glVertex3f(2.5f, -0.5f, 0.0f);
		glVertex3f(5.0f, 4.5f, 0.0f);
	glEnd();

	//triangle 19
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(7.0f, -1.0f, 0.0f);
		glVertex3f(9.0f, 3.0f, 0.0f);
		glVertex3f(5.0f, 4.5f, 0.0f);
	glEnd();

	//triangle 20
	glBegin(GL_TRIANGLES);
		glColor3f(GREEN);
		glVertex3f(6.0f, 4.0f, 0.0f);
		glVertex3f(9.0f, 3.0f, 0.0f);
		glVertex3f(5.0f, 4.5f, 0.0f);
	glEnd();

	//triangle 21
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(7.0f, -1.0f, 0.0f);
		glVertex3f(2.5f, -0.5f, 0.0f);
		glVertex3f(4.0f, -3.5f, 0.0f);
	glEnd();

	//triangle 22
	glBegin(GL_TRIANGLES);
		glColor3f(RED);
		glVertex3f(2.0f, 2.0f, 0.0f);
		glVertex3f(2.5f, -0.5f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
	glEnd();

	//triangle 23
	glBegin(GL_TRIANGLES);
		glColor3f(GREEN);
		glVertex3f(2.0f, -1.0f, 0.0f);
		glVertex3f(2.5f, -0.5f, 0.0f);
		glVertex3f(4.0f, -3.5f, 0.0f);
	glEnd();
	
	//triangle 24
	glBegin(GL_TRIANGLES);
		glColor3f(WHITE);
		glVertex3f(2.0f, -2.0f, 0.0f);
		glVertex3f(2.0f, -1.0f, 0.0f);
		glVertex3f(2.5f, -2.0f, 0.0f);
	glEnd();

	//triangle -3
	glBegin(GL_TRIANGLES);
	glColor3f(GREEN);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glEnd();

	//triangle -4
	glBegin(GL_TRIANGLES);
	glColor3f(BLUE);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle -9
	glBegin(GL_TRIANGLES);
	glColor3f(BLUE);
	glVertex3f(0.0f, -5.0f, 0.0f);
	glVertex3f(-1.0f, -5.0f, 0.0f);
	glVertex3f(-1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle -10
	glBegin(GL_TRIANGLES);
	glColor3f(RED);
	glVertex3f(0.0f, -5.0f, 0.0f);
	glVertex3f(-1.0f, -5.0f, 0.0f);
	glVertex3f(-1.0f, -7.0f, 0.0f);
	glEnd();

	//triangle -11
	glBegin(GL_TRIANGLES);
	glColor3f(RED);
	glVertex3f(0.0f, 3.0f, 0.0f);
	glVertex3f(-2.0f, 3.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glEnd();

	//triangle -12
	glBegin(GL_TRIANGLES);
	glColor3f(BLUE);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glEnd();

	//triangle -13
	glBegin(GL_TRIANGLES);
	glColor3f(GREEN);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle -14
	glBegin(GL_TRIANGLES);
	glColor3f(RED);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(-1.0f, -5.0f, 0.0f);
	glVertex3f(-1.0f, -2.0f, 0.0f);
	glEnd();

	//triangle -15
	glBegin(GL_TRIANGLES);
	glColor3f(BLUE);
	glVertex3f(-2.0f, 3.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glVertex3f(-6.0f, 4.0f, 0.0f);
	glEnd();

	//triangle -16
	glBegin(GL_TRIANGLES);
	glColor3f(RED);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glVertex3f(-6.0f, 4.0f, 0.0f);
	glEnd();

	//triangle -17
	glBegin(GL_TRIANGLES);
	glColor3f(GREEN);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glVertex3f(-2.5f, -0.5f, 0.0f);
	glVertex3f(-5.0f, 4.5f, 0.0f);
	glEnd();

	//triangle 18
	glBegin(GL_TRIANGLES);
	glColor3f(BLUE);
	glVertex3f(-7.0f, -1.0f, 0.0f);
	glVertex3f(-2.5f, -0.5f, 0.0f);
	glVertex3f(-5.0f, 4.5f, 0.0f);
	glEnd();

	//triangle -19
	glBegin(GL_TRIANGLES);
	glColor3f(RED);
	glVertex3f(-7.0f, -1.0f, 0.0f);
	glVertex3f(-9.0f, 3.0f, 0.0f);
	glVertex3f(-5.0f, 4.5f, 0.0f);
	glEnd();

	//triangle -20
	glBegin(GL_TRIANGLES);
	glColor3f(GREEN);
	glVertex3f(-6.0f, 4.0f, 0.0f);
	glVertex3f(-9.0f, 3.0f, 0.0f);
	glVertex3f(-5.0f, 4.5f, 0.0f);
	glEnd();

	//triangle 21
	glBegin(GL_TRIANGLES);
	glColor3f(RED);
	glVertex3f(-7.0f, -1.0f, 0.0f);
	glVertex3f(-2.5f, -0.5f, 0.0f);
	glVertex3f(-4.0f, -3.5f, 0.0f);
	glEnd();

	//triangle 22
	glBegin(GL_TRIANGLES);
	glColor3f(RED);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glVertex3f(-2.5f, -0.5f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glEnd();

	//triangle -23
	glBegin(GL_TRIANGLES);
	glColor3f(GREEN);
	glVertex3f(-2.0f, -1.0f, 0.0f);
	glVertex3f(-2.5f, -0.5f, 0.0f);
	glVertex3f(-4.0f, -3.5f, 0.0f);
	glEnd();

	//triangle -24
	glBegin(GL_TRIANGLES);
	glColor3f(WHITE);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, 0.0f);
	glVertex3f(-3.0f, -3.5f, 0.0f);
	glEnd();

	//triangle 25
	glBegin(GL_TRIANGLES);
	glColor3f(BLUE);
	glVertex3f(0.0f, -8.0f, 0.0f);
	glVertex3f(1.0f, -7.0f, 0.0f);
	glVertex3f(0.6f, -7.8f, 0.0f);
	glEnd();

	//triangle -25
	glBegin(GL_TRIANGLES);
	glColor3f(BLUE);
	glVertex3f(-0.0f, -8.0f, 0.0f);
	glVertex3f(-1.0f, -7.0f, 0.0f);
	glVertex3f(-0.6f, -7.8f, 0.0f);
	glEnd();

	//triangle 26
	glBegin(GL_TRIANGLES);
	glColor3f(BLUE);
	glVertex3f(1.0f, -7.0f, 0.0f);
	glVertex3f(1.0f, -5.0f, 0.0f);
	glVertex3f(1.5f, -5.5f, 0.0f);
	glEnd();

	//triangle 27
	glBegin(GL_TRIANGLES);
	glColor3f(RED);
	glVertex3f(2.0f, -5.0f, 0.0f);
	glVertex3f(1.0f, -5.0f, 0.0f);
	glVertex3f(1.5f, -5.5f, 0.0f);
	glEnd();

	glFlush();

}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case'F':
	case'f':
		if (bfScrn == false)
		{
			glutFullScreen();
			bfScrn = true;
		}
	}

}

void mouse(int button, int state, int x, int y) {
}

void uninitialize(void) {

}
