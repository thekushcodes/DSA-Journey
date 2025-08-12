// 23rd July, 2025
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

// In order to find the number of times an array is rotated, we just have to find it's pivot, which means the minimum element. So this program is exact same as the previous one, we just have to find the index of minimum element.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(log N, base 2), SC : O(1)
int rotated(vector<int> &nums){
    int n = nums.size();
    int low = 0, high = n-1;
    int index = -1;
    int minElement = INT_MAX;

    while(low <= high){
        int mid = low + (high - low) / 2;
        // If search space is already sorted:
        if(nums[low] <= nums[high]){
            if(nums[low] < minElement){
                minElement = nums[low];
                index = low;
            }
            break;
        }
        // Left sorted
        if(nums[low] <= nums[mid]){
            if(nums[low] < minElement){
                index = low;
                minElement = nums[low];
            }
            low = mid + 1;
        }
        // Else right sorted
        else{
            if(nums[mid] < minElement){
                index = mid;
                minElement = nums[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

    int x = rotated(arr);
    cout << x << endl;

    return 0;
}