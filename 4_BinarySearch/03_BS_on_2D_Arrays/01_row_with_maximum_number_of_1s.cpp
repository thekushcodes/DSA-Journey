// 4th July, 2025
// Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
// Your task is to find the index of the row with the maximum number of ones.
// Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(N * M), SC : O(1)
int brute(vector<vector<int> > &arr){
    int rows = arr.size();
    int columns = arr[0].size();

    int maxCnt = 0;
    for(int i = 0; i < rows; i++){
        int countOnes = 0;
        for(int j = 0; j < columns; j++){
            // We are using the fact that the array is sorted, so as soon as we find the first occurence of 1 we can get the number of ones by -> (total columns - current column). Alternatively, we can do the simple count(linear search) to make it look more brute force approach :>
            if(arr[i][j] == 1){
                countOnes = columns - j;
            }
            if(countOnes > maxCnt){
                // If we need to return the index of row with max ones, we can set index = i in the below condition.
                maxCnt = countOnes;
            }
        }
    }
    return maxCnt;
}

// TC : O(N * log M), SC : O(1)
int optimal(vector<vector<int> > &arr){
    int rows = arr.size();
    int columns = arr[0].size();
    int maxCnt = 0;
    for(int i = 0; i < rows; i++){
        int cnt = 0;
        int low = 0, high = columns - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[i][mid] == 1){
                // Alternatively, we could use methods like lower_bound(1), upper_bound(0), or a custom function to find the first occurrence of 1 in the row.
                cnt = columns - mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        maxCnt = max(cnt, maxCnt);
    }
    return maxCnt;
}

int main(){
    vector<vector<int> > arr = {{0,0,1,1,1}, {0,0,0,0,0}, {0,1,1,1,1}, {0,0,0,0,0}, {0,1,1,1,1}};

    int x = brute(arr);
    cout << x << endl;

    int y = optimal(arr);
    cout << y << endl;

    return 0;
}