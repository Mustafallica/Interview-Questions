// Merge Sort

///////////////////// Merge SORT /////////////////////

/*
 Merge sort: https://www.youtube.com/watch?v=JSceec-wEyw
 
 Time Complexity: Sorting arrays on different machines. Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.
 
 - O(nlogn)
 - Auxiliary Space: O(n)
 - Good for linked list.
 
 It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
 
 1. Split the data into two equal half until we get at most one element in both half.
 2. Merge Both into one making sure the resulting sequence is sorted.
 3. Recursively split them and merge on the basis of constraint given in step 1.
 4. Display the result.
 5. Exit.
 
 */

#include <iostream>
using namespace std;


void Merge(int a[], int low, int high, int mid){
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    
    // Merge the two parts into temp[].
    while (i <= mid && j <= high){
        if (a[i] < a[j]){
            temp[k] = a[i];
            k++;
            i++;
        } else {
            temp[k] = a[j];
            k++;
            j++;}}
    
    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid){
        temp[k] = a[i];
        k++;
        i++;}
    
    // Insert all the remaining values from j to high into temp[].
    while (j <= high){
        temp[k] = a[j];
        k++;
        j++;}
    
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++){
        a[i] = temp[i-low];}
}

// A function to split array into two parts.   // WRITE THIS ONE FIRST. THEN WRITE THE MERGE() FUNC. ABOVE IT SECOND.
void MergeSort(int a[], int low, int high){
    int mid;
    if (low < high){
        mid=(low+high)/2;
        // Split the data into two half.
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        
        // Merge them to get sorted output.
        Merge(a, low, high, mid);}
}


int main(int argc, const char * argv[]) {
    
    int arr[] = {5,6,8,2,1,20};
    int n = 6;
    
    cout << "Unsorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
    MergeSort(arr, 0, n-1);
    
    cout << "Sorted Array is: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";}
    cout << endl;
    
}


