// 7th August, 2025
// Problem Statement: Given a row-wise sorted matrix of size M x N, where M is no. of rows and N is no. of columns, find the median in the given matrix.
// Note: M x N is odd (Number of elements is odd).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int brute(vector<vector<int> > &mat){
    int rows = mat.size();
    int columns = mat[0].size();

    // Insert all elemets of 2D array, into a 1D array.
    vector<int> arr;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            arr.push_back(mat[i][j]);
        }
    }

    // Sort the 1D array:
    sort(arr.begin(), arr.end());

    // Return the mid-element, which is the median.
    return arr[(rows*columns) / 2];
}

// Helper function for optimal approach. This is the usual Upper Bound function.
// TC : O(log M) {where, M is number of columns in matrix}, SC : O(1)
int upperBound(vector<int> &arr, int x, int n){
    int ans = n;
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// TC : O(N) {N-> Number of rows in matrix}, SC : O(1)
int smallerEqualElements(vector<vector<int> > &mat, int n, int m, int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += upperBound(mat[i], x, m);
    }
    return cnt;
}

// TC : O(log (10^9) * (M * log N)) {log(10^9) because- low can be min. as 0, and high as 10^9}, SC : O(1)
int optimal(vector<vector<int> > &mat){
    int rows = mat.size();
    int columns = mat[0].size();

    int low = INT_MAX, high = INT_MIN;
    // Set low = min(mat) and high = max(mat): (Since matrix is sorted row-wise, we only need to check in first and last column).
    for(int i = 0; i < rows; i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][columns - 1]);
    }

    int req = (rows*columns) / 2;
    while(low <= high){
        int mid = (low + high) / 2;
        int smallerEqual = smallerEqualElements(mat, rows, columns, mid);
        if(smallerEqual <= req){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    vector<vector<int> > mat = {{1, 2, 3, 4, 5}, {8, 9, 11, 12, 13}, {21, 23, 25, 27, 29}};

    int x = brute(mat);
    cout << x << endl;

    int y = optimal(mat);
    cout << y << endl;

    return 0;
}