// 17th July, 2025
// Problem Statement: Given a Matrix, print the given matrix in spiral order.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(N * M), SC : O(N * M)
vector<int> optimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> result;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}

int main()
{
    vector<vector<int> > matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    vector<int> arr = optimal(matrix);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}