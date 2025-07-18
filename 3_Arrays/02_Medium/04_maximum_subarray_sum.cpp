// 8th July, 2025
// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N^2), SC : O(1)
int brute(vector<int> &arr, int n){
    int max_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            max_sum = max(sum, max_sum);
        }
    }
    return max_sum;
}

// Using Kadane's Algorithm
// TC : O(N), SC : O(1)
int optimal(vector<int> &arr, int n){
    int max_sum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > max_sum){
            max_sum = sum;
        }
        // If sum is less than 0(negative), then we simply discard it, because it drags us down.
        if(sum < 0){
            sum = 0;
        }
    }
    return max_sum;
}

// Follow-up Question - We have to print the subarray having maximum sum. To do this, we will store the starting and ending index of the subarray and print it.
int followUp(vector<int> &arr, int n){
    int max_sum = INT_MIN;
    int sum = 0;
    int start = 0;
    // Starting index - From the point, sum = 0
    // Ending index - Where sum > max_sum
    int startIndex = -1, endIndex = -1;
    for(int i = 0; i < n; i++){
        if(sum == 0) start = i; // Starting index

        sum += arr[i];
        if(sum > max_sum){
            max_sum = sum;

            startIndex = start;
            endIndex = i;
        }
        // If sum is less than 0(negative), then we simply discard it, because it drags us down.
        if(sum < 0){
            sum = 0;
        }
    }
    // Printing the subarray:
    cout << "The subarray is: [";
    for (int i = startIndex; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    return max_sum;
}

int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    // Below are the functions:

    // int x = brute(arr, n);
    // cout << x << endl;

    // int y = optimal(arr, n);
    // cout << y << endl;

    // int z = followUp(arr, n);
    // cout << z << endl;

    return 0;
}