// 25th July, 2025
// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

#include <iostream>
#include <cmath> // To use sqrt()
using namespace std;

// TC : O(N), SC : O(1)
// Linear search till square of number exceeds the input number
int brute(int n){
    int ans = 1;
    for(int i = 0; i <= n; i++){
        if(i*i <= n){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

// Using the in-built function in C++
int optimal1(int n){
    int ans = sqrt(n);
    return ans;
}

// TC : O(log N, base 2), SC : O(1)
// Using binary search on answers
int optimal2(int n){
    int low = 1, high = n;
    int ans = 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid*mid <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int num = 28;

    int x = brute(num);
    cout << x << "\n";

    int y = optimal1(num);
    cout << y << "\n";

    int z = optimal2(num);
    cout << z << "\n";

    cout << endl;

    return 0;
}