#pragma once

	#include "OGMessageListener.h"
	#include "OGContainerManager.h"

	using namespace Smart3dMap;

	namespace Smart3dMap
	{
		// ͼ������
		//----------------------------------------------------------
		const string STR_OPEN_LAYER				= "��";
		const string STR_CLOSE_LAYER			= "�ر�";
		const string STR_DEL_LAYER				= "ɾ��ͼ��";
		const string STR_RELT_LAYER				= "��������";
		const string STR_DEL_RELT_LAYER			= "ɾ������";
		const string STR_PROPERTY_LAYER			= "����";

		class  OG_FRAME_DLL OG2DLayer : public Container, public Smart3dMap::COGListener
		{
		public:
			OG2DLayer(const string& name, const OGGUID& guid);
			virtual ~OG2DLayer();	

		public:
			//����ӳ��
			virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
			virtual void registerFunctions(void);
			//��Ϣ��Ӧ
			virtual long	OnMessagePro(long nMsg, __int64 wParam, __int64 lParam){ return 1; }

			//��������/ɾ������
			virtual long ReltLayer(){ return 1; }
			virtual long BeforeDelRelt(){ return 1; }
			virtual long DelRelt(){ return 1; }
			virtual long BeforeDelLayer(){ return 1; }
			virtual long DelLayer(BOOL bPrompt = TRUE);

			/*******************************************************************************
			Function��setContainerNodeInfo
			purpose:����ͼ���������Ϣ
			input:aliasName��ͼ�����ʾ���ƣ�Ҳ������Ϊ�����ռ������,�������½����ǰ����
			********************************************************************************/
			void setContainerNodeInfo(string& aliasName);
			virtual void setVisible(bool visible, bool cascade = true);

			virtual void setUrl(string	strEleUrl) { mLayerUrl = strEleUrl; }
			virtual string getUrl() { return mLayerUrl; }

			//zhuyh-2021-6-9
			//��������δ���������ڻ�ȡ�����һЩ��Ϣ
			virtual __int64 getLayerPtr() { return 0; };

		protected:
			virtual Element* createAttachedObjectImpl(DataElement* element);

		private:
			ContainerManager	*m_ContainerManager;	//��άͼ�������
			ElementManager		*m_ElementManager;		//��άԪ�ع�����
		};

}
		