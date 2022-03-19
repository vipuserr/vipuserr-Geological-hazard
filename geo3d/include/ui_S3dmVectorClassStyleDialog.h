/********************************************************************************
** Form generated from reading UI file 'S3dmVectorClassStyleDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMVECTORCLASSSTYLEDIALOG_H
#define UI_S3DMVECTORCLASSSTYLEDIALOG_H

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
#include "s3dmStyleTableWidget.h"

QT_BEGIN_NAMESPACE

class Ui_S3dmVectorClassStyleDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QComboBox *fieldVal;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *patternPtn;
    QPushButton *patternName;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *colorPtn;
    QgsColorRampButton *colorName;
    S3dmStyleCateTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *classPtn;
    QPushButton *addPtn;
    QPushButton *removePtn;
    QPushButton *removeAllPtn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *applyPtn;
    QPushButton *okPtn;

    void setupUi(QDialog *S3dmVectorClassStyleDialog)
    {
        if (S3dmVectorClassStyleDialog->objectName().isEmpty())
            S3dmVectorClassStyleDialog->setObjectName(QStringLiteral("S3dmVectorClassStyleDialog"));
        S3dmVectorClassStyleDialog->resize(471, 468);
        verticalLayout_3 = new QVBoxLayout(S3dmVectorClassStyleDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget = new QWidget(S3dmVectorClassStyleDialog);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(140, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        fieldVal = new QComboBox(groupBox);
        fieldVal->setObjectName(QStringLiteral("fieldVal"));
        fieldVal->setMinimumSize(QSize(24, 24));
        fieldVal->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(fieldVal);


        horizontalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 2, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        patternPtn = new QPushButton(groupBox_2);
        patternPtn->setObjectName(QStringLiteral("patternPtn"));
        patternPtn->setMinimumSize(QSize(0, 24));
        patternPtn->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(patternPtn);

        patternName = new QPushButton(groupBox_2);
        patternName->setObjectName(QStringLiteral("patternName"));
        patternName->setMinimumSize(QSize(0, 24));
        patternName->setMaximumSize(QSize(16777215, 24));

        horizontalLayout_3->addWidget(patternName);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        colorPtn = new QPushButton(groupBox_2);
        colorPtn->setObjectName(QStringLiteral("colorPtn"));
        colorPtn->setMinimumSize(QSize(0, 24));
        colorPtn->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(colorPtn);

        colorName = new QgsColorRampButton(groupBox_2);
        colorName->setObjectName(QStringLiteral("colorName"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorName->sizePolicy().hasHeightForWidth());
        colorName->setSizePolicy(sizePolicy);
        colorName->setMinimumSize(QSize(0, 24));

        horizontalLayout_4->addWidget(colorName);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(groupBox_2);


        verticalLayout_3->addWidget(widget);

        tableWidget = new S3dmStyleCateTableWidget(S3dmVectorClassStyleDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_3->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        classPtn = new QPushButton(S3dmVectorClassStyleDialog);
        classPtn->setObjectName(QStringLiteral("classPtn"));

        horizontalLayout->addWidget(classPtn);

        addPtn = new QPushButton(S3dmVectorClassStyleDialog);
        addPtn->setObjectName(QStringLiteral("addPtn"));
        addPtn->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(addPtn);

        removePtn = new QPushButton(S3dmVectorClassStyleDialog);
        removePtn->setObjectName(QStringLiteral("removePtn"));
        removePtn->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(removePtn);

        removeAllPtn = new QPushButton(S3dmVectorClassStyleDialog);
        removeAllPtn->setObjectName(QStringLiteral("removeAllPtn"));

        horizontalLayout->addWidget(removeAllPtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        applyPtn = new QPushButton(S3dmVectorClassStyleDialog);
        applyPtn->setObjectName(QStringLiteral("applyPtn"));

        horizontalLayout_2->addWidget(applyPtn);

        okPtn = new QPushButton(S3dmVectorClassStyleDialog);
        okPtn->setObjectName(QStringLiteral("okPtn"));

        horizontalLayout_2->addWidget(okPtn);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(S3dmVectorClassStyleDialog);

        QMetaObject::connectSlotsByName(S3dmVectorClassStyleDialog);
    } // setupUi

    void retranslateUi(QDialog *S3dmVectorClassStyleDialog)
    {
        S3dmVectorClassStyleDialog->setWindowTitle(QApplication::translate("S3dmVectorClassStyleDialog", "S3dmVectorClassStyleDialog", nullptr));
        groupBox->setTitle(QApplication::translate("S3dmVectorClassStyleDialog", "\345\200\274\345\255\227\346\256\265", nullptr));
        groupBox_2->setTitle(QApplication::translate("S3dmVectorClassStyleDialog", "\347\254\246\345\217\267", nullptr));
        patternPtn->setText(QApplication::translate("S3dmVectorClassStyleDialog", "\347\254\246\345\217\267", nullptr));
        patternName->setText(QString());
        colorPtn->setText(QApplication::translate("S3dmVectorClassStyleDialog", "\351\242\234\350\211\262", nullptr));
        colorName->setText(QApplication::translate("S3dmVectorClassStyleDialog", "...", nullptr));
        classPtn->setText(QApplication::translate("S3dmVectorClassStyleDialog", "\345\210\206\347\272\247", nullptr));
        addPtn->setText(QApplication::translate("S3dmVectorClassStyleDialog", "+", nullptr));
        removePtn->setText(QApplication::translate("S3dmVectorClassStyleDialog", "-", nullptr));
        removeAllPtn->setText(QApplication::translate("S3dmVectorClassStyleDialog", "\345\205\250\351\203\250\345\210\240\351\231\244", nullptr));
        applyPtn->setText(QApplication::translate("S3dmVectorClassStyleDialog", "\345\272\224\347\224\250", nullptr));
        okPtn->setText(QApplication::translate("S3dmVectorClassStyleDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmVectorClassStyleDialog: public Ui_S3dmVectorClassStyleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMVECTORCLASSSTYLEDIALOG_H
