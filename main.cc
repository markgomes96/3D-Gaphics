// Developed by Mark Gomes
// 11/13/18

#include "includes.h"
#include "constants.h"
#include "globals.h"
#include "globals.cc"
#include "prototypes.h"

using namespace std;

void createMenu(void);
void menu(int value);

int main(int argc, char** argv)
{	
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);        //***step 3
	glutInitWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y); 		                // set pixel window
	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y); 		// place window top left on display
	glutCreateWindow("3D Graphics");	                        //window title

	glClearColor(0.0, 0.0, 0.0, 1.0);           //black background
	glColor3f(1.0, 0.0, 0.0);                   // draw in red
	glPointSize(1.0);
	glLineWidth(1.0);
	glShadeModel (GL_FLAT);

	camerapos = startcampos;

	createMenu();

	glutMouseFunc(mouse);               //checks for user input
	glutKeyboardFunc(keyboard);	 	
	glutSpecialFunc(SpecialInput);
	glutDisplayFunc(display);		    //display everyframe 
	glutReshapeFunc(reshape);
	glutIdleFunc(spinDisplay);
	glutMainLoop();				        //enters event loop
}

void createMenu(void)
{
	int panel1 = glutCreateMenu(menu);	//create a submenu
	glutAddMenuEntry("Perspective", 0);	//add sub menu entry
	glutAddMenuEntry("Orthgraphic", 1);
	glutAddMenuEntry("Custom", 2);
	
	int mainmenu = glutCreateMenu(menu);	//create the menu
 
	glutAddSubMenu("[Options] View Type", panel1);			//add panels to menu
	glutAddMenuEntry("[Toggle] Filled Surfaces", 3);
	glutAddMenuEntry("[Toggle] Axes", 4);
	glutAddMenuEntry("[Toggle] Roof Sign", 5);
	glutAddMenuEntry("Exit Program", 6);
 
	glutAttachMenu(GLUT_MIDDLE_BUTTON);	//activate with middle mouse button
}

void menu(int val)		//handles menu input
{
	switch(val)
	{
		case 0:
			displayState = Persp;
			reshape(800, 800);
		break;

		case 1:
			displayState = Ortho;
			reshape(800, 800);
		break;

		case 2:
			displayState = Custom;
			reshape(800, 800);
		break;

		case 3:
			if(fillHouse)
				fillHouse = false;
			else
				fillHouse = true;
		break;

		case 4:
			if(displayAxes)
				displayAxes = false;
			else
				displayAxes = true;
		break;

		case 5:
			if(displayRoofSign)
				displayRoofSign = false;
			else
				displayRoofSign = true;
		break;

		case 6:
			exit(0);
		break;

		default:
		break;		
	}
 
	glutPostRedisplay();
}
