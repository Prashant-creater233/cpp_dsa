#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;


//leetcode 20;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') { //opening charcters
                st.push(s[i]);
            } else { ///closing charcters
                if(st.size() == 0) { // closing brackets > opening brackets
                    return false;
                }

                if((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                } else { //no match
                    return false;
                }
            } 
        }

        return st.size() == 0;

    }
};

// container with most water

class Solution {
public:
    int maxArea(vector<int>& height) { //O(n)
        int maxWater = 0;
        int lp=0, rp=height.size()-1;

        while(lp < rp){
            int w = rp-lp;
            int ht = min(height[lp], height[rp]);
            int currWater = w * ht;

            maxWater = max(maxWater, currWater);
            
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};


// combination sum
class Solution {
public:
    set<vector<int>> s;

    void getAllCombination(vector<int>& arr, int idx,int tar, vector<vector<int>>& ans, vector<int>& combin){
        //base case
        if(idx == arr.size() || tar < 0) {
            return;
        }

        if(tar == 0){
            if(s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }


        combin.push_back(arr[idx]);
        //single
        getAllCombination(arr, idx+1, tar-arr[idx], ans, combin);
        //multiple
        getAllCombination(arr, idx, tar-arr[idx], ans, combin);
        combin.pop_back(); // backtracking

        //exclusion
        getAllCombination(arr, idx+1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombination(arr, 0, tar, ans, combin);

        return ans;
    }
};