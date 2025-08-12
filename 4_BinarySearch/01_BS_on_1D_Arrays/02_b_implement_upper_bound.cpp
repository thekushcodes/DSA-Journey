// 19th July, 2025
// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

// Upper bound means to find the smallest index at which arr[index] > num (num is given by user).

#include <iostream>
#include <vector>
#include <algorithm> // To use upper_bound()
using namespace std;

// TC : O(N), SC : O(1)
// We are using linear search to find upper bound.
int brute(vector<int> &arr, int x){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] > x){
            return i;
        }
    }
    return n;
}

// TC : O(log N, with base 2), SC : O(1)
// Here we are implementing binary search to find upper bound
int optimal1(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = (n-1);
    int ans = n;

    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] > x){
            ans = mid;
            high = mid-1;;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

// Here we are using the in-built function upper_bound
int optimal2(vector<int> &arr, int x){
    int up = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    return up;
}

int main(){
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int target = 9;

    // Below are the functions:

    int x = brute(arr, target);
    cout << x << endl;

    int y = optimal1(arr, target);
    cout << y << endl;

    int z = optimal2(arr, target);
    cout << z << endl;

    return 0;
}