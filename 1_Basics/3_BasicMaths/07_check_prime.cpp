// 6th June, 2025
// Question: Check a number is prime or not

#include <iostream>
using namespace std;

// Brute force (TC : O(n))
void checkPrime(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            count++;
        }
    }
    if (count == 2) cout<<"Prime";
    else cout<<"Not prime";
    cout<<endl;
}

// Optimal (TC : O(n^1/2)) (In the previous file)
void checkPrime2(int n){
    int count = 0;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            count++;
        }
        if((n/i) != i){
            count++;
        }
    }
    if (count == 2) cout<<"Prime";
    else cout<<"Not prime";
    cout<<endl;
}

int main(){
    checkPrime(7);
    checkPrime2(12);
    return 0;
}