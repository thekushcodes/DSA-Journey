// 8th June, 2025
// Question: Print n to 1, by backtracking

#include <iostream>
using namespace std;

void f(int i, int n){
    if(i > n){
        return;
    }
    f(i+1, n);
    cout<<i<<"\n";
}

int main(){
    f(1, 10);    
    return 0;
}