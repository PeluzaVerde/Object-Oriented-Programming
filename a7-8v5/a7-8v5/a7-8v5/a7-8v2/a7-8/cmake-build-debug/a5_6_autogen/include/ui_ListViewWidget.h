/********************************************************************************
** Form generated from reading UI file 'ListViewWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTVIEWWIDGET_H
#define UI_LISTVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListViewWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListView *productsListView;

    void setupUi(QWidget *ListViewWidget)
    {
        if (ListViewWidget->objectName().isEmpty())
            ListViewWidget->setObjectName(QString::fromUtf8("ListViewWidget"));
        ListViewWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(ListViewWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        productsListView = new QListView(ListViewWidget);
        productsListView->setObjectName(QString::fromUtf8("productsListView"));
        QFont font;
        font.setPointSize(16);
        productsListView->setFont(font);

        verticalLayout->addWidget(productsListView);


        retranslateUi(ListViewWidget);

        QMetaObject::connectSlotsByName(ListViewWidget);
    } // setupUi

    void retranslateUi(QWidget *ListViewWidget)
    {
        ListViewWidget->setWindowTitle(QCoreApplication::translate("ListViewWidget", "ListViewWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListViewWidget: public Ui_ListViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTVIEWWIDGET_H
