#pragma once

#include "ui_s3d_RenderSetDialog.h"
#include "s3dmqgsdialog_global.h"

class S3DMQGSDIALOG_EXPORT s3d_RenderSetDialog : public QDialog
{
	Q_OBJECT

public:
	s3d_RenderSetDialog(QWidget *parent = Q_NULLPTR);
	~s3d_RenderSetDialog();

	enum ClassifyMethod
	{
		Method_NatureBreakPoint = 0,	//自然断点
		Method_EqualInterval = 1,		//相等间隔
		Method_Quantile = 2				//分位数
	};
	
	struct ModelRenderSetStr
	{
		QgsColorRamp *pColorRamp;	//色带
		ClassifyMethod method;		//分类方法
		int iClassfyLevel;			//分类级数
		double dInvalidVal;			//无效值
		
		ModelRenderSetStr(): pColorRamp(nullptr),
							 method(Method_Quantile),
							 iClassfyLevel(0),
							 dInvalidVal(0.0)
		{
		}
	};


	//获得当前界面设置
	ModelRenderSetStr& GetCurRenderSet();
	
public slots:
	void OnBnClicked_Ok();
	
private:
	ModelRenderSetStr m_paraSet;
	
	Ui::s3d_RenderSetDialog ui;
};
