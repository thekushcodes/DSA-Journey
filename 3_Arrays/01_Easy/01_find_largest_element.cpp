// 20th June, 2025
// Question: Given an array, we have to find the largest element in the array

#include <iostream>
using namespace std;

// Approach 1: Sort the array, then return the last element. TC : O(n * log n), SC : O(n)

// Approach 2 (Better): Iterate through the array, then find and store the largest element. TC : O(n), SC : O(1)
int largestElement(int arr[], int n){
    int largest = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

int main(){
    int arr[5] = {1,56,78,0,-89};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<largestElement(arr, n);
    return 0;
}