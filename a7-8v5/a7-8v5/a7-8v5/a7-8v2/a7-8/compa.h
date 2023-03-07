#pragma once
#include "Event.h"


template <typename Type> class Comparator{
public:
    Comparator();
    ~Comparator();
    virtual bool compare(Type first, Type second) = 0;
};

template<typename Type>
Comparator<Type>::Comparator() {

}

template<typename Type>
Comparator<Type>::~Comparator() {

}

class ComparatorAscendingByPpl : public Comparator<Event>{
    bool compare(Event first, Event second) override;
};


class ComparatorAscendingByTitle : public Comparator<Event>{
public:
    bool compare(Event first, Event second) override;

};
