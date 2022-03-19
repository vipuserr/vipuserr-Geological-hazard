#pragma once
#include "qtablewidget.h"
#include "s3dmqgsdialog_global.h"
#include "qgscolorramp.h"
#include "qgsrasterlayer.h"

class S3DMQGSDIALOG_EXPORT S3dmColorTableWidget:public QTableWidget
{
public:
	enum Interpolation {
		Discrete = 0,//离散
		Linear = 1,//线性
		Exact = 2 //准确
	};
	//针对raster及不同插值色带方法变化时的显示：初始和传入方法和值时得到的list
	void setInterpolation(Interpolation);
	void showRasterRows(std::vector<double> values, std::vector<QColor> colors, std::vector<QString> labels);

	/*默认仅显示三列值：value，color和label,默认三个vector大小一致；
	 *当label需要分段时，允许colors比label个vector少一个，此时values传空
	 *传空时，仅显示两列
	 */
	void showRows(std::vector<double> values, std::vector<QColor> colors, std::vector<QString> labels, bool useInterval);

	//变更完所有后最终的list和data
	QList<QgsColorRampShader::ColorRampItem> getItem();

	 S3dmColorTableWidget(QWidget *parent = Q_NULLPTR);
	~S3dmColorTableWidget();
private:
	QList<QgsColorRampShader::ColorRampItem> colorRampItems;
	Interpolation m_interpolation;
};

