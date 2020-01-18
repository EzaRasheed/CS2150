//name: Eza Rasheed
//id: er6qt
//date: 2-7-19
//filename: stackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using namespace std;

class stackNode {
public:
    stackNode();
    // Constructor

private:
    int value;
    stackNode *next, *previous;
    friend class stack;
    

};

#endif
