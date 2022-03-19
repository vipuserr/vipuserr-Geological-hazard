#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeEntity.h"
#include "gmeStru.h"



namespace Smart3dMap
{
	class OG_GME_API gmeGeoPnt : public gmeCorner //���ʵ�
	{
	public:
		gmeGeoPnt();
		gmeGeoPnt(const gmeGeoPnt&rhs);
		virtual ~gmeGeoPnt();

	public:
		gmeGeoPnt& operator=(gmeGeoPnt &rhs);
		long Clone(gmeGeoPnt& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID	GeoPntID);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//����
		long CompressSave();//ѹ���洢
		long Delete();
		long UndoDelete();

		long SetGeoCode(GString strGeoCode);
		GString GetGeoCode();

		friend class gmeStorageDB;
	private:
		GString			mGeoCode; //���ʱ���
	};

	class OG_GME_API gmeGeoOriPnt : public gmeGeoPnt //��״��
	{
	public:
		gmeGeoOriPnt();
		gmeGeoOriPnt(const gmeGeoOriPnt&rhs);
		virtual ~gmeGeoOriPnt();

	public:
		gmeGeoOriPnt& operator=(gmeGeoOriPnt &rhs);
		long Clone(gmeGeoOriPnt& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID GeoOriPntID);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//����
		long CompressSave();//ѹ���洢
		long Delete();
		long UndoDelete();

		long SetDip(GME_GEO_DIP_TYPE dipType, double dDipDir, double dDip);
		long GetDip(GME_GEO_DIP_TYPE &dipType, double &dDipDir, double &dDip);
		friend class gmeStorageDB;
	private:
		GME_GEO_DIP_TYPE mDipType;
		double mDipDir;
		double mDip;
	};

	class OG_GME_API gmeGeoLine : public gmeGeometry //������
	{
	public:
		gmeGeoLine();
		gmeGeoLine(gmeGeoLine&rhs);
		virtual ~gmeGeoLine();

	public:
		gmeGeoLine& operator=(gmeGeoLine &rhs);
		long Clone(gmeGeoLine& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID GeoLineID, long lodlevel=0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//����
		long CompressSave(long lodlevel=0);//ѹ���洢
		long Delete(long lodlevel=0);
		long UndoDelete(long lodlevel=0);

		long SetGeoCode(GString strGeoCode);
		GString GetGeoCode();


		// ---------------------------- �߲��� ---------------------------- //
		long GetLineNum();

		gmeLine* AddALine(string name="");
		long AddALine(GME_TYPE_OBJ_ID lineID);
		long AddLines(vector<GME_TYPE_OBJ_ID> &lineIDs);

		long DeleteALine(long lLineNo);
		long DeleteALine(GME_TYPE_OBJ_ID lineID);
		long DeleteLines();

		gmeLine* GetALine(short lLineNo);
		gmeLine* operator[](short lLineNo);
		long GetALine(short lLineNo, GME_TYPE_OBJ_ID &lineID);
		long GetLines(vector<GME_TYPE_OBJ_ID> &lineIDs);

		long UpdateALine(long lLineNo, GME_TYPE_OBJ_ID lineID);
		long UpdateALine(long lLineNo, gmeLine* line);
	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

		friend class gmeStorageDB;
	private:
		vector<GME_TYPE_OBJ_ID>	mLinIDs;
		vector<gmeLine*>	mLins; //leo20200102���� ���gmeGeoLine���ڴ漶ʹ������
		GString				mGeoCode; //�����ߵ��ϵز����
		GString				mGeoCode2;//�����ߵ��µز����
	};

	class OG_GME_API gmeGeoSurface : public gmeGeometry  //������
	{
	public:
		gmeGeoSurface();
		gmeGeoSurface(const gmeGeoSurface &rhs);
		virtual ~gmeGeoSurface();

	public:
		gmeGeoSurface& operator=(gmeGeoSurface &rhs);
		long Clone(gmeGeoSurface& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID GeoSurfaceID, long lodlevel=0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//����
		long CompressSave(long lodlevel);//ѹ���洢
		long Delete(long lodlevel);
		long UndoDelete(long lodlevel);

		long SetGeoCode(GString strGeoCode);
		GString GetGeoCode();

		// ---------------------------- ����� ---------------------------- //
		long GetSurfaceNum();

		gmeSurface* AddASurface(string name="");
		long AddASurface(GME_TYPE_OBJ_ID surfaceID);
		long AddSurfaces(GME_TYPE_OBJ_ID* surfaceIDs, long lSurfaceNum=1);

		long DeleteASurface(long lSurfaceNo);
		long DeleteASurface(GME_TYPE_OBJ_ID surfaceID);
		long DeleteSurfaces();

		gmeSurface* GetASurface(short lSurfaceNo);
		long GetASurface(short lSurfaceNo, GME_TYPE_OBJ_ID &surfaceID);
		long GetSurfaces(vector<GME_TYPE_OBJ_ID>& surfaceIDs);
		long GetSurfaces(vector<gmeSurface*>& surfs);

		long UpdateASurface(long lSurfaceNo, GME_TYPE_OBJ_ID surfaceID);
		long UpdateASurface(long lSurfaceNo, gmeSurface *surface);

	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

		friend class gmeStorageDB;
	private:
		vector<GME_TYPE_OBJ_ID>	mSurfIDs;
		vector<gmeSurface*>	mSurfs;

		GString			mGeoCode; //�ϵز����
		GString			mGeoCode2; //�µز����
	};

	
	class OG_GME_API gmeGeoEntity : public gmeGeometry  //������
	{
	public:
		gmeGeoEntity();
		gmeGeoEntity(const gmeGeoEntity &rhs);
		virtual ~gmeGeoEntity();

	public:
		gmeGeoEntity& operator=(gmeGeoEntity &rhs);
		long Clone(gmeGeoEntity& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID GeoEntityID, long lodlevel=0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//����
		long CompressSave(long lodlevel);//ѹ���洢
		long Delete(long lodlevel);
		long UndoDelete(long lodlevel);

		long SetGeoCode(GString strGeoCode);
		GString GetGeoCode();

		// ---------------------------- ����� ---------------------------- //
		long GetEntityNum();

		long AddAEntity(GME_TYPE_OBJ_ID entityID);
		gmeEntity* AddAEntity(string name = "");//�ڲ��Զ�����gmeEntity
		void AddAEntity(gmeEntity*ent);//����������gmeEntity
		long AddEntitys(GME_TYPE_OBJ_ID* entityIDs, long lEntityNum=1);

		long DeleteAEntity(long lEntityNo);
		long DeleteAEntity(GME_TYPE_OBJ_ID entityID);
		long DeleteEntitys();

		gmeEntity* GetAEntity(short lEntityNo);
		long GetAEntity(short lEntityNo, GME_TYPE_OBJ_ID &entityID);
		long GetEntitys(vector<GME_TYPE_OBJ_ID>& entityIDs);
		long GetEntitys(vector<gmeEntity*>& ents);

		long UpdateAEntity(long lEntityNo, GME_TYPE_OBJ_ID entityID);
		long UpdateAEntity(long lEntityNo, gmeEntity* entity);

	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

		friend class gmeStorageDB;
	private:
		vector<GME_TYPE_OBJ_ID>	mEntityIDs;
		vector<gmeEntity*>	mEntitys;
		GString			mGeoCode; //���ʱ���
	};


	
	class OG_GME_API gmeHole : public gmeGeometry  //���
	{
		friend class gmeStorageDB;

	public:
		gmeHole();
		virtual ~gmeHole();

	public:
		gmeHole& operator=(gmeHole &rhs);
		long Clone(gmeHole& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID HoleID,long lodlevel = 0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);//����
		long CompressSave(long lodlevel = 0);//ѹ���洢
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);

	public:
		//���û��ȡ�����Ϣ
		//bBuildtotal true��ʾһ��������幹��Ϊһ��ģ�ͣ�false��ʾ�ֶι������ģ��
		void SetHoleInfo(gme_hole* holeInfo, bool bBuildtotal = false);
		
		bool getbBuildMdlTotal(); // -- LH.2021.12.07 15:56 added.

		gme_hole* GetHoleInfo();
	
		//ȡ��׽ṹģ��
		gmeGeometry* GetHoleModel();
		gmeGeometry* GetHoleModel_with_layer();
		GME_TYPE_OBJ_ID GetHoleModelID();
		gmeGeometry* GetHoleEntity();
		//ȡ�����Ʒģ��
		gmeEntity* GetHoleSampModel();
		GME_TYPE_OBJ_ID GetHoleSampModelID();

	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

	private:
		gmeGeometry*	mHoleMdl; //���ģ��(gmeGeometry�����Ϳ�����gmeGeoLine(��״)��gmeGeoEntity(��״))
		gmeEntity*		mHoleSampMdl; //�����Ʒģ��
		gme_hole		mHoleInfo;	//�������
		bool			m_bBuildMdlTotal = true;
	};


	
	
	class OG_GME_API gmeFault : public gmeGeometry  //�ϲ�
	{
		friend class gmeStorageDB;

	public:
		gmeFault();
		virtual ~gmeFault();

	public:
		gmeFault& operator=(gmeFault &rhs);
		long Clone(gmeFault& obj);//��������
		long Clear();//���
		long Load(GME_TYPE_OBJ_ID FaultID, long lodlevel = 0);//�����ݿ����¼���
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);//����
		long CompressSave(long lodlevel = 0);//ѹ���洢 ɾ������existΪ0��Ԫ��
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);

	public:
		void SetFaultInfo(gme_fault* faultInfo);
		gme_fault* GetFaultInfo();
		gmeGeometry* GetFaultEntity();
		virtual long SetPosMatName(GString materialName);
		virtual GString GetPosMatName();
		///
		//ȡ�ϲ�ģ��
		gmeGeometry* GetFaultModel();
		GME_TYPE_OBJ_ID GetFaultModelID();
		///�����ϲ�ģ��
		void buildFaultModel();

	protected:
		virtual long CalBox();//��GetBox����,�����Χ��

	private:
		gmeGeometry*	mFaultEntity; //�ϲ�ģ��(gmeGeometry����ΪgmeGeoSurface-�ϲ����gmeGeoEntity-�ϲ��)
		gme_fault		mFaultInfo;
	};


}