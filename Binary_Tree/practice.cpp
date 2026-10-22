#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// same Tree 

// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p == NULL || q == NULL) {
//             return p == q;
//         }

//         bool isLeftSame = isSameTree(p->left, q->left);
//         bool isRightSame = isSameTree(p->right, q->right);

//         return (isLeftSame && isRightSame && (p->val == q->val));
//     }
// };

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

 //Subtree of Another Tree
// class Solution {
// public:
//     bool isIdentical(TreeNode* p, TreeNode* q) {
//         if(p == NULL || q == NULL) {
//             return p == q;
//         }

//         return (p->val == q->val 
//         && isIdentical(p->left, q->left)) 
//         && isIdentical(p->right, q->right);
//     }

//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(root == NULL || subRoot == NULL) {
//             return root == subRoot;
//         }

//         if(root->val == subRoot->val && isIdentical(root, subRoot)){
//             return true;
//         }

//         return isSubtree(root->left, subRoot) 
//         || isSubtree(root->right, subRoot);
//     }
// };


// First bad version binary search

// class Solution {
// public:
//     int firstBadVersion(int n) {
//         int low = 1, high = n;

//         while(low < high) {
//             int mid = low + (high - low)/2;

//             if(isBadVersion(mid)) {
//                 high = mid;
//             } else {
//                 low = mid + 1;
//             }
//         }

//         return low;
//     }
// };