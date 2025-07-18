// 16th July, 2025
// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N*N), SC : O(N*N)
vector<vector<int> > brute(vector<vector<int> > &matrix, int n){
    // Take dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.
    vector<vector<int> > arr(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[j][n-1-i] = matrix[i][j];
        }
    }
    return arr;
}

// TC :  O(N*N) + O(N*N), SC : O(1)
vector<vector<int> > optimal(vector<vector<int> > &matrix, int n){
    // Transposing the matrix (rows->columns)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row of the matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    return matrix;
}

int main(){
    vector<vector<int> > matrix =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = matrix.size();

    // Below are the functions:

    // We are not taking m (i.e., row and column separately because the given matrix will be a square matrix, so n = m)
    vector<vector<int> > result1 = brute(matrix, n);
    for(auto it1 : result1){
        for(auto it2 : it1){
            cout << it2 << " ";
        }
    }

    vector<vector<int> > result2 = optimal(matrix, n);
    for(auto it1 : result2){
        for(auto it2 : it1){
            cout << it2 << " ";
        }
    }
    return 0;
}