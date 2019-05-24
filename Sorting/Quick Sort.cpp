// Quick Sort


/*
 
 There are many different versions of quickSort that pick pivot in different ways.
 1- Always pick first element as pivot.
 2- Always pick last element as pivot (implemented below)
 3- Pick a random element as pivot.
 4- Pick median as pivot.
 
 O(nlogn)  - Best case:
 O(n^2)    - Worst Case: The worst case occurs when the partition process always picks greatest or smallest element as pivot.
 O(nlogn)  - The best case:  occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case.
 
 */

#include <iostream>
using namespace std;


int partition(int arr[], int start, int end){
    int i = start-1;
    int j = start;
    int pivot = arr[end];
    for (;j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i],arr[j]);}}
    swap(arr[i+1], arr[end]);
    return i+1;
}

void quickSort(int arr[], int start, int end){
    if (start >= end){
        return;}
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}


int main(int argc, const char * argv[]) {
    
    int arr[] = {5,6,8,2,1,20};
    int n = 6;
    
    cout << "Unsorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
    quickSort(arr, 0, n-1);
    
    cout << "Sorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
}


