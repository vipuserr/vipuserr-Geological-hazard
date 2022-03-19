#pragma  once

#include "s3dGMdlDBEngineExp.h"
#include "gmeStru.h"
#include "gmeFeature.h"



namespace Smart3dMap
{
//ϵͳĬ�Ͻ�����Ҫ����
	
	//һ��Ҫ���� GME_FCLS_TYPE_COMM
	#define FCLS_GENERAL "GmeGeneral"
		#define FCLS_GENERAL_FLD_OBJID  "ObjID"
		#define FCLS_GENERAL_FLD_OBJNAME  "ObjName"
		#define FCLS_GENERAL_FLD_OBJDESC  "ObjDesc"

		//���ʵ�Ҫ���� GME_FCLS_TYPE_GEO_PNT
	#define FCLS_GEOPNT  "GmeGeoPnt"
		#define FCLS_GENERAL_FLD_GEOPNTID  "GeoPntID"
		#define FCLS_GENERAL_FLD_GEOPNTCODE  "GeoPntCode"
		#define FCLS_GENERAL_FLD_GEOPNTDESC  "GeoPntDesc"

		//��״��Ҫ���� GME_FCLS_TYPE_GEO_ORI_PNT
	#define FCLS_GEOORIPNT  "GmeGeoOriPnt"
		#define FCLS_GENERAL_FLD_ORIPNTID  "OriPntID"
		#define FCLS_GENERAL_FLD_ORIPNTCODE  "OriPntCode"
		#define FCLS_GENERAL_FLD_ORIPNTDIPDIR  "OriPntDipdir"
		#define FCLS_GENERAL_FLD_ORIPNTDIP  "OriPntDip"
		#define FCLS_GENERAL_FLD_ORIPNTDESC  "OriPntDesc"

		//������Ҫ���� GME_FCLS_TYPE_GEO_LIN
	#define FCLS_GEOLIN  "GmeGeoLin"
		#define FCLS_GENERAL_FLD_GEOLINEID  "GeoLineID"
		#define FCLS_GENERAL_FLD_GEOLINECODE  "GeoLineCode"
		#define FCLS_GENERAL_FLD_GEOLINETYPE  "GeoLineType" //���������ͣ��ز���ߡ��ϲ���
		#define FCLS_GENERAL_FLD_GEOLINEDESC  "GeoLineDesc"

		//������Ҫ���� GME_FCLS_TYPE_GEO_SURF
	#define FCLS_GEOSURF  "GmeGeoSurf"
		#define FCLS_GENERAL_FLD_GEOSURFID	  "GeoSurfID"
		#define FCLS_GENERAL_FLD_GEOSURFCODE  "GeoSurfCode"
		#define FCLS_GENERAL_FLD_GEOSURFTYPE  "GeoSurfType" //���������ͣ��ز��桢�ϲ���
		#define FCLS_GENERAL_FLD_GEOSURFDESC  "GeoSurfDesc"

		//������Ҫ���� GME_FCLS_TYPE_ENT
	#define FCLS_GEOENT  "GmeGeoEnt"
		#define FCLS_GENERAL_FLD_GEOENTID  "GeoEntID"//�ز�ID
		#define FCLS_GENERAL_FLD_GEOENTCODE  "GeoEntCode" //�ز����
		#define FCLS_GENERAL_FLD_GEOENTTYPE  "GeoEntType" //���������ͣ��ز�ʵ�塢�ϲ��
		#define FCLS_GENERAL_FLD_GEOENTDESC  "ObjDesc" //�ز�����
        #define FCLS_GENERAL_FLD_GEOENTNAME  "GeoEntName" //�ز�����
        #define FCLS_GENERAL_FLD_GEOENTLEVELCODE  "GeoEntLevelCode"//�ز㼶�����
        #define FCLS_GENERAL_FLD_GEOENTROCKNAME  "GeoEntRockName"//��������
        #define FCLS_GENERAL_FLD_GEOENTORIGINAL  "GeoEntRiginal"//���ʳ���
        #define FCLS_GENERAL_FLD_GEOENTAGE  "GeoEntAge"//����ʱ��"

		//���Ҫ���� GME_FCLS_TYPE_HOLE
	#define FCLS_GEOHOLE  "GmeHole"
		#define FCLS_GENERAL_FLD_HOLEID  "HOLEID"
		#define FCLS_GENERAL_FLD_HOLECODE  "HoleCode"
		#define FCLS_GENERAL_FLD_HOLEX  "HoleX"
		#define FCLS_GENERAL_FLD_HOLEY  "HoleY"//2021_4_8��posX��
		#define FCLS_GENERAL_FLD_HOLEZ  "HoleZ"//�׿ڱ��
		#define FCLS_GENERAL_FLD_HOLEDEPTH  "HoleDepth"//�׵ױ��
        #define FCLS_GENERAL_FID_HOLETYPE  "HoleType"
        #define FCLS_GENERAL_FID_HOLELEVEL  "HoleLevel"  //��׼���2021_4_8�¼�
		#define FCLS_GENERAL_FLD_HOLEDESC  "HoleDesc"

		//�ϲ�Ҫ���� GME_FCLS_TYPE_FAULT
	#define FCLS_GEOFAULT  "GmeFault"
		#define FCLS_GENERAL_FLD_FAULTID  "FaultID"
		#define FCLS_GENERAL_FLD_FAULTCODE  "FaultCode"
		#define FCLS_GENERAL_FLD_FAULTNAME  "FaultName"
        #define FCLS_GENERAL_FID_FAULTLENGTH  "FaultLength" //�ϲ㳤��,��2021_4_8�¼�
		#define FCLS_GENERAL_FLD_FAULTTYPE  "FaultType"
		#define FCLS_GENERAL_FLD_FAULTDIRTYPE  "FaultDirType" //�ϲ��������
		#define FCLS_GENERAL_FLD_FAULTDIPDIR  "FaultDipDir" //�ϲ������
		#define FCLS_GENERAL_FLD_FAULTDIP  "FaultDip" //�ϲ�����
		#define FCLS_GENERAL_FLD_FAULTDESC  "FaultDesc"

		//����Ҫ���� GME_FCLS_TYPE_DEM
	#define FCLS_GEODEM  "GmeDEM"
		#define FCLS_GENERAL_FLD_DEMID  "DEMID"
		#define FCLS_GENERAL_FLD_DEMNAME  "DEMName"
		#define FCLS_GENERAL_FLD_DEMDESC  "DEMDesc"

		//���Գ�Ҫ���� GME_FCLS_TYPE_FIELD
	#define FCLS_GEOFIELD  "GmeFIELD"
		#define FCLS_GENERAL_FLD_FIELDID  "FIELDID"
		#define FCLS_GENERAL_FLD_FIELDNAME  "FIELDName"
		#define FCLS_GENERAL_FLD_FIELDDESC "FIELDDesc"
        #define FCLS_GENERAL_FLD_FIELDLEVEL "FIELDLevel"//���Գ�����2021_4_8�¼�
        #define FCLS_GENERAL_FLD_FIELDATTNAME  "FIELDAttName"//���Գ��������ƣ�2021_4_8�¼�
        #define FCLS_GENERAL_FID_FIELDATTVALUE "FIELDAttValue" //���Գ�����ֵ��Ϣ(�ı���һ����ֵ����)��2021_4_8�¼�
        #define FCLS_GENERAL_FLD_FIELDATTCLASS "FIELDAttClass" //���Գ�����ֵ�ּ��ţ�2021_4_8�¼�

	    //ê��Ҫ���� GME_FCLS_TYPE_BOLT
    #define FCLS_GEOBOLT  "GmeBOLT"
        #define FCLS_GENERAL_FID_BOLTID  "BOLTID"
        #define FCLS_GENERAL_FID_BOLTNAME  "BOLTName"
        #define FCLS_GENERAL_FID_BOLTDESC  "BOLTDesc"
        #define FCLS_GENERAL_FID_BOLTNUMBER "BOLTNumber"
        #define FCLS_GENERAL_FID_BOLTTOPZ1  "BOLTTopZ1"
        #define FCLS_GENERAL_FID_BOLTZ1LEN  "BOLTZ1Length"
        #define FCLS_GENERAL_FID_BOLTDIR    "BOLTDir"
        #define FCLS_GENERAL_FID_BOLTTREND  "BOLTTrend"
        #define FCLS_GENERAL_FID_BOLTDIP    "BOLTDip" 
        #define FCLS_GENERAL_FID_BOLTDIAMETER  "BOLTDiameter"
        #define FCLS_GENERAL_FID_BOLTTYPE   "BOLTType"
        #define FCLS_GENERAL_FID_BOLTX      "BOLTX"
        #define FCLS_GENERAL_FID_BOLTY      "BOLTY"

	    //׮��Ҫ���� GME_FCLS_TYPE_PILE
    #define FCLS_GEOPILE  "GmePILE"
        #define FCLS_GENERAL_FID_PILEID  "PILEID"
        #define FCLS_GENERAL_FID_PILENAME  "PILEName"
        #define FCLS_GENERAL_FID_PILEDESC  "PILEDesc"

        #define FCLS_GENERAL_FID_PILEDIAMETER  "PILEDiameter"
        #define FCLS_GENERAL_FID_PILELENGTH  "PILELength"
        #define FCLS_GENERAL_FID_PILEHEIGHT  "PILETopZ"  //׮����ߣ�ԭΪPILEHeight
        #define FCLS_GENERAL_FID_PILEPROID  "PILEProID"
        #define FCLS_GENERAL_FID_PILEPRONAME  "PILEProName"
        #define FCLS_GENERAL_FID_PILEATT  "PILEAtt"
        #define FCLS_GENERAL_FID_PILEZ  "PILEZ"
        #define FCLS_GENERAL_FID_PILEZ1  "PILEZ1"
        #define FCLS_GENERAL_FID_PILEZ2  "PILEZ2"
        #define FCLS_GENERAL_FID_PILEZ3  "PILEZ3"
	    //������Ҫ���� GME_FCLS_TYPE_BUILD
    #define FCLS_GEOBUILD  "GmeBUILD"
        #define FCLS_GENERAL_FID_BUILDID  "BUILDID"
        #define FCLS_GENERAL_FID_BUILDNAME  "BUILDName"
        #define FCLS_GENERAL_FID_BUILDDESC  "BUILDDesc"
        #define FCLS_GENERAL_FID_BUILDAREA  "BUILDArea"    //���
        #define FCLS_GENERAL_FID_BUILDPERIMETER  "BUILDPerimeter"  //�ܳ�
        #define FCLS_GENERAL_FID_BUILDTOPZ  "BUILDTopZ"      //�����
        #define FCLS_GENERAL_FID_BUILDBOTTOMZ  "BUILDBottomZ"   //�ױ��

	 //Ҫ����Ҫ����һ��GUID�������ظ�
	class OG_GME_API gmeFeatureCls : public gmeObject //��άҪ����
	{
		friend class  gmeStorageDB;
	public:
		gmeFeatureCls(gmeStorageDB* storeDB = nullptr);
		gmeFeatureCls(gmeFeatureCls*obj);
		virtual ~gmeFeatureCls();
		virtual long CompressSave();//ѹ���洢
		virtual long UndoDelete(GME_TYPE_OBJ_ID fclsID);

	public:
		// -------------------- Ҫ����������� -------------------- //
		virtual long fcls_IsExist(GString fClsName);
		virtual	GME_TYPE_OBJ_ID	fcls_Create(gmeFields &fclsStru, GString& fClsName, GString& fClsGuid, GString& fClsDesc, GME_FCLS_TYPE fclsType = GME_FCLS_TYPE_GEO_ENT, GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);
		virtual	long fcls_Open(GME_TYPE_OBJ_ID fclsID);
		virtual bool fcls_HasOpened(GME_TYPE_OBJ_ID fclsID);
		virtual	long fcls_Close();
		virtual	long fcls_CloseAll();
		virtual	long fcls_Delete();
		virtual long fcls_Update();
		virtual long fcls_UpdateAll();

		// ---------------------------- ȡ��ǰҪ����������Ϣ ------------------------------- //
		virtual	long fcls_GetNum(GME_FCLS_TYPE fclsType);
		virtual	long fcls_GetNum();

		virtual	GME_TYPE_OBJ_ID fcls_GetID();
		virtual	long fcls_GetType(GME_FCLS_TYPE &fclsType); //��ȡҪ���������
		virtual	long fcls_GetGUID(GGUID& guid);
		virtual	GString fcls_GetName();
		virtual long fcls_GetIDList(GME_FCLS_TYPE  fclsType, vector<GME_TYPE_OBJ_ID>& fClsIDList); // ��ȡĳ������Ҫ�����ID�б�

		virtual	long fcls_SetAttStru(const gmeFields &fclsStru);//�������Խṹ
		virtual	long fcls_GetAttStru(gmeFields &fclsStru);//ȡ���Խṹ
			
		virtual long fcls_Update(GString fClsName);
		virtual long fcls_Update(GME_TYPE_OBJ_ID fclsID, gmeFeatureCls* fCls);

		//--------------------Ҫ�����е�Ҫ�ز�������-------------------- //
		virtual long fcls_GetFeatureNum();
		virtual long fcls_AddFeature(gmeFeature* pFeature);
		virtual long fcls_DelelteFeature(GME_TYPE_OBJ_ID featID);
		virtual long fcls_UndoDelelteFeature(GME_TYPE_OBJ_ID featID);
		virtual long fcls_GetFeature(vector<GME_TYPE_OBJ_ID>& fFeatureIDList);// ��ȡĳҪ��������Ҫ�ص�ID�б�
		virtual bool fcls_GetFeature(map<GME_TYPE_OBJ_ID, GString> & FeatureInfoList);
		virtual long fcls_GetFeature(GME_TYPE_OBJ_ID featID, gmeFeature* pFeature);
		virtual long fcls_GetFeature(GString strWhere, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);
		virtual long fcls_GetFeature(const gme_rect_3d *box, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);
		virtual long fcls_GetFeature(GString strWhere, const gme_rect_3d* pBox, vector<GME_TYPE_OBJ_ID> &featureList);
		virtual long fcls_GetFeature(const gme_vector3d *dot, const double dRadius, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);

	private:
		GME_FCLS_TYPE		mFClsType;	//Ҫ������
		GString				mFClsGuid;	//Ҫ����Guid
		gmeFields			mFclsStru;  //���Խṹ
		vector<GME_TYPE_OBJ_ID> mFeatureIDList;	//��ǰҪ�����Ҫ���б�
		map<GME_TYPE_OBJ_ID, GString> mFeatureInfoList;

		vector<GME_TYPE_OBJ_ID> mFClsIDList;	//Ҫ�����б�
		map< GME_FCLS_TYPE, vector<GME_TYPE_OBJ_ID> > mFClsIDListByType;//ĳһ���Ҫ�����б�
	};

}
