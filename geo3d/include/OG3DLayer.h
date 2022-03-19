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

		//����Ҫ�ض�Ӧ��ID
		void set3DMdlID(const OG_Mdl_ID& fid);		
		//ȡ��Ҫ�ض�Ӧ��ID
		const OG_Mdl_ID& get3DMdlID(void) const;
		//����Ҫ�ض�Ӧ��strUrl
		void set3DMdlstrUrl(const std::string& url);
		//ȡ��Ҫ�ض�Ӧ��strUrl
		const std::string& get3DMdlstrUrl(void) const;
		//���ø�ͼ��ģ�Ͷ�Ӧ�����ݿ�·��

		//���ó������Ž��
		void setSceneNode(CSceneNode* node);
		//��ȡ�������Ž��
		CSceneNode* getSceneNode(void) const;


		//ʵ�ֹ���ע��͹��ܵ���,�Ӹ���̳еĴ��麯��
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);

		//��xml�ļ��ж�ȡģ�Ͳ���
		virtual bool load(DataElement* element);
		//��xml�ļ���д��ģ�Ͳ���
		virtual bool save(DataElement* element);

		void updateData();

		virtual void setVisible(bool visible, bool cascade=true);
		virtual void onDbClick(void);
		virtual void onCreate();
		virtual void onDestroy(void);

		void setPagedLodEvent();  //0831��
		
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
		osg::ref_ptr<CSceneNode> mSceneNode;//����������ڹҽ�ģ�ͣ�CSceneNode�ͣ����ҽ���mRoot��		

		string	mStrMdlUrl;       //ģ��url(����ɾ��)

		OG_Mdl_ID	mMdlID;		  //ģ��ID
		gmeModel	*mpLayerMdl;  //ģ��
		gmeFeature  *mFeature;    //Ҫ��

		Vector3	mOffset;    //ƫ��
		Vector3	mMdlEye;    //�������������ģ��״̬
		Vector3	mMdlCenter;
		Vector3	mMdlUp;

		CGMEPagedLodEvent	*mPagedLodEvent;
	};
	
}

