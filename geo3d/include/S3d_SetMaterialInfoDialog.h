#pragma once

#include "ui_S3d_SetMaterialInfoDialog.h"
#include "s3dmqgsdialog_global.h"


//���ò�����Ϣ
class S3DMQGSDIALOG_EXPORT S3d_SetMaterialInfoDialog : public QDialog
{
	Q_OBJECT

public:
	S3d_SetMaterialInfoDialog(QWidget *parent = Q_NULLPTR);
	~S3d_SetMaterialInfoDialog();

	//��������
	enum MatrialType
	{
		Color_Type		= 0,	//��ɫ
		Texture_Type	= 1,	//����
		TableColor_Type = 2		//ɫ��
	};

	//ɫ�����ò���
	struct TableColorParaStr
	{
		QgsColorRamp *pColorRamp;	//ɫ��
		int iClassfyLevel;			//���༶��

		TableColorParaStr() : pColorRamp(nullptr), iClassfyLevel(0)
		{
		}
	};

	//������Ϣ
	struct MaterialSetInfoStr
	{
		MatrialType			materialType;	//��������
		QColor				qColor;			//��ɫ
		QString				qstrTexturePath;//����·��
		TableColorParaStr	tableColorPara;	//ɫ������

		MaterialSetInfoStr() : materialType(Color_Type)
		{
		}
	};

	//��õ�ǰ��������
	MaterialSetInfoStr& GetMaterialInfo();

public slots:
	void SelectMethod();//������Ϣѡ��ť����
	void SelectColor();			//��ɫѡ��
	void SelectTexture();		//����ѡ��
	void OnBnClicked_Ok();		//ȷ��

private:
	MaterialSetInfoStr	m_materialInfo;	//���ʲ���
	QColor m_color;
	
	Ui::S3d_SetMaterialInfoDialog ui;
};
