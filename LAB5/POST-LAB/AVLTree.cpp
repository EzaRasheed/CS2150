//name: Eza Rasheed
//id: er6qt
//date: 02-28-19
//filename: AVLTree.cpp

#include "AVLTree.h"
#include <iostream>
#include <math.h>
#include <string>
#include "AVLNode.h"
using namespace std;

AVLTree::AVLTree() { root = NULL; }

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
  //num_of_nodes = 0;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
   insert(x, root); 
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { 
    root = remove(root, x); 
    //num_of_nodes--;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    if (find(x)) {
         return pathTo(x, root);
     }
     else {
         return " ";
    }
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    return find(x, root);
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    return numNodes(root);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    if ((height(n->right) - height(n->left)) == 2) {
        if ((height(n->right->right) - height(n->right->left)) < 0) {
            n->right = rotateRight(n->right);
        }
        n = rotateLeft(n);
    }
    else if ((height(n->right) - height(n->left)) == -2) {
        if ((height(n->left->right) - height(n->left->left)) > 0){
            n->left = rotateLeft(n->left);
        }
        n = rotateRight(n);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
     AVLNode* temp_node = n->right;
     AVLNode* temp_node2 = temp_node->left;
     temp_node->left = n;
     n->right = temp_node2;
     
    /*
    AVLNode* temp_node = n->right;
    AVLNode* temp_node2 = temp_node->left;
    AVLNode* temp_node3 = n->right->right;
    temp_node->left = n;
    //n->right = temp_node2;
    temp_node3->right = temp_node2;*/
    
    n->height = max(height(n->left), height(n->right)) + 1;
    temp_node->height = max(height(temp_node->left), height(temp_node->right)) + 1;
    return temp_node;
}


// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
     AVLNode* temp_node = n->left;
     AVLNode* temp_node2 = temp_node->right;
     temp_node->right = n;
     n->left = temp_node2;
    
    n->height = max(height(n->left), height(n->right)) + 1;
    temp_node->height = max(height(temp_node->left), height(temp_node->right)) + 1;
    return temp_node;

}

int AVLTree::numNodes(AVLNode* c) const{
    int count = 1;
    if (c == NULL) 
        return 0;
    else {
        count += numNodes(c->left);
        count += numNodes(c->right);
        return count;
    }
}

bool AVLTree::find(const string& x, AVLNode* n) const {
    if (n == NULL) 
        return false;
    else if (x < n->value)
        return find(x, n->left);
    else if (x > n->value)
        return find(x, n->right);
    else
        return true;
}

void AVLTree::insert(const string& x, AVLNode*& n) {
    if (n == NULL) {
        n = new AVLNode();
        n->value = x;
        //num_of_nodes++;
    }
    else if (x < n->value) {
        insert(x, n->left);
    }
    else if (x > n->value){
        insert(x, n->right);
    }
    n->height = max(height(n->left), height(n->right)) + 1;
    balance(n);
}

string AVLTree::pathTo(const string& x, AVLNode* path_cur) const {
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
    
// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
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
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isLeft) {
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

void AVLTree::printTree() { 
    printTree(root, NULL, false); 
}
