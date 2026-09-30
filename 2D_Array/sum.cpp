#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2 sum (leetcode 1)
// 1 brute force approach

// int main() {
//     vector<int> arr= {5, 2, 11, 7, 15};
//     int n = arr.size();
//     int target = 9;
//     vector<int> ans;

//     for(int i=0; i<n; i++) {
//         int first = arr[i];
//         for(int j=i+1;  j<n; j++) {
//             int second = arr[j];
//             int sum=0;

//             sum = first + second;

//             if(sum == target){
//                 ans.push_back(first);
//                 ans.push_back(second);
//             }
//         }
//     }

//     // Print answer
//     for(int x : ans) {
//         cout << x << " ";
//     }

//     return 0;

// }

// Better approach

// int main() {
//     vector<int> arr = {5, 2, 11, 7, 15};
//     int n = arr.size();
//     int target = 9;

//     vector<int> ans;
//     int st = 0, end = n - 1;

//     sort(arr.begin(), arr.end());

//     while(st < end) {
//         int sum = arr[st] + arr[end];

//         if(sum == target) {
//             ans.push_back(st);
//             ans.push_back(end);
//             break;
//         }
//         else if(sum < target) {
//             st++;
//         }
//         else {
//             end--;
//         }
//     }

//     // print answer
//     for(int val : ans) {
//         cout << val << " ";
//     }

//     return 0;
// }

// 3sum

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                if (nums[i] + nums[j] + nums[k] == 0) {

                    vector<int> temp = {nums[i], nums[j], nums[k]};

                    // triplet ko sort karo
                    sort(temp.begin(), temp.end());

                    // check karo ki ye pehle se answer mein hai ya nahi
                    if (find(ans.begin(), ans.end(), temp) == ans.end()) {
                        ans.push_back(temp);
                    }
                }
            }
        }
    }

    // Print answer
    for (vector<int> val : ans) {
        for (int x : val) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}