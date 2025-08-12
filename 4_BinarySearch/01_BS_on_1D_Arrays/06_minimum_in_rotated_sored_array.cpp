// 22nd July, 2025
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

#include <iostream>
#include <vector>
using namespace std;

// TC : O(log n, base 2), SC : O(1)
int minElement(vector<int> &arr){
    int n = arr.size();
    int low = 0, high = n-1, ans = INT_MAX;

    while(low <= high){
        int mid = low + (high - low) / 2;
        // An optimisation if want to do:
        // There could be a situation, when we have already eliminated one half of the array and now the remaining part of the array if sorted then in this case we can simply take the first element of the remaining array to be the minimum array. Eg.- Original array-> {4,5,6,1,2,3} -->> mid will be index-3 and take min from sorted array (here - 1, from 1,2,3) then we remove; it and we are left with {4,5,6}, then this array is actually sorted, so we can just take its first element and compare it with ans. This is implemented below:
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
        }
        // Left sorted
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

    int x = minElement(arr);
    cout << x << endl;
    
    return 0;
}