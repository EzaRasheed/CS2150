//name: Eza Rasheed
//id: er6qt
//date: 2-10-19
//filename: prelab4.cpp

#include <iostream>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

void sizeOfTest() {
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}  
  
void outputBinary(unsigned int x) {
    cout << "Enter an integer value for x: ";
    cin >> x; 
    int count = 0;
    string binary_rep = "";
    for (int i = 31; i>=0; i--) {
        if (x >= pow(2, i)) {
            x = x - pow(2,i);
            binary_rep.append("1");
            count++;
        }
        else {
            binary_rep.append("0");
            count++;
        }
        
        if(count == 4) {
            binary_rep.append(" ");
            count = 0;
        }   
    }
    cout << binary_rep << endl;
}

void overflow() {
    unsigned int x = UINT_MAX;
    x = x + 1;
    cout << x << endl;
    cout << "You get 0 because it only checks 32bits.If you add 1, you get to 33bits, but because it only checks the first 32 spots, you get 0 as the output. The 0s are from carrying a 1 over each bit, as the max values are 1, and when you add 1+1 in binary, it is 0. Once it gets to the 33rd bit, it does 0+1 which is 1 in binary, but that gets chopped off and put into space, so it isn't outputted." << endl;
}

int main() {
    sizeOfTest();
    outputBinary(5);
    overflow();
}
