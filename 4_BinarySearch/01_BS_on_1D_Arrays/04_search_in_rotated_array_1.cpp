// 21st July, 2025
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which target is present and if target is not present return -1.

#include <iostream>
#include <vector>
using namespace std;

// The brute force approach for this problem is to simply use linear search.

// TC : O(log N, base 2), SC : O(1)
int search(vector<int> &nums, int x){
    int n = nums.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high) / 2;
        if(nums[mid] == x) return mid;
        
        if(nums[low] <= nums[mid]){
            if(nums[low] <= x && x <= nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(nums[mid] <= nums[high]){
            if(nums[mid] <= x && x <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {7,8,9,1,2,3,4,5,6};
    int target = 1;

    int x = search(nums, target);
    cout << x << endl;

    return 0;
}