// Bubble Sort

/*
 BUBBLE SORT
 bubble sort. : https://www.youtube.com/watch?v=nmhjrI-aW5o
 O(n^2)
 
 - Worst and Average Case Time Complexity: O(n^2). Worst case occurs when array is reverse sorted.
 - Average case: O(n^2)
 - Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
 - Auxiliary Space: O(1)
 - Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
 
 */

#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n){ // takes an array and elements number
    while (1) { // 1 means while is true.
        int swapped = 0; // var to check if list is sorted. The only time it will become 0 when it is sorted then it will break. line 134.
        for (int i = 0; i < n-1; i++) { // for loop to check the list.
            if (arr[i] > arr[i+1]) { // check  every number and compare it to the number after it. first number > number after. Then switch
                int temp = arr[i]; // var temp to store the arr[i] the bigger value.
                arr[i] = arr[i+1]; // replace the second index number arr[i+1] and replace it with arr[i].
                arr[i+1] = temp; // store the index of the smaller number arr[i+1] to the first bigger number arr[i].
                swapped = 1;}} // swapped = 1, means the list is unsorted yet.
        if (swapped == 0) { // if swap is 0, then the sort is sorted. Break.
            break;}}}

int main(int argc, const char * argv[]) {
    
    int arr[] = {5,6,8,2,1,20};
    int n = 6;
    
    cout << "Unsorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
    bubbleSort(arr, n);

    cout << "Sorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
}


