/*
 
 Q) Write a multiply function that multiples 2 integers without using *
 
 // requires only multiplication and division by 2, and can thus be implemented only using bit shifts.
 
 The idea is quite simple. Work with the binary representation of b, and add a multiplied by the required powers of two.
 This is quite similar to binary exponentiation.

 
*/


#include<iostream>
using namespace std;

long long mult(long long a, long long b) {
    
    long long ret = 0, fac = 1;
    
    // Deal with negative input
    if (b < 0) b = -b; fac = -fac;
    if (a < 0) a = -a; fac = -fac;
    
    while (b) {
        if (b & 1)
            ret += a;
        a <<= 1;
        b >>= 1;}
    return ret*fac;
}

int main() {
    cout << mult(10, 20) << endl;
}
