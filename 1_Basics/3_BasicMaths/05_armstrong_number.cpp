// 6th June, 2025
// Question: Check if a given integer is an Armstrong number
// Concept: Sum of cube of each digit is equal to number itself.
// -->> 3^3 + 7^3 + 1^3 = 371

#include <iostream>
using namespace std;

void armstrongNumber(int n){
    int num = n;
    int armstrong = 0;
    while (n>0)
    {
        int lastDigit = n%10;
        armstrong = armstrong + (lastDigit*lastDigit*lastDigit);
        n = n / 10;
    }
    if (num == armstrong)
    {
        cout<<"It is an armstrong number"<<endl;
    }
    else{
        cout<<"It is not an armstrong number"<<endl;
    }
}

int main(){
    armstrongNumber(371);
    return 0;
}