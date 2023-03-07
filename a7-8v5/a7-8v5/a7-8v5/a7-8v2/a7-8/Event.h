#include <string>
#include <windows.h>
#include "Duration.h"
#pragma once


class Event{
private:
    std::string title;
    std::string description;
    std::string link;
    int number_of_people;
    Duration duration;
public:
    //constructors
    Event();
    Event(std::string _title, std::string _description, std::string _link, int _nr_of_people, Duration _duration);
    Event(const Event& copy);
    Event(std::string _title, std::string _description, std::string _link);

    //getters
    std::string get_title() const;
    std::string get_description() const;
    std::string get_link() const;
    int get_number_of_people() const;
    Duration get_duration() const;

    ///setters
    void set_title(std::string _title);
    void set_description(std::string _description);
    void set_link(std::string _link);
    void set_duration(Duration _duration);
    void set_number_of_people(int _nr_people);

    //equality checker
    bool operator==(const Event& t);

    //to string
    std::string Event_string() const;
    std::string Event_long_string() const;

    friend std::istream& operator>>(std::istream& inputStream, Event& e);

    friend std::ostream & operator<<(std::ostream& outputStream, const Event& eventOutput);

    //play Event
    void play() const;


};