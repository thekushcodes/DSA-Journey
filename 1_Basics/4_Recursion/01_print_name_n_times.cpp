// 8th June, 2025
// Question: Print name 'n' times
// TC- O(n), SC- O(n)->In stack space(recursive trees)

#include <iostream>
using namespace std;

void f(int i, int n){
    if(i > n){
        return;
    }
    cout<<"Anurag"<<endl;
    f(i+1, n);
}

int main(){
    int n = 5;
    f(1, n);
    return 0;
}