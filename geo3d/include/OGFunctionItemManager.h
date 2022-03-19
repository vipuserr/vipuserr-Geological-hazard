 #pragma once

#include "OGBasDef.h"
#include "OgIteratorWrapper.h"


namespace Smart3dMap {	

	// 功能项类型
	enum FunctionItemType
	{
		FIT_ITEM		= 0,
		FIT_GROUP		= 1,
		FIT_SEPARATOR	= 2,
	};

	// 功能项
	class OG_FRAME_DLL FunctionItem
	{
	public:	
		FunctionItem(void)
		{
			mType = (FIT_ITEM) ;
			mDescription = ("NONE") ;
			mName = ("NONE") ;
			mState = (false) ;
			mPosition = (-1) ;
			mFunction = ("NONE");
		}
			

		virtual ~FunctionItem(void) {};
		
		virtual	void clear(void) {}
		
		// 设/取名称
		void setName(const string& name) { mName = name; }
		const string& getName(void) const	{ return mName; }
		string getName(void)			{ return mName; }
		
		// 设/取描述
		void setDescription(const string& Description) { mDescription = Description; }
		const string& getDescription(void) const	{ return mDescription; }
		string getDescription(void)		{ return mDescription; }
		
		// 设/取状态
		void setState(bool b) 		{ mState = b; }
		bool getState(void)	const 		{ return mState; }
		void switchState(void) 			{ mState = !mState; }
		
		// 设/取位置(功能的唯一UID,供ON_COMMAND响应)
		// 这里用UINT表示ID,用size_t表示个数
		void setPosition(UINT pos)  		{ mPosition = pos; }
		UINT getPosition(void)	const 		{ return mPosition; }
		
		// 设/取函数名称(项目选中时响应所调用的函数名称 - 用于功能映射)
		void setFunctionType(const string func_type)  		{ mFunction = func_type; }
		string getFunctionType(void)	const { return mFunction; }
		
		// 设/取功能项类型
		void setType(FunctionItemType t) 	{ mType = t; }
		FunctionItemType getType(void) 			{ return mType; }
		
	protected:
		FunctionItemType mType;        // 类别	
		string			 mName;        // 项目名称	
		bool			 mState;       // 状态	
		UINT    		 mPosition;    // ID号	
		string			 mDescription; // 描述信息	
		string   		 mFunction;    // 功能名称 - 用于消息映射
	};
	
	// 功能组
	class OG_FRAME_DLL FunctionItemGroup : public FunctionItem
	{
		friend class FunctionItemManager;
	public:	
		FunctionItemGroup(FunctionItemManager* functionItemManager);
		virtual ~FunctionItemGroup();		
		
		// 添加项目
		FunctionItem* appendItem(FunctionItemType type, const string& newItemName);
		
		// 插入项目
		FunctionItem* insertItem(const string& name, 
			FunctionItemType type, const string& newItemName);
		
		// 删除项目
		void removeItem(const string& name);
		
		// 删除项目
		void removeItem(FunctionItem* item);

		// 删除多个项目(该组中直接孩子)
		void removeRangeItems(const string& from, const string& to);

		// 取项目
		FunctionItem* getItem(const string& name);		
		// 根据序列号查找功能项
		FunctionItem* getItem(UINT nRank);
		// 获取项目
		FunctionItem* getItem(FunctionItemGroup* pItemGroup, UINT nRank);		
		// 功能数目
		size_t size(void);
		// 删除所有子功能
		void clear(void);
		
		// 获取管理器指针
		FunctionItemManager* getFunctionItemManager() { return mfunctionItemManager; }
		// 随机获取
		FunctionItem* operator[] (size_t pos);
		
		typedef std::vector<FunctionItem*> FunctionItemList;
		typedef VectorIterator<FunctionItemList> FunctionItemIterator;

		FunctionItemIterator getFunctionItemIterator(void){
			return FunctionItemIterator(mfuncItems.begin(), mfuncItems.end());
		}	
	protected:			
		// 自动生成菜单
		void genMenu(HMENU hSubMenu, FunctionItemGroup* pGroup);
		// 取项目的id
		size_t getItemIndex(const string& name);
		
		FunctionItemList mfuncItems; // 功能项目	
		FunctionItemManager* mfunctionItemManager;
	};
	
	// 功能项管理器虚基类,从该类继承即可带功能项
	// 比如带功能项的插件等..
	class OG_FRAME_DLL FunctionItemManager
	{	
	public:
		FunctionItemManager();
		virtual ~FunctionItemManager();
		// 功能项管理:
		// 取功能项名称
		string getItemName(UINT nID);
		// 取功能项描述
		string getItemDescription(UINT nID);
		// 取功能项类型
		string getItemFunctionType(UINT nID);
		// 切换功能项状态(选中/不选中)
		void switchItemState(UINT nID);	
		
		// 直接取功能项指针
		FunctionItem* getItem(const string& name);
		// 取根功能组指针
		FunctionItemGroup* getRootItem(void);
		// 取最大项目数目
		static size_t getNumMaxItems(void);
		void setNumMaxItems(const size_t nNumMaxItems);		
		// 响应消息,执行Item中定义的函数		
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam) = 0;
		// 派生插件必须在此函数中完成写入功能列表的工作
		virtual void registerFunctions(void) = 0;
		virtual void unRegisterFunctions(void);
		// 菜单句柄
		virtual HMENU getHMenu(void);
		virtual UINT _getNextMenuUINT();
	protected:
		virtual void genMenu(void);
		HMENU getMenu(void);
	private:		
		// 在Debug时Output所有功能项信息
		void dumpMenu(FunctionItemGroup* pItemGroup);		
	protected:
		FunctionItemGroup* mFuncItemGroup;  // 本身是一个功能组		
		static size_t mNumMaxItems;  // 最大功能数
		UINT mItemPosition;
		HMENU mdynMenu;
	};
}
