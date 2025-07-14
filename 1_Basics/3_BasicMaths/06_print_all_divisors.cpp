// 6th June, 2025
// Question: Print all divisors

#include <iostream>
#include <cmath> // To use sqrt()
using namespace std;

// Brute force (TC : O(n))
void checkDivisors(int n){
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            cout<<i<<" ";
        }
    }
}

// Optimal (TC : O(n^1/2))
void checkDivisors2(int n){
    for(int i = 1; i <= sqrt(n); i++){
        // Instead of sqrt(n), we can do i*i <= n, this will not require extra function call.
        if(n%i == 0){
            cout<<i<<" "; // Gives smaller factor
        }
        if((n/i) != i){
            cout<<(n/i)<<" "; // Gives bigger factor
        }
    }
}

int main(){
    checkDivisors(48);
    checkDivisors2(48);
    
    return 0;
}