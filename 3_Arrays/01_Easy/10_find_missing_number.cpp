// 30th June, 2025
// Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

#include <iostream>
#include <vector>
using namespace std;

// TC : O(n^2), SC : O(1)
int brute(vector<int> &arr, int n){
    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= n; i++) {
        // flag variable to check
        //if an element exists
        int flag = 0;
        //Search the element using linear search:
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing, i.e. flag == 0:
        if (flag == 0) return i;
    }
    // The following line will never execute. It is just to avoid warnings.
    return -1;
}

// TC : O(2*n), SC : O(n)
int better(vector<int> &arr, int n){
    // Using a hash array, we will store the frequency of the elements of the main array. Size of hash array = n + 1.
    int temp[n+1] = {0};
    for(int i = 0; i < n-1; i++){
        temp[arr[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(temp[i] == 0){
            return i;
        }
    }
    return -1;
}

// TC : O(n), SC : O(1)
int optimal1(vector<int> &arr, int n){
    // Here, we will use the property of sum, i.e., sum of n natural numbers - sum of all elements of given array = missing number
    int sum = (n*(n+1))/2;
    int ogSum = 0;
    for(int i = 0; i < n-1; i++){
        ogSum = ogSum + arr[i];
    }
    return sum - ogSum;
}

// TC : O(n), SC : O(1)
int optimal2(vector<int> &arr, int n){
    // XOR approach:
    // Two important properties of XOR are the following:
    // Property 1--> XOR of two same numbers is always 0 i.e. a ^ a = 0.
    // Property 2--> XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.

    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < n-1; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ n; //XOR up to [1...N], since loop didn't run till n.
    return (xor1 ^ xor2);

}

int main(){
    vector<int> arr = {1,2,4,5};
    int n = arr.size();

    // All the functions are below:

    // int x = brute(arr, n);
    // cout<<x<<endl;

    // int y = better(arr, n);
    // cout<<y<<endl;

    // int z = optimal1(arr, n);
    // cout<<z<<endl;

    // int z1 = optimal2(arr, n);
    // cout<<z1<<endl;
    return 0;
}