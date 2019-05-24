// find the first X prime numbers

#include <iostream>
#include <cmath>
using namespace std;


int main () {
    int x;
    cout << "Find first X prime numbers of: ";
    cin >> x;
    cout << endl;
    
    if (x >= 5) { cout << "Enter a valid number more than 5" << endl;}
    
    for (int i = 2; i < x; i++)
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) break;
            else if (j + 1 > sqrt(i)) { cout << i << " ";}}
    cout << endl;
}
