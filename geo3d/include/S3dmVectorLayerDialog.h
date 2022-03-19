#pragma once

#include <QDialog>
#include "ui_S3dmVectorLayerDialog.h"
#include "s3dmqgsdialog_global.h"

class S3DMQGSDIALOG_EXPORT S3dmVectorLayerDialog : public QDialog
{
	Q_OBJECT

public:
	static void getVectorSymbol(Smart3dMap::S3dmVectorLayer* layer);
public:
	S3dmVectorLayerDialog(QWidget *parent = Q_NULLPTR);
	~S3dmVectorLayerDialog();

private:
	Ui::S3dmVectorLayerDialog ui;
	Smart3dMap::S3dmVectorLayer* m_Layer;
};
