#include<GL/freeglut.h>
#include<math.h>
#define PI 3.142
bool bfullscreen = false;
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
	glutInitWindowSize(900, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GLUT: TREE ");

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
	glClearColor(0.2313f, 0.8627f, 0.9294f, 1.0f);
}
void resize(int width, int height)
{
	if (height <= 0)
		height = 1;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	//ground
	glLoadIdentity();
	glScalef(1.0f, 0.50f, 1.0f);
	glTranslatef(0.0f, -1.8f, 0.0f);
	glBegin(GL_POLYGON);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();

	//1st tree
	glLoadIdentity();
	glScalef(0.28f, 0.60f, 0.65f);
	glTranslatef(-2.3f, 0.50f, 0.0f);
	glBegin(GL_POLYGON);
		glColor3f(0.9960f, 0.8509f, 0.2862f);
		for (int i = 0; i < 100; i++) {
			float angle = 2 * PI * i / 100;
			glVertex2f(cos(angle),sin(angle));
		}
	glEnd();
	//branch1
	glLoadIdentity();
	glTranslatef(-0.72f, 0.2f, 0.0f);
	glScalef(0.09f, 0.35f, 0.35f);
	glRotatef(55.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.5f, 0.35f, 0.05f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
		glVertex3f(0.15f, -1.0f, 0.0f);
	glEnd();
	//branch2
	glLoadIdentity();
	glTranslatef(-0.581f, 0.1f, 0.0f);
	glScalef(0.09f, 0.45f, 0.35f);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.5f, 0.35f, 0.05f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
	glVertex3f(0.15f, -1.0f, 0.0f);
	glEnd();
	//bush
	glLoadIdentity();
	glTranslatef(-0.65f, 0.0f, 0.0f);
	glScalef(0.3f, 0.95f, 0.95f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.5f, 0.35f, 0.05f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
		glVertex3f(0.15f, -1.0f, 0.0f);
	glEnd();

	//2nd tree
	glLoadIdentity();
	glScalef(0.28f, 0.60f, 0.65f);
	glTranslatef(0.0f, 0.50f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.9803f, 0.8196f, 0.1921f);
	for (int i = 0; i < 100; i++) {
		float angle = 2 * PI * i / 100;
		glVertex2f(cos(angle), sin(angle));
	}
	glEnd();
	//branch1
	glLoadIdentity();
	glTranslatef(-0.08f, 0.2f, 0.0f);
	glScalef(0.09f, 0.35f, 0.35f);
	glRotatef(55.0f, 0.0f, 0.0f, 1.0f);			
	glBegin(GL_TRIANGLES);
		glColor3f(0.6f, 0.35f, 0.06f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
		glVertex3f(0.15f, -1.0f, 0.0f);
	glEnd();
	//branch2
	glLoadIdentity();
	glTranslatef(0.08f, 0.1f, 0.0f);
	glScalef(0.09f, 0.45f, 0.35f);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.6f, 0.35f, 0.06f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
		glVertex3f(0.15f, -1.0f, 0.0f);
	glEnd();
	//bush
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(0.3f, 0.95f, 0.95f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.6f, 0.35f, 0.06f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
		glVertex3f(0.15f, -1.0f, 0.0f);
	glEnd();

	//3rd tree
	glLoadIdentity();
	glScalef(0.28f, 0.60f, 0.65f);
	glTranslatef(2.3f, 0.50f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.9803f, 0.7960f, 0.0743f);
	for (int i = 0; i < 100; i++) {
		float angle = 2 * PI * i / 100;
		glVertex2f(cos(angle), sin(angle));
	}
	glEnd();
	//branch1
	glLoadIdentity();
	glTranslatef(0.57f, 0.2f, 0.0f);
	glScalef(0.09f, 0.35f, 0.35f);
	glRotatef(55.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.6f, 0.4f, 0.09f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
		glVertex3f(0.15f, -1.0f, 0.0f);
	glEnd();
	//branch2
	glLoadIdentity();
	glTranslatef(0.73f, 0.1f, 0.0f);
	glScalef(0.09f, 0.45f, 0.35f);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.6f, 0.4f, 0.09f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
		glVertex3f(0.15f, -1.0f, 0.0f);
	glEnd();
	//bush
	glLoadIdentity();
	glTranslatef(0.65f, 0.0f, 0.0f);
	glScalef(0.3f, 0.95f, 0.95f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.6f, 0.4f, 0.09f);
		glVertex3f(0.0f, 0.65f, 0.0f);
		glVertex3f(-0.15f, -1.0f, 0.0f);
		glVertex3f(0.15f, -1.0f, 0.0f);
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
		if (bfullscreen == false)
		{
			glutFullScreen();
			bfullscreen = true;
		}
	}
}

void mouse(int button, int state, int x, int y) {
}

void uninitialize(void) {

}