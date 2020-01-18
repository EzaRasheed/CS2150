//name: Eza Rasheed
//id: er6qt
//date: 02-25-19
//filename: TreeCalc.cpp

#include "TreeCalc.h"
#include "TreeNode.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
    stack<TreeNode*> mystack;
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    while (mystack.size() != 0) {
        cleanTree(mystack.top());
        mystack.pop();
    }
}
//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if (ptr->left != NULL) {
        cleanTree(ptr->left);
        //cleanTree(ptr->right);
    }
    if (ptr->right != NULL) {
        cleanTree(ptr->right);
        //cleanTree(ptr->right);
    }
    else {
        delete ptr;
    }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    TreeNode *curNode = new TreeNode(val);
    if (val == "+" || val == "-" || val == "*" || val == "/") {
        curNode->right = mystack.top();
        mystack.pop();
        curNode->left = mystack.top();
        mystack.pop();
    mystack.push(curNode);
    }
    else { //else, it's a digit
        mystack.push(curNode);
    }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
    cout << ptr->value;
    cout << " ";
    if (ptr->left != NULL) {
        printPrefix(ptr->left);
    }
    if (ptr->right != NULL) {
        printPrefix(ptr->right);
    }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
    if (ptr != NULL) {
        if (ptr->value == "+" || ptr->value == "-" || ptr->value == "*" || ptr->value == "/") {
            cout << "(";
        }
        printInfix(ptr->left);
        if (ptr->value == "+" || ptr->value == "-" || ptr->value == "*" || ptr->value == "/") {
            cout << " ";
            cout << ptr->value;
            cout << " ";
        }
        else {
            cout << ptr->value;
        }
        printInfix(ptr->right);
        if (ptr->value == "+" || ptr->value == "-" || ptr->value == "*" || ptr->value == "/") {
            cout << ")";
        }
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    if (ptr->left != NULL){
        printPostfix(ptr->left);
    }
    if (ptr->right !=NULL){
        printPostfix(ptr->right);
    }
    cout << ptr->value;
    cout << " ";
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
    if (ptr->value == "+") {
        return (calculate(ptr->left) + calculate(ptr->right));
    }
    else if (ptr->value == "-") {
        return (calculate(ptr->left) - calculate(ptr->right));
    }
    else if (ptr->value == "*") {
        return (calculate(ptr->left) * calculate(ptr->right));
    }
    else if (ptr->value == "/") {
        return (calculate(ptr->left) / calculate(ptr->right));
    }
    else {
         return atoi(ptr->value.c_str());
    }
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    while (mystack.size()!=0 && mystack.top()!=NULL) { //taken from printOutput^^
        i = calculate(mystack.top()); 
        mystack.pop();
    }
    return i;
}
