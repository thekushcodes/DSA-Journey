// 29th July, 2025
// Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // To use accumulate()
using namespace std;

// TC : O(N), SC : O(1)
int findDays(vector<int> &arr, int capacity){
    int n = arr.size();
    int current_load = 0;
    int days_needed = 1;
    for(int i = 0; i < n; i++){
        if(current_load + arr[i] > capacity){
            days_needed++;
            current_load = arr[i];
        } else{
            current_load += arr[i];
        }
    }
    return days_needed;
}

// TC : O(N * (sum(arr) - max(arr) + 1)), SC : O(1)
int brute(vector<int> &arr, int days){
    int n = arr.size();
    int sumArray = accumulate(arr.begin(), arr.end(), 0);
    int maxElement = *max_element(arr.begin(), arr.end());
    for(int i = maxElement; i <= sumArray; i++){
        if(findDays(arr, i) <= days) return i;
    }
    return -1;
}

// TC : O(N * log(sum(arr) - max(arr) + 1)), SC : O(1)
int optimal(vector<int> &arr, int days){
    int sumArray = accumulate(arr.begin(), arr.end(), 0);
    int maxElement = *max_element(arr.begin(), arr.end());
    int low = maxElement, high = sumArray;
    while(low <= high){
        int mid = (low + high) / 2;
        if(findDays(arr, mid) <= days){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    int x = brute(arr, days);
    cout << x << endl;

    int y = optimal(arr, days);
    cout << y << endl;
    
    return 0;
}