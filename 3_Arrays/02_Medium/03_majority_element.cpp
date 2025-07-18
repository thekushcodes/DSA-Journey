// 7th July, 2025
// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// TC : O(N^2), SC : O(1)
int brute(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count > n/2) return arr[i];
    }
    return -1;
}

// TC : O(2*N), SC : O(N) (In unordered_map, the TC in worst-case in O(N^2) for searching).
int better(vector<int> &arr, int n){
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second > n/2) return it.first;
    }
    return -1;
}

// Moore's Voting Algoruthm:
// 👉 What this does:
// You go through the array.

// If your count is 0, you pick the current element as your new candidate.

// If the current element is equal to your candidate, you increase the count (like getting support).

// If it's not equal, you decrease the count (like someone disagrees with your candidate).

// 🎯 The magic:
// If there's truly a majority element, it will survive all the cancellations and be left at the end.

// TC : O(N), SC : O(1)
int optimal(vector<int> &arr, int n){
    int count = 0;
    int el;
    for(int i = 0; i < n; i++){
        if(count == 0){
            count = 1;
            el = arr[i];
        }
        else if(arr[i] == el){
            count++;
        }
        else{
            count--;
        }    
    }
    // Now we are checking the number of time the majority element (el) appears so that we can make sure it appears more tha n/2 times
    int count1 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == el){
            count1++;
        }
    }
    // Now if count of majority element is greater than n2, just return the element
    if(count1 > n/2){
        return el;
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int n = arr.size();

    // Below are the functions:

    // int x = brute(arr, n);
    // cout << x << endl;

    // int y = better(arr, n);
    // cout << y << endl;

    // int z = optimal(arr, n);
    // cout << z << endl;

    return 0;
}