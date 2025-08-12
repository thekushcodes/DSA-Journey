// 4th July, 2025
// Problem Statement: Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

// Pre-requisite : Median of two sorted arrays (Previous question). Almost same as previous question.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N1 + N2), SC : O(N1 + N2)
int brute(vector<int> &arr1, vector<int> arr2, int k){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i = 0, j = 0;
    vector<int> arr3;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr3.push_back(arr1[i++]);
        }
        else{
            arr3.push_back(arr2[j++]);
        }
    }

    return arr3[k-1];
}

// TC : O(N1 + N2), SC : O(1)
int better(vector<int> &arr1, vector<int> &arr2, int k){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int kthElement = -1;;
    int cnt = 0;

    int i = 0, j = 0;

    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            if(cnt == k-1) kthElement = arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == k-1) kthElement = arr2[j];
            cnt++;
            j++;
        }
    }
    while(i < n1){
        if(cnt == k-1) kthElement = arr1[i];
        cnt++;
        i++;
    }
    while(j < n2){
        if(cnt == k-1) kthElement = arr2[j];
        cnt++;
        j++;
    }

    return kthElement;
}

// TC : O(log min(N1, N2)), SC : O(1)
int optimal(vector<int> &arr1, vector<int> &arr2, int k){
    int n1 = arr1.size();
    int n2 = arr2.size();

    if(n1 > n2) return optimal(arr2, arr1, k);

    int left = k; // Length of the left half.
    int low = max(0, k-n2), high = min(k, n1);
    while(low <= high){
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = arr1[mid1];
        if(mid2 < n2) r2 =  arr2[mid2];
        if(mid1-1 >= 0) l1 = arr1[mid1 - 1];
        if(mid2-1 >= 0) l2 = arr2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return -1;
}

int main(){
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 4;

    int x = brute(arr1, arr2, k);
    cout << x << endl;

    int y = better(arr1, arr2, k);
    cout << y << endl;

    int z = optimal(arr1, arr2, k);
    cout << z << endl;

    return 0;
}