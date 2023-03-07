#include "redoclass.h"
#include "undoclass.h"
#include <utility>


void RedoAdd::redo() {
    auto element = repo.findByTitle(ap);

    repo.delete_Event(repo.get_event(element));
}

RedoAdd::RedoAdd(Repo& repo, std::string ap): repo(repo), ap(ap) {
}


RedoDel::RedoDel(Repo& repo, Event t)
        : repo(repo), t(t) {}

void RedoDel::redo() {
    repo.add_Event(t);
}

RedoMod::RedoMod(Repo& repo, std::string old_ap, Event t)
        : repo(repo), old_ap(old_ap), t(t) {}

void RedoMod::redo() {
    auto element = repo.findByTitle(old_ap);
    repo.update_Event(repo.get_event(element),t);


}
