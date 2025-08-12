// 6th August. 2025
// Problem Statement: You are given an m x n matrix of integers, where no two adjacent elements (top, bottom, left, right) are equal. Your task is to find any one peak element in the matrix and return its coordinates (row, column).
// Imagine the matrix is surrounded by a boundary of -1s, and comparisons are made accordingly. It is guaranteed that at least one peak exists.
// A peak element is defined as an element that is strictly greater than all of its adjacent elements in the four directions: Top, bottom, left and right.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// TC : O(4 * N * M) {4 because we check in all directions each time} {where, N-> Rows, M-> Colummns}, SC : O(1)
pair<int, int> brute(vector<vector<int> > &mat){
    int rows = mat.size();
    int columns = mat[0].size();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            int up = (i > 0) ? mat[i-1][j] : -1; // The ? : in the code is the ternary operator in C++. It’s basically a compact way to write an if–else expression.
            // The above line means: If (i > 0), up = mat[i-1][j], else up = -1.
            int down = (i < rows-1) ? mat[i+1][j] : -1;
            int left = (j > 0) ? mat[i][j-1] : -1;
            int right = (j < columns-1) ? mat[i][j+1] : -1;
            if(mat[i][j] > up && mat[i][j] > down && mat[i][j] > left && mat[i][j] > right){
                return {i,j};
            }
        }
    }
    return {-1, -1};
}

// TC : O(Columns - 1), SC : O(1)
int maxEle(vector<vector<int> > &mat, int rows, int columns, int mid){
    int maxElement = -1;
    int index = -1;
    for(int i = 0; i < columns; i++){
        if(mat[i][mid] > maxElement){
            maxElement = mat[i][mid];
            index = i;
        }
    }
    return index;
}

// TC : O(N log M) {where, N-> Rows, M-> Colummns}, SC : O(1)
pair<int, int> optimal(vector<vector<int> > &mat){
    int rows = mat.size();
    int columns = mat[0].size();

    int low = 0, high = columns - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        int maxInRow = maxEle(mat, rows, columns, mid);
        int left = (mid-1 >= 0) ? mat[maxInRow][mid-1] : -1;
        int right = (mid+1 < columns) ? mat[maxInRow][mid+1] : -1;

        if(mat[maxInRow][mid] > left && mat[maxInRow][mid] > right){
            return {maxInRow, mid};
        }
        else if(mat[maxInRow][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main(){
    vector<vector<int> > mat = {{10, 8, 10, 10}, {14, 13, 12, 11}, {15, 9, 11, 21}, {16, 17, 19, 20}};

    pair<int, int> x = brute(mat);
    cout << x.first << " " << x.second << endl;

    pair<int, int> y = optimal(mat);
    cout << y.first << " " << y.second << endl;

    return 0;
}