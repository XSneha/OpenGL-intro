#include<GL/freeglut.h>

bool bfScrn = false;
GLfloat angleTri = 0.0f;
GLfloat angleSquare = 0.0f;

int main(int argc, char** argv) {
	void initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);
	void spin(void);

	glutInit(&argc, argv);									//initialize window 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);			// GLUT_SINGLE : single buffer
	glutInitWindowSize(800, 600);							//initial window size
	glutInitWindowPosition(100, 100);						//initial window position
	glutCreateWindow("Glut : 1st Window");					//title

	initialize();
	//registering callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(spin);
	glutCloseFunc(uninitialize);

	glutMainLoop();											// run loop run infinitly until user close the window
	return(0);
}

void initialize(void) {
	//clearing background and set it balck
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void resize(int width, int height) {
	if (height == 0)
		height = 1;											// cause we have to find aspect ratio width/height height should not be zero.
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();										//load identity matrix

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(1.5f, 0.0f, -6.0f);
	glScalef(0.75f, 0.75f, 0.75f);
	glRotatef(angleSquare, 1.0f, 1.0f, 1.0f);			//rotate angle by angleTri degree on all x,y,z axis
	glBegin(GL_QUADS);
	//top face
	glColor3f(1.0f, 0.0f, 0.0f);						//red
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	//bottom face
	glColor3f(0.0f, 1.0f, 0.0f);						//green
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	//front face
	glColor3f(0.0f, 0.0f, 1.0f);						//blue
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	//back face
	glColor3f(1.0f, 1.0f, 0.0f);						//yellow
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	//left face
	glColor3f(0.0f, 1.0f, 1.0f);						//cyan
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	//right face
	glColor3f(1.0f, 0.0f, 1.0f);						//magenta
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();
	//glutPostRedisplay();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		glutLeaveMainLoop();								//leave main loop and close window
		break;
	case 'F':
	case 'f':
		if (bfScrn == false) {
			glutFullScreen();
			bfScrn = true;
		}
		else {
			glutLeaveFullScreen();
			bfScrn = false;
		}
		break;
	}
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON: break;
	case GLUT_RIGHT_BUTTON: glutLeaveMainLoop();
		break;
	default: break;
	}
}

void spin(void) {
	angleTri = angleTri + 2.0f;
	if (angleTri >= 360.0f)
		angleTri = angleTri - 360.0f;

	angleSquare = angleSquare + 1.0f;
	if (angleSquare >= 360.0f)
		angleSquare = angleSquare - 360.0f;
	//TODO : fix spin
	//glutPostRedisplay();
}

void uninitialize(void) {
	//Do nothing...
}
