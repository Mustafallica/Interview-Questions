// Insertion Sort

///////////////////// INSERTION SORT /////////////////////

/*
 INSERTION SORT
 insertion sort: https://www.youtube.com/watch?v=OGzPmgsI-pQ
 
 - Assume the first element is a sorted list, start from index[1]
 - Time Complexity: O(n^2)
 - Auxiliary Space: O(1)
 - Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
 */

#include <iostream>
using namespace std;


void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;}}}



int main(int argc, const char * argv[]) {
    
    int arr[] = {5,6,8,2,1,20};
    int n = 6;
    
    cout << "Unsorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
    insertionSort(arr, n);

    cout << "Sorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
}


