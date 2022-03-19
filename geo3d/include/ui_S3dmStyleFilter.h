/********************************************************************************
** Form generated from reading UI file 'S3dmStyleFilter.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMSTYLEFILTER_H
#define UI_S3DMSTYLEFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_S3dmStyleFilter
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_10;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *S3dmStyleFilter)
    {
        if (S3dmStyleFilter->objectName().isEmpty())
            S3dmStyleFilter->setObjectName(QStringLiteral("S3dmStyleFilter"));
        S3dmStyleFilter->resize(616, 434);
        verticalLayout_6 = new QVBoxLayout(S3dmStyleFilter);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(S3dmStyleFilter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(260, 16777215));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(40, 16777215));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout_4->addLayout(horizontalLayout_2);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(260, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, -1, 5);
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);


        verticalLayout_4->addWidget(groupBox_2);

        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(260, 16777215));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 5, -1, 5);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout->addWidget(pushButton_10);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton_7);


        verticalLayout_4->addWidget(widget);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_2 = new QTableWidget(groupBox_4);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setMaximumSize(QSize(167775, 140));

        verticalLayout->addWidget(tableWidget_2);


        verticalLayout_4->addWidget(groupBox_4);


        horizontalLayout_3->addWidget(groupBox);

        widget_2 = new QWidget(S3dmStyleFilter);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_2);

        pushButton_9 = new QPushButton(widget_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 40));
        pushButton_9->setMaximumSize(QSize(26, 16777215));

        verticalLayout_5->addWidget(pushButton_9);

        pushButton_8 = new QPushButton(widget_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 40));
        pushButton_8->setMaximumSize(QSize(26, 16777215));

        verticalLayout_5->addWidget(pushButton_8);

        verticalSpacer = new QSpacerItem(20, 216, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(widget_2);

        groupBox_3 = new QGroupBox(S3dmStyleFilter);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(280, 0));
        groupBox_3->setMaximumSize(QSize(280, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, -1, 5);
        tableWidget = new QTableWidget(groupBox_3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_3->addWidget(tableWidget);


        horizontalLayout_3->addWidget(groupBox_3);


        verticalLayout_6->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(S3dmStyleFilter);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_6->addWidget(buttonBox);


        retranslateUi(S3dmStyleFilter);

        QMetaObject::connectSlotsByName(S3dmStyleFilter);
    } // setupUi

    void retranslateUi(QWidget *S3dmStyleFilter)
    {
        S3dmStyleFilter->setWindowTitle(QApplication::translate("S3dmStyleFilter", "\346\240\271\346\215\256\345\261\236\346\200\247\350\256\276\346\240\267\345\274\217", nullptr));
        groupBox->setTitle(QApplication::translate("S3dmStyleFilter", "\346\235\241\344\273\266", nullptr));
        label->setText(QApplication::translate("S3dmStyleFilter", "\350\241\250\345\220\215\357\274\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("S3dmStyleFilter", "where\346\235\241\344\273\266\350\241\250\350\276\276\345\274\217", nullptr));
        textEdit->setHtml(QApplication::translate("S3dmStyleFilter", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;PntId&quot; &gt;10</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("S3dmStyleFilter", ">=", nullptr));
        pushButton_2->setText(QApplication::translate("S3dmStyleFilter", ">", nullptr));
        pushButton_3->setText(QApplication::translate("S3dmStyleFilter", "<", nullptr));
        pushButton_4->setText(QApplication::translate("S3dmStyleFilter", "<=", nullptr));
        pushButton_5->setText(QApplication::translate("S3dmStyleFilter", "=", nullptr));
        pushButton_10->setText(QApplication::translate("S3dmStyleFilter", "!=", nullptr));
        pushButton_6->setText(QApplication::translate("S3dmStyleFilter", "and", nullptr));
        pushButton_7->setText(QApplication::translate("S3dmStyleFilter", "or", nullptr));
        groupBox_4->setTitle(QApplication::translate("S3dmStyleFilter", "\345\255\227\346\256\265\345\220\215\347\247\260", nullptr));
        pushButton_9->setText(QApplication::translate("S3dmStyleFilter", "\343\200\213", nullptr));
        pushButton_8->setText(QApplication::translate("S3dmStyleFilter", "\343\200\212", nullptr));
        groupBox_3->setTitle(QApplication::translate("S3dmStyleFilter", "\345\267\262\350\256\276\347\275\256\346\240\267\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmStyleFilter: public Ui_S3dmStyleFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMSTYLEFILTER_H
