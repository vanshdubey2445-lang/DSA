// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

// Example 1:


// Input: root = [4,2,6,1,3]
// Output: 1
// Example 2:


// Input: root = [1,0,48,null,null,12,49]
// Output: 1
 
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

void mindiff(TreeNode *root,int &prev,int &ans)
{
    if(!root)
    return ;

    mindiff(root->left,prev,ans);
    if(prev!=INT_MIN)
    ans=min(ans,root->val-prev);
    prev=root->val;

    mindiff(root->right,prev,ans);
}
    int minDiffInBST(TreeNode* root) {
        int prev=INT_MIN;
        int ans=INT_MAX;
        mindiff(root,prev,ans);
        return ans;
    }


    



};