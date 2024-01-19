#include "Barista.h"
#include "Event.h"

Barista::Barista(int num){
    this->busy.push_back(true);
    for(int m =1 ; m <=num ; m++){
        this->busy.push_back(false);
        
    }

        this->n=num;
        this->Queue=0;
        this->Max_len=0;
        this->Busy=0;

    for(int i=0 ; i <= num ; i++){
        this->busytime.push_back(0.0);
    }



}

void Barista::appendQueue(Event comer){
    this->Queue++;


    if(this->Queue > this->Max_len){
        this->Max_len=this->Queue;
    }
    this->baristaQueue.push(comer.sort,comer);
    

}

bool Barista::isEmpty(){
    

      if(this->Queue==0){
        return true;
    }
    return false;
}

bool Barista::avail(){
    return this->Busy < this->n;
}

Event Barista::coffee(double time){
    Event event1=this->baristaQueue.pop();
    

    this->Queue--;
    Event event2;
    for(int i =1 ; i<= this->n ; i++) {
        if(!busy[i]){
            // if isnt busy

            this->busy[i]=true;
            //  make it busy busy
            this->busytime[i]+=event1.s_info;
            // add barista to busytime
            this->Busy++;
            double time_plus=time+event1.s_info;
            // increase the time


            event2=Event("CoffeeFinished", time_plus, event1.TimeForEvent, event1.f_info, i  ,i);
            break;
        }
    }
    return event2;

    
}


void Barista::finished(int n ){
    this->Busy--;
    this->busy[n]=false;
}