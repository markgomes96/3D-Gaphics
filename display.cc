#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"

void display( void )
{
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

	//***transformations***
	
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
		camerapos = startcampos;
		currentrotate.x = 0.0;
		currentrotate.y = 0.0;
		currentrotate.z = 0.0;
		animState = playanim;
	}

	if(animState == hardresetanim)	//reset house / camera
	{
		//***add in reset to camera perspective
		camerapos = startcampos;
		currentrotate.x = 0.0;
		currentrotate.y = 0.0;
		currentrotate.z = 0.0;
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

	//***Drawing house, axes, sign to screen***

	if(displayAxes)
		drawAxes(20);

	drawHouse(&faces[0], (int)fillHouse);

	if(displayRoofSign)
	{
		char *charString = (char*)malloc(40*sizeof(char));		//define memory to hold string
		sprintf(charString, "Hello World!");		//put data in string
		drawString(faces[6].point[2].x, faces[6].point[2].y, faces[6].point[2].z, charString);	//place string on display
		free(charString);	//clean up
	}

	glutSwapBuffers(); 				//swap buffers to draw new frame
}

void PipeLine(vertex *vp, int vc)	//vp - pointer to temp array; vc - number of vertices
{
	// this routine will run the graphics transformation pipeline
	float transformMatrix[16];		//set up the tranformation matrix and pointer
	float *tm;
	tm = &transformMatrix[0];

	buildRotateX( currentrotate.x, tm );			//perform rotation operation around x-axis
	applyTransformation( vp, vc, tm );

	buildRotateY( currentrotate.y, tm );			//perform rotation operation around y-axis
	applyTransformation( vp, vc, tm );

	buildRotateZ( currentrotate.z, tm );			//perform rotation operation around z-axis
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

void drawString(float x, float y, float z, char* text)
{
	double angle = (atan(3.0/5.0) * 180) / M_PI;

	glPushMatrix();
	
	glTranslatef(x, y, z);
	
	glRotatef(180.0 - currentrotate.z, 0.0, 0.0, 1.0);
	glRotatef(-currentrotate.y, 0.0, 1.0, 0.0);
	glRotatef(angle - currentrotate.x, 1.0, 0.0, 0.0);   	
	
	glScalef(0.011, 0.038, 0.012);

	for( char* p = text; *p; p++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	}

	glPopMatrix();
}
