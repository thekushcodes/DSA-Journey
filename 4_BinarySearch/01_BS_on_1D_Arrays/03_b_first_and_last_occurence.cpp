// 21st July, 2025
// Problem Statement: Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(log N, base 2), SC : O(1)
int firstOccurence(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int first = -1;

    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] == x){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return first;
}

// TC : O(log N, base 2), SC : O(1)
int lastOccurence(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int last = -1;

    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] == x){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return last;
}

// Using this function to call the above two functions, in order to save time when possible(like, if first = -1, means there is no need to search for last).
pair<int, int> firstLast(vector<int> &arr, int x){
    int first = firstOccurence(arr, x);
    if(first != -1){
        int last = lastOccurence(arr, x);
        return {first, last};
    }
    return {-1, -1};
}

int main(){
    vector<int> arr = {1,2,4,8,8,8,10};
    int target = 8;

    pair<int, int> occurence = firstLast(arr, target);
    cout << occurence.first << " " << occurence.second << " " << endl;

    return 0;
}