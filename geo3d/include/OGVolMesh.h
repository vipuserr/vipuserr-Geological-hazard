 // OGVolTriMesh.h: interface for the TriMesh class.
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
const String OG_GUID_VOL_MESH_OBJECT = "845EAD3B-6F93-4e0d-9D4E-FB6D44B77901";

namespace OG {

	class OG_FRAME_DLL OGVolMesh : public OG3DElement//, public ManualResourceLoader 
	{
		friend class OGVolMeshFactory;
		friend class G3DVolumeInfoStru;

	protected:
		OGVolMesh(const String& name);
		virtual ~OGVolMesh();

	public:	
		// 继承OG3DElement::接口
		const String& getClassName(void) const;

		virtual bool load(DataElement* element);
		virtual bool save(DataElement* element);
		// 载入模型
		virtual bool load(String& strMeshName);

		virtual bool loadStart(DataElement* element);
		virtual bool loadFinish(void);
		virtual bool initFinish(const Vector3& position);



		//
		virtual bool save(void);
		// 保存模型
		virtual bool save(OG_Mdl_ID& oid);

		// 销毁
		virtual void destroy(void);		

		// 继承OG3DElement::接口结束
		virtual void reload(void);
	public:
		string getColorTableName();
		void setColorTableName(string pColorTableName);
		string getColorTableFilePath();
		vector<float> getColorTableAttu();
		vector<float> getVolumeParm();
		long	getMaxMinInvaValue(float &fAttMaxValue,float &fAttMinValue,float &fInvalidValue);
		G3DVolumeInfoStru* getG3DVolumeInfoStru();
		

	private:		
		Vector3					mScale;
		vector<float>			mVolumeParm;
	private:
		string					mColorTableName;
		string					mColorTableFilePath;
		G3DVolumeInfoStru*		mVolumeInfo;

	};


	class OG_FRAME_DLL OGVolMeshFactory : public OG3DElementFactory
	{
	public:
		OG3DElement* createInstance(const String& name)
		{	
			 OGVolMesh* object = new  OGVolMesh(name);
			return (OG3DElement*)object;
		}

		void destroyInstance(OG3DElement* node ) {
			OG_DELETE(node);
		}

		const OGGUID& getType() const {
			static OGGUID strGuid = OG_GUID_VOL_MESH_OBJECT;
			return strGuid;
		}
	};

}