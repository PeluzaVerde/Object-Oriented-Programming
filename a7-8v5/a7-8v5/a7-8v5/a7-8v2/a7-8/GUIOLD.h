//
// Created by HP on 5/7/2022.
//

#ifndef A5_6_GUIOLD_H
#define A5_6_GUIOLD_H
#pragma once
#include <qwidget.h>
#include "Event.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class GUIOLD: public QWidget{

    Q_OBJECT

public:
    GUIOLD(std::vector<Event> events, QWidget* parent =0);
    ~GUIOLD();

private:

    std::vector<Event> genes;
    QListWidget* genesList;

    std::string filename;

    void connectSignalsAndSlots();

    void open();
    void save();
    void initGUI();
    int getSelectedIndex();
    //void connectSignalsAndSlots();

    void populateGenesList();
    // When an item in the list is clicked, the text boxes get filled with the item's information
    void listItemChanged();

    void addGeneButtonHandler();
    void deleteGeneButtonHandler();

signals:
    void genesUpdatedSignal();
    void addGeneSignal(const std::string& geneName, const std::string& organismName, const std::string& sequence);

public slots:
    void addGene(const std::string& geneName, const std::string& organismName, const std::string& sequence);


};


#endif //A5_6_GUIOLD_H
