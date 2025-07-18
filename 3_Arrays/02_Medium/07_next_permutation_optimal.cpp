// 10th July, 2025
// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(3*N), SC : O(1)
vector<int> optimal(vector<int> &arr){
    int n = arr.size();
    int index = -1;
    // The below loop is to find the break-point, where arr[i] < arr[i+1] when we traverse the array from behind.
    for(int i = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1) // Means if the array is in decreasing order, or you can say it is the last permutation, we will return the first permutation.
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    // Find the next greater element from index and swap them both.
    for(int i = n-1; i > index; i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }
    // Reverse the entire right half(i.e. from index i+1 to n-1) of index i.
    reverse(arr.begin()+index+1, arr.end());
    return arr;

}

int main(){
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};

    // This is a better approach than the brute force, which uses C++ STL directly.
    // next_permutation(arr.begin(), arr.end());
    // for(auto it : arr){
    //     cout << it << " ";
    // }

    vector<int> result = optimal(arr);
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}