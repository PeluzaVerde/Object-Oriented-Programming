//
// Created by HP on 5/26/2022.
//

#include "UndoClass.h"
#include <utility>


//template<typename... Args>
//doUndo::doUndo(service& srv, Args&&... args) :srv(srv){
//    arg = std::make_tuple( std::move(args)...);
//}

void UndoAdd::undo() {
    auto element = repo.findByTitle(ap);

    repo.delete_Event(repo.get_event(element));
}

UndoAdd::UndoAdd(Repo& repo, std::string ap): repo(repo), ap(ap) {
}


UndoDel::UndoDel(Repo& repo, Event t)
        : repo(repo), t(t) {}

void UndoDel::undo() {
    repo.add_Event(t);
}

UndoMod::UndoMod(Repo& repo, std::string old_ap, Event t)
        : repo(repo), old_ap(old_ap), t(t) {}

void UndoMod::undo() {
    auto element = repo.findByTitle(old_ap);
    repo.update_Event(repo.get_event(element),t);


//    repo.delete_Event(repo.get_event(element));

//    repo.add_Event(t);
}

