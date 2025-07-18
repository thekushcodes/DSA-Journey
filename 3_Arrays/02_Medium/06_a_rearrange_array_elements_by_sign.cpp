// 9th July, 2025
// Variety-1:
// Problem Statement: There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(N+N/2), SC : O(N)
vector<int> brute(vector<int> &arr, int n){
    vector<int> pos, neg;
    vector<int> result;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    for(int i = 0; i < n/2; i++){
        // Since we have to put positives and negatives in alternate position, so it is clear that positives will always be at even indices and negatives will be at odd indices.
        arr[i*2] = pos[i];
        arr[i*2+1] = neg[i];        
    }
    return arr;
}

// TC : O(N), SC : O(N)
vector<int> optimal(vector<int> &arr, int n){
    int posIndex = 0, negIndex = 1;
    vector<int> result(n, 0);
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            result[posIndex] = arr[i];
            posIndex += 2;
        }
        else{
            result[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return result;
}

int main(){
    vector<int> arr = {1,2,-4,-5};
    int n = arr.size();

    // Below are the functionns:

    // vector<int> result1 = brute(arr, n);
    // for(int i = 0; i < n; i++){
    //     cout << result1[i] << " ";
    // }
    // cout << endl;

    // vector<int> result2 = optimal(arr, n);
    // for(int i = 0; i < n; i++){
    //     cout << result2[i] << " ";
    // }
    // cout << endl;
    
    return 0;
}