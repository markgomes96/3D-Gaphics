#ifndef RESHAPE
#define RESHAPE

#include "includes.h"
#include "prototypes.h"
#include "globals.h"

void reshape (int w, int h)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();

	//glFrustum (-400.0, 400.0, -400.0, 400.0, 10.0, 30.0);
	//glFrustum (-1.0, 1.0, -1.0, 1.0, 6.0, 20.0);

	if(displayState == Persp)
	{
		gluPerspective(perspParm[0], perspParm[1], perspParm[2], perspParm[3]);
	}
	else if(displayState == Ortho)
	{
		glOrtho(-20.0, 20.0, -20.0, 20.0, 1.5, pow(vectorMagnitude(camerapos),2));
	}
	else if(displayState == Custom)
	{
		gluPerspective(custParm[0], custParm[1], custParm[2], custParm[3]);
	}

	glMatrixMode (GL_MODELVIEW);
}

#endif
