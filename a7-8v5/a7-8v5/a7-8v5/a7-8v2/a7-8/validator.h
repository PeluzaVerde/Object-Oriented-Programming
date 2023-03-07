//
// Created by Owner on 4/16/2022.
//

#ifndef A5_6_VALIDATOR_H
#define A5_6_VALIDATOR_H
#include "Event.h"

class ValidationException: public std::exception{
private:
    std::string message;

public:
    explicit ValidationException(std::string& _message);

    const char *what() const noexcept override;
};

class EventValidator{
public:
    EventValidator();

    bool validateString(const std::string& input);

    void validateNumberOfPeople(int number_of_people);

    void validateEvent( Event* e, Event* e2);

    void validateInteger(const std::string& intinput);

    void validateHour(int hour);
    void validateMinute(int minute);
    void validateDay(int day);
    void validateMonth(int month);
    void validateYear(int year);

    void validateBool(bool var);

    ~EventValidator();
};






















#endif //A5_6_VALIDATOR_H
