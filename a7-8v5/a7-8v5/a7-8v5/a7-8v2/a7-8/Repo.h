#ifndef A5_6_REPO_H
#define A5_6_REPO_H

#pragma once
#include "DynamicVector.h"
#include "Event.h"
#include <vector>
#include <iostream>
//#pragma once
//#include "DynamicVector.h"


class Repo {
private:
    //DynamicVector<Event> arr;
    std::vector<Event> array;
    std::string EventFileName;

public:

    Repo();

    void loadEventFromFile();

    void writeEventToFile();

    void initRepo();

    std::vector<Event>& getAll();
    //TODO check if explicit breaks the code
    explicit Repo(std::vector<Event>& repo_vect,  std::string& event_filename);
    //Gets all the Events in the repo
    //Event* get_all_Events() const;
    //Adds an Event to the repo

    ///bool add_Event(const Event& new_tutorial);
    void add_Event(const Event& new_tutorial);
    //Deletes an Event from the repo
    ///bool delete_Event(const Event& to_delete);
    void delete_Event(const Event& to_delete);
    //Updates an Event in the repo
    ///bool update_Event(const Event& initial, const Event& final);
    void update_Event(const Event& initial, const Event& final);
    //Gets the number of Events in the repo
    int get_number_of_Events()const;
    //Gets the Event from a certain position
    Event get_event_from_pos(int position) const;
    Event get_event(int i) const;
    int findByTitle(const std::string& title);

    std::vector<Event> get_all_events() const;
};

class RepositoryException: public std::exception{
private:
    std::string message;
public:
    explicit RepositoryException(std::string& _message);

    const char *what() const noexcept override;
};

#endif //A5_6_REPO_H