#pragma once
#include "qtablewidget.h"
#include "s3dmqgsdialog_global.h"
#include "qgscolorramp.h"
#include "qgsrasterlayer.h"

class S3DMQGSDIALOG_EXPORT S3dmColorTableWidget:public QTableWidget
{
public:
	enum Interpolation {
		Discrete = 0,//��ɢ
		Linear = 1,//����
		Exact = 2 //׼ȷ
	};
	//���raster����ͬ��ֵɫ�������仯ʱ����ʾ����ʼ�ʹ��뷽����ֵʱ�õ���list
	void setInterpolation(Interpolation);
	void showRasterRows(std::vector<double> values, std::vector<QColor> colors, std::vector<QString> labels);

	/*Ĭ�Ͻ���ʾ����ֵ��value��color��label,Ĭ������vector��Сһ�£�
	 *��label��Ҫ�ֶ�ʱ������colors��label��vector��һ������ʱvalues����
	 *����ʱ������ʾ����
	 */
	void showRows(std::vector<double> values, std::vector<QColor> colors, std::vector<QString> labels, bool useInterval);

	//��������к����յ�list��data
	QList<QgsColorRampShader::ColorRampItem> getItem();

	 S3dmColorTableWidget(QWidget *parent = Q_NULLPTR);
	~S3dmColorTableWidget();
private:
	QList<QgsColorRampShader::ColorRampItem> colorRampItems;
	Interpolation m_interpolation;
};

