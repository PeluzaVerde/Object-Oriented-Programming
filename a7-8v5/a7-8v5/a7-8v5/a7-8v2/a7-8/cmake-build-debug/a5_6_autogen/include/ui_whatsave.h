/********************************************************************************
** Form generated from reading UI file 'whatsave.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHATSAVE_H
#define UI_WHATSAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_whatsave
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSplitter *splitter;
    QPushButton *ChooseCsv;
    QPushButton *ChooseHTML;

    void setupUi(QWidget *whatsave)
    {
        if (whatsave->objectName().isEmpty())
            whatsave->setObjectName(QString::fromUtf8("whatsave"));
        whatsave->resize(247, 90);
        verticalLayout = new QVBoxLayout(whatsave);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(whatsave);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        splitter = new QSplitter(whatsave);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        ChooseCsv = new QPushButton(splitter);
        ChooseCsv->setObjectName(QString::fromUtf8("ChooseCsv"));
        splitter->addWidget(ChooseCsv);
        ChooseHTML = new QPushButton(splitter);
        ChooseHTML->setObjectName(QString::fromUtf8("ChooseHTML"));
        splitter->addWidget(ChooseHTML);

        verticalLayout->addWidget(splitter);


        retranslateUi(whatsave);

        QMetaObject::connectSlotsByName(whatsave);
    } // setupUi

    void retranslateUi(QWidget *whatsave)
    {
        whatsave->setWindowTitle(QCoreApplication::translate("whatsave", "whatsave", nullptr));
        label->setText(QCoreApplication::translate("whatsave", "Choose How you want the data to be saved", nullptr));
        ChooseCsv->setText(QCoreApplication::translate("whatsave", "CSV", nullptr));
        ChooseHTML->setText(QCoreApplication::translate("whatsave", "HTML", nullptr));
    } // retranslateUi

};

namespace Ui {
    class whatsave: public Ui_whatsave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHATSAVE_H
