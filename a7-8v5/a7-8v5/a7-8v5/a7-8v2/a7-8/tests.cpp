////
//// Created by HP on 3/23/2022.
////
//



#include "cassert"
#include "tests.h"
#include "Event.h"
#include "compa.h"
#include "Controller.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <crtdbg.h>
void tests3() {

    Controller controller = Controller();

        std::vector<Event> vector;
//add_Event_to_repo("Excursie Adeona cabana ciubaru verde", "Munte 200lei","https://static.wikia.nocookie.net/edwikia/images/5/57/Old_Abandoned_House.jpg/revision/latest?cb=20170322163415",Duration(7,30,2007,6,30), 10);
//    add_Event_to_repo("Qrowozon", "YT", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(6, 15,2022,12,24), 1);
//    add_Event_to_repo("Animalia", "zoo", "https://static.wikia.nocookie.net/edwikia/images/4/47/Vlcsnap-2013-10-26-14h50m19s11.png/revision/latest/scale-to-width-down/250?cb=20131026215043", Duration(4,58,2022,7,5), 10);

    Event e1 = Event("Qrowozon", "YT", "https://www.youtube.com/watch?v=p9j3TKhOn30", 1,Duration(6, 15,2022,12,24));
    Event e2 = Event("Excursie Adeona cabana ciubaru verde", "Munte 200lei","https://static.wikia.nocookie.net/edwikia/images/5/57/Old_Abandoned_House.jpg/revision/latest?cb=20170322163415",24,Duration(7,30,2007,6,30));
    Event e3 = Event("Animalia", "zoo", "https://static.wikia.nocookie.net/edwikia/images/4/47/Vlcsnap-2013-10-26-14h50m19s11.png/revision/latest/scale-to-width-down/250?cb=20131026215043", 12, Duration(4,58,2022,7,5));


       vector.push_back(e1);
       vector.push_back(e2);
       vector.push_back(e3);

    Comparator<Event>* comp = new ComparatorAscendingByPpl{};
    Comparator<Event>* comp2 = new ComparatorAscendingByTitle{};
    controller.sortElems(vector, comp);
    //std::cout<<vector[1].get_number_of_people();

    assert(vector[0].get_number_of_people() == 1);
    assert(vector[1].get_number_of_people() == 12);
    assert(vector[2].get_number_of_people() == 24);

    controller.sortElems(vector, comp2);
    assert(vector[0].get_title() == "Animalia");
    assert(vector[1].get_title() == "Excursie Adeona cabana ciubaru verde");
    assert(vector[2].get_title() == "Qrowozon");

    delete comp;
    delete comp2;


/*


*/

}
//#include "tests.h"
////#include <stdlib.h>
//#include <cassert>
//#include "Repo.h"
//#include "Controller.h"
//#include <iostream>
//
//
//
//void tests() {
//    Repo repository = Repo();
//    Controller controller = Controller(repository);
//
//    assert(controller.add_Event_to_repo("title_", "description_", "link_", Duration(1,2, 2001, 4, 5), 6)==true);
//    assert(controller.add_Event_to_repo("title_", "description_", "link_", Duration(1,2, 2001, 4, 5), 6)==false);
//    assert(controller.update_Event_in_repo("title_","description_","link_", "title_final","description_final","link_final",Duration(1, 2, 2222, 3, 4), 7)==true);
//    assert(controller.update_Event_in_repo("title_","description_","link_", "title_final","description_final","link_final",Duration(1, 2, 2222, 3, 4), 7)==false);
//    assert(controller.add_Event_to_repo("title_", "description_", "link_", Duration(1,2, 2001, 4, 5), 6)==true);
//    assert(controller.delete_Event_from_repo("title_", "description_", "link_")==true);
//    assert(controller.delete_Event_from_repo("title_", "description_", "link_")==false);
//    //assert(controller.get_all_Events()==controller.get_all_Events());
//    assert(controller.get_number_of_Events()==1);
//    Duration d;
//    d.set_day(1);
//    d.set_hour(1);
//    d.set_minutes(1);
//    d.set_month(1);
//    d.set_year(2002);
//    assert(d.get_day()==1);
//    assert(d.get_month()==1);
//    assert(d.get_year()==2002);
//    assert(d.get_minutes()==1);
//    assert(d.get_hour()==1);
//
//   controller.add_Event_to_repo("Excursie Adeona cabana ciubaru verde", "Munte 200lei","https://www.youtube.com/watch?v=p9j3TKhOn30",Duration(7,30,2007,6,30), 10);
//    controller.add_Event_to_repo("Qrowozon", "YT", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(6, 15,2022,12,24), 1);
//    controller.add_Event_to_repo("Animalia", "zoo", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(4,58,2022,7,5), 10);
//    controller.add_Event_to_repo("Amongus", "Danisus", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(4,54,2021,9,20), 9);assert(controller.add_Event_to_repo("title_", "description_", "link_", Duration(1,2, 2001, 4, 5), 6)==true);
//    controller.add_Event_to_repo("Pizza party", "parca fsega", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(15, 46,2020,3,12), 6);
//    controller.add_Event_to_repo("Allnighter", "OOP", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(4,35,2021,3,12), 10);
//    controller.add_Event_to_repo("Untold", "music", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(4,40,2022,3,12), 900);
//    controller.add_Event_to_repo("mcdonals", "coada", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(7,41,2023,3,12), 7);
//    controller.add_Event_to_repo("Smash", "Varga", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(1,26,2022,12,3), 3);
//    controller.add_Event_to_repo("Code end graduation party", "the code has ended forever","https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(8,6,2060,9,9), 9);
//    assert(controller.delete_Event_from_repo("Allnighter", "OOP", "https://www.youtube.com/watch?v=p9j3TKhOn30")==true);
//
//    Event to_test = Event("title1", "description1", "link1", 1, d);
//    to_test.set_description("description");
//    to_test.set_duration(d);
//    to_test.set_link("link");
//    to_test.set_title("title");
//    to_test.set_number_of_people(1);
//    assert(to_test.get_title()=="title");
//    assert(to_test.get_link()=="link");
//    assert(to_test.get_description()=="description");
//    assert(to_test.get_number_of_people()==1);
//    assert(to_test.get_duration().get_minutes()==d.get_minutes());
//
//    std::string Event= "Event: "+ to_test.get_title() + " description " +to_test.get_description() + ". On the time and date: "+std::to_string(d.get_hour())+":"+std::to_string(d.get_minutes())+" "+ std::to_string(d.get_day())+"/"+std::to_string(d.get_month())+"/"+std::to_string(d.get_year())+" with "+std::to_string(to_test.get_number_of_people())+" people.\n";
//    assert(to_test.Event_long_string()==Event);
//
//
//
//
//
//}
//
//
//
//void tests2() {
//    Repo repository = Repo();
//    Controller controller = Controller(repository);
//    Duration d;
//    d.set_day(1);
//    d.set_hour(1);
//    d.set_minutes(1);
//    d.set_month(1);
//    d.set_year(2002);
//
//
//    controller.add_Event_to_repo("Excu", "Munte 200lei","https://www.youtube.com/watch?v=p9j3TKhOn30",Duration(7,30,2007,6,30), 10);
//    controller.add_Event_to_repo("Qrowozon", "YT", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(6, 15,2022,12,24), 1);
//    controller.add_Event_to_repo("Animalia", "zoo", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(4,58,2022,7,5), 10);
//    controller.add_Event_to_repo("Amongus", "Danisus", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(4,54,2021,9,20), 9);assert(controller.add_Event_to_repo("title_", "description_", "link_", Duration(1,2, 2001, 4, 5), 6)==true);
//    controller.add_Event_to_repo("Pizza party", "parca fsega", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(15, 46,2020,3,12), 6);
//    controller.add_Event_to_repo("Allnighter", "OOP", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(4,35,2021,3,12), 10);
//    controller.add_Event_to_repo("Untold", "music", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(4,40,2022,3,12), 900);
//    controller.add_Event_to_repo("mcdonals", "coada", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(7,41,2023,3,12), 7);
//    controller.add_Event_to_repo("Smash", "Varga", "https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(1,26,2022,12,3), 3);
//    controller.add_Event_to_repo("Code end graduation party", "the code has ended forever","https://www.youtube.com/watch?v=p9j3TKhOn30", Duration(8,6,2060,9,9), 9);
//    assert(controller.delete_Event_from_repo("Allnighter", "OOP", "https://www.youtube.com/watch?v=p9j3TKhOn30")==true);
//
//    Event to_test = Event("title1", "description1", "link1", 1, d);
//
//    Event e1 = Event("Excu", "Munte 200lei","https://www.youtube.com/watch?v=p9j3TKhOn30",10,Duration(7,30,2007,6,30));
//    Event e2 = Event("Qrowozon", "YT", "https://www.youtube.com/watch?v=p9j3TKhOn30",1, Duration(6, 15,2022,6,24));
//    Event e3 = Event("Animalia", "zoo", "https://www.youtube.com/watch?v=p9j3TKhOn30",10, Duration(4,58,2022,6,5));
//
//
//    controller.sort_by_date();
//    int nr;
//
//    controller.add_Event_to_agenda(to_test);
////    Event* allE= controller.get_agenda_Events();
////    //std::cout<<allE[0].get_title();
////    assert(allE[0].get_title()=="title1");
////    assert(controller.get_number_of_Events_agenda()==1);
////    assert(controller.add_Event_to_agenda(to_test)==false);
////    assert(controller.get_Event_position_agenda(0).get_title()==to_test.get_title());
////
////    int nr_Events;
////    Event* m = controller.get_all_Events_by_month(1,nr_Events);
////    //std::cout<<m[0].get_title();
////    assert(nr_Events==0);
////    controller.add_Event_to_agenda(e1);
////    controller.add_Event_to_agenda(e2);
////    controller.add_Event_to_agenda(e3);
////    Event* n = controller.get_all_Events_by_month(6,nr_Events);
////    //std::cout<<m[0].get_title();
////    //std::cout<<nr_Events;
////    assert(nr_Events==1);
////
////
////    std::string Event= "Event: "+ to_test.get_title() + " description " +to_test.get_description() + ". On the time and date: "+std::to_string(d.get_hour())+":"+std::to_string(d.get_minutes())+" "+ std::to_string(d.get_day())+"/"+std::to_string(d.get_month())+"/"+std::to_string(d.get_year())+" at the following link: "+to_test.get_link()+"\n";
////    assert(to_test.Event_string()==Event);
////
////
////
////    assert(controller.delete_Event_from_agenda(to_test)==true);
////    assert(controller.get_number_of_Events_agenda()==3);
////    assert(controller.delete_Event_from_agenda(to_test)==false);
////    assert(controller.get_number_of_Events_agenda()==3);
//
//}