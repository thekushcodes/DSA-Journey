// 25th July, 2025
// Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

#include <iostream>
using namespace std;

// Brute force solution(By linear method):
// Binary exponentiation / Power exponentiation (Explained in later lectures) -> It simply calculates a^n in (log n) TC.
// TC : O(log exp, base 2), SC : O(1)
long long expFunc(int b, int exp){
    long long base = b;
    long long ans = 1;
    while(exp > 0){
        // If exponential is odd:
        if(exp % 2){
            exp--;
            ans = ans * base;
        }
        // If exponential is even:
        else{
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}

// TC: O(N × log M), where N = num and M = exponent(m), SC: O(1)
int brute(int num, int m){
    for(int i = 0; i <= num; i++){
        long long val = expFunc(i, m);

        if(val == num * 1ll) return i; // This checks if (val == num), that '1ll' simply converts num to long long to tackle overflow/bugs.
        else if(val > num * 1ll) break;
    }
    return -1;
}

// Optimal solution(by binary search):

// TC : O(exp), SC : O(1)
int func(int mid, int num, int exp){
    // This function returns: 1 if ans==m, 2 if ans > m, 0 if ans < m
    long long ans = 1;
    for(int i = 1; i <= exp; i++){
        ans = ans * mid;
        if(ans > num) return 2;
    }
    if(ans == num) return 1;
    return 0;
}

// TC : O(n * log num, base 2) where - n is exponent, num is input number, SC : O(1)
int optimal(int num, int n){
    int low = 1, high = num;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int midN = func(mid, num, n);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid + 1;
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int num = 27, n = 3;
    int x = brute(num, n);
    cout << x << "\n";

    int y = optimal(num, n);
    cout << y << "\n";

    cout << endl;

    return 0;
}