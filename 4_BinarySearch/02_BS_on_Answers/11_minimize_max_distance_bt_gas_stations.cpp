// 2nd August, 2025
// Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
// Find the minimum value of ‘dist’.

// Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, it is okay to return 0.654216. Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // To use priority_queue (Stores data in top to bottom manner, with largest one at the top)
#include <utility> // To use pair
using namespace std;

// TC : O(k*N) + O(N), SC : O(N-1)
long double brute(vector<int> &arr, int k){
    int n = arr.size();

    // To store the number of gas stations in between two sections:
    vector<int> howMany(n-1, 0);

    // Pick and place k gas stations
    for(int gasStation = 1; gasStation <= k; gasStation++){
        // Find the maximum section and place the gas station:
        long double maxSection = -1;
        int maxIndex = -1;
        for(int i = 0; i < n-1; i++){
            long double diff = arr[i+1] - arr[i];
            long double sectionLength = diff / ((long double)howMany[i] + 1.0);
            if(sectionLength > maxSection){
                maxSection = sectionLength;
                maxIndex = i;
            }
            // Insert the current gas station:
        }
        howMany[maxIndex]++;
    }
    // Find the maximum distance:
    long double maxAns = -1;
    for(int i = 0; i < n-1; i++){
        long double diff = arr[i+1] - arr[i];
        long double sectionLength = diff / ((long double)howMany[i] + 1.0);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

// TC : O(N log N + k log N), SC : O(N-1) + O(N-1) {The first O(n-1) is for the array to keep track of placed gas stations and the second one is for the priority queue.}
long double better(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howMany(n-1, 0);

    // Insert the first n-1 elements into pq with respective distance values:
    priority_queue<pair<long double, int> > pq;
    for(int i = 0; i < n-1; i++){
        pq.push({arr[i+1]-arr[i], i});
    }

    // Pick and place k gas stations
    for(int gasStations = 1; gasStations <= k; gasStations++){
        // Find the maximum distance and insert the current gas station:
        auto tp = pq.top();
        pq.pop();
        int secIndex = tp.second;
        // Insert the current gas station:
        howMany[secIndex]++;

        long double iniDiff = arr[secIndex + 1] - arr[secIndex];
        long double newSectionLen = iniDiff / ((long double)(howMany[secIndex] + 1.0));
        pq.push({newSectionLen, secIndex});
    }
    return pq.top().first;
}

int noOfGasStationsRequired(long double dist, vector<int> &arr){
    int n = arr.size();
    int cnt = 0;
    for(int i = 1; i < n; i++){
        int numberInBetween = (arr[i] - arr[i-1]) / dist;
        if((arr[i] - arr[i-1]) == (dist * numberInBetween)){
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

// TC : O(N * log(Len)) + O(N) {Len-> Length of answer space}, SC : O(1)
long double optimal(vector<int> &arr, int k){
    int n = arr.size();

    long double low = 0;
    long double high = 0;

    // Find the maximum distance:
    for(int i = 0; i < n-1; i++){
        high = max(high, (long double)(arr[i+1] - arr[i]));
    }
    // Apply binary search:
    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (high + low) / (2.0);
        int cnt = noOfGasStationsRequired(mid, arr);
        if(cnt > k){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    long double x = brute(arr, k);
    cout << x << endl;

    long double y = better(arr, k);
    cout << y << endl;

    long double z = optimal(arr, k);
    cout << z << endl;

    return 0;
}