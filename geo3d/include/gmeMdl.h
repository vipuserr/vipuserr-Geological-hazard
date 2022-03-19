#pragma once


#include "s3dGMdlDBEngineExp.h"
#include "gmeFeatureCls.h"
#include "s3dSqlsBase.h"


namespace Smart3dMap
{

	class gmeModel;
	class OG_GME_API gmeDataBase : gmeObject	//数据库
	{
	private:
		gmeDataBase();
		virtual ~gmeDataBase();

	public:
		static gmeDataBase* getSingletonPtr();
		static gmeDataBase& getSingleton();


	public:
		// -------------------- 基本操作 -------------------- //
		//打开数据库，并返回数据库连接对象（如果已经连接，则直接返回连接对象）
		virtual __int64 Open(const GString& strDBUrl="", GME_LinkType linktype = GME_DB_LINK_SQLITE, const GString& strUserName="", const GString& strPswName="");//打开数据库
		virtual __int64 Open(GME_LinkType linkType, const GString& strHost, const GString& strPort, const GString& dbName, const GString& strUserName, const GString& strPswName);//打开数据库
		virtual	long Close(); //关闭数据库
		virtual DB_CONN_INFO& getDbInfo();
		//设置当前的数据库连接
		virtual void setCurDbConn(__int64 conn);
		//获取当前的数据库连接
		virtual __int64 getCurDbConn();


		virtual long Clear();  //清空数据库
		virtual	bool IsOpened();//取数据库打开状态
		void  setAutoCommit(BOOL type);
		void commitAll();

		//模型版本信息
		virtual long SetVersion(long lMajorVer, long lMinorVer, long l3rdVer);
		virtual long GetVersion(long &lMajorVer, long &lMinorVer, long &l3rdVer);
		virtual long GetVersion(GString &strVer);

		//获取模型数量、模型ID、名称等
		virtual long GetModelNum(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);
		virtual long GetModelIDList(vector<GME_TYPE_OBJ_ID> &mdlIDList, GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);
		virtual long GetModelInfList(map<GME_TYPE_OBJ_ID, GString> &mdlNameList, GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);

		//根据类型取默认要素类
		virtual GME_TYPE_OBJ_ID getFClsID(GME_FCLS_TYPE fClsType);
		virtual  gmeFeatureCls* getFCls(GME_FCLS_TYPE fClsType);

		//根据sql语句文件读出所有的sql语句
		virtual std::vector<std::string>& getAllSqlsFromFile();
		//建立所有的表结构
		virtual void createAllTbls(std::vector<std::string>& sqllist);

	protected:
		long			mlMajorVer, mlMinorVer, ml3rdVer;//模型版本 //leo20200202
		std::vector<std::string>	mGmeSqlList;
	};


	class OG_GME_API gmeModel : public gmeGeometry //模型
	{
		friend class gmeStorageDB;
	public:
		gmeModel();
		virtual ~gmeModel();

		virtual long Clone(gmeModel* obj);//拷贝对象
		virtual long Clear();//清空
		virtual long Load(GME_TYPE_OBJ_ID mdlID, long lodLevel=0);//从数据库重新加载
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel = 0);//保存
		virtual long CompressSave(long lodLevel = 0);//压缩存储
		virtual long Delete(long lodLevel = 0);
		virtual long UndoDelete(long lodLevel = 0);


	public:
		//模型类型(结构模型/属性模型/钻孔模型/剖面模型/...)
		void SetModelType(GME_MODEL_TYPE mdlType);
		GME_MODEL_TYPE GetModelType();

		//模型图例
		void SetLegend(gmeLegend *legend);
		gmeLegend *GetLegend();

		//模型对应的标准地层
		void SetSeries(gmeSeries* segies);
		gmeSeries* GetSeries();

		//模型对应的坐标参考系
		void SetGeoRef(gmeGeoRef* geoRef);
		gmeGeoRef* GetGeoRef();

		//子模型
		long GetSubModelsNum();
		gmeModel* AddASubModel(const string& name="");//推荐使用...
		long DeleteASubModel(long subModelIdx);
		long DeleteAllSubModels();
		long GetSubModels(vector<gmeModel*>& subModelList);
		long GetSubModelIDs(vector<GME_TYPE_OBJ_ID>& subModelList);
		gmeModel* GetASubModel(short subModelIdx);
		long UpdateASubModel(long subModelIdx, gmeModel& subModel);

		//取出模型中的要素类型的个数
		long GetFeatClsNum();
		GME_TYPE_OBJ_ID GetAFeatCls(long i);

		gmeFeature* AddAFeature(GME_TYPE_OBJ_ID fClsID, const string& name=""); //推荐使用....
		long AddAFeature(gmeFeature& feat);
		long DeleteAFeature(GME_TYPE_OBJ_ID fClsID, long featureIdx);
		long DeleteAllFeature();
		//获取模型中某一要素类中的要素个数
		long GetFeatureNum(GME_TYPE_OBJ_ID fClsID);
		//获取模型中某一要素类中的要素,featIdx为要素的序号，而不是ID
		gmeFeature* GetAFeature(GME_TYPE_OBJ_ID fClsID, short featureIdx);
		long GetFeatureIDs(GME_TYPE_OBJ_ID fClsID, vector<GME_TYPE_OBJ_ID>& featureIDs);
		long GetAllFeatureIDs(vector<gme_mdl_featID>& mdlFeatIDList);
		long UpdateAFeature(GME_TYPE_OBJ_ID fClsID, long i, gmeFeature& feat);
		map<GME_TYPE_OBJ_ID, vector<gmeFeature*>>* GetAllMdlFeatures();
		gme_vector3d GetOffset();
	protected:
		virtual long CalBox();//被GetBox调用,计算包围盒

	private:
		//注记ID记在基类里
		gmeLegend				mLegend;//模型图例
		gmeSeries				mSeries;//标准地层
		gmeGeoRef				mGeoRef;//空间参考系
		GME_MODEL_TYPE			mMdlType;	  //模型类型(结构模型/属性模型/钻孔模型/剖面模型/...)
		vector<gmeModel*> mSubMdlList; //子模型列表
		vector<GME_TYPE_OBJ_ID> mSubMdlIDList; //子模型ID列表
		map<GME_TYPE_OBJ_ID, vector<gmeFeature*>> mMdlFeatList; //模型中的要素列表，按要素类进行分类
		vector<gme_mdl_featID> mMdlFeatIDList; //模型中的要素ID列表，按要素类进行分类
	};

	OG_GME_API  gmeModel* createGmeModel(string mdlName = "");
	void OG_GME_API releaseGmeModel(gmeModel* &mdl);
	OG_GME_API gmeModel* saveHoleModelIntoGmeDB(vector<gme_hole>& holeInfo);

}

