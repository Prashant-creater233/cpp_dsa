#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
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


//minimum distanxe between bst nodes

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


//Recover Binary Search tree

// class Solution {
// public:
//     TreeNode* prev = NULL;
//     TreeNode* first = NULL;
//     TreeNode* second = NULL;

//     void inorder(TreeNode* root) {
//         if(root == NULL) {
//             return;
//         }

//         inorder(root->left);

//         if(prev != NULL && prev->val > root->val) {
//             if(first == NULL) {
//                 first = prev;
//             }
//             second = root;
//         }
//         prev = root;

//         inorder(root->right);
//     }

//     void recoverTree(TreeNode* root) {
//         inorder(root);

//         int temp = first->val;
//         first->val = second->val;
//         second->val = temp;
//     }
// };


//Populate Next Right Pointers

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root == NULL || root->left == NULL) {
//             return root;
//         }

//         queue<Node*> q;
//         q.push(root);
//         q.push(NULL); //mark the end of a level

//         Node* prev = NULL;

//         while(q.size() > 0) {
//             Node* curr = q.front();
//             q.pop();

//             if(curr == NULL) {
//                 if(q.size() == 0) {
//                     break;
//                 }

//                 q.push(NULL);
//             } else {
//                 if(curr->left != NULL) {
//                     q.push(curr->left);
//                 }

//                 if(curr->right != NULL) {
//                     q.push(curr->right);
//                 }

//                 if(prev != NULL) {
//                     prev->next = curr;
//                 }
//             }

//             prev = curr;
//         }

//         return root;
//     }
// };


// Transformation array

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            int idx = ((i + nums[i]) % n + n) % n;
            result[i] = nums[idx];
        }

        return result;
    }
};



//square of a sorted array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int left=0, right=n-1;
        for(int i=n-1; i>=0; i--) {
            if(abs(nums[left]) < abs(nums[right])) {
                ans[i] = nums[right]*nums[right];
                right--;
            } else {
                ans[i] = nums[left]*nums[left];
                left++;
            }
        }

        return ans;
    }
};


//Two sum ||

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> ans;

        int st = 0, end = n-1;
        while(st < end) {
            if(arr[st] + arr[end] < target){
                st++;
            } else if(arr[st] + arr[end] > target) {
                end--;
            } else {
                ans.push_back(st+1);
                ans.push_back(end+1);
                break;
            }
        }

        return ans;
    }
};



// populate next right pointers


// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root == NULL || root->left == NULL) {
//             return root;
//         }

//         queue<Node*> q;
//         q.push(root);
//         q.push(NULL); //mark the end of a level

//         Node* prev = NULL;

//         while(q.size() > 0) {
//             Node* curr = q.front();
//             q.pop();

//             if(curr == NULL) {
//                 if(q.size() == 0) {
//                     break;
//                 }

//                 q.push(NULL);
//             } else {
//                 if(curr->left != NULL) {
//                     q.push(curr->left);
//                 }

//                 if(curr->right != NULL) {
//                     q.push(curr->right);
//                 }

//                 if(prev != NULL) {
//                     prev->next = curr;
//                 }
//             }

//             prev = curr;
//         }

//         return root;
//     }
// };


// Populating next pointer

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root == NULL || root->left == NULL) {
//             return root;
//         }

//         queue<Node*> q;
//         q.push(root);
//         q.push(NULL);

//         Node* prev = NULL;

//         while(q.size() > 0) {
//             Node* curr = q.front();
//             q.pop();

//             if(curr == NULL) {
//                 if(q.size() == 0) {
//                     break;
//                 }
//                 q.push(NULL);
//             } else {
//                 if(curr->left != NULL) {
//                     q.push(curr->left);
//                 }

//                 if(curr->right != NULL) {
//                     q.push(curr->right);
//                 }

//                 if(prev != NULL) {
//                     prev->next = curr;
//                 }
//             }
//             prev = curr;
//         }

//         return root;
//     }
// };


// sort array by parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return nums;
    }
};


// row with maximum ones


class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int maxx = -1;
        int idx = 0;

        for(int i = 0; i < m; i++) {
            int curr = 0;

            for(int j = 0; j < n; j++) {
                curr += mat[i][j];
            }

            if(curr > maxx) {
                maxx = curr;
                idx = i;
            }
        }

        return {idx, maxx};
    }
};



// max row with ones


class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int maxx = -1;
        int idx = 0;

        for(int i = 0; i < m; i++) {
            int curr = 0;

            for(int j = 0; j < n; j++) {
                curr += mat[i][j];
            }

            if(curr > maxx) {
                maxx = curr;
                idx = i;
            }
        }

        return {idx, maxx};
    }
};


// running sum of 1d array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int s = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            s = s + nums[i];
            ans.push_back(s);
        }

        return ans;
    }
};

// convert 1d into 2d array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m * n != original.size()) {
            return {};
        }

        vector<vector<int>> ans(m, vector<int>(n));
        int index = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans[i][j] = original[index];
                index++;
            }
        }

        return ans;
    }
};

// add digits

class Solution {
public:
    int addDigits(int num) {
        while(!(num >= 0 && num <= 9) ) {
            int ans = 0;
            while(num != 0 ) {
                int digit = num%10;
                ans += digit;
                num = num/10;
            }
            num = ans;
        }

        return num;
    }
};


//clear digits

class Solution {
public:
    string clearDigits(string s) {
        string ans;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                ans.pop_back();
            }
            else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};


// Rotating Oranges

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int ans = 0;

//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         queue<pair<pair<int, int>, int>> q; // (i,j), time

//         // pushing all sources in queue
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 if(grid[i][j] == 2) {
//                     q.push({{i,j}, 0});
//                     vis[i][j] = true;
//                 }
//             }
//         }

//         while(q.size() > 0) {
//             int i = q.front().first.first;
//             int j = q.front().first.second;
//             int time = q.front().second;
//             q.pop();

//             ans = max(ans, time);

//             if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1) { // top
//                 q.push({{i-1, j}, time+1});
//                 vis[i-1][j] = true;
//             }

//             if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1) { // right
//                 q.push({{i, j+1}, time+1});
//                 vis[i][j+1] = true;
//             }

//             if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1) { // bottom
//                 q.push({{i+1, j}, time+1});
//                 vis[i+1][j] = true;
//             }

//             if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1) { // left-1
//                 q.push({{i, j-1}, time+1});
//                 vis[i][j-1] = true;
//             }
//         }

//         //check for fresh orange
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 if(grid[i][j] == 1 && !vis[i][j]) {
//                     return -1;
//                 }
//             }
//         }

//         return ans;
//     }
// };


//sort array

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        
        for(int i=0; i<indices.size(); i++) {
            int row = indices[i][0];
            int col = indices[i][1];

            for(int j=0; j<n; j++) {
                mat[row][j]++;
            }

            for(int j=0; j<m; j++) {
                mat[j][col]++;
            }
        }
        
        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((mat[i][j] %2) != 0) {
                    count++;
                }
            }
        }

        return count;
    }
};


class Solution {
public:
    string generateTheString(int n) {
        string s(n, 'p');
        if(n%2 == 0) {
            s[n-1] = 'z';
        }

        return s;
    }
};


// Course Schedule

class Solution {
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& edges) {
        vis[src] = true;
        recPath[src] = true;

        for(int i=0; i<edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src) {
                if(!vis[v]) {
                    if(isCycleDFS(v, vis, recPath, edges)) {
                        return true;
                    }
                } else if(recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(isCycleDFS(i, vis, recPath, edges)) {
                    return false;
                }
            }
        }

        return true;
    }
};


// couse schedule 2

class Solution {
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& edges) {
        vis[src] = true;
        recPath[src] = true;

        for(int i=0; i<edges.size(); i++) {
            int v = edges[i][0]; 
            int u = edges[i][1]; 

            if(src == u) {
                if(!vis[v]) {
                    if(isCycleDFS(v, vis, recPath, edges)) {
                        return true;
                    }
                } else if(recPath[v]) { //BACK EDGE -> cycle
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    void topoOrder(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& edges) {
        vis[src] = true;

        for(int i=0; i<edges.size(); i++) {
            int v = edges[i][0]; 
            int u = edges[i][1]; 

            if(src == u) {
                if(!vis[v]) {
                    topoOrder(v, vis, s, edges);
                }
            }
        }

        s.push(src);
    } 

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(isCycleDFS(i, vis, recPath, edges)) {
                    return ans;
                }
            }
        }

        // Topological sorted order - DAG
        stack<int> s;
        vis.assign(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                topoOrder(i, vis, s, edges);
            }
        }

        while(s.size() > 0) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};


// Flood Fill

class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int orgColor) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != orgColor || image[i][j] == newColor) {
            return;
        }

        image[i][j] = newColor;

        dfs(image, i-1, j, newColor, orgColor); //top
        dfs(image, i, j+1, newColor, orgColor); //right
        dfs(image, i+1, j, newColor, orgColor); //bottom
        dfs(image, i, j-1, newColor, orgColor); //left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};


// sort colors

class Solution {
public:
    void sortColors(vector<int>& nums) { // O(n)
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            } else if(nums[mid] == 1) {
                mid++;
            } else { // 2
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};


// Add two Integers

class Solution {
public:
    int sum(int num1, int num2) {
        int ans = num1 + num2;

        return ans;
    }
};



// add to array form integers


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        vector<int> ans;

        int i = num.size() - 1;

        while(i >= 0 || k > 0) {

            if(i >= 0) {
                k += num[i];
                i--;
            }

            ans.push_back(k % 10);
            k = k / 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};


// Maximum product of two digits

class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;

        while(n > 0) {
            int dig = n % 10;
            ans.push_back(dig);
            n = n/10;
        }

        int maxProd = INT_MIN;
        for(int i=0; i<ans.size(); i++) {
            for(int j=i+1; j<ans.size(); j++){
                int prod = ans[i]*ans[j];
                maxProd = max(maxProd, prod);
            }
        }

        return maxProd;
    }
};



//generate a string with characters that have odd counts

class Solution {
public:
    string generateTheString(int n) {
        string s(n, 'p');
        if(n%2 == 0) {
            s[n-1] = 'z';
        }

        return s;
    }
};


// 4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n; ) {

                int p = j+1, q = n-1;

                while(p < q) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                    if(sum < tar) {
                        p++;
                    } else if(sum > tar) {
                        q--;
                    } else{ // sum == tar
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;  q--;

                        while(p < q &&  nums[p] == nums[p-1]) p++;
                    }
                }

                j++;
                while(j < n && nums[j] == nums[j-1]) j++;
            }
        }

        return ans;
    }
};

//swap nodes in pair


// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head == NULL || head->next == NULL) {
//             return head;
//         }

//         ListNode* first = head;
//         ListNode* sec = head->next;
//         ListNode* prev = NULL;

//         while(first != NULL && sec != NULL) {
//            ListNode* third = sec->next;

//            sec->next = first;
//            first->next = third;

//            if(prev != NULL) {
//             prev->next = sec;
//            } else {
//             head = sec;
//            }

//            //update
//            prev = first;
//            first = third;
//            if(third != NULL) {
//             sec = third->next;
//            } else {
//             sec = NULL;
//            }
//         }

//         return head;
//     }
// };


// next permutations

class Solution {
public:
    void nextPermutation(vector<int>& A) { // TC O(n)  SC O(1)
        //step1 find the pivot
        int pivot = -1, n = A.size();
        for(int i=n-2; i>=0; i--){
            if(A[i] < A[i+1]) {
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            reverse(A.begin(), A.end()); //in place changes
            return;
        }

        //step2 : next larger element
        for(int i=n-1; i>pivot;  i--){
            if(A[i] > A[pivot]){
                swap(A[i], A[pivot]);
                break;
            }
        }

        //step3 : reverse (piv+1 to n-1)

        //reverse(A.begin() + pivot + 1, A.end());  // Alternate method to reverse

    
        int i=pivot+1, j=n-1;
        while(i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }

    }
};


//remove duplicates from sorted array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0;
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
         
        return i + 1;
    }
};


//reverse nodes in k group

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
//         int count = 0;

//         //check if nodes exixt
//         while(count < k) {
//             if(temp == NULL) {
//                 return head;
//             }
//             temp = temp->next;
//             count++;
//         }

//         //recursively call for rest of LL
//         ListNode* prevNode = reverseKGroup(temp, k);

//         //reverse current group
//         temp = head; count = 0;
//         while(count < k) {
//             ListNode* next = temp->next;
//             temp->next = prevNode;
//             prevNode = temp;
//             temp = next;

//             count++;
//         }

//         return prevNode;
//     }
// };



// leetcode 1192

class Solution {
public:
    int time;
    vector<int> dt, low;

    void dfs(int u, int parU, vector<vector<int>> &adj, vector<vector<int>> &cc) {
        dt[u] = low[u] = ++time;

        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];

            if(dt[v] == -1) {
                dfs(v, u, adj, cc);
                //update low
                low[u] = min(low[v], low[u]);

                //Bridge
                if(low[v] > dt[u]) {
                    cc.push_back({u, v});
                }
            } else if(v != parU) {
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //adj
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;
        dt.resize(n, -1);
        low.resize(n);

        vector<vector<int>> bridges;

        for(int i=0; i<n; i++) {
            if(dt[i] == -1) {
                dfs(i, -1, adj, bridges);
            }
        }

        return bridges;
    }
};