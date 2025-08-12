// 30th July, 2025
// Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(N), SC : O(1)
int brute(vector<int> &arr, int k){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
}

// TC : O(log N), SC : O(1)
int optimal(vector<int> &arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        int missingNumbers = arr[mid] - (mid + 1);
        if(missingNumbers < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    // We are returning (low + k) because: 
    // First of all after completion of BS, high will point to index after which kth missing number will be found and low will be pointing next to high, i.e., the element before which kth missing element is.
    // So we know till high, missing numbers = arr[high] - high + 1, according to formula, but we need to go further to get more missing elements to get the kth one since kth one lies after high.
    // More missing numbers = k - (arr[high] - (high + 1))
    // Now, we will simply add more missing elements to the arr[high], therefore- kth element = arr[high] + missing = arr[high] + [k - (arr[high] - (high + 1))].
    // Simplifying the above equation, kth missing element = high + 1 + k. And (high + 1) is nothing but low in this case, so return (low + k) or (high + 1 + k).
    return low + k;
}

int main(){
    vector<int> arr = {4, 7, 9, 10};
    int k = 4;

    int x = brute(arr, k);
    cout << x << endl;

    int y = optimal(arr, k);
    cout << y << endl;

    return 0;
}