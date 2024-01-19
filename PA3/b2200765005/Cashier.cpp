#include "Barista.h"
#include "Event.h"
#include "Cashier.h"

Cashier::Cashier(int num){
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

void Cashier::appendQueue(Event comer){
    
    this->Queue++;
    if(this->Queue > this->Max_len){
        this->Max_len=this->Queue;
    }
  

   
    this->CashierQueue.push(comer.sort,comer);

    

    
    
}

bool Cashier::isEmpty(){
        if(this->Queue==0){
        return true;
    }
    return false;
}

bool Cashier::avail(){
    return this->Busy < this->n;
}

Event Cashier::Order(double time){
  
    Event event1=this->CashierQueue.pop();
 

    
    this->Queue--;
    Event event2;
    for(int i =1 ; i<= this->n ; i++) 
        if(!busy[i]){
            // if isnt busy
            this->busy[i]=true;
             //  make it busy busy
            this->busytime[i]+=event1.f_info;
            // add cashiertime to busytime
            this->Busy++;
                // increase the time in ( time+ event1.f_info) 
            event2=Event("Finished",  time+event1.f_info  ,event1.TimeForEvent ,   i    ,event1.s_info,event1.t_info);
            break;
        }

    return event2;
}


void Cashier::finished(int n ){
    this->Busy--;
    this->busy[n]=false;
}


