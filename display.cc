#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"

void display( void )
{
	if(displayState == Custom)	//constantly reshape window if in Custom display state
		reshape(800, 800);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);		//set up 2D viewing
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_MAX_X, 0.0, WINDOW_MAX_Y);
	glMatrixMode(GL_MODELVIEW);

	drawCustomViewInput();		//draw custom view input

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity ();             /* clear the matrix */
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);		//convert to 3D
	glPushMatrix();
	gluLookAt (camerapos.x, camerapos.y, camerapos.z, targetpos.x, targetpos.y, targetpos.z, 0.0, 0.0, 1.0);

	struct box faces[7];		//define house points
	defineHouse(&faces[0]);

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

	if(displayAxes)			//draw axes
		drawAxes(20);

	drawHouse(&faces[0], (int)fillHouse);		//draw house

	if(displayRoofSign)			//draw roof sign
	{
		glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);
		char *charString = (char*)malloc(40*sizeof(char));		//define memory to hold string
		sprintf(charString, "Hello World!");		//put data in string
		drawStringStroke(faces[6].point[2].x + 0.001, faces[6].point[2].y + 0.001, faces[6].point[2].z + 0.001, charString);	//place string on display
		free(charString);	//clean up
		glLineWidth(1.0);
	}
	glPopMatrix();	

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

void drawCustomViewInput()
{
	const char* perspHeaders[] = {"FOVY", "ASPECT", "ZNEAR", "ZFAR"};
	float sx = 450.0;
	float sy = 750.0;	

	char *charString = (char*)malloc(40*sizeof(char));

	if(displayState == Persp)	
		sprintf(charString, "Perspective");
	else if(displayState == Ortho)
		sprintf(charString, "Orthographic");
	else if(displayState == Custom)
		sprintf(charString, "Custom");

	drawStringBitmap( sx - 120, sy , charString );
	free(charString);

	for(int i = 0; i < 4; i++)		//draw parameter titles
	{
		char *charString = (char*)malloc(40*sizeof(char));		
		sprintf(charString, (char*)perspHeaders[i]);
		drawStringBitmap( sx + (i * 80), sy , charString );
		free(charString);
	}

	for(int i = 0; i < 4; i++)		//draw parameter input boxes
	{
		char *charString = (char*)malloc(40*sizeof(char));

		if(displayState == Persp || displayState == Ortho)	
			sprintf(charString, "%.4f", perspParm[i]);
		else if(displayState == Custom)
			sprintf(charString, "%.4f", custParm[i]);

		drawStringBitmap( sx + (i * 80), sy - 25 , charString );
		free(charString);
	}
}

void drawStringBitmap(float x, float y, char* text)
{
	const char *c;
	glRasterPos2f(x, y);
	for(c = text; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
}

void drawStringStroke(float x, float y, float z, char* text)
{
	double angle = (atan(3.0/5.0) * 180) / M_PI;

	glPushMatrix();
	
	glTranslatef(x, y, z);
	
	glRotatef(180.0 - currentrotate.z, 0.0, 0.0, 1.0);
	glRotatef(-currentrotate.y, 0.0, 1.0, 0.0);
	glRotatef(angle - currentrotate.x, 1.0, 0.0, 0.0);   	
	
	glScalef(0.014, 0.039, 0.012);

	for( char* p = text; *p; p++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	}

	glPopMatrix();
}
