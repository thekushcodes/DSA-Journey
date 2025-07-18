// 14th July, 2025
// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Brute Solution
// TC : O(N^2), SC : O(1)
bool linearSearch(vector<int> &arr, int num){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] == num) return true;
    }
    return false;
}

int brute(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return 0;

    int longestSequence = 1;
    for(int i = 0; i < n; i++){
        int curElement = arr[i];
        int cnt = 1;
        while(linearSearch(arr, curElement+1) == true){
            curElement += 1;
            cnt += 1;
        }
        longestSequence = max(cnt, longestSequence);
    }
    return longestSequence;
}

// Better Solution
// TC : O(N log N) + O(N), SC : O(1)
int better(vector<int> &arr){
    int n = arr.size();

    if(n == 0) return 0;
    int cnt = 0;
    int longestSequence = 1;
    int lastSmaller = INT_MIN;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(arr[i]-1 == lastSmaller){
            cnt += 1;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller){
            cnt = 1;
            lastSmaller = arr[i];
        }
        longestSequence = max(cnt, longestSequence);
    }
    return longestSequence;
}

// Optimal Solution
// TC : O(3*N), SC : O(N)
int optimal(vector<int> &arr){
    int n = arr.size();

    if(n == 0) return 0;
    int longestSequence = 1;
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int curElement = it;
            while(st.find(curElement+1) != st.end()){
                cnt += 1;
                curElement += 1;
            }
            longestSequence = max(cnt, longestSequence);
        }
    }
    return longestSequence;
}

int main(){
    vector<int> arr = {100, 200, 1, 2, 3, 4};

    // Below are the functions:

    // int x = brute(arr);
    // cout << x << endl;

    // int y = better(arr);
    // cout << y << endl;

    // int z = optimal(arr);
    // cout << z << endl;

    return 0;
}