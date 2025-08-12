// 22nd July, 2025
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

// The duplicates may pose the problem when we check which half is sorted, like in the previous program. Eg.- {3,3,1,2,3,3,3,3,3,3}, here arr[low] == arr[mid] == arr[high]. So we cannot determine which half is sorted. Therefore, we just trim down the search space by - low++ and high--, whenever this condition is fulfilled - arr[low] == arr[mid] == arr[high].

#include <iostream>
#include <vector>
using namespace std;

// TC : O(logN) for best and avg case, O(N/2) for worst case, SC : O(1)
bool search(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high-low) / 2; // Another way to calculate avg of low and high. This is a safer way because if both low and high are INT_MAX then their sum will exceed the limit.
        if(arr[mid] == x) return true;
        // Below line of code is the only difference from the previous program which contains no duplicates.
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }
        // Check if left half is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= x && x <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= x && x <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> arr = {3,3,1,2,3,3,3,3,3,3};
    int target = 3;

    bool x = search(arr, target);
    cout << x << endl;

    return 0;
}