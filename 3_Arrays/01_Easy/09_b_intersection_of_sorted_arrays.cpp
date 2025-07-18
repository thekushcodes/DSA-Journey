// 2nd July, 2025
// Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the intersection of two sorted arrays.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(N1 * N2) SC : O(N2) (For the visited boolean)
vector<int> brute(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size(), n2 = arr2.size();
    vector<int> result;
    vector<bool> visited(n2, false);  // To mark used elements in arr2

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(arr1[i] == arr2[j] && !(visited[j])){
                result.push_back(arr1[i]);
                visited[j] = true;
                break;;
            }
        }
    }
    return result;
}

// TC : O(N1 + N2), SC : O(min(N1, N2))
vector<int> optimal(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i = 0, j = 0;
    vector<int> result;
    while(i < n1 && j < n2){
        if(arr1[i] == arr2[j]){
            result.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return result;
}

int main(){
    vector<int> arr1 = {1,2,4,6,8};
    vector<int> arr2 = {1,4,8};

    vector<int> result1 = brute(arr1, arr2);
    for(auto it : result1){
        cout << it << " ";
    }
    cout << endl;

    vector<int> result2 = optimal(arr1, arr2);
    for(auto it : result2){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}