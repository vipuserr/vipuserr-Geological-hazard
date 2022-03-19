/********************************************************************************
** Form generated from reading UI file 'S3dmVectorCateStyle.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMVECTORCATESTYLE_H
#define UI_S3DMVECTORCATESTYLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "s3dmstyletablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_S3dmVectorCateStyle
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *FieldValue;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *PatternName;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QComboBox *patternColor;
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

    void setupUi(QDialog *S3dmVectorCateStyle)
    {
        if (S3dmVectorCateStyle->objectName().isEmpty())
            S3dmVectorCateStyle->setObjectName(QStringLiteral("S3dmVectorCateStyle"));
        S3dmVectorCateStyle->resize(463, 390);
        gridLayout = new QGridLayout(S3dmVectorCateStyle);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(S3dmVectorCateStyle);
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

        groupBox_2 = new QGroupBox(S3dmVectorCateStyle);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 24));
        pushButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(pushButton);

        PatternName = new QPushButton(groupBox_2);
        PatternName->setObjectName(QStringLiteral("PatternName"));
        PatternName->setMinimumSize(QSize(0, 24));

        horizontalLayout->addWidget(PatternName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 24));
        pushButton_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(pushButton_2);

        patternColor = new QComboBox(groupBox_2);
        patternColor->setObjectName(QStringLiteral("patternColor"));
        patternColor->setMinimumSize(QSize(0, 24));

        horizontalLayout_2->addWidget(patternColor);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tableWidget = new S3dmStyleCateTableWidget(S3dmVectorCateStyle);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_3->addWidget(tableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cateButton = new QPushButton(S3dmVectorCateStyle);
        cateButton->setObjectName(QStringLiteral("cateButton"));

        horizontalLayout_4->addWidget(cateButton);

        addCate = new QPushButton(S3dmVectorCateStyle);
        addCate->setObjectName(QStringLiteral("addCate"));
        addCate->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_4->addWidget(addCate);

        removeCate = new QPushButton(S3dmVectorCateStyle);
        removeCate->setObjectName(QStringLiteral("removeCate"));
        removeCate->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_4->addWidget(removeCate);

        removeAllCate = new QPushButton(S3dmVectorCateStyle);
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

        apply = new QPushButton(S3dmVectorCateStyle);
        apply->setObjectName(QStringLiteral("apply"));

        horizontalLayout_5->addWidget(apply);

        ok = new QPushButton(S3dmVectorCateStyle);
        ok->setObjectName(QStringLiteral("ok"));

        horizontalLayout_5->addWidget(ok);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(S3dmVectorCateStyle);

        QMetaObject::connectSlotsByName(S3dmVectorCateStyle);
    } // setupUi

    void retranslateUi(QDialog *S3dmVectorCateStyle)
    {
        S3dmVectorCateStyle->setWindowTitle(QApplication::translate("S3dmVectorCateStyle", "\347\237\242\351\207\217\345\210\206\347\261\273\346\240\267\345\274\217", nullptr));
        groupBox->setTitle(QApplication::translate("S3dmVectorCateStyle", "\345\200\274\345\255\227\346\256\265", nullptr));
        groupBox_2->setTitle(QApplication::translate("S3dmVectorCateStyle", "\347\254\246\345\217\267", nullptr));
        pushButton->setText(QApplication::translate("S3dmVectorCateStyle", "\347\254\246\345\217\267", nullptr));
        PatternName->setText(QString());
        pushButton_2->setText(QApplication::translate("S3dmVectorCateStyle", "\351\242\234\350\211\262", nullptr));
        cateButton->setText(QApplication::translate("S3dmVectorCateStyle", "\345\210\206\347\261\273", nullptr));
        addCate->setText(QApplication::translate("S3dmVectorCateStyle", "+", nullptr));
        removeCate->setText(QApplication::translate("S3dmVectorCateStyle", "-", nullptr));
        removeAllCate->setText(QApplication::translate("S3dmVectorCateStyle", "\345\205\250\351\203\250\345\210\240\351\231\244", nullptr));
        apply->setText(QApplication::translate("S3dmVectorCateStyle", "\345\272\224\347\224\250", nullptr));
        ok->setText(QApplication::translate("S3dmVectorCateStyle", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmVectorCateStyle: public Ui_S3dmVectorCateStyle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMVECTORCATESTYLE_H
