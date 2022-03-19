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


		//实现功能注册和功能调用,从父类继承的纯虚函数
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);

		//从xml文件中读取模型参数
		virtual bool load(DataElement* element);
		//向xml文件中写入模型参数
		virtual bool save(DataElement* element);


		virtual void setVisible(bool visible, bool cascade=true);
		virtual void onDbClick(void);
		virtual void onCreate();
		virtual void onDestroy(void);
	};
	
}

