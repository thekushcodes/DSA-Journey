// 5th July, 2025
// Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

#include <iostream>
#include <vector>
using namespace std;

// This brute is better than simple linear search, because for linear search TC would be O(Rows * Columns).
// TC : O(Rows) + O(Columns) {Here, column is just a single column}, SC : O(1)
bool brute(vector<vector<int> > &arr, int target){
    int rows = arr.size();
    int columns = arr[0].size();
    for(int i = 0; i < rows; i++){
        // Since the array is sorted, therefore before traversing entire row, we just check if target lies between first and last element of the row.
        if(arr[i][0] <= target && target <= arr[i][columns-1]){
            for(int j = 0; j < columns; j++){
                if(arr[i][j] == target) return true;
            }
        }
    }
    return false;
}


// This is the simple binary search, used as a helper function in better approach below:
// TC : O(log N), SC : O(1)
bool binarySearch(vector<int> &arr, int target){
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return true;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// TC : O(Rows + log (Columns)), SC : O(1)
bool better(vector<vector<int> > &arr, int target){
    int rows = arr.size();
    int columns = arr[0].size();

    int low = 0, high = columns - 1;
    for(int i = 0; i < rows; i++){
        if(arr[i][0] <= target && target <= arr[i][columns - 1]){
            while(low <= high){
                return binarySearch(arr[i], target);
            }
        }
    }
    return false;
}

// In this optimal approach, we are trying to assume the 2D array to be a flat 1D arrar, so the mid gives normal index(of 1D array) and we can convert it to arr[Row][Column], by Row = mid / total columns, and Column = mid % total columns.
// TC O(log (Rows * Columns)), SC : O(1)
bool optimal(vector<vector<int> > &arr, int target){
    int rows = arr.size();
    int columns = arr[0].size();

    int low = 0, high = (rows*columns) - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        int row = mid / columns;
        int column = mid % columns;

        if(arr[row][column] == target) return true;
        else if(arr[row][column] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main(){
    vector<vector<int> > arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target = 8;

    bool x = brute(arr, target);
    cout << x << endl;

    bool y = better(arr, target);
    cout << y << endl;

    bool z = optimal(arr, target);
    cout << z << endl;

    return 0;
}