
#include "Repo.h"
#include "Agenda.h"
#include "compa.h"
#include "undoclass.h"
#include "redoclass.h"
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <map>
#include <exception>
//#include <stack>
//#include <memory>

//class ICommand{

//public:
//    virtual void execute()=0;
//    virtual void undo1();
//    virtual void redo1();

//};

//typedef std::stack<std::shared_ptr<ICommand> > commandStack_t;
class Controller {
private:
    Repo repo;
    Agenda* agenda;
    std::vector<std::unique_ptr<doUndo>> undo_list;
    std::vector<std::unique_ptr<doRedo>> redo_list;
//    commandStack_t
    int undocounter;
public:
    Controller(Repo r, Agenda *a);
    Controller(Repo r);

    Controller();
    Controller(const Controller& s);

    //Adds a new Event
    ///bool add_Event_to_repo(std::string title, std::string description, std::string link, Duration duration, int number_of_people);
    void add_Event_to_repo(std::string title, std::string description, std::string link, Duration duration, int number_of_people);
    //Deletes a Event
    ///bool delete_Event_from_repo(std::string title, std::string description, std::string link);
    void delete_Event_from_repo(std::string title, std::string description, std::string link);
    //Updates a Event
    ///bool update_Event_in_repo(std::string initial_title, std::string initial_description, std::string initial_link, std::string final_title, std::string final_presenter, std::string final_link, Duration final_duration, int final_number_of_people);
    void update_Event_in_repo(std::string initial_title, std::string initial_description, std::string initial_link, std::string final_title, std::string final_presenter, std::string final_link, Duration final_duration, int final_number_of_people);
    //Gets the Events
    //Event* get_all_Events() const;
    //Gets nr of Events
    int get_number_of_Events() const;
    //Initialize repo with 10 Events
    ///void initialise_repo();

    void undo();

    void redo();







    void sort_by_date();

    //gets all the events from a month or all events
    Event* get_all_Events_by_month(int month, int &nr_Events) const;
    //adds event to agenda
    ///bool add_Event_to_agenda(Event& to_add) ;
    void add_Event_to_agenda(Event& to_add) ;
    //deletes an event from a users' agenda
    ///bool delete_Event_from_agenda(Event& to_delete) ;
    void delete_Event_from_agenda(Event& to_delete) ;
    //agenda events getter
    Event* get_agenda_Events() const ;
    //gets a specific event in agenda via position
    Event get_Event_position_agenda(int position);
    //Len of events from agenda
    int get_number_of_Events_agenda() const;

    Event get_Event(int i) const;
    //void update_Event_in_agenda(int pos, int nr) ;

    Event get_Event_agenda(int i) const;

    void change_agenda(Agenda *a);

    void save_agenda_to_file();

    void show_agenda_from_file();

    std::vector<Event> get_all_Events() const;

    std::vector<Event> get_all_Agenda_Events() const;

    std::vector<Event> get_all_Events_by_monthv2(int month) const;

    void clear_repo_and_events();

    template <typename TElem>
    void sortElems(std::vector<TElem>& v, Comparator<TElem>* c)
    {
        bool sorted = true;

        do
        {
            sorted = true;

            for (int i = 0; i < v.size() - 1; i++)
            {
                if (!c->compare(v[i], v[i + 1]))
                {
                    std::swap(v[i], v[i + 1]);
                    sorted = false;
                }
            }
        } while (!sorted);
    };
};
