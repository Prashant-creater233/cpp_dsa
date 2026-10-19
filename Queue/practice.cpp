#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;


// first unique character in string 

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> m;
        queue<int> q;

        for(int i=0; i<n; i++) {
            if(m.find(s[i]) == m.end()) {
                q.push(i);
            }

            m[s[i]]++;

            while(q.size() > 0 && m[s[q.front()]] > 1 ) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};


// sliding window Maximum  (bruteforce)

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = nums.size();
    int k = 3;
    vector<int> anss;

    for(int i = 0; i <= n-k; i++) {
        int ans = INT_MIN;

        for(int j = i; j < i+k; j++) {
            ans = max(ans, nums[j]);
        }

        anss.push_back(ans);
    }

    for(int val : anss) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
