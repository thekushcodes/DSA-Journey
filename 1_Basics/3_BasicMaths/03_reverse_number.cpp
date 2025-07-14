// 6th June, 2025
// Question: Reverse a number

#include <iostream>
using namespace std;

void reverseNumber(int n){
    int reverse_num = 0;
    while(n>0){
        int last_digit = n%10;
        n = n/ 10;
        reverse_num = (reverse_num * 10) + last_digit;
    }
    cout<<"The reverse number is "<<reverse_num<<endl;;
}

int main(){
    reverseNumber(7789);    
    return 0;
}