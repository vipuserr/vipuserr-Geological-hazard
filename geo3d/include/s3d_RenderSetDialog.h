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
		Method_NatureBreakPoint = 0,	//��Ȼ�ϵ�
		Method_EqualInterval = 1,		//��ȼ��
		Method_Quantile = 2				//��λ��
	};
	
	struct ModelRenderSetStr
	{
		QgsColorRamp *pColorRamp;	//ɫ��
		ClassifyMethod method;		//���෽��
		int iClassfyLevel;			//���༶��
		double dInvalidVal;			//��Чֵ
		
		ModelRenderSetStr(): pColorRamp(nullptr),
							 method(Method_Quantile),
							 iClassfyLevel(0),
							 dInvalidVal(0.0)
		{
		}
	};


	//��õ�ǰ��������
	ModelRenderSetStr& GetCurRenderSet();
	
public slots:
	void OnBnClicked_Ok();
	
private:
	ModelRenderSetStr m_paraSet;
	
	Ui::s3d_RenderSetDialog ui;
};
