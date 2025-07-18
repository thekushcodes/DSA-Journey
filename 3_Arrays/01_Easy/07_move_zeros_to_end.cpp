// 22nd June, 2025
// Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

#include <iostream>
#include <vector>
using namespace std;

// TC : ~O(2n), SC : O(n)
void brute(vector<int> &arr, int n){
    // Step 1: Adding non-zero elements in temp vector
    vector<int> temp;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    // Step 2: Re-entering the non-zero elements from temp to original array, from start
    for(int i = 0; i < temp.size(); i++){
        arr[i] = temp[i];
    }
    // Step 3: Finally, putting 0s in the last, after adding all non-zero elements
    for(int i = temp.size(); i < n; i++){
        arr[i] = 0;
    }
}

// TC : O(n), SC : O(1)
vector<int> optimal(vector<int> &arr, int n){
    // Step 1: Find the first occurence of 0, and place pointer j at that index.
    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }

    // In case of no non-zero elements
    if(j == -1) return arr;

    // Step 2: Swap the non-zero element with 0, so that non-zero comes first and zero shifts further.
    for(int i = j+1; i < n; i++){
        if(arr[i] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {1,0,4,2,0,0,5,1};
    int n = arr.size();
    // brute(arr, n);
    optimal(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}