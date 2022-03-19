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
	explicit S3d_LoadingDialog(std::string title ="加载中...", QWidget *parent = nullptr);
	~S3d_LoadingDialog();
	//设置提示文本
	void setTipsText(QString strTipsText);
	//设置是否显示取消等待按钮
	void setCanCancel(bool bCanCancel);
	//移动到指定窗口中间显示
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

