// 6th June, 2025
// Question: Count the number of digits

#include <iostream>
#include <cmath> // To use log
using namespace std;

void countDigits1(int n){
    int count = 0;
     if (n == 0) {
        cout << "Number of digits = 1" << endl;
        return;
    }

    n = abs(n); // Handle negative numbers

    while(n>0){
        n=n/10;
        count++;
    }
    cout<<"The number of digits are: "<<count<<endl;
}

void countDigits2(int n){
    if(n==0){
        cout<<"Number of digits = 1"<<endl;;
        return;
    }
    n = abs(n); // Takes absolute value, handle negative numbers.
    int digits = (int)log10(n) + 1;
    cout<<"The number of digits are: "<<digits<<endl;
}

int main(){
    countDigits1(7789);
    countDigits2(7789);
    return 0;
}