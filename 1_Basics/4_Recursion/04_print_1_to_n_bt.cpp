// 8th June, 2025
// Question: Print 1 to n, by backtracking

#include <iostream>
using namespace std;

void f(int i, int n){
    if(i < 1) return;
    f(i-1, n);
    cout<<i<<"\n";
}

int main(){
    f(10, 1);
    return 0;
}