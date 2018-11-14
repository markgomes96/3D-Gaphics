#ifndef DRAWBOX
#define DRAWBOX

#include "includes.h"
#include "structs.h"
#include "prototypes.h"

void drawHouse( struct box *face )
{
    int i, j;

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();
    //glTranslatef(-2.0,0.0,0.0);

    for(j = 0; j < 7; j++)
    {

        glColor3f(face[j].color.red,
                  face[j].color.green,
                  face[j].color.blue);

        glBegin(GL_POLYGON);
        	for (i=0;i<5;i++)
        	{
            		glVertex3f(face[j].point[i].x,
				face[j].point[i].y,
				face[j].point[i].z);
		}
	glEnd();
    }

    glPopMatrix();
}

#endif
