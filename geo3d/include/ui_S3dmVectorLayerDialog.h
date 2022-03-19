/********************************************************************************
** Form generated from reading UI file 'S3dmVectorLayerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMVECTORLAYERDIALOG_H
#define UI_S3DMVECTORLAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include "s3dmvectorcatestyledialog.h"
#include "s3dmvectorclassstyledialog.h"

QT_BEGIN_NAMESPACE

class Ui_S3dmVectorLayerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QTabWidget *tabWidget;
    S3dmVectorCateStyleDialog *cateWidget;
    S3dmVectorClassStyleDialog *classWidget;

    void setupUi(QDialog *S3dmVectorLayerDialog)
    {
        if (S3dmVectorLayerDialog->objectName().isEmpty())
            S3dmVectorLayerDialog->setObjectName(QStringLiteral("S3dmVectorLayerDialog"));
        S3dmVectorLayerDialog->resize(648, 660);
        verticalLayout = new QVBoxLayout(S3dmVectorLayerDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(S3dmVectorLayerDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        tabWidget = new QTabWidget(S3dmVectorLayerDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        cateWidget = new S3dmVectorCateStyleDialog();
        cateWidget->setObjectName(QStringLiteral("cateWidget"));
        tabWidget->addTab(cateWidget, QString());
        classWidget = new S3dmVectorClassStyleDialog();
        classWidget->setObjectName(QStringLiteral("classWidget"));
        tabWidget->addTab(classWidget, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(S3dmVectorLayerDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(S3dmVectorLayerDialog);
    } // setupUi

    void retranslateUi(QDialog *S3dmVectorLayerDialog)
    {
        S3dmVectorLayerDialog->setWindowTitle(QApplication::translate("S3dmVectorLayerDialog", "S3dmVectorLayerDialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cateWidget), QApplication::translate("S3dmVectorLayerDialog", "\345\210\206\347\261\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(classWidget), QApplication::translate("S3dmVectorLayerDialog", "\345\210\206\347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmVectorLayerDialog: public Ui_S3dmVectorLayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMVECTORLAYERDIALOG_H
