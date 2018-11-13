#include "structs.h"

void display( void );				//display.cc
void PipeLine( vertex* , int );
void spinDisplay(void);

void applyTransformation( vertex* , int , float* );	//transmat.cc
void matrixVectorMult( int , float* , float* );
void buildTranslate( float , float , float , float* );
void buildRotateZ( float , float* );
void buildScale( vector3D , float* );
void buildReflectVert( int , float* );

void mouse( int , int , int , int );		//input.cc
bool checkBounds( int , int );
void keyboard( unsigned char , int , int );
void SpecialInput( int , int , int );

void clipPolygon( vertex*, int , vertex* , int );		//clipping.cc
vertex getLineIntersection( vertex , vertex , vertex , vertex );
bool pointWithinLineBounds( vertex , vertex , vertex );


void tessellate( vertex*, int );		//tessellate.cc
bool isSamePoint( vertex , vertex );
bool isLineOnBounds( vertex , vertex );
float vectorAngle( vertex , vertex , vertex );
bool checkIntersection( vertex , vertex , vertex , vertex );
bool pointWithinBounds(vertex , vertex , vertex , vertex );
float dotProduct( vector3D , vector3D );
float vectorMagnitude( vector3D );
vector3D crossProduct( vector3D , vector3D );

int main( int , char** );			//main.cc
