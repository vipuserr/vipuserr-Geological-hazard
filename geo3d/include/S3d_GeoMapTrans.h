#pragma once

#include <QList>
#include <map>
#include <vector>
using namespace std;

#include <s3d_KerGeoMapTransExp.h>
#include <s3d_GeomDefine.h>
#include <s3d_geomodelDef.h>


namespace Smart3dMap
{

	class _S3D_KER_GEOMAP_TRANS_EXP s3d_AttDataParse
	{
	public:
		s3d_AttDataParse();
		~s3d_AttDataParse();
	public:
		void SetDatas( QList<string>       &DcbmVec,
			           QList<gmeEntity*>   &EntyVec,
			           QList<gme_rect_3d*> &RectVec,
			           QList<gme_vector4d> &AttPnts,
			           QList<double>       &AttLens,
			           double              wMin );

		int  CalAttDatas(QList<QList<gme_vector4d>>   &AttTopAndBtm);
		bool bInRect2d(double dx, double dy, gme_rect_3d &RectObj);
		bool bInRect3d(double dx, double dy, double dz, gme_rect_3d &RectObj);
		int  GetSampleDatas(QList<gme_vector4d> &AttPnts, int segNum, QList<double> &segDatas);
		int  SplitData(gmeEntity *pEnty, vector<gme_vector4d> &ori, QList<gme_vector4d> &top, QList<gme_vector4d> &btm);

	public:
		double                m_wMin;
		QList<double>       * m_pAttLens;
		QList<gme_vector4d> * m_pAttPnts;
		QList<string>       * m_pDcbmVec;
		QList<gmeEntity*>   * m_pEntyVec;
		QList<gme_rect_3d*> * m_pRectVec;
	};
	
	//����������...
	struct  s3d_ParaInfo
	{
		string        stratName;   //�ز����ƣ����磺���ļ�ȫ������
		string        stratCode;   //�ز���루���磺Qh��
		string        stratLevel;  //�ز㼶����루���磺010200��
		int           nLayerIndex; //�ò��Ӧ�ı�׼�ز������ţ�0,1,2��...
		int           nCount;      //�ò��ظ����ֵĴ���
		string        strYtmc;     //��������
		string        Color;       //��ɫ
		string        strMapPath;  //��о��Ƭ
		int           nMapIdx;     //��������
		gme_vector3f  vScale;      //���ű���
		s3d_ParaInfo()
		{

		}
	};

	//��ά������  : ��¼��ά�������ݵĻ�����Ϣ
	class _S3D_KER_GEOMAP_TRANS_EXP s3d_SectSurfCls : public s3d_Ref
	{
	public:
		s3d_SectSurfCls();
		~s3d_SectSurfCls();
	public:
		//��ʼ��������2����λ��
		int SetAnchDatas(vector<s3d_AnchorPnt> &AnchList);
		int SetSect3dRegs(vector<gmeSurface*>  &SurfList, vector<s3d_ParaInfo> &SurfAtt);

		//��ȡ��λ�㡢��ά�桢����
		int GetAnchDatas(vector<s3d_AnchorPnt> &AnchList);
		int GetSect3dRegs(vector<gmeSurface*>  &SurfList, vector<s3d_ParaInfo> &SurfAtt);

	public:
		string                         m_secType;  //��������
		string                         m_sectNo;   //������
		vector<gme_rect_3d>            m_SurfRect; //���� ��ά��Rect
		vector<gmeSurface*>            m_SurfList; //���� ��ά�漯��
		vector<s3d_ParaInfo>           m_SurfAtt;  //���� �����Լ���
		vector<s3d_AnchorPnt>          m_AnchList; //���� ��λ�㼯��
	};

	// ��ά����һ���Ե�����
	// ��Խ��������棬�ڽ���״�
	// ���еز����һ���Ե�������
	class _S3D_KER_GEOMAP_TRANS_EXP s3d_SectAdjustCls
	{
	public:
		s3d_SectAdjustCls();
		~s3d_SectAdjustCls();
	public:
		// װ����������:������������...
		int SetTolerance(double esp); //�����ݲĬ��Ϊ1e-6
		int SetSectDatas(vector<s3d_SectSurfCls*> &secDatas);
	public:
		//���������obj֮���Ƿ��н����
		bool CheckBCross(s3d_SectSurfCls  &obj1, s3d_SectSurfCls &obj2, int &idx1, int &idx2);

		//�����е����棬�ڽ��洦����һ����ƽ���...
		int  AdjustAllsectDatas();
	public:
		//��ȡ�������...ͨ����λ�켣�ߡ��ָ��������ø��������
		int  GetSectGrid(vector<s3d_Pointer<s3d_Polygon>> &GridPoly);
		int  Get3dSurfByPolygon(s3d_Polygon *poly, vector<s3d_ParaInfo> &SurfAtt, vector<gmeSurface*> &SurfList);
	private:
		int  GetSectRegDz(s3d_SectSurfCls *pSectCls, double FacX, double FacY, vector<double> &dzList, vector<int> &SurfIDs);
		int  UpdateSectDzVal(s3d_SectSurfCls *pSectCls, double FacX, double FacY, vector<int>   &SurfIDs, double dz, double dzNew);
		int  IsDotInRect(double FacX, double FacY, gme_rect_3d &rect);
		int  GetSectDzByHole(double FacX, double FacY, gmeSurface *pSur, vector<double> &dzList);
		int  AdjustSectByAnchor(s3d_SectSurfCls *pSect1, int idx1, s3d_SectSurfCls *pSect2, int idx2);
		int  UpdateAllCrossFlg();
		int  GetAllSegLines(vector<vector<gme_vector2d>> &InLines);
		int  Checks3d_Surface(gmeSurface *pSurf, gme_vector2d *pTracks, int num);
		int  UpdateCrossFlg(s3d_SectSurfCls  *pObj1, s3d_SectSurfCls *pObj2);
		int  GetSectSegLines(s3d_SectSurfCls *pSect, vector<vector<gme_vector2d>> &InLines);

	private:
		double                           m_esp;
		vector<s3d_SectSurfCls*>       * m_secDatas;
	};

	//�������ݵ����ࣺ��ά���� ת���� ��ά����
	class _S3D_KER_GEOMAP_TRANS_EXP s3d_GeoSectImport
	{
	public:
		s3d_GeoSectImport();
		~s3d_GeoSectImport();

	public:
		// ���ö�λ����ϢyRate�����������1��yRate�����Ϊ1:3000����3000
		// ��λ������������ȫ... ͼ��������Խ��м���.... bCalΪ������
		// ͼ������ĵ�λ�����ף�ʵ������ĵ�λ����
		int SetAnchorDatas(s3d_AnchorPnt * pAncPnts, long AnchNum, long yRate,
			long xRate = 1000, bool bCut = false, bool bCalMap = false);

		// ��ά�����ת��Ϊ��ά����
		int SectPolygonToSurface(s3d_Polygon * pPoly, gmeSurface * pSurf);

		// ��ά�����ת��Ϊ��ά����
		int Sect2dDotsTo3dDots(gme_vector2d *pInPnt, gme_vector3d *pOutPnt, long dotNum);

		// ��ά�����ת��Ϊ��ά����
		int Sect3dDotsTo2dDots(gme_vector3d *pInPnt, gme_vector2d *pOutPnt, long dotNum);

	private:
		// ��λ�����򣬰���X���꣬��С��������
		void SortAnchors();

		// ��άת��άʱ�����м��㶨λ���ͼ������
		int  CalAnchorPntVal();

		// ��λ�켣���������ཻ�󣬶Զ���ν��и���
		int  UpdatePolyByCtrlLine(vector<gme_vector2d> &vecPoly, vector<gme_vector2d> &vecPolyOut);

		// �������ϣ������׹켣������
		int  AppendCtrlLines(vector<vector<gme_vector2d>> &vecPoly, vector<gme_vector2d> &dConsLinDotsVec);

	private:
		s3d_AnchorPnt * m_pAncPnts;  //��λ����Ϣ
		long            m_AnchNum;   //��λ����Ŀ
		long            m_xRate;     //���������
		long            m_yRate;     //���������
		bool            m_bCalMap;   //�Ƿ���㶨λ���ͼ������ֵ
		double          m_dYMap;     //ͼ��Y����ƫ����
		bool            m_bCut;      //�Ƿ��ڶ�λ�㴦�ü�
	};

	//ƽ���ͼ���ݵ����ࣺ����άƽ�����Σ�ת��Ϊ��ά��
	//�̼߳��㷽�������뷴�Ȳ�ֵ���ȸ�����ȡ��
	class _S3D_KER_GEOMAP_TRANS_EXP s3d_GeoMapImport
	{
	public:
		s3d_GeoMapImport();
		~s3d_GeoMapImport();

	public:
		// ���ø߳�Լ������
		// TriLen:  �߳�,Ang: ��С��
		// dRadius: ���뷴��Ӱ��뾶
		int  SetInitDatas(vector<gme_vector3d>         *pDots,
			vector<vector<gme_vector3d>> *pVec,
			double TriLen, double Ang,
			double dRadius, double *pDZ = NULL);

		// ��ά�����ת��Ϊ��ά����
		int  MapPolygonToSurface(s3d_Polygon * pPoly, gmeSurface * pSurf);

	public:
		// ����߳�ֵ...��pDots��Zֵ�����޸�
		int  CalDotsElevs(gme_vector3d * pDots, int nDotNum);

		// ��ȡ������ڲ���Լ����
		int  GetLabelDots(s3d_Polygon *pPoly, vector<gme_vector3d> &DotVec);

	private:
		double                            * m_pDZ;     //Zֵ��ͳһ��ֵ
		double                              m_Ang;     //��С��
		double                              m_TriLen;  //����߳�...
		double                              m_dRadius; //�ʺϾ��뷴�ȵĲ�ֵ�뾶
		vector<gme_vector3d>              * m_pDotVec; //�̵߳�Լ������
		vector<vector<gme_vector3d>>      * m_pResVec; //�ȸ���Լ������
		vector<gme_vector3d>                m_TopDatasVec; //����Լ������
	};

	// ���ݶ�ά����������ά����� 2020-11-17 leo
	class _S3D_KER_GEOMAP_TRANS_EXP CreateVirtualHoles
	{
	public:
		CreateVirtualHoles();
		~CreateVirtualHoles();

	public:
		// ���ö�λ����ϢyRate�����������1��yRate�����Ϊ1:3000����3000
		// ��λ������������ȫ... ͼ��������Խ��м���.... bCalΪ������
		// ͼ������ĵ�λ�����ף�ʵ������ĵ�λ����
		int  setdatas(vector<string>        &strVec,    //���룺�ز���룬��PolyVec�ȳ���
			vector<s3d_Polygon*>  &PolyVec,   //���룺����Σ�  ��strVec �ȳ���
			vector<gme_rect_2d>   &dRects,    //���룺rect
			s3d_AnchorPnt         *pAncPnts,  //���룺��λ����Ϣ
			int                    AnchNum,   //���룺��λ����Ϣ
			int                    yRate = 1000,  //����ô�
			int                    xRate = 1000,  //�ɲ���
			double                 esp = 1e-3);  //�ݲ�

// ��ָ���� dMapX ������ �������
		int  GetVirtHole(double dMapX, s3d_BoreHole  &holeObj);

		// ����ָ���� λ�ã���������holeVec��id�������ⲿ����...
		int  GetVirtHoles(vector<double> &dMapXvec, vector<s3d_BoreHole> &holeVec);

	public:
		// ����ת�����������ת��Ϊvector
		void  polyToVVec(s3d_Polygon *pPoly, vector<vector<gme_vector2d>> &dotVV);

		// ��ͼ��dMapX���뵥���������
		int   CalVirtualHole(string                       strcode,  //�ز����
			gme_rect_2d                  &rect,    //�������ε�rect
			vector<vector<gme_vector2d>> &PolyVV,  //��������
			vector<s3d_BoreHoleLayer>    &laylist, //�����ز�����
			double     dMapX, double esp = 1e-3);  //ͼ��X���ݲ�

// ��ͼ��dMapX�������ж�����󽻣������ά�������
		int   CalVirHoles(double                dMapX,      //���룺ͼ��X����
			vector<string>        &strVec,    //���룺�ȳ���
			vector<gme_rect_2d>   &dRects,    //���룺rect
			vector<s3d_Polygon*>  &PolyVec,   //���룺�ȳ���
			s3d_BoreHole          &holeObj,   //�������ȳ���
			double                esp = 1e-3);  //���룺�ݲ�

	public:
		double                   m_esp;
		s3d_GeoSectImport      * m_pImpot;
		vector<string>         * m_strVec;    //���룺�ز���룬��PolyVec�ȳ���
		vector<s3d_Polygon*>   * m_PolyVec;   //���룺����Σ�  ��strVec �ȳ���
		vector<gme_rect_2d>    * m_dRects;    //���룺rect
	};
}
