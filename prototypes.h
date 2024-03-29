#include "structs.h"

void display( void );			//display.cc
void PipeLine( vertex* , int );
void spinDisplay( void );
void drawCustomViewInput();
void drawStringBitmap( float , float , char* );
void drawStringStroke( float , float , float , char* );

void reshape ( int , int );		//reshape.cc

void drawAxes( int );			//drawAxis.cc

void defineHouse( box* );		//defineHouse.cc

void drawHouse( box*, int );		//drawHouse.cc

void applyTransformation( vertex* , int , float* );	//transmat.cc
void matrixVectorMult( int , float* , float* );
void buildTranslate( float , float , float , float* );
void buildRotateX( float , float* );
void buildRotateY( float , float* );
void buildRotateZ( float , float* );
void buildScale( vector3D , float* );
void buildReflectVert( int , float* );

void mouse( int , int , int , int );		//input.cc
void motion( int , int );
int checkRegion( int , int , int );
void keyboard( unsigned char , int , int );
void SpecialInput( int , int , int );
float vectorMagnitude( vector3D );
bool checkValidNumInput( unsigned char );

int main( int , char** );			//main.cc
