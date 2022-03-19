/********************************************************************************
** Form generated from reading UI file 's3d_RenderSetDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3D_RENDERSETDIALOG_H
#define UI_S3D_RENDERSETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "qgscolorrampbutton.h"

QT_BEGIN_NAMESPACE

class Ui_s3d_RenderSetDialog
{
public:
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_41;
    QLineEdit *lineEdit_InvalidVal;
    QWidget *widget_15;
    QLabel *label_27;
    QgsColorRampButton *toolButton_ClrBanding;
    QWidget *widget_16;
    QLabel *label_38;
    QComboBox *comboBox_ClassMethod;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Sure;
    QPushButton *pushButton_Cancel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_40;
    QSpinBox *spinBox_Level;

    void setupUi(QDialog *s3d_RenderSetDialog)
    {
        if (s3d_RenderSetDialog->objectName().isEmpty())
            s3d_RenderSetDialog->setObjectName(QStringLiteral("s3d_RenderSetDialog"));
        s3d_RenderSetDialog->resize(283, 183);
        widget_2 = new QWidget(s3d_RenderSetDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(130, 90, 141, 38));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_41 = new QLabel(widget_2);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_4->addWidget(label_41);

        lineEdit_InvalidVal = new QLineEdit(widget_2);
        lineEdit_InvalidVal->setObjectName(QStringLiteral("lineEdit_InvalidVal"));
        lineEdit_InvalidVal->setEnabled(true);

        horizontalLayout_4->addWidget(lineEdit_InvalidVal);

        widget_15 = new QWidget(s3d_RenderSetDialog);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setGeometry(QRect(10, 10, 261, 40));
        label_27 = new QLabel(widget_15);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(9, 9, 60, 16));
        label_27->setMaximumSize(QSize(60, 16777215));
        toolButton_ClrBanding = new QgsColorRampButton(widget_15);
        toolButton_ClrBanding->setObjectName(QStringLiteral("toolButton_ClrBanding"));
        toolButton_ClrBanding->setGeometry(QRect(75, 5, 171, 25));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_ClrBanding->sizePolicy().hasHeightForWidth());
        toolButton_ClrBanding->setSizePolicy(sizePolicy);
        widget_16 = new QWidget(s3d_RenderSetDialog);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setGeometry(QRect(10, 50, 261, 41));
        label_38 = new QLabel(widget_16);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(9, 9, 60, 16));
        label_38->setMaximumSize(QSize(60, 16777215));
        comboBox_ClassMethod = new QComboBox(widget_16);
        comboBox_ClassMethod->setObjectName(QStringLiteral("comboBox_ClassMethod"));
        comboBox_ClassMethod->setGeometry(QRect(75, 6, 171, 25));
        widget_5 = new QWidget(s3d_RenderSetDialog);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(10, 130, 261, 51));
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

        widget = new QWidget(s3d_RenderSetDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 90, 121, 38));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_40 = new QLabel(widget);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(label_40);

        spinBox_Level = new QSpinBox(widget);
        spinBox_Level->setObjectName(QStringLiteral("spinBox_Level"));
        spinBox_Level->setMaximumSize(QSize(60, 16777215));
        spinBox_Level->setMinimum(2);
        spinBox_Level->setValue(5);

        horizontalLayout_3->addWidget(spinBox_Level);


        retranslateUi(s3d_RenderSetDialog);

        QMetaObject::connectSlotsByName(s3d_RenderSetDialog);
    } // setupUi

    void retranslateUi(QDialog *s3d_RenderSetDialog)
    {
        s3d_RenderSetDialog->setWindowTitle(QApplication::translate("s3d_RenderSetDialog", "\346\250\241\345\236\213\346\270\262\346\237\223\350\256\276\347\275\256", nullptr));
        label_41->setText(QApplication::translate("s3d_RenderSetDialog", "\346\227\240\346\225\210\345\200\274\357\274\232", nullptr));
        lineEdit_InvalidVal->setText(QApplication::translate("s3d_RenderSetDialog", "0.0", nullptr));
        label_27->setText(QApplication::translate("s3d_RenderSetDialog", "\345\210\206\347\272\247\350\256\276\350\211\262\357\274\232", nullptr));
        toolButton_ClrBanding->setText(QString());
        label_38->setText(QApplication::translate("s3d_RenderSetDialog", "\345\210\206\347\261\273\346\226\271\346\263\225\357\274\232", nullptr));
        pushButton_Sure->setText(QApplication::translate("s3d_RenderSetDialog", "\347\241\256\345\256\232", nullptr));
        pushButton_Cancel->setText(QApplication::translate("s3d_RenderSetDialog", "\345\217\226\346\266\210", nullptr));
        label_40->setText(QApplication::translate("s3d_RenderSetDialog", "\347\272\247\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class s3d_RenderSetDialog: public Ui_s3d_RenderSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3D_RENDERSETDIALOG_H
