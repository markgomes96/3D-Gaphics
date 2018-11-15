#include "structs.h"

void display( void );			//display.cc
void PipeLine( vertex* , int );
void spinDisplay(void);

void reshape ( int , int );		//reshape.cc

void drawAxes( int );			//drawAxis.cc

void defineHouse( box* );		//defineHouse.cc

void drawHouse( struct box* );		//drawHouse.cc

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

int main( int , char** );			//main.cc