#pragma once
//QT include
#include <QObject>
#include <QList>
//Qgis include
#include <qgsmaptool.h>
#include <qgsmapcanvas.h>
#include <qgsmapmouseevent.h>

class QgsMapToolAddFeature : public QgsMapTool
{
	Q_OBJECT
public:
	QgsMapToolAddFeature(QgsMapCanvas* mapCanvas);
	~QgsMapToolAddFeature();

	enum CaptureMode // ʸ��������
	{
		CaptureNone,       // ��
		CapturePoint,      // ��
		CaptureLine,       // ��
		CapturePolygon     // ��
	};

public:


	//! ��д���ָ���ͷ��¼�
	virtual void canvasReleaseEvent(QgsMapMouseEvent* e);



private:
	/** ���ڴ���ߺͶ����Ҫ�صĲ���ڵ��б�*/
	QList<QgsPointXY> *m_captureList;
	//���������
	CaptureMode m_captureMode;
	QgsMapCanvas * mCanvas;

};