/********************************************************************************
** Form generated from reading UI file 'S3dmLabelSelector.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMLABELSELECTOR_H
#define UI_S3DMLABELSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "simplelabelattrwidget.h"

QT_BEGIN_NAMESPACE

class Ui_S3dmLabelSelector
{
public:
    QGridLayout *gridLayout;
    QLabel *label_label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    SimpleLabelAttrWidget *widget;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget;
    QPushButton *pushButton_add;
    QPushButton *pushButton_del;
    QPushButton *pushButton_edit;
    QRadioButton *rButton_Hide;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Ok;
    QComboBox *CBox_label;

    void setupUi(QDialog *S3dmLabelSelector)
    {
        if (S3dmLabelSelector->objectName().isEmpty())
            S3dmLabelSelector->setObjectName(QStringLiteral("S3dmLabelSelector"));
        S3dmLabelSelector->resize(329, 372);
        gridLayout = new QGridLayout(S3dmLabelSelector);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_label = new QLabel(S3dmLabelSelector);
        label_label->setObjectName(QStringLiteral("label_label"));

        gridLayout->addWidget(label_label, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(S3dmLabelSelector);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new SimpleLabelAttrWidget(page);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget = new QTableWidget(page_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_3->addWidget(tableWidget, 0, 0, 1, 3);

        pushButton_add = new QPushButton(page_2);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        gridLayout_3->addWidget(pushButton_add, 1, 0, 1, 1);

        pushButton_del = new QPushButton(page_2);
        pushButton_del->setObjectName(QStringLiteral("pushButton_del"));

        gridLayout_3->addWidget(pushButton_del, 1, 1, 1, 1);

        pushButton_edit = new QPushButton(page_2);
        pushButton_edit->setObjectName(QStringLiteral("pushButton_edit"));

        gridLayout_3->addWidget(pushButton_edit, 1, 2, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 4);

        rButton_Hide = new QRadioButton(S3dmLabelSelector);
        rButton_Hide->setObjectName(QStringLiteral("rButton_Hide"));

        gridLayout->addWidget(rButton_Hide, 2, 0, 1, 2);

        pushButton_Apply = new QPushButton(S3dmLabelSelector);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        gridLayout->addWidget(pushButton_Apply, 3, 2, 1, 1);

        pushButton_Ok = new QPushButton(S3dmLabelSelector);
        pushButton_Ok->setObjectName(QStringLiteral("pushButton_Ok"));

        gridLayout->addWidget(pushButton_Ok, 3, 3, 1, 1);

        CBox_label = new QComboBox(S3dmLabelSelector);
        CBox_label->setObjectName(QStringLiteral("CBox_label"));

        gridLayout->addWidget(CBox_label, 0, 1, 1, 3);


        retranslateUi(S3dmLabelSelector);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(S3dmLabelSelector);
    } // setupUi

    void retranslateUi(QDialog *S3dmLabelSelector)
    {
        S3dmLabelSelector->setWindowTitle(QApplication::translate("S3dmLabelSelector", "\346\240\207\346\263\250", nullptr));
        label_label->setText(QApplication::translate("S3dmLabelSelector", "\346\263\250\350\256\260\350\247\204\345\210\231", nullptr));
        pushButton_add->setText(QApplication::translate("S3dmLabelSelector", "+", nullptr));
        pushButton_del->setText(QApplication::translate("S3dmLabelSelector", "-", nullptr));
        pushButton_edit->setText(QApplication::translate("S3dmLabelSelector", "\347\274\226\350\276\221", nullptr));
        rButton_Hide->setText(QApplication::translate("S3dmLabelSelector", "\346\230\257\345\220\246\351\232\220\350\227\217\346\263\250\350\256\260", nullptr));
        pushButton_Apply->setText(QApplication::translate("S3dmLabelSelector", "\345\272\224\347\224\250", nullptr));
        pushButton_Ok->setText(QApplication::translate("S3dmLabelSelector", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmLabelSelector: public Ui_S3dmLabelSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMLABELSELECTOR_H
