// 16th July, 2025
// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// TC : O((N*M)*(N + M)) + O(N*M), SC : O(1)
void markRow(vector<vector<int> > &matrix, int n, int m, int i){
    for(int j = 0; j < m; j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int> > &matrix, int n, int m, int j){
    for(int i = 0; i < n; i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

// In this brute solution, we will mark all the spaces where 0 has to be filled with -1 (Remember not the original zeros, just the places where 0 has to be filled). Then in another traversal mark all -1 as 0s.
vector<vector<int> > brute(vector<vector<int> > &matrix, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                markRow(matrix, n, n, i);
                markCol(matrix, n, m, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// Better solution
// TC :  O(2*(N*M)), SC : O(N) + O(M)
// In the better solution, we will create an extra row and column (initially set values of them as 1) and if there is any 0 in that row or column we will mark the row and column as 0. In another traversal, we will start filling 0s where needed as per watching if there is a 0 in that row or column that we made.
vector<vector<int> > better(vector<vector<int> > &matrix, int n, int m){
    int row [n] = {0};
    int col [m] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// Optimal solution
// TC : O(2*(N*M)), SC : O(1)
// This is kinda similar to the better solution, but this time we will use the first row and first column of the matrix itself to mark.
vector<vector<int> > optimal(vector<vector<int> > &matrix, int n, int m){
    int col0 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j != 0){
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }
    // (1,1) to (n-1, m-1)
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j = 0; j < m; j++){
            matrix[0][j] = 0;
        }
    }
    if(col0 = 0){
        for(int i = 0; i < n; i++){
            matrix[i][0] = 0;
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();

    // Below are the functions:

    // vector<vector<int> > result1 = brute(matrix, n, m);
    // for(auto it1 : result1){
    //     for(auto it2 : it1){
    //         cout << it2 << " ";
    //     }
    // }

    // vector<vector<int> > result2 = better(matrix, n, m);
    // for(auto it1 : result2){
    //     for(auto it2 : it1){
    //         cout << it2 << " ";
    //     }
    // }

    // vector<vector<int> > result3 = optimal(matrix, n, m);
    // for(auto it1 : result3){
    //     for(auto it2 : it1){
    //         cout << it2 << " ";
    //     }
    // }

    return 0;
}