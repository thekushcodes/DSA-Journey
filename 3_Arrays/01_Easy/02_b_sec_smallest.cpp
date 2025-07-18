// 20th June, 2025
// Problem Statement: Given an array, find the second smallest element in the array. Print ‘-1’ in the event that second smallest doesn’t exist.

#include <iostream>
#include <vector>
#include <algorithm> // To use sort()
#include <climits> // To use min, max
using namespace std;

// Brute force - Only works if no duplicates.
// Approach: Sort the given vector, then print the 2nd element.
// TC : O(n * log n) (To sort), SC : O(1)
void brute(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    int secSmallest = arr[1];
    cout << "Second smallest: " << secSmallest << "\n";
}

// Approach 2(Better): Firstly find the smallest and largest, then find element just greater than smallest(Second smallest) and just smaller than greatest(Second largest).
// TC : O(n) (due to two linear traversals, still it is O(2n)), SC : O(1)
void better(vector<int> &arr, int n){
    int smallest = INT_MAX, secSmallest = INT_MAX;
    for(int i = 0; i < n; ++i){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] < secSmallest && arr[i] > smallest){
            secSmallest = arr[i];
        }
    }

    // To ensure correctness if no second smallest is found.
    if (secSmallest == INT_MAX)
        cout << -1;
    else
        cout << "Smallest:" << smallest << " , Second smallest: " << secSmallest;
    cout << endl;
}

// Approach 3(Optimal approach): Using a single for loop, and applying effective conditions.
// TC : O(n), SC : O(1)
void optimal(vector<int> &arr, int n){
    int smallest = INT_MAX, secSmallest = INT_MAX;
    for(int i = 0; i < n; ++i){
        if(arr[i] < smallest){
            secSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < secSmallest){
            secSmallest = arr[i];
        }
    }
    // To ensure correctness if no second smallest is found.
    if (secSmallest == INT_MAX)
        cout << -1;
    else
        cout << "Smallest:" << smallest << " , Second smallest: " << secSmallest;
    cout << endl;
}

int main(){
    vector<int> arr = {1,45,67,-98,100};
    brute(arr, 5);
    better(arr, 5);
    optimal(arr, 5);
    return 0;
}