#pragma once
#include "ui_qgsdecorationgriddialog.h"
#include "s3dmqgsdialog_global.h"
#include <QDialog>
class S3dmDecorationGrid;
class QgsLineSymbol;
class QgsMarkerSymbol;

class S3DMQGSDIALOG_EXPORT S3dmDecorationGridDialog : public QDialog, private Ui::QgsDecorationGridDialog
{
	Q_OBJECT

public:
	S3dmDecorationGridDialog(S3dmDecorationGrid &decoGrid, QWidget *parent = nullptr);

private slots:
	void apply();
	void buttonBox_accepted();
	void buttonBox_rejected();
	void showHelp();
	void updateSymbolButtons();
	void mPbtnUpdateFromExtents_clicked();
	void mPbtnUpdateFromLayer_clicked();

	// from composer map
	/* void on_mLineColorButton_clicked(); */
	void annotationFontChanged();

private:
	S3dmDecorationGrid &mDeco;

	void updateGuiElements();
	void updateDecoFromGui();
	void updateInterval(bool force = false);
};

