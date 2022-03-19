#pragma once

#include "ui_S3d_SetMaterialInfoDialog.h"
#include "s3dmqgsdialog_global.h"


//设置材质信息
class S3DMQGSDIALOG_EXPORT S3d_SetMaterialInfoDialog : public QDialog
{
	Q_OBJECT

public:
	S3d_SetMaterialInfoDialog(QWidget *parent = Q_NULLPTR);
	~S3d_SetMaterialInfoDialog();

	//材质类型
	enum MatrialType
	{
		Color_Type		= 0,	//单色
		Texture_Type	= 1,	//纹理
		TableColor_Type = 2		//色带
	};

	//色带设置参数
	struct TableColorParaStr
	{
		QgsColorRamp *pColorRamp;	//色带
		int iClassfyLevel;			//分类级数

		TableColorParaStr() : pColorRamp(nullptr), iClassfyLevel(0)
		{
		}
	};

	//材质信息
	struct MaterialSetInfoStr
	{
		MatrialType			materialType;	//材质类型
		QColor				qColor;			//单色
		QString				qstrTexturePath;//纹理路径
		TableColorParaStr	tableColorPara;	//色带参数

		MaterialSetInfoStr() : materialType(Color_Type)
		{
		}
	};

	//获得当前界面设置
	MaterialSetInfoStr& GetMaterialInfo();

public slots:
	void SelectMethod();//材质信息选择按钮交互
	void SelectColor();			//单色选择
	void SelectTexture();		//纹理选择
	void OnBnClicked_Ok();		//确定

private:
	MaterialSetInfoStr	m_materialInfo;	//材质参数
	QColor m_color;
	
	Ui::S3d_SetMaterialInfoDialog ui;
};
