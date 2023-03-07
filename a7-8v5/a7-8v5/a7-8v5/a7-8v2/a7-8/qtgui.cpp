//
// Created by Owner on 5/15/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_qtgui.h" resolved

#include "qtgui.h"
#include "EventModel.h"
#include "ui_qtgui.h"
#include <QMessageBox>
#include <sstream>
#include <QKeyEvent>

using namespace std;
qtgui::qtgui(Controller& s,EventValidator valid,QWidget *parent) :
        QWidget(parent), ui(new Ui::qtgui), serv {s}, v {valid} {
    ui->setupUi(this);
    this->populateList();
    this->connectSIgnalsAndSlots();
    this->bonusA12();
}

qtgui::~qtgui() {
    delete ui;
}

void qtgui::populateList() {
    this->ui->EventListWidget->clear();
    vector<Event> allEvents = this->serv.get_all_Events();
    for(Event& e: allEvents) {
        this->ui->EventListWidget->addItem(QString::fromStdString(
                e.get_title() + " - " + e.get_description() + " - " + e.get_link() + " - " +
                std::to_string(e.get_number_of_people())
                + " - " + std::to_string(e.get_duration().get_hour()) + ":" +
                std::to_string(e.get_duration().get_minutes()) + " " + std::to_string(e.get_duration().get_year()) +
                "/" + std::to_string(e.get_duration().get_month()) + "/" + std::to_string(e.get_duration().get_day())));

    }
}

void qtgui::connectSIgnalsAndSlots() {

    QObject::connect(this->ui->DeleteButton, &QPushButton::clicked, this, &qtgui::deleteEvent);
    QObject::connect(this->ui->ModifyButton, &QPushButton::clicked, this, &qtgui::modifyEvent);
    QObject::connect(this->ui->csvButton, &QPushButton::clicked, this, &qtgui::chooseCsv);
    QObject::connect(this->ui->htmlButton, &QPushButton::clicked, this, &qtgui::chooseHTML);
    QObject::connect(this->ui->addUserButton, &QPushButton::clicked, this, &qtgui::addWatchlist);
    QObject::connect(this->ui->FilterButton, &QPushButton::clicked, this, &qtgui::filterEvent);
    QObject::connect(this->ui->playUserButton, &QPushButton::clicked, this, &qtgui::playEvent);
    QObject::connect(this->ui->DeleteUserButton, &QPushButton::clicked, this, &qtgui::deleteUserEvent);
    QObject::connect(this->ui->ShowButton, &QPushButton::clicked, this, &qtgui::showAgenda);
    QObject::connect(this->ui->FuncButton, &QPushButton::clicked, this, &qtgui::euroshow);
    QObject::connect(this->ui->undoButton, &QPushButton::clicked,this, &qtgui::undo_action);
    QObject::connect(this->ui->redoButton, &QPushButton::clicked,this, &qtgui::redo_action);
    QObject::connect(this->ui->pushButton, &QPushButton::clicked,this, &qtgui::showbutton);
    //QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z),this,&qtgui::undo_action);
    //QShortcut(QKeySequence(Qt::Key_F2),this,SLOT(undo_action()));
}

void qtgui::showbutton(){
    ProductsModel* model = new ProductsModel{s};
    ListViewWidget* listW = new ListViewWidget{model};
}

void qtgui::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_F2){
        this->undo_action();
        event->accept();
    }

    if(event->key() == Qt::Key_F3){
        this->redo_action();
        event->accept();
    }
}
void qtgui::deleteEvent() {
    int selectedIndex = this->getSelectedIndex();
    if(selectedIndex < 0)
    {
        QMessageBox::critical(this, "Error","No event was selected!");
        return;
    }
    Event e = this->serv.get_all_Events()[selectedIndex];
    this->serv.delete_Event_from_repo(e.get_title(),e.get_description(),e.get_link());

    this->populateList();

}

int qtgui::getSelectedIndex() const {

    QModelIndexList selectedIndexes = this->ui->EventListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.size()==0)
    {
        this->ui->TitlelineEdit->clear();
        this->ui->DescriptionlineEdit->clear();
        this->ui->LinklineEdit->clear();
        this->ui->PeoplelineEdit->clear();
        this->ui->DurationlineEdit->clear();
        return -1;

    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;

}

std::vector<std::string> qtgui::field_delimiter(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string field;
    while (getline(ss, field, delimiter))
        result.push_back(field);
    return result;
}



void qtgui::addEvent() {
try {
    string title = this->ui->TitlelineEdit->text().toStdString();

    string description = this->ui->DescriptionlineEdit->text().toStdString();
    string link = this->ui->LinklineEdit->text().toStdString();
    string people = this->ui->PeoplelineEdit->text().toStdString();
    string duration = this->ui->DurationlineEdit->text().toStdString();
    std::vector<std::string> fields;
    if(duration.empty())
        throw std::exception();


    fields = field_delimiter(duration, ',');
    if(fields.size()!=5)
        throw std::exception();
    this->v.validateMinute(std::stoi(fields[1]));
    this->v.validateHour(std::stoi(fields[0]));
    this->v.validateDay(std::stoi(fields[4]));
    this->v.validateMonth(std::stoi(fields[3]));
    this->v.validateYear(std::stoi(fields[2]));
    Duration d = Duration(std::stoi(fields[0]), std::stoi(fields[1]), std::stoi(fields[2]), std::stoi(fields[3]),
                          std::stoi(fields[4]));


    this->serv.add_Event_to_repo(title, description, link, d, std::stoi(people));
    this->populateList();
    int lastElement = this->serv.get_all_Events().size() - 1;
    this->ui->EventListWidget->setCurrentRow(lastElement);
}
catch (ValidationException &ex) {
    QMessageBox::critical(this, "Error",ex.what());
    return;
}
catch (RepositoryException &ex) {
    QMessageBox::critical(this, "Error",ex.what());
    return;
}
catch(...){
    QMessageBox::critical(this, "Error","sumn dunked");
    return;
}

}

void qtgui::modifyEvent() {

    try{

        int selectedIndex = this->getSelectedIndex();
        if(selectedIndex < 0)
        {
            QMessageBox::critical(this, "Error","No event was selected!");
            return;
        }
        Event e = this->serv.get_all_Events()[selectedIndex];



        string title = this->ui->TitlelineEdit->text().toStdString();

        string description = this->ui->DescriptionlineEdit->text().toStdString();
        string link = this->ui->LinklineEdit->text().toStdString();
        string people = this->ui->PeoplelineEdit->text().toStdString();
        string duration = this->ui->DurationlineEdit->text().toStdString();
        std::vector<std::string> fields;
        if(duration.empty())
            throw std::exception();


        fields = field_delimiter(duration, ',');
        if(fields.size()!=5)
            throw std::exception();
        this->v.validateMinute(std::stoi(fields[1]));
        this->v.validateHour(std::stoi(fields[0]));
        this->v.validateDay(std::stoi(fields[4]));
        this->v.validateMonth(std::stoi(fields[3]));
        this->v.validateYear(std::stoi(fields[2]));
        Duration d = Duration(std::stoi(fields[0]), std::stoi(fields[1]), std::stoi(fields[2]), std::stoi(fields[3]),
                              std::stoi(fields[4]));

        this->serv.update_Event_in_repo(e.get_title(),e.get_description(),e.get_link(),title, description, link, d, std::stoi(people));
        this->populateList();

    }
    catch (ValidationException &ex) {
        QMessageBox::critical(this, "Error",ex.what());
        return;
    }
    catch (RepositoryException &ex) {
        QMessageBox::critical(this, "Error",ex.what());
        return;
    }
    catch(...){
        QMessageBox::critical(this, "Error","sumn dunked");
        return;
    }
}

void qtgui::chooseCsv() {
    Agenda* d = new Agenda_csv("C:/Users/HP/Desktop/a7-8v5/a7-8v5/a7-8v5/a7-8v2/a7-8/agenda.csv");
    this->serv.change_agenda(d);
    this->ui->tabWidget->setTabEnabled(0,false);
    this->ui->tabWidget->setCurrentIndex(1);
}

void qtgui::chooseHTML() {
    Agenda* d = new Agenda_html("C:/Users/HP/Desktop/a7-8v5/a7-8v5/a7-8v5/a7-8v2/a7-8/agenda.html");
    this->serv.change_agenda(d);
    this->ui->tabWidget->setTabEnabled(0,false);
    this->ui->tabWidget->setCurrentIndex(1);
}

void qtgui::addWatchlist() {

    try {
        int selectedIndex = this->getSelectedIndex();
        if (selectedIndex < 0) {
            QMessageBox::critical(this, "Error", "No event was selected!");
            return;
        }
        Event e = this->serv.get_all_Events()[selectedIndex];
        this->serv.add_Event_to_agenda(e);
        this->populateAgendaList();
        int lastElement = this->serv.get_all_Agenda_Events().size() - 1;
        this->ui->AgendaListWidget->setCurrentRow(lastElement);
    }
    catch (ValidationException &ex) {
        QMessageBox::critical(this, "Error",ex.what());
        return;
    }
    catch (RepositoryException &ex) {
        QMessageBox::critical(this, "Error",ex.what());
        return;
    }
    catch(...){
        QMessageBox::critical(this, "Error","sumn dunked");
        return;
    }

    }

void qtgui::populateAgendaList() {
    this->ui->AgendaListWidget->clear();
    vector<Event> allEvents = this->serv.get_all_Agenda_Events();
    if(!allEvents.empty())
    for(Event& e: allEvents) {
        this->ui->AgendaListWidget->addItem(QString::fromStdString(
                e.get_title() + " - " + e.get_description() + " - " + e.get_link() + " - " +
                std::to_string(e.get_number_of_people())
                + " - " + std::to_string(e.get_duration().get_hour()) + ":" +
                std::to_string(e.get_duration().get_minutes()) + " " + std::to_string(e.get_duration().get_year()) +
                "/" + std::to_string(e.get_duration().get_month()) + "/" + std::to_string(e.get_duration().get_day())));

    }

}

void qtgui::filterEvent(){

    try{
        this->ui->EventListWidget->clear();
        string month = this->ui->MonthlineEdit->text().toStdString();
        int m;
        if(month.empty())
             m=0;
        else
            m=std::stoi(month);

        auto eventlist = this->serv.get_all_Events_by_monthv2(m);
        for(Event& e: eventlist) {
            this->ui->EventListWidget->addItem(QString::fromStdString(
                    e.get_title() + " - " + e.get_description() + " - " + e.get_link() + " - " +
                    std::to_string(e.get_number_of_people())
                    + " - " + std::to_string(e.get_duration().get_hour()) + ":" +
                    std::to_string(e.get_duration().get_minutes()) + " " + std::to_string(e.get_duration().get_year()) +
                    "/" + std::to_string(e.get_duration().get_month()) + "/" + std::to_string(e.get_duration().get_day())));

        }

    }
    catch (ValidationException &ex) {
        QMessageBox::critical(this, "Error",ex.what());
        return;
    }
    catch (RepositoryException &ex) {
        QMessageBox::critical(this, "Error",ex.what());
        return;
    }
    catch(...){
        QMessageBox::critical(this, "Error","sumn dunked");
        return;
    }
}

void qtgui::playEvent() {
    try{
        int selectedIndex = this->getSelectedIndexUser();
        if (selectedIndex < 0) {
            QMessageBox::critical(this, "Error", "No event was selected!");
            return;
        }
        Event e = this->serv.get_all_Agenda_Events()[selectedIndex];
        const char* fp = e.get_link().c_str();
        ShellExecuteA(NULL, NULL, "opera.exe", fp, NULL, SW_SHOWMAXIMIZED);
        //ShellExecuteA(NULL, "open",fp, NULL,NULL,SW_SHOWNORMAL);
//        this->serv.save_agenda_to_file();
//        this->serv.show_agenda_from_file();
    }

catch (ValidationException &ex) {
    QMessageBox::critical(this, "Error",ex.what());
    return;
}
catch (RepositoryException &ex) {
    QMessageBox::critical(this, "Error",ex.what());
    return;
}
catch(...){
    QMessageBox::critical(this, "Error","sumn dunked");
    return;
}

}

void qtgui::deleteUserEvent() {
    int selectedIndex = this->getSelectedIndexUser();
    if(selectedIndex < 0)
    {
        QMessageBox::critical(this, "Error","No event was selected!");
        return;
    }
    Event e = this->serv.get_all_Agenda_Events()[selectedIndex];
    this->serv.delete_Event_from_agenda(e);

    this->populateAgendaList();

}

int qtgui::getSelectedIndexUser() const {
    QModelIndexList selectedIndexes = this->ui->AgendaListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.size()==0)
    {
        this->ui->TitlelineEdit->clear();
        this->ui->DescriptionlineEdit->clear();
        this->ui->LinklineEdit->clear();
        this->ui->PeoplelineEdit->clear();
        this->ui->DurationlineEdit->clear();
        return -1;

    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void qtgui::undo_action(){
    try{
        serv.undo();
        this->populateList();
    }
    catch(std::exception){
        QMessageBox::warning(this, "Warning", QString::fromStdString("No undos ?"));
    }

}


void qtgui::redo_action(){
    try{
        serv.redo();
        this->populateList();
    }
    catch(std::exception){
        QMessageBox::warning(this, "Warning", QString::fromStdString("No redos ?"));
    }

}
void qtgui::euroshow(){

    try{
        string month = this->ui->MonthlineEdit_2->text().toStdString();
        int m;
        if(month.empty())
             m=0;
        else
            m=std::stoi(month);

        auto eventlist = this->serv.get_all_Events_by_monthv2(m);

        QDialog* dialog1 = new QDialog(this);
            dialog1->setModal(true);
            QVBoxLayout* dialog_layout = new QVBoxLayout;
            dialog1->setLayout(dialog_layout);
            dialog1->setAttribute(Qt::WA_DeleteOnClose);
            for(Event e: eventlist){
                QDialog* dialog = new QDialog(this);
                    dialog->setModal(true);
                    QVBoxLayout* dialog_layout = new QVBoxLayout;
                    dialog->setLayout(dialog_layout);
                    dialog->setAttribute(Qt::WA_DeleteOnClose);

                QWidget* form = new QWidget;
                    QFormLayout* form_layout = new QFormLayout;
                    form->setLayout(form_layout);
                    QString label =(QString::fromStdString(
                                        e.get_title() + " - " + e.get_description() + " - " + e.get_link() + " - " +
                                        std::to_string(e.get_number_of_people())
                                        + " - " + std::to_string(e.get_duration().get_hour()) + ":" +
                                        std::to_string(e.get_duration().get_minutes()) + " " + std::to_string(e.get_duration().get_year()) +
                                        "/" + std::to_string(e.get_duration().get_month()) + "/" + std::to_string(e.get_duration().get_day())));
                    form_layout->addRow(new QLabel(label));
                    QPushButton* add = new QPushButton("Add to watchlist.");
                     QPushButton* next = new QPushButton("Next Event.");
                     dialog_layout->addWidget(form);
                     dialog_layout->addWidget(add);
                     dialog_layout->addWidget(next);
                     QObject::connect(add, &QPushButton::clicked, [&](){
                                              try{

                                                  this->serv.add_Event_to_agenda(e);

                                                  dialog->close();

                                              }
                         catch (ValidationException &ex) {
                             QMessageBox::critical(this, "Error",ex.what());
                             return;
                         }
                         catch (RepositoryException &ex) {
                             QMessageBox::critical(this, "Error",ex.what());
                             return;
                         }
                         catch(...){
                             QMessageBox::critical(this, "Error","sumn dunked");
                             return;
                         }

                                          }
                         );

                         QObject::connect(next, &QPushButton::clicked, [&](){
                                              try{
                                                  dialog->close();
                                              }
                             catch (ValidationException &ex) {
                                 QMessageBox::critical(this, "Error",ex.what());
                                 return;
                             }
                             catch (RepositoryException &ex) {
                                 QMessageBox::critical(this, "Error",ex.what());
                                 return;
                             }
                             catch(...){
                                 QMessageBox::critical(this, "Error","sumn dunked");
                                 return;
                             }


                                          }

                         );


                         dialog->show();
                         dialog->exec();


            }


            //dialog1->show();
            dialog1->exec();
            this->populateAgendaList();
    }

    catch (ValidationException &ex) {
        QMessageBox::critical(this, "Error",ex.what());
        return;
    }
    catch (RepositoryException &ex) {
        QMessageBox::critical(this, "Error",ex.what());
        return;
    }
    catch(...){
        QMessageBox::critical(this, "Error","sumn dunked");
        return;
    }


}

void qtgui::showAgenda(){
        this->serv.save_agenda_to_file();
        this->serv.show_agenda_from_file();
}

void qtgui::bonusA12() {
//    QList<double> qvValues;
    QPieSeries *series = new QPieSeries();
    vector<Event> allEvents = this->serv.get_all_Events();
    int i = 0;
    for(Event& e: allEvents) {
//
//    qvValues.push_back(e.get_number_of_people());
//    }

    series->append(QString::fromStdString( e.get_title()), e.get_number_of_people());
    QPieSlice *slice = series->slices().at(i);
    //slice->setExploded();
    slice->setLabelVisible();
    //slice->setPen(QPen(Qt::darkGreen, 2));
    //slice->setBrush(Qt::green);
    i++;
//    series->append("Joe", 2);
//    series->append("Andy", 3);
//    series->append("Barbara", 4);
//    series->append("Axel", 5);
    }
//![1]

//![2]
//    QPieSlice *slice = series->slices().at(6);
//    slice->setExploded();
//    slice->setLabelVisible();
//    slice->setPen(QPen(Qt::darkGreen, 2));
//    slice->setBrush(Qt::green);
//![2]

//![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Piechart for no of people");
    chart->legend()->hide();
//![3]

//![4]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    this->ui->gridLayout->addWidget(chartView,0,0);
//    window.setCentralWidget(chartView);
//    window.resize(400, 300);
//    window.show();


}
