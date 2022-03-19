#pragma once
#include <plugin_qgsmaptool_global.h>
#include <qgisapp.h>
#include <QObject>
#include <qgsmapcanvas.h>

#include "MapEditTool/SectVertexTool.h"

class PLUGIN_QGSMAPTOOL_EXPORT VectorLayerCmd : public QObject
{
	Q_OBJECT

public:
	VectorLayerCmd(QObject* parent = nullptr);
	~VectorLayerCmd();

	void initMyVertexTool();

	void edit_bak(QgsMapCanvas* canvas, QgsProject* qgsPrj);
	void edit(QgsMapCanvas* canvas, QgsVectorLayer* curVectorLayer);
	void edit_new(QgsMapCanvas* canvas, QgsProject* qgsPrj, QgsVectorLayer* curVectorLayer);
	void edit1(QgsMapCanvas* canvas, QgsProject* qgsPrj, QgsVectorLayer* curVectorLayer);
	void attribute(QgsMapCanvas* canvas);

private:
	static QgsVectorLayer* ms_pLastVectorLayer;
	static SectVertexTool* ms_pMyVertexTool0;
	static SectVertexTool* ms_pMyVertexTool1;

	void startEditVectorLayer(QgsMapCanvas* canvas, QgsVectorLayer* curVectorLayer);
	void stopEditVectorLayer(QgsMapCanvas* canvas, QgsVectorLayer* curVectorLayer);
};
