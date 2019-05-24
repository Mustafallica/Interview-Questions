/*
 
 Q) Write a function that prints out the binary form of an int

 step 1) if NUM > 1
    a) push NUM on stack
    b) recursively call function with 'NUM / 2'
 
 step 2)
    a) pop NUM from stack, divide it by 2 and print it's remainder.
 
*/

#include  <iostream>
using namespace std;

void bin(int n) {
    if (n > 1) // step 1
        bin(n/2);
    cout << (n % 2); // step 2
}

int main() {
    bin(7);
    cout << endl;
}
