#ifndef Barista_Priority_Queue_H
#define Barista_Priority_Queue_H

// using Linked List
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Node.h"
 
template <typename T>
class Barista_Priority_Queue{

    public:
    int size ;

    Node<T> *first;
    
    Node<T> *last;
    

    Barista_Priority_Queue()
    {
        first = last = NULL;
      
        
    size=0;
        
        
    }
 
 
//popping process
//takes the minimum price
    T pop()
        {
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
// max price gets served first
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

    



    else if (first->priority < p)
    {
        temp->next=first;

        first=temp;

        
    }
    else
    {
        if(first==last){
            if(first->priority > p ){
            first->next=temp;
            last=temp;
            }
            else{
                 temp->next=first;

                first=temp;

            }
        }
        else if (p < last->priority){
            last->next=temp;
            last=temp; 
        }
        else{
           
            Node<T> *iterator = first;

        iterator=first;

        while(!(iterator->priority > p && iterator->next->priority < p)){

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
    cout<<"displaying: \n"<<endl;
    
  
   while (temp != NULL) {
   
        cout<<temp->priority<<" ";
    temp = temp->next;
   }
   cout<<"displaying over: \n"<<endl;
      cout<<""<<endl;
 
}

int Getsize(){
    return size;
}
 

};

#endif