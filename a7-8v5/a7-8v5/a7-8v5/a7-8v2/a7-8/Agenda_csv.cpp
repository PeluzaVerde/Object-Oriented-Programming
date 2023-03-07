//
// Created by Owner on 4/27/2022.
//

#include "Agenda_csv.h"
#include <fstream>
Agenda_csv::Agenda_csv(std::string file_path) {
    this->file_path = file_path;
}

void Agenda_csv::save_agenda_to_file() const {
//    Agenda::save_agenda_to_file();
    std::ofstream f(file_path);
    if (!f.is_open())
        return;
    //std::cout<<"saving\n";
    for (const auto& r: events.get_all_events())
    {
        f << r<<'\n';
    }
    f.close();
}

void Agenda_csv::show_agenda_from_file() const {
    const char* fp = file_path.c_str();
    ShellExecuteA(NULL, "open",fp, NULL,NULL,SW_SHOWNORMAL);

}
