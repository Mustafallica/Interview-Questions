
// Implement parseInt
// parseInt() function parses a string argument and returns an integer of the specified radix
// Easiest way to use stl <string> and call the function (stoi) to return the value of string in int type.

#include <iostream>
#include <string>
using namespace std;


int main(){
    
    string s = "45"; // even if you write something like "45 with words" .. it will return the int value of it which is 45/
    int i = stoi(s);
    cout << i << endl;
}

