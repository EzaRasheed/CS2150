//name: Eza Rasheed
//id: er6qt
//date: 2-3-19
//filename: postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
using namespace std;


class Calculator { // Constructor
public:
    Calculator(); 
    ~Calculator();
    bool emptyNum() const; 
    void pushNum(int value);
    void popNum();
    int topNum();
    void subtNum();
    void addNum();
    void multNum();
    void divNum();
    void unNegation();
    
    
private:
    stack <int> calc;

};

#endif
