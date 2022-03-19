#ifndef LOADINGDIALOG_H
#define LOADINGDIALOG_H
#include <QMovie>
#include <QLabel>
#include <QDialog>
#include <QPainter>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <string>

#include "s3dmqgsdialog_global.h"

#define USER_CANCEL -1
class S3DMQGSDIALOG_EXPORT S3d_LoadingDialog : public QDialog
{
	Q_OBJECT
public:
	explicit S3d_LoadingDialog(std::string title ="������...", QWidget *parent = nullptr);
	~S3d_LoadingDialog();
	//������ʾ�ı�
	void setTipsText(QString strTipsText);
	//�����Ƿ���ʾȡ���ȴ���ť
	void setCanCancel(bool bCanCancel);
	//�ƶ���ָ�������м���ʾ
	void moveToCenter(QWidget* pParent);
protected:
	void paintEvent(QPaintEvent *event) override;
private:
	void initUi(std::string title);
Q_SIGNALS:
	void cancelWaiting();
private slots:
	void cancelBtnClicked();
private:
	QFrame *m_pCenterFrame;
	QLabel *m_pMovieLabel;
	QMovie *m_pLoadingMovie;
	QLabel *m_pTipsLabel;
};
#endif // LOADINGDIALOG_H

