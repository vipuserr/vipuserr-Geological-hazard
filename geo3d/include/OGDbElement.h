#pragma once

#include "OGUserDefinedObject.h"
#include "OGElement.h"
#include "OgFactoryObj.h"
#include "OGMessageListener.h"



namespace Smart3dMap{
	class OGDbElementManager;

    class OG_FRAME_DLL OGDbElement : public Element, public Smart3dMap::COGListener
	{
	public:	
		OGDbElement(const string& name);
		virtual ~OGDbElement();

	public:
		virtual void registerFunctions(void);
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void setVisible(bool visible);

		//加载/保存元素
		virtual bool load(DataElement* element);
		virtual bool save(DataElement* element);

		//关联数据
		virtual long DispElement(long mdc);
		virtual long ReltElement();
		virtual long DelRelt();

	public:
		// 取出数据
		virtual long FetchData();
	};
	
		class OG_FRAME_DLL OGDbElementFactory : public FactoryObj<OGDbElement>
	{
	};
}