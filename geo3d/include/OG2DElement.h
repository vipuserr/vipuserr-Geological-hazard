 #pragma once

#include "OGMessageListener.h"
#include "OGElementManager.h"




	namespace Smart3dMap
	{
		//元素命令
		//----------------------------------------------------------	
		const string STR_OPEN_ELEMENT			= "打开";
		const string STR_CLOSE_ELEMENT			= "关闭";
		const string STR_DEL_ELEMENT			= "删除节点";
		const string STR_RELT_ELEMENT			= "关联数据";
		const string STR_DEL_RELT_ELEMENT		= "删除关联";
		const string STR_SET_RULE_VALUE			= "设置显示阀值";
		const string STR_PROPERTY_ELEMENT		= "属性";

		class OG_FRAME_DLL OG2DElement :public Element, public Smart3dMap::COGListener
		{
		public:	
			OG2DElement(const string& name, const OGGUID& guid);
			virtual	~OG2DElement();


			// -------------------------原框架保持不变的函数--------------------------
		public:

			//命令映射
			virtual void DoCommand(UINT nID, WPARAM wParam, LPARAM lParam) {}

			//消息响应函数
			virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);

			//消息注册函数
			virtual void registerFunctions(void);
			
			//关联数据/删除关联
			virtual long ReltElement(){ return 0; }
			virtual long ReltElement(char *pFilePath){ return 0; }
			virtual long BeforeDelRelt(){ return 1; }
			virtual long DelRelt(){ return 1; }
			virtual long DispElement(long myDC){ return 1; }

			//消息响应
			virtual long OnMessagePro(long nMsg, __int64 wParam, __int64 lParam);

			//以下两个接口如果派生类实现了,则在完成自身功能后需再调用基类接口,以实现基类对结点的操作

			//添加了对数据中心工作空间关联结点的状态改变动作
			virtual void setVisible(bool visible);

			//删除并销毁节点指针
			virtual long DelteElement(BOOL bPrompt = TRUE);


			// 设置、获取显示比率
			virtual void getRuleRange(double &dMaxSize, double &dMinSize){ }
			virtual void setRuleRange(double dMaxSize,double dMinSize){ }

			// [11/7/2012 lt] 设置、获取当前视图的显示范围
			virtual void getDataRect(double&xMin, double&yMin, double&xMax, double&ymax){ }

			// [11/7/2012 lt] 设置是否自动显示的标记
			virtual void setAutoVisFlag(bool& bFlag){ }
			virtual void getAutoVisFlag(bool& bFlag){ }
		private:
			
		};
}
		