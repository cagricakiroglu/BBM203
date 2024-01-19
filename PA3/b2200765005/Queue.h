#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
#include "Node.h"

template <typename T>
class Queue 
{
public:
    Node<T> *first;
    
    Node<T> *last;
    
    int size;

    Queue()
    {
        first = last = NULL;
        size = 0;
    }

    void setSize(int siz)
    {
        size = siz;
    }

    int Size()
    {
        return size;
    }

    bool IsEmpty()
    {
        
        if (first == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(T &item)
    {
        Node<T> *temp = new Node<T>;
        temp->item = item;
        temp->next = NULL;

        if (first == NULL)
        {
            first = temp;
            last = temp;
        }

        else
        {
            last->next = temp;
            last = temp;
        }
        size++;
    }
    T pop()
    {
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
};

#endif