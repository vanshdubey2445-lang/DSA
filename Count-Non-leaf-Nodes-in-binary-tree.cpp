// Given a Binary Tree of size n, your task is to return the count of all the non-leaf nodes of the given binary tree.

// Example:

// Input: 
// Image
// Output: 2
// Explanation: Nodes 1 and 2 are the only non leaf nodes.
// Input: 
//           8
//         /   \
//        3     9
//       / \
//      1   6
//         / \
//        4   7
// Output: 3
// Explanation: Nodes 8, 3 and 6 are the only non leaf nodes.
// Input: 
//           10
//         /    \
//       5       20
//      / \     /  \
//     3   7   15   25
// Output: 3
// Explanation: Nodes 10, 5 and 20 are the only non leaf nodes.

//solution:-

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
class Solution {
  public:
  int countnode(Node *root)
  {
      if(root==NULL)
      return 0;
      
      if(!root->left && !root->right)
      return 0;
      
      return 1 + countnode(root->left) + countnode(root->right);
  }
    int countNonLeafNodes(Node* root) {
        // Code here
        countnode(root);
    }
};