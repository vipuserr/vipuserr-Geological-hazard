 #pragma once

#include "s3d_SimpleMesh.h"
#include "OG3DElement.h"
#include "OG2DLayer.h"
#include "SceneNode.h"
#include "gmeMdl.h"
#include "CGMEPagedLodEvent.h"


namespace Smart3dMap
{
	class OG_FRAME_DLL OG3DLayer : public OG2DLayer
	{
	public:
		OG3DLayer(const string& name, const OGGUID& guid);

	public:
		~OG3DLayer(void);

		//设置要素对应的ID
		void set3DMdlID(const OG_Mdl_ID& fid);		
		//取得要素对应的ID
		const OG_Mdl_ID& get3DMdlID(void) const;
		//设置要素对应的strUrl
		void set3DMdlstrUrl(const std::string& url);
		//取得要素对应的strUrl
		const std::string& get3DMdlstrUrl(void) const;
		//设置该图层模型对应的数据库路径

		//设置场景缩放结点
		void setSceneNode(CSceneNode* node);
		//获取场景缩放结点
		CSceneNode* getSceneNode(void) const;


		//实现功能注册和功能调用,从父类继承的纯虚函数
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);

		//从xml文件中读取模型参数
		virtual bool load(DataElement* element);
		//向xml文件中写入模型参数
		virtual bool save(DataElement* element);

		void updateData();

		virtual void setVisible(bool visible, bool cascade=true);
		virtual void onDbClick(void);
		virtual void onCreate();
		virtual void onDestroy(void);

		void setPagedLodEvent();  //0831增
		
		void setOffset(Vector3 offset);
		Vector3 getOrSetOffset(gmeGeometry* geometry = NULL);
		Vector3 getOrSetOffset(vector<gme_vector3d>& vPoints);

		Vector3 getMdlEye();
		Vector3 getMdlCenter();
		Vector3 getMdlUp();
	public:
		virtual gmeModel* getLayerMdl();
		virtual void setLayerMdl(gmeModel* pmdl);

		virtual gmeFeature* getLayerFeature();
		virtual void setLayerFeature(gmeFeature* feat);

	protected:
		osg::ref_ptr<CSceneNode> mSceneNode;//场景结点用于挂接模型（CSceneNode型），挂接在mRoot下		

		string	mStrMdlUrl;       //模型url(后期删除)

		OG_Mdl_ID	mMdlID;		  //模型ID
		gmeModel	*mpLayerMdl;  //模型
		gmeFeature  *mFeature;    //要素

		Vector3	mOffset;    //偏移
		Vector3	mMdlEye;    //相机参数，保存模型状态
		Vector3	mMdlCenter;
		Vector3	mMdlUp;

		CGMEPagedLodEvent	*mPagedLodEvent;
	};
	
}

