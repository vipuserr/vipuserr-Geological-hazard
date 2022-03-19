#pragma once


#include "s3dGMdlDBEngineExp.h"
#include "gmeFeatureCls.h"
#include "s3dSqlsBase.h"


namespace Smart3dMap
{

	class gmeModel;
	class OG_GME_API gmeDataBase : gmeObject	//���ݿ�
	{
	private:
		gmeDataBase();
		virtual ~gmeDataBase();

	public:
		static gmeDataBase* getSingletonPtr();
		static gmeDataBase& getSingleton();


	public:
		// -------------------- �������� -------------------- //
		//�����ݿ⣬���������ݿ����Ӷ�������Ѿ����ӣ���ֱ�ӷ������Ӷ���
		virtual __int64 Open(const GString& strDBUrl="", GME_LinkType linktype = GME_DB_LINK_SQLITE, const GString& strUserName="", const GString& strPswName="");//�����ݿ�
		virtual __int64 Open(GME_LinkType linkType, const GString& strHost, const GString& strPort, const GString& dbName, const GString& strUserName, const GString& strPswName);//�����ݿ�
		virtual	long Close(); //�ر����ݿ�
		virtual DB_CONN_INFO& getDbInfo();
		//���õ�ǰ�����ݿ�����
		virtual void setCurDbConn(__int64 conn);
		//��ȡ��ǰ�����ݿ�����
		virtual __int64 getCurDbConn();


		virtual long Clear();  //������ݿ�
		virtual	bool IsOpened();//ȡ���ݿ��״̬
		void  setAutoCommit(BOOL type);
		void commitAll();

		//ģ�Ͱ汾��Ϣ
		virtual long SetVersion(long lMajorVer, long lMinorVer, long l3rdVer);
		virtual long GetVersion(long &lMajorVer, long &lMinorVer, long &l3rdVer);
		virtual long GetVersion(GString &strVer);

		//��ȡģ��������ģ��ID�����Ƶ�
		virtual long GetModelNum(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);
		virtual long GetModelIDList(vector<GME_TYPE_OBJ_ID> &mdlIDList, GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);
		virtual long GetModelInfList(map<GME_TYPE_OBJ_ID, GString> &mdlNameList, GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);

		//��������ȡĬ��Ҫ����
		virtual GME_TYPE_OBJ_ID getFClsID(GME_FCLS_TYPE fClsType);
		virtual  gmeFeatureCls* getFCls(GME_FCLS_TYPE fClsType);

		//����sql����ļ��������е�sql���
		virtual std::vector<std::string>& getAllSqlsFromFile();
		//�������еı�ṹ
		virtual void createAllTbls(std::vector<std::string>& sqllist);

	protected:
		long			mlMajorVer, mlMinorVer, ml3rdVer;//ģ�Ͱ汾 //leo20200202
		std::vector<std::string>	mGmeSqlList;
	};


	class OG_GME_API gmeModel : public gmeGeometry //ģ��
	{
		friend class gmeStorageDB;
	public:
		gmeModel();
		virtual ~gmeModel();

		virtual long Clone(gmeModel* obj);//��������
		virtual long Clear();//���
		virtual long Load(GME_TYPE_OBJ_ID mdlID, long lodLevel=0);//�����ݿ����¼���
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel = 0);//����
		virtual long CompressSave(long lodLevel = 0);//ѹ���洢
		virtual long Delete(long lodLevel = 0);
		virtual long UndoDelete(long lodLevel = 0);


	public:
		//ģ������(�ṹģ��/����ģ��/���ģ��/����ģ��/...)
		void SetModelType(GME_MODEL_TYPE mdlType);
		GME_MODEL_TYPE GetModelType();

		//ģ��ͼ��
		void SetLegend(gmeLegend *legend);
		gmeLegend *GetLegend();

		//ģ�Ͷ�Ӧ�ı�׼�ز�
		void SetSeries(gmeSeries* segies);
		gmeSeries* GetSeries();

		//ģ�Ͷ�Ӧ������ο�ϵ
		void SetGeoRef(gmeGeoRef* geoRef);
		gmeGeoRef* GetGeoRef();

		//��ģ��
		long GetSubModelsNum();
		gmeModel* AddASubModel(const string& name="");//�Ƽ�ʹ��...
		long DeleteASubModel(long subModelIdx);
		long DeleteAllSubModels();
		long GetSubModels(vector<gmeModel*>& subModelList);
		long GetSubModelIDs(vector<GME_TYPE_OBJ_ID>& subModelList);
		gmeModel* GetASubModel(short subModelIdx);
		long UpdateASubModel(long subModelIdx, gmeModel& subModel);

		//ȡ��ģ���е�Ҫ�����͵ĸ���
		long GetFeatClsNum();
		GME_TYPE_OBJ_ID GetAFeatCls(long i);

		gmeFeature* AddAFeature(GME_TYPE_OBJ_ID fClsID, const string& name=""); //�Ƽ�ʹ��....
		long AddAFeature(gmeFeature& feat);
		long DeleteAFeature(GME_TYPE_OBJ_ID fClsID, long featureIdx);
		long DeleteAllFeature();
		//��ȡģ����ĳһҪ�����е�Ҫ�ظ���
		long GetFeatureNum(GME_TYPE_OBJ_ID fClsID);
		//��ȡģ����ĳһҪ�����е�Ҫ��,featIdxΪҪ�ص���ţ�������ID
		gmeFeature* GetAFeature(GME_TYPE_OBJ_ID fClsID, short featureIdx);
		long GetFeatureIDs(GME_TYPE_OBJ_ID fClsID, vector<GME_TYPE_OBJ_ID>& featureIDs);
		long GetAllFeatureIDs(vector<gme_mdl_featID>& mdlFeatIDList);
		long UpdateAFeature(GME_TYPE_OBJ_ID fClsID, long i, gmeFeature& feat);
		map<GME_TYPE_OBJ_ID, vector<gmeFeature*>>* GetAllMdlFeatures();
		gme_vector3d GetOffset();
	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

	private:
		//ע��ID���ڻ�����
		gmeLegend				mLegend;//ģ��ͼ��
		gmeSeries				mSeries;//��׼�ز�
		gmeGeoRef				mGeoRef;//�ռ�ο�ϵ
		GME_MODEL_TYPE			mMdlType;	  //ģ������(�ṹģ��/����ģ��/���ģ��/����ģ��/...)
		vector<gmeModel*> mSubMdlList; //��ģ���б�
		vector<GME_TYPE_OBJ_ID> mSubMdlIDList; //��ģ��ID�б�
		map<GME_TYPE_OBJ_ID, vector<gmeFeature*>> mMdlFeatList; //ģ���е�Ҫ���б���Ҫ������з���
		vector<gme_mdl_featID> mMdlFeatIDList; //ģ���е�Ҫ��ID�б���Ҫ������з���
	};

	OG_GME_API  gmeModel* createGmeModel(string mdlName = "");
	void OG_GME_API releaseGmeModel(gmeModel* &mdl);
	OG_GME_API gmeModel* saveHoleModelIntoGmeDB(vector<gme_hole>& holeInfo);

}

