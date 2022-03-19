  #pragma once
#include "OGBasDef.h"


namespace Smart3dMap {

	//以下消息定义由Smart3dMap框架向事件对象发送时用到
	//Event对象由应用程序负责生成

	#define OG_MSG_DATABASE_UPDATE				0xEE00E000			// 数据库进行了更新
	#define OG_MSG_DATABASE_CHANGE_USER		0xEE00E001			// 数据库用户更改	

	#define OG_MSG_LAYER_ADD					0xEE00E100			// 添加层时, lParam中包含了指向COGLayer*类型指针
	#define OG_MSG_LAYER_DIALOG_ADD			0xEE00E101			// 对话框添加层	
		
	#define OG_MSG_LAYER_DIALOG_ADD_CHILD		0xEE00E102			// 对话框添加子图层	
	#define OG_MSG_LAYER_ADD_CHILD				0xEE00E103			// 添加子图层
	#define OG_MSG_LAYER_REMOVE_CHILD		    0xEE00E104			// 删除子图层

    #define OG_MSG_LAYER_DELETE				0xEE00E105			// 删除一个层
	#define OG_MSG_LAYER_UPDATE				0xEE00E106			// 层更新
	#define OG_MSG_LAYER_ORDER_CHANGED			0xEE00E107			// 层在管理器中的排列顺序发生改变
    #define OG_MSG_LAYER_DBCLICK               0xEE00E108			// 层双击
	#define OG_MSG_LAYER_ELEMENT_DBCLICK       0xEE00E109			// 层元素双击
	#define OG_MSG_LAYER_EMPTY					0xEE00E110			// 清空层元素	
	#define OG_MSG_LAYER_RENAME				0xEE00E111			// 层重新命名
	#define OG_MSG_LAYER_ACTIVATE				0xEE00E112			// 切换激活图层
	#define OG_MSG_LAYER_DEACTIVATE			0xEE00E113			// 切换激活图层
    #define OG_MSG_LAYER_ACTIVITY_CHANGED		0xEE00E114			// 激活可见
	#define OG_MSG_LAYER_VISABLE				0xEE00E115			// 激活图层
	#define OG_MSG_LAYER_INVISIBLE				0xEE00E116			// 激活可见
	#define OG_MSG_LAYER_VISIBILITY_CHANGED	0xEE00E117			// 激活可见	
	#define OG_MSG_LAYER_ELEMENT_VISIBILITY_CHANGED	0xEE00E118	// 层元素改变
	
    #define OG_MSG_LAYER_PROPERTY				0xEE00E119			// 层元素
	#define OG_MSG_LAYER_ELEMENT_PROPERTY		0xEE00E120			// 层元素
	
	
	#define OG_MSG_ENTITY_ADD					0xEE00F000
	#define OG_MSG_ENTITY_DELETE				0xEE00F001
	#define OG_MSG_ENTITY_UPDATE				0xEE00F002
	#define	OG_MSG_ENTITY_VIEW_PROP_DICTIONARY 0xEE00F003			// 查看实体的几何参数字典. lParam  指向C3DEntity的指针
	#define OG_MSG_FEATURE_ADD					0xEE00F100
	#define OG_MSG_FEATURE_UPDATE				0xEE00F101
	#define OG_MSG_FEATURE_DELETE				0xEE00F102
	#define OG_MSG_FEATURE_CLASS_ADD			0xEE00F200
	#define OG_MSG_FEATURE_CLASS_UPDATE		0xEE00F201
	#define OG_MSG_FEATURE_CLASS_DELETE		0xEE00F202
	#define	OG_MSG_FEATURE_VIEW_PROP_DICTIONARY 0xEE00F203			// 查看要素的属性信息（参数字典）. lParam  指向FEATUREID的指针
	
    #define	OG_MSG_VIEW_PROP_DICTIONARY        0xEE00F204			// 查看属性信息（参数字典）. lParam是指向PRAMADIC的指针
	#define	OG_MSG_EMPTY_PROP_DICTIONARY       0xEE00F205			// 清空参数字典
    #define OG_MSG_VIEW_MODIFY_PROP_DICTIONARY	0xEE00F206			// 清空参数字典

	#define OG_MSG_SUBFRAME_ADD				0xEE00F300			// 增加一个新的视图应用框架 lParam  指向CSubFrame的指针
	#define OG_MSG_SUBFRAME_STATE_ADD			0xEE00F400			// 增加一个新的视图应用状态 wParam  状态的 DWORD 值, lParam  指向CSubFrame的指针

	#define OG_MSG_SOLUTION_ADD				0xEE00F500			// 创建新的解决方案, lParam 指向ProjectConfigFileHeader*类型的指针

	#define OG_MSG_TERRAIN_ACTIVE				0xEE00F600			// 设置地形为当前地形 , lParam 指向CTerrainPluginBase*类型的指针

	#define OG_MSG_LOCAL_ENTITY_ADD			0xEE00F700
	#define OG_MSG_LOCAL_ENTITY_DELETE			0xEE00F701
	#define OG_MSG_LOCAL_ENTITY_UPDATE			0xEE00F702
	#define OG_MSG_LOCAL_CONTAINER_ADD			0xEE00F703
	#define OG_MSG_LOCAL_CONTAINER_DELETE		0xEE00F704
	#define OG_MSG_LOCAL_CONTAINER_UPDATE		0xEE00F705
	#define OG_MSG_LOCAL_3DLOCATE				0xEE00F706	//三维交互定位
	#define OG_MSG_LOCAL_3DLOC_DISP_COORDSTR	0xEE00F707	//显示交互定位参数
	#define OG_MSG_TELL_WORKSPACCE_ACTIVE_VIEW	0xEE00F708 //激活视图
	#define OG_MSG_GET_PRO_USERTABLE_CHINESE	0xEE00F709 //激活视图




	//containerMsg
				// 定义容器消息
		#define OG_MSG_CONTAINER_CREATE				0x0000E100	// 添加层时, lParam中包含了指向Container*类型指针
		#define OG_MSG_CONTAINER_ADD					0x0000E101	// 添加层时, lParam中包含了指向Container*类型指针
		#define OG_MSG_CONTAINER_REMOVE				0x0000E102	// 删除一个层
		#define OG_MSG_CONTAINER_DESTROY				0x0000E103	// 删除一个层
		#define OG_MSG_CONTAINER_EMPTY					0x0000E104	// 清空层元素	
		#define OG_MSG_CONTAINER_NAME_CHANGED			0x0000E105	// 层重新命名
		#define OG_MSG_CONTAINER_REM_DEST_ALL_CHILDREN	0x0000E106	// 删除子容器
			
		#define OG_MSG_CONTAINER_UPDATE				0x0000E107	// 层更新
		#define OG_MSG_CONTAINER_DBCLICK				0x0000E109	// 层双击
		#define OG_MSG_ELEMENT_DBCLICK		0x0000E110	// 层元素双击
			
		#define OG_MSG_CONTAINER_SELECT_CHANGED		0x0000E111	// 容器激活可见改变
		#define OG_MSG_CONTAINER_VISIBILITY_CHANGED	0x0000E112	// 容器可见改变
		#define OG_MSG_ELEMENT_VISIBILITY_CHANGED 0x0000E113	// 层元素改变
		#define OG_MSG_ACTIVE_CONTAINER_CHANGED		0x0000E114 // 当前容器变化
			
		#define OG_MSG_CONTAINER_FREEZE_CHANGED		0x0000E115 // 容器freeze变化
		#define OG_MSG_ELEMENT_FREEZE_CHANGED 0x0000E116 // 容器元素freeze变化
			
		#define OG_MSG_CONTAINER_LOCK_CHANGED			0x0000E117 // 容器lock变化
		#define OG_MSG_ELEMENT_LOCK_CHANGED	0x0000E118 // 容器lock变化
			
		#define OG_MSG_ELEMENT_NAME_CHANGED	0x0000E119	// 层元素重新命名
			
		#define OG_MSG_CONTAINER_ATTACH_OBJECT			0x0000E130	// 层元素改变
		#define OG_MSG_CONTAINER_DETACH_OBJECT			0x0000E131	// 层元素改变
		#define OG_MSG_CONTAINER_DETACH_ALL_OBJECTS	0x0000E132	// 层元素改变
		#define OG_MSG_CONTAINER_ORDER_CHANGED			0x0000E133	// 层在管理器中的排列顺序发生改变
		#define OG_MSG_ELEMENT_SELECT_CHANGED 0x0000E134 // 层元素改变
			
			
		#define OG_MSG_CONTAINER_SCALE_CHANGED 0x0000E135 // 层比例发生改变
		#define OG_MSG_ELEMENT_SCALE_CHANGED	0x0000E136 // 元素比例发生改变

		#define OG_MSG_CONTAINER_SPANDED 0x0000E137 // 层展开或隐藏

		#define OG_MSG_CONTAINER_SCENE_DETAIL_LEVEL_CHANGED 0x0000E138 // 层显示模式改变
		#define OG_MSG_ELEMENT_SCENE_DETAIL_LEVEL_CHANGED 0x0000E139   // 元素显示模式改变

		#define OG_MSG_CONTAINER_DISL_ALL 0x0000E140   // 显示或隐藏所有数据层


		//该消息实现二维图层创建结点时通知数据中心同步创建工作空间下结点使用
		//2008-12-02 
		#define	OG_MSG_CREATE_DATACENTER_NODE 0x0000E141			//创建工作空间结点	

		#define	OG_MSG_SET_DATACENTER_NODE_ALIASNAME 0x0000E142	//设置工作空间结点的别名		

		#define	OG_MSG_CHECK_DATACENTER_NODE_VALID 0x0000E143	//检查节点创建是否合法
		//  [3/5/2015 Feng]
		#define	OG_MSG_ADD_ELEMENT_CHILD 0x0000E144	//创建子节点
		#define OG_MSG_ACTIVE_ElEMENT_CHANGED 0x0000E145 // 设置活动的子元素发生变化
		#define OG_MSG_EXPAND_CONTAINER_CHANGED 0x0000E146 // 展开树节点
		#define OG_MSG_CHANGE_LAYER_ICON_HANDLE	0x0000E147 //改变图层图标, wParam 指向Container*类型的指针，lParam为int类型，表示ICON的标号，传入需要改变的值，传出当前值
		#define OG_MSG_CHANGE_ELEMENT_ICON_HANDLE	0x0000E148 //改变元素图标, wParam 指向Element*类型的指针，lParam为int类型，表示ICON的标号，传入需要改变的值，传出当前值
		#define OG_MSG_ELEMENT_EDIT_CHANGED 0x0000E149  // 层元素编辑状态改变
	
 
	#define WM_GET_OPENEND_LAYERLIST	(WM_USER+0x9007)	//
//TwoDimenView Message
	const string STR_2DVIEW_RBUTTDOUBLECLICK_PRO = "二维视图消息右键双击处理";
	const string STR_2DVIEW_RBUTTDOWN_PRO = "二维视图消息右键按下处理";
	const string STR_2DVIEW_RBUTT_PRO = "二维视图消息右键处理";

	const string STR_2DVIEW_LBUTTDOWN_PRO = "二维视图消息左键按下处理";
	const string STR_2DVIEW_LBUTTUP_PRO = "二维视图消息左键弹起处理";
	const string STR_2DVIEW_LBUTTSOUBLECLICK_PRO = "二维视图消息左键双击处理";
	const string STR_2DVIEW_ONPAINT_PRO = "二维视图消息重绘处理";

	const string STR_2DVIEW_ONMOUSEMOVE_PRO = "二维视图消息鼠标移动处理";
	const string STR_2DVIEW_ONMOUSEWHEEL_PRO = "二维视图消息鼠标中键处理";

	const string STR_HISVIEW_RBUTTDOUBLECLICK_PRO = "二维柱状视图消息右键双击处理";
	const string STR_HISVIEW_RBUTTDOWN_PRO = "二维柱状视图消息右键按下处理";
	const string STR_HISVIEW_RBUTT_PRO = "二维柱状视图消息右键处理";

	const string STR_HISVIEW_LBUTTDOWN_PRO = "二维柱状视图消息左键按下处理";
	const string STR_HISVIEW_LBUTTUP_PRO = "二维柱状视图消息左键弹起处理";
	const string STR_HISVIEW_LBUTTSOUBLECLICK_PRO = "二维柱状视图消息左键双击处理";
	const string STR_HISVIEW_ONPAINT_PRO = "二维柱状视图消息重绘处理";

	const string STR_HISVIEW_ONMOUSEMOVE_PRO = "二维柱状视图消息鼠标移动处理";
	const string STR_HISVIEW_ONMOUSEWHEEL_PRO = "二维柱状视图消息鼠标中键处理";

	const string G2DVIEW_MAPGIS2DREALVIEWGET  ="二维视图消息获取处理";
	const string G2DVIEW_MAPGIS2DREGET  ="二维渲染视图消息获取处理";
	const string G2DVIEW_GET2DGISVIEWBASE  ="获取2DGISBaseView";
	const string G2DVIEW_GETCURRENT2DTOOL  ="获取是否存在Tool";
	const string G2DVIEW_STOPCURRENT2DTOOL  ="设置停止当前Tool的操作";

	const string G2DHISVIEW_MAPGIS2DREALVIEWGET  ="二维柱状视图消息获取处理";
	const string G2DHISVIEW_MAPGIS2DREGET  ="二维柱状渲染视图消息获取处理";
	const string G2DHISVIEW_GET2DGISVIEWBASE  ="获取柱状2DGISBaseView";
	const string G2DHISVIEW_GETCURRENT2DTOOL  ="获取柱状是否存在Tool";
	const string G2DHISVIEW_STOPCURRENT2DTOOL  ="设置柱状停止当前Tool的操作";

//DatabaseView Message
	const string STR_DBVIEW_RBUTTDOUBLECLICK_PRO = "数据视图消息右键双击处理";
	const string STR_DBVIEW_RBUTTDOWN_PRO = "数据视图消息右键按下处理";
	const string STR_DBVIEW_RBUTTUP_PRO = "数据视图消息右键抬起处理";

	const string STR_DBVIEW_LBUTTDOWN_PRO = "数据视图消息左键按下处理";
	const string STR_DBVIEW_LBUTTUP_PRO = "数据视图消息左键弹起处理";
	const string STR_DBVIEW_LBUTTSOUBLECLICK_PRO = "数据视图消息左键双击处理";
	const string STR_DBVIEW_ONPAINT_PRO = "数据视图消息重绘处理";

	const string STR_DBVIEW_ONMOUSEMOVE_PRO = "数据视图消息鼠标移动处理";
	const string STR_DBVIEW_ONMOUSEWHEEL_PRO = "数据视图消息鼠标中键处理";
	const string GDBVIEW_GETDBVIEWBASE = "获取数据库视图";

//ThreeDimensionView Message
	const string G3DVIEW_GETTHREECONTAINERVIEW  ="获取三维切分父窗口";
	const string G3DVIEW_GET3DGISGEOVIEW        ="获取3DOGGeo3DView";
	const string G3DVIEW_GETPROJECTGISGEOVIEW   ="获取水平投影View";
	const string G3DVIEW_GETPLATFORMGISGEOVIEW  ="获取垂直投影View";
	const string G3DVIEW_3D_OPEN_T3DFILE        = "根节点消息_打开三维模型";
	const string G3DVIEW_3D_CLOSE_T3DFILE       = "根节点消息_关闭所有模型";
	const string G3DVIEW_3D_DISP_T3DFILE        = "根节点消息_显示所有模型";	
	const string G3DVIEW_3D_DELETE_T3DFILE      = "根节点消息_移除所有模型";	
}