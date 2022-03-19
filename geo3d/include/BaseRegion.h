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

	//ȡ����ʾ����
	virtual void setDisplayName(const string& dispName);
	virtual const string& getDisplayName(void) const;

	// ���Region����
	virtual unsigned short getNumRegion(void) const;
	// ���������ŵõ�Regionָ��
	virtual vector<gme_vector2d>* getRegion(unsigned short index);
	//�õ����е�Region��Χ
	virtual map<int, vector<gme_vector2d>>* getAllRegion(void);

	//��ȡ��Χ��ͼ��
	virtual QgsVectorLayer* getVectorLayer();


protected:
	string				mDisplayName;
	long				mFeatureCount;
	QgsVectorLayer*		mVectorRegion;
	map<int, vector<gme_vector2d>> mAllRegion;
};

