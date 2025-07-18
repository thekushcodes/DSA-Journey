// 22nd June, 2025
// Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(n), SC : O(1)
int linearSearch(vector<int> arr, int n, int num){
    for(int i = 0; i < n; i++){
        if (arr[i] == num){
            return i;
            break;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,4,5,8,6,18};
    int n = arr.size();
    
    int num = 18;
    cout<<linearSearch(arr, n, num);
    // Answer will be returned in zero-based indexing
    return 0;
}