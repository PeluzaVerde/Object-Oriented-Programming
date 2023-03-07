//
// Created by HP on 5/26/2022.
//

#ifndef A5_6_UNDOCLASS_H
#define A5_6_UNDOCLASS_H


#pragma once
#include <tuple>
#include <string>
#include "Repo.h"
#include "Event.h"

class doUndo {
//    std::tuple<> arg;
//    service srv;

public:
//    template <typename... Args>
//    explicit doUndo(service& srv, Args&&... args);

    virtual void undo() = 0;
    virtual ~doUndo() = default;

};

class UndoAdd: public doUndo {
private:
    Repo& repo;
    std::string ap;

public:
    void undo() override;


    UndoAdd(Repo& repo, std::string ap);
};

class UndoDel: public doUndo {
private:
    Repo& repo;
    Event t;

public:
    UndoDel(Repo&, Event);
    void undo() override;
};


class UndoMod: public doUndo {
private:
    Repo& repo;
    std::string old_ap;
    Event t;
public:
    UndoMod(Repo&, std::string, Event);
    void undo() override;
};




#endif //A5_6_UNDOCLASS_H
