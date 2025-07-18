// 2nd July, 2025
// Problem Statement: Given an array of integers arr[] and an integer target.
// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// TC : O(N^2), SC : O(1)
string brute(vector<int> &arr, int n, int target){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = arr[i] + arr[j];
            if(sum == target){
                return "YES";
            }
        }
    }
    return "NO";
}

// TC : O(N), SC : O(N)
string better(vector<int> &arr, int n, int target){
    unordered_map<int, int> mpp;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int rem = target - arr[i];
        if(mpp.find(rem) != mpp.end()){
            return "YES";
        }
        mpp[arr[i]] = i;
    }
    return "NO";
}

// TC : O(N) + O(N*logN), where N = size of the array, SC : O(1)
string optimal(vector<int> &arr, int n, int target){
    int left = 0, right = n-1;
    sort(arr.begin(), arr.end());
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            return "YES";
            left++;
            right--;
            // break;
        }
        else if(sum < target){
            left++;
        }
        else if(sum > target){
            right--;
        }
    }
    return "NO";
}

int main(){
    vector<int> arr = {2,6,8,1,12};
    int n = arr.size();
    int sum = 14;

    // The functions are as below:

    // string x = brute(arr, n, sum);
    // cout << x << endl;

    // string y = better(arr, n, sum);
    // cout << y << endl;

    // string z = optimal(arr, n, sum);
    // cout << z << endl;
    
    return 0;
}