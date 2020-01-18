//Eza Rasheed
//er6qt

//C++
#include <iostream>
using namespace std;

int xton (int x, int n) {
  if (n == 0) //base case 1
    return 1;
  else if (n == 1) //base case 2
    return x;
  else
    return x * (xton(x, n-1)); //recursive case
}

int main(){
  int x, n,total;
    cout << "Enter a value for x: ";
    cin >> x;
    cout << "Enter a value for n: ";
    cin >> n;
    total = xton (x, n);
    cout << total << endl;
    return 0;
}
 
