#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;


// largest rectangle in histogram (brute force approach)

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = INT_MIN;

//         for(int i=0; i<n; i++) {
//             int height = INT_MAX;
//             for(int j=i; j<n; j++) {
//                 height = min(height, heights[j]);
//                 int wd = j-i+1;

//                 int currArea = height* wd;

//                 maxArea = max(currArea, maxArea);
//             }
//         }

//         return maxArea;
//     }
// };

// by most optimising approacg

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0); //left smaller nearest
        vector<int> right(n,0); //right smaller nearest
        stack<int> s;
        
        // Right smaller
        for(int i=n-1; i>=0; i--) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top(); // edge case not -1 on rigth take n because formula not correct when 
            s.push(i);
        }

        while(!s.empty()) {
            s.pop();
        }

        // left smaller
        for(int i=0; i<n; i++) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            int width = right[i] - left[i] -1;
            int currArea = heights[i] * width;

            ans = max(ans, currArea);
        }

        return ans;
    }
};

// reverse word in string

class Solution {
public:
    string reverseWords(string s) {
        int n =  s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i=0; i<n; i++) {
            string word = "";

            while(i < n  && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if(word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};

// Next Grater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for(int i=2*n-1; i>=0; i--) {
            while(s.size()>0 && nums[s.top()] <= nums[i%n]) {
                s.pop();
            }

            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }

        return ans;
    }
};

// Traping RainWater by optimal solution TC = O(N) ans SC = (N);
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        lmax[0] = height[0];
        rmax[n-1] = height[n-1];

        for(int i=1; i<n; i++) {
            lmax[i] = max(lmax[i-1], height[i]);
        }

        for(int i=n-2; i>=0; i--) {
            rmax[i] = max(rmax[i+1], height[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += min(lmax[i], rmax[i]) - height[i];
        }

        return ans;
    }
};

// // Traping RainWater by optimal solution TC = O(N) ans SC = (1);
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l=0, r=n-1;
        int lmax=0, rmax=0;

        while(l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax  - height[r];
                r--;
            }
        }

        return ans;
    }
};