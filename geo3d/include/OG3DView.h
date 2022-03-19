#pragma once

#include "ogview_global.h"
#include "qgraphicsview.h"
#include <string>
using std::string;

#   pragma warning (disable : 4786)
#   pragma warning (disable : 4503)
#   pragma warning (disable : 4244)
#   pragma warning (disable : 4305)
#   pragma warning (disable : 4251)
#   pragma warning (disable : 4275)
#   pragma warning (disable : 4290)
#   pragma warning (disable : 4661)
#	 pragma warning (disable : 4996)
#	 pragma warning (disable : 4103)


class ViewerWidget;
namespace Smart3dMap
{
	class C3DRenderEngine;	//3D视图引擎
	class COGThread;
	class OGVIEW_EXPORT OG3DView : public QWidget//QGraphicsView
	{
		Q_OBJECT

	public:
		OG3DView(QWidget *parent = nullptr);
		~OG3DView();

	private slots:
		void contextMenuFunction();//右键菜单槽函数
		void contextMenu_3DView(const QPoint& pos);//三维视图右键菜单
	public:
		void keyPressEvent(QKeyEvent *event);//键盘按压事件
		void resizeEvent(QResizeEvent *event);//窗口尺寸改变事件
		void paintEvent(QPaintEvent* event);

	public:
		ViewerWidget* mRenderWidget;
		COGThread* m_ogThread;//线程
		C3DRenderEngine* m_p3DRenderEngine;//三维引擎
	};

}

