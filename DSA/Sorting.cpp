#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// ham sorting use nhi krta ha leetcode pe questions solve krna ke liya
// Bubble sort 

// void bubbleSort(int arr[], int n) { // O(n^2)
//     bool isSwap = false;

//     for(int i=0; i<n-1; i++) {
//         for(int j=0; j<n-i-1; j++){
//             if(arr[j] > arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//                 isSwap = true;
//             }
//         }
//         if(!isSwap){ // array is already sorted
//             return;
//         }
//     }
// }

// void printArray(int arr[] , int n){
//     for(int i=0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int n = 5;
//     int arr[] = {4, 1, 5, 2, 3};

//     bubbleSort(arr, n);
//     printArray(arr,n);

//     return 0;
// }


// Selection sort

// void selectionSort(int arr[], int n) { // O(n^2)

//     for(int i=0; i<n; i++) {
//         int smallestIdx = i; // unsorted part starting
//         for(int j=i+1; j<n; j++){
//             if(arr[j] < arr[smallestIdx]){
//                 smallestIdx = j;
//             }
//         }
//         swap(arr[i], arr[smallestIdx]);
//     }
// }

// void printArray(int arr[] , int n){
//     for(int i=0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int n = 5;
//     int arr[] = {4, 1, 5, 2, 3};

//     selectionSort(arr, n);
//     printArray(arr,n);

//     return 0;
// }



// Insertion sort

// void printArray(int arr[] , int n){
//     for(int i=0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void insertionSort(int arr[], int n) { // O(n^2)

//     for(int i=1; i<n; i++) {
//         int curr = arr[i];
//         int prev = i-1;

//         while(prev >= 0 && arr[prev] > curr) {
//             arr[prev+1] = arr[prev];
//             prev--;
//         }
//         arr[prev+1] = curr; // placing the curr alement in its correct position
//     }
// }

// National Flag Algorithm
// int main() {
//     int n = 5;
//     int arr[] = {4, 1, 5, 2, 3};

//     insertionSort(arr, n);
//     printArray(arr,n);

//     return 0;
// }



// Sort array with 0s, 1s, 2s leetcode 75

// class Solution {
// public:
//     void sortColors(vector<int>& nums) { // O(n)
//         int n = nums.size();
//         int low = 0, mid = 0, high = n-1;

//         while(mid <= high) {
//             if(nums[mid] == 0) {
//                 swap(nums[low], nums[mid]);
//                 mid++;
//                 low++;
//             } else if(nums[mid] == 1) {
//                 mid++;
//             } else { // 2
//                 swap(nums[high], nums[mid]);
//                 high--;
//             }
//         }
//     }
// };


// Merge 2 Sorted arrays problem leetcode 88

// class Solution {
// public:
//     void merge(vector<int>& A, int m, vector<int>& B, int n) {  // TC ->O(m+n)  SC-> O(1)
//         int idx = m+n-1, i = m-1, j = n-1;

//         while(i >= 0 && j >= 0) {
//             if(A[i] >= B[j]) {
//                 A[idx] = A[i];
//                 idx--;
//                 i--;
//             } else{
//                 A[idx] = B[j];
//                 idx--;
//                 j--;
//             }
//         }
//         while(j >= 0) {
//             A[idx] = B[j];
//             idx--;
//             j--;
//         }
//     }
// };




// Next Permutation  leetcode 31

// class Solution {
// public:
//     void nextPermutation(vector<int>& A) {  // TC O(n)  SC O(1)
//         //step1 find the pivot
//         int pivot = -1, n = A.size();
//         for(int i=n-2; i>=0; i--){
//             if(A[i] < A[i+1]) {
//                 pivot = i;
//                 break;
//             }
//         }
//         if(pivot == -1){
//             reverse(A.begin(), A.end()); //in place changes
//             return;
//         }

//         //step2 : next larger element
//         for(int i=n-1; i>pivot;  i--){
//             if(A[i] > A[pivot]){
//                 swap(A[i], A[pivot]);
//                 break;
//             }
//         }

//         //step3 : reverse (piv+1 to n-1)

//         //reverse(A.begin() + pivot + 1, A.end());  // Alternate method to reverse

    
//         int i=pivot+1, j=n-1;
//         while(i <= j) {
//             swap(A[i], A[j]);
//             i++;
//             j--;
//         }

//     }
// };

// in c++ STL next_permutation is a function we directely call it and it give us answer but this is not allowed in interview
// next_permutation(A.begin(), A.end());