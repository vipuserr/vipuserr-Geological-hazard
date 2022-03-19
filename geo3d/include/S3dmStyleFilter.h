#pragma once
#include "s3dmqgsdialog_global.h"
#include <QDialog>
#include "ui_S3dmStyleFilter.h"
#include <vector>

class QgsSymbol;
class SAConnection;

class S3DMQGSDIALOG_EXPORT S3dmStyleFilter : public QDialog
{
	Q_OBJECT
public:
	class SymbolInfo
	{
	public:
		QString innerTbl = "";//内部表名
		QString whereCase = ""; //where条件
		QgsSymbol* symbol = nullptr; //样式
	};
public:
	S3dmStyleFilter(SAConnection* con,QDialog *parent = Q_NULLPTR);
	~S3dmStyleFilter();


	void initStyleTable();

	void getTables();
	void getSelectedStyle(std::vector<SymbolInfo>& symbols);

	void updateField();
	
	void addStyle();
	void removeStyle();


private slots:
	void selectStyle(QTableWidgetItem* item);
	void selectField(QTableWidgetItem* item);
	void accept();
private:
	Ui::S3dmStyleFilter ui;
	SAConnection* m_Con;
};
