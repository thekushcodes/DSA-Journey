// 19th July, 2025
// Problem Statement: You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(log N base 2), SC : O(1)
int iterative(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low += 1;
        }
        else{
            high -= 1;
        }
    }
    return -1;
}

// TC : O(log N base 2), SC : O(1)
int recursive(vector<int> &arr, int target, int low, int high){
    if(low > high) return -1;

    int n = arr.size();

    int mid = (low+high) / 2;

    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target){
        return recursive(arr, target, low, mid-1);
    }
    return recursive(arr, target, mid+1, high);
}

int main(){
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int n = arr.size();
    int target = 6;

    // Both iterative and recursive funvtions are written: 

    // int x = iterative(arr, target);
    // cout << x << endl;

    // int y = recursive(arr, target, 0, n-1);
    // cout << y << endl;

    return 0;
}