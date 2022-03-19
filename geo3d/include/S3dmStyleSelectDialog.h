#pragma once

#include <QDialog>
#include "OgSingleton.h"
#include "S3dmVectorLayer.h"
#include "s3dmqgsdialog_global.h"
#include "ui_S3dmStyleSelectDialog.h"
#include "qgsstylemodel.h"
#include"S3dmStyleManagerDialog.h"
using namespace  Smart3dMap;
class QgsSymbol;
class QgsStyle;
class QgsCheckableStyleModel;
class QStandardItem;
class S3DMQGSDIALOG_EXPORT S3dmStyleSelectDialog : public QDialog
{
	Q_OBJECT
public:
	
	static QString getSingletonQgsSymbolName(S3dmLayerType layerType);
	static void getSingletonQgsPattern(QString& patternName,QColor& color,S3dmLayerType layerType);
	static QgsSymbol* getQgsSymbolByName(const QString &name);
	static QgsSymbol* getQgsSymbolByPattern(QString& patternName, QColor& color);
private:
	S3dmStyleSelectDialog(S3dmLayerType layerType,QWidget *parent = Q_NULLPTR);
	~S3dmStyleSelectDialog();

	void setLayerType(S3dmLayerType layerType);//设置图案类型
	QString getCurrentQgsSymbolName();//获取当前选中的符号名称
	QColor getCurrentQgsSymbolColor();
	void groupChanged(const QModelIndex &index);
	void setBold(QStandardItem *item);
	void populateGroups();
	void editItem();//编辑器
	int selectedItemType();
	bool editSymbol();
	bool editColorRamp();
private slots:
	void setCurrentQgsSymbol(const QModelIndex &index);
	void selectColor();
	void setBtnColor(QColor& color);
private:
	Ui::S3dmStyleSelectDialog ui;
	QgsStyle *m_Style = nullptr;
	S3dmCheckableStyleModel *m_Model=nullptr;
	QString m_SymbolName = "";
};
