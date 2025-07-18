// !st July, 2025
// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// TC : O(n ^ 2), SC : O(1)
int brute(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count == 1){
                return arr[i];
        }
    }
    return -1;
}

// TC : O(n log m) + O(m), SC : O(m), where n-> size of input array and m-> size of map {n+1/2}s
int better(vector<int> &arr, int n){
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

// TC : O(n), SC : O(1)
// The below methid, using XOR will only work if all the other elements appears twice, only then the even times cancel out to 0 and we the the element appearing one time only.
int optimal(vector<int> &arr, int n){
    int xor1 = 0;
    for(int i = 0; i < n; i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}

int main(){
    vector<int> arr = {1,2,1,3,3,4,4};
    int n = arr.size();

    // These are the functions:

    int x = brute(arr, n);
    cout << x << endl;

    int y = better(arr, n);
    cout << y << endl;

    int z = optimal(arr, n);
    cout << z << endl;

    return 0;
}