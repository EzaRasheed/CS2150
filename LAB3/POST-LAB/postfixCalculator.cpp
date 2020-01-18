//name: Eza Rasheed
//id: er6qt
//date: 2-3-19
//filename: postfixCalculator.cpp
//TA Helper: hpw3nr

#include <iostream>
#include "stack.h"
#include "postfixCalculator.h"

Calculator::Calculator(){
    stack calc; //concept taken from http://www.cplusplus.com/reference/stack/stack/stack/
}

Calculator::~Calculator(){
}
    
bool Calculator::emptyNum() const{ 
    return calc.empty();
}
    
void Calculator::pushNum(int value){
    calc.push(value);
}
    
void Calculator::popNum(){
    calc.pop();
}
    
int Calculator::topNum(){
    return calc.top();
}
    
void Calculator::subtNum(){
    int digit = calc.top();
    calc.pop();
    int digit2 = calc.top();
    calc.pop();
    int total = (digit2-digit);
    calc.push(total);
}
    
void Calculator::addNum(){
    int digit = calc.top();
    calc.pop();
    int digit2 = calc.top();
    calc.pop();
    int total = (digit+digit2);
    calc.push(total);
}
    
void Calculator::multNum(){
    int digit = calc.top();
    calc.pop();
    int digit2 = calc.top();
    calc.pop();
    int total = (digit*digit2);
    calc.push(total);
}
    
void Calculator::divNum(){
    int digit = calc.top();
    calc.pop();
    int digit2 = calc.top();
    calc.pop();
    int total = (digit2/digit);
    calc.push(total);
}

void Calculator::unNegation(){
    int digit = calc.top();
    calc.pop();
    int negate = (digit*-1);
    calc.push(negate);
}

