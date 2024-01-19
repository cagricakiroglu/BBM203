#ifndef BARISTA_H
#define BARISTA_H
#include "Queue.h"
#include "PriorityQueue.h"
#include "Barista_Priority_Queue.h"
#include "Event.h"

#include <iostream>
#include <vector>
using namespace std;



class Barista{

    /*
    barista has a busy vector that holds busy baristas
    and it has a 
    Barista_Priority_Queue    queue that holds min price at last and expensive one as first
    it works reverse with PriorityQueue
    
    
    */


    public:
    int n;
    vector < bool> busy;
    bool isEmpty();
    void finished(int num);
    int Busy;
    int Queue;
    int Max_len;
    vector <double> busytime;
    Barista(int num);
    bool avail();
    Event coffee(double time);
    void appendQueue(Event comer);
    Barista_Priority_Queue<Event>baristaQueue;
   


    



};

#endif