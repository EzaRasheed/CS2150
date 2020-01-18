// Eza Rasheed
// er6qt
// 04-15-19
// huffmanenc.cpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include "heapNode.h"
//#include "heapNode.cpp"
#include "heap.h"
#include "heapTree.h"
//#include "heap.cpp"
using namespace std;


//taken from fileio.cpp
int main (int argc, char* argv[]) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    //string file = argv[1];
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if(fp == NULL) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
  }
  
  
    char g;
    int numChar = 0; //variable to count the number of characters in the input file
    int dist_symb = 0; //variable to count number of distinct symbols
    
    // initialize array for frequencies of ascii values
    int frequen[128]; //array that holds frequency values
    
    for (int i = 0; i < 128; i++) { // loop through each value in array
        frequen[i] = 0; //set to an empty array with all elements equaling 0
    }

    //read source file to determine the frequencies of the characters in the file to get the number of distinct symbols
    while ( (g = fgetc(fp)) != EOF ) {
        //numChar++;
        int ascii = (int) g; //cast char g to int
        if (ascii > 31 && ascii < 128) { //only need to account for the printable characters(0x20 to 0x7e)
            frequen[ascii]++; //add 1 to count of printable characters in array
            numChar++; //add 1 for number of letters in input file
        }
    }
    
    // add distinct nodes into heap
    heap h;
    for(int i = 32; i < 128; i++) {  // 32(space) - 126(~) for each elements in frequency array
        if(frequen[i] > 0){ //if elements in array HAS a frequency (> 0)
        heapNode* charac = new heapNode(frequen[i], (char) i); //create new node 
        h.insert(charac); // insert new node into heap
        dist_symb++; //add 1 to the number of distinct characters
        }
    }
    
  
    // build tree of prefix codes to determine the unique bit codes for each character
    // make/initialize new tree to call the createHuffTree() function on
    heapTree* huffTree = new heapTree();
    heap newTree = huffTree->createHuffTree(h);
    huffTree->printPrefixCode(newTree.findMin(), ""); // get character and corresponding prefix code (section 1)
    huffTree->setPrefixCode(newTree.findMin(), ""); // encode the string of characters from input file (section 2)
    
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    // rewinds the file pointer, so that it starts reading the file
    // again from the begnning
    rewind(fp); 
    
    // create vector to hold encoded output
    vector<heapNode*> com = h.vec(); // implementing vector data structure
    int char_bits_comp = 0;
    int char_bits_org = 0;
    char_bits_org = numChar*8;

    // read in file again
    // encode character string from input text file and for each character read, write its prefix code to the output
    // loop though each character using the nodes in the heap
    while ( (g = fgetc(fp)) != EOF ) {
        for(int i = 1; i < h.size()+1; i++) { 
            if (com[i]->getVal() == g){ // if each node's character in heap is equal to/matching found characters(g) in file
                cout << com[i]->getPreCode() << " "; //encode from character prefix(getPreCode)
                char_bits_comp += com[i]->getPreCode().size(); //add the size of all the prefix codes to get the number of bits in the compressed file
        }
        }
    }
    cout << endl;
        
    cout << "----------------------------------------" << endl;

    cout << "There are a total of " << numChar << " symbols that are encoded." << endl;
    cout << "There are a total of " << dist_symb << " distinct symbols used." << endl;
    cout << "There were " << char_bits_org << " bits in the original file." << endl;
    cout << "There were " << char_bits_comp << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << numChar * 8.0 / char_bits_comp << "." << endl;
    cout << "The cost of the Huffman tree is " << char_bits_comp * 1.0 / numChar  << " bits per character." << endl;
        
    fclose(fp); 
    return 0;
}
