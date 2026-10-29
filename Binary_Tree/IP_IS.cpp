#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// find inorder Successor and inorder Predecessor

// Node* rightMostInleftSubtree(Node* root) {
//     Node* ans;

//     while(root != NULL) {
//         ans = root;
//         root = root->right;
//     }

//     return ans;
// }

// Node* leftMostInRightSubtree(Node* root) {
//     Node* ans;

//     while(root != NULL) {
//         ans = root;
//         root = root->left;
//     }

//     return ans;
// }

// vector<int> getPredSucc(Node* root, int key) {
//     Node* curr = root;
//     Node* pred = NULL;
//     Node* succ = NULL;

//     while(curr != NULL) {
//         if(key < curr->data) {
//             succ = curr;
//             curr = curr->left;
//         } else if(key > curr->data) {
//             pred = curr;
//             curr = curr->right;
//         } else {
            
//             if(curr->left != NULL) {
//                 //inorder pred
//                 pred = rightMostInleftSubtree(curr->left);
//             }

//             if(curr->right != NULL) {
//                 //inorder succ
//                 succ = leftMostInRightSubtree(curr->right);
//             }

//             break;
//         }
//     }

//     return {pred->data, succ->data};
// }


// int main() {
//     Node* root = new Node(6);
//     root->left = new Node(4);
//     root->right = new Node(8);
//     root->left->left = new Node(1);
//     root->left->right = new Node(5);
//     root->right->left = new Node(7);
//     root->right->right = new Node(9);

//     int key = 6;
//     vector<int> ans = getPredSucc(root, key);

//     cout << "predecessor: " << ans[0] << endl;
//     cout << "successor: " << ans[1] << endl;
// }



// Largest BST in binary tree return size

// 1> By BruteForce Approach

int countNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

bool isValidBST(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }

    if(min != NULL && root->data <= min->data) {
        return false;
    }

    if(max != NULL && root->data >= max->data) {
        return false;
    }

    return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
}

int largestBSTSubtree(Node* root) {
    if(root == NULL) {
        return 0;
    }

    //agar current subtree BST ha
    if(isValidBST(root, NULL, NULL)) {
        return countNodes(root);
    }

    //otherwise, left aur right subtree check karo
    return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
}


int main() {
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << "Largest BST size: "
         << largestBSTSubtree(root) << endl;

    return 0;
}