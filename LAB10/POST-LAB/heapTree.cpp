//Eza Rasheed
//er6qt
//04-15-19
//heapTree.cpp

#include "heapTree.h"
#include "heap.h"
#include "heapNode.h"
#include <iostream>
#include <string>

heapTree::heapTree(){
    r = NULL;
}

heapTree::~heapTree(){
    delete r;
}

void heapTree::printPrefixCode(heapNode *r, string pre) { 
    if(r->left == NULL && r->right == NULL) {
        //print each character with its prefix code
        if (r->val == ' '){
            cout << "space" << " " << pre << endl;
        }
            else {
            cout << r->val << " " << pre << endl;
    }
}
    //if bit read is 0, go left, if bit read is 1, go right until node is a leaf
    if(r -> left) {
       printPrefixCode(r -> left, pre + "0");
    }
    if(r -> right) {
       printPrefixCode(r -> right, pre + "1");
    }
}

void heapTree::setPrefixCode(heapNode *r, string pre) { 
    if(r->left == NULL && r->right == NULL) {
        r->prefix_code = pre; //set prefix code of the r node to the new string that holds each character node's prefix code
    }
    if(r -> left) {
        setPrefixCode(r -> left, pre + "0");
    }
    if(r -> right) {
        setPrefixCode(r -> right, pre + "1");
    }
}

heap heapTree::createHuffTree(heap min) {
    while(min.size() > 1) { 
        heapNode *h1 = min.deleteMin();
        heapNode *h2 = min.deleteMin();
        int total_freq=0;
        total_freq += (h1 -> getFre());
        total_freq += (h2 -> getFre());
        heapNode* total = new heapNode(total_freq, 'e');
        total->left = h1; //change left pointer to make child of new node
        total->right = h2; //change right pointer to make child of new node
        min.insert(total);
    }
    return min;
}

