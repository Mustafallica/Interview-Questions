// Selection Sort

///////////////////// Selection SORT /////////////////////

/*
 SELECTION SORT
 selection sort. : https://www.youtube.com/watch?v=xWBP4lzkoyM
 
 - Time Complexity: O(n^2) as there are two nested loops.
 - Auxiliary Space: O(1)
 
 The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
 */


#include <iostream>
using namespace std;


void selectionSort(int a[], int n){ // takes array and number of elements
    for (int i = 0; i < n-1; i++) { // for loop to assume the current [i]th is the minimum number.
        int minIndex = i; // min. index [i] to be stored in minIndex
        
        for (int j = i + 1; j < n; j++) { // finding the remaining minimum element in the array
            if (a[j] < a[minIndex]) { // if second loop j is bigger than i index in first loop
                minIndex = j; // swapping
            }}
        swap(a[minIndex],a[i]); // swapping elements
    }}



int main(int argc, const char * argv[]) {
    
    int arr[] = {5,6,8,2,1,20};
    int n = 6;
    
    cout << "Unsorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
    selectionSort(arr, n);

    cout << "Sorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
}


