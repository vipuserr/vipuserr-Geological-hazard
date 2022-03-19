#pragma once

#include "tdmfacelib_global.h"

#include "OGBasDef.h"
#include <map>

using namespace std;

#define OG_PLUGIN_VIEW_EXTEND "ogx"		//视图插件后缀名
#define OG_PLUGIN_WORKBAR_EXTEND "ogm"  //Dockbar插件后缀名


class QWidget;
class QMenuBar;
class QToolBar;
class QTabWidget;
class QMainWindow;
class QDockWidget;
class QLabel;
class QGraphicsView;
class QAction;
template <typename T> 
class QList;


namespace Smart3dMap
{
	class DyLoadView;


	//文件夹名
	const string STR_FRM_DIR_NAME = "appframe";
	const string STR_DATATREE_FILE_NAME_VAL = "dataTree";
	const string STR_IMAGE_FILE_NAME_VAL = "img";
	//文件名
	const string STR_SYS_FACE_FILE_NAME = "OGSysFaceCfg.xml";
	const string STR_SYS_ICON_FILE_NAME = "appIcon.png";
	const string STR_SYS_SURFACE_FILE_NAME = "appSplash.bmp";
	const string STR_SYS_TOOLBAR_FILE_NAME = "toolBar.bmp";
	const string STR_SYS_TREENODE_FILE_NAME = "TreeNode.bmp";
	const string STR_SYS_APP_FILE_NAME = "OgIntelligentGeom.exe";
	const string STR_SYS_2DBACKGROUND_FILE_NAME = "2dviewBg.png";
	//窗口
	const string STR_DOCK_VIEW_2D = "二维窗口";
	const string STR_DOCK_VIEW_3D = "三维窗口";
	const string STR_DOCK_VIEW_DATA = "数据层";
	const string STR_DOCK_VIEW_RIGHT = "右窗口";
	const string STR_DOCK_VIEW_BOTTOM = "底窗口";

	class TDMFACELIB_EXPORT OgAppResLoadingIterator
	{
	private:
		OgAppResLoadingIterator(void);
		~OgAppResLoadingIterator();

	public:
		static OgAppResLoadingIterator* getSingletonPtr(void);//全局指针
		static OgAppResLoadingIterator& getSingleton(void);//全局引用

	public:
		string GetSysEvnPath();//获取系统环境路径
		string GetFrmListPath();//获取应用程序的列表所在的路径
		vector<string>& getFrmList();//获取应用程序的列表
		void ClearFrmList();//清空应用程序列表
		
		vector<string>  getFolderListOfFolder(string strFolderPath);//获取指定文件夹下的一级文件夹列表
		vector<string>  getFileListOfFolder(string strFolderPath, string strExt);//获取指定文件夹下的一级文件列表
		vector<string>  getPluginListOfName(string strFolderPath, string strExt, vector<string> PluginList);//获取插件列表
		string getViewPluginName(string ViewPlugin);//获取视图插件名
		string getWorkBarPluginName(string WorkBarPlugin);//获取浮动窗口插件名
		
		vector<string> InitCommamdParam(string& strCurAppName);//取出命令行参数并初始化系统环境...
		void createFrmDirectory(string strFrmName);//根据当前的系统名称创建系统框架的目录系统
		
		void setCurAppName(string strCurAppName);//设置系统名称
		string getCurAppName();//获取当前系统名
		string getCurAppPath();//获取当前系统路径
		string getGmeDataBase();//获取Gme数据库路径
		string getAccessDataBase();//获取Access数据库路径
		void setViewBackgroundBrush(string viewName, string pictureName);//设置视图背景图片

		//------- 系统界面启动相关操作-----------//
		void loadSysFrame();//启动框架
		void exePreLoadCmd();//加载系统预加载项
		void exeSplashWindow(QWidget* pMainWnd);//加载系统启动界面
		void setSysDispName(QWidget* pMainWnd);//设置系统标题
		void setSysIcon(QWidget* pMainWnd);//设置系统图标

		QMenuBar* loadMenu(QWidget* pMainWnd, std::string strViewName, QList<QAction*> &actionList);//加载默认视图的菜单
		QToolBar* loadToolBar(QWidget* pMainWnd, std::string strViewName, QList<QAction*> &actionList);//加载工具栏信息
		void loadView(QTabWidget* p2DTabView, QTabWidget* p3DTabView, QTabWidget* pLeftTabView, QTabWidget* pRightTabView, QTabWidget* pBottomTabView);//加载视图
		void unLoadView(QTabWidget* p2DTabView, QTabWidget* p3DTabView, QTabWidget* pLeftTabView, QTabWidget* pRightTabView, QTabWidget* pBottomTabView);//卸载视图
		void loadStatusBar(QWidget* pMainWnd);//加载状态栏
		void editStatusCoordinate(double x, double y, double z);//编辑状态栏坐标
		void editStatusCoordinate(string x, string y, string z);//编辑状态栏坐标
		void editStatusCmd(string msg);//编辑状态栏信息
		void editStatusProg(int progress);//设置状态栏进度条
		void loadAboutDlg();//加载关于信息

		void connectFunction(string actionView, string actionResCode);//关联功能
		void executeFunction(string pluginName, string funcName);//执行功能

	private:
		vector<string>  m_strAppNameList;//系统应用名列表
		string			m_strSysEvnPath;//系统环境路径
		string			m_strAllAppPath;//app所在路径
		string			m_curAppName;//当前选择的应用程序
		string			m_curAppPath;//当前选择的应用程序路径
		string			m_curAppPathFile;//当前选择的应用程序配置文件路径
		string          m_GmeDateBasePath;//Gme数据库路径
		string          m_AccessDateBasePath;//Access数据库路径
		string			m_materialPath;

		__int64 *mStatuBar;//状态栏
		//QLabel *mStatuMessage;//状态信息
		//QLabel *mStatuMessageValue;//状态值
		QLabel *mStatuCoordinate;//坐标信息
		QLabel *mStatuCoordinatePara1;//坐标值
		QLabel *mStatuCoordinatePara2;//坐标值
		QLabel *mStatuCoordinatePara3;//坐标值
		QLabel *mStatuCoordinateUnit;//单位值
		QLabel *mStatuProgress;//进度条名称
		__int64 * mProgressBar;//进度条

		vector<DyLoadView> g_DyLeftViewList;//左插件列表
		vector<DyLoadView> g_DyRightViewList;//右插件列表
		vector<DyLoadView> g_DyBottomViewList;//底插件列表
		vector<DyLoadView> g_Dy2DViewList;//2维视图列表
		vector<DyLoadView> g_Dy3DViewList;//3维视图列表

	public:
		map<string, __int64*> m2DViewPtr;//二维视图指针
		map<string, QWidget*> m3DViewPtr;//三维视图指针
		map<string, QDockWidget*> mDockPtr;//浮动窗口指针
	};
}

