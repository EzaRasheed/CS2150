// Eza Rasheed
// er6qt
// 04-12-19
// heap.h

// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include "heapNode.h"
#include <vector>
using namespace std;

class heap {
public:
    heap();
    heap(vector<heapNode*> vec);
    ~heap();
    void insert(heapNode *x); 
    heapNode* findMin();
    heapNode* deleteMin(); 
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    vector<heapNode*> vec();
    void print();

private:
    vector<heapNode*> heep;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};
#endif
