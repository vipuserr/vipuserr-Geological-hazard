#pragma once
#include "S3dmVectorLayer.h"
#include <QDialog>
#include "ui_S3dmVectorCateStyle.h"
#include "s3dmqgsdialog_global.h"


class S3DMQGSDIALOG_EXPORT S3dmVectorCateStyle : public QDialog
{
	Q_OBJECT

public:
	S3dmVectorCateStyle(QWidget *parent = Q_NULLPTR);
	~S3dmVectorCateStyle();

	void getVectorCateStyle(Smart3dMap::S3dmVectorLayer* layer);
	void getCurrentFieldInfo();
	void changeSymbol();
	
	void applyLayer();
	void confirmLayer();

private:
	void addField();
	void updateUI(std::string field, std::map<QVariant, QgsRendererCategory>& renders);
	FieldType getFieldType(std::string field);

	PntCategoryAttr getLayerCateStyle(Smart3dMap::S3dmPntLayer* layer);

	LineCategoryAttr getLayerCateStyle(Smart3dMap::S3dmLineLayer* layer);

	RegCategoryAttr getLayerCateStyle(Smart3dMap::S3dmRegLayer* layer);

	

private:
	Ui::S3dmVectorCateStyle ui;
	Smart3dMap::S3dmVectorLayer* m_Layer;
	QgsSymbol* defSym;
};
