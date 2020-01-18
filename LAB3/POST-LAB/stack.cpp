//name: Eza Rasheed
//id: er6qt
//date: 2-6-19
//filename: stack.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "stackNode.h"
#include "stack.h"

using namespace std;

stack::stack() {
    head = new stackNode;
    count = 0;
}
    
stack::~stack() {
    delete head;
} 

void stack::push(int e) {
    //stackNode* tempNode = new stackNode();
    stackNode* tempNode = head;
    head = new stackNode();
    head->value = e;
    head->next = tempNode;
    ///head->next = head;
    ///head = tempNode;
    count++;
}


int stack::top() {
    if (empty()){
        cout << "Error: Empty stack!" << endl;
        exit(-1);
    }
    return head->value;
}

void stack::pop() {
    if (empty()){
        cout << "Error: Empty stack!" << endl;
        exit(-1);
    }
    delete head;
    head = head->next;
    count --;
} 

bool stack::empty() const {
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}
