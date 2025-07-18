// 22nd June, 2025
// Problem Statement: Given an array of N integers, left rotate the array by one place.

#include <iostream>
using namespace std;

// TC : O(n), SC : O(1)
void leftRotate(int arr[], int n){
    // Stores the first element
    int temp = arr[0];
    // Shifting the other elements
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    // Adding the 1st element in the last of the array
    arr[n-1] = temp;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    leftRotate(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}