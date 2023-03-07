#include "Controller.h"

Controller::Controller(Repo r, Agenda *a) : repo(r) {
    this->repo = r;
    agenda = a;
    undocounter=0;
}

Controller::Controller() {
    undocounter=0;
}

Controller::Controller(const Controller &s) {
    this->repo = s.repo;
    this->agenda = s.agenda;
    undocounter=0;
}
void Controller::add_Event_to_repo(std::string title, std::string description, std::string link, Duration duration,
                                   int number_of_people) {
    Event to_add = Event(title, description, link, number_of_people, duration);
    repo.add_Event(to_add);

    undo_list.push_back(std::make_unique<UndoAdd>(repo, title));
    redo_list.push_back(std::make_unique<RedoDel>(repo, to_add));
}

//bool Controller::add_Event_to_repo(std::string title, std::string description, std::string link, Duration duration,
//                                 int number_of_people) {
//    Event to_add = Event(title, description, link, number_of_people, duration);
//    return repo.add_Event(to_add);
//}

void Controller::delete_Event_from_repo(std::string title, std::string description, std::string link) {
    int todel = repo.findByTitle(title);
    auto ev = this->get_Event(todel);
    Event to_delete = Event(ev.get_title(), ev.get_description(), ev.get_link(), ev.get_number_of_people(), ev.get_duration());
    undo_list.push_back(std::make_unique<UndoDel>(repo, to_delete));
    redo_list.push_back(std::make_unique<RedoAdd>(repo, title));
    repo.delete_Event(to_delete);
}

//bool Controller::delete_Event_from_repo(std::string title, std::string description, std::string link) {
//    Event to_delete = Event(title, description, link);
//    return repo.delete_Event(to_delete);
//}

//bool Controller::update_Event_in_repo(std::string initial_title, std::string initial_description, std::string initial_link,
//                               std::string final_title, std::string final_description, std::string final_link,
//                               Duration final_duration, int final_number_of_people) {
//    Event initial = Event(initial_title, initial_description, initial_link);
//    Event final = Event(final_title, final_description, final_link, final_number_of_people, final_duration);
//    return repo.update_Event(initial, final);
//}

void Controller::update_Event_in_repo(std::string initial_title, std::string initial_description, std::string initial_link,
                                      std::string final_title, std::string final_description, std::string final_link,
                                      Duration final_duration, int final_number_of_people) {
    Event initial = Event(initial_title, initial_description, initial_link);
    Event final = Event(final_title, final_description, final_link, final_number_of_people, final_duration);

    int todel = repo.findByTitle(initial_title);
    auto ev = this->get_Event(todel);
    Event to_delete = Event(ev.get_title(), ev.get_description(), ev.get_link(), ev.get_number_of_people(), ev.get_duration());

    undo_list.push_back(std::make_unique<UndoMod>(repo, final_title, to_delete));
    redo_list.push_back(std::make_unique<RedoMod>(repo, initial.get_title(), final));
    repo.update_Event(initial, final);
}

void Controller::undo() {
    if(undo_list.empty()){
        throw std::exception();
    }
Event* e;
    undo_list.back()->undo();
    //redo_list.push_back(undo_list.back());
    undo_list.pop_back();
    undocounter++;
}

void Controller::redo() {
    if(redo_list.empty() || undocounter<=0){
        throw std::exception();
    }
    redo_list.back()->redo();
    //undo_list.push_back(std::make_unique<UndoMod>(repo),redo_list.back);
    redo_list.pop_back();
    undocounter--;
}

//Event *Controller::get_all_Events() const {
//    return repo.get_all_Events();
//}


Event Controller::get_Event(int i) const {
    return this->repo.get_event(i);
}

int Controller::get_number_of_Events() const{
    return repo.get_number_of_Events();
}

//Controller::Controller(const Controller &s) {
//    this->repo = s.repo;
//    this->agenda = s.agenda;
//}

//void Controller::initialise_repo() {
//    add_Event_to_repo("Excursie Adeona cabana ciubaru verde", "Munte 200lei","https://static.wikia.nocookie.net/edwikia/images/5/57/Old_Abandoned_House.jpg/revision/latest?cb=20170322163415",Duration(7,30,2007,6,30), 10);
//    add_Event_to_repo("Qrowozon", "YT", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(6, 15,2022,12,24), 1);
//    add_Event_to_repo("Animalia", "zoo", "https://static.wikia.nocookie.net/edwikia/images/4/47/Vlcsnap-2013-10-26-14h50m19s11.png/revision/latest/scale-to-width-down/250?cb=20131026215043", Duration(4,58,2022,7,5), 10);
//    add_Event_to_repo("a", "b", "c", Duration(4,54,2021,9,20), 9);
//    add_Event_to_repo("Pizza party", "parca fsega", "https://i.ytimg.com/vi/9nTW-R5UheM/maxresdefault.jpg", Duration(15, 46,2020,3,12), 6);
//    add_Event_to_repo("Allnighter", "OOP", "https://www.looper.com/img/gallery/things-only-adults-notice-in-ed-edd-n-eddy/eddys-magazines-1592506552.jpg", Duration(4,35,2001,3,12), 10);
//    add_Event_to_repo("Untold", "music", "https://i.gifer.com/1IC7.gif", Duration(4,40,2022,3,12), 900);
//    add_Event_to_repo("mcdonals", "coada", "https://static.wikia.nocookie.net/ed-edd-n-eddy-location-guide/images/d/d5/PCFF1.PNG/revision/latest?cb=20170317182509", Duration(7,41,2023,3,12), 7);
//    add_Event_to_repo("Smash", "Varga", "https://cn.i.cdn.ti-platform.com/cnemea/content/7393/game/4.0Migration_EdEddnEddy_CuldesacSmash_Cover.jpg", Duration(1,26,2022,12,3), 3);
//    add_Event_to_repo("Code end graduation party", "the code has ended forever","https://eventornado.com/?gclid=CjwKCAjwuYWSBhByEiwAKd_n_hyhnpYbe9iZvOLa5TaD0GTs5YDKFKc3Z-h6MB6tBO-Jj8sCip9N9hoCxy0QAvD_BwE", Duration(8,6,2060,9,9), 9);
//}
//
//Event *Controller::get_agenda_Events() const {
//    Event* Events_in_agenda = agenda.get_all_events();
//    return Events_in_agenda;
//}
Event Controller::get_Event_agenda(int i) const {
    return this->agenda->get_Event(i);

}

int Controller::get_number_of_Events_agenda() const {
    return agenda->get_nr_of_event();
}

Event* Controller::get_all_Events_by_month(int month, int &nr_Events) const{
    Event* result  = new Event[repo.get_number_of_Events()];
    nr_Events = 0;
    //Event* Events = repo.get_all_Events();
    for(int i=0;i<repo.get_number_of_Events();i++) {
        Event Events = this->get_Event(i);
        if (Events.get_duration().get_month() == month)
            result[nr_Events++] = Events;
    }
    return result;
}


std::vector<Event> Controller::get_all_Events_by_monthv2(int month) const{
    std::vector<Event> result ;

    if (month == 0)
        return repo.get_all_events();
    //Event* Events = repo.get_all_Events();
    for(int i=0;i<repo.get_number_of_Events();i++) {
        Event Events = this->get_Event(i);
        if (Events.get_duration().get_month() == month)
           result.push_back(Events);
    }
    return result;
}

//bool Controller::add_Event_to_agenda(Event& to_add) {
//    return agenda->addEvent(to_add);
//}
//
//bool Controller::delete_Event_from_agenda(Event& to_delete) {
//    return agenda->deleteEvent(to_delete);
//}
void Controller::add_Event_to_agenda(Event& to_add) {
    agenda->addEvent(to_add);
}

void Controller::delete_Event_from_agenda(Event& to_delete) {
    agenda->deleteEvent(to_delete);
}
Event Controller::get_Event_position_agenda(int position) {
    return agenda->get_event_from_agenda(position);
}

void Controller::sort_by_date()
{
    Event elem,elem2;
    for (int i=0; i< repo.get_number_of_Events()-1;i++)
        for (int j=i+1; j< repo.get_number_of_Events();j++)
            if(repo.get_event_from_pos(i).get_duration().get_year()>repo.get_event_from_pos(j).get_duration().get_year()
            || (repo.get_event_from_pos(i).get_duration().get_year()==repo.get_event_from_pos(j).get_duration().get_year()
            && repo.get_event_from_pos(i).get_duration().get_month()>repo.get_event_from_pos(j).get_duration().get_month())
            || (repo.get_event_from_pos(i).get_duration().get_year()==repo.get_event_from_pos(j).get_duration().get_year()
                && repo.get_event_from_pos(i).get_duration().get_month()==repo.get_event_from_pos(j).get_duration().get_month() &&
                    repo.get_event_from_pos(i).get_duration().get_day()>repo.get_event_from_pos(j).get_duration().get_day() )==1)
            {
                elem = repo.get_event_from_pos(i);
                elem2= repo.get_event_from_pos(j);


                //repo.get_event_from_pos(i) = repo.get_event_from_pos(j);
                //repo.get_event_from_pos(j)= elem;


                //repo.get_all_events()[i]=repo.get_all_events()[j];
                //repo.get_all_events()[j]=elem;
//                repo.get_all_events()[i].set_title(elem2.get_title());
//                repo.get_all_events()[i].set_description(elem2.get_description());
//                repo.get_all_events()[i].set_link(elem2.get_link());
//                repo.get_all_events()[i].set_duration(elem2.get_duration());
//                repo.get_all_events()[i].set_number_of_people(elem2.get_number_of_people());
//
//                repo.get_all_events()[j].set_title(elem.get_title());
//                repo.get_all_events()[j].set_description(elem.get_description());
//                repo.get_all_events()[j].set_link(elem.get_link());
//                repo.get_all_events()[j].set_duration(elem.get_duration());
//                repo.get_all_events()[j].set_number_of_people(elem.get_number_of_people());

//                std::cout<<elem.get_title()<<' '<<elem.get_description()<<' '<<elem.get_link();
                update_Event_in_repo(elem.get_title(),elem.get_description(),elem.get_link(),"placeholder",elem2.get_description(),elem2.get_link(),elem2.get_duration(),elem2.get_number_of_people());
                update_Event_in_repo(elem2.get_title(),elem2.get_description(),elem2.get_link(),elem.get_title(),elem.get_description(),elem.get_link(),elem.get_duration(),elem.get_number_of_people());
                update_Event_in_repo("placeholder",elem2.get_description(),elem2.get_link(),elem2.get_title(),elem2.get_description(),elem2.get_link(),elem2.get_duration(),elem2.get_number_of_people());
            }

    //return repo.get_all_Events();
}
void Controller::save_agenda_to_file() {
    agenda->save_agenda_to_file();
}

void Controller::show_agenda_from_file() {
    agenda->show_agenda_from_file();
}

std::vector<Event> Controller::get_all_Events() const{
    return repo.get_all_events();
}

void Controller::clear_repo_and_events() {
    for (auto e: agenda->get_all_events())
        delete_Event_from_agenda(e);
    for(auto e2:repo.get_all_events())
        delete_Event_from_repo(e2.get_title(),e2.get_description(), e2.get_link());

}

Controller::Controller(Repo r) {
    this->repo = r;
    undocounter=0;
}

void Controller::change_agenda(Agenda *a) {
    this->agenda = a;
    undocounter=0;

}

std::vector<Event> Controller::get_all_Agenda_Events() const {
    return agenda->get_all_events();
}

//void Controller::sortElems(std::vector<Event> &v, Comparator<Event> *c) {
//    bool sorted = true;
//
//    do
//    {
//        sorted = true;
//
//        for (int i = 0; i < v.size() - 1; i++)
//        {
//            if (!c->compare(v[i], v[i + 1]))
//            {
//                std::swap(v[i], v[i + 1]);
//                sorted = false;
//            }
//        }
//    } while (!sorted);
//}
