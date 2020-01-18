// Eza Rasheed
// er6qt
// 04-15-19
// heapTree.h

#ifndef heapTree_H
#define heapTree_H
#include "heap.h"
#include "heapNode.h"
#include <string>
using namespace std;

class heapTree {
public:
    heapTree();
    ~heapTree();
    heapNode *r;
    void printPrefixCode(heapNode* r, string pre);
    void setPrefixCode(heapNode* r, string pre);
    heap createHuffTree(heap min);

private:
};

#endif
