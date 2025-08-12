// 3rd July, 2025
// Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N1 + N2), SC : O(N1 + N2)
double brute(vector<int> &arr1, vector<int> &arr2){
    vector<int> arr3;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr3.push_back(arr1[i++]);
        }
        else{
            arr3.push_back(arr2[j++]);
        }
    }
    while(i < n1) arr3.push_back(arr1[i++]);
    while(j < n2) arr3.push_back(arr2[j++]);

    int n3 = arr3.size();
    if(n3 % 2 == 1){
        return (double)arr3[n3/2];
    }
    return ((double)arr3[n3/2 - 1] + (double)arr3[n3/2]) / 2.0;
}

// TC : O(N1 + N2), SC : O(1)
double better(vector<int> &arr1, vector<int> &arr2){
    // This time, instead of using a separate array to merge the two arrays, we will use a counter to keep track of the index of the third HYPOTHETICAL array.
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int ind1El = -1, ind2El = -1;
    int cnt = 0, i = 0, j = 0;
    while(i < n1 &&  j < n2){
        if(arr1[i] < arr2[j]){
            if(cnt == ind1) ind1El = arr1[i];
            if(cnt == ind2) ind2El = arr1[i];
            cnt++;
            i++;
            
        }
        else{
            if(cnt == ind1) ind1El = arr2[j];
            if(cnt == ind2) ind2El = arr2[j];
            cnt++;
            j++;
        }
    }
    while(i < n1){
        if(cnt == ind1) ind1El = arr1[i];
        if(cnt == ind2) ind2El = arr1[i];
        cnt++;
        i++;
    }
    while(j < n2){
        if(cnt == ind1) ind1El = arr2[j];
        if(cnt == ind2) ind2El = arr2[j];
        cnt++;
        j++;
    }

    if(n % 2 == 1) return (double)(ind2El);
    return (double)((double)(ind1El + ind2El) / 2.0);
}

// TC : O(log mid(N1, N2)), SC : O(1)
double optimal(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size(), n2 = arr2.size();
    // If n1 is bigger swap the arrays:
    if(n1 > n2) optimal(arr2, arr1);

    int n = n1+n2;

    int left = (n1 + n2 + 1) / 2;
    int low = 0, high = n1;
    while(low <= high){
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = arr1[mid1];
        if(mid1 < n2) r2 = arr2[mid2];
        if (mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];

        if(l1 <= r1 && l2 <= r2){
            if(n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return -1;
}

int main(){
    vector<int> arr1 = {1,4,7,10,12};
    vector<int> arr2 = {2,3,6,15};

    double x = brute(arr1, arr2);
    cout << x << endl;

    double y = better(arr1, arr2);
    cout << y << endl;

    double z = optimal(arr1, arr2);
    cout << z << endl;

    return 0;
}