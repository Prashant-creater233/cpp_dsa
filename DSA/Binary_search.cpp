#include <iostream>
#include <vector>
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
//Rotated sorted Array

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



// Peak index in mountain array

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

