//
// Created by Owner on 4/16/2022.
//

#include "validator.h"


ValidationException::ValidationException(std::string &_message): message(_message) {}

const char* ValidationException::what() const noexcept {
    return message.c_str();
}
EventValidator::EventValidator() = default;

bool EventValidator::validateString(const std::string& input) {
    for (char i : input)
        if (isdigit(i) != false)
            return false;
    return true;
}

void EventValidator::validateEvent( Event* e, Event* e2) {
    std::string errors;
    if (e->get_title()==e2->get_title() && e->get_description()==e2->get_description() && e->get_link()==e2->get_link())
        errors += std::string("This event already exists!");
    if (!errors.empty())
        throw ValidationException(errors);
}



void EventValidator::validateInteger(const std::string& intinput) {
    std::string errors;
    if (intinput.empty())
        errors += std::string("The input is empty!");
    if (intinput.find_first_not_of("0123456789") != std::string::npos)
        errors += std::string("The input isnt a number!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateNumberOfPeople(int number_of_people) {
    std::string errors;
    if (number_of_people<0)
        errors += std::string("The number of people cannot be smaller than 0!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateHour(int hour) {
    std::string errors;
    if (hour<0 || hour > 23)
        errors += std::string("The hour is invalid");
    if(!errors.empty())
        throw ValidationException(errors);

}

void EventValidator::validateMinute(int minute) {
    std::string errors;
    if (minute<0 || minute > 60)
        errors += std::string("The Minutes are invalid");
    if(!errors.empty())
        throw ValidationException(errors);

}

void EventValidator::validateDay(int day) {
    std::string errors;
    if (day<0 || day > 31)
        errors += std::string("The day is invalid");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateMonth(int month) {
    std::string errors;
    if (month<0 || month>12)
        errors += std::string("The month is invalid");
    if(!errors.empty())
        throw ValidationException(errors);

}

void EventValidator::validateYear(int year) {
    std::string errors;
    if (year<2000 || year > 3000)
        errors += std::string("The year is invalid");
    if(!errors.empty())
        throw ValidationException(errors);

}

void EventValidator::validateBool(bool var) {
    std::string errors;
    if (!var)
        errors += std::string("Error found: ");
    if(!errors.empty())
        throw ValidationException(errors);
}


EventValidator::~EventValidator()=default;