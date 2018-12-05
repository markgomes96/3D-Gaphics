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

vector3D startcampos = vector3D(35*(0.58), 35*(0.69), 35*(0.435));
vector3D camerapos;
vector3D targetpos = vector3D(0.0, 0.0, 0.0);

DisplayState displayState = Persp;		//states
AnimState animState = playanim;

bool fillHouse = false;				//dropdown menu
bool displayAxes = false;
bool displayRoofSign = false;

double perspParm[] = {60.0, 1.0, 1.5, 761.0};
double custParm[] = {60.0, 1.0, 1.5, 761.0};

bool dragmode = false;
bool editmode = false;
string input = "";
int editindex = -1;
float dragstarty = 0.0;

#endif
