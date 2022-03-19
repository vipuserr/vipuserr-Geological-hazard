#pragma once
#include "S3dmVectorLayer.h"
#include "S3dmLabels.h"
#include "s3dmqgsdialog_global.h"
#include <QDialog>
#include "ui_S3dmLabelSelector.h"
#include <vector>

using namespace Smart3dMap;
class  S3DMQGSDIALOG_EXPORT S3dmLabelSelector : public QDialog
{
	Q_OBJECT
public:
	static void getLabelAttr(S3dmPntLayer* layer);
public slots:
	void applyLabel();
	
private:
	S3dmLabelSelector(QDialog *parent = Q_NULLPTR);
	Ui::S3dmLabelSelector	ui;

	void updateUI(S3dmLabels& labels, gmeFields & flds);
	void add();
	void editTable();
	void deleteTable();
	void Settable();
	void confirmLabel();
	
	S3dmLabels m_Labels;
	gmeFields m_Fields;

	Smart3dMap::S3dmVectorLayer* m_VectorLayer;
};
