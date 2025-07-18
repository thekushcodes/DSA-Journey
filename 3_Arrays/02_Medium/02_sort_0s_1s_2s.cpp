// 3rd July, 2025
// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

#include <iostream>
#include <vector>
using namespace std;

// TC : O(2*N), SC : O(1)
void better(vector<int> &arr, int n){
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count0++;
        }
        else if(arr[i] == 1){
            count1++;
        }
        else{
            count2++;
        }
    }
    for(int i = 0; i < count0; i++){
        arr[i] = 0;
    }
    for(int i = count0; i < count0+count1; i++){
        arr[i] = 1;
    }
    for(int i = count0+count1; i < count2; i++){
        arr[i] = 2;
    }
}

// TC : O(N), SC : O(1)
// This is Dutch National Flag algorithm, created by Dijkstra.
// This algorithm uses 3 pointers to sort array having only 0s, 1s, 2s.
void optimal(vector<int> &arr, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr = {0,0,1,1,1,2,0,1,0,0,2,2,2};
    int n = arr.size();

    // The brute force approach is done by simply using a sorting technique, like Merge sort/

    // better(arr, n);
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // optimal(arr, n);
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    return 0;
}