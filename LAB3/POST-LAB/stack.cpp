//name: Eza Rasheed
//id: er6qt
//date: 2-6-19
//filename: stack.cpp
//TA Helper: kb3gz

#include <iostream>
#include <string>
#include "stack.h"
#include "List.h"

using namespace std;

stack::stack() {
    count = 0;
    the_stack = new List();
}


stack::~stack() {
    the_stack->makeEmpty();
    delete the_stack;
} 


void stack::push(int e) {
    the_stack->insertBefore(e, the_stack->first());
    count++;
}


int stack::top() {
    ListItr iter = the_stack->first(); // iterator that points to first node
    return iter.retrieve(); //access that value of that node (retrieve)
}

void stack::pop() {
    ListItr iter = the_stack->first();
    the_stack->remove(iter.retrieve()); //call remove
    count--;
} 

bool stack::empty() const {
    return the_stack->isEmpty(); //isEmpty
}
