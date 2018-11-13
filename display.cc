#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"

void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT);		//clear the window

	glColor3f(0.0, 0.0, 0.0);
	glRecti(viewportMinX, viewportMinY, viewportMaxX, viewportMaxY);    //set viewport

	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity ();             /* clear the matrix */

	/*
	int vertCount = vertexlist.size();
	vertex templist[vertCount*2];			//create temp array of current vertexlist
	vertex *tmp;					//pointer to temp array
	tmp = &templist[0];
	for(int i = 0; i < (vertCount*2); i++)		//clear out array
	{
		templist[i].x = 0.0;
		templist[i].y = 0.0;
		templist[i].z = 0.0;
		templist[i].w = 0.0;
	}

	vector<vertex>::iterator it;
	int index = 0;
	for(it = vertexlist.begin(); it != vertexlist.end(); ++it)	//copy vertex points over to a temp array
	{
		templist[index].x = it -> x;
		templist[index].y = it -> y;
		templist[index].z = it -> z;
		templist[index].w = it -> w;
		index++;
	}

	if(animState == resetanim)	//reset transformation variables to default
	{ l
		deltaspin = 0.0;		
		spin = 0.0;
		scalarvect = vector3D(1.0, 1.0, 1.0);
		reflection = 1;
		animState = playanim;
	}

	PipeLine(tmp, vertCount);		//apply transformations	 

	vector<vertex> drawlist;
	drawlist.clear();
	int ind = 0;
	while(templist[ind].w == 1.0)
	{
		drawlist.push_back(templist[ind]);
		ind++;
	}
	*/

	struct box faces[6];

	defineHouse(&faces[0]);

	//gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt (6.0, 8.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawAxes(5);
	drawHouse(&faces[0]);

	glutSwapBuffers(); 				//swap buffers to draw new frame
}

void PipeLine(vertex *vp, int vc)	//vp - pointer to temp array; vc - number of vertices
{
	// this routine will run the graphics transformation pipeline
	float transformMatrix[16];		//set up the tranformation matrix and pointer
	float *tm;
	tm = &transformMatrix[0];

	buildTranslate( cp.x - startcp.x, cp.y - startcp.y, 0.0, tm);	//translate to new rotation point 
	applyTransformation( vp, vc, tm );

	buildTranslate( -cp.x, -cp.y, 0.0, tm);		//translate to origin 
	applyTransformation( vp, vc, tm );

	buildReflectVert( reflection, tm );		//perform the reflection operation
	applyTransformation( vp, vc, tm );

	buildRotateZ( spin, tm );			//perform the rotation operation
	applyTransformation( vp, vc, tm );

	buildScale( scalarvect, tm );			//perform the scaling operation
	applyTransformation( vp, vc, tm );

	buildTranslate( cp.x, cp.y, 0.0,  tm );		//translate back to point
	applyTransformation( vp, vc, tm );
}

void spinDisplay(void)
{
	if(animState != stopanim)
	{
		spin = spin + deltaspin;
		if (spin > 360.0)
		{ 
			spin = spin - 360.0;
		}
		glutPostRedisplay();
	}
}
