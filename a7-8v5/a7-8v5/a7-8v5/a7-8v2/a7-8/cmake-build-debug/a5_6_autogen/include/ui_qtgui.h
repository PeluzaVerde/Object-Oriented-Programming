/********************************************************************************
** Form generated from reading UI file 'qtgui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUI_H
#define UI_QTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtgui
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QLabel *label;
    QPushButton *csvButton;
    QPushButton *htmlButton;
    QWidget *tab_6;
    QListWidget *EventListWidget;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *TitlelineEdit;
    QLabel *Label_2;
    QLineEdit *DescriptionlineEdit;
    QLabel *Title_3;
    QLineEdit *LinklineEdit;
    QLabel *Title_4;
    QLineEdit *DurationlineEdit;
    QLabel *Title_5;
    QLineEdit *PeoplelineEdit;
    QPushButton *addUserButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *DeleteButton;
    QPushButton *AddButton;
    QPushButton *ModifyButton;
    QListWidget *AgendaListWidget;
    QSplitter *splitter;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *DeleteUserButton;
    QPushButton *playUserButton;
    QPushButton *FilterButton;
    QLineEdit *MonthlineEdit;
    QPushButton *ShowButton;
    QPushButton *FuncButton;
    QLineEdit *MonthlineEdit_2;
    QPushButton *undoButton;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *qtgui)
    {
        if (qtgui->objectName().isEmpty())
            qtgui->setObjectName(QString::fromUtf8("qtgui"));
        qtgui->resize(885, 602);
        tabWidget = new QTabWidget(qtgui);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 891, 621));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 90, 631, 141));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tw Cen MT Condensed")});
        font.setPointSize(24);
        font.setBold(false);
        label->setFont(font);
        csvButton = new QPushButton(tab_5);
        csvButton->setObjectName(QString::fromUtf8("csvButton"));
        csvButton->setGeometry(QRect(130, 280, 201, 191));
        QPalette palette;
        QBrush brush(QColor(255, 0, 4, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QRadialGradient gradient(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(0, 0, 0, 255));
        gradient.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QRadialGradient gradient1(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(0, 0, 0, 255));
        gradient1.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient1.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient1.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient1.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient1.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient1.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QRadialGradient gradient2(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(0, 0, 0, 255));
        gradient2.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient2.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient2.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient2.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient2.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient2.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QRadialGradient gradient3(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(0, 0, 0, 255));
        gradient3.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient3.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient3.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient3.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient3.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient3.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QRadialGradient gradient4(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(0, 0, 0, 255));
        gradient4.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient4.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient4.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient4.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient4.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient4.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QRadialGradient gradient5(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(0, 0, 0, 255));
        gradient5.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient5.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient5.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient5.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient5.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient5.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QRadialGradient gradient6(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(0, 0, 0, 255));
        gradient6.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient6.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient6.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient6.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient6.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient6.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush7(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QRadialGradient gradient7(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(0, 0, 0, 255));
        gradient7.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient7.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient7.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient7.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient7.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient7.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush8(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QRadialGradient gradient8(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(0, 0, 0, 255));
        gradient8.setColorAt(0.19397, QColor(0, 0, 0, 255));
        gradient8.setColorAt(0.202312, QColor(122, 97, 0, 255));
        gradient8.setColorAt(0.495514, QColor(76, 58, 0, 255));
        gradient8.setColorAt(0.504819, QColor(255, 255, 255, 255));
        gradient8.setColorAt(0.79, QColor(255, 255, 255, 255));
        gradient8.setColorAt(1, QColor(255, 158, 158, 255));
        QBrush brush9(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush9);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        csvButton->setPalette(palette);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Perpetua")});
        font1.setPointSize(28);
        csvButton->setFont(font1);
        csvButton->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 255), stop:0.19397 rgba(0, 0, 0, 255), stop:0.202312 rgba(122, 97, 0, 255), stop:0.495514 rgba(76, 58, 0, 255), stop:0.504819 rgba(255, 255, 255, 255), stop:0.79 rgba(255, 255, 255, 255), stop:1 rgba(255, 158, 158, 255));\n"
"color: rgb(255, 0, 4);"));
        htmlButton = new QPushButton(tab_5);
        htmlButton->setObjectName(QString::fromUtf8("htmlButton"));
        htmlButton->setGeometry(QRect(460, 280, 201, 191));
        htmlButton->setFont(font1);
        htmlButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 41, 4, 255), stop:0.085 rgba(2, 79, 0, 255), stop:0.19 rgba(50, 147, 22, 255), stop:0.275 rgba(236, 191, 49, 255), stop:0.39 rgba(243, 61, 34, 255), stop:0.555 rgba(135, 81, 60, 255), stop:0.667 rgba(121, 75, 255, 255), stop:0.825 rgba(164, 255, 244, 255), stop:0.885 rgba(104, 222, 71, 255), stop:1 rgba(93, 128, 0, 255));"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        EventListWidget = new QListWidget(tab_6);
        EventListWidget->setObjectName(QString::fromUtf8("EventListWidget"));
        EventListWidget->setGeometry(QRect(0, 0, 351, 311));
        layoutWidget = new QWidget(tab_6);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 310, 252, 170));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(layoutWidget);
        Label->setObjectName(QString::fromUtf8("Label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        TitlelineEdit = new QLineEdit(layoutWidget);
        TitlelineEdit->setObjectName(QString::fromUtf8("TitlelineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, TitlelineEdit);

        Label_2 = new QLabel(layoutWidget);
        Label_2->setObjectName(QString::fromUtf8("Label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        DescriptionlineEdit = new QLineEdit(layoutWidget);
        DescriptionlineEdit->setObjectName(QString::fromUtf8("DescriptionlineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, DescriptionlineEdit);

        Title_3 = new QLabel(layoutWidget);
        Title_3->setObjectName(QString::fromUtf8("Title_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Title_3);

        LinklineEdit = new QLineEdit(layoutWidget);
        LinklineEdit->setObjectName(QString::fromUtf8("LinklineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, LinklineEdit);

        Title_4 = new QLabel(layoutWidget);
        Title_4->setObjectName(QString::fromUtf8("Title_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Title_4);

        DurationlineEdit = new QLineEdit(layoutWidget);
        DurationlineEdit->setObjectName(QString::fromUtf8("DurationlineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, DurationlineEdit);

        Title_5 = new QLabel(layoutWidget);
        Title_5->setObjectName(QString::fromUtf8("Title_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Title_5);

        PeoplelineEdit = new QLineEdit(layoutWidget);
        PeoplelineEdit->setObjectName(QString::fromUtf8("PeoplelineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, PeoplelineEdit);

        addUserButton = new QPushButton(tab_6);
        addUserButton->setObjectName(QString::fromUtf8("addUserButton"));
        addUserButton->setGeometry(QRect(350, 150, 141, 41));
        layoutWidget1 = new QWidget(tab_6);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(-10, 460, 261, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        DeleteButton = new QPushButton(layoutWidget1);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        horizontalLayout->addWidget(DeleteButton);

        AddButton = new QPushButton(layoutWidget1);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        horizontalLayout->addWidget(AddButton);

        ModifyButton = new QPushButton(layoutWidget1);
        ModifyButton->setObjectName(QString::fromUtf8("ModifyButton"));

        horizontalLayout->addWidget(ModifyButton);

        AgendaListWidget = new QListWidget(tab_6);
        AgendaListWidget->setObjectName(QString::fromUtf8("AgendaListWidget"));
        AgendaListWidget->setGeometry(QRect(490, 0, 391, 431));
        splitter = new QSplitter(tab_6);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(497, 470, 351, 26));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        DeleteUserButton = new QPushButton(layoutWidget2);
        DeleteUserButton->setObjectName(QString::fromUtf8("DeleteUserButton"));

        horizontalLayout_2->addWidget(DeleteUserButton);

        playUserButton = new QPushButton(layoutWidget2);
        playUserButton->setObjectName(QString::fromUtf8("playUserButton"));

        horizontalLayout_2->addWidget(playUserButton);

        FilterButton = new QPushButton(layoutWidget2);
        FilterButton->setObjectName(QString::fromUtf8("FilterButton"));

        horizontalLayout_2->addWidget(FilterButton);

        splitter->addWidget(layoutWidget2);
        MonthlineEdit = new QLineEdit(splitter);
        MonthlineEdit->setObjectName(QString::fromUtf8("MonthlineEdit"));
        splitter->addWidget(MonthlineEdit);
        ShowButton = new QPushButton(tab_6);
        ShowButton->setObjectName(QString::fromUtf8("ShowButton"));
        ShowButton->setGeometry(QRect(540, 520, 171, 24));
        FuncButton = new QPushButton(tab_6);
        FuncButton->setObjectName(QString::fromUtf8("FuncButton"));
        FuncButton->setGeometry(QRect(710, 520, 112, 24));
        MonthlineEdit_2 = new QLineEdit(tab_6);
        MonthlineEdit_2->setObjectName(QString::fromUtf8("MonthlineEdit_2"));
        MonthlineEdit_2->setGeometry(QRect(820, 520, 58, 26));
        undoButton = new QPushButton(tab_6);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));
        undoButton->setGeometry(QRect(80, 520, 83, 29));
        tabWidget->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(109, 49, 631, 481));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());

        retranslateUi(qtgui);
        QObject::connect(AddButton, SIGNAL(clicked()), qtgui, SLOT(addEvent()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(qtgui);
    } // setupUi

    void retranslateUi(QWidget *qtgui)
    {
        qtgui->setWindowTitle(QCoreApplication::translate("qtgui", "qtgui", nullptr));
        label->setText(QCoreApplication::translate("qtgui", "Select the mode u want the info to be saved", nullptr));
        csvButton->setText(QCoreApplication::translate("qtgui", "CSV", nullptr));
        htmlButton->setText(QCoreApplication::translate("qtgui", "HTML", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("qtgui", "Tab 1", nullptr));
        Label->setText(QCoreApplication::translate("qtgui", "Title", nullptr));
        Label_2->setText(QCoreApplication::translate("qtgui", "Description", nullptr));
        Title_3->setText(QCoreApplication::translate("qtgui", "link", nullptr));
        Title_4->setText(QCoreApplication::translate("qtgui", "Duration(Hr,Min,Yr,Mo,D)", nullptr));
        Title_5->setText(QCoreApplication::translate("qtgui", "Number of people", nullptr));
        addUserButton->setText(QCoreApplication::translate("qtgui", "Add selected To Watchlist", nullptr));
        DeleteButton->setText(QCoreApplication::translate("qtgui", "Delete", nullptr));
        AddButton->setText(QCoreApplication::translate("qtgui", "Add", nullptr));
        ModifyButton->setText(QCoreApplication::translate("qtgui", "Modify", nullptr));
        DeleteUserButton->setText(QCoreApplication::translate("qtgui", "Delete", nullptr));
        playUserButton->setText(QCoreApplication::translate("qtgui", "Play", nullptr));
        FilterButton->setText(QCoreApplication::translate("qtgui", "Show by month", nullptr));
        ShowButton->setText(QCoreApplication::translate("qtgui", "Show Agenda(fancy)\342\230\272", nullptr));
        FuncButton->setText(QCoreApplication::translate("qtgui", "Show by month", nullptr));
        undoButton->setText(QCoreApplication::translate("qtgui", "Undo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("qtgui", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("qtgui", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qtgui: public Ui_qtgui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_H
