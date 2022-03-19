#pragma once
#include "corecrt_math_defines.h"
#include "OGGeo3dMsgIDDef.h"
#include "qgsvectorlayer.h"
#include "ProjectManager.h"
#include "qgsmapcanvas.h"
#include "Gm_MathDef.h"
#include "qdialog.h"
#include "qobject.h"
#include "ui_MapFieldDialog.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include "FieldStructDef.h"

#include "OGMessageListener.h"
#include "G2DToolDef.h"
#include "OGGeo3dMsgIDDef.h"
#include "Gm_MathDef.h"

#include "qgssymbollayer.h"
#include <qgsvectorlayerrenderer.h>
#include <qgsrendercontext.h>


#include "gmKernelAppDef.h"

using namespace G2D;
class GM_KERNEL_APP_EXP AddMapFeature:public QObject, public COGListener
{
private:
	AddMapFeature();
	~AddMapFeature();
public:
	static AddMapFeature* getSingletonPtr();
public:
	virtual void registerIntMsg();
	long OnMessagePro(long nMsg, WPARAM wParam, LPARAM lParam);

	void addRegFeature(RegList regList, QgsVectorLayer* vec);
	void addLineFeature(LinList LinList, QgsVectorLayer* vec);
	void addPntFeature(G2D_DOT dot, QgsVectorLayer* vec);

	void initUI();
	void initUIByType();
	void drawPnt(QgsVectorLayer* vec, string shpFilePath, int shpType);
	void drawLine(QgsVectorLayer* vec, string shpFilePath, int shpType);
	void drawReg(QgsVectorLayer* vec,string shpFilePath, int shpType);
public slots:
	void ClickOKButton();
	void ClickCancelButton();

private:
	G2D::G2DTOOL_PARAM_STRUCT mToolParam;//交互工具
	string m_shpFilePath;
	QgsVectorLayer* m_vectorLayer;
	std::string mStdCode;//地层编码，上层编码
	std::string mDWStdCode;//下层编码
	std::string mOriDir;//倾向
	std::string mOriDip;//倾角
	bool mPolarityRreversal;//极性反转
	//bool mIsLine;
	bool m_IsSave;
	int mShpType;
	Ui::MapFieldDialog ui;
	QDialog mWidget;
	//地层编码，上层编码
	QWidget *mFormLayoutWidget;
	QFormLayout *mFormLayoutup;
	QLabel *mLabel_upcode;
	QComboBox *mComboBox_STRAT_CODE;

	//下层编码
	QWidget *mFormLayoutWidgetDW;
	QFormLayout *mFormLayoutDW;
	QLabel *mLabel_dwcode;
	QComboBox *mComboBox_STRAT_DWCODE;

	//产状点
	QWidget *mFormLayoutWidgetOri;
	QFormLayout *mFormLayoutOri;
	QLabel *mLabelDir;
	QLineEdit *mLineEditDir;
	QLabel *mLabelDip;
	QLineEdit *mLineEditDip;
	QCheckBox *mCheckBoxPlo;

	//ok,cancel按钮
	QWidget *mHorizontalLayoutWidget;
	QHBoxLayout *mHorizontalLayout_button;
	QPushButton *mPushButton_OK;
	QPushButton *mPushButton_Cancel;
	
};


