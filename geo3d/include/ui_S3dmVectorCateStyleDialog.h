/********************************************************************************
** Form generated from reading UI file 'S3dmVectorCateStyleDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMVECTORCATESTYLEDIALOG_H
#define UI_S3DMVECTORCATESTYLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscolorrampbutton.h"
#include "s3dmstyletablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_S3dmVectorCateStyleDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *FieldValue;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QPushButton *PatternName;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_2;
    QgsColorRampButton *toolButton;
    S3dmStyleCateTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *cateButton;
    QPushButton *addCate;
    QPushButton *removeCate;
    QPushButton *removeAllCate;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *apply;
    QPushButton *ok;

    void setupUi(QDialog *S3dmVectorCateStyleDialog)
    {
        if (S3dmVectorCateStyleDialog->objectName().isEmpty())
            S3dmVectorCateStyleDialog->setObjectName(QStringLiteral("S3dmVectorCateStyleDialog"));
        S3dmVectorCateStyleDialog->resize(476, 428);
        verticalLayout_3 = new QVBoxLayout(S3dmVectorCateStyleDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget = new QWidget(S3dmVectorCateStyleDialog);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(140, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        FieldValue = new QComboBox(groupBox);
        FieldValue->setObjectName(QStringLiteral("FieldValue"));
        FieldValue->setMinimumSize(QSize(24, 24));
        FieldValue->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(FieldValue);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 2, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 24));
        pushButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_6->addWidget(pushButton);

        PatternName = new QPushButton(groupBox_2);
        PatternName->setObjectName(QStringLiteral("PatternName"));
        PatternName->setMinimumSize(QSize(0, 24));
        PatternName->setMaximumSize(QSize(16777215, 24));

        horizontalLayout_6->addWidget(PatternName);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 24));
        pushButton_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_7->addWidget(pushButton_2);

        toolButton = new QgsColorRampButton(groupBox_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setMinimumSize(QSize(0, 24));

        horizontalLayout_7->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_3->addWidget(widget);

        tableWidget = new S3dmStyleCateTableWidget(S3dmVectorCateStyleDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_3->addWidget(tableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cateButton = new QPushButton(S3dmVectorCateStyleDialog);
        cateButton->setObjectName(QStringLiteral("cateButton"));

        horizontalLayout_4->addWidget(cateButton);

        addCate = new QPushButton(S3dmVectorCateStyleDialog);
        addCate->setObjectName(QStringLiteral("addCate"));
        addCate->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_4->addWidget(addCate);

        removeCate = new QPushButton(S3dmVectorCateStyleDialog);
        removeCate->setObjectName(QStringLiteral("removeCate"));
        removeCate->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_4->addWidget(removeCate);

        removeAllCate = new QPushButton(S3dmVectorCateStyleDialog);
        removeAllCate->setObjectName(QStringLiteral("removeAllCate"));

        horizontalLayout_4->addWidget(removeAllCate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        apply = new QPushButton(S3dmVectorCateStyleDialog);
        apply->setObjectName(QStringLiteral("apply"));

        horizontalLayout_5->addWidget(apply);

        ok = new QPushButton(S3dmVectorCateStyleDialog);
        ok->setObjectName(QStringLiteral("ok"));

        horizontalLayout_5->addWidget(ok);


        verticalLayout_3->addLayout(horizontalLayout_5);


        retranslateUi(S3dmVectorCateStyleDialog);

        QMetaObject::connectSlotsByName(S3dmVectorCateStyleDialog);
    } // setupUi

    void retranslateUi(QDialog *S3dmVectorCateStyleDialog)
    {
        S3dmVectorCateStyleDialog->setWindowTitle(QApplication::translate("S3dmVectorCateStyleDialog", "\347\237\242\351\207\217\345\210\206\347\261\273\346\240\267\345\274\217", nullptr));
        groupBox->setTitle(QApplication::translate("S3dmVectorCateStyleDialog", "\345\200\274\345\255\227\346\256\265", nullptr));
        groupBox_2->setTitle(QApplication::translate("S3dmVectorCateStyleDialog", "\347\254\246\345\217\267", nullptr));
        pushButton->setText(QApplication::translate("S3dmVectorCateStyleDialog", "\347\254\246\345\217\267", nullptr));
        PatternName->setText(QString());
        pushButton_2->setText(QApplication::translate("S3dmVectorCateStyleDialog", "\351\242\234\350\211\262", nullptr));
        toolButton->setText(QApplication::translate("S3dmVectorCateStyleDialog", "...", nullptr));
        cateButton->setText(QApplication::translate("S3dmVectorCateStyleDialog", "\345\210\206\347\261\273", nullptr));
        addCate->setText(QApplication::translate("S3dmVectorCateStyleDialog", "+", nullptr));
        removeCate->setText(QApplication::translate("S3dmVectorCateStyleDialog", "-", nullptr));
        removeAllCate->setText(QApplication::translate("S3dmVectorCateStyleDialog", "\345\205\250\351\203\250\345\210\240\351\231\244", nullptr));
        apply->setText(QApplication::translate("S3dmVectorCateStyleDialog", "\345\272\224\347\224\250", nullptr));
        ok->setText(QApplication::translate("S3dmVectorCateStyleDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmVectorCateStyleDialog: public Ui_S3dmVectorCateStyleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMVECTORCATESTYLEDIALOG_H
