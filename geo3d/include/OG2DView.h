#pragma once

#include "ogview_global.h"
#include "qgsmapcanvas.h"
#include <qgsmaptoolpan.h>
#include <qevent.h>
#include <qmenu.h>

#define MOUSE_DOUBLECLICK_MESSAGE  "���˫����Ϣ"
#define MOUSE_MOVE_MESSAGE  "����ƶ���Ϣ"
#define MOUSE_PRESS_MESSAGE "��갴����Ϣ"
#define MOUSE_RELEASE_MESSAGE "����ͷ���Ϣ"

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
		HWND getWnd();						//��ȡ��ǰ����
		void ToggleRuler();					//�л����
		void mouseMoveEvent(QMouseEvent * event) override;//����ƶ��¼�
		void mouseDoubleClickEvent(QMouseEvent *e) override;
		void mousePressEvent(QMouseEvent *e) override; //��갴���¼�
		void mouseReleaseEvent(QMouseEvent *e) override;
		void dropEvent(QDropEvent *event) override;

	private:
		// ��ͬ����ͼ���ܹ���ͬһ�����ߣ�������ڵ�ǰ��ͼ�Ĳ�����Ӱ������һ����ͼ��
		QgsMapToolPan* m_mapToolPan;
		SectionMapTool* m_secMapEditor;	// �ʺ���ר�Ŵ�������ͼ��ר����ͼ��(OgFacePlugin_2DThematicView)������Ŀǰר����ͼ�಻��DLL�����ࡣ
	};
}

