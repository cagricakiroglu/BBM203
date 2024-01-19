#ifndef CASHIER_H
#define CASHIER_H

#include <iostream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"


#include <vector>
using namespace std;

class Cashier{
   public:
    int n;
    vector < bool> busy;
    /*
    cashier class has a busy vector thath holds busies
    and has a priorityQueue that holds as first come first served
    
    
    */
    bool isEmpty();
    void finished(int num);
    int Busy;
    int Queue;
    int Max_len;
    vector <double> busytime;
    Cashier(int num);
    bool avail();
    Event Order(double time);
    void appendQueue(Event comer);
    PriorityQueue<Event>CashierQueue;
   

};

#endif