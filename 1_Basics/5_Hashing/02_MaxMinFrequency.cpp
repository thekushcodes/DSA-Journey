// 20th June, 2025
// Question: Find the maximum and minimum occuring elements along with their frequency.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
	int arr[] = {11,2,34,11,2,11};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	unordered_map<int, int> freq;
	for(int i = 0; i < n; ++i){
	    freq[arr[i]]++; // This will iterate through array and add elements, frequencies in the Hashmap
	}
    int maxFreq = INT_MIN;
    int minFreq = INT_MAX;
    int maxElem, minElem;
    for(auto it : freq){
        if(it.second > maxFreq){
            maxFreq = it.second;
            maxElem = it.first;
        }
        if(it.second < minFreq){
            minFreq = it.second;
            minElem = it.first;
        }
    }
    cout<<"Element "<<minElem<<" -->> Lowest frequency "<<minFreq<<endl;
    cout<<"Element "<<maxElem<<" -->> Highest frequency "<<maxFreq<<endl;
	return 0;
}