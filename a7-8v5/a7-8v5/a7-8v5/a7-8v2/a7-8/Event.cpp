#include "Event.h"
#include <vector>
#include <sstream>
Event::Event(std::string _title, std::string _description, std::string _link, int _nr_of_people,
               Duration _duration) {

    title=_title;
    description= _description;
    link = _link;
    number_of_people = _nr_of_people;
    duration = _duration;
}

Event::Event() {
    title="";
    description="";
    duration= Duration();
    link = "";
    number_of_people=0;
}

Event::Event(const Event&copy) {
    this->title = copy.title;
    this->description= copy.description;
    this->link = copy.link;
    this->number_of_people = copy.number_of_people;
    this->duration = copy.duration;
}

std::string Event::get_title() const {
    return this->title;
}

std::string Event::get_description() const {
    return this->description;
}

std::string Event::get_link() const {
    return this->link;
}

int Event::get_number_of_people() const {
    return this->number_of_people;
}

Duration Event::get_duration() const {
    return this->duration;
}

void Event::set_description(std::string _description) {
    this->description = _description;
}

void Event::set_link(std::string _link) {
    this->link  = _link;
}

void Event::set_title(std::string _title) {
    this->title = _title;
}

void Event::set_duration(Duration _duration) {
    this->duration = _duration;
}

void Event::set_number_of_people(int _nr_people) {
    this->number_of_people = _nr_people;
}

bool Event::operator==(const Event&t) {
    if (title != t.title || t.description != description || t.link != link)
        return false;
    return true;
}

Event::Event(std::string _title, std::string _description, std::string _link) {
    title = _title;
    description = _description;
    link = _link;
    duration = Duration();
    number_of_people = 0;
}

//std::string Event::Event_string() const{
//    std::string Event= "Event: " + get_title() + " description " + get_description() + " with " + std::to_string(number_of_people) + " people.\n";
//    return Event;
//}


std::string Event::Event_string() const{
    std::string Event= "Event: "+ get_title() + " description " +get_description() + ". On the time and date: "+std::to_string(duration.get_hour())+":"+std::to_string(duration.get_minutes())+" "+ std::to_string(duration.get_day())+"/"+std::to_string(duration.get_month())+"/"+std::to_string(duration.get_year())+" at the following link: "+link+"\n";
    return Event;
}


std::string Event::Event_long_string() const {
    std::string Event= "Event: "+ get_title() + " description " +get_description() + ". On the time and date: "+std::to_string(duration.get_hour())+":"+std::to_string(duration.get_minutes())+" "+ std::to_string(duration.get_day())+"/"+std::to_string(duration.get_month())+"/"+std::to_string(duration.get_year())+" with "+std::to_string(get_number_of_people())+" people.\n";
    return Event;
}

void Event::play() const {
    ShellExecuteA(NULL, NULL, "opera.exe", this->get_link().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::vector<std::string> field_delimiter(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string field;
    while (getline(ss, field, delimiter))
        result.push_back(field);
    return result;
}

std::istream &operator>>(std::istream &inputStream, Event &e) {
    std::string line;
    std::getline(inputStream, line);
    std::vector<std::string> fields;
    if (line.empty())
        return inputStream;
    fields = field_delimiter(line, ',');
    e.title = fields[0];
    e.description = fields[1];
    e.link = fields[2];
    e.duration = Duration(std::stoi(fields[3]),std::stoi(fields[4]),std::stoi(fields[5]),std::stoi(fields[6]),std::stoi(fields[7]));
    e.number_of_people = std::stoi(fields[8]);
    return inputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const Event &eventOutput) {
    outputStream << eventOutput.title << "," <<eventOutput.description<< "," << eventOutput.link<< "," <<
    eventOutput.duration.get_hour()<< "," << std::to_string(eventOutput.duration.get_minutes())<<
    "," << std::to_string(eventOutput.duration.get_year())<< "," << std::to_string(eventOutput.duration.get_month())<<
    "," << std::to_string(eventOutput.duration.get_day()) << "," << std::to_string(eventOutput.get_number_of_people());
    return outputStream;
}
