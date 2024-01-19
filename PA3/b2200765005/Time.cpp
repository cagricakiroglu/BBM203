#include "Time.h"
#include <iostream>

Time::Time(){
    this->numberOFelements=0;
    this->maxNumberOfElements=0;

}

void Time::AppendEvent(Event comer){
 

  
   TimeQueue.push(comer.sort,comer);
    this->numberOFelements++;
    // i sort the timequeue by their time
    // low time gets served first
    //sorting by their comer.sort info 


    



    if(this->numberOFelements > this->maxNumberOfElements ){

        //checking the max nunber of queue
        // every step it auto check 
        this->maxNumberOfElements= this->numberOFelements;
    }
}

Event Time::getNext(){

    if(this->numberOFelements==0)
    {
        //if its empty return null event 
        return Event();
    }

    //if its not empty return the first of the queue
    this->numberOFelements--;

    Event event3= this->TimeQueue.pop();
     
       
    return event3;
}

bool Time::isEmpty(){
    if(this->numberOFelements==0){
        //if numberof elements is 0 so that its empty so return true
        return true;
    }
      //if numberof elements is not 0 so that its not empty so return false
    return false;
}