#pragma once
#include "S3dmVectorLayer.h"
#include "S3dmLabels.h"
#include "s3dmqgsdialog_global.h"
#include <QDialog>
#include "ui_S3dmSimpleLabelDialog.h"


using namespace Smart3dMap;
class S3DMQGSDIALOG_EXPORT S3dmSimpleLabelDialog : public QDialog
{
	Q_OBJECT
public:
	static SimpleLabelAttr getSimpleLabelAttr(S3dmVectorLayer* layer);
public slots:
	void accept();

private:
	S3dmSimpleLabelDialog(S3dmVectorLayer& layer, QDialog *parent = Q_NULLPTR);

	void updateUI(S3dmVectorLayer& layer);
	void addFieldItems(gmeFields& flds);
	void addSizeUnit();
	void addOffsetUnit();
	void addOrientation();

	Ui::S3dmSimpleLabelDialog	ui;
	SimpleLabelAttr			m_SimpleLabelAttr;
};
