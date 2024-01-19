#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T>

struct Node
{
    T item;
    double priority=0;
    // node has a template thah holds everything as T
    // and it has a priority to make them sort as their priority
 
    Node *next= NULL;
};

#endif