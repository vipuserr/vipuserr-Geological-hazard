#pragma once

#include "ogview_global.h"
#include "qgsmapcanvas.h"
#include <qgsmaptoolpan.h>
#include <qevent.h>
#include <qmenu.h>

#define MOUSE_DOUBLECLICK_MESSAGE  "鼠标双击消息"
#define MOUSE_MOVE_MESSAGE  "鼠标移动消息"
#define MOUSE_PRESS_MESSAGE "鼠标按下消息"
#define MOUSE_RELEASE_MESSAGE "鼠标释放消息"

namespace Smart3dMap
{

	class SectionMapTool;

	class OGVIEW_EXPORT OG2DView : public QgsMapCanvas
	{
		Q_OBJECT

	public:
		OG2DView(QWidget *parent = nullptr);
		~OG2DView();

		void setMapToolAsPan();
		void setMapToolAsSectionMapEditor(QgsProject* project);
		void releaseSectMapTool();

		virtual bool isEditing() const;

		virtual void additionalContextMenuActions(QMenu& menu) const {};

	public:
		HWND getWnd();						//获取当前窗口
		void ToggleRuler();					//切换标尺
		void mouseMoveEvent(QMouseEvent * event) override;//鼠标移动事件
		void mouseDoubleClickEvent(QMouseEvent *e) override;
		void mousePressEvent(QMouseEvent *e) override; //鼠标按下事件
		void mouseReleaseEvent(QMouseEvent *e) override;
		void dropEvent(QDropEvent *event) override;

	private:
		// 不同的视图不能共享同一个工具，否则会在当前视图的操作会影响另外一个视图。
		QgsMapToolPan* m_mapToolPan;
		SectionMapTool* m_secMapEditor;	// 适合由专门处理剖面图的专题视图类(OgFacePlugin_2DThematicView)管理，但目前专题视图类不是DLL导出类。
	};
}

