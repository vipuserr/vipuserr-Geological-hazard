#ifndef _OG_BAS_DEF_H
#define _OG_BAS_DEF_H

#ifdef	OG_FRAME_EXPORT
#define	OG_FRAME_DLL	__declspec(dllexport)
#else
#define	OG_FRAME_DLL	__declspec(dllimport)
#endif 


#include "s3d_KerAuxDef.h"
#include "s3d_IteratorWrapper.h"
using namespace Smart3dMap;

#pragma warning (disable :4786)
#pragma warning (disable :4503)
#pragma warning (disable :4244)
#pragma warning (disable :4305)
#pragma warning (disable :4251)
#pragma warning (disable :4275)
#pragma warning( disable :4290)
#pragma warning( disable: 4661)
#pragma warning( disable: 4996)
#pragma warning( disable: 4103)
#pragma warning( disable: 4800)
#pragma warning( disable: 4700)
#pragma warning( disable: 4018)


#define OG_DECLEAR_AUTO_RELEASE_THIS() virtual void Release() {delete this;}


namespace Smart3dMap
{
	class OGObject;
	class OGDynLibManager;

	class FunctionItem;
	class FunctionItemGroup;
	class FunctionItemManager;

	class PluginLibManager;

	class PluginBase;
	class FunctionPluginBase;
	class PluginFuncManager;
	class SubFrame;
	class WindowMsgManager;
	class Element;

	class OGUserDefinedObject;
	class SceneManagerWrapper;
	class OG3DLayerManager;
	class LayerManagerFactory;
	class Container;
	class ElementFactory;
	class ElementManager;
	class ContainerFactory;
	class ContainerManager;

	class MessageListener;
	class MessageListenerManager;

	class RootContainer;
	class RootContainerFactory;
	class ContainerListener;
	class ContainerManagerEnumerator;

	struct ContainerManagerMetaData;
	class ContainerManagerFactory;
	class DefaultContainerManagerFactory;
	class DefaultContainerManager;

	class DataElement;
	class XMLDataFile;
	class XMLDataElement;
	class BinaryDataFile;


#define OG_USER_DEFINE_PLUGIN	"用户自定义插件"

#define OG_Container_ROOT		"根图层"
#define OG_Container_2D			"基础数据源"
#define OG_Container_3D			"三维模型"
#define OG_Element_2D			"二维元素"
#define OG_Element_3D			"三维元素"
#define OG_Model_3D             "三维模型"
#define OG_Database_Table       "数据库"



	// 应用程序状态定义
#define	OG_FRAME_STATE_DEFAULT					0x00000101	// 应用程序默认状态
#define	OG_FRAME_STATE_INVALID					0x00000000	// 无效应用程序状态
#define	OG_FRAME_STATE_3D_VIEW_ROTATE			0x00000102	// 视图旋转
#define	OG_FRAME_STATE_3D_VIEW_TRAN			0x00000103	// 视图平移
#define OG_FRAME_STATE_3D_VIEW_ZOOM			0x00000104	// 视图缩放
#define OG_FRAME_STATE_EDIT					0x00000105	// 视图处于某一编辑状态
#define OG_FRAME_STATE_INTERACT				0x00000106	// 视图处于某一交互状态(无编辑插件)
#define	OG_FRAME_STATE_USER					0x0000F000	// 用户开始定义


// 场景实体特征表示码 32 位
#define OG_REPRESENTATION_MASK_SPACE_CLOSE		0x00000001	// 实体是一个封闭空间
#define	OG_REPRESENTATION_MASK_CAST_SHADOW		0x00000002	// 实体带有阴影
#define OG_REPRESENTATION_MASK_PATH_FLY			0x00000004	// 实体是可以漫游的,带有路径数据
#define OG_REPRESENTATION_MASK_LARGE			0x00000008	// 实体是巨大的，如果设置了这个bit, 一般不参与Batch
#define OG_REPRESENTATION_MASK_3			0x00000010
#define OG_REPRESENTATION_MASK_4			0x00000020
#define OG_REPRESENTATION_MASK_5			0x00000040
#define OG_REPRESENTATION_MASK_6			0x00000080
#define OG_REPRESENTATION_MASK_7			0x00000010
#define OG_REPRESENTATION_MASK_8			0x00000010
#define OG_REPRESENTATION_MASK_UNDERGROUP	0x00000100

#define OG_DEFAULT_DATASET_ID 1


// 卸载无效插件
#define  OG_NOPOWER_PLUGIN  "{C77DBAF1-2672-4e37-BD0C-E0809206F345}"

	//添加引用计数
#define	OG_ADD_PLUGINNUM	"{F5E49CB4-92E0-4a88-81D8-D3E85B2DFB17}"

	const string STR_G2DLAYERMNG = "二维图层管理器";
	const string STR_G3DLAYERMNG = "三维图层管理器";
	const string STR_GDBLAYERMNG = "数据库图层管理器";

	const string STR_WND_MAP = "地图视图";
	const string STR_WND_HISTGRAM = "柱状图视图";
	const string STR_WND_SECT = "剖面图视图";
	const string STR_WND_CHART = "图件视图";
	const string STR_WND_ATT = "属性数据视图";
	const string STR_WND_3DMDL1 = "三维模型视图1";
	const string STR_WND_3DMDL2 = "三维模型视图2";

	const string STR_2D_TREE_VIEW = "二维数据树";
	const string STR_3D_TREE_VIEW = "三维数据树";


	// 应用状态信息
	typedef struct _OG_FRAME_STATE_INFO
	{
		struct _EDIT_FUNC_CALL_PARA
		{
			UINT		nID;       //功能项ID
			string		strFunc;
			WPARAM		wParam;
			LPARAM		lParam;
			_EDIT_FUNC_CALL_PARA()
			{
				wParam = 0;
				lParam = 0;
			}
		};
		FunctionPluginBase*		pFunctionPlugin; // 对应使用的编辑插件
		string					strDescription;	 // 说明信息
		_EDIT_FUNC_CALL_PARA	editCallPara;

	}OG_FRAME_STATE_INFO;


	typedef string OG_PLUGIN_HANDLE; // 插件句柄定义

	// 数据类型句柄
	typedef string DataTypeHandle;

	typedef std::vector<DataTypeHandle> DataTypeHandleList;
	typedef VectorIterator<DataTypeHandleList> DataTypeHandleIterator;


	// 编辑插件中的一个功能接口的外部描述
	typedef struct _EDIT_SUPPORT_ITEM
	{
		string strEditPluginName;		// 编辑插件名称
		string strFuncName;			// 功能接口名称
	}EditSupportItem;

	typedef std::vector<EditSupportItem> EditSupportItemList;
	typedef VectorIterator<EditSupportItemList> EditSupportItemIterator;

	// 编辑功能接口的类型
	enum EditFuncItemType
	{
		EFIT_NORMAL = 1,	// 普通的功能接口
		EFIT_FOR_EDIT_BACK = 2,	// 只是用来在后台编辑，通常不显示在界面上
										// 但当用户对某实体进行编辑接口选择时，由系统显示
	};

	// 编辑插件功能项信息	与功能项的名称相对应
	typedef struct _OG_EDIT_FUNC_ITEM_INFO
	{
		string						strDescription;				// 对应功能项的说明信息		
		VIEW_TYPE					viewSupportForUse;			// 所支持的视图类型	
		EditFuncItemType			type;						// 编辑功能接口的类型
		DataTypeHandleList			dataTypeSupportList;		// 支持的数据类型列表

		_OG_EDIT_FUNC_ITEM_INFO()
		{
			viewSupportForUse = VT_ALL;			// 默认支持所有类型
			type = EFIT_NORMAL;
		}
	}OG_EDIT_FUNC_ITEM_INFO;


	// 数据类型信息
	typedef struct _OG_DATA_TYPE_INFO
	{
		EditSupportItemList	editSupportList;			// 支持此数据类型的功能接口列表
	}OG_DATA_TYPE_INFO;


	// 容器的功能说明信息	
	struct ContainerFunction
	{
		string name;
		string desc;
		string res1;
		string res2;
	};

	//功能插件的dllStartPlugin()与dllStopPlugin()函数
#define COMMON_FUNC_PLUGIN(plugin_name)\
	using namespace Smart3dMap;\
	plugin_name* g_plugin= 0;\
	long WINAPI dllStartPlugin(void){\
		g_plugin = new plugin_name();\
		PluginFuncManager::getSingletonPtr()->addFunctionPlugin(g_plugin);\
		return 1;\
	}\
	long WINAPI dllStopPlugin(void) {\
		OG_DELETE(g_plugin);\
	return 1;\
	}\

//二维图层插件的图层与元素同时加载，dllStartPlugin()与dllStopPlugin()函数
#define COMMON_2D_LAYLER_ELEMENT_PLUGIN1(Layer_Name,Element_Name)\
	Layer_Name##Ftry* g_p2DVecLayerFactory = NULL;\
	Element_Name##Ftry* g_p2DVecElementFtry = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p2DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p2DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault2DLayerManager()->addFactory(g_p2DVecLayerFactory);\
		g_p2DVecElementFtry = new Element_Name##Ftry();\
		if(g_p2DVecElementFtry == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault2DElementManager()->addFactory(g_p2DVecElementFtry);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p2DVecLayerFactory);\
		OG_DELETE(g_p2DVecElementFtry);\
		return 1;}\
//数据库图层插件的图层与元素同时加载，dllStartPlugin()与dllStopPlugin()函数
#define COMMON_DB_LAYLER_ELEMENT_PLUGIN1(Layer_Name,Element_Name)\
	Layer_Name##Ftry* g_p2DVecLayerFactory = NULL;\
	Element_Name##Ftry* g_p2DVecElementFtry = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p2DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p2DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefaultDbLayerManager()->addFactory(g_p2DVecLayerFactory);\
		g_p2DVecElementFtry = new Element_Name##Ftry();\
		if(g_p2DVecElementFtry == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefaultDbElementManager()->addFactory(g_p2DVecElementFtry);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p2DVecLayerFactory);\
		OG_DELETE(g_p2DVecElementFtry);\
		return 1;}\
//三维图层插件的图层与元素加载函数，dllStartPlugin()与dllStopPlugin()函数
#define  COMMON_3D_LAYLER_ELEMENT_PLUGIN1(Layer_Name,Element_Name)\
	Layer_Name##Ftry* g_p3DVecLayerFactory = NULL;\
	Element_Name##Ftry* g_p3DVecElementFtry = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p3DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p3DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault3DLayerManager()->addFactory(g_p3DVecLayerFactory);\
		g_p3DVecElementFtry = new Element_Name##Ftry();\
		if(g_p3DVecElementFtry == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault3DElementManager()->addFactory(g_p3DVecElementFtry);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p3DVecLayerFactory);\
		OG_DELETE(g_p3DVecElementFtry);\
		return 1;}\



//二维图层插件的图层与元素同时加载，dllStartPlugin()与dllStopPlugin()函数
#define COMMON_2D_LAYLER_ELEMENT_PLUGIN2(Layer_Name,Element_Name1, Element_Name2)\
	Layer_Name##Ftry* g_p2DVecLayerFactory = NULL;\
	Element_Name1##Ftry* g_p2DVecElementFtry1 = NULL;\
	Element_Name2##Ftry* g_p2DVecElementFtry2 = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p2DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p2DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault2DLayerManager()->addFactory(g_p2DVecLayerFactory);\
		g_p2DVecElementFtry1 = new Element_Name1##Ftry();\
		if(g_p2DVecElementFtry1 == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault2DElementManager()->addFactory(g_p2DVecElementFtry1);\
		g_p2DVecElementFtry2 = new Element_Name2##Ftry();\
		if(g_p2DVecElementFtry2 == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault2DElementManager()->addFactory(g_p2DVecElementFtry2);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p2DVecLayerFactory);\
		OG_DELETE(g_p2DVecElementFtry1);\
		OG_DELETE(g_p2DVecElementFtry2);\
		return 1;}\
//数据库图层插件的图层与元素同时加载，dllStartPlugin()与dllStopPlugin()函数
#define COMMON_DB_LAYLER_ELEMENT_PLUGIN2(Layer_Name,Element_Name1, Element_Name2)\
	Layer_Name##Ftry* g_p2DVecLayerFactory = NULL;\
	Element_Name1##Ftry* g_p2DVecElementFtry1 = NULL;\
	Element_Name2##Ftry* g_p2DVecElementFtry2 = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p2DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p2DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefaultDbLayerManager()->addFactory(g_p2DVecLayerFactory);\
		g_p2DVecElementFtry1 = new Element_Name1##Ftry();\
		if(g_p2DVecElementFtry1 == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefaultDbElementManager()->addFactory(g_p2DVecElementFtry1);\
		g_p2DVecElementFtry2 = new Element_Name2##Ftry();\
		if(g_p2DVecElementFtry2 == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefaultDbElementManager()->addFactory(g_p2DVecElementFtry2);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p2DVecLayerFactory);\
		OG_DELETE(g_p2DVecElementFtry1);\
		OG_DELETE(g_p2DVecElementFtry2);\
		return 1;}\

//三维图层插件的图层与元素加载函数，dllStartPlugin()与dllStopPlugin()函数
#define  COMMON_3D_LAYLER_ELEMENT_PLUGIN2(Layer_Name,Element_Name1, Element_Name2)\
	Layer_Name##Ftry* g_p3DVecLayerFactory = NULL;\
	Element_Name1##Ftry* g_p3DVecElementFtry1 = NULL;\
	Element_Name2##Ftry* g_p3DVecElementFtry2 = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p3DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p3DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault3DLayerManager()->addFactory(g_p3DVecLayerFactory);\
		g_p3DVecElementFtry1 = new Element_Name1##Ftry();\
		if(g_p3DVecElementFtry1 == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault3DElementManager()->addFactory(g_p3DVecElementFtry1);\
		g_p3DVecElementFtry2 = new Element_Name2##Ftry();\
		if(g_p3DVecElementFtry2 == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault3DElementManager()->addFactory(g_p3DVecElementFtry2);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p3DVecLayerFactory);\
		OG_DELETE(g_p3DVecElementFtry1);\
		OG_DELETE(g_p3DVecElementFtry2);\
		return 1;}\



//二维图层插件的图层加载，dllStartPlugin()与dllStopPlugin()函数
#define  COMMON_2D_LAYLER_PLUGIN(Layer_Name)\
	Layer_Name##Ftry* g_p2DVecLayerFactory = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p2DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p2DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault2DLayerManager()->addFactory(g_p2DVecLayerFactory);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p2DVecLayerFactory);\
		return 1;}\
//数据库图层插件的图层加载，dllStartPlugin()与dllStopPlugin()函数
#define  COMMON_DB_LAYLER_PLUGIN(Layer_Name)\
	Layer_Name##Ftry* g_p2DVecLayerFactory = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p2DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p2DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefaultDbLayerManager()->addFactory(g_p2DVecLayerFactory);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p2DVecLayerFactory);\
		return 1;}\
//三维图层插件的图层加载函数，dllStartPlugin()与dllStopPlugin()函数
#define  COMMON_3D_LAYLER_PLUGIN(Layer_Name)\
	Layer_Name##Ftry* g_p3DVecLayerFactory = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p3DVecLayerFactory = new Layer_Name##Ftry();\
		if(g_p3DVecLayerFactory == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault3DLayerManager()->addFactory(g_p3DVecLayerFactory);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p3DVecLayerFactory);\
		return 1;}\



//二维图层插件的二维元素加载，dllStartPlugin()与dllStopPlugin()函数
#define  COMMON_2D_ELEMENT_PLUGIN(Element_Name)\
	Element_Name##Ftry* g_p2DVecElementFtry = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p2DVecElementFtry = new Element_Name##Ftry();\
		if(g_p2DVecElementFtry == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault2DElementManager()->addFactory(g_p2DVecElementFtry);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p2DVecElementFtry);\
	return 1;}\
//数据库图层插件的二维元素加载，dllStartPlugin()与dllStopPlugin()函数
#define  COMMON_DB_ELEMENT_PLUGIN(Element_Name)\
	Element_Name##Ftry* g_p2DVecElementFtry = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p2DVecElementFtry = new Element_Name##Ftry();\
		if(g_p2DVecElementFtry == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefaultDbElementManager()->addFactory(g_p2DVecElementFtry);\
		return 1;}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p2DVecElementFtry);\
	return 1;}\
//三维图层插件的元素加载函数，dllStartPlugin()与dllStopPlugin()函数
#define  COMMON_3D_ELEMENT_PLUGIN(Element_Name)\
	Element_Name##Ftry* g_p3DVecElementFtry = NULL;\
	long WINAPI dllStartPlugin(void){\
		g_p3DVecElementFtry = new Element_Name##Ftry();\
		if(g_p3DVecElementFtry == NULL) return 0;\
		OgFrameWork::getSingletonPtr()->getDefault3DElementManager()->addFactory(g_p3DVecElementFtry);\
		return 1;\
	}\
	long WINAPI dllStopPlugin(void){\
		OG_DELETE(g_p3DVecElementFtry);\
	return 1;}\




//图层和元素的工厂类(共一套函数)
#define COMMON_LAYLER_ELEMENT_FACTORY(Layer_Name,LayerID_Name,ElementID_Name,Layer_Caption,Element_Caption)\
	class Layer_Name##Ftry:public ContainerFactory{\
	public:\
	Layer_Name##Ftry(){\
		OGObject	*pObject = NULL;\
		mChildSupportFilter.setContainerSupportType(ContainerSupportFilter::LST_List);\
		mElementSupportFilter.setContainerSupportType(ContainerSupportFilter::LST_List);\
		mChildSupportFilter.create(LayerID_Name);\
		mElementSupportFilter.create(ElementID_Name);\
		pObject=mChildSupportFilter.get(LayerID_Name);\
		if(pObject){\
			pObject->setClassName(LayerID_Name);\
			pObject->setDescription(Layer_Caption);\
			pObject->setGUID(LayerID_Name);\
			pObject->setHandle(LayerID_Name);\
			pObject->setName(Layer_Caption);}\
			pObject	=	mElementSupportFilter.get(ElementID_Name);\
		if(pObject){\
			pObject->setClassName(ElementID_Name);\
			pObject->setDescription(Element_Caption);\
			pObject->setGUID(ElementID_Name);\
			pObject->setHandle(ElementID_Name);\
			pObject->setName(Element_Caption);}}\
	virtual ~Layer_Name##Ftry(){}\
	virtual const string& getType() const{\
		static OGGUID strGuid = LayerID_Name;\
		return strGuid;}\
	virtual Container* createInstance( const string& name){\
		Layer_Name* pDeriLayer = new Layer_Name(name,LayerID_Name);\
		return (Container *)pDeriLayer;}\
		virtual void destroyInstance( Container* pLayer){\
		Layer_Name	*pDeriLayer = NULL;\
		pDeriLayer	=	(Layer_Name *)pLayer;\
		OG_DELETE(pDeriLayer);}\
	virtual const ContainerFunction& getContainerFunction(void){\
		static ContainerFunction fLayerFunc;\
		fLayerFunc.name = Layer_Caption;\
		fLayerFunc.desc = Layer_Caption;\
		return fLayerFunc;}};\
//图层的工厂类.(共一套函数)
#define COMMON_LAYLER_FACTORY(Layer_Name, LayerID_Name, Layer_Caption)\
	class Layer_Name##Ftry:public ContainerFactory{\
	public:\
	Layer_Name##Ftry(){\
		OGObject	*pObject = NULL;\
		mChildSupportFilter.setContainerSupportType(ContainerSupportFilter::LST_List);\
		mElementSupportFilter.setContainerSupportType(ContainerSupportFilter::LST_All);\
		mChildSupportFilter.create(LayerID_Name);\
		pObject=mChildSupportFilter.get(LayerID_Name);\
		if(pObject){\
			pObject->setClassName(LayerID_Name);\
			pObject->setDescription(Layer_Caption);\
			pObject->setGUID(LayerID_Name);\
			pObject->setHandle(LayerID_Name);\
			pObject->setName(Layer_Caption);}}\
	virtual ~Layer_Name##Ftry(){}\
	virtual const string& getType() const{\
	static OGGUID strGuid = LayerID_Name;\
	return strGuid;}\
	virtual Container* createInstance( const string& name){\
		Layer_Name* pDeriLayer = new Layer_Name(name,LayerID_Name);\
		return (Container *)pDeriLayer;}\
	virtual void destroyInstance( Container* pLayer){\
		Layer_Name	*pDeriLayer = NULL;\
		pDeriLayer	=	(Layer_Name *)pLayer;\
		OG_DELETE(pDeriLayer);}\
	virtual const ContainerFunction& getContainerFunction(void){\
		static ContainerFunction fLayerFunc;\
		fLayerFunc.name = Layer_Caption;\
		fLayerFunc.desc = Layer_Caption;\
		return fLayerFunc;}};\


//二维元素工厂类
#define COMMON_2D_ELEMENT_FACTORY(Element_Name,ElementFtry_ID,Element_Caption)\
	class Element_Name##Ftry: public ElementFactory\
	{\
	public:\
		Element_Name##Ftry() {}\
		virtual ~Element_Name##Ftry() {}\
		virtual const string& getType() const\
		{\
			static OGGUID strGuid = ElementFtry_ID;\
			return strGuid;\
		};\
		virtual Element* createInstance( const string& name )\
		{\
			Element_Name* pDeriElement = new Element_Name(name, ElementFtry_ID);\
			pDeriElement->setGUID(ElementFtry_ID);\
			return (Element *)pDeriElement;\
		}\
		virtual void destroyInstance( Element* pElement )\
		{\
			Element_Name	*pDeriElement = NULL;\
			pDeriElement	=	(Element_Name *)pElement;\
			OG_DELETE(pDeriElement);\
		}\
		virtual const ContainerFunction& getContainerFunction(void)\
		{\
			static ContainerFunction fLayerFunc;\
			fLayerFunc.name = Element_Caption;\
			fLayerFunc.desc = Element_Caption;\
			return fLayerFunc;\
		}\
	};\

//DB图层插件的元素工厂
#define COMMON_DB_ELEMENT_FACTORY(Element_Name, ElementFtry_ID, Element_Caption)\
class Element_Name##Ftry : public OGDbElementFactory\
	{\
	public:\
		Element_Name##Ftry() {}\
		virtual ~Element_Name##Ftry() {}\
		virtual const string& getType() const\
		{\
			static OGGUID strGuid = ElementFtry_ID;\
			return strGuid;\
		};\
		virtual OGDbElement* createInstance( const string& name )\
		{\
			Element_Name* pDeriElement = new Element_Name(name);\
			pDeriElement->setGUID(ElementFtry_ID);\
			return (OGDbElement *)pDeriElement;\
		}\
		virtual void destroyInstance( OGDbElement* pElement )\
		{\
			Element_Name	*pDeriElement = NULL;\
			pDeriElement	=	(Element_Name *)pElement;\
			OG_DELETE(pDeriElement);\
		}\
		virtual const ContainerFunction& getContainerFunction(void)\
		{\
			static ContainerFunction fLayerFunc;\
			fLayerFunc.name = Element_Caption;\
			fLayerFunc.desc = Element_Caption;\
			return fLayerFunc;\
		}\
	};\
//三维图层插件的元素工厂
#define COMMON_3D_ELEMENT_FACTORY(Element_Name, ElementFtry_ID, Element_Caption)\
class Element_Name##Ftry : public OG3DElementFactory\
	{\
	public:\
		Element_Name##Ftry() {}\
		virtual ~Element_Name##Ftry() {}\
		virtual const string& getType() const\
		{\
			static OGGUID strGuid = ElementFtry_ID;\
			return strGuid;\
		};\
		virtual OG3DElement* createInstance( const string& name )\
		{\
			Element_Name* pDeriElement = new Element_Name(name);\
			pDeriElement->setGUID(ElementFtry_ID);\
			return (OG3DElement *)pDeriElement;\
		}\
		virtual void destroyInstance( OG3DElement* pElement )\
		{\
			Element_Name	*pDeriElement = NULL;\
			pDeriElement	=	(Element_Name *)pElement;\
			OG_DELETE(pDeriElement);\
		}\
		virtual const ContainerFunction& getContainerFunction(void)\
		{\
			static ContainerFunction fLayerFunc;\
			fLayerFunc.name = Element_Caption;\
			fLayerFunc.desc = Element_Caption;\
			return fLayerFunc;\
		}\
	};\










	typedef std::map<std::string, Smart3dMap::Element*> ElementList;

	// 全局函数	
	void OG_FRAME_DLL OGUpdateActiveView();
	//取出二维数据树当前打开的所有元素
	BOOL OG_FRAME_DLL OGGetOpenElementList(std::vector<Element*> &elemList);


}




#ifndef OG_FRAME_EXPORT 
#pragma comment(lib, "S3dFrameWorkEngine.lib")
#endif


#endif