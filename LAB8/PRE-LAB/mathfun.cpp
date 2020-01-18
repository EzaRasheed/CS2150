//name: Eza Rasheed
//id: er6qt
//date: 03-23-19
//filename: mathfun.cpp

#include <iostream>
using namespace std;

extern "C" int product(int x, int y); 
extern "C" int power(int x, int y); 

int main(){
  int x;
  int y;
  int prod_res;
  int pow_res;
  
  cout << "Enter the first integer: ";
  cin >> x;
  cout << "Enter the second integer: ";
  cin >> y;
  
  prod_res = product(x,y);
  pow_res = power(x,y);
  
  cout << "The product of " << x << " and " << y << " is: " << prod_res << endl;
  cout << x << " to the power of " << y << " is: " << pow_res << endl;
  
  return 0;
  
}

