//
// Created by Owner on 4/27/2022.
//

#pragma once
#include "Agenda.h"

class Agenda_csv: public Agenda {
private:
    std::string file_path;
public:
    Agenda_csv(std::string file_path);

    void save_agenda_to_file() const override;

    void show_agenda_from_file() const override;

};
