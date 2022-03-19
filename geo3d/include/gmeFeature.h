#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeEntity.h"
#include "gmeGeoEntity.h"
#include "gmeDef.h"
#include "gmeStru.h"

namespace Smart3dMap
{
	class OG_GME_API gmeFeature : public gmeObject //要素
	{
		friend class gmeStorageDB;
		friend class gmeModel;
		
	public:
		gmeFeature();
		gmeFeature(GME_TYPE_OBJ_ID nClsID);
		virtual ~gmeFeature();

	public:
		virtual long Clear();//清空
		virtual long Clone(gmeFeature& obj);//拷贝对象
		gmeFeature& operator=(gmeFeature &rhs);
		virtual long Load(GME_TYPE_OBJ_ID featureID, long lodLevel=0);//从数据库重新加载
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel=0);//保存
		virtual long Delete(long lodLevel=0); //2021/3/8日添加
		virtual long CompressSave(long lodLevel=0);//压缩存储
		virtual long UndoDelete(long lodLevel=0);
		
	protected:
		virtual long CalBox();//被GetBox调用,计算包围盒

	public:
		// -------------------- 与要素类关联 ------------------------ //
		long SetFCls(GME_TYPE_OBJ_ID nClsID);
		long GetFCls(GME_TYPE_OBJ_ID &nClsID);

		// -------------------- 属性结构操作接口 -------------------- //
		virtual long SetFeatureAtt(gmeRecord* pRecord);
		virtual long DeleteFeatureAtt();
		virtual long GetFeatureAtt(gmeRecord** pRecord);
		virtual long UpdateFeatureAtt(gmeRecord* pRecord);

		// -------------------- 几何操作接口 -------------------- //
		virtual long GetGeometryNum();
		virtual long SetGeometryList(GME_Geometry_ID *pGeomIDList, int nGeomNum);
		virtual long GetGeometryList(vector<GME_Geometry_ID> &geometryIDList);  //cc add
		virtual long GetGeometryList(vector<gmeGeometry*>& geometryList); //zhyh add 2021.10.26
		virtual long AddGeometryList(vector<GME_Geometry_ID>geomID);
		//推荐使用，创建一个新的空geometry并添加到mGeomList中
		virtual gmeGeometry* AddAGeometry(GME_OBJ_TYPE geomType);
		//推荐使用，添加一个几何对象，将其指针记录在要素的几何对象列表中
		virtual long AddAGeometry(gmeGeometry*geom);
		//添加一个已经存在的几何对象给要素，内部会复制一份几何对象
		virtual long AddAGeometry(gmeGeometry&geom);
		virtual long AddAGeometry(GME_Geometry_ID geomID);

		virtual gmeGeometry* GetAGeometry(short i);
		virtual long GetAGeometry(short i, GME_Geometry_ID &geomID);//i from 0

		virtual long DeleteAGeometry(short i);
		virtual long DeleteAGeometry(GME_Geometry_ID geomID);
		virtual long UpdateAGeometry(short i, GME_Geometry_ID geomID);
		virtual long UpdateAGeometry(short i, gmeGeometry *geom);

		//要素关系列表
		long GetRatationFeatureNum();
		long AddARelation(GME_TYPE_OBJ_ID relFeatID, GME_FEATURE_RELATION_TYPE relationType, GME_FEATURE_RELATION_VALUE relationVal);
		long DelARelation(GME_TYPE_OBJ_ID relFeatID);
		long GetARelation(GME_TYPE_OBJ_ID &relFeatID, GME_FEATURE_RELATION_TYPE &relationType, GME_FEATURE_RELATION_VALUE &relationVal);
		long GetRelations(vector<gme_feature_relation> &relFeatureList);
		long UpdateRelation(GME_TYPE_OBJ_ID relFeatID, GME_FEATURE_RELATION_TYPE relationType, GME_FEATURE_RELATION_VALUE relationVal);

		//获取要素的整体坐标偏移
		gme_vector3d GetOffset();

	private:
		GME_TYPE_OBJ_ID mFClsID;
		vector<GME_Geometry_ID> mGeomIDList; //几何对象列表
		vector<gme_feature_relation> relFeatList; //相关的要素列表
		gmeRecord * mpRecord;
		vector<gmeGeometry *> mGeomList;
	};
	

}