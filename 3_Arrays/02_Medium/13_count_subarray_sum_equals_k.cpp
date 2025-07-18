// 18th July, 2025
// Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC : O(N^3), SC : O(1)
int brute(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += arr[k];
            }
            if(sum == k){
                cnt++;
            }
        }
    }
    return cnt;
}

// TC : O(N^2), SC : O(1)
int better(vector<int> &arr, int k){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == k){
                cnt++;
            }
        }
    }
    return cnt;
}

// Using prefix-sum approach
// TC : O(N), SC : O(N)
int optimal(vector<int> &arr, int k){
    int n = arr.size();
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}

int main(){
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;

    // Below are the functions:

    // int x = brute(arr, k);
    // cout << x << endl;

    // int y = better(arr, k);
    // cout << y << endl;

    int z = optimal(arr, k);
    cout << z << endl;
    return 0;
}