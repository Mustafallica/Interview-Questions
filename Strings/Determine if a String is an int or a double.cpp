// Determine if a String is an int or a double


#include <iostream>
using namespace std;

// Returns true if s is a number else false
bool isNumber(string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}


int main() {
    
    // Saving the input in a string
    string str;
    cout << "Enter a string number: ";
    cin >> str;

    
    // Function returns 1 if all elements are in range '0-9'
    if (isNumber(str)) cout << "Integer" << endl;
    
    // Function returns 0 if the input is not an integer
    else cout << "Double" << endl;
}
