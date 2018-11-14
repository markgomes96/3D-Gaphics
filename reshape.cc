#ifndef RESHAPE
#define RESHAPE

#include "includes.h"
#include "prototypes.h"

void reshape (int w, int h)
{
	glViewport (100, 100, 600, 600);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	//glFrustum (-400.0, 400.0, -400.0, 400.0, 10.0, 30.0);
	//glFrustum (-1.0, 1.0, -1.0, 1.0, 6, 20.0);
	gluPerspective(60.0, 1, 1.5, 40.0); 
	//glOrtho   (-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);

	glMatrixMode (GL_MODELVIEW);
}

#endif
