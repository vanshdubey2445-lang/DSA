// Given a root of a Binary Tree, your task is to return its Inorder Traversal.

// Note: An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).

// Examples:

// Input: root = [1, 2, 3, 4, 5]
            
// Output: [4, 2, 5, 1, 3]
// Explanation: The inorder traversal of the given binary tree is [4, 2, 5, 1, 3].
// Input: root = [8, 1, 5, N, 7, 10, 6, N, 10, 6]
              
// Output: [1, 7, 10, 8, 6, 10, 5, 6]
// Explanation: The inorder traversal of the given binary tree is [1, 7, 10, 8, 6, 10, 5, 6].

//solution:-

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

 void in(Node *root, vector<int>&ans)
  {
      if(root==NULL)
      return ;
      
      in(root->left,ans);
      ans.push_back(root->data);
      in(root->right,ans);
  }
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>ans;
        in(root,ans);
        return ans;
    }
};