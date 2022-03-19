/********************************************************************************
** Form generated from reading UI file 'S3dmSimpleLabelDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMSIMPLELABELDIALOG_H
#define UI_S3DMSIMPLELABELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_S3dmSimpleLabelDialog
{
public:
    QPushButton *pushButton_Apply;
    QComboBox *CBox_Field;
    QLabel *label_Field;
    QLabel *label_Size;
    QComboBox *CBox_SizeUnit;
    QLabel *label_Color;
    QLabel *label_Font;
    QComboBox *CBox_OffsetUnit;
    QPushButton *pushButton_Cancel;
    QLabel *label_WrapChar;
    QLineEdit *lineEdit_WrapChar;
    QLabel *label_Orientation;
    QComboBox *CBox_Orientation;
    QLabel *label_setOffset;
    QPushButton *pButton_Color;
    QPushButton *pButton_Font;
    QDoubleSpinBox *dSBox_Size;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Offset_x_2;
    QDoubleSpinBox *dSBox_Offset_y;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Offset_x;
    QDoubleSpinBox *dSBox_Offset_x;

    void setupUi(QDialog *S3dmSimpleLabelDialog)
    {
        if (S3dmSimpleLabelDialog->objectName().isEmpty())
            S3dmSimpleLabelDialog->setObjectName(QStringLiteral("S3dmSimpleLabelDialog"));
        S3dmSimpleLabelDialog->resize(252, 287);
        pushButton_Apply = new QPushButton(S3dmSimpleLabelDialog);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));
        pushButton_Apply->setGeometry(QRect(190, 253, 51, 23));
        CBox_Field = new QComboBox(S3dmSimpleLabelDialog);
        CBox_Field->setObjectName(QStringLiteral("CBox_Field"));
        CBox_Field->setGeometry(QRect(91, 14, 151, 20));
        label_Field = new QLabel(S3dmSimpleLabelDialog);
        label_Field->setObjectName(QStringLiteral("label_Field"));
        label_Field->setGeometry(QRect(13, 14, 48, 16));
        label_Size = new QLabel(S3dmSimpleLabelDialog);
        label_Size->setObjectName(QStringLiteral("label_Size"));
        label_Size->setGeometry(QRect(13, 42, 24, 16));
        CBox_SizeUnit = new QComboBox(S3dmSimpleLabelDialog);
        CBox_SizeUnit->setObjectName(QStringLiteral("CBox_SizeUnit"));
        CBox_SizeUnit->setGeometry(QRect(170, 42, 71, 20));
        label_Color = new QLabel(S3dmSimpleLabelDialog);
        label_Color->setObjectName(QStringLiteral("label_Color"));
        label_Color->setGeometry(QRect(12, 69, 24, 16));
        label_Font = new QLabel(S3dmSimpleLabelDialog);
        label_Font->setObjectName(QStringLiteral("label_Font"));
        label_Font->setGeometry(QRect(12, 100, 24, 16));
        CBox_OffsetUnit = new QComboBox(S3dmSimpleLabelDialog);
        CBox_OffsetUnit->setObjectName(QStringLiteral("CBox_OffsetUnit"));
        CBox_OffsetUnit->setGeometry(QRect(170, 147, 71, 20));
        CBox_OffsetUnit->setAutoFillBackground(false);
        pushButton_Cancel = new QPushButton(S3dmSimpleLabelDialog);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(120, 253, 51, 23));
        label_WrapChar = new QLabel(S3dmSimpleLabelDialog);
        label_WrapChar->setObjectName(QStringLiteral("label_WrapChar"));
        label_WrapChar->setGeometry(QRect(13, 192, 48, 16));
        lineEdit_WrapChar = new QLineEdit(S3dmSimpleLabelDialog);
        lineEdit_WrapChar->setObjectName(QStringLiteral("lineEdit_WrapChar"));
        lineEdit_WrapChar->setGeometry(QRect(90, 192, 151, 20));
        lineEdit_WrapChar->setMaximumSize(QSize(10707215, 16777215));
        lineEdit_WrapChar->setAcceptDrops(true);
        label_Orientation = new QLabel(S3dmSimpleLabelDialog);
        label_Orientation->setObjectName(QStringLiteral("label_Orientation"));
        label_Orientation->setGeometry(QRect(13, 220, 72, 16));
        CBox_Orientation = new QComboBox(S3dmSimpleLabelDialog);
        CBox_Orientation->setObjectName(QStringLiteral("CBox_Orientation"));
        CBox_Orientation->setGeometry(QRect(89, 220, 151, 20));
        label_setOffset = new QLabel(S3dmSimpleLabelDialog);
        label_setOffset->setObjectName(QStringLiteral("label_setOffset"));
        label_setOffset->setGeometry(QRect(12, 131, 24, 16));
        pButton_Color = new QPushButton(S3dmSimpleLabelDialog);
        pButton_Color->setObjectName(QStringLiteral("pButton_Color"));
        pButton_Color->setGeometry(QRect(90, 69, 151, 23));
        pButton_Font = new QPushButton(S3dmSimpleLabelDialog);
        pButton_Font->setObjectName(QStringLiteral("pButton_Font"));
        pButton_Font->setGeometry(QRect(91, 100, 151, 23));
        dSBox_Size = new QDoubleSpinBox(S3dmSimpleLabelDialog);
        dSBox_Size->setObjectName(QStringLiteral("dSBox_Size"));
        dSBox_Size->setGeometry(QRect(91, 42, 71, 20));
        layoutWidget = new QWidget(S3dmSimpleLabelDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(91, 160, 72, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Offset_x_2 = new QLabel(layoutWidget);
        label_Offset_x_2->setObjectName(QStringLiteral("label_Offset_x_2"));

        horizontalLayout_3->addWidget(label_Offset_x_2);

        dSBox_Offset_y = new QDoubleSpinBox(layoutWidget);
        dSBox_Offset_y->setObjectName(QStringLiteral("dSBox_Offset_y"));

        horizontalLayout_3->addWidget(dSBox_Offset_y);

        layoutWidget1 = new QWidget(S3dmSimpleLabelDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(91, 132, 72, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Offset_x = new QLabel(layoutWidget1);
        label_Offset_x->setObjectName(QStringLiteral("label_Offset_x"));

        horizontalLayout_2->addWidget(label_Offset_x);

        dSBox_Offset_x = new QDoubleSpinBox(layoutWidget1);
        dSBox_Offset_x->setObjectName(QStringLiteral("dSBox_Offset_x"));

        horizontalLayout_2->addWidget(dSBox_Offset_x);


        retranslateUi(S3dmSimpleLabelDialog);

        QMetaObject::connectSlotsByName(S3dmSimpleLabelDialog);
    } // setupUi

    void retranslateUi(QDialog *S3dmSimpleLabelDialog)
    {
        S3dmSimpleLabelDialog->setWindowTitle(QApplication::translate("S3dmSimpleLabelDialog", "\345\215\225\344\270\200\346\263\250\350\256\260", nullptr));
        pushButton_Apply->setText(QApplication::translate("S3dmSimpleLabelDialog", "\347\241\256\345\256\232", nullptr));
        label_Field->setText(QApplication::translate("S3dmSimpleLabelDialog", "\346\230\276\347\244\272\345\255\227\346\256\265", nullptr));
        label_Size->setText(QApplication::translate("S3dmSimpleLabelDialog", "\345\244\247\345\260\217", nullptr));
        label_Color->setText(QApplication::translate("S3dmSimpleLabelDialog", "\351\242\234\350\211\262", nullptr));
        label_Font->setText(QApplication::translate("S3dmSimpleLabelDialog", "\345\255\227\344\275\223", nullptr));
        pushButton_Cancel->setText(QApplication::translate("S3dmSimpleLabelDialog", "\345\217\226\346\266\210", nullptr));
        label_WrapChar->setText(QApplication::translate("S3dmSimpleLabelDialog", "\346\215\242\350\241\214\345\255\227\347\254\246", nullptr));
        label_Orientation->setText(QApplication::translate("S3dmSimpleLabelDialog", "\346\226\207\345\255\227\346\230\276\347\244\272\346\226\271\345\220\221", nullptr));
        label_setOffset->setText(QApplication::translate("S3dmSimpleLabelDialog", "\345\201\217\347\247\273", nullptr));
        pButton_Color->setText(QString());
        pButton_Font->setText(QString());
        label_Offset_x_2->setText(QApplication::translate("S3dmSimpleLabelDialog", "Y", nullptr));
        label_Offset_x->setText(QApplication::translate("S3dmSimpleLabelDialog", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmSimpleLabelDialog: public Ui_S3dmSimpleLabelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMSIMPLELABELDIALOG_H
