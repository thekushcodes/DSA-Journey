// 20th July, 2025
// Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].

// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(log N, base 2), SC : O(1)
int floor(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int floor = -1;

    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] <= x){
            floor = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return floor;
}

// TC : O(log N, base 2), SC : O(1)
int ceil(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int ceil = -1;

    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] >= x){
            ceil = arr[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ceil;
}

int main(){
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;

    int x = floor(arr, target);
    cout << x << endl;

    int y = ceil(arr, target);
    cout << y << endl;

    return 0;
}