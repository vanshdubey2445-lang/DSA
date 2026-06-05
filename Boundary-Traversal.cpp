// Given a root of a Binary Tree, return its boundary traversal in the following order:

// Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.

// Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

// Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

// Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output: [1, 2, 4, 8, 9, 6, 7, 3]
// Explanation:

// Input: root = [1, N, 2, N, 3, N, 4, N, N] 
// Output: [1, 4, 3, 2]
// Explanation:

// Left boundary: [1] (as there is no left subtree)
// Leaf nodes: [4]
// Right boundary: [3, 2] (in reverse order)
// Final traversal: [1, 4, 3, 2]

//Solution:-

#include<iostream>
#include<vector>
#include<queue>
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


class Solution {
  public:
  
  void leftsub(Node *root,vector<int>&ans)
{
    if(!root||!root->left&&!root->right)
    return ;
    
    ans.push_back(root->data);
    if(root->left)
    leftsub(root->left,ans);
    else
    leftsub(root->right,ans);
}

void leaf(Node *root,vector<int>&ans)
{
    if(!root)
    return;
    
    if(!root->left&&!root->right)
    {
        ans.push_back(root->data);
        return;
    }
    
    leaf(root->left,ans);
    leaf(root->right,ans);
}

void rightsub(Node *root,vector<int>&ans)
{
    if(!root||!root->left&&!root->right)
    return;
    
    if(root->right)
    rightsub(root->right,ans);
    else
    rightsub(root->left,ans);
    
    ans.push_back(root->data);
}
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int>ans;
        ans.push_back(root->data);
        leftsub(root->left,ans);
        if(root->left||root->right)
        leaf(root,ans);
        rightsub(root->right,ans);
        
        return ans;
    }
};