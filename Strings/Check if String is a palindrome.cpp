// Check if String is a palindrome


#include <iostream>
using namespace std;

// A function to check if a string str is palindrome
void isPalindrome(char str[]) {
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;
    
    // Keep comparing characters while they are same
    while (h > l) {
        if (str[l++] != str[h--]) {
            cout << str << " is Not Palindrome " << endl;
            return;}}
    cout << str << " is Palindrome " << endl;
}

// Driver program to test above function
int main() {
    isPalindrome("abba");
    isPalindrome("abbccbba");
    isPalindrome("meeek");
}
