#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <GL/glut.h>

#include <unistd.h>
using namespace std;

const float 
	white[] = {1, 1, 1, 1}, 
	red[]   = {1, 0, 0, 1}, 
	green[] = {0, 1, 0, 1}, 
	blue[]  = {0, 0, 1, 1}, 
	black[] = {0, 0, 0, 1}, 
	dark_red[]   = {.5, 0, 0, 1}, 
	dark_green[] = {0, .5, 0, 1}, 
	dark_blue[]  = {0, 0, .5, 1}, 
	light_red[]   = {1, 0.75, 0.75, 1}, 
	light_green[] = {0.75, 1, 0.75, 1}, 
	light_blue[]  = {0.75, 0.75, 1, 1};

size_t width=480, height=480, n;
float lower, upper;

vector<float> puntos;

void display();
void draw_puntos();
void wait_for_input();

void init();

int main(int argc, char **argv){
	cin >> n;
	puntos.resize(n);
	cin >> lower >> upper;
	glutInit(&argc, argv);
	init();
	glutMainLoop();
	return 0;
}

void init(){
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
	glutInitWindowSize(width,height); glutInitWindowPosition(50,50);
	glutCreateWindow("Graficador de puntos de colores");
	glutDisplayFunc(display);
	glutIdleFunc(wait_for_input);

	glClearColor( white[0], white[1], white[2], 1);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
	glMatrixMode(GL_PROJECTION); glOrtho(lower, upper, -1, 1, -1, 1);

	glPointSize(3);
	glColor3fv(black);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	draw_puntos();
	glutSwapBuffers();

	//usleep(1e5);
}

void wait_for_input(){
	if(not cin){
		glutIdleFunc(NULL);
		cin.clear();
		string s;
		while(getline(cin,s)) //el programa finalizo. se hace un bypass a la entrada
			cerr << s << endl;
		cerr << "Fin";
		glutPostRedisplay();
		return;
	}
	for(size_t K=0; K<n; ++K)
		cin>>puntos[K];
	glutPostRedisplay();
}


void draw_puntos(){
	glBegin(GL_POINTS);{
		for(size_t K=0; K<n; ++K)
			glVertex2f(puntos[K], 0);
	};glEnd();
}

