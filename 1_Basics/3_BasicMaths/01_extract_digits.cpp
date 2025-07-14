// 6th June, 2025
// Question: Extract digits

#include <iostream>
using namespace std;

void extractDigits(int n){
    cout<<"Digits are:\n";
    for (int i = 0; n > 0 ; i++)
    {
        int last_digit = n%10;
        cout<<last_digit<<"\n";
        n=n/10;
    }
}

int main(){
    extractDigits(7789);
    return 0;
}