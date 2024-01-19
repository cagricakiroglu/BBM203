#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H



#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Node.h"
 
template <typename T>
class PriorityQueue{

    public:
    int size ;

    Node<T> *first;
    
    Node<T> *last;
    

    PriorityQueue()
    {
        //constructer
        first = last = NULL;
    size=0;
        
        
    }
 
 

    T pop()
        {
            //popping process
            //takes the minimum time
            size--;
    
           if (first == NULL)
        {
      
            T item;
            return item;
        }
       
        Node<T> *temp = first;

         

        
        T data = temp->item;
       
        if (first == last)
        {
          
            first = last = NULL;
        }
        else
        {
          
            first = first->next;
            delete temp;
        }
        
        return data;
}
 
// A method that push the T , as has a minimum priority inserted in front of the queue
// min time gets served first

void push(double p,T &item )
{
    size++;
    Node<T> *temp = new Node<T>;
    temp->item = item;
    temp->priority=p;
    
    temp->next = NULL;    
 
    if(first==NULL){
      
        first = temp;
            last = temp;
            first->priority=temp->priority;
       

            
 
    }

 
    else if (first->priority > p)
    {
    
        temp->next = first;
        
        first = temp;
        first->priority=temp->priority;
        
    }
    else
    {
        if(first==last){
            first->next=temp;
            last=temp;
        }

        else if (p> last->priority){
            last->next=temp;
            last=temp; 
        }
        else{
           
            Node<T> *iterator = first;

        iterator=first;

        while(!(iterator->priority < p && iterator->next->priority>p)){

         iterator=iterator->next;

        }
         temp->next=iterator->next;

        iterator->next=temp;
        
        
        }
    }
}


void display(){
     Node<T> *temp = new Node<T>;
    temp=first;

    
  
   while (temp != NULL) {
   
        cout<<temp->priority<<" ";
    temp = temp->next;
   }
      cout<<""<<endl;
 
}

int Getsize(){
    return size;
}
 

};

#endif