// 27th July, 2025
// Problem Statement: You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(N * (max(arr) - min(arr)+1), SC : O(1)
int brute(vector<int> &arr, int k, int m){
    int n = arr.size();
    if(m*k > arr.size()) return -1; // Not enough flowers.

    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] < mini) mini = arr[i];
        if(arr[i] > maxi) maxi = arr[i];
    }
    for(int i = mini; i <= maxi; i++){
        int noOfBouquets = 0;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] <= i){
                cnt++;
                if(cnt == k){
                    noOfBouquets++;
                    cnt = 0;
                }
            }
            else{
                cnt = 0;
            }
        }
        if(noOfBouquets >= m) return i;
    }
    return -1;
}

// TC : O(N), SC : O(1)
bool possible(vector<int> &arr, int day, int k, int m){
    int n = arr.size();
    int cnt = 0;
    int noOfBouquets = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] <= day){
            cnt++;
            if(cnt == k){
                noOfBouquets++;
                cnt = 0;
            }
        }
        else if(arr[i] > day){
            cnt = 0;
        }
    }
    return noOfBouquets >= m;
}
// TC : O(N * log(max(arr)-min(arr)+1), base 2), SC : O(1)
int optimal(vector<int> &arr, int k, int m){
    if(m * k > arr.size()) return -1; // Not enough flowers.
    int n = arr.size();

    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
    }

    int low = mini, high = maxi;
    while(low <= high){
        int mid = (low + high) / 2;
        if(possible(arr, mid, k, m)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3, m = 2;

    int x = brute(arr, k, m);
    cout << x << endl;
    
    int y = optimal(arr, k, m);
    cout << y << endl;
    
    return 0;
}