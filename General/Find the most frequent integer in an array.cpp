/*
 
- Find the most frequent integer in an array

* An efficient solution is to use hashing. We create a hash table and store elements and their frequency counts as key value pairs.
 Finally we traverse the hash table and print the key with maximum value. *

*/


#include <iostream>
#include <unordered_map>
using namespace std;

int mostFrequent(int arr[], int n) {
    
    // Insert all elements in hash.
    unordered_map<int, int> hash;
    int max_count = 0, res = -1;
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        hash[key]++;
        if (max_count < hash[key]) {
            max_count = hash[key];
            res = arr[i];
        }
    }
    return res;
}

int main() {
    int arr[] = { 5, 5, 2, 1, 5, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mostFrequent(arr, n) << endl;
    return 0;
}
