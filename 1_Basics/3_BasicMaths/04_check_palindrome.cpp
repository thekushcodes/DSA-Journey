// 6th June, 2025
// Question: Check if a given integer is palindrome

#include <iostream>
using namespace std;

void checkPalindrome(int n){
    int num = n;
    int reverseNumber = 0;
    while(n>0){
        int lastDigit = n%10;
        n = n / 10;
        reverseNumber = (reverseNumber * 10) + lastDigit;        
    }
    if(num == reverseNumber){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not palindrome";
    }
}

int main(){
    checkPalindrome(1221);    
    return 0;
}