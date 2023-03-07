#include "Duration.h"

Duration::Duration()
{
    this->minutes = 0;
    this->hour = 0;
    this->year = 0;
    this->month = 0;
    this->day = 0;
}

Duration::Duration(int hour, int minutes, int year, int month, int day)
{
    this->minutes = minutes;
    this->hour = hour;
    this->year = year;
    this->month = month;
    this->day = day;
}

Duration::Duration(const Duration& copy)
{
    this->minutes = copy.minutes;
    this->hour = copy.hour;
    this->year = copy.year;
    this->month = copy.month;
    this->day = copy.day;
}

int Duration::get_minutes() const
{
    return minutes;
}

int Duration::get_hour() const
{
    return hour;
}
int Duration::get_year() const
{
    return year;
}
int Duration::get_month() const
{
    return month;
}
int Duration::get_day() const
{
    return day;
}


void Duration::set_minutes(int minutes)
{
    this->minutes = minutes;
}

void Duration::set_hour(int hour)
{
    this->hour = hour;
}
void Duration::set_year(int year)
{
    this->year = year;
}
void Duration::set_month(int month)
{
    this->month = month;
}
void Duration::set_day(int day)
{
    this->day = day;
}