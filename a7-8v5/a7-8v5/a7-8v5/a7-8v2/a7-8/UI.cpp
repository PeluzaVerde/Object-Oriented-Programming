//
// Created by HP on 3/21/2022.
//
/*
#include "UI.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Agenda_csv.h"
#include "Agenda_html.h"

UI::UI(const EventValidator& v){
    //controller = Controller(repo);
    validator =v;
    mode = -1;
}

void UI::start_application() {
    std::cout << "Life after school initializing...%\n...%\n";

    std::cout<< "Welcome!\n How should data be saved? 1)CSV or 2) HTML";
    int op;
    std::cin>>op;
    Agenda* a;
    if (op==1){
        a = new Agenda_csv("C:/Users/HP/Downloads/a7-8v5/a7-8v2/a7-8/agenda.csv");
    }
    else if (op==2){
        a = new Agenda_html("C:/Users/HP/Downloads/a7-8v5/a7-8v2/a7-8/agenda.html");
    }
    else {
        std::cout << "not an option";
        return;
    }
    const Repo & repo = Repo();
    controller = Controller(repo,a);

    read_Events_from_file_admin();
    //controller.initialise_repo();
    choose_mode();
}

void UI::choose_mode() {
    std::cout << "Choose a mode: admin \n user\n or exit\n";
    std::string mode;
    std::cin>>mode;
    if (mode == "admin")
    {
        this->mode = 0;
        std::cout << "Welcome, administrator.\n";
        start_admin_mode();
    }
    else if (mode == "user") {start_user_mode();} //std::cout << "A work in progress. Get. Out.\n"; choose_mode();
    else if (mode == "exit") {std::cout<<"Returning to school ...%\nDeleting search history..%\n..."; return;}
    else std::cout<<"Go back to school and learn to spell.\n";
    choose_mode();
}

void UI::start_admin_mode() {
    print_admin_menu();
    std::cout<<"Option: ";
    std::string choice;
    std::cin>>choice;
    if(choice.find_first_not_of("0123456789") == std::string::npos)
    {
        int choice_integer = std::stoi(choice);
        switch(choice_integer){
            case 1:
                add_Event_admin_mode();
                break;
            case 2:
                delete_Event_admin_mode();
                break;
            case 3:
                update_Event_admin_mode();
                break;
            case 4:
                show_Events_admin_mode();
                break;
            case 5:
                return;
            case 6:
                save_Events_admin();
                break;
            case 7:
                read_Events_from_file_admin();
                break;
            default:
                std::cout<<"You had one job and you messed it up\n";
        }
    }
    else
        std::cout<<"Option does not exist.\n";
    start_admin_mode();
}

void UI::print_admin_menu() {
    std::cout<<"Admin menu:\n";
    std::cout<<"1. Add an Event.\n";
    std::cout<<"2. Delete a Event.\n";
    std::cout<<"3. Update a Event.\n";
    std::cout<<"4. Show all Events.\n";
    std::cout<<"5. Exit application.\n";
    std::cout<<"6. Save the changes onto the file.\n";
    std::cout<<"7. Read the info from the file(save first or progress will be lost).\n";

}

void UI::add_Event_admin_mode() {
    std::cout << "\nadd Event.\n";
    std::string title_, description_, link_, number_of_people_, minutes_, hour_, year_, month_, day_;
    int number_of_people, minutes, hour, year, month, day;
    std::cin.get();
    std::cout << "Title of the Event: ";
    std::getline(std::cin, title_);
    std::cout << "\nSuccint description: ";
    std::getline(std::cin, description_);
    std::cout << "\nLink to event: ";
    std::getline(std::cin, link_);
    std::cout << "\nNumber of people participating: ";
    std::getline(std::cin, number_of_people_);


//    if (number_of_people_.find_first_not_of("0123456789") != std::string::npos)
//    {
//        std::cout<<"Invalid number of people.\n";
//        return;
//    }
//    number_of_people = std::stoi(number_of_people_);
//    if (number_of_people < 0){
//        std::cout<<"Invalid number of people.\n";
//        return;
//    }
    std::cout << "\nDuration:\nMinutes: ";
    std::getline(std::cin, minutes_);
//    if (minutes_.find_first_not_of("0123456789") != std::string::npos)
//    {
//        std::cout<<"Invalid minutes.\n";
//        return;
//    }
//    minutes = std::stoi(minutes_);
//    if (minutes<0 || minutes >59){
//        std::cout<<"Invalid minutes.\n";
//        return;
//    }

    std::cout << "\nhour: ";
    std::getline(std::cin, hour_);
//    if (hour_.find_first_not_of("0123456789") != std::string::npos)
//    {
//        std::cout<<"Invalid hour.\n";
//        return;
//    }
//    hour = std::stoi(hour_);
//    if (hour<0 || hour > 23)
//    {
//        std::cout<<"Invalid hour.\n";
//        return;
//    }

    std::cout << "\nyear: ";
    std::getline(std::cin, year_);
//    if (year_.find_first_not_of("0123456789") != std::string::npos)
//    {
//        std::cout<<"Invalid year.\n";
//        return;
//    }
//    year = std::stoi(year_);
//    if (year<2000 || hour > 3000)
//    {
//        std::cout<<"Invalid year.\n";
//        return;
//    }

    std::cout << "\nmonth: ";
    std::getline(std::cin, month_);
//    if (month_.find_first_not_of("0123456789") != std::string::npos)
//    {
//        std::cout<<"Invalid hour.\n";
//        return;
//    }
//    month = std::stoi(month_);
//    if (month<0 || month > 12)
//    {
//        std::cout<<"Invalid month.\n";
//        return;
//    }

    std::cout << "\nday: ";
    std::getline(std::cin, day_);
//    if (day_.find_first_not_of("0123456789") != std::string::npos)
//    {
//        std::cout<<"Invalid day.\n";
//        return;
//    }
//    day = std::stoi(day_);
//    if (day<0 || day > 31)
//    {
//        std::cout<<"Invalid day.\n";
//        return;
//    }

    if (day == 30 || day == 31)
        if (month == 2)
            std::cout << "Im not gonna be the one to tell em...\n";

    try {
        this->validator.validateInteger(number_of_people_);
        number_of_people = std::stoi(number_of_people_);
        this->validator.validateNumberOfPeople(number_of_people);
        this->validator.validateInteger(day_);
        this->validator.validateInteger(month_);
        this->validator.validateInteger(year_);
        this->validator.validateInteger(hour_);
        this->validator.validateInteger(minutes_);
        day = std::stoi(day_);
        month = std::stoi(month_);
        year = std::stoi(year_);
        minutes = std::stoi(minutes_);
        hour = std::stoi(hour_);
        this->validator.validateDay(day);
        this->validator.validateMonth(month);
        this->validator.validateYear(year);
        this->validator.validateHour(hour);
        this->validator.validateMinute(minutes);
    }
    catch (ValidationException &ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
    try {
        //bool check = controller.add_Event_to_repo(title_, description_, link_,Duration(minutes, hour, year, month, day), number_of_people);
        //this->validator.validateBool(check);
        //if (check)
        controller.add_Event_to_repo(title_, description_, link_,Duration(minutes, hour, year, month, day), number_of_people);
        std::cout << "\nEvent added successfully.\n";
//        else
//            std::cout << "\nEvent already exists.\n";

    }
    //catch(RepositoryException &re) {
    catch(RepositoryException &re) {
        std::cout<< re.what();
    //std::cout<< "event adlready exists.\n";
    return;
    }
}


void UI::delete_Event_admin_mode() {
    std::cout<<"\ndeletus Eventus:\n";
    std::string title_, description_, link_;
    std::cin.get();
    std::cout<<"Title of Event: ";
    std::getline(std::cin, title_);
    std::cout<<"\nDescription: ";
    std::getline(std::cin, description_);
    std::cout<<"\nLink to event: ";
    std::getline(std::cin, link_);

    try {
        //bool check = controller.delete_Event_from_repo(title_, description_, link_);
        //this->validator.validateBool(check);
        //if (check)
        controller.delete_Event_from_repo(title_, description_, link_);
            std::cout<<"\nEvent deleted successfully.\n";
    }

    catch(RepositoryException &ex) {
        std::cout<< ex.what();
        //std::cout<<"\nI looked everywhere, but it was nowhere to be found.\n";
        return;
    }
//    bool check = controller.delete_Event_from_repo(title_, description_, link_);
//    if (check)
//        std::cout<<"\nEvent deleted successfully.\n";
//    else
//        std::cout<<"\nI looked everywhere, but it was nowhere to be found.\n";
}

void UI::update_Event_admin_mode() {
    std::string title_initial, description_initial, link_initial, number_of_people_final, minutes_final, hour_final, year_final, month_final, day_final;
    int number_of_people, minutes, hour, year, month, day;
    std::cin.get();
    std::cout<<"title of Event to modify: ";
    std::getline(std::cin, title_initial);
    std::cout<<"\ndescription: ";
    std::getline(std::cin, description_initial);
    std::cout<<"\nlink to event: ";
    std::getline(std::cin, link_initial);
    std::string title_final, description_final, link_final;
    std::cout<<"\nFinal title of event: ";
    std::getline(std::cin, title_final);
    std::cout<<"\nFinal description: ";
    std::getline(std::cin, description_final);
    std::cout<<"\nFinal link to event: ";
    std::getline(std::cin, link_final);
    std::cout<<"\nFinal number of people: ";
    std::getline(std::cin, number_of_people_final);

    std::cout<<"\nFinal duration:\nMinutes: ";
    std::getline(std::cin, minutes_final);

    std::cout<<"\nhour: ";
    std::getline(std::cin, hour_final);

    std::cout<<"\nyear: ";
    std::getline(std::cin, year_final);

    std::cout<<"\nmonth: ";
    std::getline(std::cin, month_final);

    std::cout<<"\nday: ";
    std::getline(std::cin, day_final);


    if(day==30 || day == 31)
        if(month==2)
            std::cout<<"Im not gonna be the one to tell em...\n";


    try {
        this->validator.validateInteger(number_of_people_final);
        number_of_people = std::stoi(number_of_people_final);
        this->validator.validateNumberOfPeople(number_of_people);
        this->validator.validateInteger(day_final);
        this->validator.validateInteger(month_final);
        this->validator.validateInteger(year_final);
        this->validator.validateInteger(hour_final);
        this->validator.validateInteger(minutes_final);
        day = std::stoi(day_final);
        month = std::stoi(month_final);
        year = std::stoi(year_final);
        minutes = std::stoi(minutes_final);
        hour = std::stoi(hour_final);
        this->validator.validateDay(day);
        this->validator.validateMonth(month);
        this->validator.validateYear(year);
        this->validator.validateHour(hour);
        this->validator.validateMinute(minutes);
    }
    catch (ValidationException &ex) {
        std::cout << ex.what() << std::endl;
        return;
    }


    try{

        controller.update_Event_in_repo(title_initial,description_initial,link_initial, title_final,description_final,link_final,Duration(minutes, hour, year, month, day), number_of_people);
        std::cout << "\nEvent updated successfully.\n";
    }

    catch(RepositoryException &ex){
            std::cout<< ex.what();
            //std::cout<<"\nInitial Event dont exist, buy it from walmart first.\n";
            return;
    }

//TODO REDO THIS
//try{
//    bool check = controller.update_Event_in_repo(title_initial,description_initial,link_initial, title_final,description_final,link_final,Duration(minutes, hour, year, month, day), number_of_people);
//    this->validator.validateBool(check);
//    if (check) {
//        std::cout << "\nEvent updated successfully.\n";
//
//    }
//    else
//        std::cout<<"\nInitial Event dont exist, buy it from walmart first.\n";
//}
//catch(ValidationException &ex) {
//    std::cout<< ex.what();
//    std::cout<<"\nInitial Event dont exist, buy it from walmart first.\n";
//    return;
//}

}

void UI::show_Events_admin_mode() {
    std::cout<<"\nAll Events in database: \n";
    //Event* all_Events = controller.get_all_Events();
    std::vector<Event> all_events = controller.get_all_Events();
    int number_of_Events = controller.get_number_of_Events();
//    for (int i=0;i<number_of_Events;i++)
//        //std::cout<<this->controller.event
//        std::cout<<this->controller.get_Event(i).Event_long_string();
    auto print =[](const Event& e) {std::cout<<e.Event_long_string()<<"\n";};
    std::for_each(all_events.begin(), all_events.end(), print);

}

void UI::start_user_mode() {
    std::cout<<"Welcome user!\n";
    print_user_menu();
    std::string choice;
    std::cin>>choice;
    if(choice.find_first_not_of("0123456789") == std::string::npos)
    {
        int choice_integer = std::stoi(choice);
        switch(choice_integer){
            case 1:
                see_Events_by_a_given_month();
                break;
            case 2:
                show_Events_agenda();
                break;
            case 3:
                play_agenda_user_mode();
                break;
            case 4:
                return;
            default:
                std::cout<<"Option does not exist.\n";
        }
    }
    else
        std::cout<<"Option does not exist.\n";
    start_user_mode();
}

void UI::print_user_menu() {
    std::cout<<"User menu:\n";
    std::cout<<"1. See Events by a given month (1-12).\n";
    std::cout<<"2. See agenda.\n";
    std::cout<<"3. Play agenda.\n";
    std::cout<<"4. Exit application.\n";
}

void UI::show_Events_agenda() {
    std::cout<<"\nAll Events in the agenda:\n";
    //Event* all_Events_in_agenda = controller.get_agenda_Events();
//    int number_of_Events_in_agenda = controller.get_number_of_Events_agenda();
//    for(int i=0;i<number_of_Events_in_agenda;i++)
//        std::cout<<this->controller.get_Event(i).Event_string();
    controller.save_agenda_to_file();
    controller.show_agenda_from_file();
}




void UI::see_Events_by_a_given_month() {
    controller.sort_by_date();
    std::cout<<"Choose a month: ";
    std::string month;
    std::cin.get();
    std::getline(std::cin, month);
    Event* repo_monthly;
    int number_of_Events;


    if (!month.empty()) {


            //if(month.find_first_not_of("0123456789") == std::string::npos){
            int month_int;
            try{
                this->validator.validateInteger(month);
                month_int = std::stoi(month);
                this->validator.validateMonth(month_int);
            }
            catch(ValidationException &ex){
                std::cout<<ex.what();
                return;
            }
            repo_monthly = controller.get_all_Events_by_month(month_int, number_of_Events);
//        }
//        else
//        {
//            std::cout<<"Invalid month.\n";
//            return;
//        }

    }
    else {


        //repo_monthly = controller.get_all_Events();
        number_of_Events = controller.get_number_of_Events();
    }
    //controller.sort_by_date(repo_monthly);
    if (repo_monthly) {
        for (int i = 0; i < number_of_Events; i++)

            if (!play_Event_for_adding_user_mode(repo_monthly[i]))
                break;
            else if (i == number_of_Events - 1)
                i = -1;
    }
    else{
        for (int i = 0; i < number_of_Events; i++)
            if(!play_Event_for_adding_user_mode(this->controller.get_Event(i)))
                break;
            else if (i == number_of_Events - 1)
                i = -1;
    }

}

bool UI::play_Event_for_adding_user_mode(Event Event) {
    std::cout<<Event.Event_long_string();
    Event.play();
    std::string answer;
    int i = 0;
        do {
            std::cout<<"Would you like to add it to your agenda?\n";
            std::getline(std::cin, answer);
        }
        while(answer!="yes" && answer!="no");
        if (answer == "yes") {
            add_Event_to_agenda_user_mode(Event, i);


        }
    do {
        std::cout<<"\nWould you like to skip to the next Event?\n";
        std::getline(std::cin, answer);
    }
    while(answer!="yes" && answer!="no");
    if (answer=="yes")
        return true;
    else
        return false;
}

void UI::add_Event_to_agenda_user_mode(Event& Event, int& i) {


    try{
        controller.add_Event_to_agenda(Event);
        std::cout << "Event added successfully to the agenda\n";
    }

    catch(RepositoryException &ex){
        //std::cout<<ex.what();
        std::cout << "Error occurred. You cannot add the same Event multiple times.\n";
    }
//    try {
//        bool check = controller.add_Event_to_agenda(Event);
//        this->validator.validateBool(check);
//        if (check) {
//            std::cout << "Event added successfully to the agenda\n";
//            add_participation_to_event(Event, i);
//            i++;
//        }
//    }
//    catch (ValidationException &ex) {
//        std::cout<<ex.what();
//        std::cout << "Error occurred. You cannot add the same Event multiple times.\n";
//
//    }
}
//
//
//
void UI::play_agenda_user_mode() {
    std::cout<<"\nPlaying your agenda:\n";
    //for(int i = 0; i<controller.get_number_of_Events_agenda(); i++)
    //while (controller.get_number_of_Events_agenda() > 0)
    int i=0;
    while(i<controller.get_number_of_Events_agenda()){
        play_Event_agenda_user_mode(controller.get_Event_position_agenda(i), i);
        i++;
    }
}

void UI::play_Event_agenda_user_mode(Event Event, int& i) {
    std::cout<<Event.Event_string();
    Event.play();
    std::cout<<"Delete event from agenda?\n";
    std::string answer;
    std::getchar();
    std::getline(std::cin, answer);
    if (answer=="yes") {
        controller.delete_Event_from_agenda(Event);
        decrease_participation_to_event(Event);
        i--;
        std::cout << "The Event has been deleted from your agenda.\n";
    }




}

void UI::add_participation_to_event(Event &Event, int i) {
    int people_coming = Event.get_number_of_people() + 1;
    controller.update_Event_in_repo(Event.get_title(), Event.get_description(), Event.get_link(), Event.get_title(), Event.get_description(), Event.get_link(), Event.get_duration(), people_coming);
    //controller.delete_Event_from_agenda(Event);
    //controller.get_Event_position_agenda(0)
    //Event.set_number_of_people(people_coming);
    //controller.update_Event_in_agenda(i,people_coming);
}

void UI::decrease_participation_to_event(Event &Event) {
    int people_coming = Event.get_number_of_people();
    controller.update_Event_in_repo(Event.get_title(), Event.get_description(), Event.get_link(), Event.get_title(), Event.get_description(), Event.get_link(), Event.get_duration(), people_coming);
}


void UI::read_Events_from_file_admin() {
    std::cout<<"Reading Events: Events.txt\n";
    std::ifstream f("C:/Users/HP/Downloads/a7-8v5/a7-8v2/a7-8/events.txt");
    if (!f.is_open())
        return;
    controller.clear_repo_and_events();
    Event input{};
    while (f>>input)
    {
        //std::cout<<input.get_number_of_people()<<' ';
        controller.add_Event_to_repo(input.get_title(),input.get_description(),input.get_link(),input.get_duration(),input.get_number_of_people());
    }
    std::cout<<"Events read successfully.\n";
    f.close();
}

void UI::save_Events_admin(){
    std::cout<<"Save the Events to the file\n";
    std::ofstream f("C:/Users/HP/Downloads/a7-8v5/a7-8v2/a7-8/events.txt");
    if (!f.is_open())
        return;
    std::vector<Event> evs = controller.get_all_Events();
    for (auto e:evs)
        f<<e<<"\n";
    std::cout<<"Events saved successfully\n";
    f.close();
}
 */