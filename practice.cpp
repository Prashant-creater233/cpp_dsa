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

// minimum repeat to make a substring

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        
        string temp = "";
        int count = 0;
        
        while(temp.length() < s2.length()) {
            temp += s1;
            count++;
        }
        
        //current string check
        if(temp.find(s2) != string::npos) {
            return count;
        }
        
        //one extra repetation
        temp += s1;
        count++;
        
        if(temp.find(s2) != string::npos) {
            return count;
        }
        
        return -1;
        
    }
};


//leetcode 114
// flatteb binary tree in linked lsit
// class Solution {
// public:
//     TreeNode* nextRight = NULL; // declare as globally

//     void flatten(TreeNode* root) {
//         if(root == NULL) {
//             return;
//         }

//         flatten(root->right);
//         flatten(root->left);

//         root->left = NULL;
//         root->right = nextRight;
//         nextRight = root;
//     }
// };


//merge two binary trees
//leetcode 617

// class Solution {
// public:
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if(!root1 && !root2) {
//             return NULL;
//         }
//         if(root1==NULL){
//             return root2;
//         }
//         if(root2==NULL){
//             return root1;
//         }

//         TreeNode* root = new TreeNode(root1->val + root2->val);

//         root->left = mergeTrees(root1->left, root2->left);
//         root->right = mergeTrees(root1->right, root2->right);

//         return root;
//     }
// };


//Length of last word
// leeetcode 58
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.size();
        int i = n-1;

        while(i>=0 && s[i] == ' ') {
            i--;
        } 

        while(i>=0 && s[i] != ' ') {
            count++; i--;
        }

        return count;
    }
};


// constuct binary tree from preorder and inorder traversal

// class Solution {
// public:
//     int search(vector<int>& inorder, int left, int right, int val) {
//         for(int i=left; i<=right; i++) {
//             if(inorder[i] == val) {
//                 return i;
//             }
//         }

//         return -1;
//     }

//     TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int  right) {
//         if(left > right) {
//             return NULL;
//         }

//         TreeNode* root = new TreeNode(preorder[preIdx]);

//         int inIdx = search(inorder, left, right, preorder[preIdx]);
//         preIdx++;;

//         root->left = helper(preorder, inorder, preIdx, left, inIdx-1);
//         root->right = helper(preorder, inorder, preIdx, inIdx+1, right);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int preIdx = 0;
//         return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
//     }
// };




// BST (binary serach tree)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     int prevOrder = 0;

//     int kthSmallest(TreeNode* root, int k) {
//         if(root == NULL) {
//             return -1;
//         }

//         if(root->left != NULL) {
//             int leftAns = kthSmallest(root->left, k);
//             if(leftAns != -1) {
//                 return leftAns;
//             }
//         }

//         if(prevOrder + 1 == k) {
//             return root->val;
//         }
//         prevOrder = prevOrder + 1;

//         if(root->right != NULL) {
//             int rightAns = kthSmallest(root->right, k);
//             if(rightAns != -1) {
//                 return rightAns;
//             }
//         }

//         return -1;
//     }
// };


// Minimun distance between nodes

// class Solution {
// public:
//     TreeNode* prev = NULL;

//     int minDiffInBST(TreeNode* root) {
//         if(root == NULL) {
//             return INT_MAX;
//         }

//         int ans = INT_MAX;
//         if(root->left != NULL) {
//             int leftMin = minDiffInBST(root->left);
//             ans = min(ans, leftMin);
//         }

//         if(prev != NULL) {
//             ans = min(ans, root->val - prev->val);
//         }
//         prev = root;

//         if(root->right != NULL) {
//             int rightMin = minDiffInBST(root->right);
//             ans = min(ans, rightMin);
//         }
        
//         return ans;
//     }
// };


// validate bst

// class Solution {
// public:
//     bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
//         if(root == NULL) {
//             return true;
//         }

//         if(min != NULL && root->val <= min->val) {
//             return false;
//         }

//         if(max != NULL && root->val >= max->val) {
//             return false;
//         }

//         return helper(root->left, min, root) && helper(root->right, root, max);
//     }

//     bool isValidBST(TreeNode* root) {

//         return helper(root, NULL, NULL);
//     }
// };


// convert sorted tree into binary serach tree 

// class Solution {
// public:
//     TreeNode* helper(vector<int>& nums, int st, int end) {
//         if(st > end) {
//             return NULL;
//         }

//         int mid = st + (end-st)/2;

//         TreeNode* root = new TreeNode(nums[mid]);
        
//         root->left = helper(nums, st, mid-1);
//         root->right = helper(nums, mid+1, end);

//         return root;
//     }

//     TreeNode* sortedArrayToBST(vector<int>& nums) {

//         return helper(nums, 0, nums.size()-1);
//     }
// };

//flatten binary tree

// class Solution {
// public:
//     TreeNode* nextRight = NULL; // declare as globally

//     void flatten(TreeNode* root) {
//         if(root == NULL) {
//             return;
//         }

//         flatten(root->right);
//         flatten(root->left);

//         root->left = NULL;
//         root->right = nextRight;
//         nextRight = root;
//     }
// };


// count negatve no of matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++) {
            int st =0, end = n-1;
            int ans = n;

            while(st <= end) {
                int mid = st + (end - st)/2;
                
                if(grid[i][mid] < 0) {
                    ans = mid;
                    end = mid-1;
                } else {
                    st = mid + 1;
                }
            }
            
            count += n - ans;
        }

        return count;
    }
};


// maximum width of binary tree

// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         queue<pair<TreeNode*, unsigned long long>> q;
//         q.push({root, 0});
//         int maxWidth = 0;

//         while(q.size() > 0) {
//             unsigned long long currLevelSize = q.size();
//             unsigned long long stIdx = q.front().second;
//             unsigned long long endIdx = q.back().second;

//             maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

//             for(int i=0; i<currLevelSize; i++) {
//                 auto curr = q.front();
//                 q.pop();

//                 if(curr.first->left) {
//                     q.push({curr.first->left, curr.second*2 + 1});
//                 }

//                 if(curr.first->right) {
//                     q.push({curr.first->right, curr.second*2 + 2});
//                 }
//             }
//         }

//         return maxWidth;
//     }
// };



// convert bst from preorder leetcode 1008

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution { // O(n*2)
// public:
//     TreeNode* helper(vector<int>& preorder, int& i, int bound) {   
//         if(i >= preorder.size() || preorder[i] > bound) {
//             return NULL;
//         }

//         TreeNode* root = new TreeNode(preorder[i]);
//         i++;

//         root->left = helper(preorder, i, root->val);
//         root->right = helper(preorder, i, bound);

//         return root;
//     }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int i = 0;
//         return helper(preorder, i, INT_MAX);
//     }
// };

// convert bst from preorder leetcode 1008

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution { // O(n*2)
// public:
//     TreeNode* helper(vector<int>& preorder, int& i, int bound) {   
//         if(i >= preorder.size() || preorder[i] > bound) {
//             return NULL;
//         }

//         TreeNode* root = new TreeNode(preorder[i]);
//         i++;

//         root->left = helper(preorder, i, root->val);
//         root->right = helper(preorder, i, bound);

//         return root;
//     }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int i = 0;
//         return helper(preorder, i, INT_MAX);
//     }
// };


//kth lowest element in bst

// class Solution {
// public:
//     int prevOrder = 0;

//     int kthSmallest(TreeNode* root, int k) {
//         if(root == NULL) {
//             return -1;
//         }

//         if(root->left != NULL) {
//             int leftAns = kthSmallest(root->left, k);
//             if(leftAns != -1) {
//                 return leftAns;
//             }
//         }

//         if(prevOrder + 1 == k) {
//             return root->val;
//         }
//         prevOrder = prevOrder + 1;

//         if(root->right != NULL) {
//             int rightAns = kthSmallest(root->right, k);
//             if(rightAns != -1) {
//                 return rightAns;
//             }
//         }

//         return -1;
//     }
// };


// lowest common ancestor

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL) {
//             return NULL;
//         }

//         if(root->val > p->val && root->val > q->val) { //left suubtree
//             return lowestCommonAncestor(root->left, p, q);
//         } else if(root->val < p->val && root->val < q->val) { //right subtree
//             return lowestCommonAncestor(root->right, p, q);
//         } else {
//             return root;
//         }
//     }
// };