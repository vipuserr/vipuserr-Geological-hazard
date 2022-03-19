#pragma once
#include "S3dmVectorLayer.h"
#include <QDialog>
#include "ui_S3dmVectorCateStyleDialog.h"
#include "s3dmqgsdialog_global.h"


class S3DMQGSDIALOG_EXPORT S3dmVectorCateStyleDialog : public QDialog
{
	Q_OBJECT

public:
	static void getVectorCateStyle(Smart3dMap::S3dmVectorLayer* layer);
	
public:
	S3dmVectorCateStyleDialog(QWidget *parent = Q_NULLPTR);
	~S3dmVectorCateStyleDialog();

	void getCurrentFieldInfo();
	void changeSymbol();

	void applyLayer();
	void confirmLayer();

	void addCate();

	void addField();
	void updateUI(std::string field, std::map<QVariant, QgsRendererCategory>& renders);
	FieldType getFieldType(std::string field);

	PntCategoryAttr getLayerCateStyle(Smart3dMap::S3dmPntLayer* layer);

	LineCategoryAttr getLayerCateStyle(Smart3dMap::S3dmLineLayer* layer);

	RegCategoryAttr getLayerCateStyle(Smart3dMap::S3dmRegLayer* layer);

	

private:
	Ui::S3dmVectorCateStyleDialog ui;
	Smart3dMap::S3dmVectorLayer* m_Layer;
};
