#ifndef TIME_H
#define TIME_H

#include "Event.h"
#include "PriorityQueue.h"
#include <iostream>

class Time{

    public:
    PriorityQueue<Event>TimeQueue;
    int numberOFelements;
    int maxNumberOfElements;
    Time();
    void AppendEvent(Event addThis);
    Event getNext();
    bool isEmpty();


};

#endif