#pragma once
#include "S3dmVectorLayer.h"
#include <QDialog>
#include "ui_S3dmRegColorDialog.h"
#include "s3dmqgsdialog_global.h"

namespace Smart3dMap {
	class S3DMQGSDIALOG_EXPORT S3dmRegColorDialog : public QDialog
	{
		Q_OBJECT

	public:
		static RegColorAttr getRegColorAttr(S3dmRegLayer* layer);
	public slots:
		void accept();
	private:
		S3dmRegColorDialog(S3dmRegLayer&layer, QDialog *parent = Q_NULLPTR);
		Ui::S3dmRegColorDialog ui;
		void updateUI(S3dmRegLayer&layer);
		//��������ʽ
		void addFillstyle();
		//��ӱ߿���ʽ
		void addBorderstyle();
		//��ӱ߿�λ
		void addBorderwidthunit();

		RegColorAttr m_RegColorAttr;
	};
}
