#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeEntity.h"
#include "gmeStru.h"



namespace Smart3dMap
{
	class OG_GME_API gmeGeoPnt : public gmeCorner //地质点
	{
	public:
		gmeGeoPnt();
		gmeGeoPnt(const gmeGeoPnt&rhs);
		virtual ~gmeGeoPnt();

	public:
		gmeGeoPnt& operator=(gmeGeoPnt &rhs);
		long Clone(gmeGeoPnt& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID	GeoPntID);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//保存
		long CompressSave();//压缩存储
		long Delete();
		long UndoDelete();

		long SetGeoCode(GString strGeoCode);
		GString GetGeoCode();

		friend class gmeStorageDB;
	private:
		GString			mGeoCode; //地质编码
	};

	class OG_GME_API gmeGeoOriPnt : public gmeGeoPnt //产状点
	{
	public:
		gmeGeoOriPnt();
		gmeGeoOriPnt(const gmeGeoOriPnt&rhs);
		virtual ~gmeGeoOriPnt();

	public:
		gmeGeoOriPnt& operator=(gmeGeoOriPnt &rhs);
		long Clone(gmeGeoOriPnt& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID GeoOriPntID);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB);//保存
		long CompressSave();//压缩存储
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

	class OG_GME_API gmeGeoLine : public gmeGeometry //地质线
	{
	public:
		gmeGeoLine();
		gmeGeoLine(gmeGeoLine&rhs);
		virtual ~gmeGeoLine();

	public:
		gmeGeoLine& operator=(gmeGeoLine &rhs);
		long Clone(gmeGeoLine& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID GeoLineID, long lodlevel=0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//保存
		long CompressSave(long lodlevel=0);//压缩存储
		long Delete(long lodlevel=0);
		long UndoDelete(long lodlevel=0);

		long SetGeoCode(GString strGeoCode);
		GString GetGeoCode();


		// ---------------------------- 线操作 ---------------------------- //
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
		virtual long CalBox();//被GetBox调用,计算包围盒

		friend class gmeStorageDB;
	private:
		vector<GME_TYPE_OBJ_ID>	mLinIDs;
		vector<gmeLine*>	mLins; //leo20200102新增 解决gmeGeoLine的内存级使用问题
		GString				mGeoCode; //地质线的上地层编码
		GString				mGeoCode2;//地质线的下地层编码
	};

	class OG_GME_API gmeGeoSurface : public gmeGeometry  //地质面
	{
	public:
		gmeGeoSurface();
		gmeGeoSurface(const gmeGeoSurface &rhs);
		virtual ~gmeGeoSurface();

	public:
		gmeGeoSurface& operator=(gmeGeoSurface &rhs);
		long Clone(gmeGeoSurface& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID GeoSurfaceID, long lodlevel=0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//保存
		long CompressSave(long lodlevel);//压缩存储
		long Delete(long lodlevel);
		long UndoDelete(long lodlevel);

		long SetGeoCode(GString strGeoCode);
		GString GetGeoCode();

		// ---------------------------- 面操作 ---------------------------- //
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
		virtual long CalBox();//被GetBox调用,计算包围盒

		friend class gmeStorageDB;
	private:
		vector<GME_TYPE_OBJ_ID>	mSurfIDs;
		vector<gmeSurface*>	mSurfs;

		GString			mGeoCode; //上地层编码
		GString			mGeoCode2; //下地层编码
	};

	
	class OG_GME_API gmeGeoEntity : public gmeGeometry  //地质体
	{
	public:
		gmeGeoEntity();
		gmeGeoEntity(const gmeGeoEntity &rhs);
		virtual ~gmeGeoEntity();

	public:
		gmeGeoEntity& operator=(gmeGeoEntity &rhs);
		long Clone(gmeGeoEntity& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID GeoEntityID, long lodlevel=0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel=0);//保存
		long CompressSave(long lodlevel);//压缩存储
		long Delete(long lodlevel);
		long UndoDelete(long lodlevel);

		long SetGeoCode(GString strGeoCode);
		GString GetGeoCode();

		// ---------------------------- 体操作 ---------------------------- //
		long GetEntityNum();

		long AddAEntity(GME_TYPE_OBJ_ID entityID);
		gmeEntity* AddAEntity(string name = "");//内部自动申请gmeEntity
		void AddAEntity(gmeEntity*ent);//由外面申请gmeEntity
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
		virtual long CalBox();//被GetBox调用,计算包围盒

		friend class gmeStorageDB;
	private:
		vector<GME_TYPE_OBJ_ID>	mEntityIDs;
		vector<gmeEntity*>	mEntitys;
		GString			mGeoCode; //地质编码
	};


	
	class OG_GME_API gmeHole : public gmeGeometry  //钻孔
	{
		friend class gmeStorageDB;

	public:
		gmeHole();
		virtual ~gmeHole();

	public:
		gmeHole& operator=(gmeHole &rhs);
		long Clone(gmeHole& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID HoleID,long lodlevel = 0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);//保存
		long CompressSave(long lodlevel = 0);//压缩存储
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);

	public:
		//设置或获取钻孔信息
		//bBuildtotal true表示一个钻孔整体构建为一个模型，false表示分段构建钻孔模型
		void SetHoleInfo(gme_hole* holeInfo, bool bBuildtotal = false);
		
		bool getbBuildMdlTotal(); // -- LH.2021.12.07 15:56 added.

		gme_hole* GetHoleInfo();
	
		//取钻孔结构模型
		gmeGeometry* GetHoleModel();
		gmeGeometry* GetHoleModel_with_layer();
		GME_TYPE_OBJ_ID GetHoleModelID();
		gmeGeometry* GetHoleEntity();
		//取钻孔样品模型
		gmeEntity* GetHoleSampModel();
		GME_TYPE_OBJ_ID GetHoleSampModelID();

	protected:
		virtual long CalBox();//被GetBox调用,计算包围盒

	private:
		gmeGeometry*	mHoleMdl; //钻孔模型(gmeGeometry的类型可能是gmeGeoLine(线状)或gmeGeoEntity(柱状))
		gmeEntity*		mHoleSampMdl; //钻孔样品模型
		gme_hole		mHoleInfo;	//钻孔数据
		bool			m_bBuildMdlTotal = true;
	};


	
	
	class OG_GME_API gmeFault : public gmeGeometry  //断层
	{
		friend class gmeStorageDB;

	public:
		gmeFault();
		virtual ~gmeFault();

	public:
		gmeFault& operator=(gmeFault &rhs);
		long Clone(gmeFault& obj);//拷贝对象
		long Clear();//清空
		long Load(GME_TYPE_OBJ_ID FaultID, long lodlevel = 0);//从数据库重新加载
		long Save(GME_MDL_IO_TYPE mdlIoType = GME_MDL_IO_DB, long lodlevel = 0);//保存
		long CompressSave(long lodlevel = 0);//压缩存储 删除表中exist为0的元素
		long Delete(long lodlevel = 0);
		long UndoDelete(long lodlevel = 0);

	public:
		void SetFaultInfo(gme_fault* faultInfo);
		gme_fault* GetFaultInfo();
		gmeGeometry* GetFaultEntity();
		virtual long SetPosMatName(GString materialName);
		virtual GString GetPosMatName();
		///
		//取断层模型
		gmeGeometry* GetFaultModel();
		GME_TYPE_OBJ_ID GetFaultModelID();
		///创建断层模型
		void buildFaultModel();

	protected:
		virtual long CalBox();//被GetBox调用,计算包围盒

	private:
		gmeGeometry*	mFaultEntity; //断层模型(gmeGeometry可能为gmeGeoSurface-断层面或gmeGeoEntity-断层块)
		gme_fault		mFaultInfo;
	};


}