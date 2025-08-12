// 23rd July, 2025
// Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(N), SC : O(1)
// Using Linear search:
int brute1(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    for(int i = 1; i < n-1; i++){
        if(arr[i] != arr[i+1] && arr[i] != arr[i-1]){
                return arr[i];
        }
    }
    return -1;
}

// TC : O(N), SC : O(1)
// Using XOR:
int brute2(vector<int> &arr){
    int n = arr.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

// TC : O(log N, base 2), SC : O(1)
// Using binary search:
int optimal(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    // If(even, odd)-> The single element is on the right half
    // If(odd, even)-> The single element is on the left half

    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
        if((mid % 2 == 1 && arr[mid-1] == arr[mid]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    int x = brute1(arr);
    cout << x << endl;

    int y = brute2(arr);
    cout << y << endl;

    int z = optimal(arr);
    cout << z << endl;

    return 0;
}