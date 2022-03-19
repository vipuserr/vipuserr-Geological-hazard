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
		//ȡ����ʾ����
		virtual void setDisplayName(const string& dispName);
		virtual const string& getDisplayName(void) const;

		// ���Region����
		virtual unsigned short getNumRegions(void) const;
		virtual unsigned short getNumLins(void) const;

		//����/��ȡ �����ֶ���
		virtual void setCodeFldName(string fldName);
		virtual void getCodeFldName(string& fldName);

		// ȡ����index����
		virtual void getLine(vector<gme_vector2d>& lin, unsigned short index);
		//ȡ����index�����е��׸������
		virtual void getRegion(vector<gme_vector2d>&poly, unsigned short index);
		//ȡ����index����
		virtual void getRegion(PolyRef& poly, unsigned short index);

		//�õ����е���
		virtual void getAllLins(vector<vector<gme_vector2d>>& lins);
		//�õ����е����е�һ������μ���
		virtual void getAllRegions(vector<vector<gme_vector2d>>& all1stPolys);
		//�õ����е�����
		virtual void getAllRegions(vector<PolyRef>& polys);

		//ȡ��������ɫ
		virtual void getObjClr(gme_color4& rgbClr, unsigned short index);
		virtual void getObjClrs(vector<gme_color4>& rgbClrs);

		virtual void getObjCode(string fldName, long idx, string& codeVal);
		virtual void getObjCodes(string fldName, vector<string>& codeVals);


	protected:
		string							mDisplayName; //��ʾ����
		string							mCodeFldName; //��ʾ����

		vector<vector<gme_vector2d>>	mAllLines; //���е���

		vector<PolyRef>					mAllPolys; //���е�����
		vector<vector<gme_vector2d>>	mAll1stPolys; //���е����е�һ������μ���
		vector<string>					mObjCodes; //��������б�
		vector<gme_color4>				mObjClrs; //������ɫ�б�
	};

}
