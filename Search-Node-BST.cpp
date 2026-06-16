// Given the root of a Binary Search Tree and a node value key, return true if the node with value key is present in the BST; otherwise, return false.

// Examples:

// Input: root = [6, 2, 8, N, N, 7, 9], key = 8
    
// Output: true
// Explanation: 8 is present in the BST as right child of root.
// Input: root = [16, 12, 18, 10, N, 17, 19], key = 14
    
// Output: false
// Explanation: 14 is not present in the BST

//Solution:-

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    bool search(Node* root, int target) {
        
    if(!root)
    return 0;

    if(root->data==target)
    return 1;

    if(root->data>target)
    return search(root->left,target);
    else
    return search(root->right,target);
    }
};