 // OGContainerManager.h: interface for the ContainerManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGContainer.h"
#include "OGContainerFactory.h"
#include "OGElement.h"


namespace Smart3dMap { 
	// 
	class ContainerUIListener
	{
	public:
		// 响应创建层对话框
// 		virtual bool onCreateContainer(ContainerManager* creator, 
// 			string& dispName, OGGUID& guid, string& name) = 0;

		// 响应创建层对话框（根据父数据层创建）
		virtual bool onCreateContainer(Container* parent, 
			string& dispName, OGGUID& guid, string& name) = 0;

		virtual bool SetTreeCtrlExpand(Container* parent) = 0;

		// 响应创建层元素对话框（根据父数据层创建）
		virtual bool onCreateElement(Container* parent, 
			string& dispName, OGGUID& guid, string& name) = 0;

		// 层重命名
		virtual bool onRenameContainer(Container* container, string& newName) = 0;

		// 层元素重命名
		virtual bool onRenameElement(Element* element, string& newName) = 0;		

		// 设置图层显示比例
		virtual bool onSetContainerScale(Container* container, Real& dX, Real& dY, Real& dZ) = 0;		

	};

	// 数据层管理器
	class OG_FRAME_DLL ContainerManager
	{
	public:
		typedef std::map<string, Container*> ContainerList;
		typedef MapIterator<ContainerList> ContainerIterator;
		
		typedef std::map<string, ContainerFactory*> ContainerFactoryList;
		typedef MapIterator<ContainerFactoryList> ContainerFactoryIterator;

		typedef std::vector<ContainerListener*> ContainerListenerList;
		typedef VectorIterator<ContainerListenerList> ContainerListenerIterator;
	public:
		ContainerManager(const string& instanceName);
		virtual ~ContainerManager();

		/** Return the instance name of this ContainerManager. */
		const string& getName(void) const { return mName; }

		/** Retrieve the type name of this scene manager.*/
		virtual const string& getTypeName(void) const = 0;

		// 添加数据层工厂
		void addFactory(ContainerFactory* pFactory);
		ContainerFactory* getFactory(const string& type);
		ContainerFactoryIterator getFactoryIterator(void){
			return ContainerFactoryIterator(mFactories.begin(), mFactories.end());
		}
		
		// 创建（生产）数据层
		// 参数: name: 工具名称 type: 数据层类型
		Container* create(void);
		Container* create(const OGGUID& guid);
		Container* create(const string& name, const OGGUID& guid);		

		//从树中删除数据层
		void remove(Container* pContainer);
		// 清除根数据层下的所有子数据层和元素和
		// 其他数据层管理器产生但是没有挂接到任何数据层下的数据层
		void clear(void);

		// 获得根数据层
		Container* getRootContainer(void) const;

		// 获取
		bool exists(const string& name);

		// 获取数据层
		Container* getContainer(const string& name);

		// 获取某类型数据层列表
		void getContainerList(ContainerList& Containers, const OGGUID& guid);

		// 获取某类型数据层数目
		const size_t getNumContainers(const OGGUID& guid = "");
		
		// 获取所有数据层列表 ~ Fast access to ContainerList
        const ContainerList& getContainerList(void) const;	
		
		// 数据层迭代器
		ContainerIterator getContainerIterator(void){
			return ContainerIterator(mContainers.begin(), mContainers.end());
		}


		// 删除数据层
		void destroyContainer(Container* pContainer);				
		// 删除数据层
		void destroyContainer(const string& name);		
		// 删除一类数据层
		void destroyContainerList(const OGGUID& guid);		
		// 删除所有数据层, 内部使用
		void destroyAllContainers(void);
		

		//图例图层
		void setLegendContainer(Container* pContainer);
		Container* getLegendContainer();

	
	    // 活动数据层管理
		void setActiveContainer(const string& name);
		void setActiveContainer(Container* pContainer);
		Container* getActiveContainer(void);
		bool isActiveContainer(const string& name);
		bool isActiveContainer(Container* pContainer);		
		void emptyActiveContainer(void);


	   // 活动元素管理
		//void setActiveElement(const string& name);
		void setActiveElement(Element* pElement);
		Element* getActiveElement(void);
		void setEditElement(Element* pElement, bool bEdit = true);
		void getEditElement(vector<Element*>& editEleList);

		void setActivePrjElement(Element* pElement);
		Element* getActivePrjElement(void);

		//bool isActiveElement(const string& name);
		bool isActiveElement(Element* pElement);		
		void emptyActiveElement(void);		


		// 层监听器管理
		void addContainerListener(ContainerListener* listener);
		void removeContainerListener(ContainerListener* listener);
		void removeAllContainerListeners(void);		
		ContainerListenerIterator getContainerListenerIterator(void) {
			return ContainerListenerIterator(mListeners.begin(), mListeners.end());
		}		

		// 载入数据层
		bool load(const string& filename);
		// 卸载数据层
		bool unload(const string& filename);
		// 保存数据层
		bool save(const string& filename);
		// 消息转发
		void _routeMessage(UINT nMsg, WPARAM wParam = 0, LPARAM lParam = 0);
		// 设置数据层回调对象
		void setContainerUIListener(ContainerUIListener* containerUIListener);
		ContainerUIListener* getContainerUIListener(void);
		string getRootName(); 
	private:		
		// 删除数据层 内部调用
		void destroyContainerImpl(const string& name);
		// 如果是所删除的数据层是当前活动数据层,则将当前活动数据层置为空
		void autoEmptyActiveContainer(Container* pContainer);			
	private:
		Container* mRootContainer;
		RootContainerFactory* mRootContainerFactory;

		bool mLoaded;
		Container*  mActiveContainer;
		Container*  mLegendContainer;
		//  [3/10/2015 Feng]
		Element*  mActiveElement;
		Element*  mActivePrjElement;

		ContainerFactoryList mFactories; // 工厂列表		
		ContainerList mContainers; // 数据层列表
		/// A list of all registered external container listeners.
		ContainerListenerList mListeners;
		ContainerUIListener* mContainerUIListener;
		string mName;
	};

		/** Structure containing information about a scene manager. */
	struct ContainerManagerMetaData
	{
		/// A globally unique std::string identifying the scene manager type
		string typeName;
		/// A text description of the scene manager
		string description;
		/// Flag indicating whether world geometry is supported
		bool worldGeometrySupported;
	};
    
	/** Class which will create instances of a given ContainerManager. */
	class OG_FRAME_DLL ContainerManagerFactory
	{
	protected:
		mutable ContainerManagerMetaData mMetaData;
		mutable bool mMetaDataInit;
		/// Internal method to initialise the metadata, must be implemented
		virtual void initMetaData(void) const = 0;
	public:
		ContainerManagerFactory() : mMetaDataInit(true) {}
		virtual ~ContainerManagerFactory() {}
		/** Get information about the ContainerManager type created by this factory. */
		virtual const ContainerManagerMetaData& getMetaData(void) const 
		{
			if (mMetaDataInit)
			{
				initMetaData();
				mMetaDataInit = false;
			}
			return mMetaData; 
		}
		/** Create a new instance of a ContainerManager.
		@remarks
		Don't call directly, use ContainerManagerEnumerator::createContainerManager.
		*/
		virtual ContainerManager* createInstance(const string& instanceName) = 0;
		/** Destroy an instance of a ContainerManager. */
		virtual void destroyInstance(ContainerManager* instance) = 0;

	};

	/// Factory for default scene manager
	class OG_FRAME_DLL DefaultContainerManagerFactory : public ContainerManagerFactory
	{
	protected:
		void initMetaData(void) const;
	public:
		DefaultContainerManagerFactory() {}
		~DefaultContainerManagerFactory() {}
		/// Factory type name
		static const string FACTORY_TYPE_NAME;
		ContainerManager* createInstance(const string& instanceName);
		void destroyInstance(ContainerManager* instance);
	};
	
	/// Default scene manager
	class OG_FRAME_DLL DefaultContainerManager : public ContainerManager
	{
	public:
		DefaultContainerManager(const string& name);
		~DefaultContainerManager();
		const string& getTypeName(void) const;
	};
} // namespace Smart3dMap


