#pragma once

#include "ogframeaux_global.h"
#include "OGTreeCtrl.h"
#include "OGBasDef.h"
#include "OGContainerListener.h"
#include "OGContainerManager.h"
#include "OGMessageListener.h"
#include "OGBasDef.h"
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction> 

namespace Smart3dMap
{

	typedef QStandardItem* _HTREEITEM;
	typedef long _CImageList;

	class OGFRAMEAUX_EXPORT OGContainerTreeCtrl : public OGTreeCtrl, public ContainerListener, public ContainerUIListener, public Smart3dMap::COGListener
	{
		Q_OBJECT

		struct DBINFO
		{
			std::string strDBName;
			std::string strDBFilepath;
		};

		enum _ITEM_TYPE
		{
			_ITEM_TYPE_SOLUTION = 0,
			_ITEM_TYPE_CONTAINER = 1,
			_ITEM_TYPE_ELEMENT = 2,
			_ITEM_TYPE_ELEMENTSUB = 3,
			_ITEM_FORCE_DWORD = 0x7fffFFFF,
		};

		typedef struct _ITEM_DATA
		{
			_ITEM_TYPE	  type;
			DWORD		  dwData;		// �洢������ָ��
		}ITEM_DATA;

	public:
		OGContainerTreeCtrl(
			ContainerManager* p2DContainerManager, ElementManager *p2DElementManager,
			ContainerManager* p3DContainerManager = nullptr, ElementManager *p3DElementManager = nullptr,
			ContainerManager* pDbContainerManager = nullptr, ElementManager *pDbElementManager = nullptr,
			QWidget *parent = nullptr);

		~OGContainerTreeCtrl();

		//���ؼ���Ϣ����
	public:
		virtual void contextMenuEvent(QContextMenuEvent* event);

	public:
		// �̳��� COGListener
		virtual void registerStrMsg();
		virtual long OnMessagePro(string msg, __int64 wParam, __int64 lParam);
		
		// �̳���ContainerUIListener
		virtual bool onCreateContainer(Container* parent, std::string& dispName, OGGUID& guid, std::string& name);
		virtual bool onCreateElement(Container* parent, std::string& dispName, OGGUID& guid, std::string& name);
		virtual bool onRenameContainer(Container* container, std::string& newName);// ��������
		virtual bool onRenameElement(Element* element, std::string& newName);// ��Ԫ��������
		virtual bool onSetContainerScale(Container* container, Real& dX, Real& dY, Real& dZ);// ����ͼ����ʾ����
		virtual void onContainerOrderChanged();
		virtual bool SetTreeCtrlExpand(Container* pContainer);

		// �̳���ContainerListener
		virtual void postAddContainer(Container* pContainer);
		virtual bool preRemoveContainer(Container* pContainer);
		virtual bool preDestroyContainer(Container* pContainer);
		virtual bool preRemoveAndDestroyAllChildren(Container* pContainer);
		virtual void onUpdateContainer(Container* pContainer);

		virtual void postContainerVisibilityChanged(Container* pContainer, bool cascade = true);
		virtual void postContainerSelectChanged(Container* pContainer, bool cascade = true);
		virtual void postContainerNameChanged(Container* Container);
		virtual void postContainerFreezeChanged(Container* pContainer, bool cascade = true);
		virtual void postContainerLockChanged(Container* pContainer, bool cascade = true);
		virtual void postActiveContainerChanged(Container* pContainer);

		virtual void postActiveElementChanged(Element* element);
		virtual void postElementVisibilityChanged(Element* element);
		virtual void postElementSelectChanged(Element* element);
		virtual void postElementNameChanged(Element* element);
		virtual void postElementFreezeChanged(Element* element);
		virtual void postElementLockChanged(Element* element);

		virtual bool preDetachAllObjects(Container* pContainer);// ��һԪ�صĲ���
		virtual void postAttachObject(Element* element);
		virtual bool preDetachObject(Element* element);
		
		virtual bool preContainerScaleChanged(Container* container); //���������ı�
		virtual void postContainerScaleChanged(Container* container);
		virtual bool preElementScaleChanged(Element* element);
		virtual void postElementScaleChanged(Element* element);

		virtual void ChangeContainerICon(Container* pContainer, int preIcon, int postIcon);
		virtual void ChangeElementICon(Element* pElement, int preIcon, int postIcon);
		virtual bool ExpandContainerChild(Container* container, bool bExpand);
		virtual void ExpandContainerTree(_HTREEITEM hItem, bool bExpand);
		virtual bool AddElementChild(Element* pParentElem, Element* pSubElem);


	public:
		void InitTreeCtrl();
		void AddDBInfo(Container* parent, std::string strDBFilepath, std::string strDBName);

		void SetImages(_CImageList *pImageList, int iRootImg = 0, int iFoldImg = 0, int iFoldSelImg = 0,
			int iNodeImg = 0, int iNodeSelImg = 0, int iNotVisibleImg = 0, int iVisibleImg = 0);

		void SetDragSucceed(BOOL bDragSucceed) { mbDragSucceed = bDragSucceed; }
		BOOL GetDragSucceed() { return mbDragSucceed; }
		void SetAllowDrag(BOOL bAllowDrag) { m_bAllowDrag = bAllowDrag; }
		void SetExpand(BOOL bExpand) { mbExpand = bExpand; }
		BOOL GetExpand() { return mbExpand; }

		string getViewName(_HTREEITEM hItem);
		string getParentName(_HTREEITEM hItem);

		_HTREEITEM FindContainerItem(Container* pContainer);
		_HTREEITEM FindElementItem(Element* hElement, ITEM_DATA** ppItemData = NULL);
		_HTREEITEM FindSubElementItem(Element* pElement);

		void postSubElementVisibilityChanged(Element* pSubElem);
		void updateChildContainerItem(_HTREEITEM updateItem);// add by dj ���������ӽڵ�mapӳ�� 2017.6.8
		void RemoveContainerItem(Container* pContainer);
		void RemoveSubElementItem(Element* pElement);

	private:
		_HTREEITEM	CopyToDesc(_HTREEITEM hSrc, _HTREEITEM hDesc);

		BOOL	CopyAllChildItemToDesc(_HTREEITEM hSrc, _HTREEITEM hDesc);
		BOOL	CopyItemPropToDesc(_HTREEITEM hSrc, _HTREEITEM hDesc);
		BOOL	CopyChrnTODesc(_HTREEITEM hSrc, _HTREEITEM hDesc);
		BOOL	GetChrnList(Container *pContainer);
		BOOL	GetAllChrnList(Container *pContainer);
		BOOL	isChild(_HTREEITEM hItem, _HTREEITEM hParentItem);
		BOOL	isAllowMoveTo(_HTREEITEM hSrc, _HTREEITEM hDesc);

		//�������Ŀ¼��״̬�仯
		void    SendStrMsgToLayerAndElements(std::string strViewName, _HTREEITEM hSelectedItem);
		void    SendSelectMsgToSwitchView(std::string strViewName, _HTREEITEM hSelectedItem);

		//���ݵ�ǰ���ѡ�е����ڵ�ȷ���Ҽ��˵�...
		void	GenPopupMenu(QMenu* qMenu, FunctionItemGroup* pGroup);
		
	private slots:
		void	menuMsgFuntion();


	private:
		ContainerManager* mContainerManager2D; //�ϲ��Ժ����
		ElementManager *mElementManager2D;
		ContainerManager* mContainerManager3D;
		ElementManager *mElementManager3D;
		ContainerManager* mContainerManagerDB;
		ElementManager *mElementManagerDB;

		Container* mActiveContainer;// ���ػ����
		Element* mActiveElement;

		typedef std::map<Container*, _HTREEITEM>	ContainerToTreeItemMap;//_HTREEITEM
		typedef std::map<Element*, _HTREEITEM>	SubElementToTreeItemMap;
		ContainerToTreeItemMap				m_ContainerToTreeItemMap;
		SubElementToTreeItemMap				m_SubElementToTreeItemMap;

		_HTREEITEM					m_hRoot;//_HTREEITEM
		_HTREEITEM					m_hItemDragD;
		_HTREEITEM					m_hItemDragS;
		std::vector<ITEM_DATA>		m_ItemData;
		_CImageList			m_Images;
		_CImageList			*m_pImageList;
		_CImageList*		m_pDragImage; //�϶�ʱ��ʾ��ͼ���б�

		POINT				m_HoverPoint; //���λ��
		POINT				mCurRPoint;
		std::vector<ITEM_DATA>	m_TmpItemData;		//ֱ���ӽڵ�ָ�������
		std::vector<ITEM_DATA>	m_ChrnItemData;		//�����ӽڵ�ָ�������
		std::vector<DBINFO>		m_vDBInfo;

		UINT		m_TimerTicks; //��������Ķ�ʱ����������ʱ��
		UINT		m_nScrollTimerID; //��������Ķ�ʱ��
		UINT		m_nHoverTimerID; //������ж�ʱ��
		DWORD		m_dwDragStart; //������������һ�̵�ʱ��
		BOOL		m_bDragging; //��ʶ�Ƿ������϶�������
		BOOL		m_bAllowDrag;
		BOOL		mbDragSucceed;
		BOOL		mbContrinerExpand;
		BOOL		mbElementExpand;
		BOOL		mbExpand;
		BOOL		m_bChangeFatherSonRel; //�϶����Ƿ�ı丸�ӹ�ϵ
		BOOL		m_bChangeSameLevelOnly;		//�Ƿ�֧���϶������丸�ڵ�ͬ��
		BOOL		m_bChange;

		int		m_nRootImg;
		int		m_nFoldImg;
		int		m_nFoldSelImg;
		int		m_nNodeImg;
		int		m_nNodeSelImg;
		int		m_nVisibleImg;
		int		m_nNotVisibleImg;


		QMenu					m_qPopMenu;
		FunctionItemManager*	m_pCurLayer;
		_HTREEITEM				m_pCurSelItem;
	};
}