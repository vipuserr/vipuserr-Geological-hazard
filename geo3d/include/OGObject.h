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
		
		// 取得类名称
		virtual const string& getClassName(void) const;
		void setClassName(const string& strClassName);
		
		// 取得类名称(用GUID表示) -> 调用了getClassName
		virtual const OGGUID& getGUID(void) const;
		void setGUID(const string& strClassName);

		// 取得对象句柄
		const string& getHandle(void) const;
		void setHandle(const string& strHandle);

		// 取得对象名称==名称
		const string& getName(void) const;
		void setName(const string& strHandle);
		
		// 取得对象的序号
		const int& getIndex(void) const;
		void setIndex(const int& nIndex);

		// 取得对象描述
		virtual const string& getDescription(void) const;
		void setDescription(const string& strDesc);

		BOOL isKindOf(const string& strClassName);
		BOOL isA(const string& strClassName);		

		// 存取用户值
		const DWORD getUserData(void);
		void setUserData(const DWORD dwData);

	protected:
		string	mClassName;	// 类名称, 用于界面显示
		string	mDescription;// 插件描述, 用于提供插件功能简短描述
		string	mHandle; // 对象句柄
		int		mnIndex;
		DWORD	mUserData;	// 用户数据
		typedef	std::map<string, long>		ClassSetMap;
		
		ClassSetMap		mClassSet;
	};


}
