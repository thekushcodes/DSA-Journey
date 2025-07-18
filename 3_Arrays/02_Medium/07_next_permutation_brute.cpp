// 10th July, 2025
// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
// This program contains the brute force solution only.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This is brute force approach.
// TC : O(N! * N), SC : O(N! * N) + O(N)(recursion) {The total number of permutations is n! (n factorial)}
// The total time and space taken is too much so for bigger number having more number of digits, is quite bothersome with this technique.
void permute(vector<int> &arr, int index, vector<vector<int> > &ans){
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }   
    for(int i = index; i < arr.size(); i++){
        swap(arr[i], arr[index]);
        permute(arr, index+1, ans);
        swap(arr[i], arr[index]);
    }
}
vector<int> findNextPermutation(vector<int> &arr, vector<vector<int> > &ans){
    int index = -1;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            if(ans[i] == arr){
                index = i; // Now index stores the index of input array in the permutations list.
                break;
            }
        }
    }
    return ans[index+1];
}

int main(){
    vector<int> arr = {1,2,3};
    sort(arr.begin(), arr.end()); // Sorting the array gives us all possible combinations.
    vector<vector<int> > ans; // In this vector, all our permutations will be stored.
    permute(arr, 0, ans); // This is the recursive function to compute all possible permutations and store it in ans vector.
    // The below piece of code is to print all permutations stored in ans vector.
    // for(int i = 0; i < ans.size(); i++){
    //     for(int j = 0; j < ans[i].size(); j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> result = findNextPermutation(arr, ans);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}