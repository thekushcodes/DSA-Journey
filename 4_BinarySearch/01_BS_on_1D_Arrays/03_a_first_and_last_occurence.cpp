// 20th July, 2025
// Given a sorted array of N integers, write a program to find the index of the first and last occurrence of the target key. If the target is not found then return -1.

#include <iostream>
#include <vector>
#include <utility> // To use pair
using namespace std;

// TC : O(2*N), SC : O(1)
pair<int, int> bruteOccurence(vector<int> &arr, int x){
    int n = arr.size();
    pair<int, int> occurence = {-1, -1};
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            if(occurence.first == -1){
                occurence.first = i;
            }
            occurence.second = i;
        }
    }
    return occurence;
}

// The first occurence is nothing but the lower bound, and the last occurence is (upper bound - 1). That's what we are implementing here:
// TC : O(log N, base 2), SC : O(1)
int firstOccurence(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int firstOccurence = -1;

    while(low <=  high){
        int mid = (low+high) / 2;
        if(arr[mid] >= x){
            firstOccurence = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if(arr[firstOccurence] != x){
        return -1;
    }
    return firstOccurence;
}

int lastOccurence(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int lastOccurence = -1;

    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] > x){
            lastOccurence = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(lastOccurence == 0 || arr[lastOccurence-1] != x){
        return -1;
    }
    return (lastOccurence - 1);
}

int main(){
    vector<int> arr = {1,2,4,8,8,8,10};
    int target = 8;

    // Below are the functions:
    
    pair<int, int> z = bruteOccurence(arr, target);
    cout << z.first << " " << z.second << " " << endl;

    int x = firstOccurence(arr, target);
    cout << x << endl;

    int y = lastOccurence(arr, target);
    cout << y << endl;

    return 0;
}