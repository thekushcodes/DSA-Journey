// 9th June, 2025
// Question: Check if string is palindrome
// TC : O(n/2), SC : O(n/2)

#include <iostream>
#include <string>
using namespace std;

bool f(int i, string s, int n){
    if(i >= n/2){
        return true;
    }
    if(s[i] != s[n-1-i]){
        return false;
    }
    return f(i+1, s, n);
}

int main(){
    string s = "AABBAA";
    int n = s.length();
    cout<<f(0, s, n);
    return 0;
}