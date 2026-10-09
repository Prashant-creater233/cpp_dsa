#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// int main() {
//     //stock prices
//     vector<int> price = {100, 80, 60, 70, 60, 75, 85};

//     //solution
//     vector<int> ans(price.size(), 0);
//     stack<int> s;

//     for(int i=0; i<price.size(); i++) {
//         while(s.size() > 0 && price[s.top()] <= price[i]) {
//             s.pop();
//         }

//         if(s.size() == 0) {
//             ans[i] = i+1;
//         } else {
//             ans[i] = i - s.top(); // i - prevHigh
//         }

//         s.push(i);
//     }

//     for(int val : ans) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }


// Next Greater Element

// int main() {
//     vector<int> arr = {6, 8, 0, 1, 3};

//     //Next Greater Element
//     stack<int> s;
//     vector<int> ans(arr.size(), 0);
//     int n = arr.size();

//     for(int i=n-1; i>=0; i--) {
//         while(s.size() > 0 && s.top() <= arr[i]) {
//             s.pop();
//         }

//         if(s.empty()) {
//             ans[i] = -1;
//         } else {
//             ans[i] = s.top();
//         }

//         s.push(arr[i]);
//     }

//     for(int val : ans) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }



// Leetcode 496

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int,int> m; //nums2[i], NG;
//         stack<int> s;

//         for(int i=nums2.size()-1; i>=0; i--) {
//         while(s.size() > 0 && s.top() <= nums2[i]) {
//             s.pop();
//         }

//         if(s.empty()) {
//             m[nums2[i]] = -1;
//         } else {
//             m[nums2[i]] = s.top();
//         }

//         s.push(nums2[i]);
//     }

//     vector<int> ans;
//     for(int i=0; i<nums1.size(); i++) {
//         ans.push_back(m[nums1[i]]);
//     }

//     return ans;
//     }
  
// };



// Previous Smaller element

vector<int> prevSmallerElement(vector<int> &arr) {
    vector<int> ans(arr.size(), 0);
    stack<int> s;

    for(int i=0; i<arr.size(); i++) {
        while(s.size() > 0 && s.top() >= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    return ans;
}


int main() {
    vector<int> arr = {3, 1, 0, 8, 6};

    vector<int> ans = prevSmallerElement(arr);

    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}