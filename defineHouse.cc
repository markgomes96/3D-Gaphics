#ifndef DEFINE_BOX
#define DEFINE_BOX

#include "includes.h"
#include "structs.h"
#include "prototypes.h"

void defineHouse( box *face )
{
	face[0].point[0].x = -1.0;	//bottom side
	face[0].point[0].y = -1.0;
	face[0].point[0].z =  0.0;
	face[0].point[0].w =  1.0;

	face[0].point[1].x = -1.0;
	face[0].point[1].y =  1.0;
	face[0].point[1].z =  0.0;
	face[0].point[1].w =  1.0;

	face[0].point[2].x =  1.0;
	face[0].point[2].y =  1.0;
	face[0].point[2].z =  0.0;
	face[0].point[2].w =  1.0;

	face[0].point[3].x =  1.0;
	face[0].point[3].y = -1.0;
	face[0].point[3].z =  0.0;
	face[0].point[3].w =  1.0;

	face[1].point[0].x = -1.0;	//left side
	face[1].point[0].y = -1.0;
	face[1].point[0].z =  0.0;
	face[1].point[0].w =  1.0;

	face[1].point[1].x = -1.0;
	face[1].point[1].y = -1.0;
	face[1].point[1].z =  1.0;
	face[1].point[1].w =  1.0;

	face[1].point[2].x =  1.0;
	face[1].point[2].y = -1.0;
	face[1].point[2].z =  1.0;
	face[1].point[2].w =  1.0;

	face[1].point[3].x =  1.0;
	face[1].point[3].y = -1.0;
	face[1].point[3].z =  0.0;
	face[1].point[3].w =  1.0;

	face[2].point[0].x = -1.0;	//right side
	face[2].point[0].y =  1.0;
	face[2].point[0].z =  0.0;
	face[2].point[0].w =  1.0;

	face[2].point[1].x = -1.0;
	face[2].point[1].y =  1.0;
	face[2].point[1].z =  1.0;
	face[2].point[1].w =  1.0;

	face[2].point[2].x =  1.0;
	face[2].point[2].y =  1.0;
	face[2].point[2].z =  1.0;
	face[2].point[2].w =  1.0;

	face[2].point[3].x =  1.0;
	face[2].point[3].y =  1.0;
	face[2].point[3].z =  0.0;
	face[2].point[3].w =  1.0;
	
	face[3].point[0].x = -1.0;	//back side
	face[3].point[0].y = -1.0;
	face[3].point[0].z =  0.0;
	face[3].point[0].w =  1.0;

	face[3].point[1].x = -1.0;
	face[3].point[1].y = -1.0;
	face[3].point[1].z =  1.0;
	face[3].point[1].w =  1.0;

	face[3].point[2].x = -1.0;
	face[3].point[2].y =  1.0;
	face[3].point[2].z =  1.0;
	face[3].point[2].w =  1.0;

	face[3].point[3].x = -1.0;
	face[3].point[3].y =  1.0;
	face[3].point[3].z =  0.0;
	face[3].point[3].w =  1.0;

	face[4].point[0].x =  1.0;	//front side
	face[4].point[0].y = -1.0;
	face[4].point[0].z =  0.0;
	face[4].point[0].w =  1.0;

	face[4].point[1].x =  1.0;
	face[4].point[1].y = -1.0;
	face[4].point[1].z =  1.0;
	face[4].point[1].w =  1.0;

	face[4].point[2].x =  1.0;
	face[4].point[2].y =  1.0;
	face[4].point[2].z =  1.0;
	face[4].point[2].w =  1.0;

	face[4].point[3].x =  1.0;
	face[4].point[3].y =  1.0;
	face[4].point[3].z =  0.0;
	face[4].point[3].w =  1.0;

	face[5].point[0].x = -1.0;	//top side
	face[5].point[0].y = -1.0;
	face[5].point[0].z =  1.0;
	face[5].point[0].w =  1.0;

	face[5].point[1].x = -1.0;
	face[5].point[1].y =  1.0;
	face[5].point[1].z =  1.0;
	face[5].point[1].w =  1.0;

	face[5].point[2].x =  1.0;
	face[5].point[2].y =  1.0;
	face[5].point[2].z =  1.0;
	face[5].point[2].w =  1.0;

	face[5].point[3].x =  1.0;
	face[5].point[3].y = -1.0;
	face[5].point[3].z =  1.0;
	face[5].point[3].w =  1.0;

	face[0].color.red   = 1.0;	//define the colors
	face[0].color.green = 0.0;
	face[0].color.blue  = 0.0;
	
	face[1].color.red   = 0.0;
	face[1].color.green = 1.0;
	face[1].color.blue  = 0.0;
	
	face[2].color.red   = 0.0;
	face[2].color.green = 0.0;
	face[2].color.blue  = 1.0;

	face[3].color.red   = 1.0;
	face[3].color.green = 1.0;
	face[3].color.blue  = 0.0;

	face[4].color.red   = 1.0;
	face[4].color.green = 0.0;
	face[4].color.blue  = 1.0;

	face[5].color.red   = 0.0;
	face[5].color.green = 1.0;
	face[5].color.blue  = 1.0;
	
}

#endif
