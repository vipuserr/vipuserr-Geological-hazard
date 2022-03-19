//接口派生实现类

#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeMdl.h"
#include "gmeOctGeoField.h"
#include "gmeModelMetadata.h"

class SAConnection;
class SACommand;

namespace Smart3dMap
{ 
	class s3dSqlBase;

	//物理存储基类
	class OG_GME_API gmeStorageDB
	{
		friend class gmeDataBase;

	public:
		gmeStorageDB(SAConnection* dbCon = nullptr);
		virtual ~gmeStorageDB();
		void setCon(SAConnection* dbCon);
	public:
		static gmeStorageDB* getSingletonPtr();
		static gmeStorageDB& getSingleton();

	public:
		// ---------------------------------------- 数据库操作 ---------------------------------------- //
							    //打开数据库，并返回数据库连接对象（如果已经连接，则直接返回连接对象,如果strDBUrl传空，则返回当前数据库连接对象）
		virtual __int64			db_Open(const GString& strDBUrl = "", GME_LinkType linktype = GME_DB_LINK_SQLITE, const GString& strUserName = "", const GString& strPswName = "");//打开数据库
		virtual __int64			db_Open(GME_LinkType linkType, const GString& strHost, const GString& strPort, const GString& dbName, const GString& strUserName, const GString& strPswName);//打开数据库
		virtual	long			db_Close(); //关闭数据库
		virtual long			db_CompressSave();  //保存数据库
		virtual long			db_Clear();  //清空数据库记录
		virtual bool            db_IsOpened();//数据库打开状态

		// ---------------------------------------- 模型操作 ---------------------------------------- //
		virtual long			mdl_GetModelNum();
		virtual long			mdl_GetModelIDlist(vector<GME_TYPE_OBJ_ID> &mdlIDList);
		virtual long			mdl_GetModelInfo(map<GME_TYPE_OBJ_ID, GString> &mdlNameList);
		virtual GME_TYPE_OBJ_ID	mdl_AppendModel(gmeModel &ft);
		virtual long			mdl_DeleteModel(GME_TYPE_OBJ_ID mdlID);
		virtual long			mdl_GetModel(GME_TYPE_OBJ_ID mdlID, gmeModel* const &mdl);
		virtual long			mdl_UpdateModel(GME_TYPE_OBJ_ID mdlID, gmeModel* mdl);
		virtual long			mdl_CompressSave();
		virtual long			mdl_UndoDeleteAMdl(GME_TYPE_OBJ_ID mdlID);

		// ---------------------------------------------- 标注操作 ------------------------------------------------ //
		virtual long			note_GetNoteNum();
		virtual GME_TYPE_OBJ_ID	note_AddNote(gmeNote* note);
		virtual long			note_DeleteNote(const GME_TYPE_OBJ_ID noteID);
		virtual long			note_GetNote(const GME_TYPE_OBJ_ID noteID, gmeNote *note);
		virtual long			note_UpdateNote(const GME_TYPE_OBJ_ID objID, gmeNote *note);
		virtual long			note_CompressSave();
		virtual long			geom_UndoDeleteNote(const GME_TYPE_OBJ_ID noteID);


		// ------------------------------------空间参考系操作----------------------------------- //
		virtual long			gref_GetGeorefNum();
		virtual GME_TYPE_OBJ_ID	gref_AddGeoref(gmeGeoRef* georef);
		virtual long			gref_DeleteGeoref(const GME_TYPE_OBJ_ID georefID);
		virtual long			gref_GetGeoref(const GME_TYPE_OBJ_ID georefID, gmeGeoRef *georef);
		virtual long			gref_UpdateGeoref(const GME_TYPE_OBJ_ID objID, gmeGeoRef *georef);
		virtual long			gref_CompressSave();
		virtual long			geom_UndoDeleteNoteGref(const GME_TYPE_OBJ_ID grefID);


		// ------------------------------------标准地层操作----------------------------------- //
		virtual long			ser_GetSeriesNum();
		virtual GME_TYPE_OBJ_ID	ser_AddSeries(gmeSeries* series);
		virtual long			ser_DeleteSeries(const GME_TYPE_OBJ_ID seriesID, GString mstrStratName);
		virtual long			ser_GetSeries(const GME_TYPE_OBJ_ID seriesID, GString mstrStratName, gmeSeries *series);
		virtual long			ser_GetSeries(GString mstrStratLevel, gmeSeries *series);
		virtual long			ser_UpdateSeries(const GME_TYPE_OBJ_ID objID, GString mstrStratName, gmeSeries *series);
		virtual long			ser_CompressSave();
		virtual long			geom_UndoDeleteNoteSer(const GME_TYPE_OBJ_ID serID);


		// ------------------------------------材质库操作----------------------------------- //
		virtual long			mat_GetMaterialLibNum();
		virtual GME_TYPE_OBJ_ID	mat_AddMaterialLib(gmeMaterialLib* matlib);
		virtual long			mat_DeleteMaterialLib(const GME_TYPE_OBJ_ID matlibID);
		virtual long			mat_GetMaterialLib(const GME_TYPE_OBJ_ID matlibID, gmeMaterialLib *matlib);
		virtual long			mat_UpdateMaterialLib(const GME_TYPE_OBJ_ID objID, gmeMaterialLib *matlib);
		virtual long			mat_CompressSave();
		virtual long			geom_UndoDeleteNoteMat(const GME_TYPE_OBJ_ID matID);


		// ------------------------------------三维图例库操作----------------------------------- //
		virtual long			led_GetLegendNum();
		virtual GME_TYPE_OBJ_ID	led_AddLegend(gmeLegend* legend);
		virtual long			led_DeleteLegend(const GME_TYPE_OBJ_ID legendID);
		virtual long			led_GetLegend(const GME_TYPE_OBJ_ID legendID, gmeLegend* legend);
		virtual long			led_UpdateLegend(const GME_TYPE_OBJ_ID objID, gmeLegend* legend);
		virtual long			led_CompressSave();
		virtual long			geom_UndoDeleteNoteLed(const GME_TYPE_OBJ_ID legendID);


		// ---------------------------------------------- 要素类操作 ---------------------------------------------------------------- //
		virtual	long			fcls_GetNum(GME_FCLS_TYPE fclsType);
		virtual	long			fcls_GetNum();
		virtual long			fcls_IsExist(GString fClsName); //如果存在 返回第一条记录的ID

		virtual	GME_TYPE_OBJ_ID	fcls_Create(gmeFields & fclsStru, GString & fClsURL, GString & fClsGuid, GString & fClsDesc, GME_FCLS_TYPE fclsType = GME_FCLS_TYPE_GEO_ENT);
		virtual	long			fcls_Delete(GME_TYPE_OBJ_ID fclsID);
		virtual	long			fcls_Get(GME_TYPE_OBJ_ID fclsID, gmeFeatureCls* fCls);
		virtual	long			fcls_Get(GGUID guid, gmeFeatureCls* fCls);
		virtual	long			fcls_Get(const char * fclsName, gmeFeatureCls*fCls);//打开第一个
		virtual long			fcls_Update(GME_TYPE_OBJ_ID fclsID, GString fClsName);
		virtual long			fcls_Update(GME_TYPE_OBJ_ID fclsID, gmeFeatureCls* fCls);
		
		virtual long			fcls_CompressSave();
		virtual long			fcls_UndoDeletefcls(GME_TYPE_OBJ_ID fclsID);




		// ----------------------------------------------要素操作---------------------------------------------------------------- //
		//要素类中的要素操作...
		virtual long			fcls_GetFeatureNum(GME_TYPE_OBJ_ID fclsID);
		virtual long			fcls_AddFeature(GME_TYPE_OBJ_ID fclsID, gmeFeature* pFeature);
		virtual long			fcls_DeleteFeature(GME_TYPE_OBJ_ID fclsID, GME_TYPE_OBJ_ID nFeatureID);
		virtual long			fcls_GetFeature(GME_TYPE_OBJ_ID fclsID, vector<GME_TYPE_OBJ_ID>& fFeatureIDList);// 获取某要素类所有要素的ID列表
		virtual long			fcls_GetFeature(GME_TYPE_OBJ_ID fclsID, GME_TYPE_OBJ_ID featID, gmeFeature *ft);
		virtual long			fcls_GetFeature(GME_TYPE_OBJ_ID fclsID, GString strWhere, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);
		virtual long			fcls_GetFeature(GME_TYPE_OBJ_ID fclsID, const gme_rect_3d *box, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);
		virtual long			fcls_GetFeature(GME_TYPE_OBJ_ID fclsID, GString strWhere, const gme_rect_3d* pBox, vector<GME_TYPE_OBJ_ID> &featureList);
		virtual long			fcls_GetFeature(GME_TYPE_OBJ_ID fclsID, const gme_vector3d *dot, const double dRadius, vector<GME_TYPE_OBJ_ID> &fFeatureIDList);
		virtual long			fcls_UpdateFeature(GME_TYPE_OBJ_ID fclsID, const GME_TYPE_OBJ_ID nFeatureID, gmeFeature* pFeature);
		virtual long			feature_CompressSave();
		virtual long			fcls_UndoDeleteFeature(GME_TYPE_OBJ_ID fclsID, GME_TYPE_OBJ_ID nFeatureID);


		// ---------------------------------------------- 结点操作 ---------------------------------------------------------------- //
		virtual long			geom_GetCornerNum();
		virtual GME_TYPE_OBJ_ID	geom_AddACorner(gmeCorner *pCorners); //添加结点
		virtual long			geom_DeleteACorner(GME_TYPE_OBJ_ID cornerID); //删除1个结点
		virtual long			geom_GetACorner(GME_TYPE_OBJ_ID cornerID, gmeCorner *pCorner);//获得1个结点
		virtual long			geom_UpdateACorner(GME_TYPE_OBJ_ID cornerID, gmeCorner *pCorner);//更新1个结点
		virtual long			geom_CornerCompressSave();//压缩保存该表
		virtual long			geom_UndoDeleteACorner(GME_TYPE_OBJ_ID cornerID); //撤销删除1个结点

		// ---------------------------------------------- 线操作 ---------------------------------------------------------------- //
		virtual long			geom_GetLineNum();
		virtual GME_TYPE_OBJ_ID	geom_AddLine(gmeLine *p3DLine);
		virtual long			geom_DeleteLine(const GME_TYPE_OBJ_ID nLineID);
		virtual long			geom_GetLine(const GME_TYPE_OBJ_ID nLineID, gmeLine *p3DLine);
		virtual long			geom_UpdateLine(const GME_TYPE_OBJ_ID nLineID, gmeLine *p3DLine);
		virtual long			geom_LineCompressSave();
		virtual long			geom_UndoDeleteLine(const GME_TYPE_OBJ_ID nLineID);

		// ---------------------------------------------- 面操作 ---------------------------------------------------------------- //
		virtual long			geom_GetSurfaceNum();
		virtual GME_TYPE_OBJ_ID	geom_AddSurface(gmeSurface *p3DBaseSurface);
		virtual long			geom_DeleteSurface(const GME_TYPE_OBJ_ID nSurfaceID);
		virtual long			geom_GetSurface(const GME_TYPE_OBJ_ID nSurfaceID, gmeSurface *pSurface);
		virtual long			geom_UpdateSurface(const GME_TYPE_OBJ_ID nSurfaceID, gmeSurface *pSurface);
		virtual long			geom_SurfaceCompressSave();
		virtual long			geom_UndoDeleteSurface(const GME_TYPE_OBJ_ID nSurfaceID);

		// --------------- 面lod数据的操作接口 ---------------------//
		GME_TYPE_OBJ_ID geom_GetLodSurfID(const GME_TYPE_OBJ_ID nSurfID, long lodLevel);
		virtual long   geom_GetLodSurfNum();//获取所有的lod数量

		virtual long   geom_GetLodSurfLevelNum(GME_TYPE_OBJ_ID nSurfID);//获取一个面的Lod级别数量，用于按照级别遍历面的Lod  wzj 2021.8.18
		virtual long   geom_GetLodSurfLevelNo(GME_TYPE_OBJ_ID nSurfID, vector<long>& LevelList);//获取一个面现有的Level级别号列表  wzj 2021.8.18

		virtual long   geom_GetLodSurfNum(GME_TYPE_OBJ_ID nSurfID);//获取某一个曲面的lod数量
		virtual GME_TYPE_OBJ_ID geom_AddALodofASurf(GME_TYPE_OBJ_ID nSurfID, gmeSurface *lodSurf, long lodLevel = 1, long rowNo = 0, long ColNo = 0);//添加面的lod数据，返回面lod的id
		virtual long   geom_DeleteALodofASurf(const GME_TYPE_OBJ_ID nLodSurfID);//删除一个面的一个lod数据1
		virtual long   geom_DeleteALodofASurf(const GME_TYPE_OBJ_ID nSurfID, long lodLevel);//删除一个面的一个lod数据2
		virtual long   geom_DeleteAllLodofASurf(const GME_TYPE_OBJ_ID nSurfID);//删除一个面的所有lod数据//
		virtual long   geom_DeleteALodofAllSurf();//删除所有面的所有lod数据
		virtual long   geom_GetALodSurf(const GME_TYPE_OBJ_ID nLodSurfID, gmeSurface *pLodSurf);//获取一个lod曲面1
		virtual long   geom_GetALodSurf(const GME_TYPE_OBJ_ID nSurfID, long lodLevel, gmeSurface *pLodSurf);//获取一个lod曲面2
		virtual long   geom_UpdateLodSurf(const GME_TYPE_OBJ_ID nlodSurfID, gmeSurface *pLodSurf);//加载一个lod曲面1
		virtual long   geom_UpdateLodSurf(const GME_TYPE_OBJ_ID nSurfID, long lodLevel, gmeSurface *pLodSurf);//加载一个lod曲面2
		virtual long   geom_LodSurfCompressSave(const GME_TYPE_OBJ_ID nlodSurfID);
		virtual long   geom_LodSurfCompressSave1(const GME_TYPE_OBJ_ID nSurfID);
		virtual long   geom_UndoDeleteLodSurf(const GME_TYPE_OBJ_ID nLodSurfID);//撤销删除1
		virtual long   geom_UndoDeleteLodSurf(const GME_TYPE_OBJ_ID nSurfID, long LodLevel);//撤销删除2
		virtual long   geom_UndoDeleteLodSurf1(const GME_TYPE_OBJ_ID nSurfID);//撤销删除1

		// ---------------------------------------------- 体操作 ---------------------------------------------------------------- //
		virtual long			geom_GetEntityNum();
		virtual GME_TYPE_OBJ_ID	geom_AddEntity(gmeEntity *p3DEntity);
		virtual long			geom_DeleteEntity(const GME_TYPE_OBJ_ID nEntityID);
		virtual long			geom_GetEntity(const GME_TYPE_OBJ_ID nEntityID, gmeEntity *p3DEntity);
		virtual long			geom_UpdateEntity(const GME_TYPE_OBJ_ID nEntityID, gmeEntity *p3DEntity);
		virtual long			geom_EntityCompressSave();
		virtual long			geom_UndoDeleteEntity(const GME_TYPE_OBJ_ID nEntityID);


		// ---------------------------------------------- 地质点操作 ---------------------------------------------------------------- //
		virtual long			geom_GetGeoPntNum();
		virtual GME_TYPE_OBJ_ID	geom_AddGeoPnt(gmeGeoPnt *obj);
		virtual long			geom_DeleteGeoPnt(const GME_TYPE_OBJ_ID objID);
		virtual long			geom_GetGeoPnt(const GME_TYPE_OBJ_ID objID, gmeGeoPnt *obj);
		virtual long			geom_UpdateGeoPnt(const GME_TYPE_OBJ_ID objID, gmeGeoPnt *obj);
		virtual long            geom_CompressSaveGeoPnt();
		virtual long            geom_UndoDeleteGeoPnt(const GME_TYPE_OBJ_ID objID);

		// ---------------------------------------------- 产状点操作 ---------------------------------------------------------------- //
		virtual long			geom_GetGeoOriPntNum();
		virtual GME_TYPE_OBJ_ID	geom_AddGeoOriPnt(gmeGeoOriPnt *obj);
		virtual long			geom_DeleteGeoOriPnt(const GME_TYPE_OBJ_ID objID);
		virtual long			geom_GetGeoOriPnt(const GME_TYPE_OBJ_ID objID, gmeGeoOriPnt *obj);
		virtual long			geom_UpdateGeoOriPnt(const GME_TYPE_OBJ_ID objID, gmeGeoOriPnt *obj);
		virtual long            geom_CompressSaveGeoOriPnt();
		virtual long			geom_UndoDeleteGeoOriPnt(const GME_TYPE_OBJ_ID objID);

		// ---------------------------------------------- 地质线操作 ---------------------------------------------------------------- //
		virtual long			geom_GetGeoLineNum();
		virtual GME_TYPE_OBJ_ID	geom_AddGeoLine(gmeGeoLine *obj);
		virtual long			geom_DeleteGeoLine(const GME_TYPE_OBJ_ID objID);
		virtual long			geom_GetGeoLine(const GME_TYPE_OBJ_ID objID, gmeGeoLine *obj);
		virtual long			geom_UpdateGeoLine(const GME_TYPE_OBJ_ID objID, gmeGeoLine *obj);
		virtual long            geom_CompressSaveGeoLine();
		virtual long			geom_UndoDeleteGeoLine(const GME_TYPE_OBJ_ID objID);

		// ---------------------------------------------- 地质面操作 ---------------------------------------------------------------- //
		virtual long			geom_GetGeoSurfaceNum();
		virtual GME_TYPE_OBJ_ID	geom_AddGeoSurface(gmeGeoSurface *obj);
		virtual long			geom_DeleteGeoSurface(const GME_TYPE_OBJ_ID objID);
		virtual long			geom_GetGeoSurface(const GME_TYPE_OBJ_ID objID, gmeGeoSurface *obj);
		virtual long			geom_UpdateGeoSurface(const GME_TYPE_OBJ_ID objID, gmeGeoSurface *obj);
		virtual long            geom_CompressSaveGeoSurface();
		virtual long			geom_UndoDeleteGeoSurface(const GME_TYPE_OBJ_ID objID);


		// ------------------------------------DEM操作----------------------------------- //
		virtual long			dem_GetDemNum();
		virtual GME_TYPE_OBJ_ID	dem_AddDEM(gmeDEM* dem);
		virtual long			dem_DeleteDEM(const GME_TYPE_OBJ_ID demID);
		virtual long			dem_GetDEM(const GME_TYPE_OBJ_ID demID, gmeDEM* dem);
		virtual long            dem_GetDEMInfo(const GME_TYPE_OBJ_ID demID,gmeDEM* dem);
		virtual long            dem_GetDEMLevelInfo(const GME_TYPE_OBJ_ID demID,const long levelNo, gme_dem_level* demLevel);
		virtual long            dem_GetDEMReData(const GME_TYPE_OBJ_ID demID,const long levelNo,const long rowNo,const long colNo, vector<double>* demReTileData);
		virtual long            dem_GetDEMIrreData(const GME_TYPE_OBJ_ID demID, const long levelNo, const long rowNo, const long colNo, gme_IrreTileData* demIrreTileData);
		virtual long			dem_UpdateDEM(const GME_TYPE_OBJ_ID objID, gmeDEM* dem);
		virtual long			dem_DEMCompressSave();
		virtual long			dem_UndoDeleteDEM(const GME_TYPE_OBJ_ID demID);
		

		// ---------------------------------------------- 地质体操作 ---------------------------------------------------------------- //
		virtual long			geom_GetGeoEntityNum();
		virtual GME_TYPE_OBJ_ID	geom_AddGeoEntity(gmeGeoEntity *obj);
		virtual long			geom_DeleteGeoEntity(const GME_TYPE_OBJ_ID objID);
		virtual long			geom_GetGeoEntity(const GME_TYPE_OBJ_ID objID, gmeGeoEntity *obj);
		virtual long			geom_UpdateGeoEntity(const GME_TYPE_OBJ_ID objID, gmeGeoEntity *obj);
		virtual long            geom_CompressSaveGeoEntity();
		virtual long			geom_UndoDeleteGeoEntity(const GME_TYPE_OBJ_ID objID);


		// ---------------------------------------------- 地质属性场操作 ---------------------------------------------------------------- //
		virtual long			geom_GetGeoFieldNum();
		virtual GME_TYPE_OBJ_ID	geom_AddGeoField(gmeGeoField *obj);
		virtual long			geom_DeleteGeoField(const GME_TYPE_OBJ_ID objID);
		virtual long			geom_GetGeoField(const GME_TYPE_OBJ_ID objID, gmeGeoField *obj);
		virtual long			geom_GetGeoFieldInfo(const GME_TYPE_OBJ_ID objID, gmeGeoField *obj);
		virtual long			geom_GetGeoFieldLevelInfo(const GME_TYPE_OBJ_ID objID,const long levelNo, gme_field_level *objLevel);
		virtual long            geom_GetFieldReData(const GME_TYPE_OBJ_ID objID, const long levelNo,const long rowNo,const long colNo,const long depNO, vector<double>* fieldReData);
		virtual long            geom_GetFieldIrreData(const GME_TYPE_OBJ_ID objID, const long rowNo, const long colNo, const long depNo, vector<irreField_data>* fieldIrreData);
		virtual long			geom_UpdateGeoField(const GME_TYPE_OBJ_ID objID, gmeGeoField *obj);
		virtual long			geom_FieldCompressSave();
		virtual long            geom_FieldUndoDelete(const GME_TYPE_OBJ_ID objID);

		// ---------------------------------------------- 钻孔操作 ---------------------------------------------------------------- //
		virtual long			geom_GetHoleNum();
		virtual GME_TYPE_OBJ_ID	geom_AddHole(gmeHole *obj);
		virtual long			geom_DeleteHole(const GME_TYPE_OBJ_ID objID);
		virtual long			geom_GetHole(const GME_TYPE_OBJ_ID objID, gmeHole *obj);
		virtual long			geom_UpdateHole(const GME_TYPE_OBJ_ID objID, gmeHole *obj);
		virtual long			geom_HoleCompressSave();
		virtual long			geom_UndoDeleteHole(const GME_TYPE_OBJ_ID objID);

		// ---------------------------------------------- 断层操作 ---------------------------------------------------------------- //
		virtual long			geom_GetFaultNum();
		virtual GME_TYPE_OBJ_ID	geom_AddFault(gmeFault *obj);
		virtual long			geom_DeleteFault(const GME_TYPE_OBJ_ID objID);
		virtual long			geom_GetFault(const GME_TYPE_OBJ_ID objID, gmeFault *obj);
		virtual long			geom_UpdateFault(const GME_TYPE_OBJ_ID objID, gmeFault *obj);
		virtual long            geom_FaultCompressSave();
		virtual long			geom_UndoDeleteFault(const GME_TYPE_OBJ_ID objID);

		// ---------------------------------------------- 规则网格地质属性场 ------------------------------------------------------ //
		virtual long			geom_GetOctGeoFieldNum(bool excludeDeleting = true);
		virtual long			geom_GetOctGeoFieldList(std::vector<GME_TYPE_OBJ_ID>& idList, bool excludeDeleting = true);
		virtual GME_TYPE_OBJ_ID geom_AddOctGeoField(gmeOctGeoField* octField);
		virtual long			geom_GetOctGeoField(GME_TYPE_OBJ_ID modelId, gmeOctGeoField* octField);
		virtual long			geom_UpdateOctGeoField(gmeOctGeoField* octField);
		virtual long			geom_DeleteOctGeoField(GME_TYPE_OBJ_ID modelId);
		virtual long			geom_UndoDeleteOctGeoField(GME_TYPE_OBJ_ID modelId);
		virtual long			geom_OctGeoFieldCompressSave();
		virtual long			geom_CreateOctGeoFieldIndex(GME_TYPE_OBJ_ID modelId, gmeOctGeoField::OctIndex& index);
		virtual long			geom_GetOctGeoFieldIndex(GME_TYPE_OBJ_ID modelId, const GString& fieldName, gmeOctGeoField::OctIndex& index);
		virtual long			geom_DeleteOctGeoFieldIndex(GME_TYPE_OBJ_ID modelId, const GString& fieldName);
		// 读分片数据。通过参数data输出读取的数据，调用者负责管理data指向的内存。
		virtual long			geom_ReadTileData(int octIndexId, int level, int tileI, int tileJ, int tileK, const GString& fieldName, unsigned char* &data, int& size);
		virtual long			geom_WriteTileData(int octIndexId, int level, int tileI, int tileJ, int tileK, const GString& fieldName, unsigned char* data, int size);

		// ---------------------------------------------- 三维地质模型的元数据 ------------------------------------------------------ //
		virtual bool ReadModelMetadata(int modelId, gmeModelMetadata& meta);
		virtual bool WriteModelMetadata(const gmeModelMetadata& meta);
		virtual bool DeleteModelMetadata(int modelId);

	public:
		//设置事务提交模式
		virtual void  setAutoCommit(BOOL type = true);
		virtual void commitAll();

		//取出sql操作对象
		s3dSqlBase* getSqlObj();

		//根据类型取默认要素类
		GME_TYPE_OBJ_ID getFClsID(GME_FCLS_TYPE fClsType = GME_FCLS_TYPE_GEO_ENT);
		gmeFeatureCls* getFCls(GME_FCLS_TYPE fClsType = GME_FCLS_TYPE_GEO_ENT);
		void ConvertFclsStru2Default(gmeFeature* pFeature);
		void ConvertFclsStruFromDefault(gmeFeature* pFeature);
		map<string, string> getFclsFieldsDictionary(GME_TYPE_OBJ_ID fClsType);//要素类属性字段//2021_4_8加

		//创建默认的要素类...
		void createDefaultFCls();
		//获取默认创建的要素类信息
		void getDefaultFCls();

	private:
		virtual	GME_TYPE_OBJ_ID	AttTbl_Create(gmeFields & fclsStru, GString & AttTableName);
		virtual	long			AttTbl_GetAtt(gmeFields & fclsStru, GString & AttTableName);
		//取出此表插入新记录后的ID号
		int getNewRowID(string tblName); // 这是一个低效率函数 -- LH.2021.10.11 14:13 commented.
		// 重载，直接使用sql中的max函数 -- LH.2021.10.11 11:38 added.
		int getNewRowID(string id_name, string table_name);

		GString GetTableNameOfOctGridTiles(GME_TYPE_OBJ_ID modelId) const;

	private:
		GME_TYPE_OBJ_ID		mcurFClsID;	//_当前操作的要素类ID
		bool				mHasOpened;

		SAConnection        *mCon;//数据库连接
		long				mCurMdlID;
		long				mBulkFetchSize; //批取大小
		std::map<GME_FCLS_TYPE, gmeFeatureCls*>	mDefGmeFcls; //系统默认构建的要素类(普通型、地质点、产状点、地质线、地质面、地质体、钻孔、断层、地形、属性场要素类)
		const GString TableName_MDMetadata_ = GString("md_metadata");
		const GString TableName_MDIdentification_ = GString("md_identification");
		const GString TableName_MDContent_ = GString("md_content");
		const GString TableName_MDModelQuality_ = GString("md_model_quality");
		const GString TableName_MDSRS_ = GString("md_rs_reference_system");
		const GString TableName_MDDistribution_ = GString("md_distribution");
	};

}