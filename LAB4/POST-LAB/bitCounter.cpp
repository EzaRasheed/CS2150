//name: Eza Rasheed
//id: er6qt
//date: 02-14-19
//filename: bitCounter.cpp

#include <iostream>
#include <string> 
#include <math.h> //for floor
#include <cstdlib> //for exit(-1)

using namespace std;


int bin_bit_counter(int b){
    if (b == 1) { //base case
        return 1;
    }
    else if (b%2 == 0) { //check if b is even number
        b = b/2;
        return bin_bit_counter(b); //recursion
    }
    else if (b%2 != 0) { //check if b is odd number
        b = floor(b/2);
        return bin_bit_counter(b)+1; //recursion
    }
}

int main (int argc, char* argv[]) {
    if(argc  == 1) { //only doing executable
        cout << "Error: No command-line parameters found" << endl;
        exit(-1);
    }
    int b = atoi(argv[1]);
    cout << "Number of 1's in the binary representation of b: " << bin_bit_counter(b) << endl;
}
