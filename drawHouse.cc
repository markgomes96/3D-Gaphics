/*
/*Base of code was copied from https://github.com/drlbs/perspective.git
*/

#ifndef DRAWBOX
#define DRAWBOX

#include "includes.h"
#include "structs.h"
#include "prototypes.h"

void drawHouse(struct box *face, int drawmode)		//0->wireframe, 1->filled
{
	int i, j;

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);

	glPushMatrix();

	for(j = 0; j < 7; j++)
	{

		glColor3f(face[j].color.red,
			  face[j].color.green,
			  face[j].color.blue);

		if(drawmode == 0)
		{
			glColor3f(0.0, 1.0, 0.0);

			glBegin( GL_LINE_LOOP );
				for (i=0;i<5;i++)
				{
		    			glVertex3f(face[j].point[i].x,
						face[j].point[i].y,
						face[j].point[i].z);
				}
			glEnd();
		}
		else if(drawmode == 1)
		{
			glColor3f(face[j].color.red,
			  face[j].color.green,
			  face[j].color.blue);

			glBegin( GL_POLYGON );
				for (i=0;i<5;i++)
				{
		    			glVertex3f(face[j].point[i].x,
						face[j].point[i].y,
						face[j].point[i].z);
				}
			glEnd();
		}
	}

	glPopMatrix();
}

#endif
