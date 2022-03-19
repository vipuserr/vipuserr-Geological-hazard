/********************************************************************************
** Form generated from reading UI file 'S3dmStyleSelectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3DMSTYLESELECTDIALOG_H
#define UI_S3DMSTYLESELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_S3dmStyleSelectDialog
{
public:
    QGridLayout *gridLayout;
    QTreeView *m_groupTree;
    QDialogButtonBox *m_StyleSelectButtonBox;
    QStackedWidget *mSymbolViewStackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QListView *m_SymbolListView;
    QWidget *page2;
    QVBoxLayout *verticalLayout_4;
    QTreeView *m_SymbolTreeView;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *S3dmStyleSelectDialog)
    {
        if (S3dmStyleSelectDialog->objectName().isEmpty())
            S3dmStyleSelectDialog->setObjectName(QStringLiteral("S3dmStyleSelectDialog"));
        S3dmStyleSelectDialog->resize(760, 614);
        gridLayout = new QGridLayout(S3dmStyleSelectDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_groupTree = new QTreeView(S3dmStyleSelectDialog);
        m_groupTree->setObjectName(QStringLiteral("m_groupTree"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_groupTree->sizePolicy().hasHeightForWidth());
        m_groupTree->setSizePolicy(sizePolicy);
        m_groupTree->setMinimumSize(QSize(0, 0));
        m_groupTree->setMaximumSize(QSize(200, 16777215));
        m_groupTree->setEditTriggers(QAbstractItemView::DoubleClicked);

        gridLayout->addWidget(m_groupTree, 0, 0, 1, 1);

        m_StyleSelectButtonBox = new QDialogButtonBox(S3dmStyleSelectDialog);
        m_StyleSelectButtonBox->setObjectName(QStringLiteral("m_StyleSelectButtonBox"));
        m_StyleSelectButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(m_StyleSelectButtonBox, 2, 0, 1, 2);

        mSymbolViewStackedWidget = new QStackedWidget(S3dmStyleSelectDialog);
        mSymbolViewStackedWidget->setObjectName(QStringLiteral("mSymbolViewStackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        m_SymbolListView = new QListView(page);
        m_SymbolListView->setObjectName(QStringLiteral("m_SymbolListView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(m_SymbolListView->sizePolicy().hasHeightForWidth());
        m_SymbolListView->setSizePolicy(sizePolicy1);
        m_SymbolListView->setEditTriggers(QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        m_SymbolListView->setIconSize(QSize(77, 70));
        m_SymbolListView->setTextElideMode(Qt::ElideNone);
        m_SymbolListView->setFlow(QListView::LeftToRight);
        m_SymbolListView->setResizeMode(QListView::Adjust);
        m_SymbolListView->setSpacing(5);
        m_SymbolListView->setViewMode(QListView::IconMode);
        m_SymbolListView->setUniformItemSizes(false);
        m_SymbolListView->setWordWrap(true);

        verticalLayout_3->addWidget(m_SymbolListView);

        mSymbolViewStackedWidget->addWidget(page);
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        verticalLayout_4 = new QVBoxLayout(page2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        m_SymbolTreeView = new QTreeView(page2);
        m_SymbolTreeView->setObjectName(QStringLiteral("m_SymbolTreeView"));

        verticalLayout_4->addWidget(m_SymbolTreeView);

        mSymbolViewStackedWidget->addWidget(page2);

        gridLayout->addWidget(mSymbolViewStackedWidget, 0, 1, 1, 1);

        pushButton = new QPushButton(S3dmStyleSelectDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        label = new QLabel(S3dmStyleSelectDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);


        retranslateUi(S3dmStyleSelectDialog);

        mSymbolViewStackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(S3dmStyleSelectDialog);
    } // setupUi

    void retranslateUi(QWidget *S3dmStyleSelectDialog)
    {
        S3dmStyleSelectDialog->setWindowTitle(QApplication::translate("S3dmStyleSelectDialog", "\347\254\246\345\217\267\351\200\211\345\217\226", nullptr));
        pushButton->setText(QString());
        label->setText(QApplication::translate("S3dmStyleSelectDialog", "\345\233\276\346\241\210\351\242\234\350\211\262\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class S3dmStyleSelectDialog: public Ui_S3dmStyleSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3DMSTYLESELECTDIALOG_H
