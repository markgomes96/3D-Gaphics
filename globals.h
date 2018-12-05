#ifndef INC_GLOBALS_H
#define INC_GLOBALS_H

#include "structs.h"
#include "includes.h"

using namespace std;

extern vector<vertex> vertexlist;
extern vector<triangle> trianglelist;

extern float deltaspin;
extern float spin;
extern vector3D deltarotate;
extern vector3D currentrotate;

extern vector3D startcampos;
extern vector3D camerapos;
extern vector3D targetpos;

extern DisplayState displayState;
extern AnimState animState;

extern bool fillHouse;
extern bool displayAxes;
extern bool displayRoofSign;

extern double perspParm[];
extern double custParm[];

extern bool dragmode;
extern bool editmode;
extern string input;
extern int editindex;
extern float dragstarty;

#endif
