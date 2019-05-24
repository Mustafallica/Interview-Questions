
// Reverse a String iteratively and recursively

#include <iostream>
using namespace std;


/*
 
 
 
 
- Method 1 (Iterative)
 
 
void reverseStr(string& str) { // Function to reverse a string
    int n = str.length();
    for (int i = 0; i < n / 2; i++)     // Swap character starting from two corners
        swap(str[i], str[n - i - 1]);}

int main() {
    string str = "mustafa";
    reverseStr(str);
    cout << str << endl;}
 
 
 
 
 
 */






/*
 

 
 
- Method 2 - Recursive
 
void recursiveReverse(string &str, int i = 0) {
    int n = str.length();
    if (i == n / 2)
        return;
    swap(str[i], str[n - i - 1]);
    recursiveReverse(str, i + 1);}

int main() {
    string str = "mustafa";
    recursiveReverse(str);
    cout << str << endl;}

 
 
 
*/




