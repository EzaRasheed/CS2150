// Eza Rasheed
// er6qt
// 04-12-19
// heapNode.h

#ifndef heapNode_H
#define heapNode_H
#include <string>
using namespace std;

class heapNode {
public:
    char val;
    int frequency;
    string prefix_code;
    heapNode *left, *right;
    heapNode();
    ~heapNode(); 
    heapNode(int f, char c); 
    int getFre() const; 
    char getVal();
    string getPreCode();
    void setFre(int f);
    void setVal(char c);
    void left_rightNode(heapNode* l, heapNode* r);
    bool operator<(const heapNode& hn) const;

private:
    //friend class heap;
};

#endif
