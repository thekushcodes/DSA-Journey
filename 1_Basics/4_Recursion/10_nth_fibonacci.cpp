// 9th June, 2025
// Question: Find nth Fibonacci number
// Concept: f(n) = f(n-1) + f(n-2)
// TC : O(2^n)

#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    int last = fibonacci(n-1);
    int sec_last = fibonacci(n-2);
    return (last + sec_last);
}

int main(){
    cout<<fibonacci(6);
    return 0;
}