/***************************************************************************
    QgsMaptoolDoubleClickFeatrue.h  -  map tool for selecting features
    ---------------------
    begin                :
    copyright            :
    email                :
 ***************************************************************************
 *                                                                         *
 *                                                                         *
 ***************************************************************************/
#pragma once

#include "qgsmaptool.h"
#include "QgsMapToolSelectHandlerExt.h"

class QgsMapCanvas;
class QMouseEvent;

class QgsMaptoolDoubleClickFeatrue : public QgsMapTool
{
    Q_OBJECT

  public:
    QgsMaptoolDoubleClickFeatrue( QgsMapCanvas *canvas );

    void setSelectionMode( QgsMapToolSelectHandlerExt::SelectionMode selectionMode );

    void canvasPressEvent( QgsMapMouseEvent *e ) override;
	void canvasDoubleClickEvent(QgsMapMouseEvent *e ) override;
    void canvasMoveEvent( QgsMapMouseEvent *e ) override;
    void canvasReleaseEvent( QgsMapMouseEvent *e ) override;
    void keyReleaseEvent( QKeyEvent *e ) override;
    void deactivate() override;

  private slots:
    void selectFeatures( Qt::KeyboardModifiers modifiers );

  private:
    std::unique_ptr<QgsMapToolSelectHandlerExt> mSelectionHandler;
};
