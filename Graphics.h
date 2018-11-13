#include "includes.h"
#include "structs.h"

using namespace std;

class Graphics 
{
     public:
	
	static void myglutInit( int argc, char** argv );
	static void myInit( void );
	
	static void drawCenterPoint(vertex v, color c);
	static void drawOutline( vector<vertex> vl, color c );
	static void drawTessPolygon(vector<triangle> tl, color c);
	static void drawTessTriangle(vector<triangle> tl, color c);

     private:
};

