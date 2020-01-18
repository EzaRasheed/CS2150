// Eza Rasheed
// er6qt
// 04-17-19
// huffmandec.cpp


// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "heapNode.h"
using namespace std;

void decodeTree(heapNode *r, string pre) {
    heapNode* curr = r; 
    // iterate through the encoded prefix code string
    for (int i = 0; i < pre.length(); i++) {
        if (pre[i] == '0' && curr->left != NULL) { // if bit is 0 and left child is not empty
            curr = curr->left; // move to left child node
        }
        if (pre[i] == '1' && curr->right != NULL) { // if bit is 1 and right child is not empty
            curr = curr->right; // move to right child node
        }   
        // reached leave node (leaf nodes are the characters)
        if (curr->left == NULL && curr->right == NULL) { // if left and right child nodes are empty(there's nothing there), you've hit a leaf node
            cout << curr->getVal(); // print out character stored at leaf node
            curr = r; // reset node
            //cout << (int)curr->getVal();
        }
    }
}
    
void makeTree(heapNode* r, string pre, char c) {
    //start at root node for each character
    
    //base case (leaf node)
    if (pre.length() == 0) { // if prefix code string has a length of 0
        r->val = c; // get character(val) at leaf node and set it to the character we will output 
    }
    if (pre[0] == '0' && r->left == NULL) { // if bit is 0 and there is no child there
            heapNode* left_child = new heapNode(); // go left and create new node (Note: '\0' is a place holder that will now show up in any text files)
            r->left = left_child; // set node's left to new left child created
    }
    if (pre[0] == '0') { //recursively call function 
        makeTree(r->left, pre.substr(1), c); 
    }
    if (pre[0] == '1' && r->right == NULL) { // if bit is 1 and there is no child there
            heapNode* right_child = new heapNode(); // // go right and create new node
            r->right = right_child; // set node's right to new right child
    }
    if (pre[0] == '1') {  // recursively call function 
        makeTree(r->right, pre.substr(1), c);
    }
}

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    heapNode *node = new heapNode();
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix_code;
        // read in the first token on the line
        file >> character;
        // check for space
        if ( character == "space" )
            character = " ";
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // read in the prefix code
        file >> prefix_code;
        // do something with the prefix
        makeTree(node, prefix_code, character[0]);
    }
    
    
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    decodeTree(node, allbits);
    cout << endl;
    // close the file before exiting
    file.close();
}
