#pragma once

class Duration {
private:
    int minutes;
    int hour;
    int year;
    int month;
    int day;

public:
    Duration();
    Duration(int minutes, int hour, int year, int month, int day);
    Duration(const Duration& copy);
    int get_minutes() const;
    int get_hour() const;
    int get_year() const;
    int get_month() const;
    int get_day() const;
    void set_minutes(int minutes);
    void set_hour(int hour);
    void set_year(int year);
    void set_month(int month);
    void set_day(int day);
};