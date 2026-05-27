// Given the root of a binary tree, your task is to find the maximum depth of the tree.

// Note: The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.

// Examples:

// Input: root = [12, 8, 18, 5, 11]

// Output: 2
// Explanation: One of the longest path from the root(node 12) goes through node 8 to node 5, which has 2 edges.
// Input: root = [1, 2, 3, 4, N, 10, 5, N, N, N, N, 6, 7]

// Output: 3
// Explanation: The longest path from the root(node 1) to a leaf node 6 with 3 edges.

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


class Solution {
  public:
  
  int h(Node *root)
  {
      if(root==NULL)
        return -1;
        
        return 1+max(h(root->left),h(root->right));
  }
    int height(Node* root) {
        // code here
        
        h(root);
        
    }
};