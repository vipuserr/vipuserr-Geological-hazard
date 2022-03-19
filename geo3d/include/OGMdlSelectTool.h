#pragma once

#include "gmeEntity.h"


namespace Smart3dMap
{
	class osg::Node;

	typedef struct OG_SEL_MDL{
		OG_SubMdl_ID* pFID;
		//gmeGeometry* pGeometry;
		short MdlType;
	}OG_SEL_MDL;


	class OG_FRAME_DLL OGMdlSelectTool
	{
	private:
		OGMdlSelectTool(void);
		~OGMdlSelectTool(void);

	public:
		bool AddNodeToCurrentScene(osg::Node* pNode,OG_SubMdl_ID* pFID);
		bool RemoveNodeToCurrentScene(osg::Node* pNode,OG_SubMdl_ID* pFID);
		bool AddSlectNode(osg::Node* pNode);
		bool SlectNodeExist(OG_SubMdl_ID* pFID);
		vector<OG_SubMdl_ID*> getSlectResult();
		//ע��ýӿ�ʹ�õ�ʱ����Ҫ�ڵ��õ�ʱ���Ƚ�pSelMdl�ĳ�ԱpGeometry��ǰnew�ã�������ǰ�趨�����ͣ�ָ�뷵�غ���Ҫת�����Լ���Ҫ������ʹ��
		bool getSlectGeometry(OG_SubMdl_ID* pMdlFID,OG_SEL_MDL* pSelMdl);

		bool getSlectGeometry(OG_SubMdl_ID* pMdlFID,gmeSurface& surface);
		bool getSlectGeometry(OG_SubMdl_ID* pMdlFID,gmeEntity& entity);
		bool getSlectGeometry(OG_SubMdl_ID* pMdlFID,gmeLine& line);


		string getPickMdlMatName(OG_SEL_MDL* pSelMdl);
		string getPickMdlMatName(OG_SubMdl_ID* pSelMdl);

		bool HighLightModel(osg::Node* pNode);
		bool CanCelHighLightMdl(osg::Node* pNode);

		bool HighLightModel(OG_SubMdl_ID* pSubMdl);
		bool CanCelHighLightMdl(OG_SubMdl_ID* pSubMdl);
		bool CanCelHighLightMdl();
		bool CanCelSelectMdl();

		OG_SubMdl_ID* getMdlFID(osg::Node* pNode);
		osg::Node* getMdlNode(OG_SubMdl_ID* pSubMdl);



	protected:
		bool TransParentModel(osg::Node* pNode);
		bool CanCelTransParentMdl(osg::Node* pNode);
		string GenMaterialNameByParam(gmeSurface& pSurf);
	private:
		osg::ref_ptr<osg::StateSet> mCurrentState;
		map<osg::Node*,OG_SubMdl_ID*> mTotalNode;
		vector<OG_SubMdl_ID*> mSlectResult;

	public:
		// ����
		static OGMdlSelectTool& getSingleton(void);
		static OGMdlSelectTool* getSingletonPtr(void);

	};

}


