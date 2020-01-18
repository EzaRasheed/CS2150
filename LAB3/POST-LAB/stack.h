//name: Eza Rasheed
//id: er6qt
//date: 2-6-19
//filename: stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackNode.h"


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
    stackNode *head;
    int count;
    friend class stackNode;
};
    
    
#endif 
