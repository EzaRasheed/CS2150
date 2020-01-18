//name: Eza Rasheed
//id: er6qt
//date: 02-26-19
//filename: BinarySearchTree.cpp

#include "BinarySearchTree.h"
#include <string>
#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() { 
    root = NULL; 
    num_of_nodes = 0;
} 

BinarySearchTree::~BinarySearchTree() { 
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    insert (x, root); 
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { 
    root = remove(root, x);
    num_of_nodes--;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    if (find(x)) {
         return pathTo(x, root);
     }
     else {
         return " ";
    }
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    return find(x, root);
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
    return num_of_nodes;
}

string BinarySearchTree::pathTo(const string& x, BinaryNode* path_cur) const {
    if (path_cur == NULL) {
        return " ";
    }
    else if (path_cur->left == NULL && path_cur->right == NULL){
        return path_cur->value;
    }
    else if (x < path_cur->value) {
        return path_cur->value + " " + pathTo(x, path_cur->left);
    }
    else if (x > path_cur->value) {
        return path_cur->value + " " + pathTo(x, path_cur->right);
        pathTo(x, path_cur->right);
    }
    
}

void BinarySearchTree::insert(const string& x, BinaryNode*& curNode) {
    if (find(x) == true) {
    }
    if (curNode == NULL) {
        curNode = new BinaryNode();
        curNode->value = x;
        num_of_nodes++;
    }
    else if (x < curNode->value) {
        insert(x, curNode->left);
    }
    else if (x > curNode->value){
        insert(x, curNode->right);
    }
}

bool BinarySearchTree::find(const string& x, BinaryNode* no) const {
    if (no == NULL) 
        return false;
    else if (x < no->value)
        return find(x, no->left);
    else if (x > no->value)
        return find(x, no->right);
    else
        return true;
}
// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}

void BinarySearchTree::printTree() { printTree(root, NULL, false); }
