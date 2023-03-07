//
// Created by HP on 3/21/2022.
//
/*
//#pragma once
#include "Controller.h"
#include "validator.h"

class UI {
private:
    Controller controller;
    EventValidator validator;
    int mode ; //0 for admin, 1 for user
public:
    explicit UI(const EventValidator& v);
    //Starts up the application
    void start_application();
    //Chooses the mode of the application
    void choose_mode();

    //Starts admin mode of application
    void start_admin_mode();
    //Prints admin menu for application
    static void print_admin_menu();
    //Add a Event admin mode
    void add_Event_admin_mode();
    //Delete a Event admin mode
    void delete_Event_admin_mode();
    //Update a Event admin mode
    void update_Event_admin_mode();
    //Show all Events admin mode
    void show_Events_admin_mode();



    //Starts user mode of application
    void start_user_mode();
    //Prints user menu for application
    void print_user_menu();
    //Shows all Events in agenda
    void show_Events_agenda();
    //Plays Event with option to add to agenda
    bool play_Event_for_adding_user_mode(Event Event);
    //Adds a Event to the agenda
    void add_Event_to_agenda_user_mode(Event& Event, int& i);


    //Shows the Events by a given month or all events
    void see_Events_by_a_given_month();
    //Plays an Event for the user in agenda
    void play_Event_agenda_user_mode(Event Event, int& i);
    //Increases people attending an event
    void add_participation_to_event(Event& Event, int i);
    //Decreases the people attending an event
    void decrease_participation_to_event(Event& Event);


    //Plays agenda in user mode
    void play_agenda_user_mode();


    void read_Events_from_file_admin();

    void save_Events_admin();
};
*/