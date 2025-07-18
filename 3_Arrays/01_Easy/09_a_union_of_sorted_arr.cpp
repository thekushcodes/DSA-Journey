// 23rd June, 2025
// Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// TC : O(m + n log(m+n)), SC : O(m + n)
vector<int> brute(vector<int> arr1, vector<int> arr2, int n1, int n2){
    set<int> sett;
    vector<int> temp;
    for(int i = 0; i < n1; i++){
        sett.insert(arr1[i]);
    }
    for(int i = 0; i < n2; i++){
        sett.insert(arr2[i]);
    }
    for(auto it = sett.begin(); it != sett.end(); it++){
        temp.push_back(*it);
    }
    return temp;
}

// TC : O(n1 + n2)-> In worst-case, if no common elements
// SC : O(n1 + n2)-> If space taken by union list is considered, else-> O(1)
vector<int> optimal(vector<int> arr1, vector<int> arr2, int n1, int n2){
    int i = 0, j = 0;
    vector<int> temp;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            if(temp.size() == 0 || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
        }
        else if(arr2[j] < arr1[i]){
            if(temp.size() == 0 || temp.back() != arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i < n1){
        if(temp.size() == 0 || temp.back() != arr1[i]){
            temp.push_back(arr1[i]);
        }
        i++;
    }
    while(j < n2){
        if(temp.size() == 0 || temp.back() != arr2[j]){
            temp.push_back(arr2[j]);
        }
        j++;
    }
    return temp;
}

int main(){
    vector<int> arr1 = {1,2,2,3,4,5,6,8};
    int n1 = arr1.size();

    vector<int> arr2 = {2,3,4,4,5,6,7};
    int n2 = arr2.size();

    // vector<int> FindUnion = brute(arr1, arr2, n1, n2);
    vector<int> FindUnion = optimal(arr1, arr2, n1, n2);
    for(int i = 0; i < FindUnion.size(); i++){
        cout<<FindUnion[i]<<" ";
    }
    return 0;
}