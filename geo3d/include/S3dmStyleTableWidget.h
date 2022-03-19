#pragma once
#include <qtablewidget.h>
#include <qgssymbol.h>
#include <vector>
#include <qpair.h>

#include "s3dmqgsdialog_global.h"

enum FieldType
{
	FLD_STRING,
	FLD_DOUBLE,
	FLD_INT
};

class S3DMQGSDIALOG_EXPORT S3dmStyleCateTableWidget:public QTableWidget
{
public:
	struct cateValue
	{
		QgsSymbol* symbol = nullptr;
		std::pair<FieldType,QVariant>   value;
		QString	   label;
	};
	explicit S3dmStyleCateTableWidget(QWidget *parent = nullptr);
	void setLayerType(const S3dmLayerType& type);
	~S3dmStyleCateTableWidget();

	void addAllRow(std::vector<cateValue>& cateValues);
	void addRow(int row,cateValue& cateValue);
	void updateRow(int row, cateValue& cateValue);
	//分级
	void addAllClassRow(std::vector<cateValue>& cateValues);
	//颜色的更新
	void addAllClassRowClr(std::vector<cateValue>& cateValues);
	
	void addClassRow(int row, cateValue& cateValue);
	//用于更新一行的信息
	void updateClassRow(int row, cateValue& cateValue);
	//用于更新所有行的信息
	void updateAllRow(std::vector<cateValue>& cateValues);

	void updateAllRowClr(std::vector<cateValue>& cateValues);
	void removeAllRow();
	void getAllRow(std::vector<S3dmStyleCateTableWidget::cateValue>& cateValues);
	
	void getClassAllRow(std::vector<S3dmStyleCateTableWidget::cateValue>& cateValues);
private:
	struct QSymbolData:public QObjectUserData
	{
		QgsSymbol* symbol;
	};

	S3dmLayerType m_LayerType;
	FieldType m_FieldType;
};

