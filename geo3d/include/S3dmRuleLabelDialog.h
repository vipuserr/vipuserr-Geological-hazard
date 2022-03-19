#pragma once

#include <QWidget>
#include "ui_S3dmRuleLabelDialog.h"


class S3dmRuleLabelDialog : public QDialog
{
	Q_OBJECT

public:
	static RuleLabelAttr getRLAttr(RuleLabelAttr oldAttr, gmeFields & flds);
public slots:
	void RLDialogAccept();
private:
	S3dmRuleLabelDialog(QDialog  *parent = nullptr);


	Ui::S3dmRuleLableDialog ui;

	void addFields(gmeFields & flds);
	void updateUI(gmeFields & flds);
	RuleLabelAttr           m_RuleLabelAttr;
	QEventLoop *m_Loop;
};
