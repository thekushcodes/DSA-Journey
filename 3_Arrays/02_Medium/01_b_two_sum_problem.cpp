// 3rd July, 2025
// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility> // To use pair, although few compilers has this default, but including it is a good practice.
using namespace std;

// TC : O(N^2), SC : O(1)
vector<pair<int, int>> brute(vector<int> &arr, int n, int target){
    vector<pair<int, int>> index;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = arr[i] + arr[j];
            if(sum == target){
                index.push_back({i,j});
            }
        }
    }
    return index;
}

// TC : O(N), SC : O(N)
vector<pair<int, int>> better(vector<int> &arr, int n, int target){
    unordered_map<int, int> mpp;
    vector<pair<int, int>> index;
    // int sum = 0;
    for(int i = 0; i < n; i++){
        int rem = target - arr[i];
        if(mpp.find(rem) != mpp.end()){
            index.push_back({mpp[rem], i});
        }
        // This will work if the array elements are unique because doing mpp[arr[i]] = i will over-write previous indices.
        mpp[arr[i]] = i;
    }
    return index;
}

// TC : O(N) + O(N*logN), where N = size of the array, SC : O(1)
vector<pair<int, int>> optimal(vector<int> &arr, int n, int target){
    vector<pair<int, int>> index;
    // Since we are sorting this to use two-pointers, the resulting index will also be of the sorted array and not the original array.
    sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            index.push_back({left, right});
            left++;
            right--;
        }
        else if(sum < target) left++;
        else right--;
    }
    return index;
}



int main(){
    vector<int> arr = {2,6,8,1,12};
    int n = arr.size();
    int sum = 14;

    // The functions as well as their result blocks are as below:

    // vector<pair<int, int>> result1 = brute(arr, n, sum);
    // for(auto it : result1){
    //     cout << it.first << " " << it.second;
    //     cout << endl;
    // }

    // vector<pair<int, int>> result2 = better(arr, n, sum);
    // for(auto it : result2){
    //     cout << it.first << " " << it.second;
    //     cout << endl;
    // }

    // vector<pair<int, int>> result3 = optimal(arr, n, sum);
    // for(auto it : result3){
    //     cout << it.first << " " << it.second;
    //     cout << endl;
    // }

    return 0;
}