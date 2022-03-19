 // OGTriMesh.h: interface for the TriMesh class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OG3DElement.h"
#include "OG3DElementManager.h"

#include "OgSimpleMesh.h"
#include "OG3DRenderEngine.h"
#include "OGG3DVolumeBase.h"



//------------------------------------------------
const String OG_GUID_TRI_MESH_OBJECT = "6BB42D64-913E-42ff-B2CC-A8DCFCF8B8AC";

namespace OG {
	
	class OG_FRAME_DLL TriMesh : public OG3DElement//, public ManualResourceLoader 
	{
		friend class TriMeshFactory;
	protected:
		TriMesh(const String& name);
		virtual ~TriMesh();

	public:	
		/* override ManualResourceLoader */
	//	virtual void loadResource(Resource* resource);		

		// 继承OG3DElement接口
		const String& getClassName(void) const;

		virtual bool load(DataElement* element);
		virtual bool save(DataElement* element);
		// 载入模型
		virtual bool load(SuperMesh& smesh);
		virtual bool load(String& strMeshName);

		virtual bool loadStart(DataElement* element);
		virtual bool loadFinish(void);

		virtual bool initFinish(const Vector3& position);



		// 保存为gmeEntity,保存完取OG_Mdl_ID
		virtual bool save(void);
		// 保存模型
		virtual bool save(OG_Mdl_ID& oid);

		// 返回Movable
		virtual MovableObject* getMovableObject(void) const;
		// 销毁
		virtual void destroy(void);		

		// 是否启用透明
		bool isAlphaEnabled(void);
		void setAlphaEnabled(bool bEnabled);

		// 透明度
		void setTransparency(Real transparency);
		Real getTransparency(void) const;
		
		// 继承OG3DElement接口结束

		// 是否为静态实体
		bool getIsStatic(void) const { return mIsStatic; }
		
		// 是否接受阴影
		bool getCastShadows(void) const { return mCastShadows; }

		// 取实体
		Entity* getEntity(void) { return mSceneEntity; }
		
		// 设置Entity
		void setupEntity(Entity* entity);
		// 销毁
		void destroyEntity(Entity* entity);

		virtual void reload(void);

		//osg::Node* getCurentNode(void);



	private:		
		bool saveByC3DEntity(void);



	private:		
		Entity*			mSceneEntity;
		Vector3			mOffset;
		Vector3			mScale;
		Quaternion		mOrientation;	
		uint32			mRepresentMask;


		bool mIsStatic;
		bool mCastShadows;
	};

	
	class OG_FRAME_DLL TriMeshFactory : public OG3DElementFactory
	{
	public:
		OG3DElement* createInstance(const String& name)
		{	
			TriMesh* object = new TriMesh(name);
			return (OG3DElement*)object;
        }
        
        void destroyInstance(OG3DElement* node ) {
			OG_DELETE(node);
		}
		
		const OGGUID& getType() const {
			static OGGUID strGuid = OG_GUID_TRI_MESH_OBJECT;
			return strGuid;
		}
	};

}