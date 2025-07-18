// 22nd June, 2025
// Problem Statement: Given an array of integers, rotating array of elements by k elements to the left.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(n), SC : O(d) (Since d elements needs to be stored in array)
void brute(vector<int> &arr, int n, int d){
    d = d % n; // Handle d > n
    // Step 1: Store first d elements
    vector<int> temp;
    for(int i = 0; i < d; i++){
        temp.push_back(arr[i]);
    }

    // Step 2: Shift remaining elements to the left
    for (int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }

    // Step 3: Copy temp elements to the end
    for (int i = 0; i < d; i++){
        arr[n - d + i] = temp[i];
    }
}

// TC : O(n), SC : O(1)
void optimal1(vector<int> &arr, int n, int d){
    // If use STL functions, this can be done very simple:
    d = d % n;
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());
}

// The above thing is done manually here. Above, we are using reverse function from STL, but this time we will make our own reverse function as below and then RotateLeft as same.
// TC : O(n), SC : O(1)
void reverseArr(vector<int> &arr, int start, int end){
    while(start <=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotateLeft(vector<int> &arr, int k, int n){
    k = k % n;
    reverseArr(arr, 0, k-1);
    reverseArr(arr, k, n-1);
    reverseArr(arr, 0, n-1);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int n = arr.size();
    int d = 3;

    // These are the functions, use any one at a time:
    // brute(arr, n, d);
    // optimal1(arr, n, d);
    rotateLeft(arr, d, n);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}