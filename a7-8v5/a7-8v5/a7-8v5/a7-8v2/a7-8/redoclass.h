#ifndef REDOCLASS_H
#define REDOCLASS_H


//#pragma once
#include <tuple>
#include <string>
#include "Repo.h"
#include "Event.h"

class doRedo {
//    std::tuple<> arg;
//    service srv;

public:
//    template <typename... Args>
//    explicit doUndo(service& srv, Args&&... args);

    virtual void redo() = 0;
    virtual ~doRedo() = default;

};

class RedoAdd: public doRedo {
private:
    Repo& repo;
    std::string ap;

public:
    void redo() override;


    RedoAdd(Repo& repo, std::string ap);
};

class RedoDel: public doRedo {
private:
    Repo& repo;
    Event t;

public:
    RedoDel(Repo&, Event);
    void redo() override;
};


class RedoMod: public doRedo {
private:
    Repo& repo;
    std::string old_ap;
    Event t;
public:
    RedoMod(Repo&, std::string, Event);
    void redo() override;
};

#endif // REDOCLASS_H
