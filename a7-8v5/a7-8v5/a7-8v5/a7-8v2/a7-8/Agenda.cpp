#include "Agenda.h"

//Agenda::Agenda()
//{
//    currentIndex=0;
//}

//bool Agenda::addEvent(const Event& event)
//{
//	return events.add_Event(event);
//}

void Agenda::addEvent(const Event& event)
{
    events.add_Event(event);
}

//bool Agenda::deleteEvent(const Event& event)
//{
//    return events.delete_Event(event);
//}

void Agenda::deleteEvent(const Event& event)
{
    events.delete_Event(event);
}

//Event* Agenda::get_all_events() const {
//    return events.get_all_Events();
//}

Event Agenda::get_Event(int i) const {
    //return this->get_Event(i).get_event(i);
    return this->events.get_event(i);
}

int Agenda::get_nr_of_event() const{
    return events.get_number_of_Events();
}
//void Agenda::play() const
//{
//	//Event* allTheEvents = events.get_all_Events();
//
//	//allTheEvents[currentIndex].play();
//	this->events.get_event(currentIndex).play();
//}

std::vector<Event> Agenda::get_all_events() const {
    return events.get_all_events();
}

Event Agenda::get_event_from_agenda(int pos) const{
    return events.get_event_from_pos(pos);
}
Agenda::~Agenda(){

}



