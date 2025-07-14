// 6th June, 2025
// Question: Find GCD(Greatest Commom Divisor) / HCF(Highest Common Factor)

#include <iostream>
using namespace std;

// TC : O(min(n1, n2))
void gcd(int n1, int n2){
    int gcd = 1;
    for(int i = 1; i <= n1; i++){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
        }
    }
    cout<<gcd;
    cout<<endl;
}

// TC : O(min(n1, n2)) in the worst case, if GCD is 1.
void gcd2(int n1, int n2){
    for(int i = min(n1, n2); i >= 1; i--){
        if(n1 % i == 0 && n2 % i == 0){
            cout<<i;
            break; // Found GCD, exit loop
        }
    }
    cout<<endl;
}

// Using Euclidean Algorithm
// TC : O(log(min(a,b)), with base phi)
void gcd3(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    if (a == 0){
       cout<<b; // GCD = b
    }
    else{
        cout<<a; // GCD = a
        }
    cout<<endl;
}

int main(){
    gcd(12,20);
    gcd2(12,20);
    gcd3(12,20);
    return 0;
}