#include<GL/freeglut.h>
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
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GLUT: NONAME ");

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
	glClearColor(0.0f, 0.0f,0.0f,1.0f);
}
void resize(int width,int height)
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
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(0.75f, 0.75f, 0.75f);

	glBegin(GL_QUADS);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);

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

void mouse(int button , int state ,int x, int y) {
}

void uninitialize(void) {

}

























