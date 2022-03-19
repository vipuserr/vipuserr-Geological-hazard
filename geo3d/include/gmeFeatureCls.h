#pragma  once

#include "s3dGMdlDBEngineExp.h"
#include "gmeStru.h"
#include "gmeFeature.h"



namespace Smart3dMap
{
//系统默认建立的要素类
	
	//一般要素类 GME_FCLS_TYPE_COMM
	#define FCLS_GENERAL "GmeGeneral"
		#define FCLS_GENERAL_FLD_OBJID  "ObjID"
		#define FCLS_GENERAL_FLD_OBJNAME  "ObjName"
		#define FCLS_GENERAL_FLD_OBJDESC  "ObjDesc"

		//地质点要素类 GME_FCLS_TYPE_GEO_PNT
	#define FCLS_GEOPNT  "GmeGeoPnt"
		#define FCLS_GENERAL_FLD_GEOPNTID  "GeoPntID"
		#define FCLS_GENERAL_FLD_GEOPNTCODE  "GeoPntCode"
		#define FCLS_GENERAL_FLD_GEOPNTDESC  "GeoPntDesc"

		//产状点要素类 GME_FCLS_TYPE_GEO_ORI_PNT
	#define FCLS_GEOORIPNT  "GmeGeoOriPnt"
		#define FCLS_GENERAL_FLD_ORIPNTID  "OriPntID"
		#define FCLS_GENERAL_FLD_ORIPNTCODE  "OriPntCode"
		#define FCLS_GENERAL_FLD_ORIPNTDIPDIR  "OriPntDipdir"
		#define FCLS_GENERAL_FLD_ORIPNTDIP  "OriPntDip"
		#define FCLS_GENERAL_FLD_ORIPNTDESC  "OriPntDesc"

		//地质线要素类 GME_FCLS_TYPE_GEO_LIN
	#define FCLS_GEOLIN  "GmeGeoLin"
		#define FCLS_GENERAL_FLD_GEOLINEID  "GeoLineID"
		#define FCLS_GENERAL_FLD_GEOLINECODE  "GeoLineCode"
		#define FCLS_GENERAL_FLD_GEOLINETYPE  "GeoLineType" //地质线类型：地层界线、断层线
		#define FCLS_GENERAL_FLD_GEOLINEDESC  "GeoLineDesc"

		//地质面要素类 GME_FCLS_TYPE_GEO_SURF
	#define FCLS_GEOSURF  "GmeGeoSurf"
		#define FCLS_GENERAL_FLD_GEOSURFID	  "GeoSurfID"
		#define FCLS_GENERAL_FLD_GEOSURFCODE  "GeoSurfCode"
		#define FCLS_GENERAL_FLD_GEOSURFTYPE  "GeoSurfType" //地质面类型：地层面、断层面
		#define FCLS_GENERAL_FLD_GEOSURFDESC  "GeoSurfDesc"

		//地质体要素类 GME_FCLS_TYPE_ENT
	#define FCLS_GEOENT  "GmeGeoEnt"
		#define FCLS_GENERAL_FLD_GEOENTID  "GeoEntID"//地层ID
		#define FCLS_GENERAL_FLD_GEOENTCODE  "GeoEntCode" //地层编码
		#define FCLS_GENERAL_FLD_GEOENTTYPE  "GeoEntType" //地质体类型：地层实体、断层块
		#define FCLS_GENERAL_FLD_GEOENTDESC  "ObjDesc" //地层描述
        #define FCLS_GENERAL_FLD_GEOENTNAME  "GeoEntName" //地层名称
        #define FCLS_GENERAL_FLD_GEOENTLEVELCODE  "GeoEntLevelCode"//地层级别编码
        #define FCLS_GENERAL_FLD_GEOENTROCKNAME  "GeoEntRockName"//岩土名称
        #define FCLS_GENERAL_FLD_GEOENTORIGINAL  "GeoEntRiginal"//地质成因
        #define FCLS_GENERAL_FLD_GEOENTAGE  "GeoEntAge"//地质时代"

		//钻孔要素类 GME_FCLS_TYPE_HOLE
	#define FCLS_GEOHOLE  "GmeHole"
		#define FCLS_GENERAL_FLD_HOLEID  "HOLEID"
		#define FCLS_GENERAL_FLD_HOLECODE  "HoleCode"
		#define FCLS_GENERAL_FLD_HOLEX  "HoleX"
		#define FCLS_GENERAL_FLD_HOLEY  "HoleY"//2021_4_8由posX改
		#define FCLS_GENERAL_FLD_HOLEZ  "HoleZ"//孔口标高
		#define FCLS_GENERAL_FLD_HOLEDEPTH  "HoleDepth"//孔底标高
        #define FCLS_GENERAL_FID_HOLETYPE  "HoleType"
        #define FCLS_GENERAL_FID_HOLELEVEL  "HoleLevel"  //钻孔级别，2021_4_8新加
		#define FCLS_GENERAL_FLD_HOLEDESC  "HoleDesc"

		//断层要素类 GME_FCLS_TYPE_FAULT
	#define FCLS_GEOFAULT  "GmeFault"
		#define FCLS_GENERAL_FLD_FAULTID  "FaultID"
		#define FCLS_GENERAL_FLD_FAULTCODE  "FaultCode"
		#define FCLS_GENERAL_FLD_FAULTNAME  "FaultName"
        #define FCLS_GENERAL_FID_FAULTLENGTH  "FaultLength" //断层长度,，2021_4_8新加
		#define FCLS_GENERAL_FLD_FAULTTYPE  "FaultType"
		#define FCLS_GENERAL_FLD_FAULTDIRTYPE  "FaultDirType" //断层倾角类型
		#define FCLS_GENERAL_FLD_FAULTDIPDIR  "FaultDipDir" //断层的倾向
		#define FCLS_GENERAL_FLD_FAULTDIP  "FaultDip" //断层的倾角
		#define FCLS_GENERAL_FLD_FAULTDESC  "FaultDesc"

		//地形要素类 GME_FCLS_TYPE_DEM
	#define FCLS_GEODEM  "GmeDEM"
		#define FCLS_GENERAL_FLD_DEMID  "DEMID"
		#define FCLS_GENERAL_FLD_DEMNAME  "DEMName"
		#define FCLS_GENERAL_FLD_DEMDESC  "DEMDesc"

		//属性场要素类 GME_FCLS_TYPE_FIELD
	#define FCLS_GEOFIELD  "GmeFIELD"
		#define FCLS_GENERAL_FLD_FIELDID  "FIELDID"
		#define FCLS_GENERAL_FLD_FIELDNAME  "FIELDName"
		#define FCLS_GENERAL_FLD_FIELDDESC "FIELDDesc"
        #define FCLS_GENERAL_FLD_FIELDLEVEL "FIELDLevel"//属性场级别，2021_4_8新加
        #define FCLS_GENERAL_FLD_FIELDATTNAME  "FIELDAttName"//属性场属性名称，2021_4_8新加
        #define FCLS_GENERAL_FID_FIELDATTVALUE "FIELDAttValue" //属性场属性值信息(文本，一般是值区间)，2021_4_8新加
        #define FCLS_GENERAL_FLD_FIELDATTCLASS "FIELDAttClass" //属性场属性值分级号，2021_4_8新加

	    //锚杆要素类 GME_FCLS_TYPE_BOLT
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

	    //桩基要素类 GME_FCLS_TYPE_PILE
    #define FCLS_GEOPILE  "GmePILE"
        #define FCLS_GENERAL_FID_PILEID  "PILEID"
        #define FCLS_GENERAL_FID_PILENAME  "PILEName"
        #define FCLS_GENERAL_FID_PILEDESC  "PILEDesc"

        #define FCLS_GENERAL_FID_PILEDIAMETER  "PILEDiameter"
        #define FCLS_GENERAL_FID_PILELENGTH  "PILELength"
        #define FCLS_GENERAL_FID_PILEHEIGHT  "PILETopZ"  //桩顶标高，原为PILEHeight
        #define FCLS_GENERAL_FID_PILEPROID  "PILEProID"
        #define FCLS_GENERAL_FID_PILEPRONAME  "PILEProName"
        #define FCLS_GENERAL_FID_PILEATT  "PILEAtt"
        #define FCLS_GENERAL_FID_PILEZ  "PILEZ"
        #define FCLS_GENERAL_FID_PILEZ1  "PILEZ1"
        #define FCLS_GENERAL_FID_PILEZ2  "PILEZ2"
        #define FCLS_GENERAL_FID_PILEZ3  "PILEZ3"
	    //建筑物要素类 GME_FCLS_TYPE_BUILD
    #define FCLS_GEOBUILD  "GmeBUILD"
        #define FCLS_GENERAL_FID_BUILDID  "BUILDID"
        #define FCLS_GENERAL_FID_BUILDNAME  "BUILDName"
        #define FCLS_GENERAL_FID_BUILDDESC  "BUILDDesc"
        #define FCLS_GENERAL_FID_BUILDAREA  "BUILDArea"    //面积
        #define FCLS_GENERAL_FID_BUILDPERIMETER  "BUILDPerimeter"  //周长
        #define FCLS_GENERAL_FID_BUILDTOPZ  "BUILDTopZ"      //顶标高
        #define FCLS_GENERAL_FID_BUILDBOTTOMZ  "BUILDBottomZ"   //底标高

	 //要素类要增加一个GUID，以免重复
	class OG_GME_API gmeFeatureCls : public gmeObject //三维要素类
	{
		friend class  gmeStorageDB;
	public:
		gmeFeatureCls(gmeStorageDB* storeDB = nullptr);
		gmeFeatureCls(gmeFeatureCls*obj);
		virtual ~gmeFeatureCls();
		virtual long CompressSave();//压缩存储
		virtual long UndoDelete(GME_TYPE_OBJ_ID fclsID);

	public:
		// -------------------- 要素类操作函数 -------------------- //
		virtual long fcls_IsExist(GString fClsName);
		virtual	GME_TYPE_OBJ_ID	fcls_Create(gmeFields &fclsStru, GString& fClsName, GString& fClsGuid, GString& fClsDesc, GME_FCLS_TYPE fclsType = GME_FCLS_TYPE_GEO_ENT, GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);
		virtual	long fcls_Open(GME_TYPE_OBJ_ID fclsID);
		virtual bool fcls_HasOpened(GME_TYPE_OBJ_ID fclsID);
		virtual	long fcls_Close();
		virtual	long fcls_CloseAll();
		virtual	long fcls_Delete();
		virtual long fcls_Update();
		virtual long fcls_UpdateAll();

		// ---------------------------- 取当前要素类的相关信息 ------------------------------- //
		virtual	long fcls_GetNum(GME_FCLS_TYPE fclsType);
		virtual	long fcls_GetNum();

		virtual	GME_TYPE_OBJ_ID fcls_GetID();
		virtual	long fcls_GetType(GME_FCLS_TYPE &fclsType); //获取要素类的类型
		virtual	long fcls_GetGUID(GGUID& guid);
		virtual	GString fcls_GetName();
		virtual long fcls_GetIDList(GME_FCLS_TYPE  fclsType, vector<GME_TYPE_OBJ_ID>& fClsIDList); // 获取某类所有要素类的ID列表

		virtual	long fcls_SetAttStru(const gmeFields &fclsStru);//设置属性结构
		virtual	long fcls_GetAttStru(gmeFields &fclsStru);//取属性结构
			
		virtual long fcls_Update(GString fClsName);
		virtual long fcls_Update(GME_TYPE_OBJ_ID fclsID, gmeFeatureCls* fCls);

		//--------------------要素类中的要素操作函数-------------------- //
		virtual long fcls_GetFeatureNum();
		virtual long fcls_AddFeature(gmeFeature* pFeature);
		virtual long fcls_DelelteFeature(GME_TYPE_OBJ_ID featID);
		virtual long fcls_UndoDelelteFeature(GME_TYPE_OBJ_ID featID);
		virtual long fcls_GetFeature(vector<GME_TYPE_OBJ_ID>& fFeatureIDList);// 获取某要素类所有要素的ID列表
		virtual bool fcls_GetFeature(map<GME_TYPE_OBJ_ID, GString> & FeatureInfoList);
		virtual long fcls_GetFeature(GME_TYPE_OBJ_ID featID, gmeFeature* pFeature);
		virtual long fcls_GetFeature(GString strWhere, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);
		virtual long fcls_GetFeature(const gme_rect_3d *box, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);
		virtual long fcls_GetFeature(GString strWhere, const gme_rect_3d* pBox, vector<GME_TYPE_OBJ_ID> &featureList);
		virtual long fcls_GetFeature(const gme_vector3d *dot, const double dRadius, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);

	private:
		GME_FCLS_TYPE		mFClsType;	//要素类型
		GString				mFClsGuid;	//要素类Guid
		gmeFields			mFclsStru;  //属性结构
		vector<GME_TYPE_OBJ_ID> mFeatureIDList;	//当前要素类的要素列表
		map<GME_TYPE_OBJ_ID, GString> mFeatureInfoList;

		vector<GME_TYPE_OBJ_ID> mFClsIDList;	//要素类列表
		map< GME_FCLS_TYPE, vector<GME_TYPE_OBJ_ID> > mFClsIDListByType;//某一类的要素类列表
	};

}
