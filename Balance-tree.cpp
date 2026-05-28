// Given the root of a binary tree, determine if it is height-balanced or not.

// Note: A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

// Examples:

// Input: root = [10, 20, 30, 40, 60]
    
// Output: true 
// Explanation: The height difference between the left and right subtrees at all nodes is at most 1. Hence, the tree is balanced.
// Input: root = [1, 2, 3, 4, N, N, N, 5]
   
// Output: false
// Explanation: The height difference between the left and right subtrees at node 2 is 2, which exceeds 1. Hence, the tree is not balanced.

//Solution:-

#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


int height(Node *root, bool &valid)
{
    if(!root)
    return 0;
    
    int l= height(root->left,valid);
    int r=height(root->right,valid);
    
    if(abs(l-r)>1)
    valid=0;
    
    return 1+max(l,r);
}
class Solution {
  public:
    bool isBalanced(Node* root) {
        // code here
        bool valid=1;
        height(root,valid);
        return valid;
    }
};