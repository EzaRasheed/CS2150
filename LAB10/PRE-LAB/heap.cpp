// Eza Rasheed
// er6qt
// 04-12-19
// heap.cpp

// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "heapNode.h" 
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heep.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<heapNode*> vec) : heap_size(vec.size()) {
    heep = vec;
    heep.push_back(heep[0]);
    heep[0] = 0;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(heapNode *h) {
    // a vector push_back will resize as necessary
    heep.push_back(h);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    heapNode* x = heep[hole]; 
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x -> frequency < heep[hole/2] -> frequency); hole /= 2 ) //get frequencies of values for prefix code
        heep[hole] = heep[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    heep[hole] = x;
}

heapNode* heap::deleteMin() { 
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    heapNode* ret = heep[1]; 
    // move the last inserted position into the root
    heep[1] = heep[heap_size--];
    // make sure the vector knows that there is one less element
    heep.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) { 
    // get the value to percolate down
    heapNode *he = heep[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (heep[child+1] -> frequency < heep[child] -> frequency) ) //check right child value frequency with left child value frequency
            child++;
        // if the child is greater than the node...
        if ( he -> frequency > heep[child] -> frequency) { 
            heep[hole] = heep[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heep[hole] = he;
}

heapNode* heap::findMin() { 
  if ( heap_size == 0 )
    throw "findMin() called on empty heap";
  return heep[1]; 
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
}

bool heap::isEmpty() {
    return heap_size == 0;
}

vector<heapNode*> heap::vec(){
    return heep;
}

//don't need
void heap::print() {
  cout << "(" << heep[0] << ") "; 
  for( int i = 1; i <= heap_size; i++ ) {
    cout << heep[i] << " ";
    // next line from from http://tinyurl.com/mf9tbgm
    bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
    if ( isPow2 )
        cout << endl << "\t";
  }
  cout << endl;
}
