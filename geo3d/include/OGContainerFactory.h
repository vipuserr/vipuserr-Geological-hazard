 // OGContainerFactory.h: interface for the OGContainerFactory class.
//
//////////////////////////////////////////////////////////////////////

#pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGContainer.h"
#include "OgFactoryObj.h"
#include "OGManagerWrappers.h"

namespace Smart3dMap {

	class OG_FRAME_DLL ContainerSupportFilter : public PtrMapManager<OGGUID, OGObject>
	{
	public:
		enum ContainerSupportType
		{
			LST_None = 0,			// ���ж���֧��
			LST_List = 1,			// ֧���б�
			LST_All = 2,			// ֧������
			LST_FORCE_DWORD = 0x7fffFFFF,
		};
	public:
		ContainerSupportFilter();
		~ContainerSupportFilter();
		
		void setContainerSupportType(ContainerSupportType type);
		ContainerSupportType getContainerSupportType(void);

		/*
		�ж��Ƿ�֧��ĳ������
		���mType == LST_None ����false
            mType == LST_All  ����true
			mType == LST_List ���List�д���, �򷵻�true, ���򷵻�false
		*/
		bool isSupport(const OGGUID& guid);	
	protected:		
		ContainerSupportType mType;		
	};

	// ���ɲ��������๤������
	class OG_FRAME_DLL ContainerFactory : public FactoryObj<Container>	
	{
	public:
		ContainerFactory();
		virtual ~ContainerFactory();

		// ˵����Ϣ	
		virtual const ContainerFunction& getContainerFunction(void) { 
			return mContainerFunction; };

		// ����������֧����Ϣ
		virtual const ContainerSupportFilter* getContainerChildSupportFilter(void) { 
			return &mChildSupportFilter; }

		// ����Ԫ������֧����Ϣ
		virtual const ContainerSupportFilter* getElementSupportFilter(void) { 
			return &mElementSupportFilter; }

		// �ж������������Ƿ�֧��
		bool isSupportContainerChildType(const OGGUID& guid) {
			return mChildSupportFilter.isSupport(guid);
		}

		// �ж�����Ԫ�������Ƿ�֧��
		bool isSupportElementType(const OGGUID& guid) {
			return mElementSupportFilter.isSupport(guid);
		}

		// �Զ������
//		virtual void setUserObject(UserDefinedObject* obj) { mUserObject = obj; }
//        virtual UserDefinedObject* getUserObject(void) { return mUserObject; }

	protected:
		ContainerFunction mContainerFunction;
		ContainerSupportFilter mChildSupportFilter;
		ContainerSupportFilter mElementSupportFilter;
//		UserDefinedObject* mUserObject;
	};
}
