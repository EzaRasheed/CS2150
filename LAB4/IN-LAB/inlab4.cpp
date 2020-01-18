//name: Eza Rasheed
//id: ere6qt
//date: 02-12-19
//filename: inlab4.cpp

#include <iostream>
#include <climits>
#include <float.h> //TA advice for getting max of double and float


using namespace std;


int main() {

    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of char*: " << sizeof(char*) << endl;
    cout << "Size of double*: " << sizeof(double*) << endl;
    
    cout << "Max value of int: " << INT_MAX << endl;
    cout << "Max value of unsigned int: " << UINT_MAX << endl;
    cout << "Max value of float: " << FLT_MAX << endl;
    cout << "Max value of double: " << DBL_MAX << endl;
    cout << "Max value of char: " << CHAR_MAX << endl;
    cout << "Max value of bool: " << "1" << endl;
   
    int e = 0;
    cout << "Zero stored in int as: " << e << endl;
    e = 1;
    cout << "One stored in int as: " << e << endl;
    
    unsigned int z = 0;
    cout << "Zero stored in unsighned int as: " << z << endl;
    z = 1;
    cout << "One stored in unsigned int as: " << z << endl;
    
    float a = 0.0;
    cout << "Zero stored in float as: " << a << endl;
    a = 1.0;
    cout << "One stored in float as: " << a << endl;
    
    double r = 0.0;
    cout << "Zero stored in double as: " << r << endl;
    r = 1.0;
    cout << "One stored in double as: " << r << endl;
    
    char s = '0';
    cout << "Zero stored in char as: " << s << endl;
    s = '1';
    cout << "One stored in char as: " << s << endl;
    
    bool h = false;
    cout << "Zero stored in bool as: " << h << endl;
    h = true;
    cout << "One stored in bool as: " << h << endl;
    
    int* d = NULL;
    cout << "NULL stored in int* as: " << d << endl;
    
    char* b = NULL;
    cout << "NULL stored in char* as: " << b << endl;
    
    double* c = NULL;
    cout << "NULL stored in double* as: " << c << endl;


//End of section 1 of inlab4-----------------------------------------------------------------
    

    int IntArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char CharArray[10] = {'e', 'z', 'a', 'r', 's', 'h', 'd', 'b', 'c', 'f'};

    int IntArray2D[6][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}, {26,27,28,29,30} };
    
    char CharArray2D[6][5] = { {'a','b','c','d','e'}, {'f','g','h','i','j'}, {'k','l','m','n','o'}, {'p','q','r','s','t'}, {'u','v','w','x','y'}, {'z','a','b','c','d'} };

    return 0;

}
