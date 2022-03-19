// OGObject.h: interface for the OGObject class.
#pragma once

#include "OGBasDef.h"


namespace Smart3dMap {

	class OG_FRAME_DLL OGObject
	{
	public:
		OGObject(const string& ObjGUID);
		OGObject();
		virtual ~OGObject();
		
		// ȡ��������
		virtual const string& getClassName(void) const;
		void setClassName(const string& strClassName);
		
		// ȡ��������(��GUID��ʾ) -> ������getClassName
		virtual const OGGUID& getGUID(void) const;
		void setGUID(const string& strClassName);

		// ȡ�ö�����
		const string& getHandle(void) const;
		void setHandle(const string& strHandle);

		// ȡ�ö�������==����
		const string& getName(void) const;
		void setName(const string& strHandle);
		
		// ȡ�ö�������
		const int& getIndex(void) const;
		void setIndex(const int& nIndex);

		// ȡ�ö�������
		virtual const string& getDescription(void) const;
		void setDescription(const string& strDesc);

		BOOL isKindOf(const string& strClassName);
		BOOL isA(const string& strClassName);		

		// ��ȡ�û�ֵ
		const DWORD getUserData(void);
		void setUserData(const DWORD dwData);

	protected:
		string	mClassName;	// ������, ���ڽ�����ʾ
		string	mDescription;// �������, �����ṩ������ܼ������
		string	mHandle; // ������
		int		mnIndex;
		DWORD	mUserData;	// �û�����
		typedef	std::map<string, long>		ClassSetMap;
		
		ClassSetMap		mClassSet;
	};


}
