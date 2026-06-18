// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

// Example 1:


// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
// Example 2:

// Input: preorder = [1,3]
// Output: [1,null,3]

//Solution:-

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    TreeNode *bst(vector<int>&pre,int &index,int lower,int upper)
    {
        if(index==pre.size()||pre[index]<lower||pre[index]>upper)
        return NULL;

        TreeNode *root=new TreeNode(pre[index++]);
        root->left=bst(pre,index,lower,root->val);
        root->right=bst(pre,index,root->val,upper);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        int lower=INT_MIN;
        int upper=INT_MAX;
        int index=0;
        TreeNode* root=bst(pre,index,lower,upper);
        return root;
    }
};