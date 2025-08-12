// 28th July, 2025
// Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

#include <iostream>
#include <vector>
#include <algorithm> // To use max_element()
#include <cmath> // To use ceil()
using namespace std;

//TC : O(max(arr) * N), SC : O(1)
int brute(vector<int> &arr, int limit){
    int n = arr.size();
    if(n > limit) return -1;
    
    for(int i = 1; i <= *max_element(arr.begin(), arr.end()); i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += ceil((double)(arr[j]) / (double)(i));
        }
        if(sum <= limit) return i;
    }
    return -1;
}

// TC : O(N), SC : O(1)
int calcSum(vector<int> &arr, int limit, int mid){
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += ceil((double)(arr[i]) / (double)(mid));
    }
    return sum;
}

// TC : O((max(arr)-min(Arr)+1) * N), SC : O(1)
int optimal(vector<int> &arr, int limit){
    int n = arr.size();
    if(n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());
    while(low <= high){
        int mid = (low + high) / 2;
        if(calcSum(arr, limit, mid) <= limit){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;

    int x = brute(arr, limit);
    cout << x << endl;

    int y = optimal(arr, limit);
    cout << y << endl;
    
    return 0;
}