 #pragma once

#include "OG2DLayer.h"


namespace Smart3dMap
{

	class OG_FRAME_DLL OGDbLayer : public OG2DLayer
	{
	public:
		OGDbLayer(const string& name, const OGGUID& guid);

	public:
		~OGDbLayer(void);


		//ʵ�ֹ���ע��͹��ܵ���,�Ӹ���̳еĴ��麯��
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);

		//��xml�ļ��ж�ȡģ�Ͳ���
		virtual bool load(DataElement* element);
		//��xml�ļ���д��ģ�Ͳ���
		virtual bool save(DataElement* element);


		virtual void setVisible(bool visible, bool cascade=true);
		virtual void onDbClick(void);
		virtual void onCreate();
		virtual void onDestroy(void);
	};
	
}

