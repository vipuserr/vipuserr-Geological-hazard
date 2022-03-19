#pragma once

#include "OGBasDef.h"


//#pragma execution_character_set("utf-8")

namespace Smart3dMap
{
	#define ID_WORKSPACE_BAR_2D		(10001)
	#define ID_VIEW_2D				(20000)
	#define ID_VIEW_3D				(ID_VIEW_2D+1)


	//节点标签
	const std::string STR_RESOURCE_RES_TAG = "Resource";
	const std::string STR_MENU_RES_TAG = "MenuBar";
	const std::string STR_TOOLBAR_RES_TAG = "Toolbar";
	const std::string STR_VIEW_RES_TAG = "VIEW";
	const std::string STR_STATUSBAR_RES_TAG = "StatusBar";
	const std::string STR_SYSTEMABOUT_RES_TAG = "SystemAbout";
	const std::string STR_PRELOAD_RES_TAG = "PreLoad";
	const std::string STR_ITEM_NAME_TAG = "Item";


	//节点属性
	//编码
	const std::string STR_RES_CODE_ATTR = "ResCode";
	//系统
	const std::string STR_SYSTEM_NAME_ATTR = "SystemName";
	const std::string STR_SYSTEM_PATH_ATTR = "SystemPath";
	const std::string STR_SYSTEM_ICON_FILE_ATTR = "SystemIconFile";
	const std::string STR_SYSTEM_SLASH_IMAGE_FILE_ATTR = "SystemSlashImageFile";
	const std::string STR_SYSTEM_DESCRIPTION_ATTR = "SystemDescription";
	const std::string STR_GME_DATABASE_PATH_ATTR = "GmeDataBasePath";
	const std::string STR_ACCESS_DATABASE_PATH_ATTR = "AccessDataBasePath";
	const std::string STR_TOOL_LIN_WIDTH = "ToolLinWidth";//Tool的几个参数
	const std::string STR_TOOL_LIN_CLR = "ToolLinClr";
	const std::string STR_TOOL_REG_CLR = "ToolRegClr";
	const std::string STR_TOOL_PNT_RADIUS = "ToolPntRadius";
	const std::string STR_TOOL_LIN_RADIUS = "ToolLinRadius";

	//名称
	const std::string STR_RES_NAME_ATTR = "ResName";
	const std::string STR_VIEW_NAME_ATTR = "ViewName";
	const std::string STR_PLUG_NAME_ATTR = "PlugName";
	const std::string STR_FUNC_NAME_ATTR = "FuncName";
	const std::string STR_WINDOW_TITLE_NAME_ATTR = "WindowTitleName";
	const std::string STR_BMPFILE_NAME_ATTR = "BmpFileName";
	const std::string STR_RESPATH_NAME_ATTR = "ResPathName";
	const std::string STR_BTNIMGPATH_NAME_ATTR = "BtnImgPathName";
	const std::string STR_SHORT_CUT_NAME_ATTR = "ShortCutName";
	//类型
	const std::string STR_TYPE_ATTR = "Type";
	const std::string STR_VIEW_TYPE_ATTR = "ViewType";
	const std::string STR_PLUGIN_TYPE_ATTR = "PluginType";
	const std::string STR_CONTROL_TYPE_ATTR = "ControlType";
	const std::string STR_IMAGE_FILE_TYPE_ATTR = "ImageFileType";
	//文件
	const std::string STR_IMAGE_FILE_ATTR = "ImageFile";
	const std::string STR_PLUGIN_FILE_ATTR = "PluginFile";
	const std::string STR_ABOUT_IMAGE_FILE_ATTR = "AboutImageFile";
	const std::string STR_DATA_TREE_XML_FILE_ATTR = "DataTreeXmlFile";
	const std::string STR_TREE_NODE_IMAGE_FILE_ATTR = "TreeNodeImageFile";
	//参数
	const std::string STR_PARA_NAME_ATTR1 = "Parameter1";
	const std::string STR_PARA_NAME_ATTR2 = "Parameter2";
	const std::string STR_PARA_NAME_ATTR3 = "Parameter3";
	//路径
	const std::string STR_DATA_TREE_PATH_ATTR = "DataTreePath";
	const std::string STR_IMAGE_PATH_ATTR = "ImagePath";
	const std::string STR_TEMP_PATH_ATTR = "TempPath";
	const std::string STR_SYMBOL_PATH_ATTR = "SymbolPath";
	//其它
	const std::string STR_MODE_ATTR = "Mode";
	const std::string STR_BIND_VIEW_ATTR = "BindView";
	const std::string STR_HOTKEY_ATTR = "HotKey";
	const std::string STR_DOCK_POS_ATTR = "DockPos";
	const std::string STR_AUTHOR_ATTR = "Author";
	const std::string STR_VERSION_NO_ATTR = "VersionNo";
	const std::string STR_DEFAULT_VALUE_ATTR = "DefaultValue";


	//节点属性值
	const std::string STR_RESPATH_NAME_ATTR_VAL = "Pro_Res/";
	const std::string STR_BTNIMGPATH_NAME_ATTR_VAL = "Image/";
	const std::string STR_SEPARATOR_NAME_ATTR_VAL = "-------";
	const std::string STR_LEFT_VIEW_TYPE_ATTR_VAL = "LeftView";
	const std::string STR_RIGHT_VIEW_TYPE_ATTR_VAL = "RightView";
	const std::string STR_BOTTOM_VIEW_TYPE_ATTR_VAL = "BottomView";
	const std::string STR_CENTER_VIEW_TYPE_ATTR_VAL = "CenterView";


	#define MSG_DISP_RESNODE_INFO  (WM_USER+100) //显示资源节点的信息
	#define MSG_UPDATE_RESBMP_INFO  (WM_USER+101) //显示资源节点的图标文件信息

}