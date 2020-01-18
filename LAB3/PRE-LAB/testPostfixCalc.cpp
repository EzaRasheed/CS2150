//name: Eza Rasheed
//id: er6qt
//date: 2-3-19
//filename: testPostfixCalc.cpp

#include <iostream>
#include <string>
#include "postfixCalculator.h"
using namespace std;

int main() {
    
    Calculator c;
    //Test #1
    c.pushNum (2);
    c.pushNum (5);
    c.pushNum (5);
    c.addNum(); //testing addition
    c.pushNum (4);
    c.pushNum (6);
    c.subtNum(); //testing subtraction
    c.divNum(); //testing division
    c.pushNum (8);
    c.multNum(); //testing multiplication
    c.addNum();
    c.pushNum (3);
    c.unNegation(); //testing unary negation
    c.multNum();
    
    cout << "End result: " << c.topNum() << endl;
    
    //Test #2
    c.pushNum (6);
    c.pushNum (5);
    c.pushNum (2);
    c.pushNum (3);
    c.addNum(); //testing addition
    c.pushNum (8);
    c.multNum(); //testing multiplication
    c.addNum(); //testing addition
    c.pushNum (3); 
    c.addNum(); //testing addition
    c.multNum(); //testing multiplication
    
    cout << "End result: " << c.topNum() << endl;
    
    //Test #3
    c.pushNum (9);
    c.pushNum (4);
    c.pushNum(6);
    c.subtNum(); //testing subtraction
    c.addNum(); //testing addition
    c.pushNum (2); 
    c.multNum(); //testing multiplication
    c.pushNum(7);
    c.subtNum(); //testing subtraction
    
    cout << "End result: " << c.topNum() << endl;
    
    
    //COPIED TEST FILES FROM ONLINE PDR:
    
    //testing addition
    c.pushNum (1);
    c.pushNum (2);
    c.pushNum (3);
    c.pushNum (4);
    c.pushNum (5);
    c.addNum();
    c.addNum();
    c.addNum();
    c.addNum();
    cout << "End result: " << c.topNum() << endl;
    
    //testing subtraction
    c.pushNum (20);
    c.pushNum (10);
    c.subtNum();
    c.pushNum (-3);
    c.pushNum (10);
    c.subtNum();
    c.subtNum();
    c.pushNum (2);
    c.subtNum();;
    cout << "End result: " << c.topNum() << endl;
    
    //testing multiplication
    c.pushNum (-1);
    c.pushNum (-2);
    c.pushNum (-5);
    c.pushNum (3);
    c.multNum();
    c.pushNum (2);
    c.pushNum (-2);
    c.multNum();
    c.multNum();
    c.multNum();
    c.multNum();
    cout << "End result: " << c.topNum() << endl;
    
    //testing division
    c.pushNum (-1512);
    c.pushNum (-12);
    c.pushNum (-2);
    c.divNum();
    c.divNum();
    c.pushNum(-2);
    c.divNum();
    c.pushNum(3);
    c.divNum();
    cout << "End result: " << c.topNum() << endl;
    
    //testing unary negation
    c.pushNum(-1);
    c.unNegation();
    c.unNegation();
    c.unNegation();
    cout << "End result: " << c.topNum() << endl;
    
    return 0;
}

