//name: Eza Rasheed
//id: er6qt
//date: 2-6-19
//filename: stack.h


#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"


using namespace std;

class stack {
public:
    stack();
    ~stack();
    void push(int e);
    int top();
    void pop();
    bool empty() const;
    
    
private: 
    List* the_stack;
    int count;
    friend class List;
};
    
    
#endif 


