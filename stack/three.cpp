#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


// largest rectangle in histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;

        for(int i=0; i<n; i++) {
            int height = INT_MAX;
            for(int j=i; j<n; j++) {
                height = min(height, heights[j]);
                int wd = j-i+1;

                int currArea = height* wd;

                maxArea = max(currArea, maxArea);
            }
        }

        return maxArea;
    }
};