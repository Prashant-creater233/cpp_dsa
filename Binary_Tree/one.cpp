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

static int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); //LEFT
    root->right = buildTree(preorder); // RIGHT

    return root;
}

//preorder
void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//inorder traversal
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}

//postorder

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}


//level order
// void levelOrder(Node* root) {
//     queue<Node*> q;

//     q.push(root);

//     while(q.size() > 0) {
//         Node* curr = q.front();
//         q.pop();

//         cout << curr->data << " ";

//         if(curr->left != NULL) {
//             q.push(curr->left);
//         }

//         if(curr->right != NULL) {
//             q.push(curr->right);
//         }
//     }

//     cout << endl;
// }

// if we print levelwise



void levelOrder(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }

        cout << curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }

        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout << endl;
}

// int main() {
//     vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

//     Node* root = buildTree(preorder);
//     // cout << root->data << endl;
//     // cout << root->left->data << endl;
//     // cout << root->right->data << endl;

//     // preOrder(root);
//     // cout << endl;

//     // inorder(root);
//     // cout << endl;

//     // postorder(root);
//     // cout << endl;

//     levelOrder(root);

//     return 0;
// }



// Height of a Tree

// int height(Node* root) {
//     if(root == NULL) {
//         return 0;
//     }

//     int leftHt = height(root->left);
//     int rightHt = height(root->right);
//     return max(leftHt, rightHt) + 1;
// }

// // count the total no of nodes in BT
// int count(Node* root) {
//     if(root == NULL) {
//         return 0;
//     }

//     int leftCount = count(root->left);
//     int rightCount = count(root->right);
//     return leftCount + rightCount + 1;
// }


// // Sum of nodes
// int sum(Node* root) {
//     if(root == NULL) {
//         return 0;
//     }

//     int leftSum = sum(root->left);
//     int rightSum = sum(root->right);
//     return leftSum + rightSum + root->data;
// }


// int main() {
//     vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
//     Node* root = buildTree(preorder);

//     cout << "height : " << height(root) << endl;
//     cout << "Count : " << count(root) << endl;
//     cout << "Sum : " << sum(root) << endl;

//     return 0;
// }



// Transform to Sum Tree

int sumTree(Node* root) { // O(n)
    if(root == NULL) {
        return 0;
    }

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;

    return root->data;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout << "before conversion : ";
    preOrder(root);
    cout << endl;

    sumTree(root);

    cout << "after conversion : ";
    preOrder(root);
    cout << endl;

    return 0;
}






























// BST 

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

// Node* insert(Node* root, int val) {
//     if(root == NULL) {
//         return new Node(val);
//     }

//     if(val < root->data) {
//         root->left = insert(root->left, val);
//     } else {
//         root->right = insert(root->right, val);
//     }

//     return root;
// }

// Node* builtBST(vector<int> arr) {
//     Node* root = NULL;

//     for(int val : arr) {
//         root = insert(root, val);
//     }

//     return root;
// }

// void inorder(Node* root) {
//     if(root == NULL) {
//         return;
//     }

//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// bool search(Node* root, int key) { //O(height)
//     if(root == NULL) {
//         return false;
//     }

//     if(root->data == key) {
//         return true;
//     }

//     if(key < root->data) {
//         return search(root->left, key);
//     } else {
//         return search(root->right, key);
//     }
// }

// Node* getInorderSuccessor(Node* root) { // left most node in right subtree
//     while(root != NULL && root->left != NULL) {
//         root = root->left;
//     }

//     return root;
// }

// Node* delNode(Node* root, int key) { // key => val to delete
//     if(root == NULL) {
//         return NULL;
//     }

//     if(key < root->data) {
//         root->left = delNode(root->left, key);
//     } else if(key > root->data) {
//         root->right = delNode(root->right, key);
//     }  else {
//         // key == root
//         if(root->left == NULL) {
//             Node* temp = root->right;
//             delete root;
//             return temp;
//         } else if(root->right == NULL) {
//             Node* temp = root->left;
//             delete root;
//             return temp;
//         } else { //2 children
//             Node* IS = getInorderSuccessor(root->right);
//             root->data = IS->data;
//             root->right = delNode(root->right, IS->data);
//         }
//     }

//     return root;
// }

// int main() {
//     vector<int> arr = {3, 2, 1, 5, 6, 4};

//     Node* root = builtBST(arr);
//     cout << "before : ";
//     inorder(root);
//     cout << endl;

//     // cout << search(root, 5) << endl;

//     delNode(root, 6);

//     cout << "after : ";
//     inorder(root);
//     cout << endl;

//     return 0;
// }