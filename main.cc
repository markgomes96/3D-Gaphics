// Developed by Mark Gomes
// 11/13/18

#include "includes.h"
#include "constants.h"
#include "globals.h"
#include "globals.cc"
#include "prototypes.h"

using namespace std;


int main(int argc, char** argv)
{	
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y); 		                // set pixel window
	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y); 		// place window top left on display
	glutCreateWindow("3D Graphics");	                        //window title

	glClearColor(0.0, 0.0, 0.0, 1.0);           //black background
	glColor3f(1.0, 0.0, 0.0);                   // draw in red
	glPointSize(1.0);
	glLineWidth(1.0);
	glShadeModel (GL_FLAT);

	glutMouseFunc(mouse);               //checks for user input
	glutKeyboardFunc(keyboard);	 	
	glutSpecialFunc(SpecialInput);
	glutDisplayFunc(display);		    //display everyframe 
	glutReshapeFunc(reshape);
	glutMainLoop();				        //enters event loop
}
