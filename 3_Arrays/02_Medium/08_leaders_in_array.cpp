// 11th July, 2025
// Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N^2), SC : O(N)
vector<int> brute(vector<int> &arr){
    int n = arr.size();
    vector<int> leaderElement;
    
    for(int i = 0; i < n; i++){
        bool leader = true;;
        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            leaderElement.push_back(arr[i]);
        }
    }
    return leaderElement;

}

// TC : O(N), SC : O(N)
vector<int> optimal(vector<int> &arr){
    int n = arr.size();
    if (n == 0) return {};

    vector<int> leaderElement;
    int maxFromRight = arr[n-1];
    leaderElement.push_back(maxFromRight); // Last element is always a leader.

    for(int i = n-2; i >= 0; i--){
        if(arr[i] > maxFromRight){
            maxFromRight = arr[i];
            leaderElement.push_back(arr[i]);
        }
    }
    // All the leader elements will be stored in the leaderElement vector in reverse order(back to front), so if you want to return original order just reverse the vector.
    return leaderElement;
}

int main(){
    vector<int> arr = {1,34,56,2,3};

    // Below are the functions:

    // vector<int> x = brute(arr);
    // for(int i = 0; i < x.size(); i++){
    //     cout << x[i] << " ";
    // }
    // cout << endl;

    // vector<int> y = optimal(arr);
    // for(int i = 0; i < x.size(); i++){
    //     cout << y[i] << " ";
    // }
    // cout << endl;
    return 0;
}