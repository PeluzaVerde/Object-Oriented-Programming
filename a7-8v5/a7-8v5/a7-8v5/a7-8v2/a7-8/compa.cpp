//
// Created by HP on 5/6/2022.
//

#include "compa.h"


bool ComparatorAscendingByPpl::compare(Event first, Event second) {
    if (first.get_number_of_people()>second.get_number_of_people())
        return false;
    return true;
}



bool ComparatorAscendingByTitle::compare(Event first, Event second) {
    if (first.get_title()>second.get_title())
        return false;
    return true;
}