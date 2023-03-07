//
// Created by Owner on 4/27/2022.
//

#include "Agenda_html.h"
#include <fstream>

Agenda_html::Agenda_html(std::string file_path) {
    this->file_path = file_path;
}

void Agenda_html::save_agenda_to_file() const {
    //Agenda::save_agenda_to_file();
    std::ofstream f(file_path);
    if (!f.is_open())
        return;
    f<<"<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<title>agenda</title>\n\t</head>\n\t<body>\n\t\t<table border=\"\">\n";
    f<<"\t\t<tr>\n\t\t\t<td>Title</td>\n\t\t\t<td>Description</td>\n\t\t\t<td>Duration</td>\n\t\t\t<td>Link</td>\n\t\t\t<td>People</td>\n\t\t</tr>\n";
    for (auto r: events.get_all_events())
    {
        f<<"\t\t<tr>\n";
        f<<"\t\t\t<td>"<<r.get_title()<<"</td>\n";
        f<<"\t\t\t<td>"<<r.get_description()<<"</td>\n";
        f<<"\t\t\t<td>"<<r.get_duration().get_hour()<<":"<<r.get_duration().get_minutes()<<" "<<r.get_duration().get_day()<<"/"<<r.get_duration().get_month()<<"/"<<r.get_duration().get_year()<<" </td>\n";
        f<<"\t\t\t<td><a href = \""<<r.get_link()<<"\">Link</a></td>\n";
        f<<"\t\t\t<td>"<<r.get_number_of_people()<<"</td>\n";
        f<<"\t\t</tr>\n";
    }
    f<<"\t\t</table>\n\t</body>\n</html>\n";
    f.close();
}

void Agenda_html::show_agenda_from_file() const {
    const char* fp = file_path.c_str();
    ShellExecuteA(NULL, "open",fp, NULL,NULL,SW_SHOWNORMAL);
}
