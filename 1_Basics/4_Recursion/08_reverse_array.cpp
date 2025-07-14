// 9th June, 2025
// Question: Reverse an array

#include <iostream>
using namespace std;

// Using two variables/pointers
void f1(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    // Swap a[l], a[r]
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

    f1(arr, l+1, r-1); // Recursive call
}

// Using single variable/pointer
void f2(int arr[], int i, int n){
    if(i > n/2) return;
    // Swap a[i], a[n-1-i]
    int temp = arr[i];
    arr[i] = arr[n-1-i];
    arr[n-1-i] = temp;

    f2(arr, i + 1, n); // Recursive call
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    f1(arr, 0, n-1); // Reverses the array
    f2(arr, 0, n); // Reverses the array again, restored to original

    // Print the array
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}