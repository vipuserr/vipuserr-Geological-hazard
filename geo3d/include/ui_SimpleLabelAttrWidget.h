/********************************************************************************
** Form generated from reading UI file 'SimpleLabelAttrWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLELABELATTRWIDGET_H
#define UI_SIMPLELABELATTRWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleLabelAttrWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Field;
    QComboBox *CBox_Field;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Size;
    QDoubleSpinBox *dSBox_Size;
    QComboBox *CBox_SizeUnit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Color;
    QPushButton *pButton_Color;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_Font;
    QPushButton *pButton_Font;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_setOffset;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Offset_x;
    QDoubleSpinBox *dSBox_Offset_x;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Offset_x_2;
    QDoubleSpinBox *dSBox_Offset_y;
    QComboBox *CBox_OffsetUnit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_WrapChar;
    QLineEdit *lineEdit_WrapChar;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_Orientation;
    QComboBox *CBox_Orientation;

    void setupUi(QWidget *SimpleLabelAttrWidget)
    {
        if (SimpleLabelAttrWidget->objectName().isEmpty())
            SimpleLabelAttrWidget->setObjectName(QStringLiteral("SimpleLabelAttrWidget"));
        SimpleLabelAttrWidget->resize(301, 275);
        gridLayout = new QGridLayout(SimpleLabelAttrWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_Field = new QLabel(SimpleLabelAttrWidget);
        label_Field->setObjectName(QStringLiteral("label_Field"));

        horizontalLayout_5->addWidget(label_Field);

        CBox_Field = new QComboBox(SimpleLabelAttrWidget);
        CBox_Field->setObjectName(QStringLiteral("CBox_Field"));

        horizontalLayout_5->addWidget(CBox_Field);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 6);

        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_Size = new QLabel(SimpleLabelAttrWidget);
        label_Size->setObjectName(QStringLiteral("label_Size"));

        horizontalLayout_4->addWidget(label_Size);

        dSBox_Size = new QDoubleSpinBox(SimpleLabelAttrWidget);
        dSBox_Size->setObjectName(QStringLiteral("dSBox_Size"));

        horizontalLayout_4->addWidget(dSBox_Size);

        CBox_SizeUnit = new QComboBox(SimpleLabelAttrWidget);
        CBox_SizeUnit->setObjectName(QStringLiteral("CBox_SizeUnit"));

        horizontalLayout_4->addWidget(CBox_SizeUnit);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_Color = new QLabel(SimpleLabelAttrWidget);
        label_Color->setObjectName(QStringLiteral("label_Color"));

        horizontalLayout_6->addWidget(label_Color);

        pButton_Color = new QPushButton(SimpleLabelAttrWidget);
        pButton_Color->setObjectName(QStringLiteral("pButton_Color"));

        horizontalLayout_6->addWidget(pButton_Color);

        horizontalLayout_6->setStretch(0, 3);
        horizontalLayout_6->setStretch(1, 6);

        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_Font = new QLabel(SimpleLabelAttrWidget);
        label_Font->setObjectName(QStringLiteral("label_Font"));

        horizontalLayout_7->addWidget(label_Font);

        pButton_Font = new QPushButton(SimpleLabelAttrWidget);
        pButton_Font->setObjectName(QStringLiteral("pButton_Font"));

        horizontalLayout_7->addWidget(pButton_Font);

        horizontalLayout_7->setStretch(0, 3);
        horizontalLayout_7->setStretch(1, 6);

        gridLayout->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_setOffset = new QLabel(SimpleLabelAttrWidget);
        label_setOffset->setObjectName(QStringLiteral("label_setOffset"));

        horizontalLayout_3->addWidget(label_setOffset);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Offset_x = new QLabel(SimpleLabelAttrWidget);
        label_Offset_x->setObjectName(QStringLiteral("label_Offset_x"));

        horizontalLayout->addWidget(label_Offset_x);

        dSBox_Offset_x = new QDoubleSpinBox(SimpleLabelAttrWidget);
        dSBox_Offset_x->setObjectName(QStringLiteral("dSBox_Offset_x"));

        horizontalLayout->addWidget(dSBox_Offset_x);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Offset_x_2 = new QLabel(SimpleLabelAttrWidget);
        label_Offset_x_2->setObjectName(QStringLiteral("label_Offset_x_2"));

        horizontalLayout_2->addWidget(label_Offset_x_2);

        dSBox_Offset_y = new QDoubleSpinBox(SimpleLabelAttrWidget);
        dSBox_Offset_y->setObjectName(QStringLiteral("dSBox_Offset_y"));

        horizontalLayout_2->addWidget(dSBox_Offset_y);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        CBox_OffsetUnit = new QComboBox(SimpleLabelAttrWidget);
        CBox_OffsetUnit->setObjectName(QStringLiteral("CBox_OffsetUnit"));
        CBox_OffsetUnit->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(CBox_OffsetUnit);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_WrapChar = new QLabel(SimpleLabelAttrWidget);
        label_WrapChar->setObjectName(QStringLiteral("label_WrapChar"));

        horizontalLayout_8->addWidget(label_WrapChar);

        lineEdit_WrapChar = new QLineEdit(SimpleLabelAttrWidget);
        lineEdit_WrapChar->setObjectName(QStringLiteral("lineEdit_WrapChar"));
        lineEdit_WrapChar->setMaximumSize(QSize(10707215, 16777215));
        lineEdit_WrapChar->setAcceptDrops(true);

        horizontalLayout_8->addWidget(lineEdit_WrapChar);

        horizontalLayout_8->setStretch(0, 3);
        horizontalLayout_8->setStretch(1, 6);

        gridLayout->addLayout(horizontalLayout_8, 5, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_Orientation = new QLabel(SimpleLabelAttrWidget);
        label_Orientation->setObjectName(QStringLiteral("label_Orientation"));

        horizontalLayout_9->addWidget(label_Orientation);

        CBox_Orientation = new QComboBox(SimpleLabelAttrWidget);
        CBox_Orientation->setObjectName(QStringLiteral("CBox_Orientation"));

        horizontalLayout_9->addWidget(CBox_Orientation);

        horizontalLayout_9->setStretch(0, 3);
        horizontalLayout_9->setStretch(1, 6);

        gridLayout->addLayout(horizontalLayout_9, 6, 0, 1, 1);


        retranslateUi(SimpleLabelAttrWidget);

        QMetaObject::connectSlotsByName(SimpleLabelAttrWidget);
    } // setupUi

    void retranslateUi(QWidget *SimpleLabelAttrWidget)
    {
        SimpleLabelAttrWidget->setWindowTitle(QApplication::translate("SimpleLabelAttrWidget", "Form", nullptr));
        label_Field->setText(QApplication::translate("SimpleLabelAttrWidget", "\346\230\276\347\244\272\345\255\227\346\256\265", nullptr));
        label_Size->setText(QApplication::translate("SimpleLabelAttrWidget", "\345\244\247\345\260\217", nullptr));
        label_Color->setText(QApplication::translate("SimpleLabelAttrWidget", "\351\242\234\350\211\262", nullptr));
        pButton_Color->setText(QString());
        label_Font->setText(QApplication::translate("SimpleLabelAttrWidget", "\345\255\227\344\275\223", nullptr));
        pButton_Font->setText(QString());
        label_setOffset->setText(QApplication::translate("SimpleLabelAttrWidget", "\345\201\217\347\247\273", nullptr));
        label_Offset_x->setText(QApplication::translate("SimpleLabelAttrWidget", "X", nullptr));
        label_Offset_x_2->setText(QApplication::translate("SimpleLabelAttrWidget", "Y", nullptr));
        label_WrapChar->setText(QApplication::translate("SimpleLabelAttrWidget", "\346\215\242\350\241\214\345\255\227\347\254\246", nullptr));
        label_Orientation->setText(QApplication::translate("SimpleLabelAttrWidget", "\346\226\207\345\255\227\346\230\276\347\244\272\346\226\271\345\220\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimpleLabelAttrWidget: public Ui_SimpleLabelAttrWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLELABELATTRWIDGET_H
