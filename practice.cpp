#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 7};
    int x = 4;

    auto it = lower_bound(arr.begin(), arr.end(), x);

    cout << "Lower Bound Index: " << it - arr.begin();
    return 0;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 7};
    int x = 4;

    auto it = upper_bound(arr.begin(), arr.end(), x);

    cout << "Upper Bound Index: " << it - arr.begin();
    return 0;
}

int binarySearch(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

vector<int> searchRange(vector<int>& arr, int x) {
    int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    if (first == arr.size() || arr[first] != x)
        return {-1, -1};

    int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;

    return {first, last};
}

void reverseArray(vector<int>& arr) {
    int i = 0, j = arr.size() - 1;

    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

// check if sentence is pangram
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
    
        for(int i=0; i<sentence.size(); i++) {
            s.insert(sentence[i]);
        }

        return s.size() == 26;
    }
};


//Happy Number

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;

        if(n < 0) {
            return false;
        }

        while(n != 1 && s.find(n) == s.end()) {
            s.insert(n);

            int sum = 0;

            while(n != 0) {
                int dig = n % 10;
                sum += dig * dig;
                n = n /10;
            }

            n = sum;
        }

        return n == 1;
    }
};


// intersection of two arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int> result;

        for(int i=0; i<n; i++) {
            s1.insert(nums1[i]);
        }

        for(int j=0; j<m; j++) {
            if(s1.find(nums2[j]) != s1.end()) {
                result.insert(nums2[j]);
            }
        }

        vector<int> ans(result.begin(), result.end());
        return ans;
    }
};

// Binary tree inorder traversal

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         TreeNode* curr = root;

//         // Morris inorder traversal algorithm
//         while(curr != NULL) {
//             if(curr->left == NULL) {
//                 ans.push_back(curr->val);
//                 curr = curr->right;
//             } else {
//                 //find the IP
//                 TreeNode* IP = curr->left;
//                 while(IP->right != NULL && IP->right != curr) {
//                     IP = IP->right;
//                 }

//                 if(IP->right == NULL) {
//                     IP->right = curr; //create
//                     curr = curr->left;
//                 } else {
//                     IP->right = NULL; //delete
//                     ans.push_back(curr->val);
//                     curr = curr->right;
//                 }
//             }
//         }

//         return ans;
//     }
// };


//single number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        for(int val : nums){
            ans = ans^val;
        }
        return ans;
        
    }
};


// // Leetcode 100 same tree

//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p == NULL || q == NULL) {
//             return p == q;
//         }

//         bool isLeftSame = isSameTree(p->left, q->left);
//         bool isRightSame = isSameTree(p->right, q->right);

//         return (isLeftSame && isRightSame && (p->val == q->val));
//     }
// };


// isomorphic string

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        map<char, char> mp1;
        map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {

            // s -> t check
            if (mp1.find(s[i]) != mp1.end()) {
                if (mp1[s[i]] != t[i]) {
                    return false;
                }
            }

            // t -> s check
            if (mp2.find(t[i]) != mp2.end()) {
                if (mp2[t[i]] != s[i]) {
                    return false;
                }
            }

            // mapping store
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        return true;
    }
};


// valid anagram

class Solution {
public:
    bool isAnagram(string s, string t) { //O(n)
        if(s.size() != t.size()) {
            return false;
        }
        
        int freq[26] = {0};
        for(int i=0; i<s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i=0; i<26; i++) {
            if(freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};


//count number of words

class Solution {
  public:
    int countWords(string &s) {
        // code here
        int count = 0;
        bool inWord = false;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
                inWord = false;
            } else if (!inWord) {
                count++;
                inWord = true;
            }
        }
        
        return count;
    }
};