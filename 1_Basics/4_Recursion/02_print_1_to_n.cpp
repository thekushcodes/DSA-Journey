// 8th June, 2025
// Question: Print 1 to n, linearly

#include <iostream>
using namespace std;

void f(int i, int n){
    if(i>n){
        return;
    }
    cout<<i<<"\n";
    f(i+1, n);
}

int main(){
    f(1, 10);
    return 0;
}