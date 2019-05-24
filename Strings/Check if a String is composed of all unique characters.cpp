// Check if a String is composed of all unique characters


#include <iostream>
using namespace std;

bool uniqueCharacters(string str) {
    
    // If at any time we encounter 2 same characters, return false
    for (int i = 0; i < str.length(); i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                return false;}}}
    
    // If no duplicate characters encountered, return true
    return true;
}


int main() {
    
    string str = "abnc";
    
    if (uniqueCharacters(str)) {cout << "The String " << str << " has all unique characters" << endl;}
    else { cout << "The String " << str << " has duplicate characters" << endl;}

}

