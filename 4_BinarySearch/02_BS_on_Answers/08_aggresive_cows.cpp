// 30th July, 2025
// Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'cows' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'cows' cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N), SC : O(1)
int canWePlace(vector<int> &arr, int distance, int cows){
    int n = arr.size();
    int cntCows = 1;
    int last = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - last >= distance){
            cntCows++;
            last = arr[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

// TC : O(N log N) + O(N * arr[n-1] - arr[0]), SC : O(1)
int brute(vector<int> &arr, int cows){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int last = -1;
    int limit = arr[n-1] - arr[0];
    for(int i = 1; i <= limit; i++){
        if(canWePlace(arr, i, cows) == false){
            return i-1;
        }
    }
    return limit;
}

// TC : O(N log N) + O(N * log(arr[n-1] - arr[0])), SC : O(1)
int optimal(vector<int> &arr, int cows){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[n-1] - arr[0];
    while(low <= high){
        int mid = (low + high) / 2;
        if(canWePlace(arr, mid, cows)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    vector<int> arr = {0,3,4,7,10,9};
    int cows = 4;

    int x = brute(arr, cows);
    cout << x << endl;

    int y = optimal(arr, cows);
    cout << y << endl;
    
    return 0;
}