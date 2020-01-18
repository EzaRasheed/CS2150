//name: Eza Rasheed
//id: er6qt
//date: 02-25-19
//filename: TreeNode.cpp

#include "TreeNode.h"

//Default Constructor -left and right are NULL, value '?'
TreeNode::TreeNode() {
    value="?";
    left=NULL;
    right=NULL;
}

//Constructor - sets value to val
TreeNode::TreeNode(const string & val) {
    value=val;
    left=NULL;
    right=NULL;
}
