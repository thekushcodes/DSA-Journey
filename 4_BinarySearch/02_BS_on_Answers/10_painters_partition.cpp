// 31st July, 2025
// ****Same as previous one****
// Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

// This is the statement of "Split array - largest sum" problem. Apparently, both this one and painter's partition is same. Not only this, these are exactly same as the previous problem - Allocate books.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// TC : O(N), SC : O(1)
int countPartitions(vector<int> &arr, int maxSum){
    int n = arr.size();
    int partitions = 1, subarraySum = 0;
    for(int i = 0; i < n; i++){
        if(subarraySum + arr[i] <= maxSum){
            // Insert element to current subarray
            subarraySum += arr[i];
        }
        else{
            // Insert elements to the next subarray
            partitions++;
            subarraySum = arr[i];
        }
    }
    return partitions;
}

// TC : O(N * log( sum(arr)-max(arr) )), SC : O(1)
int optimal(vector<int> &arr, int k){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low + high) / 2;
        if(countPartitions(arr, mid) > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    int x = optimal(arr, k);
    cout << x << endl;

    return 0;
}