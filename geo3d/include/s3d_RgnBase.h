#pragma once
#include "geo2dtools_global.h"
#include "qgsvectorlayer.h"

#include "s3d_GeomDefine.h"

#include "qstring.h"
#include <vector>
#include <string>
#include <map>
using namespace std;




#include "gme_vector2.h"

namespace Smart3dMap
{
	class GEO2DTOOLS_EXPORT s3d_RgnBase
	{
	public:
		s3d_RgnBase(const string& path, string fldName = "");
		virtual~s3d_RgnBase();

	public:
		//取得显示名称
		virtual void setDisplayName(const string& dispName);
		virtual const string& getDisplayName(void) const;

		// 获得Region个数
		virtual unsigned short getNumRegions(void) const;
		virtual unsigned short getNumLins(void) const;

		//设置/获取 索引字段名
		virtual void setCodeFldName(string fldName);
		virtual void getCodeFldName(string& fldName);

		// 取出第index条线
		virtual void getLine(vector<gme_vector2d>& lin, unsigned short index);
		//取出第index个区中的首个多边形
		virtual void getRegion(vector<gme_vector2d>&poly, unsigned short index);
		//取出第index个区
		virtual void getRegion(PolyRef& poly, unsigned short index);

		//得到所有的线
		virtual void getAllLins(vector<vector<gme_vector2d>>& lins);
		//得到所有的区中第一个多边形集合
		virtual void getAllRegions(vector<vector<gme_vector2d>>& all1stPolys);
		//得到所有的区域
		virtual void getAllRegions(vector<PolyRef>& polys);

		//取出对象颜色
		virtual void getObjClr(gme_color4& rgbClr, unsigned short index);
		virtual void getObjClrs(vector<gme_color4>& rgbClrs);

		virtual void getObjCode(string fldName, long idx, string& codeVal);
		virtual void getObjCodes(string fldName, vector<string>& codeVals);


	protected:
		string							mDisplayName; //显示名称
		string							mCodeFldName; //显示名称

		vector<vector<gme_vector2d>>	mAllLines; //所有的线

		vector<PolyRef>					mAllPolys; //所有的区域
		vector<vector<gme_vector2d>>	mAll1stPolys; //所有的区中第一个多边形集合
		vector<string>					mObjCodes; //对象编码列表
		vector<gme_color4>				mObjClrs; //对象颜色列表
	};

}
