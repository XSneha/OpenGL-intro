#include<GL/freeglut.h>
#include<iostream>
bool bfScrn = false;
GLfloat angleTri = 0.0f;
GLfloat angleSquare = 0.0f;
int cx = 0, cy = 0, cz = 0;
int cn;

/*	Draw quads and create 3D shpes out of it
	enable num lock and use number keys on right side of your keyboard
	8: back 
	2: front
	4: left
	6: right
	u : up
	d : down
	c : clear
	Don't forget to press <space> after choosing the right vertex for your quad
*/

struct Quads {
	int x1, x2, x3,x4, y1, y2, y3,y4, z1, z2, z3,z4;
	float r, g, b;
	int state;
	int total;
}; 
Quads Q[100];

int main(int argc, char** argv) {
	void initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);
	void spin(void);
	void drawCube(void);
	void drawGrid(void);
	void addQuad(void);
	void drawQuad(void);

	glutInit(&argc, argv);									//initialize window 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);			// GLUT_SINGLE : single buffer
	glutInitWindowSize(800, 600);							//initial window size
	glutInitWindowPosition(100, 100);						//initial window position
	glutCreateWindow("Glut : 3D fun");						//title

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
	glLoadIdentity();
	gluPerspective(35, 1.0f, 0.1f, 1000);
	glMatrixMode(GL_MODELVIEW);
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

void drawCube() {
	glPushMatrix();	
		glColor3f(1,1,1);
		glRotatef(1, 30.0f, 1.0f, 0.0f);			//rotate angle by angleTri degree on all x,y,z axis
		glTranslatef(cx, cy, cz);
		glutSolidCube(0.5);
	glPopMatrix();
}

void drawGrid() {
	int i;
	for (i = 0; i < 20; i++) {
		glPushMatrix();
		if (i < 10) { 
			glTranslatef(0, 0, i);
		}
		if (i >= 10) {
			glTranslatef(i-10, 0, 0);
			glRotatef(-90,0,1,0);
		}
		glBegin(GL_LINES);
			glColor3f(1,1,1);
			glLineWidth(1);
			glVertex3f(0,-0.1,0);
			glVertex3f(9,-0.1,0);
		glEnd();
		glPopMatrix();
	}
}

void addQuad() {
	Q[0].state++;
	if (Q[0].state > 4) { Q[0].state = 1; }
	int st = Q[0].state;
	if (st == 1) {
		Q[0].total++;
		cn = Q[0].total;
	}
	if (st == 1) {
		Q[cn].x1 = cx;
		Q[cn].y1 = cy;
		Q[cn].z1 = cz;
	}
	if (st == 1 || st == 2) {
		Q[cn].x2 = cx;
		Q[cn].y2 = cy;
		Q[cn].z2 = cz;
	}
	if (st == 1 || st == 2 || st == 3) {
		Q[cn].x3 = cx;
		Q[cn].y3 = cy;
		Q[cn].z3 = cz;
	}
	if (st == 1 || st == 2 || st == 3 || st == 4) {
		Q[cn].x4 = cx;
		Q[cn].y4 = cy;
		Q[cn].z4 = cz;
	}
}

void drawQuad() {
	int i;
	for (int i = 0; i < Q[0].total + 1; i++) {
		glBegin(GL_QUADS);
		glColor3f(Q[i].r, Q[i].g, Q[i].b);
		glVertex3f(Q[i].x1, Q[i].y1, Q[i].z1);
		glVertex3f(Q[i].x2, Q[i].y2, Q[i].z2);
		glVertex3f(Q[i].x3, Q[i].y3, Q[i].z3);
		glVertex3f(Q[i].x4, Q[i].y4, Q[i].z4);
		glEnd();
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-25, 2, -70);					//set perspective
	glRotatef(30, 1.0f, 1.0f, 0.0f);			//rotate angle by angleTri degree on all x,y,z axis
	glScalef(4,4,4);
	drawCube();
	drawGrid();
	drawQuad();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	//std::cout << "key pressed : "<<key;
	switch (key) {
	case 27:
		glutLeaveMainLoop();								//leave main loop and close window
		break;
	case 32:
		addQuad();								//leave main loop and close window
		break;
	case 'F':
	case 'f':
		if (bfScrn == false) {
			glutFullScreen();				//enable fullscreen
			bfScrn = true;	
		}
		else {
			glutLeaveFullScreen();			//disable fullscreen
			bfScrn = false;
		}
		break;
	case '8': cz -= 1; //backword
		break;
	case '2': cz += 1; //forword
		break;
	case '4' : cx -= 1; //left
		break;
	case '6' : cx += 1; //right
		break;
	case 'd':
	case 'D' : cy -= 1; //down
		break;
	case 'u':
	case 'U' : cy += 1; //up
		break;
	case 'r':
	case 'R':
			Q[cn].r=1;//set color to red
			Q[cn].g = 0;
			Q[cn].b = 0;
		break;
	case 'g':
	case 'G':
		Q[cn].r = 0;
		Q[cn].g = 1;//set color to green
		Q[cn].b = 0;
		break;
	case 'b':
	case 'B':
		Q[cn].r = 0;
		Q[cn].g = 0;
		Q[cn].b = 1;//set color to blue
		break;
	case 'c':
	case 'C': Q[0].total = 0;
		break;
	}
	glutPostRedisplay();
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
}

void uninitialize(void) {
	//Do nothing...
}