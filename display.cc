#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"

void display( void )
{
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

	struct box faces[7];

	defineHouse(&faces[0]);

	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity ();             /* clear the matrix */

	//gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt (camerapos.x, camerapos.y, camerapos.z, targetpos.x, targetpos.y, targetpos.z, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);			//set color to white
	//glRecti(VIEWPORT_MIN_X, VIEWPORT_MIN_Y, VIEWPORT_MAX_X, VIEWPORT_MAX_Y);    //set viewport

	//***start of transformations
	//***transfer all vertices from faces to temp and transfer it back
	
	int vertCount = 7 * 5;		//number of faces * number of vertices
	vertex templist[vertCount];			//create temp array of current vertexlist
	vertex *tmp;					//pointer to temp array
	tmp = &templist[0];
	for(int i = 0; i < vertCount; i++)		//clear out array
	{
		templist[i].x = 0.0;
		templist[i].y = 0.0;
		templist[i].z = 0.0;
		templist[i].w = 0.0;
	}

	int index = 0;
	for(int i = 0; i < 7; i++)	//copy house points over to a temp array
	{
		for(int j = 0; j < 5; j++)
		{
			templist[index].x = faces[i].point[j].x;
			templist[index].y = faces[i].point[j].y;
			templist[index].z = faces[i].point[j].z;
			templist[index].w = faces[i].point[j].w;

			index++;
		}
	}
	

	if(animState == stopanim)	//stop rotating animation
	{
		deltarotate.x = 0;
		deltarotate.y = 0;
		deltarotate.z = 0;
		animState = playanim;
	}

	if(animState == resetanim)	//reset house to original position / size
	{
		//***add in stuff
		camerapos = startcampos;
		animState = playanim;
	}

	if(animState == hardresetanim)	//reset house / camera
	{
		//***add in stuff
		animState = playanim;
	}

	PipeLine(tmp, vertCount);		//apply transformations	 

	index = 0;
	for(int i = 0; i < 7; i++)	//copy temp array back into faces
	{
		for(int j = 0; j < 5; j++)
		{
			faces[i].point[j].x = templist[index].x;
			faces[i].point[j].y = templist[index].y;
			faces[i].point[j].z = templist[index].z;
			faces[i].point[j].w = templist[index].w;

			index++;
		}
	}

	//***end of transformations

	drawAxes(20);
	drawHouse(&faces[0]);

	glutSwapBuffers(); 				//swap buffers to draw new frame
}

void PipeLine(vertex *vp, int vc)	//vp - pointer to temp array; vc - number of vertices
{
	// this routine will run the graphics transformation pipeline
	float transformMatrix[16];		//set up the tranformation matrix and pointer
	float *tm;
	tm = &transformMatrix[0];

	//buildTranslate( cp.x - startcp.x, cp.y - startcp.y, 0.0, tm);	//translate to new rotation point 
	//applyTransformation( vp, vc, tm );

	buildTranslate( -cp.x, -cp.y, -cp.z, tm);		//translate to origin 
	applyTransformation( vp, vc, tm );

	//buildReflectVert( reflection, tm );		//perform the reflection operation
	//applyTransformation( vp, vc, tm );

	buildRotateX( currentrotate.x, tm );			//perform rotation operation around x-axis
	applyTransformation( vp, vc, tm );

	buildRotateY( currentrotate.y, tm );			//perform rotation operation around y-axis
	applyTransformation( vp, vc, tm );

	buildRotateZ( currentrotate.z, tm );			//perform rotation operation around z-axis
	applyTransformation( vp, vc, tm );

	//buildScale( scalarvect, tm );			//perform the scaling operation
	//applyTransformation( vp, vc, tm );

	buildTranslate( cp.x, cp.y, cp.z,  tm );		//translate back to point
	applyTransformation( vp, vc, tm );
}

void spinDisplay(void)
{
	if(animState != stopanim)
	{
		currentrotate.x += deltarotate.x;
		currentrotate.y += deltarotate.y;
		currentrotate.z += deltarotate.z;

		if(currentrotate.x > 360)
			currentrotate.x -= 360.0;

		if(currentrotate.y > 360)
			currentrotate.y -= 360.0;

		if(currentrotate.z > 360)
			currentrotate.z -= 360.0;

		glutPostRedisplay();
	}
}
