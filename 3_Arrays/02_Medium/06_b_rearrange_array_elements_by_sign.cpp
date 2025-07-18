// 9th July, 2025
// Variety-2:
// Problem Statement: There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(2*N), SC : O(N)
vector<int> rearrangeBySign(vector<int> &arr, int n){
    vector<int> pos, neg;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    // If positives < negatives
    if(pos.size() < neg.size()){
        for(int i = 0; i < pos.size(); i++){
            arr[i*2] = pos[i];
            arr[i*2+1] = neg[i];
        }

        // Fill the remaining indices
        int index = pos.size()*2;
        for(int i = 0; i < neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
    // If negatives < positives
    else{
        for(int i = 0; i < neg.size(); i++){
            arr[i*2] = pos[i];
            arr[i*2+1] = neg[i];
        }

        // Fill the remaining indices
        int index = neg.size()*2;
        for(int i = neg.size(); i < pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {1,2,-4,-5};
    int n = arr.size();

    vector<int> result = rearrangeBySign(arr, n);
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}