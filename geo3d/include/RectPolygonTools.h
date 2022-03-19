#pragma once
#include "geodatatools_global.h"
#include "OGMessageListener.h"
#include "G2DToolDef.h"

using namespace Smart3dMap;
using namespace std;
class GEODATATOOLS_EXPORT RectPolygonTools:public  Smart3dMap::COGListener
{
public:
	//工具索引(true表示矩形，fasle表示多边形)
	//RectPolygonTools(const short& index);
	RectPolygonTools(const bool& index, Smart3dMap::COGListener* listener);
	~RectPolygonTools();
	//得到选择范围
	void getThreeDimPointSets(vector<gme_vector3d>&);
	void getTwoDimPointSets(vector<gme_vector2d>&);
	void getRegDots(RegDots&);
	void getBox(G2D_RECT&);
	long OnMessagePro(long nMsg, __int64 wParam, __int64 lParam);
private:
	void initRectSelectTool();//初始化矩形工具
	void initPolygonSelectTool();//初始化多边形工具
	void registerIntMsg();
	G2DToolParam mToolParam; //创建参数
	int          mSelectTool;//判断选择工具，true为矩形，false为多边形
	vector<gme_vector3d>	mHole3dDots;//建模范围
	vector<gme_vector2d>	mHole2dDots;//建模范围
	RegDots					mHoleRgnDots;//建模范围
	G2D_RECT				mHoleBox;
	Smart3dMap::COGListener* mlistener;
};
