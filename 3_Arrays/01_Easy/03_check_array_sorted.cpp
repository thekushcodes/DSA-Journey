// 21st June, 2025
// Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.
// Note: Two consecutive equal values are considered to be sorted.

#include <iostream>
#include <vector>
using namespace std;

// Approach (Optimal): Iterate through the array, check if each next element is greter than the previous one.
// TC : O(n), SC : O(1)
bool arraySorted(vector<int> &arr, int n){
    int sorted;
    for(int i = 0; i < n-1; ++i){
        // Condition is (i < n-1) because to eliminate out of bound access.
        if(arr[i] >= arr[i+1]){
            return false;
        }
    } 
    return true;
}

int main(){
    vector<int> arr = {-1,2,3,4,5,6,7,8};
    cout << arraySorted(arr, 8);
    return 0;
}