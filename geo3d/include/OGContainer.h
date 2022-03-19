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
	// ��άͼ�������ַ���
	//----------------------------------------------------------
	const string STR_CONTAINER_SELECT				= "ѡ�����ݲ�";
	const string STR_CONTAINER_UNSELECT				= "ȡ��ѡ��";
	const string STR_CONTAINER_DELETE				= "ɾ�����ݲ�";
	const string STR_CONTAINER_SET_AS_ACTIVE		= "���û";	
	//-----------------------------------------------------------
	/*const string STR_CONTAINER_CREATE_CHILD			= "�½�ͼ���ļ�";
	const string STR_CONTAINER_OPEN_CHILD			= "��ͼ���ļ�";
	const string STR_CONTAINER_CREATE_ELEMENT		= "����Ԫ��";
	const string STR_CONTAINER_ALL_CHILD_VISIBLE	= "��ʾ�������ݲ�";
	const string STR_CONTAINER_ALL_CHILD_INVISIBLE	= "�����������ݲ�";
	const string STR_CONTAINER_DELETE_ALL_CHILDREN	= "ɾ���������ݲ�";	
	const string STR_CONTAINER_DELETE_ALL_ELEMENTS	= "ɾ������Ԫ��";
	const string STR_CONTAINER_EXPAND_ELE			= "չ��Ԫ��";
	const string STR_CONTAINER_UN_EXPAND_ELE		= "����Ԫ��";
	const string STR_CONTAINER_CHANGE_NAME			= "������";
	const string STR_CONTAINER_SET_DISP_SCALE		= "������ʾ����";
	const string STR_CONTAINER_ADD_CHILD			= "������ݲ�";*/
	const string STR_CONTAINER_CREATE_CHILD = "�������ݲ�";
	const string STR_CONTAINER_CREATE_ELEMENT = "����Ԫ��";
	const string STR_CONTAINER_ALL_CHILD_VISIBLE = "��ʾ�������ݲ�";
	const string STR_CONTAINER_ALL_CHILD_INVISIBLE = "�����������ݲ�";
	const string STR_CONTAINER_DELETE_ALL_CHILDREN = "ɾ���������ݲ�";
	const string STR_CONTAINER_DELETE_ALL_ELEMENTS = "ɾ������Ԫ��";
	const string STR_CONTAINER_EXPAND_ELE = "չ��Ԫ��";
	const string STR_CONTAINER_UN_EXPAND_ELE = "����Ԫ��";
	const string STR_CONTAINER_CHANGE_NAME = "������";
	const string STR_CONTAINER_SET_DISP_SCALE = "������ʾ����";
	//-----------------------------------------------------------
	const string STR_CONTAINER_PROPERTY				= "����";

	//��ά���ݿ������ַ���
	const string STR_CONTAINER_CREATE_DB_CHILD		= "�����ݿ�";
	const string STR_CONTAINER_CLOSE_DB_CHILD		= "�ر�ȫ�����ݿ�";
	const string STR_CONTAINER_DELETE_DB_CHILD		= "�Ƴ�ȫ�����ݿ�";

	//��ά��ͼ�����ַ�
	const string STR_CONTAINER_3D_CREATE_CHILD      = "������άͼ��";
	const string STR_CONTAINER_3D_CLOSE_CHILD       = "�ر���άͼ��";
	const string STR_CONTAINER_3D_DELETE_CHILD      = "�Ƴ���άͼ��";
	const string STR_CONTAINER_3D_OPEN_T3DFILE      = "����άģ��";
	const string STR_CONTAINER_3D_CLOSE_T3DFILE     = "�ر�ȫ��ģ��";
	const string STR_CONTAINER_3D_DISP_T3DFILE      = "��ʾȫ��ģ��";	
	const string STR_CONTAINER_3D_DELETE_T3DFILE    = "�Ƴ�ȫ��ģ��";	

	////�������
	//�޸�����Check״̬
	const string STR_CONTAINER_TREE_ELEMENTCHECKVALUE = "�޸�ELEMENT��Check״̬";
	const string STR_CONTAINER_TREE_ELEMENTSTATE      = "�޸�ELEMENT�����ӻ�״̬";
	const string STR_CONTAINER_TREE_LAYERCHECKVALUE   = "�޸�LAYER��Check״̬";
	const string STR_CONTAINER_TREE_LAYERSTATE        = "�޸�LAYER�����ӻ�״̬";
	const string STR_CONTAINER_TWO_LAYERCHECKVALUE   = "�޸�LAYER��Check״̬";
	const string STR_CONTAINER_TWO_LAYERSTATE        = "�޸�LAYER�����ӻ�״̬";
	const string MSG_CONTAINER_DB_TABLE_ELEMENCHECKVALUE = "�޸����ݿ�Element��Check״̬";
	const string MSG_CONTAINER_DB_TABLE_ELEMENTSTATE = "�޸����ݿ�Element�����ӻ�״̬";
	const string MSG_CONTAINER_TREE_LAYERITEM = "����Layer��Ӧ����֦";
	const string MSG_CONTAINER_TREE_ELEMENTITEM = "����Element��Ӧ����֦";
	const string G3DVIEW_LAYER_OPERATION        = "��άͼ��ڵ���Ϣ_������άģ��";
	const string G3DVIEW_ELEMENT_OPERATION      = "��άҪ�ؽڵ���Ϣ_������άģ��";
	const string DATABASE_LAYER_OPERATION       = "���ݿ�ڵ���Ϣ_������";
	const string DATABASE_ELEMENT_OPERATION     = "���ݿ�ڵ���Ϣ_������";
	const string G2DVIEW_LAYER_OPERATION        = "��ά�ڵ���Ϣ_������άͼ��";
	const string G2DVIEW_ELEMENT_OPERATION      = "��ά�ڵ���Ϣ_������άͼ��";
	const string MSG_CONTAINER_CREATE_G2DVIEW_CHILD			= "��Ϣ_�½���άͼ���ļ�";
	const string MSG_CONTAINER_OPEN_G2DVIEW_CHILD			= "��Ϣ_�򿪶�άͼ���ļ�";	
	const string MSG_CONTAINER_RESET_G2DVIEW_CHILD			= "��Ϣ_��λ��άͼ���ļ�";	
	const string MSG_CONTAINER_ALL_CHILD_VISIBLE	= "��Ϣ_��ʾ��������ͼ��";
	const string MSG_CONTAINER_ALL_CHILD_INVISIBLE	= "��Ϣ_������������ͼ��";
	const string MSG_CONTAINER_DELETE_ALL_CHILDREN	= "��Ϣ_ɾ�����ж�ά����ͼ��";	
	const string MSG_CONTAINER_ALL_DB_INVISIBLE	= "��Ϣ_�����������ݿ��";
	const string MSG_CONTAINER_ALL_DB_DELETE	= "��Ϣ_ɾ���������ݿ��";
	const string MSG_CONTAINER_ALL_TWO_DISPLAYORDER	= "��Ϣ_�޸Ķ�άͼ����ʾ˳��";	
	const string MSG_NOTIFY_CONTAINER_TWO_LAYERCHECKVALUE   = "��Ϣ_��֪��άͼ���״̬�仯";
	const string MSG_NOTIFY_CONTAINER_THREE_ELEMENTCHECKVALUE   = "��Ϣ_��֪��άģ�͵�״̬�仯";
	////�빤���ļ����
	const string MSG_CONTAINER_CREATE_NEWPROJECT	= "�����¹���";
	const string MSG_CONTAINER_OPEN_PROJECT	= "�򿪹���";
	const string MSG_CONTAINER_SAVE_PROJECT	= "���湤��";	
	const string MSG_CONTAINER_SAVE_AS_PROJECT	= "��湤��";
	const string MSG_CONTAINER_CLOSE_PROJECT	= "�رչ���";	
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

	// ���ݲ����
	class OG_FRAME_DLL Container : public FunctionItemManager, public OGObject
	{
	public:
		// ���ݲ㷢���¼�ʱ����
		class OG_FRAME_DLL Listener
		{
		public:
			Listener() {}
			virtual ~Listener() {}
			
			// ���ݲ㱻����
			virtual void containerDestroyed(const Container* container) {};

			// ���ݲ㱻attach
			virtual void containerAttached(const Container* container) {};
			
			// ���ݲ㱻detach
			virtual void containerDetached(const Container* container) {};
		
		};
		friend class ContainerManager;
	public:
		Container(const string& name, const OGGUID& guid);		
		virtual ~Container();

		// ȡ����ʾ����
		virtual const string& getDisplayName(void) const;
		virtual void setDisplayName(const string& dispName);

		// �ɼ���cascade->�Ƿ����
		// ������������û���setVisible
		virtual void setVisible(bool visible, bool cascade = true);
		virtual bool isVisible(void) const;
		// �淴�ɼ���
		virtual void flipVisibility(bool cascade = true);
		// ѡ��
		virtual void select(bool select, bool cascade = true);
		virtual bool isSelected(void) const;
		// ��ѡ
		virtual void flipSelect(bool cascade = true);
		// ����
		virtual void freeze(bool freeze, bool cascade = true);
		virtual bool isFrozen(void) const;
		// ����	
		virtual void lock(bool lock, bool cascade = true);
		virtual bool isLocked(void) const;

		// ��DataElement����
		virtual bool load(DataElement* element);
		// ���浽DataElement
		virtual bool save(DataElement* element);

		// UI�����е�˫��
		virtual void onDbClick() { };
		// ���ԶԻ���
		virtual void onPropertyDialog() { };
	
		// ����ӳ�� - �̳�FunctionItemManager
		// ���Ҫ���ຯ��onCommand,���ں���������Container::onCommand()		
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);		
		virtual void registerFunctions(void);	

		//#define HashMap stdext::hash_map;
		typedef stdext::hash_map<string, Container*> ChildContainerMap;
        typedef MapIterator<ChildContainerMap> ChildContainerIterator;
		typedef ConstMapIterator<ChildContainerMap> ConstChildContainerIterator;

		// ���ô������ݲ�Ĺ�����ָ��
		ContainerManager* getCreator(void) const;
		void setCreator(ContainerManager* manager); 

		// ���º���ά�����ݲ�֮���ι�ϵ
		// ���ø����ݲ�
		virtual void setParent(Container* parent);		
		virtual Container* getParent(void) const;

		// �������ݲ� - ����������� ���ڲ��Զ�����
        virtual Container* createChild(const OGGUID& guid);

        // �������ݲ� - ���ڲ��Զ�����
        virtual Container* createChild(const string& name, const OGGUID& guid);

        // ���(�Ѿ�������)���ݲ�, ���������ݲ�attach���������ݲ�,������detach
        virtual void addChild(Container* child);

        // ������ݲ����
        virtual unsigned short getNumChildren(void) const;

        // ���������ŵõ����ݲ�ָ��
        virtual Container* getChild(unsigned short index) const;    

		// �������ʵõ����ݲ�ָ��
        virtual Container* getChild(const string& name) const;

        // �Ƴ����������ݲ�
        virtual void removeAllChild(bool bDestroy=0);
		//�Ƴ�һ�����ӽڵ㼰����������ڵ�
        virtual void removeAllChild(Container* child, bool bDestroy=0);

        // ���ݲ������
        virtual ChildContainerIterator getChildIterator(void);
		virtual ConstChildContainerIterator getChildIterator(void) const;

		// �ж��Ƿ������ݲ�����
		virtual bool isInGraph(void) const { return mIsInGraph; }		

		// �ڲ�����,�����Ƿ������ݲ�����,��setParent��ʱ�����
		void setInGraph(bool inGraph);		

		// �����ݲ�Ϊ�����ݲ�,ֻ�����ݲ�������ܵ��øú���		
		virtual void _notifyRootContainer(void) { mIsInGraph = true; }
		
		// ���º���ά�����ݲ�Ԫ��
		typedef stdext::hash_map<string, Element*> ElementMap;
	    typedef MapIterator<ElementMap> ObjectIterator;
		typedef ConstMapIterator<ElementMap> ConstObjectIterator;

		// ����Ԫ��
		virtual Element* createAttachedObject(DataElement* element);
		virtual Element* createAttachedObject(const std::string& name, const std::string& type);
	
		// ���Ԫ��
		virtual void attachObject(Element* element);

		// ��ȡԪ��ָ��
		virtual Element* getAttachedObject(size_t index);

		// ��ȡԪ��ָ��
		virtual Element* getAttachedObject(const string& name);

		// ��ȡԪ�ظ���
		virtual const size_t getNumAttachedObjects(void) const;	
		
		// ɾ��Ԫ��
		virtual void detachObject(Element* element, bool bDestroy=0);
		// ɾ������Ԫ��
		virtual void detachAllObjects(bool bDestroy=0);

		 // Ԫ�ص�����
        virtual ObjectIterator getAttachedObjectIterator(void);
		virtual ConstObjectIterator getAttachedObjectIterator(void) const;

		// ���ò������
		void setListener(Listener* listener) { mListener = listener; }		
		// ȡ�������
		Listener* getListener(void) const { return mListener; }

		// �ж��Ƿ�֧�ָ����͵����ݲ�
		bool checkChildTypeSupported(const OGGUID& guid);
		// �ж��Ƿ�֧�ָ����͵�Ԫ��
		bool checkElementTypeSupported(const OGGUID& guid);

		// ��Container�е��������ݺϲ�����ǰContainer
		// ��ɾ��Container�ڲ���Container��Ԫ��,����ɾ��Container
		bool merge(Container* container);

		// ��������
		void setListeningEnabled(bool enabled);

		// �Ƿ���������
		bool getListeningEnabled(void) const;

		//�Ƿ������Ͻ�Ԫ�ؽڵ��г�
		bool setChildInTreeListFlag(bool bList = true);

		virtual void setPosition(Real x,Real y,Real z);

		//�Ƿ�չ��Ԫ��
		virtual bool ExpandElement(bool bExpand);

		//���ýڵ����ʾ����
		long SetDispScale();
		virtual void setScale(Real x,Real y,Real z);
		virtual void getScale(Real& x,Real& y,Real& z);
		//���ó�������ʾ����
		virtual void setSceneScale(Real x, Real y, Real z) {}
		virtual void setSceneScale(){}
		virtual void getSceneScale(Real x, Real y, Real z){}

		virtual int getIConBMPNO(){return mICon_BmpNo;}
		virtual void setIConBMPNO(int ICon_BmpNo){ mICon_BmpNo  =ICon_BmpNo;}

		// �ı���λ��,srcΪ�ı�Ľ�㣬desΪ�µĽ��λ�ã���src�ı䵽des����
		// add by dj 2017.6.8
		void changeChildOrder(Container* src, Container* des);
		void changeChildOrder(Element* src, Element* des);

		//��ȡ���ݲ������ 2020.12.30
		virtual __int64 getContainerData() { return 1; }

		//���Ի�ȡ����
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
		// ��ʼ������øú���
		virtual void onCreate(void);

		// ��������øú���
		virtual void onDestroy(void);

		// �������ݲ���ڲ�ʵ�� ����������ݲ�, ����ʵ�ָú���
        virtual Container* createChildImpl(const OGGUID& guid);

        // �������ݲ���ڲ�ʵ�� ����������ݲ�, ����ʵ�ָú���
        virtual Container* createChildImpl(const string& name, const OGGUID& guid);

		// ����Ԫ�ص��ڲ�ʵ�� �������Ԫ�صĴ���, ����ʵ�ָú���
		virtual Element* createAttachedObjectImpl(DataElement* element);

	public:

		// �Ƴ����ݲ�(����ɾ��),�����ݲ��������attach��������ݲ�
        virtual Container* removeChild(Container* child, bool bDestroy=0);
		
		//��������/ɾ������
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

		//ͼ����������
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
		// �������ݲ� - ��load����
		bool loadChildren(DataElement* element);
		bool loadElements(DataElement* element);
		
		// ����Ԫ�� - ��save����
		bool saveChildren(DataElement* element);
		bool saveElements(DataElement* element);
		
		void setChildIndex(Container *pcontainer,BOOL bAdd = TRUE);
		void setObjectIndex(Element *pelement,BOOL bAdd = TRUE);


	protected:
		// Ԫ��ָ���б�
		ElementMap mElementsByName;	
//	private:
		// ָ�������ݲ��ָ��
        Container* mParent;
		// ������
		ContainerManager* mCreator;
		// ֱ�����ݲ�ָ���б�
        ChildContainerMap mChildren;
     	// �ɼ���
		bool mVisible;
		// �Ƿ�ѡ��
		bool mSelected;
		// �Ƿ񶳽�
		bool mFrozen;
		// �Ƿ�����
		bool mLocked;
		// �Ƿ������ݲ�����
		bool mIsInGraph;
		// ��ʾ��
		string mDisplayName;		
		// ֻ֧��һ��
		Listener* mListener;
		//�Ƿ���������
		bool mEnabled;

		bool mbChildInTreeListFlag;

		int mICon_BmpNo;
		//����һ����Ϣ����
		std::string mstrMsgID;
		string				mLayerUrl;
		string  m_CanvasName = "";

	private:
		bool mbChangeScale;
		Real mScaleX,mScaleY,mScaleZ;
		Real mTotalScaleX, mTotalScaleY, mTotalScaleZ;
	};
} // namespace Smart3dMap

