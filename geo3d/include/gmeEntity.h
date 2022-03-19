#pragma once

#include "s3dGMdlDBEngineExp.h"

#include "gmeStru.h"
#include "gme_Ref.h"


namespace Smart3dMap
{
	class gmeStorageDB;


	//重新分配内存
	OG_GME_API void* _ReAllocBuf(void* pBuf, long lBufSize);
	//替换字符串
	void  OG_GME_API _Replace_Str(std::string& strName, const std::string& strSrc, const std::string& strDesc);
	//提取路径
	bool  OG_GME_API _AbstractPath(string& szPathFile, string& szPath);
	//提取文件名
	bool  OG_GME_API _AbstractFile(string& szPathFile, string& szFileName);
	//提取文件标题名
	bool  OG_GME_API _AbstractTitle(string& szPathFile, string& szFileTitle);
	//提取文件扩展名
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



	//获取可执行文件的路径
	void OG_GME_API _GetSysExePath(string& syspath);
	//生成全球唯一码...
	GString OG_GME_API _GetAUniqueString(string baseName);
	//创建三维模型数据库，DbPath传空就创建一个临时三维模型数据库
	int OG_GME_API _CreateGmeDB_Sqlite(string DbPath = "");

	//根据地层颜色获取颜色材质
	OG_GME_API string _getClrMatName(long stratColorRgb);
	//根据地层图案号和背景色获取纹理材质
	OG_GME_API string _getTexMatName(std::string graphNo, long graphClrRgb);

	//根据分隔符将字符串分割为字符串列表
	OG_GME_API vector<string> _og_split(const string& str, const string& pattern);

	OG_GME_API string LevelCode2OrderCodeTrans(string &levelCode);
	OG_GME_API string OrderCode2LevelCodeTrans(string &orderCode);

	//数据转换
	void OG_GME_API vec2dTovec3d(gme_vector2d *pdot, gme_vector3d *p3dot, double dz = 0.0);
	void OG_GME_API vec2dTovec3d(gme_vector2d *pdot, gme_vector3d *p3dot, int num, double dz = 0.0);
	void OG_GME_API vec2dTovec3d(vector<gme_vector2d> &pdotv, vector<gme_vector3d> &p3dotv, double dz = 0.0);
	void OG_GME_API vec3dTovec2d(gme_vector3d *p3dot, gme_vector2d *pdot);
	void OG_GME_API vec3dTovec2d(vector<gme_vector3d> &p3dotv, vector<gme_vector2d> &pdotv);

	//_点集定义
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
		long Clear();//清空
		long GetPointNum();//取点数

		//偏移
		long SetOffset(const gme_vector3d &offset);
		gme_vector3d& GetOffset();

		//按照增删查改顺序
		// ---------------------------- 顶点操作 ---------------------------- // 
		long SetPoints(vector<gme_vector3d> &pnts);
		long SetPointsInfo(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);
		long AddPoints(vector<gme_vector3d> &pnts, long lPntNo = 0);
		long AddAPoint(const gme_vector3d *pnt, long lPntNo = 0);

		long DeleteAllPoints();
		long DeleteAPoint(long lPntNo);

		//获取带偏移的顶点坐标
		long GetPoints_Offset(vector<gme_vector3d> &pnts);
		long GetPointsInfo_Offset(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);

		//取出不带偏移的顶点坐标...
		long GetPoints(vector<gme_vector3d> &pnts);
		vector<gme_vector3d>& GetPoints();
		gme_vector3d *GetAPoint(long lPntNo);
		long GetPointsInfo(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);
		long GetPointsInfo(vector<gme_vector3d>* &pntCoords, vector<gme_vector3d>* &pntNormals, vector<gme_color4>* &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>>* &pntTexCoords);
		long GetPointTexInfo(GME_TEXTURE_STAGE texLayer, vector<gme_tex_coord>* &pntTexCoords);

		long UpdatePoints(vector<gme_vector3d> &pnts, long nStartPntNo = 0);
		long UpdateAPoint(long lPntNo, const gme_vector3d *pnt);


		// ------------------ 点的参数操作 ----------------------- //
		//点的法向
		long AppendPntNormals(vector<gme_vector3d> &pntNormals);
		long DeleteAllPntNormals();
		long GetPntNormals(vector<gme_vector3d> &pntNormals);
		vector<gme_vector3d>& GetPntNormals();
		long UpdatePntNormals(vector<gme_vector3d> &pntNormals);
		long UpdateAPntNormal(long lPntNo, gme_vector3d* pPntNormal);

		//点的颜色
		long AppendPntColors(vector<gme_color4> &pntColors);
		long DeleteAllPntColors();
		long GetPntColors(vector<gme_color4> &pntColors);
		vector<gme_color4>& GetPntColors();
		long UpdatePntColors(vector<gme_color4> &pntColors);
		long UpdateAPntColor(long lPntNo, gme_color4* pPntColor);

		//点的纹理坐标...
		long AppendPntTexCoords(GME_TEXTURE_STAGE tsn, vector<gme_tex_coord> &pPntTexCoords);
		long DeleteAPntTexCoords(GME_TEXTURE_STAGE tsn);
		long GetPntTexCoords(GME_TEXTURE_STAGE tsn, vector<gme_tex_coord> &pPntTexCoords);
		vector<gme_tex_coord>& GetPntTexCoords(GME_TEXTURE_STAGE tsn = GME_TSN_1);
		long UpdatePntTexCoords(GME_TEXTURE_STAGE tsn, vector<gme_tex_coord> &pPntTexCoords);
		long UpdateAPntTexCoord(GME_TEXTURE_STAGE tsn, long lPntNo, gme_tex_coord* pPntTexCoord);

		// ---------------------------- 点分析 ---------------------------- // 
		long SetBox(gme_rect_3d& box); //设置包围盒
		long GetBox(gme_rect_3d& box); //获取包围盒
		//查找距离该点最近的点，返回点索引号, 错误则返回<0的数
		long FindNearestPoint(gme_vector3d *pPnts);
		//查找距离该点最近的点，范围在radius内，返回点索引号, 错误则返回<0的数
		long FindNearestPoint(gme_vector3d *pPnts, double radius);
		//查找批量点
		long FindNearestPoint(gme_vector3d *pPnts, double radius, vector<long>& indexList);

		//顶点索引类型（1-通过顶点赋色，0-通过三角形赋色）
		void setAssignClrByVertOrTriFlag(bool bFlag = 1);
		void getAssignClrByVertOrTriFlag(bool& bFlag);

		//顶点索引类型（0-通过顶点赋色，1-通过三角形赋色）
		void setClrBindType(bool bFlag = 0);
		void getClrBindType(bool& bFlag);

		//法向索引类型（0-通过顶点赋法向，1-通过三角形赋法向）
		void setNormalBindType(bool bFlag = 0);
		void getNormalBindType(bool& bFlag);


	protected:
		virtual long CalBox();//被GetBox调用,计算包围盒
		void InitOffset(gme_vector3d* offset = nullptr);

	private:
		gme_vector3d		mOffSet; //顶点偏移
		gme_rect_3d		    mBox;	  //包围盒
		vector<gme_vector2d> mPointArray_2d; //顶点坐标
		vector<gme_vector3d> mPointArray; //顶点坐标
		vector<gme_vector3d> mNormalArray;//顶点法向
		vector<gme_color4>  mColorArray; //顶点颜色
		map< GME_TEXTURE_STAGE, vector<gme_tex_coord> > mTexcoordMap;//顶点纹理坐标
		vector<vector<double>>	mPntAttVal; //每一个点有n个属性
		bool					mbAssignClrByVertOrTri; //顶点索引类型（1-通过顶点赋色，0-通过三角形赋色），
													    //决定了mColorArray、mNormalArray和mTexcoordMap的元素个数.
		bool					mbAssignNormalByVertOrTri;

	};

	//三维边
	class OG_GME_API gmeEdge
	{
		friend class gmeStorageDB;
	public:
		gmeEdge();
		gmeEdge(const gmeEdge & rhs);
		virtual ~gmeEdge();
		gmeEdge& operator=(const gmeEdge& rhs);

	public:
		long Clear();//清空

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
		// -------------------- 序列化操作 ------------------------ //
		virtual long Clear();//清空
		virtual long Load(GME_TYPE_OBJ_ID id);//从数据库重新加载
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//保存
		virtual long CompressSave();//压缩存储
		virtual gmeObject& operator=(gmeObject& obj);
		virtual long Clone(gmeObject* obj);//拷贝对象
		virtual long Delete();
		virtual long UndoDelete();

		long GetObjNum();//取逻辑数
		long GetPhyObjNum();//取物理数
		virtual long SetBox(gme_rect_3d& box); //设置包围盒
		virtual long GetBox(gme_rect_3d& box); //获取包围盒
		virtual long GetBox(gme_rect_2d& box); //获取包围盒

		long SetID(GME_TYPE_OBJ_ID lID); //对象ID
		GME_TYPE_OBJ_ID GetID(); //

		long SetName(GString strName);//设置名称
		GString GetName();//获取名称

		void SetCaption(const GString& cattion);//设置显示信息
		GString GetCaption();//取显示信息

		long GetDateTime(gme_date_time& strDateTime);//获取创建时间，由系统自动生成
		long SetDateTime(gme_date_time& strDateTime);//获取创建时间，由系统自动生成

		long SetExistFlag(bool bExistFlag); //删除标志
		long GetExistFlag(bool& bExistFlag); //删除标志

		long SetObjType(GME_OBJ_TYPE oType);//设对象类型 
		GME_OBJ_TYPE GetObjType();//取对象类型

		int SetDim(GME_DIM_TYPE dim); //设置对象维数（创建对象时确定）
		int GetDim(GME_DIM_TYPE &dim); //确定对象维数

		long SetModifyState(bool bModifyState);//设置编辑状态
		long GetModifyState(bool& bModifyState);//取编辑状态
		friend class gmeStorageDB;

		// -------------------- 存取方式 -------------------- //
		gmeStorageDB* getMdlIoObjByType(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_UNKNOWN);
		gmeStorageDB* getMdlIoObjByID(GME_TYPE_OBJ_ID mdlID = 0xFFFFFFFE);
		long getMdlIoType(GME_MDL_IO_TYPE& mdlIoType); //获取数据操作对象
		// 配置数据库存储对象。ioObj 对象的构造和析构都由调用者负责管理。
		void setGMEStorageDB(gmeStorageDB* ioObj);

	protected:
		virtual long CalBox();//被GetBox调用,计算包围盒

	protected:
		gmeStorageDB*	mPhyIoObj;//数据获取对象指针（）
		GME_MDL_IO_TYPE	mMdlIoType;//对象的存取方式
		GME_TYPE_OBJ_ID	mObjID;	  //对象ID
		GString			mObjName; //对象名称
		GString			mObjCaption; //对象描述
		gme_date_time	mDateTime;//对象创建时间
		bool			mExistFlag; //存在标志
		gme_rect_3d		mBox;	  //包围盒
		GME_OBJ_TYPE	mObjType; //对象类型
		bool			mModifyState;//修改编辑状态
		GME_DIM_TYPE	mDimension;//数据维度
		long			mSubObjNum, mPhySubObjNum;//对象里包含的子对象的个数
		vector<GME_TYPE_OBJ_ID> mSubObjIDList; //子对象的ID列表
	};


	class OG_GME_API gmeGeoRef :public gmeObject	//空间参照系
	{
		friend class  gmeStorageDB;//声明gmeStorageSqlDB为本类的友元类
	public:
		gmeGeoRef();
		virtual ~gmeGeoRef();

	public:
		long GetGeoRefNum();

		virtual long Load(GME_TYPE_OBJ_ID GeoRefID);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//保存
		virtual long CompressSave();//压缩存储
		virtual long Delete();
		virtual long UndoDelete();

		long SetParam(long lGeoID, gme_date_time gdate, GString strName,
			GString strProjCSName, double dFalseEasting, double dFalseNorthing, double dCentralMeridian, double dScaleFactor, double dLatOfOrigin, double dLenthUnit,
			GString	strGCSName, double dAnglrUnit, double dPrimeMeridian, GString strDatum, GString strSpheriod, double dSemimajorAxis, double dSemiminorAxis, double dInverseFlattening);
		long GetParam(long &lGeoID, gme_date_time &gdate, GString &strName,
			GString &strProjCSName, double &dFalseEasting, double &dFalseNorthing, double &dCentralMeridian, double &dScaleFactor, double &dLatOfOrigin, double &dLenthUnit,
			GString	&strGCSName, double &dAnglrUnit, double &dPrimeMeridian, GString &strDatum, GString &strSpheriod, double &dSemimajorAxis, double &dSemiminorAxis, double &dInverseFlattening);
	private:
		//地理参考系参数...
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


	class OG_GME_API gmeMaterialLib : public gmeObject	//材质库
	{
		friend class gmeStorageDB;
	public:
		gmeMaterialLib();
		virtual ~gmeMaterialLib();

	public:
		long GetMaterialNum();

		virtual long Load(GME_TYPE_OBJ_ID MaterialLibID);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//保存
		virtual long CompressSave();//压缩存储
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

	class OG_GME_API gmeSeries :public gmeObject	//标准地层StdStrat
	{
		friend class gmeStorageDB;
	public:
		//gmeSeries();
		//virtual ~gmeSeries();

	public:
		//long GetStdStratNum();//获取该标准地层表的地层数目
		//long GetStratNumByStdID();//暂时不用

		//virtual long Load(GME_TYPE_OBJ_ID seriesID, GString mstrStratName);//从数据库重新加载
		//virtual long Save(GME_DATA_STORAGE_TYPE lSaveType = GME_DST_TEMP);//保存
		//virtual long CompressSave(GME_DATA_STORAGE_TYPE lSaveType = GME_DST_TEMP);//压缩存储
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
		//标准地层表Cme_StdStrat
		//id、时间默认
		GString mstrStdStratName;//地层表名称
		GString mstrStdGeoType;//地层表类型 水文、工程
		GString mstrStdStratDesc;//地层表描述

		//地层 Gme_SubStrat
		//id
		GString mstrStratName;//地层名称
		GString mstrStratCode;//地层编码
		GString mstrStratLevel;//级别编码
		GString mstrLithology;//岩性
		GString mstrGeoRelation;//相互关系
		GString mstrAge;//地质年代
		GString mstrCause;//成因
		GString mstrStratDesc;//地层描述

		//地层材质 Gme_StdStratMat
		//地质类型（水文 工程）；地层编码
		long	mlMaterialLibID;//材质id
		GString mstrMatLibName;//材质库名称
		GString mstrClrMatName;//颜色材质名称
		int     miStratClr;//材质颜色
		GString mstrTexMatName;//纹理材质名称
		int     miStratTexID;//材质纹理号
		int     miStratTexHeight;//材质高度
		int     miStratTexWidth;//材质宽度
		GString mstrStratTexBKClr;//材质背景	
	};



	class OG_GME_API gmeLegend : public gmeObject	//图例
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


		virtual long Load(GME_TYPE_OBJ_ID LegendID);//从数据库重新加载
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//保存
		virtual long CompressSave();//压缩存储
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

	class OG_GME_API gmeNote : public gmeObject	//注记
	{
		friend class gmeStorageDB;
	public:
		gmeNote();
		virtual ~gmeNote();

	public:
		long GetNoteNum();
		long GetLegendCellNum(long lLegendID);

		virtual long Load(GME_TYPE_OBJ_ID NoteID);//从数据库重新加载
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//保存
		virtual long Delete();
		virtual long CompressSave();//压缩存储
		virtual long UndoDelete();

		long SetParam(long lNoteID, gme_date_time gdate, gme_note_info* noteInfo, vector<gme_note_content> noteData);
		long GetParam(long &lNoteID, gme_date_time &gdate, gme_note_info* &noteInfo, vector<gme_note_content> &noteData);

	private:
		gme_note_info mNoteInfo;
		vector<gme_note_content> mNoteData;
	};


	class OG_GME_API gmeGeometry : public gmeObject //基础几何数据对象
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
		virtual long Clone(gmeGeometry& obj);//拷贝对象
		virtual long Clear();//清空
		virtual long Load(GME_TYPE_OBJ_ID objID, long lodLevel=0);//从数据库重新加载
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel=0);//保存
		virtual long CompressSave(long lodLevel=0);//压缩存储
		virtual long Delete(long lodLevel=0);
		virtual long UndoDelete(long lodLevel=0);

		long SetOffset(const gme_vector3d &offset);
		gme_vector3d& GetOffset();

		// ---------------------------- 拓扑信息 ---------------------------- //
		long SetTopoObj(GME_TYPE_OBJ_ID& lLeftObjID, GME_TYPE_OBJ_ID& lRightObjID);
		long GetTopoInfo(GME_TYPE_OBJ_ID& lLeftObjID, GME_TYPE_OBJ_ID& lRightObjID);

		long SetPntSet(gmePntSet &pntSet);//设置点集
		long DeletePntSet();//删除点集
		long GetPntSet(gmePntSet &pntSet);//获取点集
		gmePntSet* GetPntSet();
		long Update(gmePntSet &pntSet);//更新点集

		virtual long SetMaterialName(GString MaterialName[2]);
		virtual long SetPosMatName(GString MaterialName);
		long SetPosMatName2Null();//材质置空
		virtual long SetNegMatName(GString MaterialName);
		long SetNegMatName2Null();//材质置空
		virtual GString GetPosMatName();
		virtual GString GetNegMatName();

		long SetMaterialInfo(GME_MATERIAL_TYPE matType, GString strMatName, GME_MATERIAL_SIDE matSide = GME_MS_POSITIVE);//设置材质
		long GetMaterialInfo(GME_MATERIAL_TYPE &matType, GString &strMatName, GME_MATERIAL_SIDE matSide = GME_MS_POSITIVE);//获取材质

		//几何对象的注记
		void SetNote(gmeNote* note);
		gmeNote* GetNote();

		// ---------------------------- 几何对象基本操作 ---------------------------- //
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
		virtual long CalBox();//被GetBox调用,计算包围盒

	public:
		GME_TYPE_OBJ_ID		mLeftObjID;
		GME_TYPE_OBJ_ID		mRightObjID;
		gmePntSet			mPntSet; //顶点数据
		GME_MATERIAL_TYPE	mMatType[2];//正反两面材质的类型(一般只设置正面)
		GString				mMatName[2];//正反两面材质的名称
		gmeNote				mNote;	//几何对象对应的注记
	};



	class OG_GME_API gmeCorner : public gmeGeometry //结点
	{
		friend class gmeStorageDB;

	public:
		gmeCorner();
		gmeCorner(const gmeCorner&rhs);
		virtual ~gmeCorner();

	public:
		gmeCorner& operator=(gmeCorner &rhs);
		long Clone(gmeCorner& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID CornerID,long lodlevel = 0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);//保存
		long CompressSave(long lodlevel = 0);//压缩存储
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);
		long SetPoint(const gme_vector3d *p3DPnt);
		long DeletePoint();
		long GetPoint(gme_vector3d *p3DPnt);
		long UpdateAPoint(const gme_vector3d *p3DPnt);
		long SetPointPara(CPointStyleParam &PntPara);
		long GetPointPara(CPointStyleParam &PntPara);

	protected:
		virtual long CalBox();//被GetBox调用,计算包围盒

	private:
		gme_vector3d mPntPos;
		CPointStyleParam mPntPara;
	};


	class OG_GME_API gmeLine : public gmeGeometry //线
	{
		friend class gmeStorageDB;
	public:
		gmeLine();
		gmeLine(const gmeLine& rhs);
		virtual ~gmeLine();

	public:
		gmeLine& operator=(gmeLine &rhs);
		long Clone(gmeLine& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID linID, long lodlevel = 0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);//保存
		long CompressSave(long lodlevel = 0);//压缩存储
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);

	public:
		//线宽操作
		long SetLineWidth(double lineWidth);
		double GetLineWidth();

		//以点集的方式操作顶点见基类gmeGeometry
		// ---------------------------- 顶点操作 ---------------------------- // 
		long GetPointNum();

		void* init(int dotnum);
		long SetPoints(gme_vector2d*pPnts, long dotnum);
		long SetPoints(gme_vector3d*pPnts, long dotnum);
		long SetPoints(vector<gme_vector3d> &pPnts);
		long AddPoints(vector<gme_vector3d> &pPnts, long lPntNo = 0);
		long AddAPoint(const gme_vector3d *pPnt, long lPntNo = 0);

		long DeleteAllPoints();
		long DeleteAPoint(long lPntNo);

		//获取带偏移的顶点坐标
		long GetPoints_Offset(vector<gme_vector3d> &pnts);
		long GetPointsInfo_Offset(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);

		//取点坐标
		gme_vector3d* ptXYZ();
		gme_vector2d* GetPoints_2d();
		vector<gme_vector3d>& GetPoints();
		long GetPoints(vector<gme_vector3d> &pPnts);//返回不带偏移的坐标
		gme_vector3d* GetAPoint(long lPntNo);
		long GetPointsInfo(vector<gme_vector3d> &pPnts, vector<gme_vector3d> &pPntNormals, vector<gme_color4> &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pPntTexCoords);
		long GetPointsInfo(vector<gme_vector3d>* &pPnts, vector<gme_vector3d>* &pPntNormals, vector<gme_color4>* &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>>* &pPntTexCoords);

		long UpdatePoints(vector<gme_vector3d> &pPnts, long nStartPntNo = 0);
		long UpdateAPoint(const gme_vector3d *pPnts, long lPntNo);

		// ---------------------------- 线上的结点操作 ---------------------------- // 
		long SetCorners(gmeCorner pCorners[2], long lCornerNum = 2);
		long SetCorners(GME_TYPE_OBJ_ID pBoundIDs[2], long lCornerNum = 2);
		long DeleteAllCorners();
		long GetCorners(gmeCorner p3DCorners[2]);
		long UpdateCorners(gmeCorner pCorners[2], long lCornerNum = 2);

		// ---------------------------- 线上边的操作 ---------------------------- // 
		long GetEdgeNum();
		long GetPhyEdgeNum();
		long SetEdges(const vector<gmeEdge> &pEdges);
		long AddEdges(const vector<gmeEdge> &pEdges, long lEdgeNo = 0);
		long DeleteAllEdges();
		long GetEdges(vector<gmeEdge> &pEdges);
		long GetPhyEdges(vector<gmeEdge> &pEdges);//取出物理数的边数据 
		long UpdateEdges(vector<gmeEdge> &pEdges, long lStartEdgeNo = 0);

		// ---------------------------- 线参数的操作 ---------------------------- // 
		long SetLinePara(CLineStyleParam &LinPara);
		long GetLinePara(CLineStyleParam &LinPara);
	private:
		//线上的顶点在基类中已定义
		GME_TYPE_OBJ_ID		mLinCorner[2]; //线的结点（2个）
		vector<gmeEdge>	mLinEdge;   //线的边
		double			mLineWidth;
		CLineStyleParam mLinPara;
	};
	typedef gmeLine* CAnyLinePTR;



	class  OG_GME_API gmeSurface : public gmeGeometry //面
	{
		friend class gmeStorageDB;
	public:
		gmeSurface();
		gmeSurface(const gmeSurface& surface);
		virtual ~gmeSurface();

	public:
		gmeSurface&	 operator=(gmeSurface &rhs);
		long Clone(gmeSurface& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID surID,long lodLevel=0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel=0);//保存
		long CompressSave( GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB,long lodLevel=0);//压缩存储
		long Delete(long lodlevel=0);
		long DeleteAllLod();
		long UndoDelete(long lodlevel=0);
		

	public:
		// ---------------------------- 边界操作（线列表） ---------------------------- //
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


		// ---------------------------- 点操作 ---------------------------- //
		long GetPointNum();
		long AddPoints(vector<gme_vector3d> &pPnts);
		long AddAPoint(gme_vector3d *pPnt, long lPntNo = 0);
		long SetPoints(vector<gme_vector3d> &pPnts);
		long SetPointsInfo(vector<gme_vector3d> &pPnts, vector<gme_vector3d> &pPntNormals, vector<gme_color4> &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pPntTexCoords);
		long DeleteAllPoints();
		long DeleteAPoint(long lPntNo);

		//带偏移的点...
		long GetPoints_Offset(vector<gme_vector3d> &pPnts);
		long GetPointsInfo_Offset(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);

		long GetPoints(vector<gme_vector3d> &pPnts);
		gme_vector3d*	 GetPointsPtr();
		vector<gme_vector3d>& GetPoints();
		vector<gme_vector3d>& GetNormals();
		vector<gme_color4>& GetColors();

		vector<gme_tex_coord>& GetTexCoords();
		int* GetColorsPtr();//顶点颜色，长度为pntnum
		gme_vector3d* GetNormalsPtr();//顶点法向量，长度为pntnum
		gme_vector2d* GetTexCoordsPtr();//顶点纹理坐标，长度为pntnum

		int GetTexLayerNum();//纹理坐标层数
		gme_vector3d* GetAPoint(long lPntNo);
		long GetPointsInfo(vector<gme_vector3d> &pPnts, vector<gme_vector3d> &pPntNormals, vector<gme_color4> &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pPntTexCoords);
		long GetPointsInfo(vector<gme_vector3d>* &pPnts, vector<gme_vector3d>* &pPntNormals, vector<gme_color4>* &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>>* &pPntTexCoords);

		long UpdatePoints(vector<gme_vector3d> &pPnts, long nStartPntNo = 0);
		long UpdateAPoint(long lPntNo, gme_vector3d *pPnts);


		// ---------------------------- 三角形操作 ---------------------------- //
		//批量三角形
		long GetTriangleNum();
		long GetTriangleTopNum();

		long SetTriangles(vector<gme_triangle> &pTriangle, vector<gme_triangle_top> &pTriangleTop);
		long AddTriangles(vector<gme_triangle> &pTriangle, vector<gme_triangle_top> &pTriangleTop);
		long AddATriangle(gme_triangle* pTriangle, gme_triangle_top* pTriangleTop);

		long RemoveAllTriangle();
		long RemoveATriangle(gme_triangle* pTriangle);
		long RemoveATriangle(long nTriNo);

		int* GetTrianglesPtr();           //三角形顶点序列，长度为3*trinum
		gme_triangle* getTrianglesPtr();           //三角形顶点序列，长度为trinum
		long GetTriangles(vector<gme_triangle> &pTriangle, vector<gme_triangle_top> &pTriangleTop);
		long GetATriangle(long nTriNo, gme_triangle* pTriangle, gme_triangle_top* pTriangleTop);
		vector<gme_triangle>& GetTriangles();
		vector<gme_triangle_top>& GetTriangleTops();
		int* GetTriangleTopsPtr();          //三角形边top，长度为3*trinum
		gme_triangle_top* getTriangleTopsPtr();          //三角形边top，长度为trinum

		long UpdateTriangles(vector<gme_triangle> &pTriangle, vector<gme_triangle_top> &pTriangleTop, long nStartTriNo = 0);
		long UpdateATriangle(long nTriNo, gme_triangle *pTriangle, gme_triangle_top* pTriangleTop);

		//面参数操作
		long SetSurfPara(CSurfaceStyleParam &SurfPara);
		long GetSurfPara(CSurfaceStyleParam &SurfPara);

		//面类型操作
		long SetSurfType(GME_SURF_TYPE SurfType);
		long GetSurfType(GME_SURF_TYPE &SurfType);
		GME_SURF_TYPE GetSurfType();

		//顶点索引类型（0-通过顶点赋色，1-通过三角形赋色）
		void setClrBindType(bool bFlag = 0);
		void getClrBindType(bool& bFlag);

		//顶点索引类型（0-通过顶点赋色，1-通过三角形赋色）
		void setNormalBindType(bool bFlag = 0);
		void getNormalBindType(bool& bFlag);

		//曲面变换操作 2020-01-04 leo add from ogSimpleMesh
		void convertPostionsToLocalCoordinate(const gme_vector3d& center); //坐标平移
		void calculateDefaultNormals();    //计算缺省法向
		long calMeshTop(long lSuffix = 0); //计算面的拓扑...
		//coord表示坐标轴，0-X轴，1-Y轴，2-Z轴
		void makerotate(long coord, double angle);
		void makerotate(gme_vector3d& point, long coord, double angle);
		void getMeshcenter(gme_vector3d& center);
		long getIndexBufferSize();
		bool merge(gmeSurface* src);
		//交换面
		gmeSurface& swap_gm_surf(gmeSurface& sur);
		//计算纹理坐标（侧面）
		void calTexCoord(gme_vector3d* poly = NULL, long polydotsnum = 0, gme_rect_2d* rsImageBox = NULL);
		void MatchTexCoord();//使得纹理坐标与顶点数一致
		//面内存变量赋值...
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

		//设置某一个级别的面模型
		void setLodSurf(s3d_Pointer<gmeSurface>& lodSurf, long lodLevel = 1);
		//取出某一个级别的面模型
		void getLodSurf(gmeSurface& lodSurf, long lodLevel = 0);
		//获取一个面的Lod级别数量，用于按照级别遍历面的Lod  wzj 2021.8.18
		long getLodLevelNum();
		//取出面的lod
		void getLodLevelList(map<long, s3d_Pointer<gmeSurface>> & lodSurfList);
		// 获取一个面现有的Level级别号列表  wzj 2021.8.18
		void getLodLevelList(vector<long>& lodIDList);


		
	private:
		vector<GME_TYPE_OBJ_ID>  mSurfLinIDs;
		vector<gmeLine*>		 mSurfLins;

		vector<gme_triangle>     mTriangles;
		vector<gme_triangle_top> mTriangleTops;
		CSurfaceStyleParam       mSurfPara;
		GME_SURF_TYPE            mSurfType;

		long					mSurfRowNo, mSurfColNo;
		map<long, s3d_Pointer<gmeSurface>> mLodSurf; //曲面的lod
	};


	class OG_GME_API gmeEntity : public gmeGeometry //体
	{
		friend class gmeStorageDB;
	public:
		gmeEntity();
		gmeEntity(const gmeEntity& rhs);
		virtual ~gmeEntity();

	public:
		gmeEntity&	 operator=(gmeEntity &rhs);
		long Clone(gmeEntity& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID EntityID,long lodlevel=0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//保存
		long CompressSave(long lodlevel=0);//压缩存储
		long Delete(long lodlevel=0);
		long UndoDelete(long lodlevel=0);
		
		
	public:
		// ---------------------------- 边界操作（线列表） ---------------------------- //
		/////已测试,GetBoundNum要修改(防止数组越界)，GetSurfaceNum要修改
		long GetSurfaceNum() { return GetBoundNum(); }
		long GetBoundNum();//获取指定圈层的面数量，默认是外圈层////////加一个short boundNo
		long GetEntRingNum();//获取圈层的数量
		long GetTotalSurfNum();//获取所有面的个数，不区分圈层
		long GetTotalSurfIDNum();//获取所有面ID的个数，不区分圈层

		//AddSurface与AddABound函数意义相同，就是向体中添加一个面
		gmeSurface*	AddSurface(string name = "");
		void AddSurface(gmeSurface*surf);
		void AddSurface(gmeSurface&surf);
		void AddSurface(s3d_Pointer<gmeSurface>& surf);

		gmeSurface*	AddABound(string name = "", int boundNo = 0);//推荐使用 内部自动申请gmeSurface
		void AddABound(gmeSurface*surf, int boundNo = 0);//由外面申请gmeSurface
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
		gmeSurface* GetABound(short boundNo, short lRegionNo);//2021_4_12加
		gmeSurface* GetABound(const string& name);
		long GetABound(short lObjNo, GME_TYPE_OBJ_ID& ObjID);
		long GetABound(short bondNo, short lRegionNo, GME_TYPE_OBJ_ID& ObjID);//2021_4_12加
		long GetBound(vector<gmeSurface*>& pBounds);
		long GetBound(vector<GME_TYPE_OBJ_ID>& pObjIDs);
		long GetBound(vector<GME_TYPE_OBJ_ID>& pObjIDs, int boundNo);//2021_4_12加
		long GetBound(vector<gmeSurface*>& pBounds, short boundNo);//2021_4_13加
		std::vector<gmeSurface*> GetBound();//获取所有的面，将所有圈层的面加入到一维数组中返回
		std::vector<gmeSurface*> GetBound(int boundNo);//获取某一圈层的面列表，//2021_4_12加
		vector<vector<s3d_Pointer<gmeSurface>>>& getAllSurface();//2021_4_12加
		//////yc
		int UpdateSurf(int idx, gmeSurface& surfObj);
		int UpdateSurf(short boundNo, short lRegionNo, gmeSurface& surfObj);//2021_4_12加
		int UpdateSurf(int idx, GME_TYPE_OBJ_ID surfID);//更新idx位置的面ID号, /////这个函数是Updata,与上下函数不同名
		int UpdateSurf(short bondNo, short lRegionNo, GME_TYPE_OBJ_ID surfID);//2021_4_12加
		long UpdateBound(vector<gmeSurface*> &pBounds, long nStartNo = 0);
		long UpdateBound(vector<GME_TYPE_OBJ_ID> &pObjIDs, long nStartNo = 0);
		long UpdateABound(long lObjNo, gmeSurface* pObj);
		long UpdateABound(long lObjNo, GME_TYPE_OBJ_ID ObjID);

		/////
		long set(vector<s3d_Pointer<gmeSurface>> &surfvec, int idx);//2021_4_12加
		long set(vector<vector<s3d_Pointer<gmeSurface>>>  &surfvec);//2021_4_12加


		// ---------------------------- 点操作 ---------------------------- //
		long GetPointNum();

		long SetPoints(vector<gme_vector3d> &pPnts);
		long AddPoints(vector<gme_vector3d> &pPnts, long lPntNo = 0);
		long AddAPoint(gme_vector3d *pPnt, long lPntNo = 0);

		long DeleteAllPoints();
		long DeleteAPoint(long lPntNo);

		//带偏移的点...
		long GetPoints_Offset(vector<gme_vector3d> &pPnts);
		long GetPointsInfo_Offset(vector<gme_vector3d> &pntCoords, vector<gme_vector3d> &pntNormals, vector<gme_color4> &pntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pntTexCoords);

		long GetPoints(vector<gme_vector3d> &pPnts);
		gme_vector3d *GetAPoint(long lPntNo);
		long GetPointsInfo(vector<gme_vector3d> &pPnts, vector<gme_vector3d> &pPntNormals, vector<gme_color4> &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>> &pPntTexCoords);
		long GetPointsInfo(vector<gme_vector3d>* &pPnts, vector<gme_vector3d>* &pPntNormals, vector<gme_color4>* &pPntColors, map<GME_TEXTURE_STAGE, vector<gme_tex_coord>>* &pPntTexCoords);

		long UpdatePoints(vector<gme_vector3d> &pPnts, long nStartPntNo = 0);
		long UpdateAPoint(long lPntNo, gme_vector3d *pPnts);

		// ---------------------------- 体元顶点索引操作 ---------------------------- //
		long GetCellNum();
		long AddCellPntIndex(vector<long> &pPntIndex);
		long GetCellPntIndex(vector<long> &pPntIndex);

		// ---------------------------- 体元顶点索引操作 ---------------------------- //
		long AddACellFacets(long lCellNo, gme_triangle* pFacets);
		long AddCellFacets(vector<gme_triangle> &pFacets);
		long GetACellFacets(long lCellNo, gme_triangle* &pFacets);
		long GetCellFacets(vector<gme_triangle> &pFacets);

		// ---------------------------- 邻接体元 ---------------------------- //
		long AddACellAdj(long lCellNo, long* pAdjCellIDs, long lAdjCellNumPerCell);
		long AddCellAdjs(vector<long> &pAdjCellIDs);
		long GetACellAdj(long lCellNo, long* &pAdjCellIDs, long &lAdjCellNumPerCell);
		long GetCellAdjs(vector<long> &pAdjCellIDs);

		// ---------------------------- 体元面片 ---------------------------- //
		long SetFacetNumPerCell(long lNumPerCell);
		long GetFacetNumPerCell();

		//多曲面变换操作 2020-01-04 leo add from ogSimpleMesh
		bool merge(gmeEntity& srcEntity, gmeSurface& mergedSurf);
		bool merge(gmeSurface& mergedSurf);
		void calculateDefaultNormals();
		gmeEntity& swap_gm_ent(gmeEntity& ent);

		// ------------------------ 内部体/内边界 ------------------------ //
		// 添加一个内部体。ent指向的对象应该已有效的ID，并且ID不与当前体其它内部体的ID重复。
		// 添加成功后ent指向的对象的内存由本对象负责管理。返回true表示添加成功，否则表示操作失败。
		//bool AddInnerEntity(gmeEntity* ent);
		// 取内部体的数目。
		//long GetInnerEntityCount() const;
		// 取指定的内部体对象。idx是从0开始的索引号。调用者不能删除返回的指针。
		//gmeEntity* GetInnerEntity(int idx) const;
		// 移除指定的内部体对象。idx是从0开始的索引号。
		// 返回被移除的体对象，且其内存由调用者负责管理。
		//gmeEntity* RemoveInnerEntity(int idx);
		// 移除指定的内部体对象。objID是要被移除的对象的ID。
		// 返回被移除的体对象，且其内存由调用者负责管理。对应的对象不存在时返回空指针。
		//gmeEntity* RemoveInnerEntityByID(GME_TYPE_OBJ_ID objID);

	protected:
		virtual long CalBox();//被GetBox调用,计算包围盒

	private:
		//2021-11-21 为了区分添加到gmeEntity中的gmeSurface是谁申请的，就使用智能指针，不用的时候自动释放.
		std::vector<vector<s3d_Pointer<gmeSurface>>> mBoundSurfs;//2021_4_11 用于将不通圈层的面分别开

		vector<vector<GME_TYPE_OBJ_ID>>   mBoundSurfIDs;//2021_4_11改为二维数组，用于存多个圈
		vector<long>              mCellPntNos;
		vector<gme_triangle>      mCellFacets;
		vector<long>              mAdjCell;
		long                      mFacetNumPerCell;
	};


	class OG_GME_API gmeDEM : public gmeGeometry//DEM数据
	{
	public:
		gmeDEM();
		gmeDEM(const gmeDEM& rhs);
		virtual ~gmeDEM();
		long Load(GME_TYPE_OBJ_ID objID, long lodlevel = 0); //leo 需要补充...
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
		gme_dem_info			   mDemInfo;  //DEM信息
		vector<gme_dem_level>	   mDemLevelInfo;//DEM级别信息
		vector<gme_dem_re_tile>    mDemReTileInfo; //规则dem块数据
		vector<gme_dem_irre_tile>  mDemIrreTileInfo;//不规则dem块数据


		friend class gmeStorageDB;
	};


	class OG_GME_API gmeGeoField : public gmeGeometry //属性场
	{
	public:
		gmeGeoField();
		gmeGeoField(const gmeGeoField& rhs);
		virtual ~gmeGeoField();

	public:
		gmeGeoField& operator=(gmeGeoField &rhs);
		long Clone(gmeGeoField& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID FieldID, long lodlevel=0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//保存
		long CompressSave(long lodlevel=0);//压缩存储
		long Delete(long lodlevel=0);
		long UndoDelete(long lodlevel=0);

	public:
		long SetInfo(gme_field_info gme_field_info);
		long GetInfo(gme_field_info &gme_field_info);

		long GetLevelNum();
		long SetLevelInfo(vector<gme_field_level> FieldSplitLevelInfo);
		long SetLevelInfo(long i, gme_field_level levelInfo);
		long GetLevelInfo(long i, gme_field_level &levelInfo);

		//均匀剖分...
		long SetTile(vector<gme_field_tile_reg> mReFieldTileReg);
		long GetTile(vector<gme_field_tile_reg> &mReFieldTileReg);
		long SetTile(long lLevelNo, long lTileXNo, long lTileYNo, long lTileZNo, gme_field_tile_reg* fieldData);
		long GetTile(long lLevelNo, long lTileXNo, long lTileYNo, long lTileZNo, gme_field_tile_reg* &fieldData);

		//不均匀剖分
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