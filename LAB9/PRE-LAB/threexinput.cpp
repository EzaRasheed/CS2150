// Eza Rasheed
// er6qt
// 04-09-19
// threexinput.cpp


#include <iostream>
#include <string>
#include "timer.h"
#include <cstdlib>

using namespace std; 

extern "C" int threexplusone(int); 

int main(){
    int x;
    int n;
    timer t;
    
    cout << "Please enter a number: ";
    cin >> x;
    cout << "Please enter how many times you want to run: ";
    cin >> n;
    
    t.start();
    for (int i = 0; i < n; i++) {
        threexplusone(x);
    }
    t.stop();
    
    
    cout << "Steps taken: " << threexplusone(x) << endl;
    
    double averageTime = ((t.getTime()*1000.0)/(n*1.0));
    cout << "Average time taken: " << averageTime << endl;
    
    return 0;

}
