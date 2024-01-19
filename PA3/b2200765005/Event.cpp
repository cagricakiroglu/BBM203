#include "Event.h"
#include <iostream>


Event::Event(){
    this->eventtype="NONE";
  
}

Event::Event(string comer_type , double first , double second , double third, double forth , double fifth){
    this->eventtype=comer_type;
    this->sort=first;
    this->TimeForEvent=second;
    this->f_info=third;
    this->s_info=forth;
    this->t_info=fifth;
}




