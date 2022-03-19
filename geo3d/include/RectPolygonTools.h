#pragma once
#include "geodatatools_global.h"
#include "OGMessageListener.h"
#include "G2DToolDef.h"

using namespace Smart3dMap;
using namespace std;
class GEODATATOOLS_EXPORT RectPolygonTools:public  Smart3dMap::COGListener
{
public:
	//��������(true��ʾ���Σ�fasle��ʾ�����)
	//RectPolygonTools(const short& index);
	RectPolygonTools(const bool& index, Smart3dMap::COGListener* listener);
	~RectPolygonTools();
	//�õ�ѡ��Χ
	void getThreeDimPointSets(vector<gme_vector3d>&);
	void getTwoDimPointSets(vector<gme_vector2d>&);
	void getRegDots(RegDots&);
	void getBox(G2D_RECT&);
	long OnMessagePro(long nMsg, __int64 wParam, __int64 lParam);
private:
	void initRectSelectTool();//��ʼ�����ι���
	void initPolygonSelectTool();//��ʼ������ι���
	void registerIntMsg();
	G2DToolParam mToolParam; //��������
	int          mSelectTool;//�ж�ѡ�񹤾ߣ�trueΪ���Σ�falseΪ�����
	vector<gme_vector3d>	mHole3dDots;//��ģ��Χ
	vector<gme_vector2d>	mHole2dDots;//��ģ��Χ
	RegDots					mHoleRgnDots;//��ģ��Χ
	G2D_RECT				mHoleBox;
	Smart3dMap::COGListener* mlistener;
};
