//name: Eza Rasheed
//id: er6qt
//date: 02-28-19
//filename: AVLNode.cpp

#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
  value = "?";
  left = NULL;
  right = NULL;
  height = 0;
}

AVLNode::~AVLNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
