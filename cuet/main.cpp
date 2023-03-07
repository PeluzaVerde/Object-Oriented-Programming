#include <QApplication>
#include <QPushButton>
#include "a7-8/UI.h"
#include "a7-8/tests.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    QPushButton b("", nullptr);
    b.resize(800, 900);
    b.show();


    EventValidator v = EventValidator();
    std::vector<Event> RepoVect;
    RepoVect.reserve(10);
    std::string filename = R"(C:/Users/HP/CLionProjects/cuet/a7-8/events.txt)";
    Repo repository = Repo{RepoVect, filename};
    repository.initRepo();
    UI ui = UI(v);

    //ui.start_application();


    return QApplication::exec();
}
