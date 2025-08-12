// 19th July, 2025
// Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array. If the target value is not in the array, return the index at which the target should be placed, so that the order of elements remains sorted.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(log N, with base 2), SC : O(1)
// The answer to this problem is simply the implementation of lower bound.
int insertPosition(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    
    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,4,5,10,14};
    int target = 4;

    int x = insertPosition(arr, target);
    cout << x << endl;

    return 0;
}