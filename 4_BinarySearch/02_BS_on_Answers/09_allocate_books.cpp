// 31st July, 2025
// Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.

// Allocate books in such a way that:
// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. Return -1.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // To use accumulate()
using namespace std;

// TC : O(N), SC : O(1)
int calcStudents(vector<int> &arr, int pages){
    int n = arr.size();
    int studentPages = 0, student = 1;
    for(int i = 0; i < n; i++){
        if(studentPages + arr[i] <= pages){
            // Add pages to the current student
            studentPages += arr[i];
        }
        else{
            // Add pages to the next student
            student++;
            studentPages = arr[i];
        }
    }
    return student;
}

// TC : O(N * (sum(arr)-max(arr) + 1)), SC : O(1)
int brute(vector<int> &arr, int students){
    if(arr.size() < students) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for(int i = low; i <= high; i++){
        if(calcStudents(arr, i) == students){
            return i;
        }
    }
    return -1;
}

// TC : O(N * log( sum(arr)-max(arr) )), SC : O(1)
int optimal(vector<int> &arr, int students){
    if(arr.size() < students) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low + high) / 2;
        if(calcStudents(arr, mid) > students){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {25, 46, 28, 49, 24};
    int students = 4;

    int x = brute(arr, students);
    cout << x << endl;

    int y = optimal(arr, students);
    cout << y << endl;

    return 0;
}