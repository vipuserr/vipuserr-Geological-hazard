#pragma once

#include "s3dGMdlDBEngineExp.h"

#include "gmeStru.h"
#include "gme_Ref.h"


namespace Smart3dMap
{
	class gmeStorageDB;


	//���·����ڴ�
	OG_GME_API void* _ReAllocBuf(void* pBuf, long lBufSize);
	//�滻�ַ���
	void  OG_GME_API _Replace_Str(std::string& strName, const std::string& strSrc, const std::string& strDesc);
	//��ȡ·��
	bool  OG_GME_API _AbstractPath(string& szPathFile, string& szPath);
	//��ȡ�ļ���
	bool  OG_GME_API _AbstractFile(string& szPathFile, string& szFileName);
	//��ȡ�ļ�������
	bool  OG_GME_API _AbstractTitle(string& szPathFile, string& szFileTitle);
	//��ȡ�ļ���չ��
	bool  OG_GME_API _AbstractExt(string& szPathFile, string& szFileExt);

	string OG_GME_API _GBK2Utf8(const char* gb2312);
	std::string  OG_GME_API _Utf82GBK(const char* strUtf8);
	std::wstring  OG_GME_API _Utf82Unicode(const std::string& utf8string);
	bool  OG_GME_API _Unicode2UTF8(vector<char>& pu8, const wchar_t* pun, int32 uLen);
	std::string  OG_GME_API _Unicode2Utf8(const std::wstring& widestring);
	bool  OG_GME_API _GBK2Unicode(vector<wchar_t>& pun, const char* pmb, int32 mLen);	
	std::string  OG_GME_API _Unicode2GBK(std::string &strValue);
	std::string  OG_GME_API _String2Unicode(const string &strSrc);
	std::wstring  OG_GME_API _String2Wstring(const std::string str);
	std::string  OG_GME_API _Wstring2String(const std::wstring str);
	std::wstring  OG_GME_API _Char2Wchar(const char* c, size_t m_encode = CP_ACP);
	std::string  OG_GME_API _Wchar2Char(const wchar_t* wp, size_t m_encode = CP_ACP);



	//��ȡ��ִ���ļ���·��
	void OG_GME_API _GetSysExePath(string& syspath);
	//����ȫ��Ψһ��...
	GString OG_GME_API _GetAUniqueString(string baseName);
	//������άģ�����ݿ⣬DbPath���վʹ���һ����ʱ��άģ�����ݿ�
	int OG_GME_API _CreateGmeDB_Sqlite(string DbPath = "");

	//���ݵز���ɫ��ȡ��ɫ����
	OG_GME_API string _getClrMatName(long stratColorRgb);
	//���ݵز�ͼ���źͱ���ɫ��ȡ�������
	OG_GME_API string _getTexMatName(std::string graphNo, long graphClrRgb);

	//���ݷָ������ַ����ָ�Ϊ�ַ����б�
	OG_GME_API vector<string> _og_split(const string& str, const string& pattern);

	OG_GME_API string LevelCode2OrderCodeTrans(string &levelCode);
	OG_GME_API string OrderCode2LevelCodeTrans(string &orderCode);

	//����ת��
	void OG_GME_API vec2dTovec3d(gme_vector2d *pdot, gme_vector3d *p3dot, double dz = 0.0);
	void OG_GME_API vec2dTovec3d(gme_vector2d *pdot, gme_vector3d *p3dot, int num, double dz = 0.0);
	void OG_GME_API vec2dTovec3d(vector<gme_vector2d> &pdotv, vector<gme_vector3d> &p3dotv, double dz = 0.0);
	void OG_GME_API vec3dTovec2d(gme_vector3d *p3dot, gme_vector2d *pdot);
	void OG_GME_API vec3dTovec2d(vector<gme_vector3d> &p3dotv, vector<gme_vector2d> &pdotv);

	//_�㼯����
	class OG_GME_API gmePntSet
	{
		friend class gmeGeometry;
		friend class gmeCorner;
		friend class gmeLine;
		friend class gmeSurface;
		friend class gmeEntity;
		friend class gmeGeoPnt;
		friend class gmeGeoLine;
		friend class gmeGeoSurface;
		friend class gmeGeoEntity;
		friend class gmeStorageDB;

	public:
		gmePntSet();
		gmePntSet(const gmePntSet& src);
		virtual ~gmePntSet();

	public:
		long Clear();//���
		long GetPointNum();//ȡ����

		//ƫ��
		long SetOffset(const gme_vector3d &offset);
		gme_vector3d& GetOffset();

		//������ɾ���˳��
		// ---------------------------- ������� ---------------------------- // 
		long SetPoints(vector<gme_vector3d> &pnts);
		long SetPointsInfo(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);
		long AddPoints(vector<gme_vector3d> &pnts, long lPntNo = 0);
		long AddAPoint(const gme_vector3d *pnt, long lPntNo = 0);

		long DeleteAllPoints();
		long DeleteAPoint(long lPntNo);

		//��ȡ��ƫ�ƵĶ�������
		long GetPoints_Offset(vector<gme_vector3d> &pnts);
		long GetPointsInfo_Offset(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);

		//ȡ������ƫ�ƵĶ�������...
		long GetPoints(vector<gme_vector3d> &pnts);
		vector<gme_vector3d>& GetPoints();
		gme_vector3d *GetAPoint(long lPntNo);
		long GetPointsInfo(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);
		long GetPointsInfo(vector<gme_vector3d>* &pntCoords, vector<gme_vector3d>* &pntNormals, vector<gme_color4>* &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>>* &pntTexCoords);
		long GetPointTexInfo(GME_TEXTURE_STAGE texLayer, vector<gme_tex_coord>* &pntTexCoords);

		long UpdatePoints(vector<gme_vector3d> &pnts, long nStartPntNo = 0);
		long UpdateAPoint(long lPntNo, const gme_vector3d *pnt);


		// ------------------ ��Ĳ������� ----------------------- //
		//��ķ���
		long AppendPntNormals(vector<gme_vector3d> &pntNormals);
		long DeleteAllPntNormals();
		long GetPntNormals(vector<gme_vector3d> &pntNormals);
		vector<gme_vector3d>& GetPntNormals();
		long UpdatePntNormals(vector<gme_vector3d> &pntNormals);
		long UpdateAPntNormal(long lPntNo, gme_vector3d* pPntNormal);

		//�����ɫ
		long AppendPntColors(vector<gme_color4> &pntColors);
		long DeleteAllPntColors();
		long GetPntColors(vector<gme_color4> &pntColors);
		vector<gme_color4>& GetPntColors();
		long UpdatePntColors(vector<gme_color4> &pntColors);
		long UpdateAPntColor(long lPntNo, gme_color4* pPntColor);

		//�����������...
		long AppendPntTexCoords(GME_TEXTURE_STAGE tsn, vector<gme_tex_coord> &pPntTexCoords);
		long DeleteAPntTexCoords(GME_TEXTURE_STAGE tsn);
		long GetPntTexCoords(GME_TEXTURE_STAGE tsn, vector<gme_tex_coord> &pPntTexCoords);
		vector<gme_tex_coord>& GetPntTexCoords(GME_TEXTURE_STAGE tsn = GME_TSN_1);
		long UpdatePntTexCoords(GME_TEXTURE_STAGE tsn, vector<gme_tex_coord> &pPntTexCoords);
		long UpdateAPntTexCoord(GME_TEXTURE_STAGE tsn, long lPntNo, gme_tex_coord* pPntTexCoord);

		// ---------------------------- ����� ---------------------------- // 
		long SetBox(gme_rect_3d& box); //���ð�Χ��
		long GetBox(gme_rect_3d& box); //��ȡ��Χ��
		//���Ҿ���õ�����ĵ㣬���ص�������, �����򷵻�<0����
		long FindNearestPoint(gme_vector3d *pPnts);
		//���Ҿ���õ�����ĵ㣬��Χ��radius�ڣ����ص�������, �����򷵻�<0����
		long FindNearestPoint(gme_vector3d *pPnts, double radius);
		//����������
		long FindNearestPoint(gme_vector3d *pPnts, double radius, vector<long>& indexList);

		//�����������ͣ�1-ͨ�����㸳ɫ��0-ͨ�������θ�ɫ��
		void setAssignClrByVertOrTriFlag(bool bFlag = 1);
		void getAssignClrByVertOrTriFlag(bool& bFlag);

		//�����������ͣ�0-ͨ�����㸳ɫ��1-ͨ�������θ�ɫ��
		void setClrBindType(bool bFlag = 0);
		void getClrBindType(bool& bFlag);

		//�����������ͣ�0-ͨ�����㸳����1-ͨ�������θ�����
		void setNormalBindType(bool bFlag = 0);
		void getNormalBindType(bool& bFlag);


	protected:
		virtual long CalBox();//��GetBox����,�����Χ��
		void InitOffset(gme_vector3d* offset = nullptr);

	private:
		gme_vector3d		mOffSet; //����ƫ��
		gme_rect_3d		    mBox;	  //��Χ��
		vector<gme_vector2d> mPointArray_2d; //��������
		vector<gme_vector3d> mPointArray; //��������
		vector<gme_vector3d> mNormalArray;//���㷨��
		vector<gme_color4>  mColorArray; //������ɫ
		map< GME_TEXTURE_STAGE, vector<gme_tex_coord> > mTexcoordMap;//������������
		vector<vector<double>>	mPntAttVal; //ÿһ������n������
		bool					mbAssignClrByVertOrTri; //�����������ͣ�1-ͨ�����㸳ɫ��0-ͨ�������θ�ɫ����
													    //������mColorArray��mNormalArray��mTexcoordMap��Ԫ�ظ���.
		bool					mbAssignNormalByVertOrTri;

	};

	//��ά��
	class OG_GME_API gmeEdge
	{
		friend class gmeStorageDB;
	public:
		gmeEdge();
		gmeEdge(const gmeEdge & rhs);
		virtual ~gmeEdge();
		gmeEdge& operator=(const gmeEdge& rhs);

	public:
		long Clear();//���

		long SetPntID(long lFromPntID, long lToPntID);
		long GetPntID(long &lFromPntID, long &lToPntID);
	private:
		long mFromPntID, mToPntID;
	};

	class OG_GME_API gmeObject : public s3d_Ref
	{
		friend class gmeStorageDB;
		friend class gmeEntity;
		friend class gmeSurface;

	public:
		gmeObject(gmeStorageDB* storeDB = nullptr);
		gmeObject(const gmeObject&gmeo);
		virtual ~gmeObject();

	public:
		// -------------------- ���л����� ------------------------ //
		virtual long Clear();//���
		virtual long Load(GME_TYPE_OBJ_ID id);//�����ݿ����¼���
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//����
		virtual long CompressSave();//ѹ���洢
		virtual gmeObject& operator=(gmeObject& obj);
		virtual long Clone(gmeObject* obj);//��������
		virtual long Delete();
		virtual long UndoDelete();

		long GetObjNum();//ȡ�߼���
		long GetPhyObjNum();//ȡ������
		virtual long SetBox(gme_rect_3d& box); //���ð�Χ��
		virtual long GetBox(gme_rect_3d& box); //��ȡ��Χ��
		virtual long GetBox(gme_rect_2d& box); //��ȡ��Χ��

		long SetID(GME_TYPE_OBJ_ID lID); //����ID
		GME_TYPE_OBJ_ID GetID(); //

		long SetName(GString strName);//��������
		GString GetName();//��ȡ����

		void SetCaption(const GString& cattion);//������ʾ��Ϣ
		GString GetCaption();//ȡ��ʾ��Ϣ

		long GetDateTime(gme_date_time& strDateTime);//��ȡ����ʱ�䣬��ϵͳ�Զ�����
		long SetDateTime(gme_date_time& strDateTime);//��ȡ����ʱ�䣬��ϵͳ�Զ�����

		long SetExistFlag(bool bExistFlag); //ɾ����־
		long GetExistFlag(bool& bExistFlag); //ɾ����־

		long SetObjType(GME_OBJ_TYPE oType);//��������� 
		GME_OBJ_TYPE GetObjType();//ȡ��������

		int SetDim(GME_DIM_TYPE dim); //���ö���ά������������ʱȷ����
		int GetDim(GME_DIM_TYPE &dim); //ȷ������ά��

		long SetModifyState(bool bModifyState);//���ñ༭״̬
		long GetModifyState(bool& bModifyState);//ȡ�༭״̬
		friend class gmeStorageDB;

		// -------------------- ��ȡ��ʽ -------------------- //
		gmeStorageDB* getMdlIoObjByType(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_UNKNOWN);
		gmeStorageDB* getMdlIoObjByID(GME_TYPE_OBJ_ID mdlID = 0xFFFFFFFE);
		long getMdlIoType(GME_MDL_IO_TYPE& mdlIoType); //��ȡ���ݲ�������
		// �������ݿ�洢����ioObj ����Ĺ�����������ɵ����߸������
		void setGMEStorageDB(gmeStorageDB* ioObj);

	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

	protected:
		gmeStorageDB*	mPhyIoObj;//���ݻ�ȡ����ָ�루��
		GME_MDL_IO_TYPE	mMdlIoType;//����Ĵ�ȡ��ʽ
		GME_TYPE_OBJ_ID	mObjID;	  //����ID
		GString			mObjName; //��������
		GString			mObjCaption; //��������
		gme_date_time	mDateTime;//���󴴽�ʱ��
		bool			mExistFlag; //���ڱ�־
		gme_rect_3d		mBox;	  //��Χ��
		GME_OBJ_TYPE	mObjType; //��������
		bool			mModifyState;//�޸ı༭״̬
		GME_DIM_TYPE	mDimension;//����ά��
		long			mSubObjNum, mPhySubObjNum;//������������Ӷ���ĸ���
		vector<GME_TYPE_OBJ_ID> mSubObjIDList; //�Ӷ����ID�б�
	};


	class OG_GME_API gmeGeoRef :public gmeObject	//�ռ����ϵ
	{
		friend class  gmeStorageDB;//����gmeStorageSqlDBΪ�������Ԫ��
	public:
		gmeGeoRef();
		virtual ~gmeGeoRef();

	public:
		long GetGeoRefNum();

		virtual long Load(GME_TYPE_OBJ_ID GeoRefID);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//����
		virtual long CompressSave();//ѹ���洢
		virtual long Delete();
		virtual long UndoDelete();

		long SetParam(long lGeoID, gme_date_time gdate, GString strName,
			GString strProjCSName, double dFalseEasting, double dFalseNorthing, double dCentralMeridian, double dScaleFactor, double dLatOfOrigin, double dLenthUnit,
			GString	strGCSName, double dAnglrUnit, double dPrimeMeridian, GString strDatum, GString strSpheriod, double dSemimajorAxis, double dSemiminorAxis, double dInverseFlattening);
		long GetParam(long &lGeoID, gme_date_time &gdate, GString &strName,
			GString &strProjCSName, double &dFalseEasting, double &dFalseNorthing, double &dCentralMeridian, double &dScaleFactor, double &dLatOfOrigin, double &dLenthUnit,
			GString	&strGCSName, double &dAnglrUnit, double &dPrimeMeridian, GString &strDatum, GString &strSpheriod, double &dSemimajorAxis, double &dSemiminorAxis, double &dInverseFlattening);
	private:
		//����ο�ϵ����...
		GString		mProjCSName;
		double		mFalseEasting;
		double		mFalseNorthing;
		double		mCentralMeridian;
		double		mScaleFactor;
		double		mLatOfOrigin;
		double		mLenthUnit;

		GString		mGCSName;
		double		mAnglrUnit;
		double		mPrimeMeridian;
		GString		mDatum;
		GString		mSpheriod;
		double		mSemimajorAxis;
		double		mSemiminorAxis;
		double		mInverseFlattening;
	};


	class OG_GME_API gmeMaterialLib : public gmeObject	//���ʿ�
	{
		friend class gmeStorageDB;
	public:
		gmeMaterialLib();
		virtual ~gmeMaterialLib();

	public:
		long GetMaterialNum();

		virtual long Load(GME_TYPE_OBJ_ID MaterialLibID);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//����
		virtual long CompressSave();//ѹ���洢
		virtual long Delete();
		virtual long UndoDelete();

		long SetParam(long lGeoID, gme_date_time gdate, GString strName,
			GString strUrl, GString strDesc);
		long GetParam(long &lGeoID, gme_date_time &gdate, GString &strName,
			GString &strUrl, GString &strDesc);
	private:
		GString mMaterialLibUrl;
		GString mMaterialLibDesc;
	};

	class OG_GME_API gmeSeries :public gmeObject	//��׼�ز�StdStrat
	{
		friend class gmeStorageDB;
	public:
		//gmeSeries();
		//virtual ~gmeSeries();

	public:
		//long GetStdStratNum();//��ȡ�ñ�׼�ز��ĵز���Ŀ
		//long GetStratNumByStdID();//��ʱ����

		//virtual long Load(GME_TYPE_OBJ_ID seriesID, GString mstrStratName);//�����ݿ����¼���
		//virtual long Save(GME_DATA_STORAGE_TYPE lSaveType = GME_DST_TEMP);//����
		//virtual long CompressSave(GME_DATA_STORAGE_TYPE lSaveType = GME_DST_TEMP);//ѹ���洢
		//virtual long Delete(GME_TYPE_OBJ_ID	seriesID, GString mstrStratName);
		//virtual long UndoDelete();

		/*long SetParam(long lStdStratID, gme_date_time gdate, GString StdStratName,
					  GString strStratLevel, GString strStratCode, GString StratName, GString strLithology, GString strGeoRelation, GString strAge, GString strCause,
					  long lMaterialLibID, GString strClrMatName, GString strTexMatName, GString strStratDesc);
		long GetParam(long &lStdStratID, gme_date_time &gdate, GString &StdStratName,
					  GString &strStratLevel, GString &strStratCode, GString &StratName, GString &strLithology, GString &strGeoRelation, GString &strAge, GString &strCause,
					  long &lMaterialLibID, GString &strClrMatName, GString &strTexMatName, GString &strStratDesc);
		long GetSerirs(GString mstrStratLevel);*/

	private:
		//��׼�ز��Cme_StdStrat
		//id��ʱ��Ĭ��
		GString mstrStdStratName;//�ز������
		GString mstrStdGeoType;//�ز������ ˮ�ġ�����
		GString mstrStdStratDesc;//�ز������

		//�ز� Gme_SubStrat
		//id
		GString mstrStratName;//�ز�����
		GString mstrStratCode;//�ز����
		GString mstrStratLevel;//�������
		GString mstrLithology;//����
		GString mstrGeoRelation;//�໥��ϵ
		GString mstrAge;//�������
		GString mstrCause;//����
		GString mstrStratDesc;//�ز�����

		//�ز���� Gme_StdStratMat
		//�������ͣ�ˮ�� ���̣����ز����
		long	mlMaterialLibID;//����id
		GString mstrMatLibName;//���ʿ�����
		GString mstrClrMatName;//��ɫ��������
		int     miStratClr;//������ɫ
		GString mstrTexMatName;//�����������
		int     miStratTexID;//���������
		int     miStratTexHeight;//���ʸ߶�
		int     miStratTexWidth;//���ʿ��
		GString mstrStratTexBKClr;//���ʱ���	
	};



	class OG_GME_API gmeLegend : public gmeObject	//ͼ��
	{
		friend class gmeStorageDB;
	public:
		gmeLegend();
		virtual ~gmeLegend();
	public:
		GME_LEGEND_TYPE GetLegendType();
		long GetLegendNum();
		long GetLegendCellNum(long lLegendID);
		vector<gme_legend_cell>& GetLegendCellData();


		virtual long Load(GME_TYPE_OBJ_ID LegendID);//�����ݿ����¼���
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//����
		virtual long CompressSave();//ѹ���洢
		virtual long Delete();
		virtual long UndoDelete();

		long SetParam(long lLegendID, gme_date_time gdate, GString strName,
			GME_LEGEND_TYPE legendType, double legendHeight, double lgendWidth, double legendSubAngle, long legendChFont, long legendEnFont, bool legendVisible,
			vector<gme_legend_cell> legendCellData);
		long GetParam(long &lLegendID, gme_date_time &gdate, GString &strName,
			GME_LEGEND_TYPE &legendType, double &legendHeight, double &lgendWidth, double &legendSubAngle, long &legendChFont, long &legendEnFont, bool &legendVisible,
			vector<gme_legend_cell> &legendCellData);

	private:
		GME_LEGEND_TYPE		mLegendType;
		double				mLegendHeight;
		double				mLegendWidth;
		double				mLegendSubAngle;
		long				mLegendChFont;
		long				mLegendEnFont;
		bool				mLegendVisible;
		vector<gme_legend_cell> mLegendCellData;
	};

	class OG_GME_API gmeNote : public gmeObject	//ע��
	{
		friend class gmeStorageDB;
	public:
		gmeNote();
		virtual ~gmeNote();

	public:
		long GetNoteNum();
		long GetLegendCellNum(long lLegendID);

		virtual long Load(GME_TYPE_OBJ_ID NoteID);//�����ݿ����¼���
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//����
		virtual long Delete();
		virtual long CompressSave();//ѹ���洢
		virtual long UndoDelete();

		long SetParam(long lNoteID, gme_date_time gdate, gme_note_info* noteInfo, vector<gme_note_content> noteData);
		long GetParam(long &lNoteID, gme_date_time &gdate, gme_note_info* &noteInfo, vector<gme_note_content> &noteData);

	private:
		gme_note_info mNoteInfo;
		vector<gme_note_content> mNoteData;
	};


	class OG_GME_API gmeGeometry : public gmeObject //�����������ݶ���
	{
		friend class gmeStorageDB;
		friend class gmeFeature;
		friend class gmeEntity;
		friend class gmeSurface;
	public:
		gmeGeometry();
		gmeGeometry(const gmeGeometry& geom);
		virtual ~gmeGeometry();

	public:
		virtual long Clone(gmeGeometry& obj);//��������
		virtual long Clear();//���
		virtual long Load(GME_TYPE_OBJ_ID objID, long lodLevel=0);//�����ݿ����¼���
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel=0);//����
		virtual long CompressSave(long lodLevel=0);//ѹ���洢
		virtual long Delete(long lodLevel=0);
		virtual long UndoDelete(long lodLevel=0);

		long SetOffset(const gme_vector3d &offset);
		gme_vector3d& GetOffset();

		// ---------------------------- ������Ϣ ---------------------------- //
		long SetTopoObj(GME_TYPE_OBJ_ID& lLeftObjID, GME_TYPE_OBJ_ID& lRightObjID);
		long GetTopoInfo(GME_TYPE_OBJ_ID& lLeftObjID, GME_TYPE_OBJ_ID& lRightObjID);

		long SetPntSet(gmePntSet &pntSet);//���õ㼯
		long DeletePntSet();//ɾ���㼯
		long GetPntSet(gmePntSet &pntSet);//��ȡ�㼯
		gmePntSet* GetPntSet();
		long Update(gmePntSet &pntSet);//���µ㼯

		virtual long SetMaterialName(GString MaterialName[2]);
		virtual long SetPosMatName(GString MaterialName);
		long SetPosMatName2Null();//�����ÿ�
		virtual long SetNegMatName(GString MaterialName);
		long SetNegMatName2Null();//�����ÿ�
		virtual GString GetPosMatName();
		virtual GString GetNegMatName();

		long SetMaterialInfo(GME_MATERIAL_TYPE matType, GString strMatName, GME_MATERIAL_SIDE matSide = GME_MS_POSITIVE);//���ò���
		long GetMaterialInfo(GME_MATERIAL_TYPE &matType, GString &strMatName, GME_MATERIAL_SIDE matSide = GME_MS_POSITIVE);//��ȡ����

		//���ζ����ע��
		void SetNote(gmeNote* note);
		gmeNote* GetNote();

		// ---------------------------- ���ζ���������� ---------------------------- //
		virtual long Equals(gmeObject& obj);
		virtual long Disjoint(gmeObject& obj);
		virtual long Touches(gmeObject& obj);
		virtual long Crosses(gmeObject& obj);
		virtual long Within(gmeObject& obj);
		virtual long Overlaps(gmeObject& obj);
		virtual long Contains(gmeObject& obj);
		virtual long Intersects(gmeObject& obj);
		virtual long Relate(gmeObject& obj);

	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

	public:
		GME_TYPE_OBJ_ID		mLeftObjID;
		GME_TYPE_OBJ_ID		mRightObjID;
		gmePntSet			mPntSet; //��������
		GME_MATERIAL_TYPE	mMatType[2];//����������ʵ�����(һ��ֻ��������)
		GString				mMatName[2];//����������ʵ�����
		gmeNote				mNote;	//���ζ����Ӧ��ע��
	};



	class OG_GME_API gmeCorner : public gmeGeometry //���
	{
		friend class gmeStorageDB;

	public:
		gmeCorner();
		gmeCorner(const gmeCorner&rhs);
		virtual ~gmeCorner();

	public:
		gmeCorner& operator=(gmeCorner &rhs);
		long Clone(gmeCorner& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID CornerID,long lodlevel = 0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);//����
		long CompressSave(long lodlevel = 0);//ѹ���洢
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);
		long SetPoint(const gme_vector3d *p3DPnt);
		long DeletePoint();
		long GetPoint(gme_vector3d *p3DPnt);
		long UpdateAPoint(const gme_vector3d *p3DPnt);
		long SetPointPara(CPointStyleParam &PntPara);
		long GetPointPara(CPointStyleParam &PntPara);

	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

	private:
		gme_vector3d mPntPos;
		CPointStyleParam mPntPara;
	};


	class OG_GME_API gmeLine : public gmeGeometry //��
	{
		friend class gmeStorageDB;
	public:
		gmeLine();
		gmeLine(const gmeLine& rhs);
		virtual ~gmeLine();

	public:
		gmeLine& operator=(gmeLine &rhs);
		long Clone(gmeLine& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID linID, long lodlevel = 0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);//����
		long CompressSave(long lodlevel = 0);//ѹ���洢
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);

	public:
		//�߿����
		long SetLineWidth(double lineWidth);
		double GetLineWidth();

		//�Ե㼯�ķ�ʽ�������������gmeGeometry
		// ---------------------------- ������� ---------------------------- // 
		long GetPointNum();

		void* init(int dotnum);
		long SetPoints(gme_vector2d*pPnts, long dotnum);
		long SetPoints(gme_vector3d*pPnts, long dotnum);
		long SetPoints(vector<gme_vector3d> &pPnts);
		long AddPoints(vector<gme_vector3d> &pPnts, long lPntNo = 0);
		long AddAPoint(const gme_vector3d *pPnt, long lPntNo = 0);

		long DeleteAllPoints();
		long DeleteAPoint(long lPntNo);

		//��ȡ��ƫ�ƵĶ�������
		long GetPoints_Offset(vector<gme_vector3d> &pnts);
		long GetPointsInfo_Offset(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);

		//ȡ������
		gme_vector3d* ptXYZ();
		gme_vector2d* GetPoints_2d();
		vector<gme_vector3d>& GetPoints();
		long GetPoints(vector<gme_vector3d> &pPnts);//���ز���ƫ�Ƶ�����
		gme_vector3d* GetAPoint(long lPntNo);
		long GetPointsInfo(vector<gme_vector3d> &pPnts, vector<gme_vector3d> &pPntNormals, vector<gme_color4> &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pPntTexCoords);
		long GetPointsInfo(vector<gme_vector3d>* &pPnts, vector<gme_vector3d>* &pPntNormals, vector<gme_color4>* &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>>* &pPntTexCoords);

		long UpdatePoints(vector<gme_vector3d> &pPnts, long nStartPntNo = 0);
		long UpdateAPoint(const gme_vector3d *pPnts, long lPntNo);

		// ---------------------------- ���ϵĽ����� ---------------------------- // 
		long SetCorners(gmeCorner pCorners[2], long lCornerNum = 2);
		long SetCorners(GME_TYPE_OBJ_ID pBoundIDs[2], long lCornerNum = 2);
		long DeleteAllCorners();
		long GetCorners(gmeCorner p3DCorners[2]);
		long UpdateCorners(gmeCorner pCorners[2], long lCornerNum = 2);

		// ---------------------------- ���ϱߵĲ��� ---------------------------- // 
		long GetEdgeNum();
		long GetPhyEdgeNum();
		long SetEdges(const vector<gmeEdge> &pEdges);
		long AddEdges(const vector<gmeEdge> &pEdges, long lEdgeNo = 0);
		long DeleteAllEdges();
		long GetEdges(vector<gmeEdge> &pEdges);
		long GetPhyEdges(vector<gmeEdge> &pEdges);//ȡ���������ı����� 
		long UpdateEdges(vector<gmeEdge> &pEdges, long lStartEdgeNo = 0);

		// ---------------------------- �߲����Ĳ��� ---------------------------- // 
		long SetLinePara(CLineStyleParam &LinPara);
		long GetLinePara(CLineStyleParam &LinPara);
	private:
		//���ϵĶ����ڻ������Ѷ���
		GME_TYPE_OBJ_ID		mLinCorner[2]; //�ߵĽ�㣨2����
		vector<gmeEdge>	mLinEdge;   //�ߵı�
		double			mLineWidth;
		CLineStyleParam mLinPara;
	};
	typedef gmeLine* CAnyLinePTR;



	class  OG_GME_API gmeSurface : public gmeGeometry //��
	{
		friend class gmeStorageDB;
	public:
		gmeSurface();
		gmeSurface(const gmeSurface& surface);
		virtual ~gmeSurface();

	public:
		gmeSurface&	 operator=(gmeSurface &rhs);
		long Clone(gmeSurface& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID surID,long lodLevel=0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel=0);//����
		long CompressSave( GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB,long lodLevel=0);//ѹ���洢
		long Delete(long lodlevel=0);
		long DeleteAllLod();
		long UndoDelete(long lodlevel=0);
		

	public:
		// ---------------------------- �߽���������б� ---------------------------- //
		long GetBoundNum();

		gmeLine* AddABound(string name = "");
		long AddABound(GME_TYPE_OBJ_ID surfID);
		long AddBound(vector<gmeLine*> &pBounds);
		long AddBound(vector<GME_TYPE_OBJ_ID> &pBoundIDs);

		long DeleteBound();
		long DeleteABound(GME_TYPE_OBJ_ID ObjID);

		long GetBound(vector<gmeLine*> &pBounds);
		long GetBound(vector<GME_TYPE_OBJ_ID> &ObjIDs);
		gmeLine* GetABound(short lObjNo);
		long GetABound(short lObjNo, GME_TYPE_OBJ_ID &ObjID);

		long UpdateBound(vector<gmeLine*> &pBounds, long nStartNo = 0);
		long UpdateBound(vector<GME_TYPE_OBJ_ID> &ObjIDs, long nStartNo = 0);
		long UpdateABound(long lObjNo, gmeLine* pObj);
		long UpdateABound(long lObjNo, GME_TYPE_OBJ_ID ObjID);

		long SetRowColNo(long row, long col);
		long GetRowColNo(long &row, long &col);


		// ---------------------------- ����� ---------------------------- //
		long GetPointNum();
		long AddPoints(vector<gme_vector3d> &pPnts);
		long AddAPoint(gme_vector3d *pPnt, long lPntNo = 0);
		long SetPoints(vector<gme_vector3d> &pPnts);
		long SetPointsInfo(vector<gme_vector3d> &pPnts, vector<gme_vector3d> &pPntNormals, vector<gme_color4> &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pPntTexCoords);
		long DeleteAllPoints();
		long DeleteAPoint(long lPntNo);

		//��ƫ�Ƶĵ�...
		long GetPoints_Offset(vector<gme_vector3d> &pPnts);
		long GetPointsInfo_Offset(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);

		long GetPoints(vector<gme_vector3d> &pPnts);
		gme_vector3d*	 GetPointsPtr();
		vector<gme_vector3d>& GetPoints();
		vector<gme_vector3d>& GetNormals();
		vector<gme_color4>& GetColors();

		vector<gme_tex_coord>& GetTexCoords();
		int* GetColorsPtr();//������ɫ������Ϊpntnum
		gme_vector3d* GetNormalsPtr();//���㷨����������Ϊpntnum
		gme_vector2d* GetTexCoordsPtr();//�����������꣬����Ϊpntnum

		int GetTexLayerNum();//�����������
		gme_vector3d* GetAPoint(long lPntNo);
		long GetPointsInfo(vector<gme_vector3d> &pPnts, vector<gme_vector3d> &pPntNormals, vector<gme_color4> &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pPntTexCoords);
		long GetPointsInfo(vector<gme_vector3d>* &pPnts, vector<gme_vector3d>* &pPntNormals, vector<gme_color4>* &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>>* &pPntTexCoords);

		long UpdatePoints(vector<gme_vector3d> &pPnts, long nStartPntNo = 0);
		long UpdateAPoint(long lPntNo, gme_vector3d *pPnts);


		// ---------------------------- �����β��� ---------------------------- //
		//����������
		long GetTriangleNum();
		long GetTriangleTopNum();

		long SetTriangles(vector<gme_triangle> &pTriangle, vector<gme_triangle_top> &pTriangleTop);
		long AddTriangles(vector<gme_triangle> &pTriangle, vector<gme_triangle_top> &pTriangleTop);
		long AddATriangle(gme_triangle* pTriangle, gme_triangle_top* pTriangleTop);

		long RemoveAllTriangle();
		long RemoveATriangle(gme_triangle* pTriangle);
		long RemoveATriangle(long nTriNo);

		int* GetTrianglesPtr();           //�����ζ������У�����Ϊ3*trinum
		gme_triangle* getTrianglesPtr();           //�����ζ������У�����Ϊtrinum
		long GetTriangles(vector<gme_triangle> &pTriangle, vector<gme_triangle_top> &pTriangleTop);
		long GetATriangle(long nTriNo, gme_triangle* pTriangle, gme_triangle_top* pTriangleTop);
		vector<gme_triangle>& GetTriangles();
		vector<gme_triangle_top>& GetTriangleTops();
		int* GetTriangleTopsPtr();          //�����α�top������Ϊ3*trinum
		gme_triangle_top* getTriangleTopsPtr();          //�����α�top������Ϊtrinum

		long UpdateTriangles(vector<gme_triangle> &pTriangle, vector<gme_triangle_top> &pTriangleTop, long nStartTriNo = 0);
		long UpdateATriangle(long nTriNo, gme_triangle *pTriangle, gme_triangle_top* pTriangleTop);

		//���������
		long SetSurfPara(CSurfaceStyleParam &SurfPara);
		long GetSurfPara(CSurfaceStyleParam &SurfPara);

		//�����Ͳ���
		long SetSurfType(GME_SURF_TYPE SurfType);
		long GetSurfType(GME_SURF_TYPE &SurfType);
		GME_SURF_TYPE GetSurfType();

		//�����������ͣ�0-ͨ�����㸳ɫ��1-ͨ�������θ�ɫ��
		void setClrBindType(bool bFlag = 0);
		void getClrBindType(bool& bFlag);

		//�����������ͣ�0-ͨ�����㸳ɫ��1-ͨ�������θ�ɫ��
		void setNormalBindType(bool bFlag = 0);
		void getNormalBindType(bool& bFlag);

		//����任���� 2020-01-04 leo add from ogSimpleMesh
		void convertPostionsToLocalCoordinate(const gme_vector3d& center); //����ƽ��
		void calculateDefaultNormals();    //����ȱʡ����
		long calMeshTop(long lSuffix = 0); //�����������...
		//coord��ʾ�����ᣬ0-X�ᣬ1-Y�ᣬ2-Z��
		void makerotate(long coord, double angle);
		void makerotate(gme_vector3d& point, long coord, double angle);
		void getMeshcenter(gme_vector3d& center);
		long getIndexBufferSize();
		bool merge(gmeSurface* src);
		//������
		gmeSurface& swap_gm_surf(gmeSurface& sur);
		//�����������꣨���棩
		void calTexCoord(gme_vector3d* poly = NULL, long polydotsnum = 0, gme_rect_2d* rsImageBox = NULL);
		void MatchTexCoord();//ʹ�����������붥����һ��
		//���ڴ������ֵ...
		void set(int pntnum, gme_vector3d*dots,
			int trinum, gme_triangle*tris, gme_triangle_top* tritops = NULL,
			gme_color4* colors = NULL, gme_vector3d* normals = NULL, gme_tex_coord* texcoords = NULL, int texturelayernum = 0,
			GME_SURF_TYPE surftype = Smart3dMap::GME_SURF_TYPE::SUR_TYPE_INIT, string matname = "");
		void set(int pntnum, gme_vector3d *pdots,
			int trinum, int *ptris, int *ptopos = NULL,
			int *pcolors = NULL, gme_vector3d * pnormals = NULL, gme_vector2d * ptextures = NULL, int texturelayernum = 0,
			GME_SURF_TYPE sur_type = Smart3dMap::GME_SURF_TYPE::SUR_TYPE_INIT, string matName = "");

		void set_pnt_num(int dotnum);
		void set_tri_num(int trinum);
		void init_normals(int num = -1);
		void init_colors(int num = -1);
		void init_texcoords(int num = -1);
		void init_tri_tops(int num = -1);
		void init(int pntnum, int trinum, int texlayernum = 1);
		void set_pnts(gme_vector3d* dots, int dotnum = -1);
		void set_tris(gme_triangle* tris, int trinum = -1);
		void set_tris(int* tris, int trinum = -1);
		void set_tri_tops(gme_triangle_top* tritops);
		void set_normals(gme_vector3d* normals);
		void set_colors(int* colors);
		void set_colors(gme_color4* colors);
		void set_texcoords(gme_tex_coord* texcoords, int tex_coord_dot_num = -1);

		//����ĳһ���������ģ��
		void setLodSurf(s3d_Pointer<gmeSurface>& lodSurf, long lodLevel = 1);
		//ȡ��ĳһ���������ģ��
		void getLodSurf(gmeSurface& lodSurf, long lodLevel = 0);
		//��ȡһ�����Lod�������������ڰ��ռ���������Lod  wzj 2021.8.18
		long getLodLevelNum();
		//ȡ�����lod
		void getLodLevelList(map<long, s3d_Pointer<gmeSurface>> & lodSurfList);
		// ��ȡһ�������е�Level������б�  wzj 2021.8.18
		void getLodLevelList(vector<long>& lodIDList);


		
	private:
		vector<GME_TYPE_OBJ_ID>  mSurfLinIDs;
		vector<gmeLine*>		 mSurfLins;

		vector<gme_triangle>     mTriangles;
		vector<gme_triangle_top> mTriangleTops;
		CSurfaceStyleParam       mSurfPara;
		GME_SURF_TYPE            mSurfType;

		long					mSurfRowNo, mSurfColNo;
		map<long, s3d_Pointer<gmeSurface>> mLodSurf; //�����lod
	};


	class OG_GME_API gmeEntity : public gmeGeometry //��
	{
		friend class gmeStorageDB;
	public:
		gmeEntity();
		gmeEntity(const gmeEntity& rhs);
		virtual ~gmeEntity();

	public:
		gmeEntity&	 operator=(gmeEntity &rhs);
		long Clone(gmeEntity& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID EntityID,long lodlevel=0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//����
		long CompressSave(long lodlevel=0);//ѹ���洢
		long Delete(long lodlevel=0);
		long UndoDelete(long lodlevel=0);
		
		
	public:
		// ---------------------------- �߽���������б� ---------------------------- //
		/////�Ѳ���,GetBoundNumҪ�޸�(��ֹ����Խ��)��GetSurfaceNumҪ�޸�
		long GetSurfaceNum() { return GetBoundNum(); }
		long GetBoundNum();//��ȡָ��Ȧ�����������Ĭ������Ȧ��////////��һ��short boundNo
		long GetEntRingNum();//��ȡȦ�������
		long GetTotalSurfNum();//��ȡ������ĸ�����������Ȧ��
		long GetTotalSurfIDNum();//��ȡ������ID�ĸ�����������Ȧ��

		//AddSurface��AddABound����������ͬ���������������һ����
		gmeSurface*	AddSurface(string name = "");
		void AddSurface(gmeSurface*surf);
		void AddSurface(gmeSurface&surf);
		void AddSurface(s3d_Pointer<gmeSurface>& surf);

		gmeSurface*	AddABound(string name = "", int boundNo = 0);//�Ƽ�ʹ�� �ڲ��Զ�����gmeSurface
		void AddABound(gmeSurface*surf, int boundNo = 0);//����������gmeSurface
		void AddABound(s3d_Pointer<gmeSurface>& surf, int boundNo = 0);
		long AddABound(GME_TYPE_OBJ_ID surfID, int bondNo = 0);
		long AddBound(vector<gmeSurface*>& pBounds, short boundNo = 0);
		long AddBound(vector<s3d_Pointer<gmeSurface>>& pBounds, short boundNo = 0);
		long AddBound(vector<GME_TYPE_OBJ_ID>& pObjIDs);
		//////
		long DeleteSurf(int idx) { return DeleteABound((short)idx); }
		long DeleteABound(GME_TYPE_OBJ_ID ObjID);
		long DeleteABound(short index);
		long DeleteBound();
		//////yc
		gmeSurface* GetSurface(int idx) { return GetABound(idx); }
		gmeSurface* GetABound(short lObjNo);
		s3d_Pointer<gmeSurface>& GetABoundPtr(short lObjNo);
		gmeSurface* GetABound(short boundNo, short lRegionNo);//2021_4_12��
		gmeSurface* GetABound(const string& name);
		long GetABound(short lObjNo, GME_TYPE_OBJ_ID& ObjID);
		long GetABound(short bondNo, short lRegionNo, GME_TYPE_OBJ_ID& ObjID);//2021_4_12��
		long GetBound(vector<gmeSurface*>& pBounds);
		long GetBound(vector<GME_TYPE_OBJ_ID>& pObjIDs);
		long GetBound(vector<GME_TYPE_OBJ_ID>& pObjIDs, int boundNo);//2021_4_12��
		long GetBound(vector<gmeSurface*>& pBounds, short boundNo);//2021_4_13��
		std::vector<gmeSurface*> GetBound();//��ȡ���е��棬������Ȧ�������뵽һά�����з���
		std::vector<gmeSurface*> GetBound(int boundNo);//��ȡĳһȦ������б�//2021_4_12��
		vector<vector<s3d_Pointer<gmeSurface>>>& getAllSurface();//2021_4_12��
		//////yc
		int UpdateSurf(int idx, gmeSurface& surfObj);
		int UpdateSurf(short boundNo, short lRegionNo, gmeSurface& surfObj);//2021_4_12��
		int UpdateSurf(int idx, GME_TYPE_OBJ_ID surfID);//����idxλ�õ���ID��, /////���������Updata,�����º�����ͬ��
		int UpdateSurf(short bondNo, short lRegionNo, GME_TYPE_OBJ_ID surfID);//2021_4_12��
		long UpdateBound(vector<gmeSurface*> &pBounds, long nStartNo = 0);
		long UpdateBound(vector<GME_TYPE_OBJ_ID> &pObjIDs, long nStartNo = 0);
		long UpdateABound(long lObjNo, gmeSurface* pObj);
		long UpdateABound(long lObjNo, GME_TYPE_OBJ_ID ObjID);

		/////
		long set(vector<s3d_Pointer<gmeSurface>> &surfvec, int idx);//2021_4_12��
		long set(vector<vector<s3d_Pointer<gmeSurface>>>  &surfvec);//2021_4_12��


		// ---------------------------- ����� ---------------------------- //
		long GetPointNum();

		long SetPoints(vector<gme_vector3d> &pPnts);
		long AddPoints(vector<gme_vector3d> &pPnts, long lPntNo = 0);
		long AddAPoint(gme_vector3d *pPnt, long lPntNo = 0);

		long DeleteAllPoints();
		long DeleteAPoint(long lPntNo);

		//��ƫ�Ƶĵ�...
		long GetPoints_Offset(vector<gme_vector3d> &pPnts);
		long GetPointsInfo_Offset(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);

		long GetPoints(vector<gme_vector3d> &pPnts);
		gme_vector3d *GetAPoint(long lPntNo);
		long GetPointsInfo(vector<gme_vector3d> &pPnts, vector<gme_vector3d> &pPntNormals, vector<gme_color4> &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pPntTexCoords);
		long GetPointsInfo(vector<gme_vector3d>* &pPnts, vector<gme_vector3d>* &pPntNormals, vector<gme_color4>* &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>>* &pPntTexCoords);

		long UpdatePoints(vector<gme_vector3d> &pPnts, long nStartPntNo = 0);
		long UpdateAPoint(long lPntNo, gme_vector3d *pPnts);

		// ---------------------------- ��Ԫ������������ ---------------------------- //
		long GetCellNum();
		long AddCellPntIndex(vector<long> &pPntIndex);
		long GetCellPntIndex(vector<long> &pPntIndex);

		// ---------------------------- ��Ԫ������������ ---------------------------- //
		long AddACellFacets(long lCellNo, gme_triangle* pFacets);
		long AddCellFacets(vector<gme_triangle> &pFacets);
		long GetACellFacets(long lCellNo, gme_triangle* &pFacets);
		long GetCellFacets(vector<gme_triangle> &pFacets);

		// ---------------------------- �ڽ���Ԫ ---------------------------- //
		long AddACellAdj(long lCellNo, long* pAdjCellIDs, long lAdjCellNumPerCell);
		long AddCellAdjs(vector<long> &pAdjCellIDs);
		long GetACellAdj(long lCellNo, long* &pAdjCellIDs, long &lAdjCellNumPerCell);
		long GetCellAdjs(vector<long> &pAdjCellIDs);

		// ---------------------------- ��Ԫ��Ƭ ---------------------------- //
		long SetFacetNumPerCell(long lNumPerCell);
		long GetFacetNumPerCell();

		//������任���� 2020-01-04 leo add from ogSimpleMesh
		bool merge(gmeEntity& srcEntity, gmeSurface& mergedSurf);
		bool merge(gmeSurface& mergedSurf);
		void calculateDefaultNormals();
		gmeEntity& swap_gm_ent(gmeEntity& ent);

		// ------------------------ �ڲ���/�ڱ߽� ------------------------ //
		// ���һ���ڲ��塣entָ��Ķ���Ӧ������Ч��ID������ID���뵱ǰ�������ڲ����ID�ظ���
		// ��ӳɹ���entָ��Ķ�����ڴ��ɱ��������������true��ʾ��ӳɹ��������ʾ����ʧ�ܡ�
		//bool AddInnerEntity(gmeEntity* ent);
		// ȡ�ڲ������Ŀ��
		//long GetInnerEntityCount() const;
		// ȡָ�����ڲ������idx�Ǵ�0��ʼ�������š������߲���ɾ�����ص�ָ�롣
		//gmeEntity* GetInnerEntity(int idx) const;
		// �Ƴ�ָ�����ڲ������idx�Ǵ�0��ʼ�������š�
		// ���ر��Ƴ�������������ڴ��ɵ����߸������
		//gmeEntity* RemoveInnerEntity(int idx);
		// �Ƴ�ָ�����ڲ������objID��Ҫ���Ƴ��Ķ����ID��
		// ���ر��Ƴ�������������ڴ��ɵ����߸��������Ӧ�Ķ��󲻴���ʱ���ؿ�ָ�롣
		//gmeEntity* RemoveInnerEntityByID(GME_TYPE_OBJ_ID objID);

	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

	private:
		//2021-11-21 Ϊ��������ӵ�gmeEntity�е�gmeSurface��˭����ģ���ʹ������ָ�룬���õ�ʱ���Զ��ͷ�.
		std::vector<vector<s3d_Pointer<gmeSurface>>> mBoundSurfs;//2021_4_11 ���ڽ���ͨȦ�����ֱ�

		vector<vector<GME_TYPE_OBJ_ID>>   mBoundSurfIDs;//2021_4_11��Ϊ��ά���飬���ڴ���Ȧ
		vector<long>              mCellPntNos;
		vector<gme_triangle>      mCellFacets;
		vector<long>              mAdjCell;
		long                      mFacetNumPerCell;
	};


	class OG_GME_API gmeDEM : public gmeGeometry//DEM����
	{
	public:
		gmeDEM();
		gmeDEM(const gmeDEM& rhs);
		virtual ~gmeDEM();
		long Load(GME_TYPE_OBJ_ID objID, long lodlevel = 0); //leo ��Ҫ����...
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);
		long ComPressSave(long lodlevel = 0);


	public:
		long SetDemInfo(gme_dem_info demInfo);
		long GetDemInfo(gme_dem_info &demInfo);

		long GetLevelNum();
		long SetLevelInfo(vector<gme_dem_level>	 demLevelInfo);
		long GetLevelInfo(vector<gme_dem_level>	 &demLevelInfo);
		long SetLevelInfo(long i, gme_dem_level  demLevelInfo);
		long GetLevelInfo(long i, gme_dem_level  &demLevelInfo);

		long SetTile(vector<gme_dem_re_tile>     demReTileInfo);
		long GetTile(vector<gme_dem_re_tile>    &demReTileInfo);
		long SetTile(long lLevelNo, long lTileXNo, long lTileYNo, vector<double> demReData);
		long GetTile(long lLevelNo, long lTileXNo, long lTileYNo, vector<double> &deRemData);

		long SetTile(vector<gme_dem_irre_tile>     demIrreTileInfo);
		long GetTile(vector<gme_dem_irre_tile>    &demIrreTileInfo);
		long SetTile(long lLevelNo, long lTileXNo, long lTileYNo, gme_IrreTileData demIrreData);
		long GetTile(long lLevelNo, long lTileXNo, long lTileYNo, gme_IrreTileData deIrremData);

	private:
		gme_dem_info			   mDemInfo;  //DEM��Ϣ
		vector<gme_dem_level>	   mDemLevelInfo;//DEM������Ϣ
		vector<gme_dem_re_tile>    mDemReTileInfo; //����dem������
		vector<gme_dem_irre_tile>  mDemIrreTileInfo;//������dem������


		friend class gmeStorageDB;
	};


	class OG_GME_API gmeGeoField : public gmeGeometry //���Գ�
	{
	public:
		gmeGeoField();
		gmeGeoField(const gmeGeoField& rhs);
		virtual ~gmeGeoField();

	public:
		gmeGeoField& operator=(gmeGeoField &rhs);
		long Clone(gmeGeoField& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID FieldID, long lodlevel=0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//����
		long CompressSave(long lodlevel=0);//ѹ���洢
		long Delete(long lodlevel=0);
		long UndoDelete(long lodlevel=0);

	public:
		long SetInfo(gme_field_info gme_field_info);
		long GetInfo(gme_field_info &gme_field_info);

		long GetLevelNum();
		long SetLevelInfo(vector<gme_field_level> FieldSplitLevelInfo);
		long SetLevelInfo(long i, gme_field_level levelInfo);
		long GetLevelInfo(long i, gme_field_level &levelInfo);

		//�����ʷ�...
		long SetTile(vector<gme_field_tile_reg> mReFieldTileReg);
		long GetTile(vector<gme_field_tile_reg> &mReFieldTileReg);
		long SetTile(long lLevelNo, long lTileXNo, long lTileYNo, long lTileZNo, gme_field_tile_reg* fieldData);
		long GetTile(long lLevelNo, long lTileXNo, long lTileYNo, long lTileZNo, gme_field_tile_reg* &fieldData);

		//�������ʷ�
		long GetCellNum();
		long SetTile(vector<gme_field_cell_data_irreg> mIrreFieldTileReg);
		long GetTile(vector<gme_field_cell_data_irreg> &mIrreFieldTileReg);
		long SetTile(long lTileXNo, long lTileYNo, long lTileZNo, gme_field_cell_data_irreg* fieldData);
		long GetTile(long lTileXNo, long lTileYNo, long lTileZNo, gme_field_cell_data_irreg* &fieldData);

		
	private:
		gme_field_info			   mFieldInfo;
		vector<gme_field_level>	   mFieldSplitLevelInfo;

		vector<gme_field_tile_reg> mReFieldTileReg;
		vector<gme_field_cell_data_irreg> mIrreFieldTileReg;
		friend class gmeStorageDB;
	};




}