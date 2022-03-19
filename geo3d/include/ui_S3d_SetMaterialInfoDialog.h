/********************************************************************************
** Form generated from reading UI file 'S3d_SetMaterialInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3D_SETMATERIALINFODIALOG_H
#define UI_S3D_SETMATERIALINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscolorrampbutton.h"

QT_BEGIN_NAMESPACE

class Ui_S3d_SetMaterialInfoDialog
{
public:
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *radioButton_Color;
    QRadioButton *radioButton_Texture;
    QRadioButton *radioButton_TableColor;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_SelectColor;
    QLineEdit *lineEdit_TexturePath;
    QgsColorRampButton *pushButton_SelectClrBanding;
    QLabel *label_23;
    QSpinBox *spinBox_LevelNum;
    QPushButton *pushButton_SelectTexture;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Sure;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *S3d_SetMaterialInfoDialog)
    {
        if (S3d_SetMaterialInfoDialog->objectName().isEmpty())
            S3d_SetMaterialInfoDialog->setObjectName(QStringLiteral("S3d_SetMaterialInfoDialog"));
        S3d_SetMaterialInfoDialog->resize(302, 203);
        groupBox_2 = new QGroupBox(S3d_SetMaterialInfoDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 281, 141));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 49, 111));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        radioButton_Color = new QRadioButton(layoutWidget_2);
        radioButton_Color->setObjectName(QStringLiteral("radioButton_Color"));
        radioButton_Color->setChecked(true);

        verticalLayout_10->addWidget(radioButton_Color);

        radioButton_Texture = new QRadioButton(layoutWidget_2);
        radioButton_Texture->setObjectName(QStringLiteral("radioButton_Texture"));
        radioButton_Texture->setEnabled(true);

        verticalLayout_10->addWidget(radioButton_Texture);

        radioButton_TableColor = new QRadioButton(layoutWidget_2);
        radioButton_TableColor->setObjectName(QStringLiteral("radioButton_TableColor"));
        radioButton_TableColor->setEnabled(true);

        verticalLayout_10->addWidget(radioButton_TableColor);

        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 20, 131, 112));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_SelectColor = new QPushButton(verticalLayoutWidget);
        pushButton_SelectColor->setObjectName(QStringLiteral("pushButton_SelectColor"));
        pushButton_SelectColor->setMinimumSize(QSize(0, 24));

        verticalLayout->addWidget(pushButton_SelectColor);

        lineEdit_TexturePath = new QLineEdit(verticalLayoutWidget);
        lineEdit_TexturePath->setObjectName(QStringLiteral("lineEdit_TexturePath"));
        lineEdit_TexturePath->setEnabled(false);

        verticalLayout->addWidget(lineEdit_TexturePath);

        pushButton_SelectClrBanding = new QgsColorRampButton(verticalLayoutWidget);
        pushButton_SelectClrBanding->setObjectName(QStringLiteral("pushButton_SelectClrBanding"));
        pushButton_SelectClrBanding->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_SelectClrBanding->sizePolicy().hasHeightForWidth());
        pushButton_SelectClrBanding->setSizePolicy(sizePolicy);
        pushButton_SelectClrBanding->setMinimumSize(QSize(0, 24));

        verticalLayout->addWidget(pushButton_SelectClrBanding);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(260, 100, 21, 21));
        spinBox_LevelNum = new QSpinBox(groupBox_2);
        spinBox_LevelNum->setObjectName(QStringLiteral("spinBox_LevelNum"));
        spinBox_LevelNum->setEnabled(false);
        spinBox_LevelNum->setGeometry(QRect(210, 100, 41, 21));
        spinBox_LevelNum->setValue(5);
        pushButton_SelectTexture = new QPushButton(groupBox_2);
        pushButton_SelectTexture->setObjectName(QStringLiteral("pushButton_SelectTexture"));
        pushButton_SelectTexture->setEnabled(false);
        pushButton_SelectTexture->setGeometry(QRect(210, 63, 41, 23));
        widget_5 = new QWidget(S3d_SetMaterialInfoDialog);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(10, 150, 281, 51));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(68, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pushButton_Sure = new QPushButton(widget_5);
        pushButton_Sure->setObjectName(QStringLiteral("pushButton_Sure"));

        horizontalLayout_5->addWidget(pushButton_Sure);

        pushButton_Cancel = new QPushButton(widget_5);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout_5->addWidget(pushButton_Cancel);


        retranslateUi(S3d_SetMaterialInfoDialog);

        QMetaObject::connectSlotsByName(S3d_SetMaterialInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *S3d_SetMaterialInfoDialog)
    {
        S3d_SetMaterialInfoDialog->setWindowTitle(QApplication::translate("S3d_SetMaterialInfoDialog", "\350\256\276\347\275\256\346\235\220\350\264\250\344\277\241\346\201\257", nullptr));
        groupBox_2->setTitle(QApplication::translate("S3d_SetMaterialInfoDialog", "\346\235\220\350\264\250\344\277\241\346\201\257", nullptr));
        radioButton_Color->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "\345\215\225\350\211\262", nullptr));
        radioButton_Texture->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "\347\272\271\347\220\206", nullptr));
        radioButton_TableColor->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "\350\211\262\350\241\250", nullptr));
        pushButton_SelectColor->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "...", nullptr));
        pushButton_SelectClrBanding->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "...", nullptr));
        label_23->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "\347\272\247", nullptr));
        pushButton_SelectTexture->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "...", nullptr));
        pushButton_Sure->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "\347\241\256\345\256\232", nullptr));
        pushButton_Cancel->setText(QApplication::translate("S3d_SetMaterialInfoDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3d_SetMaterialInfoDialog: public Ui_S3d_SetMaterialInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3D_SETMATERIALINFODIALOG_H
