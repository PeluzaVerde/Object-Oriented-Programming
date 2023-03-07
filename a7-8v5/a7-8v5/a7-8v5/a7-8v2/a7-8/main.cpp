//
// Created by HP on 3/20/2022.
//

#include "UI.h"
#include "tests.h"
#include <stdlib.h>
#include <crtdbg.h>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFormLayout>
#include <QtWidgets/QApplication>
#include "GUIOLD.h"
//#include "gui.h"
#include "Agenda_html.h"
#include "qtgui.h"
//#include "EventModel.h"
#include "ListViewWidget.h"

#include <QtWidgets/QApplication>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



//    QApplication a(argc, argv);
//
//    QWidget* w = new QWidget{};
//    QHBoxLayout* hLayout = new QHBoxLayout{ w };
//    QSpinBox* spinner = new QSpinBox{};
//    // set font
//    QFont font("Courier", 50, 10, true);
//    spinner->setFont(font);
//
//    QSlider* slider = new QSlider{ Qt::Horizontal };
//    slider->setMinimumHeight(50);
//    slider->setMinimumWidth(400);
//
//    hLayout->addWidget(spinner);
//    hLayout->addWidget(slider);
//
//    //Synchronise the spinner and the slider
//    //Connect spin box - valueChanged to slider setValue
//    //QObject::connect(spinner, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
//    QObject::connect(spinner, &QSpinBox::valueChanged, slider, &QSlider::setValue);
//
//    //Connect - slider valueChanged to spin box setValue
//    QObject::connect(slider, &QSlider::valueChanged, spinner, &QSpinBox::setValue);
//
//    w->show();


//    QApplication app(argc, argv);
//
//    // Horizontal layout with 3 buttons
//    QHBoxLayout *hLayout = new QHBoxLayout;
//    QPushButton *b1 = new QPushButton("Add");
//    QPushButton *b2 = new QPushButton("Delete");
//    QPushButton *b3 = new QPushButton("Update");
//    hLayout->addWidget(b1);
//    hLayout->addWidget(b2);
//    hLayout->addWidget(b3);
//
//    QMessageBox *s = new QMessageBox("Layouts");
//    hLayout->addWidget(s);
//    // Vertical layout with 3 buttons
//    QVBoxLayout *vLayout = new QVBoxLayout;
//    QPushButton *b4 = new QPushButton("D");
//    QPushButton *b5 = new QPushButton("E");
//    QPushButton *b6 = new QPushButton("F");
//    vLayout->addWidget(b4);
//    vLayout->addWidget(b5);
//    vLayout->addWidget(b6);
//
//    // Outer Layer
//    QVBoxLayout *mainLayout = new QVBoxLayout;
//
//    // Add the previous two inner layouts
//    mainLayout->addLayout(hLayout);
//    mainLayout->addLayout(vLayout);
//
//    // Create a widget
//    QWidget *w = new QWidget();
//
//    // Set the outer layout as a main layout
//    // of the widget
//    w->setLayout(mainLayout);
//
//    // Window title
//    w->setWindowTitle("layouts");
//
//    // Display
//    w->show();
//
//    // Event loop
//    return app.exec();




//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
//    QPushButton b("", nullptr);
//    b.resize(800, 900);
//    b.show();

//    //Test_All t;
//    t.tests_everything();
//    tests();
//    tests2();


    //QMenu* fileMenu = this->menuBar()->addMeny("File");
    tests3();
    std::cout<<"\n Memory leaks?:"<<_CrtDumpMemoryLeaks();
    EventValidator v = EventValidator();
    std::vector<Event> RepoVect;
    RepoVect.reserve(10);
    std::string filename = R"(C:/Users/HP/Desktop/a7-8v5/a7-8v5/a7-8v5/a7-8v2/a7-8/events.txt)";
    Repo repository = Repo{RepoVect, filename};
    repository.initRepo();




    Controller c(repository);

    //UI ui = UI(v);
    //Agenda* d = new Agenda_html("D:/Downloads/Downloads/a7-8v5/a7-8v5/a7-8v5/a7-8v2/a7-8/agenda.csv");
   // GUI w(c);
    //w.show();
    //ui.start_application();
//    Agenda* b;
//    b =  new Agenda_html("C:/Users/HP/Downloads/a7-8v5/a7-8v2/a7-8/agenda.csv");



    ProductsModel* model = new ProductsModel{repository};
    ListViewWidget* listW = new ListViewWidget{model};
    qtgui w{c,v};
    w.show();
    listW->show();

    return a.exec();
}

