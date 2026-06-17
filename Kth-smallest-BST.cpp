// Given a binary search tree, write a function to find the kth smallest element in the tree.
// NOTE: You may assume 1 <= k <= Total number of nodes in BST


// Input Format
// The first argument is the root node of the binary tree.
// The second argument B is an integer equal to the value of k.


// Output Format
// Return the value of the kth smallest node.


// Example Input
//   2
//  / \
// 1   3


// and k = 2



// Example Output
// 2


// Example Explanation
// As 2 is the second smallest element in the tree.

//Solution:-

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 
 void ksmallest(TreeNode *root,int &sum,int &k)
 {
     if(!root)
     return ;
     
     ksmallest(root->left,sum,k);
     k--;
     
     if(k==0)
     sum=root->val;
     
     if(k<=0)
     return ;
     
     ksmallest(root->right,sum,k);
 }
 
int kthsmallest(TreeNode* root, int k) {
    int sum=0;
    ksmallest(root,sum,k);
    return sum;
}
