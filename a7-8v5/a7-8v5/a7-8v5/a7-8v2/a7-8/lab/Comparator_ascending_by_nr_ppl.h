//
// Created by Oana on 4/18/2022.
//

#pragma once

#include "Comparator.h"

class Comparator_ascending_by_nr_ppl : public Comparator<int>{
public:
    Comparator_ascending_by_nr_ppl(){};
    bool compare(int t1, int t2) const;

};

