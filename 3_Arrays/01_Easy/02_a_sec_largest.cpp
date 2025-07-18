// 20th June, 2025
// Problem Statement: Given an array, find the second largest element in the array. Print ‘-1’ in the event that second largest doesn’t exist.

#include <iostream>
#include <vector>
#include <algorithm> // To use sort()
#include <climits> // To use min, max
using namespace std;

// Brute force - Only works if no duplicates.
// Approach: Sort the given vector, then print the 2nd last element.
// TC : O(n * log n) (To sort), SC : O(1)
void brute(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    int secLargest = arr[n-2];
    cout<<"Second largest : "<<secLargest<<"\n";
}

// Approach 2(Better): Firstly find the largest, then find element just smaller than greatest(Second largest).
// TC : O(n) (due to two linear traversals, still it is O(2n)), SC : O(1)
void better(vector<int> &arr, int n){
    int largest = INT_MIN, secLargest = INT_MIN;
    for(int i = 0; i < n; ++i){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] > secLargest && arr[i] < largest){
            secLargest = arr[i];
        }
    }

    // To ensure correctness if no second largest is found.
    if (secLargest == INT_MIN)
        cout << -1;
    else
        cout << "Largest:" << largest << " , Second largest: " << secLargest;
    cout << endl;
}

// Approach 3(Optimal approach): Using a single for loop, and applying effective conditions.
// TC : O(n), SC : O(1)
void optimal(vector<int> &arr, int n){
    int largest = INT_MIN, secLargest = INT_MIN;
    for(int i = 0; i < n; ++i){
        if(arr[i] > largest){
            secLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secLargest){
            secLargest = arr[i];
        }
    }
    // To ensure correctness if no second largest is found.
    if (secLargest == INT_MIN)
        cout << -1;
    else
        cout << "Largest:" << largest << " , Second largest: " << secLargest;

    cout << endl;
}

int main(){
    vector<int> arr = {1,45,67,-98,100};
    brute(arr, 5);
    better(arr, 5);
    optimal(arr, 5);
    return 0;
}