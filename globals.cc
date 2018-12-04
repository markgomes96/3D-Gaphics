#ifndef INC_GLOBALS_CC
#define INC_GLOBALS_CC

#include "structs.h"
#include "includes.h"

using namespace std;

vector<vertex> vertexlist;
vector<triangle> trianglelist;

float deltaspin = 0.0;				//rotation
float spin = 0.0;

vector3D deltarotate = vector3D(0.0, 0.0, 0.0);
vector3D currentrotate = vector3D(0.0, 0.0, 0.0);

vector3D startcampos = vector3D(16.0, 19.0, 12.0);
vector3D camerapos;
vector3D targetpos = vector3D(0.0, 0.0, 2.5);

DisplayState displayState = Persp;		//states
AnimState animState = playanim;

bool fillHouse = false;				//dropdown menu
bool displayAxes = false;
bool displayRoofSign = false;

double perspParm[] = {60.0, 1.0, 1.5, 761.0};
double custParm[] = {60.0, 1.0, 1.5, 761.0};

bool editmode = false;
char input[15];
int editindex = -1;

#endif
