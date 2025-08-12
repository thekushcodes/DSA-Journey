// 23rd July, 2025
// Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(N), SC : O(1)
int brute(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return -1;
    if(n == 1) return 0;

    for(int i = 0; i < n; i++){
        if((i == 0 || arr[i-1] < arr[i]) && (i == n-1 || arr[i] > arr[i+1])){
            return i;
        }
    }
    return -1;
}

// TC : O(log N, base 2), SC : O(1)
int optimal(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return -1;
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return mid;
        }
        else if(arr[mid] > arr[mid-1]){
            low = mid + 1;
        }
        else if(arr[mid] > arr[mid+1]){
            high = mid - 1;
        }
        // The below condition is added just for the case where there are multiple (>1) peaks. So, the above conditions do not check if(arr[mid] < arr[mid+1] && arr[mid] < arr[mid-1]), like {2,1,3}, so if mid reaches element-1, it gets stuck in an infinite loop.
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};

    int peakElement1 = brute(arr);
    cout << peakElement1 << endl;

    int peakElement2 = optimal(arr);
    cout << peakElement2 << endl;

    return 0;
}