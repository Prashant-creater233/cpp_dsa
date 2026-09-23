#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// For Iterative Binary Search

// int binarySearch(vector<int> arr, int tar) {
//     int st=0, end=arr.size()-1;

//     while(st <= end){
//         int mid = st + (end-st)/2;

//         if(tar > arr[mid]){
//             st = mid + 1; //2nd half
//         } else if(tar < arr[mid]) {
//             end = mid-1; // 1st half
//         } else{
//             return mid;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd array
//     int tar1 = 5;

//     // cout << binarySearch(arr1, tar1) << endl;

//     vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even array
//     int tar2 = 0;

//     cout << binarySearch(arr2, tar2) << endl;

// }

// For Recursive Binary search

// int recBinarySearch(vector<int> arr, int tar, int st, int end){

//     if(st <= end){
//         int mid = st + (end-st)/2;

//         if(tar > arr[mid]){
//             return recBinarySearch(arr, tar, mid+1, end);
//         } else if(tar < arr[mid]){
//             return recBinarySearch(arr, tar, st, mid-1);
//         } else {  // mid => ans
//             return mid;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd array
//     int tar1 = 5;

//     // cout << binarySearch(arr1, tar1) << endl;

//     vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even array
//     int tar2 = 0;

//     cout << recBinarySearch(arr2, tar2, 0, arr2.size()-1 ) << endl;

//     return 0;

// }

// ques 33 in leetcode
// Rotated sorted Array

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int st=0, end = nums.size() - 1;

//         while(st <= end){
//             int mid = st + (end-st)/2;
//             if(nums[mid] == target){
//                 return mid;
//             }

//             if(nums[st] <= nums[mid]){ // left sorted
//                 if(nums[st] <= target && target <= nums[mid]) {
//                     end = mid -1;
//                 } else {
//                     st = mid + 1;
//                 }
//             } else { // right sorted
//                 if(nums[mid] <= target && target <= nums[end]) {
//                     st = mid + 1;
//                 } else{
//                     end = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };

// 852 leetcode  Peak index in mountain array

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& A) {
//         int st = 1, end = A.size()-2;

//         while(st <= end) {
//             int mid = st + (end - st)/2;

//             if(A[mid-1] < A[mid] && A[mid] > A[mid + 1]) {
//                 return mid;
//             } else if  (A[mid - 1] < A[mid]) { // increasing so right
//                 st = mid + 1;
//             } else { // dec  left
//                 end = mid - 1;
//             }
//         }
//         return -1;
//     }
// };

// 540 leetcode   Single element in sorted array

// class Solution
// {
// public:
//     int singleNonDuplicate(vector<int> &A)
//     {
//         int n = A.size();

//         if (n == 1)
//             return A[0];

//         int st = 0, end = n - 1;

//         while (st <= end)
//         {
//             int mid = st + (end - st) / 2;

//             if (mid == 0 && A[0] != A[1])
//                 return A[mid];
//             if (mid == n - 1 && A[n - 1] != A[n - 2])
//                 return A[mid];

//             if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1])
//                 return A[mid];

//             if (mid % 2 == 0)
//             { // even
//                 if (A[mid] == A[mid - 1])
//                 { // left
//                     end = mid - 1;
//                 }
//                 else
//                 { // right
//                     st = mid + 1;
//                 }
//             }
//             else
//             { // odd
//                 if (A[mid] == A[mid - 1])
//                 { // right
//                     st = mid + 1;
//                 }
//                 else
//                 { // left
//                     end = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };




// Book Allocation of Allocate Books Problem 

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {   //O(n)
    int students=1, pages=0;

    for(int i=0; i<n; i++) {
        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }
    return students > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m){   // O(log * n)
    if(m > n) {  //edge case
        return -1;
    }

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    int ans = 0;
    int st = 0, end = sum; // range of possible ans

    while(st <= end) { //O(logN) * n
        int mid = st + (end-st)/2;

        if(isValid(arr, n, m, mid)) { //left
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ans;

}


int main() {
    // vector<int> arr = {2, 1, 3, 4}; //6
    // int n = 4, m = 2;

    vector<int> arr = {15, 17, 20}; //32
    int n = 3, m = 2;

    cout << allocateBooks(arr, n, m) << endl;
}




// Pinters Partition Problem

// bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime) {  // O(n)
//     int painters = 1, time = 0;

//     for(int i=0; i<n; i++) {
//         if(time + arr[i] <=  maxAllowedTime){
//             time += arr[i];
//         } else { //new painter
//             painters++;
//             time = arr[i];
//         }
//     }

//     return painters <= m;
// }

// int minTimeToPaint(vector<int> &arr, int n, int m) { 
//     int sum =0, maxValue = INT_MIN;
//     for(int i=0; i<n;i++) {   //O(n)
//         sum += arr[i];
//         maxValue = max(maxValue, arr[i]);
//     }

//     int ans = -1;
//     int st = maxValue, end = sum; // range of possible ans

//     while(st <= end) { //  O(log(sum)) * n
//         int mid = st + (end-st)/2;

//         if(isPossible(arr, n, m , mid)) { // left
//             ans = mid;
//             end = mid - 1;
//         } else { // right
//             st = mid + 1;
//         }
//     }
//     return ans;
// }

// int main(){
//     vector<int> arr = {40, 30, 10, 20};
//     int n = 4, m = 2;

//     cout << minTimeToPaint(arr, n, m) << endl;

//     return 0;
// }




// Aggressive cows  problem 


// bool isPossible(vector<int> &arr, int N, int C, int minallowedDistance){ // O(N)
//     int cows = 1, lastStallPos = arr[0];

//     for(int i=0; i<N; i++){
//         if(arr[i] - lastStallPos >= minallowedDistance){
//             cows++;
//             lastStallPos = arr[i];
//         }

//         if(cows == C){
//             return true;
//         }
//     }
//     return false;
// }

// int getDistance(vector<int> &arr, int N, int C) {
//     sort(arr.begin(), arr.end());

//     int st = 1, end = arr[N-1]-arr[0], ans = -1;

//     while(st <= end){ // O(log(Range) * N)
//         int mid = st + (end-st)/2;

//         if(isPossible(arr, N, C, mid)) { // right
//             ans = mid;
//             st = mid + 1;
//         } else{ // left
//             end = mid - 1;
//         }
//     }
//     return ans;
// }


// int main(){
//     vector<int> arr = {1, 2, 4, 8, 9};
//     int N = 5, C = 3;

//     cout << getDistance(arr, N, C) << endl;

//     return 0;
// }
