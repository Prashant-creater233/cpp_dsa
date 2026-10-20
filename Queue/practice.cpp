#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;


// first unique character in string 

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int n = s.size();
//         unordered_map<char, int> m;
//         queue<int> q;

//         for(int i=0; i<n; i++) {
//             if(m.find(s[i]) == m.end()) {
//                 q.push(i);
//             }

//             m[s[i]]++;

//             while(q.size() > 0 && m[s[q.front()]] > 1 ) {
//                 q.pop();
//             }
//         }

//         return q.empty() ? -1 : q.front();
//     }
// };


// // sliding window Maximum  (bruteforce)

// int main() {
//     vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
//     int n = nums.size();
//     int k = 3;
//     vector<int> anss;

//     for(int i = 0; i <= n-k; i++) {
//         int ans = INT_MIN;

//         for(int j = i; j < i+k; j++) {
//             ans = max(ans, nums[j]);
//         }

//         anss.push_back(ans);
//     }

//     for(int val : anss) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }


// sliding window maximum by brute force approach

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        // analyze 1st window 
        for(int i=0; i<k; i++) {
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // SWE for other windows
        for(int i=k; i<n; i++) {
            ans.push_back(nums[dq.front()]);
            
            // Remove from deque which are not part of current window
            while(dq.size() > 0 && dq.front() <= i-k) {
                dq.pop_front();
            }

            // remove the smaller values
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

       for(int val : ans) {
        cout << val << " ";
    }
       cout << endl;
    }
};