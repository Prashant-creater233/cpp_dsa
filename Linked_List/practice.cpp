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

bool isalnum(char ch) {
    if((tolower(ch) >= 'a' && tolower(ch) <='z') || (ch >= '0' && ch <= '9')) {
        return true;
    }

    return false;
}

bool isPalindrome(string s) {
    int i=0, j=s.size()-1;

    while(i < j) {
        if(!isalnum(s[i])) {
            i++; continue;
        }

        if(!isalnum(s[j])) {
            j--; continue;
        }

        if(tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++; j--;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);

    return 0;
}