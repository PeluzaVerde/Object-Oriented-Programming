//#include "gui.h"
//
//void GUI::layout_initialization() {
//    setLayout(main_layout);
//
//    QWidget *output_widget = new QWidget;
//    QVBoxLayout *output_layout = new QVBoxLayout;
//
//    output_widget->setLayout(output_layout);
//    output_list = new QTableWidget;
//    output_list->setRowCount(0);
//    output_list->setColumnCount(5);
//    output_list->setSelectionMode(QAbstractItemView::SingleSelection);
//    output_list->setSelectionBehavior(QAbstractItemView::SelectRows);
//    QStringList temp_table_header;
//    temp_table_header << "Title" << "Description" << "no of people" << "Duration" << "Link";
//    output_list->setHorizontalHeaderLabels(temp_table_header);
//    output_layout->addWidget(output_list);
//
//    main_layout->addWidget(output_widget);
//
//    QWidget *input_widget = new QWidget;
//    QVBoxLayout *input_layout = new QVBoxLayout;
//
//    input_widget->setLayout(input_layout);
//
//    add_button = new QPushButton("Add");
//    delete_button = new QPushButton("Delete");
//    modify_button = new QPushButton("Modify");
//    filter_button = new QPushButton("Filter");
//    //undo_button = new QPushButton("Undo");
//
//    input_layout->addWidget(add_button);
//    input_layout->addWidget(delete_button);
//    input_layout->addWidget(modify_button);
//    input_layout->addWidget(filter_button);
//    //input_layout->addWidget(undo_button);
//
//    main_layout->addWidget(input_widget);
//
//    QWidget *new_widget = new QWidget;
//    new_widget->setLayout(new_layout);
//    main_layout->addWidget(new_widget);
//
//
//    std::ifstream f("D:/Downloads/Downloads/a7-8v5/a7-8v5/a7-8v5/a7-8v2/a7-8/events.txt");
//    if (!f.is_open())
//        return;
//    //srv.clear_repo_and_events();
//    Event input{};
//    while (f >> input) {
//        //std::cout<<input.get_number_of_people()<<' ';
//        srv.add_Event_to_repo(input.get_title(), input.get_description(), input.get_link(), input.get_duration(),
//                              input.get_number_of_people());
//    }
//    std::cout << "Events read successfully.\n";
//    f.close();
//
//
//    QDialog *diag = new QDialog(this);
//    diag->setModal(true);
//    QVBoxLayout *diag_layout = new QVBoxLayout;
//    diag->setLayout(diag_layout);
//
//    QWidget *form = new QWidget;
//    QFormLayout *form_layout = new QFormLayout;
//    form->setLayout(form_layout);
//    main_layout->addWidget(form);
//
//
//    QLineEdit *title_txt = new QLineEdit;
//    form_layout->addRow(new QLabel("Title: "), title_txt);
//    //QLineEdit::textChanged(title_txt)
////     output_list->findItems(title_txt,);
////for (int i =0; i<=srv.get_all_Events().size(); i++)
////    //QString str=QString::toStdString( output_list->item(i,0);
//}
//void GUI::event_connection()
//{
//
//    QObject::connect(add_button, &QPushButton::clicked,this, &GUI::add_action);
//
//    QObject::connect(delete_button, &QPushButton::clicked,this, &GUI::delete_action);
//
//    QObject::connect(modify_button, &QPushButton::clicked,this, &GUI::modify_action);
//
//    QObject::connect(filter_button, &QPushButton::clicked,this, &GUI::filter_action);
//
//    //QObject::connect(undo_button, &QPushButton::clicked,this, &GUI::undo_action);
//}
//
//
//void GUI::reload_list()
//{
//    output_list->clearContents();
//    auto event_list = srv.get_all_Events();
//    std::unordered_map<std::string, int> map;
//    output_list->setRowCount(event_list.size());
//    int i = 0;
//    for(const auto& event: event_list){
//        try{
//            auto& temporary = map.at(event.get_title());
//
//            temporary++;
//        }catch(...){
//            map.insert({event.get_title(), i});
//        }
//
//        output_list->setItem(i,0, new QTableWidgetItem(QString::fromStdString(event.get_title())));
//        output_list->setItem(i,1, new QTableWidgetItem(QString::fromStdString(event.get_description())));
//        output_list->setItem(i,2, new QTableWidgetItem(QString::number(event.get_number_of_people())));
//        output_list->setItem(i,3, new QTableWidgetItem(QString::fromStdString(std::to_string(event.get_duration().get_hour())+":"+std::to_string(event.get_duration().get_minutes()) +" "+std::to_string(event.get_duration().get_year())+"/"+std::to_string(event.get_duration().get_month())+"/"+std::to_string(event.get_duration().get_day()) )));
//        output_list->setItem(i,4, new QTableWidgetItem(QString::fromStdString(event.get_link())));
//        i++;
//    }
//    clearLayout(new_layout);
//    for(const auto& el: map){
//        QPushButton* btn = new QPushButton(QString::fromStdString(el.first));
//        int a = el.second;
//        QObject::connect(btn, &QPushButton::clicked, [a, this](){
//            QMessageBox::information(this, QString::number(a), QString::fromStdString("Playing"));
//            output_list->item(a,4);
//           const char* fp = output_list->item(a,4)->text().toStdString().c_str();
//            ShellExecuteA(NULL, "open",fp, NULL,NULL,SW_SHOWNORMAL);
//
//        });
//        new_layout->addWidget(btn);
//    }
//    main_layout->update();
//}
//
//void GUI::add_action()
//{
//    QDialog* diag = new QDialog(this);
//    diag->setModal(true);
//    QVBoxLayout* diag_layout = new QVBoxLayout;
//    diag->setLayout(diag_layout);
//
//    QWidget* form = new QWidget;
//    QFormLayout* form_layout = new QFormLayout;
//    form->setLayout(form_layout);
//
//    QLineEdit* title_txt = new QLineEdit;
//    form_layout->addRow(new QLabel("Title: "), title_txt);
//
//    QLineEdit* description_txt = new QLineEdit;
//    form_layout->addRow(new QLabel("description: "), description_txt);
//
//    QLineEdit* link_txt = new QLineEdit;
//    form_layout->addRow(new QLabel("link: "), link_txt);
//
//    QLineEdit* numberppl_txt = new QLineEdit;
//    form_layout->addRow(new QLabel("number of people: "), numberppl_txt);
//
//    QPushButton* add = new QPushButton("Add");
//
//    diag_layout->addWidget(form);
//    diag_layout->addWidget(add);
//
//
//    QObject::connect(add, &QPushButton::clicked, [&](){
//                         int nrPPl ;
//                         std::string desc, link,apartment;
//                         try{
//
////                             apartment = validator::validate_apartment(apartment_txt->text().toStdString());
////                             desc = validator::validate_desc(desc_txt->text().toStdString());
////                             link = validator::validate_link(link_txt->text().toStdString());
////                             area = validator::validate_area(area_txt->text().toStdString());
//                             apartment = title_txt->text().toStdString();
//                             desc = description_txt->text().toStdString();
//                             link = link_txt->text().toStdString();
//                             nrPPl = numberppl_txt->text().toInt();
//
//                             this->srv.add_Event_to_repo(apartment, desc, link,Duration(12,12,2012,12,12),nrPPl);
//                             reload_list();
//
//                         }
//                         catch(ValidationException& ex){
//                             QMessageBox::warning(diag, "Warning", QString::fromStdString(ex.what()));
//                         }
//
//                     }
//    );
//    diag->exec();
//}
//
//void GUI::delete_action()
//{
//    auto row = output_list->currentRow();
//    if(row == -1)
//        QMessageBox::warning(this, "Warning", "No event was selected");
//    else{
//        auto ap = (output_list->item(row, 0))->text().toInt();
////        try{
////            srv.delete_Event_from_repo(ap);
////            reload_list();
////        }
////        catch(my_exception& ex){
////            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_error()));
////        }
//    }
//}
//
////void GUI::undo_action()
////{
////    try{
////        srv.undo();
////        reload_list();
////    }
////    catch(my_exception& ex){
////        QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_error()));
////    }
////}
//
//void GUI::modify_action()
//{
//    auto row = output_list->currentRow();
//    if(row == -1)
//        QMessageBox::warning(this, "Warning", "No event was selected");
//    else{
//        auto ap = (output_list->item(row, 0))->text().toInt();
//        //try
//        {
//
//            QDialog* diag = new QDialog(this);
//            diag->setModal(true);
//            QVBoxLayout* diag_layout = new QVBoxLayout;
//            diag->setLayout(diag_layout);
//
//            QWidget* form = new QWidget;
//            QFormLayout* form_layout = new QFormLayout;
//            form->setLayout(form_layout);
//
//            QLineEdit* apartment_txt = new QLineEdit;
//            form_layout->addRow(new QLabel("New Apartment: "), apartment_txt);
//
//            QLineEdit* desc_txt = new QLineEdit;
//            form_layout->addRow(new QLabel("New desc: "), desc_txt);
//
//            QLineEdit* link_txt = new QLineEdit;
//            form_layout->addRow(new QLabel("New link: "), link_txt);
//
//            QLineEdit* area_txt = new QLineEdit;
//            form_layout->addRow(new QLabel("New Area: "), area_txt);
//
//            QPushButton* add = new QPushButton("Modify");
//
//            diag_layout->addWidget(form);
//            diag_layout->addWidget(add);
//
//            apartment_txt->setText((output_list->item(row, 0))->text());
//            desc_txt->setText((output_list->item(row, 1))->text());
//            link_txt->setText((output_list->item(row, 2))->text());
//            area_txt->setText((output_list->item(row, 3))->text());
//
//
//            QObject::connect(add, &QPushButton::clicked, [&](){
//                                 int apartment, area;
//                                 std::string desc, link;
//
//                                // try
//                                 {
////
////                                     apartment = validator::validate_apartment(apartment_txt->text().toStdString());
////                                     desc = validator::validate_desc(desc_txt->text().toStdString());
////                                     link = validator::validate_link(link_txt->text().toStdString());
////                                     area = validator::validate_area(area_txt->text().toStdString());
////
////                                     this->srv.modify(ap, apartment, desc, link, area);
////                                     reload_list();
////                                     diag->close();
//
//                                 }
//                                 //catch(my_exception& ex)
////                                 {
////                                     QMessageBox::warning(diag, "Warning", QString::fromStdString(ex.get_error()));
////                                 }
//
//                             }
//            );
//            diag->exec();
//        }
//        //catch(my_exception& ex){
//            //QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_error()));
//        }
//    }
////}
//
//void GUI::clearLayout(QLayout *layout)
//{
//    if (layout == NULL)
//        return;
//    QLayoutItem *item;
//    while((item = layout->takeAt(0))) {
//        if (item->layout()) {
//            clearLayout(item->layout());
//            delete item->layout();
//        }
//        if (item->widget()) {
//            delete item->widget();
//        }
//        delete item;
//    }
//}
//
//GUI::GUI(Controller& srv): srv{srv}
//{
//    layout_initialization();
//    event_connection();
//    reload_list();
//}
//
//GUI::~GUI()
//{
//}
//
//void GUI::filter_action() {
//    QDialog *diag = new QDialog(this);
//    diag->setModal(true);
//    QVBoxLayout *diag_layout = new QVBoxLayout;
//    diag->setLayout(diag_layout);
//
//    QWidget *form = new QWidget;
//    QFormLayout *form_layout = new QFormLayout;
//    form->setLayout(form_layout);
//
//
//    QLineEdit *chef_txt = new QLineEdit;
//    form_layout->addRow(new QLabel("month: "), chef_txt);
//
//    QPushButton *add = new QPushButton("Filter by month");
//
//    diag_layout->addWidget(form);
//    diag_layout->addWidget(add);
//    diag->exec();
//    int chef;
//    chef = chef_txt->text().toInt();
//    output_list->clearContents();
//    auto event_list = srv.get_all_Events_by_monthv2(chef);
//    std::unordered_map<std::string, int> map;
//    output_list->setRowCount(event_list.size());
//    int i = 0;
//    for (const auto &event: event_list) {
//        try {
//            auto &temp = map.at(event.get_title());
//            temp++;
//        }
//        catch (...) {
//            map.insert({event.get_title(), 1});
//        }
//        output_list->setItem(i,0, new QTableWidgetItem(QString::fromStdString(event.get_title())));
//        output_list->setItem(i,1, new QTableWidgetItem(QString::fromStdString(event.get_description())));
//        output_list->setItem(i,2, new QTableWidgetItem(QString::number(event.get_number_of_people())));
//        output_list->setItem(i,3, new QTableWidgetItem(QString::fromStdString(std::to_string(event.get_duration().get_hour())+":"+std::to_string(event.get_duration().get_minutes()) +" "+std::to_string(event.get_duration().get_year())+"/"+std::to_string(event.get_duration().get_month())+"/"+std::to_string(event.get_duration().get_day()) )));
//        output_list->setItem(i,4, new QTableWidgetItem(QString::fromStdString(event.get_link())));
//
//        i++;
//    }
//    clearLayout(new_layout);
//
//    for (const auto &el: map) {
//        QPushButton *btn = new QPushButton(QString::fromStdString(el.first));
//        int a = el.second;
//        QObject::connect(btn, &QPushButton::clicked, [a, this]() {
//            QMessageBox::information(this, "test", QString::fromStdString("test2"));
//
//        });
//        new_layout->addWidget(btn);
//    }
//    main_layout->update();
//}