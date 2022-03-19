/********************************************************************************
** Form generated from reading UI file 'DBSelectorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBSELECTORDIALOG_H
#define UI_DBSELECTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBSelectorDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *rBtnLocalFileDB;
    QRadioButton *rBtnSysDB;
    QWidget *panelLocalDB;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_9;
    QPushButton *btnSelectLocalDB;
    QLineEdit *localDBPath;
    QLabel *label_8;
    QLineEdit *localUserName;
    QLabel *label_10;
    QComboBox *localDbType;
    QLabel *label_11;
    QLineEdit *localPassword;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_12;
    QLineEdit *lineEdit_2;
    QWidget *panelSysDB;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QComboBox *listSysDBs;
    QLabel *label_4;
    QLabel *labelServerType;
    QLabel *label_6;
    QLabel *labelServerAddress;
    QLabel *label_5;
    QLabel *labelSysDBName;
    QLabel *label_7;
    QLabel *labelDBUserName;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DBSelectorDialog)
    {
        if (DBSelectorDialog->objectName().isEmpty())
            DBSelectorDialog->setObjectName(QStringLiteral("DBSelectorDialog"));
        DBSelectorDialog->resize(361, 402);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DBSelectorDialog->sizePolicy().hasHeightForWidth());
        DBSelectorDialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        DBSelectorDialog->setFont(font);
        verticalLayout_3 = new QVBoxLayout(DBSelectorDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DBSelectorDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        rBtnLocalFileDB = new QRadioButton(DBSelectorDialog);
        rBtnLocalFileDB->setObjectName(QStringLiteral("rBtnLocalFileDB"));
        rBtnLocalFileDB->setChecked(true);

        horizontalLayout->addWidget(rBtnLocalFileDB);

        rBtnSysDB = new QRadioButton(DBSelectorDialog);
        rBtnSysDB->setObjectName(QStringLiteral("rBtnSysDB"));

        horizontalLayout->addWidget(rBtnSysDB);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        panelLocalDB = new QWidget(DBSelectorDialog);
        panelLocalDB->setObjectName(QStringLiteral("panelLocalDB"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(panelLocalDB->sizePolicy().hasHeightForWidth());
        panelLocalDB->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(panelLocalDB);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(8);
        label_2 = new QLabel(panelLocalDB);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_9 = new QLabel(panelLocalDB);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        btnSelectLocalDB = new QPushButton(panelLocalDB);
        btnSelectLocalDB->setObjectName(QStringLiteral("btnSelectLocalDB"));

        gridLayout->addWidget(btnSelectLocalDB, 1, 2, 1, 1);

        localDBPath = new QLineEdit(panelLocalDB);
        localDBPath->setObjectName(QStringLiteral("localDBPath"));
        localDBPath->setReadOnly(true);

        gridLayout->addWidget(localDBPath, 1, 1, 1, 1);

        label_8 = new QLabel(panelLocalDB);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        localUserName = new QLineEdit(panelLocalDB);
        localUserName->setObjectName(QStringLiteral("localUserName"));

        gridLayout->addWidget(localUserName, 4, 1, 1, 1);

        label_10 = new QLabel(panelLocalDB);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        localDbType = new QComboBox(panelLocalDB);
        localDbType->setObjectName(QStringLiteral("localDbType"));

        gridLayout->addWidget(localDbType, 0, 1, 1, 1);

        label_11 = new QLabel(panelLocalDB);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 2, 0, 1, 1);

        localPassword = new QLineEdit(panelLocalDB);
        localPassword->setObjectName(QStringLiteral("localPassword"));

        gridLayout->addWidget(localPassword, 5, 1, 1, 1);

        lineEdit = new QLineEdit(panelLocalDB);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        pushButton = new QPushButton(panelLocalDB);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 5, 2, 1, 1);

        label_12 = new QLabel(panelLocalDB);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 3, 0, 1, 1);

        lineEdit_2 = new QLineEdit(panelLocalDB);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);


        verticalLayout_3->addWidget(panelLocalDB);

        panelSysDB = new QWidget(DBSelectorDialog);
        panelSysDB->setObjectName(QStringLiteral("panelSysDB"));
        panelSysDB->setEnabled(true);
        formLayout_2 = new QFormLayout(panelSysDB);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setHorizontalSpacing(6);
        formLayout_2->setVerticalSpacing(10);
        label_3 = new QLabel(panelSysDB);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        listSysDBs = new QComboBox(panelSysDB);
        listSysDBs->setObjectName(QStringLiteral("listSysDBs"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, listSysDBs);

        label_4 = new QLabel(panelSysDB);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        labelServerType = new QLabel(panelSysDB);
        labelServerType->setObjectName(QStringLiteral("labelServerType"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, labelServerType);

        label_6 = new QLabel(panelSysDB);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        labelServerAddress = new QLabel(panelSysDB);
        labelServerAddress->setObjectName(QStringLiteral("labelServerAddress"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, labelServerAddress);

        label_5 = new QLabel(panelSysDB);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_5);

        labelSysDBName = new QLabel(panelSysDB);
        labelSysDBName->setObjectName(QStringLiteral("labelSysDBName"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, labelSysDBName);

        label_7 = new QLabel(panelSysDB);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_7);

        labelDBUserName = new QLabel(panelSysDB);
        labelDBUserName->setObjectName(QStringLiteral("labelDBUserName"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, labelDBUserName);


        verticalLayout_3->addWidget(panelSysDB);

        buttonBox = new QDialogButtonBox(DBSelectorDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(DBSelectorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DBSelectorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DBSelectorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DBSelectorDialog);
    } // setupUi

    void retranslateUi(QDialog *DBSelectorDialog)
    {
        DBSelectorDialog->setWindowTitle(QApplication::translate("DBSelectorDialog", "\351\200\211\346\213\251\346\225\260\346\215\256\345\272\223\357\274\232", nullptr));
        label->setText(QApplication::translate("DBSelectorDialog", "\346\225\260\346\215\256\345\272\223\347\261\273\345\236\213\357\274\232", nullptr));
        rBtnLocalFileDB->setText(QApplication::translate("DBSelectorDialog", "\346\234\254\345\234\260\346\225\260\346\215\256\345\272\223", nullptr));
        rBtnSysDB->setText(QApplication::translate("DBSelectorDialog", "\347\263\273\347\273\237\346\225\260\346\215\256\345\272\223", nullptr));
        label_2->setText(QApplication::translate("DBSelectorDialog", "\346\225\260\346\215\256\346\272\220\357\274\232", nullptr));
        label_9->setText(QApplication::translate("DBSelectorDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        btnSelectLocalDB->setText(QApplication::translate("DBSelectorDialog", "\351\200\211\346\213\251", nullptr));
        label_8->setText(QApplication::translate("DBSelectorDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_10->setText(QApplication::translate("DBSelectorDialog", "\346\225\260\346\215\256\345\272\223\347\261\273\345\236\213\357\274\232", nullptr));
        label_11->setText(QApplication::translate("DBSelectorDialog", "\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("DBSelectorDialog", "\350\277\236\346\216\245\346\265\213\350\257\225", nullptr));
        label_12->setText(QApplication::translate("DBSelectorDialog", "\346\225\260\346\215\256\345\272\223\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("DBSelectorDialog", "\346\225\260\346\215\256\346\272\220\357\274\232", nullptr));
        label_4->setText(QApplication::translate("DBSelectorDialog", "\346\234\215\345\212\241\345\231\250\347\261\273\345\236\213\357\274\232", nullptr));
        labelServerType->setText(QString());
        label_6->setText(QApplication::translate("DBSelectorDialog", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        labelServerAddress->setText(QString());
        label_5->setText(QApplication::translate("DBSelectorDialog", "\347\211\251\347\220\206\345\272\223\345\220\215\345\255\227\357\274\232", nullptr));
        labelSysDBName->setText(QString());
        label_7->setText(QApplication::translate("DBSelectorDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelDBUserName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DBSelectorDialog: public Ui_DBSelectorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBSELECTORDIALOG_H
