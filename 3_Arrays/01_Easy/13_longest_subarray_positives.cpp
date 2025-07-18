// 2nd July, 2025
// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// TC : O(n^3), SC : O(1)
int brute(vector<int> &arr, int n, int k){
    int len = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int l = i; l <= j; l++){
                sum += arr[l];
            }
            if(sum == k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

// TC : O(n^2), SC : O(1)
int better1(vector<int> &arr, int n, int k){
    int len = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

// TC : O(n log n) -> For Ordered map and O(n)-> Unordered_Map (Without worst case, just the loop), but O(n^2) -> Unordered_Map in worst case(Unordered_Map takes O(n))
// SC : O(n)
int better2(vector<int> &arr, int n, int k){
    int maxLen = 0;
    int sum = 0;
    map<int, int> preSumMap;
    for(int i = 0; i < n; i++){
        //calculate the prefix sum till index i:
        sum += arr[i];
        // if the sum = k, update the maxLen:
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

// TC : O(2*n), SC : O(1)
int optimal(vector<int> &arr, int n, int k){
    int left = 0, right = 0;
    int sum = arr[0];
    int len = 0;
    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            len = max(len, right-left+1);
        }

        right++;
        if(right < n){
            sum += arr[right];
        }
    }
    return len;
}

int main(){
    vector<int> arr = {2, 3, 5, 1, 9};
    int requiredSum = 10;

    // The functions are:

    int x = brute(arr, arr.size(), requiredSum);
    cout << x << endl;

    int y = better1(arr, arr.size(), requiredSum);
    cout << y << endl;

    int z = better2(arr, arr.size(), requiredSum);
    cout << z << endl;

    int t = optimal(arr, arr.size(), requiredSum);
    cout << t << endl;
    return 0;
}