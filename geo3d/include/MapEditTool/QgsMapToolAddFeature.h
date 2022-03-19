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

	enum CaptureMode // 矢量化类型
	{
		CaptureNone,       // 无
		CapturePoint,      // 点
		CaptureLine,       // 线
		CapturePolygon     // 面
	};

public:


	//! 重写鼠标指针释放事件
	virtual void canvasReleaseEvent(QgsMapMouseEvent* e);



private:
	/** 用于存放线和多边形要素的捕获节点列表*/
	QList<QgsPointXY> *m_captureList;
	//捕获的类型
	CaptureMode m_captureMode;
	QgsMapCanvas * mCanvas;

};