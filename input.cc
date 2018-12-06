#include "includes.h"
#include "constants.h"
#include "prototypes.h"

#include "globals.h"

void mouse( int button, int state, int x, int y )
{ 	
	int region = checkRegion(x, WINDOW_MAX_Y - y, state);

	switch (button) 
	{
        	case GLUT_LEFT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
				if(region == 0)			//click in left region
				{
					if(deltarotate.y > -10.0)		//max CCW spin at 10 degrees per iteration
					{
						deltarotate.y += -0.01;		//decrement rotation in y-axis
					}
					
				}
				else if(region == 1)		//click in right region
				{
					if(deltarotate.x > -10.0)		//max CCW spin at 10 degrees per iteration
					{
						deltarotate.x += -0.01;		//decrement rotation in x-axis
					}
				}
				else if(region == 2)		//click in bottom region 
				{
					if(deltarotate.z > -10.0)		//max CCW spin at 10 degrees per iteration
					{
						deltarotate.z += -0.01;		//decrement rotation in z-axis
					}
				}
				animState = playanim;
		    	}
            	break;

        	case GLUT_RIGHT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
				if(region == 0)			//click in left region
				{
					if(deltarotate.y < 10.0)		//max CW spin at 10 degrees per iteration
					{
						deltarotate.y += 0.01;		//increment rotation in y-axis
					}
				}
				else if(region == 1)		//click in right region
				{
					if(deltarotate.x < 10.0)		//max CW spin at 10 degrees per iteration
					{
						deltarotate.x += 0.01;		//increment rotation in x-axis
					}
				}
				else if(region == 2)		//click in bottom region 
				{
					if(deltarotate.z < 10.0)		//max CW spin at 10 degrees per iteration
					{
						deltarotate.z += 0.01;		//increment rotation in z-axis
					}
				}
				animState = playanim;
		    	}
            	break;

        	default:
            	break;
    	}

	glutIdleFunc(spinDisplay);
}

void motion(int x, int y)
{
	float screeny = (float)(WINDOW_MAX_Y - y);

	if(dragmode && screeny > 0)
	{
		if(screeny - dragstarty > 0)
			custParm[editindex] += 1;
		else if(screeny - dragstarty < 0)
			custParm[editindex] -= 1;
	}
	dragstarty = screeny;
}

int checkRegion(int x, int y, int state)		//returns region code for left[0], right[1], bottom[2]
{
	if(dragmode)
		dragmode = false;

	vertex center = vertex(WINDOW_MAX_X/2, WINDOW_MAX_Y/2, 0, 0);
	editmode = false;	//if you click anywhere else reset editmode
	if(x > 400 && y > 700)	//buffer zone
	{
		if(displayState == Custom)	//only edit when in Custom view
		{
			int count = 0;
			for(int i = 440; i < 780; i = i + 85)
			{
				if(x > i && x < (i+80) && y > 715 && y < 745)	//check if click was inside cell
				{
					if(state == 0 && !dragmode)
					{
						dragmode = true;
						editindex = count;
						dragstarty = y;
					}
					else if(state == 1)
					{
						editmode = true;
						editindex = count;
					}
				}
				count++;
			}
		}
	}
	else
	{
		if(x <= center.x)	//left screen
		{
			float divide = ( (center.y - 0.0) / (center.x - 0.0) ) * x;

			if(y > divide)
			{
				return 0; 
			}
			else
			{
				return 2; 
			}

		}
		else if(x > center.x)		//right screen
		{
			float divide = WINDOW_MAX_Y + (((0.0 - WINDOW_MAX_Y) / (WINDOW_MAX_X - 0.0)) * x);

			if(y > divide)
			{
				return 1; 
			}
			else
			{
				return 2; 
			}
		}
	}

	return -10;
}

void keyboard( unsigned char key, int x, int y )
{ 	
	if(editmode)
	{
		if (checkValidNumInput(key))
		{
			input += key;
		}
		else if(int(key) == 13 && !input.empty())
		{
			custParm[editindex] = stod(input);
			input.clear();
			editmode = false;
		}
	}

	if ( key == 's' || key == 'S')		//stops any animations
	{
		animState = stopanim;
	}
	if ( key == 'r')		//return house to original position and size
	{
		animState = resetanim;
	}
	if ( key == 'R')		//reset house -> original position / size; reset camera -> original position / perspective
	{
		animState = hardresetanim;
	}
	if ( key == 'q' || key == 'Q') 		//exit the program
	{
		printf("FARWELL, POWERING OFFFF...\n");
		exit(0);
	}
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{
	float magnitude = vectorMagnitude(vector3D(targetpos.x - camerapos.x, targetpos.y - camerapos.y, targetpos.z - camerapos.z));
	switch(key)		//moves the center point 5 pixels in inputed direction
	{
		case GLUT_KEY_PAGE_UP:
			if(magnitude > 3.0)
			{
				camerapos.x -= ((camerapos.x / magnitude) * 0.8);
				camerapos.y -= ((camerapos.y / magnitude) * 0.8);
				camerapos.z -= ((camerapos.z / magnitude) * 0.8);
				perspParm[3] = pow(vectorMagnitude(camerapos),2);	//adjust far value
				custParm[3] = pow(vectorMagnitude(camerapos),2);
			}
		break;
			
		case GLUT_KEY_PAGE_DOWN:
			camerapos.x += ((camerapos.x / magnitude) * 0.8);
			camerapos.y += ((camerapos.y / magnitude) * 0.8);
			camerapos.z += ((camerapos.z / magnitude) * 0.8);
			perspParm[3] = pow(vectorMagnitude(camerapos),2);	//adjust far value
			custParm[3] = pow(vectorMagnitude(camerapos),2);
		break;
	}
	glutPostRedisplay();
}

float vectorMagnitude(vector3D v1)
{
    float vm;
    vm  = sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));
    return vm;
}

bool checkValidNumInput(unsigned char c)
{
	if(isdigit(c) || c == '.')
		return true;
	else
		return false;
}

