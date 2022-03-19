#pragma once
#include "geodatatools_global.h"
#include "qgsvectorlayer.h"

#include "qstring.h"
#include <vector>
#include <string>
#include <map>
using namespace std;


#include "gme_vector2.h"


class GEODATATOOLS_EXPORT BaseRegion
{
public:
	BaseRegion(const string& path);
	BaseRegion(const QString& path);
	virtual~BaseRegion();

	//取得显示名称
	virtual void setDisplayName(const string& dispName);
	virtual const string& getDisplayName(void) const;

	// 获得Region个数
	virtual unsigned short getNumRegion(void) const;
	// 根据索引号得到Region指针
	virtual vector<gme_vector2d>* getRegion(unsigned short index);
	//得到所有的Region范围
	virtual map<int, vector<gme_vector2d>>* getAllRegion(void);

	//获取范围的图层
	virtual QgsVectorLayer* getVectorLayer();


protected:
	string				mDisplayName;
	long				mFeatureCount;
	QgsVectorLayer*		mVectorRegion;
	map<int, vector<gme_vector2d>> mAllRegion;
};

