#pragma once

#include "S3dmVectorLayer.h"
#include <QDialog>
#include "ui_S3dmVectorClassStyleDialog.h"
#include "s3dmqgsdialog_global.h"

class S3DMQGSDIALOG_EXPORT S3dmVectorClassStyleDialog : public QDialog
{
	Q_OBJECT

public:
	static void getVectorClassStyle(Smart3dMap::S3dmVectorLayer* layer);

public:

	S3dmVectorClassStyleDialog(QWidget *parent = Q_NULLPTR);
	~S3dmVectorClassStyleDialog();

	void getCurrentFieldInfo();
	//�ı�ɫ��
	void changeSymbol();
	//�ı���ɫ
	void changeColor();
	//Ӧ�õ�ͼ��
	void applyLayer();
	//����Ĭ���ֶε���Ϣ��ʾ��tablewidget��

	void confirmLayer();

	void addCate();

	void addField();
	void updateUI(std::string field, std::map<QVariant, QgsRendererCategory>& renders);
	FieldType getFieldType(std::string field);
	

	PntCategoryAttr getLayerClassStyle(Smart3dMap::S3dmPntLayer* layer);

	LineCategoryAttr getLayerClassStyle(Smart3dMap::S3dmLineLayer* layer);

	RegCategoryAttr getLayerClassStyle(Smart3dMap::S3dmRegLayer* layer);
private:
	Ui::S3dmVectorClassStyleDialog ui;

	Smart3dMap::S3dmVectorLayer* m_Layer;

	QgsSymbol* m_Symbol = nullptr;

	std::vector<QColor> m_Colors;

	std::string defaultFld;
	
};
