// Eza Rasheed
// er6qt
// 04-12-19
//heapNode.cpp

#include <iostream>
#include "heap.h"
#include "heapNode.h"
#include <string>
using namespace std;

heapNode::heapNode(){
    left = NULL;
    right = NULL;
    frequency = 0;
    val = ' ';
    prefix_code = "";
}

heapNode::~heapNode() {
    delete left;
    delete right;
}   
    
heapNode::heapNode(int f, char c) {
    left = NULL;
    right = NULL;
    frequency = f;
    val = c;
    prefix_code = "";
}

int heapNode::getFre() const {
    return frequency;
}

char heapNode::getVal() {
    return val;
}

string heapNode::getPreCode() {
    return prefix_code;
}

void heapNode::setFre(int f) {
    frequency = f;
}

void heapNode::setVal(char c) {
    val = c;
}

void heapNode::left_rightNode(heapNode* l, heapNode* r) { 
    left = l; 
    right = r;
}

//operator<() method
bool heapNode::operator<(const heapNode& hn) const {
    return(this->getFre() < hn.getFre());
}
