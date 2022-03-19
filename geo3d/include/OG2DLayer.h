#pragma once

	#include "OGMessageListener.h"
	#include "OGContainerManager.h"

	using namespace Smart3dMap;

	namespace Smart3dMap
	{
		// 图层命令
		//----------------------------------------------------------
		const string STR_OPEN_LAYER				= "打开";
		const string STR_CLOSE_LAYER			= "关闭";
		const string STR_DEL_LAYER				= "删除图层";
		const string STR_RELT_LAYER				= "关联数据";
		const string STR_DEL_RELT_LAYER			= "删除关联";
		const string STR_PROPERTY_LAYER			= "属性";

		class  OG_FRAME_DLL OG2DLayer : public Container, public Smart3dMap::COGListener
		{
		public:
			OG2DLayer(const string& name, const OGGUID& guid);
			virtual ~OG2DLayer();	

		public:
			//命令映射
			virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
			virtual void registerFunctions(void);
			//消息响应
			virtual long	OnMessagePro(long nMsg, __int64 wParam, __int64 lParam){ return 1; }

			//关联数据/删除关联
			virtual long ReltLayer(){ return 1; }
			virtual long BeforeDelRelt(){ return 1; }
			virtual long DelRelt(){ return 1; }
			virtual long BeforeDelLayer(){ return 1; }
			virtual long DelLayer(BOOL bPrompt = TRUE);

			/*******************************************************************************
			Function：setContainerNodeInfo
			purpose:设置图层结点关联信息
			input:aliasName：图层的显示名称，也用来作为工作空间结点别名,必须在新建结点前调用
			********************************************************************************/
			void setContainerNodeInfo(string& aliasName);
			virtual void setVisible(bool visible, bool cascade = true);

			virtual void setUrl(string	strEleUrl) { mLayerUrl = strEleUrl; }
			virtual string getUrl() { return mLayerUrl; }

			//zhuyh-2021-6-9
			//由于子类未导出，用于获取子类的一些信息
			virtual __int64 getLayerPtr() { return 0; };

		protected:
			virtual Element* createAttachedObjectImpl(DataElement* element);

		private:
			ContainerManager	*m_ContainerManager;	//二维图层管理器
			ElementManager		*m_ElementManager;		//二维元素管理器
		};

}
		