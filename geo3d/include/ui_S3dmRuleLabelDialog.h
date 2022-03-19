/********************************************************************************
** Form generated from reading UI file 'S3dmRuleLabelDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMRULELABELDIALOG_H
#define UI_S3DMRULELABELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include "simplelabelattrwidget.h"

QT_BEGIN_NAMESPACE

class Ui_S3dmRuleLableDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_filterField;
    QComboBox *CBox_filterField;
    QLabel *label_WrapChar_4;
    QLineEdit *lineEdit_filterValue;
    SimpleLabelAttrWidget *slWidget;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Apply;

    void setupUi(QDialog *S3dmRuleLableDialog)
    {
        if (S3dmRuleLableDialog->objectName().isEmpty())
            S3dmRuleLableDialog->setObjectName(QStringLiteral("S3dmRuleLableDialog"));
        S3dmRuleLableDialog->resize(301, 355);
        gridLayout = new QGridLayout(S3dmRuleLableDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_filterField = new QLabel(S3dmRuleLableDialog);
        label_filterField->setObjectName(QStringLiteral("label_filterField"));

        gridLayout->addWidget(label_filterField, 0, 0, 1, 1);

        CBox_filterField = new QComboBox(S3dmRuleLableDialog);
        CBox_filterField->setObjectName(QStringLiteral("CBox_filterField"));

        gridLayout->addWidget(CBox_filterField, 0, 1, 1, 2);

        label_WrapChar_4 = new QLabel(S3dmRuleLableDialog);
        label_WrapChar_4->setObjectName(QStringLiteral("label_WrapChar_4"));

        gridLayout->addWidget(label_WrapChar_4, 1, 0, 1, 1);

        lineEdit_filterValue = new QLineEdit(S3dmRuleLableDialog);
        lineEdit_filterValue->setObjectName(QStringLiteral("lineEdit_filterValue"));
        lineEdit_filterValue->setMaximumSize(QSize(10707215, 16777215));
        lineEdit_filterValue->setAcceptDrops(true);

        gridLayout->addWidget(lineEdit_filterValue, 1, 1, 1, 2);

        slWidget = new SimpleLabelAttrWidget(S3dmRuleLableDialog);
        slWidget->setObjectName(QStringLiteral("slWidget"));

        gridLayout->addWidget(slWidget, 2, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 2);

        pushButton_Apply = new QPushButton(S3dmRuleLableDialog);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        gridLayout->addWidget(pushButton_Apply, 3, 2, 1, 1);


        retranslateUi(S3dmRuleLableDialog);

        QMetaObject::connectSlotsByName(S3dmRuleLableDialog);
    } // setupUi

    void retranslateUi(QDialog *S3dmRuleLableDialog)
    {
        S3dmRuleLableDialog->setWindowTitle(QApplication::translate("S3dmRuleLableDialog", "\347\274\226\350\276\221\350\247\204\345\210\231", nullptr));
        label_filterField->setText(QApplication::translate("S3dmRuleLableDialog", "\350\277\207\346\273\244\345\255\227\346\256\265", nullptr));
        label_WrapChar_4->setText(QApplication::translate("S3dmRuleLableDialog", "\350\277\207\346\273\244\345\200\274", nullptr));
        pushButton_Apply->setText(QApplication::translate("S3dmRuleLableDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmRuleLableDialog: public Ui_S3dmRuleLableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMRULELABELDIALOG_H
