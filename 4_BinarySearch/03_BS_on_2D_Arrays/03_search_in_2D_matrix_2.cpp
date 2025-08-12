// 5th August, 2025
// Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order.
// But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
// You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Brute force : Linear search in the 2D array. TC : O(N * M).
// Better approach is to use binary search in each row. We will traverse in the matrix by each row, and then apply BS on each row. TC : O(N * log M) {where, N-> Rows, M-> Columns}.

// TC : O(N + M), SC : O(1)
// Although this approach doesn't seems to be using binary search in traditional method but it definitely uses it's core principle of elimination.
pair<int, int> optimal(vector<vector<int> > &arr, int target){
    int rows = arr.size();
    int columns = arr[0].size();

    int row = 0, column = columns - 1;
    while(row < rows && columns >= 0){
        if(arr[row][column] == target) return {row, column};
        else if(arr[row][column] < target) row++;
        else column--;
    }
    return {-1,-1};
}

int main(){
    vector<vector<int> > arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},{3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
    int target = 10;

    pair<int, int> x = optimal(arr, target);
    cout << x.first << " " << x.second << endl;

    return 0;
}