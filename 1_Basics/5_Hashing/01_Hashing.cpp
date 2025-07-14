// 10th June, 2025
// Hashing (Integer and character hashing)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    // Input elements in array
    int n;
    cout<<"Enter number of elements in array: ";
    cin >> n;
    cout<<"Enter the elements"<<endl;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // Pre-computation
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
        // For character hashing with a string s, use: mpp[s[i]]++;. This will store like- a->4, b->8...
    }

    // Fetch
    for (auto &pair : mpp) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}