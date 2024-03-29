#ifndef STRUCTS
#define STRUCTS

enum DisplayState { Persp, Ortho, Custom };
enum AnimState { playanim, stopanim, resetanim, hardresetanim};

typedef struct vertex 
{ 
	float x;
	float y;
	float z;
	float w;

	vertex()
	{}

	vertex(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
} vertex;

typedef struct colortype
{
	float red;
	float green;
	float blue;
    
	colortype()
	{};

	colortype(float _red, float _green, float _blue)
	{
		red = _red;
		green = _green;
		blue = _blue;
	}
} colortype;

typedef struct box 
{
	vertex point[5];
	colortype color;	
} box;

typedef struct vector3D		//stores data for a 3D vector used for calcualtions
{
	float x;
	float y;
	float z;

	vector3D()
	{}

	vector3D(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
} vector3D;

typedef struct triangle		//stores vertexes for a triangle used for tesselation
{
	vertex v1;
	vertex v2;
	vertex v3;

	triangle()
	{}

	triangle(vertex _v1, vertex _v2, vertex _v3)
	{
		v1 = _v1;
		v2 = _v2;
		v3 = _v3;
	}
} triangle;

#endif
