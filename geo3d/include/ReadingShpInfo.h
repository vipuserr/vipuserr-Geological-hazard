#pragma once


#include "geodatatools_global.h"
#include "BaseRegion.h"


class GEODATATOOLS_EXPORT ReadingShpInfo : public BaseRegion
{
public:
	ReadingShpInfo(const string& path);
	ReadingShpInfo(const QString& path);
	virtual~ReadingShpInfo();


private:
	void ReadingRegion(void);

private:

};
