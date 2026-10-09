#include <iostream>
#include <vector>
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