#include "includes.h"
#include "constants.h"
#include "prototypes.h"

#include "globals.h"

void mouse( int button, int state, int x, int y )
{ 	
	switch (button) 
	{
		int region = checkRegion(x, y);
	
        	case GLUT_LEFT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
				if(region == 0)			//click in left region
				{
					if(deltarotate.y > -10.0)		//max CCW spin at 10 degrees per iteration
					{
						deltarotate.y += -0.5;		//decrement rotation in y-axis
		        			glutIdleFunc(spinDisplay);
					}
					
				}
				else if(region == 1)		//click in right region
				{
					if(deltarotate.x > -10.0)		//max CCW spin at 10 degrees per iteration
					{
						deltarotate.x += -0.5;		//decrement rotation in x-axis
		        			glutIdleFunc(spinDisplay);
					}
				}
				else if(region == 2)		//click in bottom region 
				{
					if(deltarotate.z > -10.0)		//max CCW spin at 10 degrees per iteration
					{
						deltarotate.z += -0.5;		//decrement rotation in z-axis
		        			glutIdleFunc(spinDisplay);
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
						deltarotate.y += 0.5;		//increment rotation in y-axis
		        			glutIdleFunc(spinDisplay);
					}
					
				}
				else if(region == 1)		//click in right region
				{
					if(deltarotate.x < 10.0)		//max CW spin at 10 degrees per iteration
					{
						deltarotate.x += 0.5;		//increment rotation in x-axis
		        			glutIdleFunc(spinDisplay);
					}
				}
				else if(region == 2)		//click in bottom region 
				{
					if(deltarotate.z < 10.0)		//max CW spin at 10 degrees per iteration
					{
						deltarotate.z += 0.5;		//increment rotation in z-axis
		        			glutIdleFunc(spinDisplay);
					}
				}
				animState = playanim;
		    	}
            	break;

        	default:
            	break;
    	}
}

int checkRegion(int x, int y)		//returns region code for left[0], right[1], bottom[2]
{
	vertex center = vertex(WINDOW_MAX_X/2, WINDOW_MAX_Y/2, 0, 0);

	if(x <= center.x)	//left screen
	{
		float divide = ( (center.y - 0.0) / (center.x - 0.0) ) * x;

		if(y > divide)
			return 0;
		else
			return 2;

	}
	else if(x > center.x)		//right screen
	{
		float divide = ( (0.0 - center.y) / (0.0 - center.x) ) * x;

		if(y > divide)
			return 0;
		else
			return 2;
	}

	return false;
}

void keyboard( unsigned char key, int x, int y )
{ 
	/*HANDLED BY DROP DOWN MENU
	if ( key == 'f' || key == 'F')		// Fill the polygon in with tesselation
	{
		displayState = tessfill;
	}	
	if ( key == 't' || key == 'T')		// Display outlines of triangles used in tesselation
	{
		displayState = tesstriangle;
	}
	if ( key == 'l' || key == 'L')		// Return polyon to an outline
	{
		displayState = outline;
	}
	*/

	
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
	switch(key)		//moves the center point 5 pixels in inputed direction
	{
		case GLUT_KEY_UP:
			if(resizeBoundMode)
			{
				viewportMinY -= 5;
				viewportMaxY += 5;
			}
			else
			{
				cp.y += 5;
			}
			break;
			
		case GLUT_KEY_DOWN:
			if(resizeBoundMode)
			{
				viewportMinY += 5;
				viewportMaxY -= 5;
			}
			else
			{
				cp.y -= 5;
			}
			break;
			
		case GLUT_KEY_LEFT:
			if(resizeBoundMode)
			{
				viewportMinX += 5;
				viewportMaxX -= 5;
			}
			else
			{
				cp.x -= 5;
			}
			break;
			
		case GLUT_KEY_RIGHT:
			if(resizeBoundMode)
			{
				viewportMinX -= 5;
				viewportMaxX += 5;
			}
			else
			{
				cp.x += 5;
			}
			break;
	}
	glutPostRedisplay();
}
