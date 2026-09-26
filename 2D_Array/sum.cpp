#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2 sum (leetcode 1)
// 1 brute force approach

int main() {
    vector<int> arr= {5, 2, 11, 7, 15};
    int n = arr.size();
    int target = 9;
    vector<int> ans;

    for(int i=0; i<n; i++) {
        int first = arr[i];
        for(int j=i+1;  j<n; j++) {
            int second = arr[j];
            int sum=0;

            sum = first + second;

            if(sum == target){
                ans.push_back(first);
                ans.push_back(second);
            }
        }
    }

    // Print answer
    for(int x : ans) {
        cout << x << " ";
    }

    return 0;

}

// Better approach
