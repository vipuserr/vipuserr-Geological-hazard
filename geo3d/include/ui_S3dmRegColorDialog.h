/********************************************************************************
** Form generated from reading UI file 'S3dmRegColorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMREGCOLORDIALOG_H
#define UI_S3DMREGCOLORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_S3dmRegColorDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lable_Color;
    QPushButton *pButton_Color;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Opacity;
    QSlider *horizontalSlider;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Fillstyle;
    QComboBox *CBox_Fillstyle;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Bordercolor;
    QPushButton *pButton_Bordercolor;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Borderstyle;
    QComboBox *CBox_Borderstyle;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Borderwidth;
    QDoubleSpinBox *dSBox_Borderwidth;
    QComboBox *CBox_Borderwidthunit;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Apply;

    void setupUi(QWidget *S3dmRegColorDialog)
    {
        if (S3dmRegColorDialog->objectName().isEmpty())
            S3dmRegColorDialog->setObjectName(QStringLiteral("S3dmRegColorDialog"));
        S3dmRegColorDialog->resize(254, 300);
        gridLayout = new QGridLayout(S3dmRegColorDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lable_Color = new QLabel(S3dmRegColorDialog);
        lable_Color->setObjectName(QStringLiteral("lable_Color"));

        horizontalLayout_2->addWidget(lable_Color);

        pButton_Color = new QPushButton(S3dmRegColorDialog);
        pButton_Color->setObjectName(QStringLiteral("pButton_Color"));

        horizontalLayout_2->addWidget(pButton_Color);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 7);

        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Opacity = new QLabel(S3dmRegColorDialog);
        label_Opacity->setObjectName(QStringLiteral("label_Opacity"));

        horizontalLayout->addWidget(label_Opacity);

        horizontalSlider = new QSlider(S3dmRegColorDialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        doubleSpinBox = new QDoubleSpinBox(S3dmRegColorDialog);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        horizontalLayout->addWidget(doubleSpinBox);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Fillstyle = new QLabel(S3dmRegColorDialog);
        label_Fillstyle->setObjectName(QStringLiteral("label_Fillstyle"));

        horizontalLayout_3->addWidget(label_Fillstyle);

        CBox_Fillstyle = new QComboBox(S3dmRegColorDialog);
        CBox_Fillstyle->setObjectName(QStringLiteral("CBox_Fillstyle"));

        horizontalLayout_3->addWidget(CBox_Fillstyle);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 7);

        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_Bordercolor = new QLabel(S3dmRegColorDialog);
        label_Bordercolor->setObjectName(QStringLiteral("label_Bordercolor"));

        horizontalLayout_4->addWidget(label_Bordercolor);

        pButton_Bordercolor = new QPushButton(S3dmRegColorDialog);
        pButton_Bordercolor->setObjectName(QStringLiteral("pButton_Bordercolor"));

        horizontalLayout_4->addWidget(pButton_Bordercolor);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 7);

        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_Borderstyle = new QLabel(S3dmRegColorDialog);
        label_Borderstyle->setObjectName(QStringLiteral("label_Borderstyle"));

        horizontalLayout_5->addWidget(label_Borderstyle);

        CBox_Borderstyle = new QComboBox(S3dmRegColorDialog);
        CBox_Borderstyle->setObjectName(QStringLiteral("CBox_Borderstyle"));

        horizontalLayout_5->addWidget(CBox_Borderstyle);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 7);

        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_Borderwidth = new QLabel(S3dmRegColorDialog);
        label_Borderwidth->setObjectName(QStringLiteral("label_Borderwidth"));

        horizontalLayout_6->addWidget(label_Borderwidth);

        dSBox_Borderwidth = new QDoubleSpinBox(S3dmRegColorDialog);
        dSBox_Borderwidth->setObjectName(QStringLiteral("dSBox_Borderwidth"));

        horizontalLayout_6->addWidget(dSBox_Borderwidth);

        CBox_Borderwidthunit = new QComboBox(S3dmRegColorDialog);
        CBox_Borderwidthunit->setObjectName(QStringLiteral("CBox_Borderwidthunit"));

        horizontalLayout_6->addWidget(CBox_Borderwidthunit);

        horizontalLayout_6->setStretch(0, 3);
        horizontalLayout_6->setStretch(1, 3);
        horizontalLayout_6->setStretch(2, 4);

        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_Cancel = new QPushButton(S3dmRegColorDialog);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout_7->addWidget(pushButton_Cancel);

        pushButton_Apply = new QPushButton(S3dmRegColorDialog);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout_7->addWidget(pushButton_Apply);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        gridLayout->addLayout(horizontalLayout_8, 6, 0, 1, 1);


        retranslateUi(S3dmRegColorDialog);

        QMetaObject::connectSlotsByName(S3dmRegColorDialog);
    } // setupUi

    void retranslateUi(QWidget *S3dmRegColorDialog)
    {
        S3dmRegColorDialog->setWindowTitle(QApplication::translate("S3dmRegColorDialog", "S3dmRegColorDialog", nullptr));
        lable_Color->setText(QApplication::translate("S3dmRegColorDialog", "\351\242\234\350\211\262", nullptr));
        pButton_Color->setText(QString());
        label_Opacity->setText(QApplication::translate("S3dmRegColorDialog", "\351\200\217\346\230\216\345\272\246", nullptr));
        label_Fillstyle->setText(QApplication::translate("S3dmRegColorDialog", "\345\241\253\345\205\205\346\240\267\345\274\217", nullptr));
        label_Bordercolor->setText(QApplication::translate("S3dmRegColorDialog", "\350\276\271\346\241\206\351\242\234\350\211\262", nullptr));
        pButton_Bordercolor->setText(QString());
        label_Borderstyle->setText(QApplication::translate("S3dmRegColorDialog", "\350\276\271\346\241\206\346\240\267\345\274\217", nullptr));
        label_Borderwidth->setText(QApplication::translate("S3dmRegColorDialog", "\350\276\271\346\241\206\345\256\275\345\272\246", nullptr));
        pushButton_Cancel->setText(QApplication::translate("S3dmRegColorDialog", "\345\217\226\346\266\210", nullptr));
        pushButton_Apply->setText(QApplication::translate("S3dmRegColorDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmRegColorDialog: public Ui_S3dmRegColorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMREGCOLORDIALOG_H
