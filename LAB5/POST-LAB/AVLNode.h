//name: Eza Rasheed
//id: er6qt
//date: 02-28-19
//filename: AVLNode.h

#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
  AVLNode();
  ~AVLNode();

  string value;
  AVLNode* left;
  AVLNode* right;
  int height;

  friend class AVLTree;
};

#endif
