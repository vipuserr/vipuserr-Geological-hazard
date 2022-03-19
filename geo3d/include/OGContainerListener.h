 // OGContainerListener.h: interface for the ContainerListener class.
//
//////////////////////////////////////////////////////////////////////
#pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000





namespace Smart3dMap {
	
	// �����¼�
	struct ContainerEvent
	{
		Container* source; // ��ϢԴ
		UINT nMsg;     // �Զ�����Ϣ
		bool cascade;  // �Ƿ����

		ContainerEvent()
		{
			source = 0;
			nMsg = 0;
			cascade = true;
		}
	};

	// ����Ԫ���¼�
	struct ElementEvent
	{
		Element* source; // ��ϢԴ
		UINT nMsg;            // �Զ�����Ϣ

		ElementEvent()
		{
			source = 0;
			nMsg = 0;
		};
	};
	
	// �������
	class OG_FRAME_DLL ContainerListener  
	{
	public:
		ContainerListener() { mEnabled = true; }
		virtual ~ContainerListener() { }
		
		// ����
		virtual bool preAddContainer(Container* container) { return true; };
		virtual void postAddContainer(Container* container) { };

		virtual bool preRemoveContainer(Container* container) { return true; };
		virtual void postRemoveContainer(Container* container) { };

		virtual bool preDestroyContainer(Container* container) { return true; };
		virtual void postDestroyContainer(Container* container) { };

		virtual bool preRemoveAndDestroyAllChildren(Container* container) { return true; };
		virtual void postRemoveAndDestroyAllChildren(Container* container) { };
				
		virtual void postContainerVisibilityChanged(Container* container, bool cascade = true) { };		
		virtual void postContainerSelectChanged(Container* container, bool cascade = true) { };
		virtual void postContainerFreezeChanged(Container* container, bool cascade = true) { };
		virtual void postContainerLockChanged(Container* container, bool cascade = true) { };
		virtual void postContainerNameChanged(Container* container) { };
		virtual void postContainerClicked(Container* container) { };

		// ����������
		virtual void preActiveContainerChanged(Container* container) { };
		virtual void postActiveContainerChanged(Container* container) { };
		//  [3/10/2015 Feng]
		virtual void postActiveElementChanged(Element* element) { };

		
		// ����Ԫ�ص����ɾ��
		virtual bool preAttachObject(Element* element) { return true; };
		virtual void postAttachObject(Element* element) { };

		virtual bool preDetachObject(Element* element) { return true; };
		virtual void postDetachObject(Element* element) { };

		virtual bool preDetachAllObjects(Container* container) { return true; };
		virtual void postDetachAllObjects(Container* container) { };

		virtual void postElementVisibilityChanged(Element* element) { };
		virtual void postElementSelectChanged(Element* element) { };
		virtual void postElementFreezeChanged(Element* element) { };
		virtual void postElementLockChanged(Element* element) { };		
		virtual void postElementNameChanged(Element* element) { };
		virtual void postElementEditChanged(Element* element) { };
		virtual void postElementClicked(Element* element) { };

		virtual bool onNotifyContainerMsg(const ContainerEvent& element) { return true; };
		virtual bool onNotifyElementMsg(const ElementEvent& element) { return true; };		

		// �����Ƿ�,ֻ�лʱ�Ž����ڲ���Ϣ
		void setEnabled(bool enabled) { mEnabled = enabled; }
		bool getEnabled(void) { return mEnabled; };




		//���������ı�
		virtual  bool preContainerScaleChanged(Container* container) { return true;};
		virtual  void postContainerScaleChanged(Container* container) { };
		virtual  bool preElementScaleChanged(Element* element) { return true;};
		virtual  void postElementScaleChanged(Element* element) { };

		//���ݲ�չ��������
		virtual  bool preContainerExpanded(Container* container, bool bIsExpand) { return true;};
		virtual  void postContainerExpanded(Container* container, bool bIsExpand) { };

		//ģ����ʾģʽ�����ı�
		virtual  bool preContainerSceneDetailLevelChanged(Container* container, Smart3dMap::PolygonMode detail) { return true;};
		virtual  void postContainerSceneDetailLevelChanged(Container* container, Smart3dMap::PolygonMode detail) { };
		virtual  bool preElementSceneDetailLevelChanged(Element* element, Smart3dMap::PolygonMode detail) { return true;};
		virtual  void postElementSceneDetailLevelChanged(Element* element, Smart3dMap::PolygonMode detail) { };

		//��ʾ�����������ݲ�
		virtual  bool preContainerDispAll(Container* container, bool bDispAll) { return true;};
		virtual  void postContainerDispAll(Container* container, bool bDispAll) { };
		
		//  [3/5/2015 Feng]
		virtual bool AddElementChild(Element* pParentElem,Element* pSubElem){return true;}
		//  [4/12/2015 Feng]
		virtual bool ExpandContainerChild(Container* container, bool bExpand){return true;}

		virtual void ChangeContainerICon(Container* pContainer, int preIcon,int postIcon){}
		virtual void ChangeElementICon(Element* pElement, int preIcon,int postIcon){}

	public:
		bool mEnabled;
	};
}

