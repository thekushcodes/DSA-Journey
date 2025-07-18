// 9th July, 2025
// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N^2), SC : O(1)
int brute(vector<int> &arr, int n){
    int maxProfit = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                int profit = arr[j] - arr[i];
                maxProfit = max(profit, maxProfit);
            }
        }
    }
    return maxProfit;
}

// TC : O(N), SC : O(1)
int optimal(vector<int> &arr, int n){
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < n; i++){
        minPrice = min(minPrice, arr[i]);
        maxProfit = max((arr[i] - minPrice), maxProfit);
    }
    return maxProfit;
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};
    int n = arr.size();

    // Below are the functions:

    // int x = brute(arr, n);
    // cout << x << endl;

    // int y = optimal(arr, n);
    // cout << y << endl;
    return 0;
}