// 9th June, 2025
// Question: Sum of first n numbers

#include <iostream>
using namespace std;

// f1 is Parameterised way (Using cout directly)
void f1(int i, int sum){
    if(i<1){
        cout<<sum<<"\n";
        return;
    }
    f1(i-1, sum+i);
}

// f2 is Functional way (Using return)
int f2(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n + f2(n-1);
    }
}

int main(){
    f1(10, 0);
    cout<<f2(10)<<"\n";
    
    return 0;
}