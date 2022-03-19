 // OGlement.h: interface for the ContainerElement1 class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGFunctionItemManager.h"
#include "OGObject.h"

#include <unordered_map>
using namespace std;

namespace Smart3dMap {
	// 元素命令字符串
	const string STR_ELEMENT_DELETE				= "删除对象";
	const string STR_ELEMENT_PROPERTY			= "显示对象属性";
	const string STR_ELEMENT_CHANGE_NAME		= "重命名";

	const string STR_ELEMENT_SET_ACTIVE			= "设为活动";
	const string STR_ELEMENT_SET_EDIT			= "设为编辑";

//
	static string ELEMENT_GUID = "{579FC6DD-B46D-42e9-9879-CCB7139119FA}";

    // 元素基类
	class OG_FRAME_DLL Element :public FunctionItemManager, public OGObject
	{
		friend class ElementManager;
	protected:
		Element(const string& name);
		Element(const string& name,const string& guid);
		virtual ~Element();
	public:
		// 取得显示名称
	    virtual const string& getDisplayName(void) const;
	    virtual void setDisplayName(const string& dispName);

		// 从DataElement载入
		virtual bool load(DataElement* element);
		// 保存到DataElement
		virtual bool save(DataElement* element);

		// 取所在容器
		virtual Container* getParentContainer(void) const;

		// 内部调用
		virtual void _notifyAttached(Container* parent);

		// 是否在容器中
		virtual bool isAttached(void) const;
		
		// 设创建器
		virtual void setCreator(void* creator);

		// 创建器
		virtual void* getCreator(void) const;
		
		// 派生类必须后调用基类setVisible
		virtual void setVisible(bool visible);
		virtual bool isVisible(void) const;	

		// 选择
		virtual void select(bool select = true);
		virtual bool isSelected(void) const;

		// 冻结
		virtual void freeze(bool freeze);
		virtual bool isFrozen(void) const;
		// 锁定	
		virtual void lock(bool lock);
		virtual bool isLocked(void) const;
		virtual void Edit(bool bEdit);
		virtual bool isEdit(void) const;

		// 命令映射 - 继承FunctionItemManager
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		
		// 双击
		virtual void onDbClick(void) { };
		// 属性对话框
		virtual void onPropertyDialog(void) { };
		
		virtual void setScale(Real x,Real y,Real z);
		virtual void setPosition(Real x,Real y,Real z);

		// 销毁
		virtual void destroy(void);

		virtual int getIConBMPNO(){return mIConBMPNo;}
		virtual void setIConBMPNO(int ICon_BmpNo){ mIConBMPNo  =ICon_BmpNo;}

		virtual bool getHasData(){return mHasData;}
		virtual void setHasData(bool HasData){ mHasData  =HasData;}

		 void setDemLayerState(__int64 layer, bool bIsVisble = true);
		 void setRasterLayerState(__int64 layer, bool bIsVisble = true);
		 void setRegLayerState(__int64 layer, bool bIsVisble = true);
		 void setLinLayerState(__int64 layer, bool bIsVisble = true);
		 void setPntLayerState(__int64 layer, bool bIsVisble = true);
		 void getLayers(vector<__int64>& pMapLayers);
		 virtual void setUrl(string	strEleUrl) { mEleUrl = strEleUrl; }
		 virtual string getUrl() { return mEleUrl; }

		 std::string getCanvasName() { return m_CanvasName; }
		 void	setCanvasName(std::string canvasName) { m_CanvasName = canvasName; };

		 virtual __int64 getLayerPtr();

	public:
		bool IsEdit();
		void CloseEditStatus();
		void ActivateEditStatus();
	protected:
	    // 初始化完调用该函数
		virtual void onCreate(void);

		int mIConBMPNo;
		bool mHasData;
		std::string m_CanvasName;
	private:
		void* mElementMgr;
		ContainerManager* mContainerMgr;// 创建者
		Container* mParentContainer;

		bool mVisible;
		bool mSelected;
		bool mFrozen;
		bool mLocked;
		bool mEdit;
		string mDisplayName;
		string	mEleUrl;
	};
}


