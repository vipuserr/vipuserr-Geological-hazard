#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeEntity.h"
#include "gmeGeoEntity.h"
#include "gmeDef.h"
#include "gmeStru.h"

namespace Smart3dMap
{
	class OG_GME_API gmeFeature : public gmeObject //Ҫ��
	{
		friend class gmeStorageDB;
		friend class gmeModel;
		
	public:
		gmeFeature();
		gmeFeature(GME_TYPE_OBJ_ID nClsID);
		virtual ~gmeFeature();

	public:
		virtual long Clear();//���
		virtual long Clone(gmeFeature& obj);//��������
		gmeFeature& operator=(gmeFeature &rhs);
		virtual long Load(GME_TYPE_OBJ_ID featureID, long lodLevel=0);//�����ݿ����¼���
		virtual long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodLevel=0);//����
		virtual long Delete(long lodLevel=0); //2021/3/8�����
		virtual long CompressSave(long lodLevel=0);//ѹ���洢
		virtual long UndoDelete(long lodLevel=0);
		
	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

	public:
		// -------------------- ��Ҫ������� ------------------------ //
		long SetFCls(GME_TYPE_OBJ_ID nClsID);
		long GetFCls(GME_TYPE_OBJ_ID &nClsID);

		// -------------------- ���Խṹ�����ӿ� -------------------- //
		virtual long SetFeatureAtt(gmeRecord* pRecord);
		virtual long DeleteFeatureAtt();
		virtual long GetFeatureAtt(gmeRecord** pRecord);
		virtual long UpdateFeatureAtt(gmeRecord* pRecord);

		// -------------------- ���β����ӿ� -------------------- //
		virtual long GetGeometryNum();
		virtual long SetGeometryList(GME_Geometry_ID *pGeomIDList, int nGeomNum);
		virtual long GetGeometryList(vector<GME_Geometry_ID> &geometryIDList);  //cc add
		virtual long GetGeometryList(vector<gmeGeometry*>& geometryList); //zhyh add 2021.10.26
		virtual long AddGeometryList(vector<GME_Geometry_ID>geomID);
		//�Ƽ�ʹ�ã�����һ���µĿ�geometry����ӵ�mGeomList��
		virtual gmeGeometry* AddAGeometry(GME_OBJ_TYPE geomType);
		//�Ƽ�ʹ�ã����һ�����ζ��󣬽���ָ���¼��Ҫ�صļ��ζ����б���
		virtual long AddAGeometry(gmeGeometry*geom);
		//���һ���Ѿ����ڵļ��ζ����Ҫ�أ��ڲ��Ḵ��һ�ݼ��ζ���
		virtual long AddAGeometry(gmeGeometry&geom);
		virtual long AddAGeometry(GME_Geometry_ID geomID);

		virtual gmeGeometry* GetAGeometry(short i);
		virtual long GetAGeometry(short i, GME_Geometry_ID &geomID);//i from 0

		virtual long DeleteAGeometry(short i);
		virtual long DeleteAGeometry(GME_Geometry_ID geomID);
		virtual long UpdateAGeometry(short i, GME_Geometry_ID geomID);
		virtual long UpdateAGeometry(short i, gmeGeometry *geom);

		//Ҫ�ع�ϵ�б�
		long GetRatationFeatureNum();
		long AddARelation(GME_TYPE_OBJ_ID relFeatID, GME_FEATURE_RELATION_TYPE relationType, GME_FEATURE_RELATION_VALUE relationVal);
		long DelARelation(GME_TYPE_OBJ_ID relFeatID);
		long GetARelation(GME_TYPE_OBJ_ID &relFeatID, GME_FEATURE_RELATION_TYPE &relationType, GME_FEATURE_RELATION_VALUE &relationVal);
		long GetRelations(vector<gme_feature_relation> &relFeatureList);
		long UpdateRelation(GME_TYPE_OBJ_ID relFeatID, GME_FEATURE_RELATION_TYPE relationType, GME_FEATURE_RELATION_VALUE relationVal);

		//��ȡҪ�ص���������ƫ��
		gme_vector3d GetOffset();

	private:
		GME_TYPE_OBJ_ID mFClsID;
		vector<GME_Geometry_ID> mGeomIDList; //���ζ����б�
		vector<gme_feature_relation> relFeatList; //��ص�Ҫ���б�
		gmeRecord * mpRecord;
		vector<gmeGeometry *> mGeomList;
	};
	

}