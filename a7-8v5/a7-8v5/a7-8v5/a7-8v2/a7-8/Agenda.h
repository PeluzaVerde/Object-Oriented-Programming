#pragma once
#include "Repo.h"
#include "Event.h"
class Agenda
{
//	int currentIndex;

protected:
    Repo events;
public:
	~Agenda();
    // add event to agenda
	///bool addEvent(const Event& event);
	void addEvent(const Event& event);
    //deletes event from agenda
    ///bool deleteEvent(const Event& event);
    void deleteEvent(const Event& event);
    //gets all events from agenda
    //Event* get_all_events()const;
    //gets nr of events from agenda
    int get_nr_of_event()const;
    //gets a certain event from a position from agenda
    Event get_event_from_agenda(int pos) const;
	//youtube.mp4
    //void play() const;

    std::vector<Event> get_all_events()const;
    Event get_Event(int i) const;

    //saves to file
    virtual void save_agenda_to_file() const = 0;

    //shows watchlist from file
    virtual void show_agenda_from_file() const = 0;
};

