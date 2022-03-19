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
		// ��Ӧ������Ի���
// 		virtual bool onCreateContainer(ContainerManager* creator, 
// 			string& dispName, OGGUID& guid, string& name) = 0;

		// ��Ӧ������Ի��򣨸��ݸ����ݲ㴴����
		virtual bool onCreateContainer(Container* parent, 
			string& dispName, OGGUID& guid, string& name) = 0;

		virtual bool SetTreeCtrlExpand(Container* parent) = 0;

		// ��Ӧ������Ԫ�ضԻ��򣨸��ݸ����ݲ㴴����
		virtual bool onCreateElement(Container* parent, 
			string& dispName, OGGUID& guid, string& name) = 0;

		// ��������
		virtual bool onRenameContainer(Container* container, string& newName) = 0;

		// ��Ԫ��������
		virtual bool onRenameElement(Element* element, string& newName) = 0;		

		// ����ͼ����ʾ����
		virtual bool onSetContainerScale(Container* container, Real& dX, Real& dY, Real& dZ) = 0;		

	};

	// ���ݲ������
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

		// ������ݲ㹤��
		void addFactory(ContainerFactory* pFactory);
		ContainerFactory* getFactory(const string& type);
		ContainerFactoryIterator getFactoryIterator(void){
			return ContainerFactoryIterator(mFactories.begin(), mFactories.end());
		}
		
		// ���������������ݲ�
		// ����: name: �������� type: ���ݲ�����
		Container* create(void);
		Container* create(const OGGUID& guid);
		Container* create(const string& name, const OGGUID& guid);		

		//������ɾ�����ݲ�
		void remove(Container* pContainer);
		// ��������ݲ��µ����������ݲ��Ԫ�غ�
		// �������ݲ��������������û�йҽӵ��κ����ݲ��µ����ݲ�
		void clear(void);

		// ��ø����ݲ�
		Container* getRootContainer(void) const;

		// ��ȡ
		bool exists(const string& name);

		// ��ȡ���ݲ�
		Container* getContainer(const string& name);

		// ��ȡĳ�������ݲ��б�
		void getContainerList(ContainerList& Containers, const OGGUID& guid);

		// ��ȡĳ�������ݲ���Ŀ
		const size_t getNumContainers(const OGGUID& guid = "");
		
		// ��ȡ�������ݲ��б� ~ Fast access to ContainerList
        const ContainerList& getContainerList(void) const;	
		
		// ���ݲ������
		ContainerIterator getContainerIterator(void){
			return ContainerIterator(mContainers.begin(), mContainers.end());
		}


		// ɾ�����ݲ�
		void destroyContainer(Container* pContainer);				
		// ɾ�����ݲ�
		void destroyContainer(const string& name);		
		// ɾ��һ�����ݲ�
		void destroyContainerList(const OGGUID& guid);		
		// ɾ���������ݲ�, �ڲ�ʹ��
		void destroyAllContainers(void);
		

		//ͼ��ͼ��
		void setLegendContainer(Container* pContainer);
		Container* getLegendContainer();

	
	    // ����ݲ����
		void setActiveContainer(const string& name);
		void setActiveContainer(Container* pContainer);
		Container* getActiveContainer(void);
		bool isActiveContainer(const string& name);
		bool isActiveContainer(Container* pContainer);		
		void emptyActiveContainer(void);


	   // �Ԫ�ع���
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


		// �����������
		void addContainerListener(ContainerListener* listener);
		void removeContainerListener(ContainerListener* listener);
		void removeAllContainerListeners(void);		
		ContainerListenerIterator getContainerListenerIterator(void) {
			return ContainerListenerIterator(mListeners.begin(), mListeners.end());
		}		

		// �������ݲ�
		bool load(const string& filename);
		// ж�����ݲ�
		bool unload(const string& filename);
		// �������ݲ�
		bool save(const string& filename);
		// ��Ϣת��
		void _routeMessage(UINT nMsg, WPARAM wParam = 0, LPARAM lParam = 0);
		// �������ݲ�ص�����
		void setContainerUIListener(ContainerUIListener* containerUIListener);
		ContainerUIListener* getContainerUIListener(void);
		string getRootName(); 
	private:		
		// ɾ�����ݲ� �ڲ�����
		void destroyContainerImpl(const string& name);
		// �������ɾ�������ݲ��ǵ�ǰ����ݲ�,�򽫵�ǰ����ݲ���Ϊ��
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

		ContainerFactoryList mFactories; // �����б�		
		ContainerList mContainers; // ���ݲ��б�
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


