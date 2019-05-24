// Determine if 2 Strings are anagrams


#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


bool is_anagram(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;}


int main() {
    
    cout << "'1 = Anagrams OR 0 = Not Anagrams' || :::: The answer is: -> " << is_anagram("mustafa", "afatjfdfdfdsum") << endl;
    
}
