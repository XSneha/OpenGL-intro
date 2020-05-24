#include <iostream>
#include <ctime>
#include<GL/freeglut.h>
#define PI 3.14159265358
using namespace std;

bool bfScrn = false;
GLfloat clockAngle = 0.0f;
GLfloat secondHand = 0.0f;
GLfloat minuteHand = 0.0f;
GLfloat hourHand = 0.0f;
int hour = 0;
int minute = 0;
int second = 0;

int count = 0;
int main(int argc, char** argv) {
	void initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);
	void timer(int);
	//get current time
	time_t now = time(0);
	tm* ltm = localtime(&now);

	hour = ltm->tm_hour;
	minute = ltm->tm_min;
	second = ltm->tm_sec;

	hourHand = -((hour * 30) + (0.5 * minute));
	minuteHand = -((minute * 6) + (0.1 * second));
	secondHand = -(second * 6);

	glutInit(&argc, argv);									//initialize window 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);			// GLUT_DOUBLE : double buffer to add movement 
	glutInitWindowSize(500, 500);							//initial window size
	glutInitWindowPosition(100, 100);						//initial window position
	glutCreateWindow("Glut : Analog Clock");				//title

	initialize();
	//registering callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);
	timer(0);
	glutMainLoop();// run loop run infinitly until user close the window
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
	glMatrixMode(GL_PROJECTION);
	glPointSize(6.0f);
	//12 points for clock hours
	for (int i = 0; i <= 12; i++) {
		glLoadIdentity();
		glScalef(0.75f, 0.75f, 0.75f);
		glRotatef(clockAngle +=30, 0.0f, 0.0f, 1.0f);						
		glTranslatef(1.0f, 0.0f, 0.0f);
		glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2i(0, 0);
		glEnd();
	}
	//clock frame
	glLoadIdentity();
	glScalef(0.65f, 0.65f, 0.65f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(secondHand, 0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 1.0);
		for (int i = 0; i < 100; i++) {
			float angle = 2 * PI * i / 100;
			glVertex2f(cos(angle),sin(angle));
		}
	glEnd();
	//second hand
	glLoadIdentity();
	glLineWidth(2.0);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(secondHand, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(0, 0.7f);
	glEnd();
	//minute hand
	glLoadIdentity();
	glLineWidth(3.0);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(minuteHand, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0, 0.5f);
	glEnd();
	//hour hand
	glLoadIdentity();
	glLineWidth(4.0);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(hourHand, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0, 0.3f);
	glEnd();
	//center
	glLoadIdentity();
	glScalef(0.02f, 0.02f, 0.02f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(secondHand, 0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i < 100; i++) {
		float angle = 2 * PI * i / 100;
		glVertex2f(cos(angle), sin(angle));
	}
	glEnd();
	
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		glutLeaveMainLoop();								
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

void timer(int value) {
	glutTimerFunc(1000, timer, 0);
	secondHand -= 6;
	if (secondHand == -360) {
		secondHand = 0;
		minuteHand -= 6;
		hourHand -= 0.5;
		if (minuteHand == -360) {
			minuteHand = 0;
			if (hourHand == -360)
				hourHand = 0;
		}
	}
	glutPostRedisplay();
}

void uninitialize(void) {
	//Do nothing...
}
