// Implement binary search in a rotated array (ex. {5,6,7,8,1,2,3})

/*
 
 1) Find middle point mid = (l + h)/2
 2) If key is present at middle point, return mid.
 3) Else If arr[l..mid] is sorted - a) If key to be searched lies in range from arr[l] to arr[mid], recur for arr[l..mid].
                                    b) Else recur for arr[mid+1..r]
 4) Else (arr[mid+1..r] must be sorted) - a) If key to be searched lies in range from arr[mid+1] to arr[r], recur for arr[mid+1..r].
                                          b) Else recur for arr[l..mid]
 
*/


// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <iostream>
using namespace std;

// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
int search(int arr[], int l, int h, int key) {
    if (l > h) return -1;
    
    int mid = (l+h)/2;
    if (arr[mid] == key) return mid;
    
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) {
        /* As this subarray is sorted, we can quickly
         check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid-1, key);
        
        return search(arr, mid+1, h, key);
    }
    
    /* If arr[l..mid] is not sorted, then arr[mid... r]
     must be sorted*/
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid+1, h, key);
    
    return search(arr, l, mid-1, key);
}


int main() {
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 6;
    int i = search(arr, 0, n-1, key);
    
    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";
}
