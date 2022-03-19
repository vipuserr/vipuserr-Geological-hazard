#pragma once

#include "GmeCommonLayer.h"
#include "OG3DElement.h"
#include "OGFrameWork.h"
#include "OG3DLayerManager.h"
#include "OGGme3DLayerGuid.h"
#include "OG3DElementManager.h"
#include "layerplugin_geo3d_global.h"


//��άͼ��CGMELayer�����Ź���
//const string	FUNC_AddModel = "����ģ��";
const string	FUNC_Legend = "ͼ������";
const string	FUNC_DrawText = "ע�ǿ���";
const string	FUNC_SaveModel = "�洢ģ��";

const string	FUNC_JumpToModel = "��ת��ʾ";
const string	FUNC_ShowNormal = "��ʾ����";
const string	FUNC_ShowTriIDs = "��ʾ�����κ�";
const string	FUNC_ShowTriVertexIDs = "��ʾ�����ζ����";
const string	FUNC_layerTransparency = "ͼ��͸����";

const string	FUNC_BuildIsoMap = "���ɵز�����ֵ��";//������


namespace Smart3dMap
{
	class LAYERPLUGIN_GEO3D_EXPORT CGMELayer : public GmeCommonLayer
	{
	public:
		CGMELayer(const string& name, const OGGUID& guid);
		~CGMELayer();

		//����ӳ��
		virtual void registerFunctions(void);
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);

		//��Ϣ��Ӧ
		virtual void registerIntMsg();
		virtual long OnMessagePro(long nMsg, __int64 wParam, __int64 lParam);

		virtual void registerStrMsg();
		virtual long OnMessagePro(string msg, __int64 wParam, __int64 lParam);

		//ɾ������
		virtual long BeforeDelRelt();
		virtual long DelRelt();

		//ɾ��ͼ��
		virtual long BeforeDelLayer();
		virtual long DelLayer(BOOL bPrompt = TRUE);

		//��DataElement����
		virtual bool load(DataElement* element);
		//���浽DataElement
		virtual bool save(DataElement* element);
		virtual void BeforeSave();

		//���ݿɼ�
		virtual void setVisible(bool visible, bool cascade = true);

	public:
		void setScaleFactor(osg::Vec3 factor);
		osg::Vec3 getScaleFactor();

		//ע��
		osg::ref_ptr<osg::MatrixTransform> cvtGmeNote23DLayer();

		//δʹ��
		void MdlSave2GmeDB();

	protected:
		//δʹ��
		Container* GetLayerContainer(std::string enuFileFilter);
		Container* GetLayerContainer();
		Container* OpenThreedimensionFile(std::string strFilterCondition);


	};

	COMMON_LAYLER_FACTORY(CGMELayer, THREEDIMENSION_LAYER_GUID, "��άģ��");
}
