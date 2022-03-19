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
	// Ԫ�������ַ���
	const string STR_ELEMENT_DELETE				= "ɾ������";
	const string STR_ELEMENT_PROPERTY			= "��ʾ��������";
	const string STR_ELEMENT_CHANGE_NAME		= "������";

	const string STR_ELEMENT_SET_ACTIVE			= "��Ϊ�";
	const string STR_ELEMENT_SET_EDIT			= "��Ϊ�༭";

//
	static string ELEMENT_GUID = "{579FC6DD-B46D-42e9-9879-CCB7139119FA}";

    // Ԫ�ػ���
	class OG_FRAME_DLL Element :public FunctionItemManager, public OGObject
	{
		friend class ElementManager;
	protected:
		Element(const string& name);
		Element(const string& name,const string& guid);
		virtual ~Element();
	public:
		// ȡ����ʾ����
	    virtual const string& getDisplayName(void) const;
	    virtual void setDisplayName(const string& dispName);

		// ��DataElement����
		virtual bool load(DataElement* element);
		// ���浽DataElement
		virtual bool save(DataElement* element);

		// ȡ��������
		virtual Container* getParentContainer(void) const;

		// �ڲ�����
		virtual void _notifyAttached(Container* parent);

		// �Ƿ���������
		virtual bool isAttached(void) const;
		
		// �贴����
		virtual void setCreator(void* creator);

		// ������
		virtual void* getCreator(void) const;
		
		// ������������û���setVisible
		virtual void setVisible(bool visible);
		virtual bool isVisible(void) const;	

		// ѡ��
		virtual void select(bool select = true);
		virtual bool isSelected(void) const;

		// ����
		virtual void freeze(bool freeze);
		virtual bool isFrozen(void) const;
		// ����	
		virtual void lock(bool lock);
		virtual bool isLocked(void) const;
		virtual void Edit(bool bEdit);
		virtual bool isEdit(void) const;

		// ����ӳ�� - �̳�FunctionItemManager
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		
		// ˫��
		virtual void onDbClick(void) { };
		// ���ԶԻ���
		virtual void onPropertyDialog(void) { };
		
		virtual void setScale(Real x,Real y,Real z);
		virtual void setPosition(Real x,Real y,Real z);

		// ����
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
	    // ��ʼ������øú���
		virtual void onCreate(void);

		int mIConBMPNo;
		bool mHasData;
		std::string m_CanvasName;
	private:
		void* mElementMgr;
		ContainerManager* mContainerMgr;// ������
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


