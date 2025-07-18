// 21st June, 2025
// Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.
// If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.
//Note: Return k after placing the final result in the first k slots of the array.

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// TC : O(n * log n) + O(n), SC : O(n)
int brute(vector<int> &arr, int n){
    set<int> stt; // Using set because it stores unique elements (No duplicates)
    for(int i = 0; i < n; i++){
        stt.insert(arr[i]);
    }
    // Entering the unique elements in the array
    int j = 0;
    for(int x : stt){
        arr[j++] = x;
    }
    // Returning the size of set (Number of unique elements)
    int k = stt.size();
    return k;
}

// TC : O(n), SC : O(1)
int optimal(vector<int> &arr, int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return (i+1);
}

int main(){
    vector<int> arr = {1,1,2,2,2,3,3};
    // cout<<brute(arr, 7)<<endl;;
    cout<<optimal(arr, 7)<<endl;

    return 0;
}