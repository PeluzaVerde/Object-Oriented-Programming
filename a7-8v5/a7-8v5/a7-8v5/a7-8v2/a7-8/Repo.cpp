#include "Repo.h"
#include <fstream>
#include <algorithm>

RepositoryException::RepositoryException(std::string &_message) : message(_message){}

const char* RepositoryException::what() const noexcept {
    return message.c_str();
}

Repo::Repo() {

}


Repo::Repo(std::vector<Event>& repo_vect, std::string& event_filename) {
this->EventFileName = event_filename;
this->array= repo_vect;
}

//Repo::Repo() = default;

//Event *Repo::get_all_Events() const {
//    return arr.get_all_elems();
//}

void Repo::loadEventFromFile() {

    if(!this->EventFileName.empty()){
        Event eventFromFile;
        std::ifstream  fin(this->EventFileName);
        while(fin >> eventFromFile){
        if(std::find(this->array.begin(), this->array.end(), eventFromFile)==
        this->array.end())
        this->array.push_back(eventFromFile);
        }
        fin.close();
    }

}

void Repo::writeEventToFile(){
    if(!this->EventFileName.empty()){
        std::ofstream fout(this->EventFileName);
        for(const Event &e: this->array){
            fout << e <<"\n";
        }
        fout.close();
    }
}

void Repo::initRepo(){
    this->loadEventFromFile();
}

std::vector<Event>& Repo::getAll(){
    return this->array;
}


//bool Repo::add_Event(const Event &new_event) {
//    int nr_elements = arr.get_size();
//    arr.add_element(new_event);
//
//    //arr+new_event;
//    //new_event+arr;
//    if (arr.get_size()-1 == nr_elements)
//        return true;
//    else {
//        std::string error;
//        //error+= std::string("CE DRACU NU MERGE!");
//        //if(!error.empty())
//            //throw RepositoryException(error);
//        return false;
//    }

void Repo::add_Event(const Event &new_event) {


int existing = this->findByTitle(new_event.get_title());
if (existing != -1) {
    if (array[existing] == new_event) {
        std::string err;
        err += std::string("Event already exists!");
        if (!err.empty())
            throw RepositoryException(err);
    }
}
this->array.push_back(new_event);
this->writeEventToFile();
}



//bool Repo::delete_Event(const Event &to_delete) {
//    int nr_elements = arr.get_size();
//    arr.delete_element(to_delete);
//    if(nr_elements-1 == arr.get_size())
//        return true;
//    else
//        return false;
//}

void Repo::delete_Event(const Event &to_delete) {

    int existing = this->findByTitle(to_delete.get_title());
    if (existing == -1) {
        if (!(array[existing] == to_delete)) {
            std::string err;
            err += std::string("I looked everywhere, but it was nowhere to be found.!");
            if (!err.empty())
                throw RepositoryException(err);
        }
    }

    auto position = std::find(array.begin(), array.end(), to_delete);
    array.erase(position);
    this->writeEventToFile();
}
//bool Repo::update_Event(const Event &initial, const Event &final) {
//    int pos = arr.position_element(initial);
//    if (pos==-1)
//        return false;
//    arr.update_element(initial, final);
//    //if (arr.get_element_from_position(pos)==final)
//        return true;
//
//}

void Repo::update_Event(const Event &initial, const Event &final) {

    int existing = this->findByTitle(initial.get_title());
    if (existing == -1) {
        if (!(array[existing] == initial)) {
            //std::cout<<array[existing].get_title()<<' '<<array[existing].get_description();
            std::string err;
            err += std::string("Initial Event dont exist, buy it from walmart first.");
            if (!err.empty())
                throw RepositoryException(err);
        }
    }
    auto position = std::find(array.begin(), array.end(), initial);
    int pos = position - array.begin();
    array[pos] = final;
    this->writeEventToFile();

}
int Repo::get_number_of_Events() const {
    return array.size();
}

Event Repo::get_event_from_pos(int position) const {
    return array[position];
}

Event Repo::get_event(int i) const {
    return this->array[i];
}

std::vector<Event> Repo:: get_all_events() const{
    return array;
}
int Repo::findByTitle(const std::string &title) {
    int search = -1;
    std::vector<Event>::iterator it;
    it = std::find_if(this->array.begin(), this->array.end(), [&title](Event& event){return event.get_title() == title;});
    if (it != this->array.end())
    {
        search = it - this->array.begin();
    }
    return search;


    //std::sort(array.begin(),array.end(), array)
}


