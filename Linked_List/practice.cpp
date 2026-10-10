#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
//         int count = 0;

//         //check if nodes exixt
//         while(count < k) {
//             if(temp == NULL) {
//                 return head;
//             }
//             temp = temp->next;
//             count++;
//         }

//         //recursively call for rest of LL
//         ListNode* prevNode = reverseKGroup(temp, k);

//         //reverse current group
//         temp = head; count = 0;
//         while(count < k) {
//             ListNode* next = temp->next;
//             temp->next = prevNode;
//             prevNode = temp;
//             temp = next;

//             count++;
//         }

//         return prevNode;
//     }
// };


// class Solution {
// public:
//     bool isSafe(vector<string> &board, int row, int col, int n) { //O(n)
//         //horizontal 
//         for(int j=0; j<n; j++) {
//             if(board[row][j] == 'Q'){
//                 return false;
//             }
//         }

//         //vertical
//         for(int i=0; i<n; i++) {
//             if(board[i][col] == 'Q'){
//                 return false;
//             }
//         }

//         // Left diagonal
//         for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//         }

//         //Right diagonal
//         for(int i=row, j=col; i>=0 && j<n; i--, j++) {
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//         }

//         return true;
//     } 

//     void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
//         if(row == n) {
//             ans.push_back({board});
//             return;
//         }


//         for(int j=0; j<n; j++) {
//             if(isSafe(board, row, j, n)) {
//                 board[row][j] = 'Q';
//                 nQueens(board, row+1, n, ans);
//                 board[row][j] = '.';           
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n, string(n, '.'));
//         vector<vector<string>> ans;

//         nQueens(board, 0, n, ans);
//         return ans;
//     }
// };



// count primes
// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n <= 2) return 0;

//         vector<bool> isPrime(n, true);

//         isPrime[0] = false;
//         isPrime[1] = false;

//         for (int i = 2; i * i < n; i++) {
//             if (isPrime[i]) {
//                 for (int j = i * i; j < n; j += i) {
//                     isPrime[j] = false;
//                 }
//             }
//         }

//         int count = 0;

//         for (int i = 2; i < n; i++) {
//             if (isPrime[i]) {
//                 count++;
//             }
//         }

//         return count;
//     }
// };


// maximum subarrray sum (kadane;s algorithm)

// int main() {
//     vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
//     int n = arr.size();

//     int currSum = 0;
//     int maxSubSum = INT_MIN;

//     for(int i=0; i<n; i++) {
//         currSum += arr[i];
//         maxSubSum = max(currSum, maxSubSum);

//         if(currSum < 0) {
//             currSum = 0;
//         }
//     }

//     cout << maxSubSum << endl;
// }


// maximum subarray  product

// int main() {
//     vector<int> arr = {-2,0, -1};
//     int n = arr.size();
//     int currProd1 = 1, maxSubProd = INT_MIN;

//     for(int i=0; i<n; i++) {
//         currProd1 *= arr[i];
//         maxSubProd = max(currProd1, maxSubProd);

//         if(currProd1 == 0) {
//             currProd1 = 1;
//         }
//     }

//     int currProd2 = 1;
//     for(int i=n-1; i>=0; i--) {
//         currProd2 *= arr[i];
//         maxSubProd = max(currProd2, maxSubProd);

//         if(currProd2 == 0) {
//             currProd2 = 1;
//         }
//     }
//     cout << maxSubProd << endl;
// }


// container with most water;

// int main() {
//     vector<int> height = {1,8,6,2,5,4,8,3,7};
//     int n = height.size();
//     int lp=0, rp=n-1;
//     int maxWater = 1;

//     while(lp < rp) {
//         int w = rp - lp;
//         int ht = min(height[lp], height[rp]);

//         int currWater = w * ht;

//         maxWater = max(currWater, maxWater);

//         height[lp] < height[rp] ? lp++ : rp--;
//     }

//     cout << maxWater << endl;
// }


// valid palindrome

// bool isalnum(char ch) {
//     if((tolower(ch) >= 'a' && tolower(ch) <='z') || (ch >= '0' && ch <= '9')) {
//         return true;
//     }

//     return false;
// }

// bool isPalindrome(string s) {
//     int i=0, j=s.size()-1;

//     while(i < j) {
//         if(!isalnum(s[i])) {
//             i++; continue;
//         }

//         if(!isalnum(s[j])) {
//             j--; continue;
//         }

//         if(tolower(s[i]) != tolower(s[j])) {
//             return false;
//         }
//         i++; j--;
//     }
//     return true;
// }

// int main() {
//     string s = "A man, a plan, a canal: Panama";
//     cout << isPalindrome(s);

//     return 0;
// }


//left to right array by k

// int main() {
//     vector<int> arr = {1,2,3,4,5,6,7};
//     int n = arr.size();
//     int k = 3;
//     k = k % n; // if k is greater than n
//     vector<int> ans;

//     for(int i=n-k; i<n; i++) {
//         ans.push_back(arr[i]);
//     }

//     for(int i=0; i<n-k; i++) {
//         ans.push_back(arr[i]);
//     }

//     for(int val : ans) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }

//  roted array by secont method 

// int main() {
//     vector<int> arr = {1,2,3,4,5,6,7};
//     int n = arr.size();
//     int k = 16;
//     k = k % n; // if k is greater than n

//     reverse(arr.begin(), arr.end());
//     reverse(arr.begin(), arr.begin() + k);
//     reverse(arr.begin() + k, arr.end());

//     for(int val : arr) {
//         cout << val << " ";
//     }
//     cout << endl;
//     return 0;
// }


// serach in 2D matrix

// bool searchInRow(vector<vector<int>>& mat, int target, int row) {
//     int n = mat[0].size();
//     int st =0, end =n-1;

//     while(st <= end) {
//         int mid = st + (end-st)/2;

//         if(target == mat[row][mid]) {
//             return true;
//         } else if(target > mat[row][mid]){
//             st = mid+1;
//         } else {
//             end = mid-1;
//         }
//     }
//     return false;
// }

// bool searchMatrix(vector<vector<int>>& mat, int target){
//     int m = mat.size(), n = mat[0].size();
//     int stRow = 0, endRow = m-1;
//     while(stRow <= endRow){
//         int midRow = stRow + (endRow - stRow)/2;

//         if(target >= mat[midRow][0] && target <= mat[midRow][n-1]) {
//             return searchInRow(mat, target, midRow);
//         } else if(target > mat[midRow][n-1]) {
//             stRow = midRow+1;
//         } else {
//             endRow = midRow - 1;
//         }
//     }

//     return false;
// }

// int main() {
//     vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
//     int target = 3;

//     cout << searchMatrix(mat, target);

//     return 0;

// }



// serach in rotated sorted array

int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    int n = arr.size();
    int ans = -1;

    int st =0, end=n-1;
    while(st <= end) {
        int mid = st + (end-st)/2;
        if(target == arr[mid]) {
            ans = mid;
            break;
        } 

        if(arr[st] <= arr[mid]) {
            if(target >= arr[st] && target <= arr[mid]) {
                end = mid-1;
            } else {
                st = mid +1;
            }
        } else {
            if(target >= arr[mid] && target <= arr[end]) {
                st = mid+1;
            } else {
                end = mid-1;
            }
        }
    }

    cout << ans;

    return 0;
}