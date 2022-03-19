#pragma once

#include "tdmfacelib_global.h"

#include "OGBasDef.h"
#include <map>

using namespace std;

#define OG_PLUGIN_VIEW_EXTEND "ogx"		//��ͼ�����׺��
#define OG_PLUGIN_WORKBAR_EXTEND "ogm"  //Dockbar�����׺��


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


	//�ļ�����
	const string STR_FRM_DIR_NAME = "appframe";
	const string STR_DATATREE_FILE_NAME_VAL = "dataTree";
	const string STR_IMAGE_FILE_NAME_VAL = "img";
	//�ļ���
	const string STR_SYS_FACE_FILE_NAME = "OGSysFaceCfg.xml";
	const string STR_SYS_ICON_FILE_NAME = "appIcon.png";
	const string STR_SYS_SURFACE_FILE_NAME = "appSplash.bmp";
	const string STR_SYS_TOOLBAR_FILE_NAME = "toolBar.bmp";
	const string STR_SYS_TREENODE_FILE_NAME = "TreeNode.bmp";
	const string STR_SYS_APP_FILE_NAME = "OgIntelligentGeom.exe";
	const string STR_SYS_2DBACKGROUND_FILE_NAME = "2dviewBg.png";
	//����
	const string STR_DOCK_VIEW_2D = "��ά����";
	const string STR_DOCK_VIEW_3D = "��ά����";
	const string STR_DOCK_VIEW_DATA = "���ݲ�";
	const string STR_DOCK_VIEW_RIGHT = "�Ҵ���";
	const string STR_DOCK_VIEW_BOTTOM = "�״���";

	class TDMFACELIB_EXPORT OgAppResLoadingIterator
	{
	private:
		OgAppResLoadingIterator(void);
		~OgAppResLoadingIterator();

	public:
		static OgAppResLoadingIterator* getSingletonPtr(void);//ȫ��ָ��
		static OgAppResLoadingIterator& getSingleton(void);//ȫ������

	public:
		string GetSysEvnPath();//��ȡϵͳ����·��
		string GetFrmListPath();//��ȡӦ�ó�����б����ڵ�·��
		vector<string>& getFrmList();//��ȡӦ�ó�����б�
		void ClearFrmList();//���Ӧ�ó����б�
		
		vector<string>  getFolderListOfFolder(string strFolderPath);//��ȡָ���ļ����µ�һ���ļ����б�
		vector<string>  getFileListOfFolder(string strFolderPath, string strExt);//��ȡָ���ļ����µ�һ���ļ��б�
		vector<string>  getPluginListOfName(string strFolderPath, string strExt, vector<string> PluginList);//��ȡ����б�
		string getViewPluginName(string ViewPlugin);//��ȡ��ͼ�����
		string getWorkBarPluginName(string WorkBarPlugin);//��ȡ�������ڲ����
		
		vector<string> InitCommamdParam(string& strCurAppName);//ȡ�������в�������ʼ��ϵͳ����...
		void createFrmDirectory(string strFrmName);//���ݵ�ǰ��ϵͳ���ƴ���ϵͳ��ܵ�Ŀ¼ϵͳ
		
		void setCurAppName(string strCurAppName);//����ϵͳ����
		string getCurAppName();//��ȡ��ǰϵͳ��
		string getCurAppPath();//��ȡ��ǰϵͳ·��
		string getGmeDataBase();//��ȡGme���ݿ�·��
		string getAccessDataBase();//��ȡAccess���ݿ�·��
		void setViewBackgroundBrush(string viewName, string pictureName);//������ͼ����ͼƬ

		//------- ϵͳ����������ز���-----------//
		void loadSysFrame();//�������
		void exePreLoadCmd();//����ϵͳԤ������
		void exeSplashWindow(QWidget* pMainWnd);//����ϵͳ��������
		void setSysDispName(QWidget* pMainWnd);//����ϵͳ����
		void setSysIcon(QWidget* pMainWnd);//����ϵͳͼ��

		QMenuBar* loadMenu(QWidget* pMainWnd, std::string strViewName, QList<QAction*> &actionList);//����Ĭ����ͼ�Ĳ˵�
		QToolBar* loadToolBar(QWidget* pMainWnd, std::string strViewName, QList<QAction*> &actionList);//���ع�������Ϣ
		void loadView(QTabWidget* p2DTabView, QTabWidget* p3DTabView, QTabWidget* pLeftTabView, QTabWidget* pRightTabView, QTabWidget* pBottomTabView);//������ͼ
		void unLoadView(QTabWidget* p2DTabView, QTabWidget* p3DTabView, QTabWidget* pLeftTabView, QTabWidget* pRightTabView, QTabWidget* pBottomTabView);//ж����ͼ
		void loadStatusBar(QWidget* pMainWnd);//����״̬��
		void editStatusCoordinate(double x, double y, double z);//�༭״̬������
		void editStatusCoordinate(string x, string y, string z);//�༭״̬������
		void editStatusCmd(string msg);//�༭״̬����Ϣ
		void editStatusProg(int progress);//����״̬��������
		void loadAboutDlg();//���ع�����Ϣ

		void connectFunction(string actionView, string actionResCode);//��������
		void executeFunction(string pluginName, string funcName);//ִ�й���

	private:
		vector<string>  m_strAppNameList;//ϵͳӦ�����б�
		string			m_strSysEvnPath;//ϵͳ����·��
		string			m_strAllAppPath;//app����·��
		string			m_curAppName;//��ǰѡ���Ӧ�ó���
		string			m_curAppPath;//��ǰѡ���Ӧ�ó���·��
		string			m_curAppPathFile;//��ǰѡ���Ӧ�ó��������ļ�·��
		string          m_GmeDateBasePath;//Gme���ݿ�·��
		string          m_AccessDateBasePath;//Access���ݿ�·��
		string			m_materialPath;

		__int64 *mStatuBar;//״̬��
		//QLabel *mStatuMessage;//״̬��Ϣ
		//QLabel *mStatuMessageValue;//״ֵ̬
		QLabel *mStatuCoordinate;//������Ϣ
		QLabel *mStatuCoordinatePara1;//����ֵ
		QLabel *mStatuCoordinatePara2;//����ֵ
		QLabel *mStatuCoordinatePara3;//����ֵ
		QLabel *mStatuCoordinateUnit;//��λֵ
		QLabel *mStatuProgress;//����������
		__int64 * mProgressBar;//������

		vector<DyLoadView> g_DyLeftViewList;//�����б�
		vector<DyLoadView> g_DyRightViewList;//�Ҳ���б�
		vector<DyLoadView> g_DyBottomViewList;//�ײ���б�
		vector<DyLoadView> g_Dy2DViewList;//2ά��ͼ�б�
		vector<DyLoadView> g_Dy3DViewList;//3ά��ͼ�б�

	public:
		map<string, __int64*> m2DViewPtr;//��ά��ͼָ��
		map<string, QWidget*> m3DViewPtr;//��ά��ͼָ��
		map<string, QDockWidget*> mDockPtr;//��������ָ��
	};
}

