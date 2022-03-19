/***************************************************************************
    QgsMapToolSelectExt.h  -  map tool for selecting features
    ---------------------
    begin                : May 2010
    copyright            : (C) 2010 by Jeremy Palmer
    email                : jpalmer at linz dot govt dot nz
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSMAPTOOLSELECTEXT_H
#define QGSMAPTOOLSELECTEXT_H

#include "qgsmaptool.h"
#include "QgsMapToolSelectHandlerExt.h"

class QgsMapCanvas;
class QMouseEvent;

class QgsMapToolSelectExt : public QgsMapTool
{
    Q_OBJECT

public:
	QgsMapToolSelectExt(QgsMapCanvas *canvas);

	void setSelectionMode(QgsMapToolSelectHandlerExt::SelectionMode selectionMode);

	void canvasPressEvent(QgsMapMouseEvent *e) override;
	void canvasMoveEvent(QgsMapMouseEvent *e) override;
	void canvasDoubleClickEvent(QgsMapMouseEvent *e) override;
	void canvasReleaseEvent(QgsMapMouseEvent *e) override;
	void keyReleaseEvent(QKeyEvent *e) override;
	void deactivate() override;

private slots:
	void selectFeatures(Qt::KeyboardModifiers modifiers);

private:
	std::unique_ptr<QgsMapToolSelectHandlerExt> mSelectionHandler;

};

#endif
