 // OGContainer.h: interface for the Container class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hash_map>
#include <string>
#include "OGObject.h"
#include "OGFunctionItemManager.h"
#include "OGElement.h"
#include "OGContainerListener.h"
namespace Smart3dMap {
	// 二维图层命令字符串
	//----------------------------------------------------------
	const string STR_CONTAINER_SELECT				= "选择数据层";
	const string STR_CONTAINER_UNSELECT				= "取消选择";
	const string STR_CONTAINER_DELETE				= "删除数据层";
	const string STR_CONTAINER_SET_AS_ACTIVE		= "设置活动";	
	//-----------------------------------------------------------
	/*const string STR_CONTAINER_CREATE_CHILD			= "新建图层文件";
	const string STR_CONTAINER_OPEN_CHILD			= "打开图层文件";
	const string STR_CONTAINER_CREATE_ELEMENT		= "创建元素";
	const string STR_CONTAINER_ALL_CHILD_VISIBLE	= "显示所有数据层";
	const string STR_CONTAINER_ALL_CHILD_INVISIBLE	= "隐藏所有数据层";
	const string STR_CONTAINER_DELETE_ALL_CHILDREN	= "删除所有数据层";	
	const string STR_CONTAINER_DELETE_ALL_ELEMENTS	= "删除所有元素";
	const string STR_CONTAINER_EXPAND_ELE			= "展开元素";
	const string STR_CONTAINER_UN_EXPAND_ELE		= "隐藏元素";
	const string STR_CONTAINER_CHANGE_NAME			= "重命名";
	const string STR_CONTAINER_SET_DISP_SCALE		= "设置显示比例";
	const string STR_CONTAINER_ADD_CHILD			= "添加数据层";*/
	const string STR_CONTAINER_CREATE_CHILD = "创建数据层";
	const string STR_CONTAINER_CREATE_ELEMENT = "创建元素";
	const string STR_CONTAINER_ALL_CHILD_VISIBLE = "显示所有数据层";
	const string STR_CONTAINER_ALL_CHILD_INVISIBLE = "隐藏所有数据层";
	const string STR_CONTAINER_DELETE_ALL_CHILDREN = "删除所有数据层";
	const string STR_CONTAINER_DELETE_ALL_ELEMENTS = "删除所有元素";
	const string STR_CONTAINER_EXPAND_ELE = "展开元素";
	const string STR_CONTAINER_UN_EXPAND_ELE = "隐藏元素";
	const string STR_CONTAINER_CHANGE_NAME = "重命名";
	const string STR_CONTAINER_SET_DISP_SCALE = "设置显示比例";
	//-----------------------------------------------------------
	const string STR_CONTAINER_PROPERTY				= "属性";

	//二维数据库命令字符串
	const string STR_CONTAINER_CREATE_DB_CHILD		= "打开数据库";
	const string STR_CONTAINER_CLOSE_DB_CHILD		= "关闭全部数据库";
	const string STR_CONTAINER_DELETE_DB_CHILD		= "移除全部数据库";

	//三维视图命令字符
	const string STR_CONTAINER_3D_CREATE_CHILD      = "创建三维图层";
	const string STR_CONTAINER_3D_CLOSE_CHILD       = "关闭三维图层";
	const string STR_CONTAINER_3D_DELETE_CHILD      = "移除三维图层";
	const string STR_CONTAINER_3D_OPEN_T3DFILE      = "打开三维模型";
	const string STR_CONTAINER_3D_CLOSE_T3DFILE     = "关闭全部模型";
	const string STR_CONTAINER_3D_DISP_T3DFILE      = "显示全部模型";	
	const string STR_CONTAINER_3D_DELETE_T3DFILE    = "移除全部模型";	

	////与树相关
	//修改树的Check状态
	const string STR_CONTAINER_TREE_ELEMENTCHECKVALUE = "修改ELEMENT树Check状态";
	const string STR_CONTAINER_TREE_ELEMENTSTATE      = "修改ELEMENT树可视化状态";
	const string STR_CONTAINER_TREE_LAYERCHECKVALUE   = "修改LAYER树Check状态";
	const string STR_CONTAINER_TREE_LAYERSTATE        = "修改LAYER树可视化状态";
	const string STR_CONTAINER_TWO_LAYERCHECKVALUE   = "修改LAYER树Check状态";
	const string STR_CONTAINER_TWO_LAYERSTATE        = "修改LAYER树可视化状态";
	const string MSG_CONTAINER_DB_TABLE_ELEMENCHECKVALUE = "修改数据库Element树Check状态";
	const string MSG_CONTAINER_DB_TABLE_ELEMENTSTATE = "修改数据库Element树可视化状态";
	const string MSG_CONTAINER_TREE_LAYERITEM = "处理Layer对应的树枝";
	const string MSG_CONTAINER_TREE_ELEMENTITEM = "处理Element对应的树枝";
	const string G3DVIEW_LAYER_OPERATION        = "三维图层节点消息_操作三维模型";
	const string G3DVIEW_ELEMENT_OPERATION      = "三维要素节点消息_操作三维模型";
	const string DATABASE_LAYER_OPERATION       = "数据库节点消息_操作表";
	const string DATABASE_ELEMENT_OPERATION     = "数据库节点消息_操作表";
	const string G2DVIEW_LAYER_OPERATION        = "二维节点消息_操作二维图层";
	const string G2DVIEW_ELEMENT_OPERATION      = "二维节点消息_操作二维图层";
	const string MSG_CONTAINER_CREATE_G2DVIEW_CHILD			= "消息_新建二维图层文件";
	const string MSG_CONTAINER_OPEN_G2DVIEW_CHILD			= "消息_打开二维图层文件";	
	const string MSG_CONTAINER_RESET_G2DVIEW_CHILD			= "消息_复位二维图层文件";	
	const string MSG_CONTAINER_ALL_CHILD_VISIBLE	= "消息_显示所有数据图层";
	const string MSG_CONTAINER_ALL_CHILD_INVISIBLE	= "消息_隐藏所有数据图层";
	const string MSG_CONTAINER_DELETE_ALL_CHILDREN	= "消息_删除所有二维数据图层";	
	const string MSG_CONTAINER_ALL_DB_INVISIBLE	= "消息_隐藏所有数据库层";
	const string MSG_CONTAINER_ALL_DB_DELETE	= "消息_删除所有数据库层";
	const string MSG_CONTAINER_ALL_TWO_DISPLAYORDER	= "消息_修改二维图层显示顺序";	
	const string MSG_NOTIFY_CONTAINER_TWO_LAYERCHECKVALUE   = "消息_告知二维图层的状态变化";
	const string MSG_NOTIFY_CONTAINER_THREE_ELEMENTCHECKVALUE   = "消息_告知三维模型的状态变化";
	////与工程文件相关
	const string MSG_CONTAINER_CREATE_NEWPROJECT	= "创建新工程";
	const string MSG_CONTAINER_OPEN_PROJECT	= "打开工程";
	const string MSG_CONTAINER_SAVE_PROJECT	= "保存工程";	
	const string MSG_CONTAINER_SAVE_AS_PROJECT	= "另存工程";
	const string MSG_CONTAINER_CLOSE_PROJECT	= "关闭工程";	
	// {9537542C-9554-4ed8-BA10-7D0270E04C6A}
	const string CONTAINER_GUID = "{ 0x9537542c, 0x9554, 0x4ed8, { 0xba, 0x10, 0x7d, 0x2, 0x70, 0xe0, 0x4c, 0x6a } }";
	typedef enum {OGGEOOBJECT = NULL,OGGEOOBJECTDB,OGGEOOBJECTT2D,OGGEOOBJECTT3D} OGGEOOBJECTTYPE;
	typedef enum {OGGEOFILE = NULL,OGGEOTABLEFILE,OGGEOT2DFILE,OGGEOT3DFILE} OGGEOFILETYPE;
	typedef enum {OGFILESTATENOTHING = 0, OGFILEVISIBLE,OGFILECLOSE,OGFILEEDIT} OGFILESTATE;
	struct PULGIN_BASICINFO
	{
		std::string m_dispName;
		std::string m_guid;
		std::string m_name;
		std::string m_parentname;
		OGGEOOBJECTTYPE m_enuObjectType;
		OGGEOFILETYPE m_enuFileType;
		OGFILESTATE  m_enuFileState;
		bool bIsRegister;
		PULGIN_BASICINFO()
		{
			bIsRegister = false;
			m_enuObjectType = OGGEOOBJECT;
			m_enuFileType = OGGEOFILE;
			m_enuFileState = OGFILESTATENOTHING;
		}
		void GetBasicInfo(std::string& dispName,std::string& guid,std::string& name)
		{
			dispName = m_dispName;
			guid = m_guid;
			name = m_name;
		}
	};

	// 数据层基类
	class OG_FRAME_DLL Container : public FunctionItemManager, public OGObject
	{
	public:
		// 数据层发生事件时调用
		class OG_FRAME_DLL Listener
		{
		public:
			Listener() {}
			virtual ~Listener() {}
			
			// 数据层被销毁
			virtual void containerDestroyed(const Container* container) {};

			// 数据层被attach
			virtual void containerAttached(const Container* container) {};
			
			// 数据层被detach
			virtual void containerDetached(const Container* container) {};
		
		};
		friend class ContainerManager;
	public:
		Container(const string& name, const OGGUID& guid);		
		virtual ~Container();

		// 取得显示名称
		virtual const string& getDisplayName(void) const;
		virtual void setDisplayName(const string& dispName);

		// 可见性cascade->是否迭代
		// 派生类必须后调用基类setVisible
		virtual void setVisible(bool visible, bool cascade = true);
		virtual bool isVisible(void) const;
		// 逆反可见性
		virtual void flipVisibility(bool cascade = true);
		// 选择
		virtual void select(bool select, bool cascade = true);
		virtual bool isSelected(void) const;
		// 反选
		virtual void flipSelect(bool cascade = true);
		// 冻结
		virtual void freeze(bool freeze, bool cascade = true);
		virtual bool isFrozen(void) const;
		// 锁定	
		virtual void lock(bool lock, bool cascade = true);
		virtual bool isLocked(void) const;

		// 从DataElement载入
		virtual bool load(DataElement* element);
		// 保存到DataElement
		virtual bool save(DataElement* element);

		// UI操作中的双击
		virtual void onDbClick() { };
		// 属性对话框
		virtual void onPropertyDialog() { };
	
		// 命令映射 - 继承FunctionItemManager
		// 如果要基类函数onCommand,请在函数最后调用Container::onCommand()		
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);		
		virtual void registerFunctions(void);	

		//#define HashMap stdext::hash_map;
		typedef stdext::hash_map<string, Container*> ChildContainerMap;
        typedef MapIterator<ChildContainerMap> ChildContainerIterator;
		typedef ConstMapIterator<ChildContainerMap> ConstChildContainerIterator;

		// 设置创建数据层的管理器指针
		ContainerManager* getCreator(void) const;
		void setCreator(ContainerManager* manager); 

		// 以下函数维护数据层之间层次关系
		// 设置父数据层
		virtual void setParent(Container* parent);		
		virtual Container* getParent(void) const;

		// 创建数据层 - 如果不传名称 则内部自动生成
        virtual Container* createChild(const OGGUID& guid);

        // 创建数据层 - 则内部自动生成
        virtual Container* createChild(const string& name, const OGGUID& guid);

        // 添加(已经创建的)数据层, 如果这个数据层attach到其他数据层,必须先detach
        virtual void addChild(Container* child);

        // 获得数据层个数
        virtual unsigned short getNumChildren(void) const;

        // 根据索引号得到数据层指针
        virtual Container* getChild(unsigned short index) const;    

		// 根据名词得到数据层指针
        virtual Container* getChild(const string& name) const;

        // 移除所有子数据层
        virtual void removeAllChild(bool bDestroy=0);
		//移除一个孩子节点及其所有子孙节点
        virtual void removeAllChild(Container* child, bool bDestroy=0);

        // 数据层迭代器
        virtual ChildContainerIterator getChildIterator(void);
		virtual ConstChildContainerIterator getChildIterator(void) const;

		// 判断是否在数据层树中
		virtual bool isInGraph(void) const { return mIsInGraph; }		

		// 内部方法,设置是否在数据层树中,在setParent的时候调用
		void setInGraph(bool inGraph);		

		// 该数据层为根数据层,只有数据层管理器能调用该函数		
		virtual void _notifyRootContainer(void) { mIsInGraph = true; }
		
		// 以下函数维护数据层元素
		typedef stdext::hash_map<string, Element*> ElementMap;
	    typedef MapIterator<ElementMap> ObjectIterator;
		typedef ConstMapIterator<ElementMap> ConstObjectIterator;

		// 创建元素
		virtual Element* createAttachedObject(DataElement* element);
		virtual Element* createAttachedObject(const std::string& name, const std::string& type);
	
		// 添加元素
		virtual void attachObject(Element* element);

		// 获取元素指针
		virtual Element* getAttachedObject(size_t index);

		// 获取元素指针
		virtual Element* getAttachedObject(const string& name);

		// 获取元素个数
		virtual const size_t getNumAttachedObjects(void) const;	
		
		// 删除元素
		virtual void detachObject(Element* element, bool bDestroy=0);
		// 删除所有元素
		virtual void detachAllObjects(bool bDestroy=0);

		 // 元素迭代器
        virtual ObjectIterator getAttachedObjectIterator(void);
		virtual ConstObjectIterator getAttachedObjectIterator(void) const;

		// 设置层监听器
		void setListener(Listener* listener) { mListener = listener; }		
		// 取层监听器
		Listener* getListener(void) const { return mListener; }

		// 判断是否支持该类型的数据层
		bool checkChildTypeSupported(const OGGUID& guid);
		// 判断是否支持该类型的元素
		bool checkElementTypeSupported(const OGGUID& guid);

		// 将Container中的所有内容合并到当前Container
		// 并删除Container内部的Container和元素,但不删除Container
		bool merge(Container* container);

		// 允许被监听
		void setListeningEnabled(bool enabled);

		// 是否允许被监听
		bool getListeningEnabled(void) const;

		//是否在树上将元素节点列出
		bool setChildInTreeListFlag(bool bList = true);

		virtual void setPosition(Real x,Real y,Real z);

		//是否展开元素
		virtual bool ExpandElement(bool bExpand);

		//设置节点的显示比例
		long SetDispScale();
		virtual void setScale(Real x,Real y,Real z);
		virtual void getScale(Real& x,Real& y,Real& z);
		//设置场景的显示比例
		virtual void setSceneScale(Real x, Real y, Real z) {}
		virtual void setSceneScale(){}
		virtual void getSceneScale(Real x, Real y, Real z){}

		virtual int getIConBMPNO(){return mICon_BmpNo;}
		virtual void setIConBMPNO(int ICon_BmpNo){ mICon_BmpNo  =ICon_BmpNo;}

		// 改变结点位置,src为改变的结点，des为新的结点位置，将src改变到des后面
		// add by dj 2017.6.8
		void changeChildOrder(Container* src, Container* des);
		void changeChildOrder(Element* src, Element* des);

		//获取数据层的数据 2020.12.30
		virtual __int64 getContainerData() { return 1; }

		//属性获取函数
		void SetContainerCurrentExpandinTreeCtrl();
		void InitialDefaultMsg();
		void Initial2DViewMsg();
		void Initial3DViewMsg();
		void InitialDBViewMsg();
		void onExecuteIn2DView(const string& name, WPARAM wParam, LPARAM lParam);	
		void onExecuteIn3DView(const string& name, WPARAM wParam, LPARAM lParam);	
		void onExecuteInDBView(const string& name, WPARAM wParam, LPARAM lParam);	
		string getCurrentRootName();
		void AddT2DLayerItem();
		void AddT2DLayerItem(std::vector<PULGIN_BASICINFO*>& vBasicInfos);
		void AddDBLayerItem(PULGIN_BASICINFO* pInfo);
	protected:
		// 初始化完调用该函数
		virtual void onCreate(void);

		// 销毁完调用该函数
		virtual void onDestroy(void);

		// 创建数据层的内部实现 如果包含数据层, 必须实现该函数
        virtual Container* createChildImpl(const OGGUID& guid);

        // 创建数据层的内部实现 如果包含数据层, 必须实现该函数
        virtual Container* createChildImpl(const string& name, const OGGUID& guid);

		// 创建元素的内部实现 如果包含元素的创建, 必须实现该函数
		virtual Element* createAttachedObjectImpl(DataElement* element);

	public:

		// 移除数据层(并不删除),该数据层可以重新attach到别的数据层
        virtual Container* removeChild(Container* child, bool bDestroy=0);
		
		//关联数据/删除关联
		virtual long ReltLayer() { return 1; }
		virtual long BeforeDelRelt() { return 1; }
		virtual long DelRelt() { return 1; }
		virtual long BeforeDelLayer() { return 1; }
		virtual long DelLayer(BOOL bPrompt = TRUE) { return 1; }

	public:
		void SetScleX(Real pScaleX) { mScaleX = pScaleX; }
		void SetScleY(Real pScaleY) { mScaleY = pScaleY; }
		void SetScleZ(Real pScaleZ) { mScaleZ = pScaleZ; }
		Real GetScleX() { return mScaleX; }
		Real GetScleY() { return mScaleY; }
		Real GetScleZ() { return mScaleZ; }

		void SetTotalScleX(Real pTotalScaleX) { mTotalScaleX = pTotalScaleX; }
		void SetTotalScleY(Real pTotalScaleY) { mTotalScaleY = pTotalScaleY; }
		void SetTotalScleZ(Real pTotalScaleZ) { mTotalScaleZ = pTotalScaleZ; }
		Real GetTotalScleX() { return mTotalScaleX; }
		Real GetTotalScleY() { return mTotalScaleY; }
		Real GetTotalScleZ() { return mTotalScaleZ; }

		std::string getStrMsgID();
		void setStrMsgID(std::string strMsgID);

		//图层容器管理
		void setDemLayerState(__int64 layer, bool bIsVisble = true);
		void setRasterLayerState(__int64 layer, bool bIsVisble = true);
		void setRegLayerState(__int64 layer, bool bIsVisble = true);
		void setLinLayerState(__int64 layer, bool bIsVisble = true);
		void setPntLayerState(__int64 layer, bool bIsVisble = true);
		void getLayers(vector<__int64>& pMapLayers);

		static void removeAllLayer();
		virtual void setUrl(string	strEleUrl) { mLayerUrl = strEleUrl; }
		virtual string getUrl() { return mLayerUrl; }
		std::string getCanvasName() { return m_CanvasName; }
		void	setCanvasName(std::string canvasName) { m_CanvasName = canvasName; };
	private:
		// 载入数据层 - 被load调用
		bool loadChildren(DataElement* element);
		bool loadElements(DataElement* element);
		
		// 保存元素 - 被save调用
		bool saveChildren(DataElement* element);
		bool saveElements(DataElement* element);
		
		void setChildIndex(Container *pcontainer,BOOL bAdd = TRUE);
		void setObjectIndex(Element *pelement,BOOL bAdd = TRUE);


	protected:
		// 元素指针列表
		ElementMap mElementsByName;	
//	private:
		// 指向父亲数据层的指针
        Container* mParent;
		// 创建者
		ContainerManager* mCreator;
		// 直接数据层指针列表
        ChildContainerMap mChildren;
     	// 可见性
		bool mVisible;
		// 是否选择
		bool mSelected;
		// 是否冻结
		bool mFrozen;
		// 是否锁定
		bool mLocked;
		// 是否在数据层树中
		bool mIsInGraph;
		// 显示名
		string mDisplayName;		
		// 只支持一个
		Listener* mListener;
		//是否允许被监听
		bool mEnabled;

		bool mbChildInTreeListFlag;

		int mICon_BmpNo;
		//增加一个消息变量
		std::string mstrMsgID;
		string				mLayerUrl;
		string  m_CanvasName = "";

	private:
		bool mbChangeScale;
		Real mScaleX,mScaleY,mScaleZ;
		Real mTotalScaleX, mTotalScaleY, mTotalScaleZ;
	};
} // namespace Smart3dMap

