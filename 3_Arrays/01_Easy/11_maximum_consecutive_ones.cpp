// 30th June, 2025
// Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

#include <iostream>
using namespace std;

// TC : O(n), SC : O(1)
int maxConsecutives(int arr[], int n){
    int count = 0;
    int max = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            count++;
            if(count > max){
                max = count;
            }
        }
        else if(arr[i] != arr[i+1]){
            count = 0;
        }
    }
    return max;
    
}

int main() {
	int arr[8] = {1,1,0,1,1,1,0,1};
	int x = maxConsecutives(arr, 8);
    cout<<x;
}