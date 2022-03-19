#ifndef SIMPLE_LABEL_ATTR_WIDGET_H
#define SIMPLE_LABEL_ATTR_WIDGET_H
#include "S3dmVectorLayer.h"
#include <QDialog>
#include <qstring.h>
#include "ui_SimpleLabelAttrWidget.h"
#include "s3dmqgsdialog_global.h"
#include "gmeStru.h"

using namespace Smart3dMap;


class S3DMQGSDIALOG_EXPORT SimpleLabelAttrWidget : public QWidget, private Ui::SimpleLabelAttrWidget
{
	Q_OBJECT

public:
	SimpleLabelAttrWidget(QWidget *parent = Q_NULLPTR);
	
	SimpleLabelAttr& getSimpleLabelAttr();
	void setSimpleLabelAttr(SimpleLabelAttr SimpleLabelAttr, gmeFields & flds);
	void updateUI(gmeFields & flds);

	void addFields(gmeFields& flds);

private:
	void addSizeUnit();
	void addOffsetUnit();
	void addOrientation();

	SimpleLabelAttr m_SimpleLabelAttr;
};
#endif