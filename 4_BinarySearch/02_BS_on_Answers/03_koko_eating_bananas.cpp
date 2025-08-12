// 27th July, 2025
// Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

#include <iostream>
#include <vector>
#include <cmath> // To use ceil()
using namespace std;

// TC : O(N), SC : O(1)
// This function calculates the maximum number of bananas there in the array, i.e., max. element of the array.
int maxBananas(vector<int> &arr){
    int n = arr.size();
    int maxBanana = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxBanana){
            maxBanana = arr[i];
        }
    }
    return maxBanana;
}
// TC : O(N), SC : O(1)
// This function calculates if we are given a rate(hourlyRate), then it returns number of hours required to finish the bananas.
int calculateTotalHours(vector<int> &arr, int hourlyRate){
    int n = arr.size();
    int totalHours = 0;
    for(int i = 0; i < n; i++){
        totalHours += ceil((double)(arr[i]) / (double)(hourlyRate)); // double is a floating-point data type with greater precision
    }
    return totalHours;
}

// TC : O(N * max(arr)), SC : O(1)
int brute(vector<int> &arr, int deadline){
    int n = arr.size();
    int maxBanana = maxBananas(arr);
    for(int i = 1; i < maxBanana; i++){
        int reqTime = calculateTotalHours(arr, i); // Here, i is the hourly rate transferred to the function        
        if(reqTime <= deadline){
            return i;
        }
    }
    return -1;
}

// TC : O(N * log(max(arr))), SC : O(1)
int optimal(vector<int> &arr, int deadline){
    int n = arr.size();
    int maxBanana = maxBananas(arr);
    int low = 1, high = maxBanana;
    while(low <= high){
        int mid = (low + high) / 2;
        int totalHours = calculateTotalHours(arr, mid);
        if(totalHours <= deadline){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low; // Because low was firstly pointing to a not possible element and high was pointing to a possible element. So by the end of BS, this will be reversed, and low will be pointing to the answer. We can also use another variable to store the ans in the above 'if' condition.
}

int main(){
    vector<int> arr = {7, 15, 6, 3};
    int h = 8;

    int hourlyRate1 = brute(arr, h);
    cout << hourlyRate1 << "\n";

    int hourlyRate2 = optimal(arr, h);
    cout << hourlyRate2 << "\n";
    
    cout << endl;

    return 0;
}