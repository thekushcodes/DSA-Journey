// 9th June, 2025
// Question: Factorial of n

#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    cout<<factorial(5)<<"\n";
    return 0;
}