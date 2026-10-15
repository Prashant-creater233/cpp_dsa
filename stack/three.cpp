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

            right[i] = s.empty() ? n : s.top();
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