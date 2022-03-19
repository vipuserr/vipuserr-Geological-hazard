#pragma once
#include "G2DToolDef.h"
#include "geo2dtools_global.h"

#include "OGBasDef.h"
#include <string>
#include <vector>
using namespace std;
using namespace Smart3dMap;

long GEO2DTOOLS_EXPORT _GetLineNameList(vector<string> &vecLinName, BOOL flag=TRUE);
double GEO2DTOOLS_EXPORT  _GetLinBufR();
long GEO2DTOOLS_EXPORT _GetLineDotByName(LPCTSTR lpszLinName, vector<gme_vector2d> &vecLineDots);

