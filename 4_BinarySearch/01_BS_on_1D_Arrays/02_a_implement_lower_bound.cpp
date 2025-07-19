// 19th July, 2025
// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N), SC : O(1)
// We can do it using binary search.
int method1(vector<int> &nums, int x){
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = n;
    
    while(low <= high){
        int mid = (low+high) / 2;
        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else if(nums[mid] < x){
            low = mid + 1;
        }
    }
    return ans;
}

// TC : O(log N with base 2), SC : O(1)
// We can directly use lower_bound function available in C++.
int method2(vector<int> &nums, int x){
    // lower_bound function returns an iterator that's why we need to subtract nums.begin() to get the index.
    int lb = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    return lb;
}

// *****There is one more brute force method where we use linear search to find nums[i] >= x, i.e., lower bound.

int main(){
    vector<int> nums = {3, 5, 8, 15, 19};
    int target = 15;

    // Below are the functions:

    int x = method1(nums, target);
    cout << x << endl;

    int y = method2(nums, target);
    cout << y << endl;
    
    return 0;
}