// Determine if one array is a rotated version of the another given array

// QUESTION: Given 2 integer arrays, determine of the 2nd array is a rotated version of the 1st array. Ex. Original Array A={1,2,3,5,6,7,8} Rotated Array B={5,6,7,8,1,2,3}



#include <iostream>
using namespace std;

int size=10;
int a1[10]={1,2,3,4,5,6,7,8,9,10};
int a2[10]={5,6,7,8,9,10,1,2,3,4};

void compareFirstArray(int x) {
    
    int y=0;
    for(int k=x;k<size;k++) {
        
        if(a1[k]==a2[y])
            y++;
        else {
            cout<<"The arrays aren't rotated versions of each other"<<endl;}}
    cout<<"The arrays are rotated versions of each other"<<endl;
}

void compareSecondArray(int a) {
    int c=0;
    for(int j=a;j<size;j++) {
        if(a1[c]==a2[j])
            c++;
        
        else {
            cout<<"The arrays aren't rotated versions of each other"<<endl;}}
    compareFirstArray(c);
}


int main() {
    
    for(int i=0;i<size;i++){
        if(a1[0]==a2[i])
            compareSecondArray(i);}
}

