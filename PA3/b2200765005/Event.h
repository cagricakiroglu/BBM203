#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <vector>

using namespace std;
#include <string>


class Event
{
    public:
    string eventtype;
    double TimeForEvent;
    double sort;
    double f_info;
    double s_info;
    double t_info;

    Event();
    Event(string type, double a , double b , double c, double d,double e);

};

#endif