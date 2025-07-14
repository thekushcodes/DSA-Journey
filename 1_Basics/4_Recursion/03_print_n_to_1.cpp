// 8th June, 2025
// Question: Print n to 1, linearly

#include <iostream>
using namespace std;

void f(int i, int n){
    if(i < 1){
        return;
    }
    cout<<i<<"\n";
    f(i-1, n);
}

int main(){
    f(10, 1);
    
    return 0;
}