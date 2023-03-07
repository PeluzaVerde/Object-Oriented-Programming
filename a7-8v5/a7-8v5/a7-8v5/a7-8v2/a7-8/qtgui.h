//
// Created by Owner on 5/15/2022.
//

#ifndef A5_6_QTGUI_H
#define A5_6_QTGUI_H

#include <QWidget>
#include "Controller.h"
//#include "Controller.h"
#include "validator.h"
#include "Agenda_html.h"
#include "Agenda_csv.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QShortcut>
#include "ListViewWidget.h"
#include "EventModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class qtgui; }
QT_END_NAMESPACE

class qtgui : public QWidget {
Q_OBJECT

public:
    explicit qtgui(Controller& serv, EventValidator valid,QWidget *parent = nullptr);

    ~qtgui() override;

private:
    Ui::qtgui *ui;
    Controller& serv;
    EventValidator v;

    void connectSIgnalsAndSlots();
    int getSelectedIndex() const;
    int getSelectedIndexUser() const;
    void populateList();
    void populateAgendaList();
    void deleteEvent();
    void modifyEvent();
    void chooseCsv();
    void chooseHTML();
    void filterEvent();
    void addWatchlist();
    void playEvent();
    void deleteUserEvent();
    void showAgenda();
    void bonusA12();
    void euroshow();
    //void undo_action();
    //void redo_action();
    std::vector<std::string> field_delimiter(const std::string& str, char delimiter);
    void keyPressEvent (QKeyEvent * event);
    void showbutton();


public slots:
    void addEvent();
    void undo_action();
    void redo_action();
};


#endif //A5_6_QTGUI_H
