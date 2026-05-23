// Given the root of a binary tree, your task is to return its Preorder traversal.

// Note: A preorder traversal first visits the node, then visits the left child (including its entire subtree), and finally visits the right child (including its entire subtree).

// Examples:

// Input: root = [1, 4, N, 4, 2]
   
// Output: [1, 4, 4, 2]
// Explanation: The preorder traversal of the given binary tree is [1, 4, 4, 2]
// Input: root = [6, 3, 2, N, 1, 2, N]
    
// Output: [6, 3, 1, 2, 2] 
// Explanation: The preorder traversal of the given binary tree is [6, 3, 1, 2, 2] 

// solution:-

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:

  class Node
{
    public:
    int data;
    Node *left , *right;
    Node(int value)
    {
        data=value;
        left=right=NULL;
    }
};
  
  void pre(Node *root, vector<int>&ans)
{
    if(root==NULL)
    return ;
    
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}

    vector<int> preOrder(Node* root) {
        // code here
        vector<int>ans;
        pre(root,ans);
        return ans;
    }
};