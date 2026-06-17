// Given the root of a binary tree. Check whether it is a BST or not.

// A BST is defined as follows:

// The left subtree of a node contains only nodes with data less than the node's data.
// The right subtree of a node contains only nodes with data greater than the node's data.
// Both the left and right subtrees must also be binary search trees.
// Examples:

// Input: root = [2, 1, 3, N, N, N, 5]


// Output: true 
// Explanation: The left subtree of every node contains smaller data and right subtree of every node contains greater data. Hence, the tree is a BST.
// Input: root = [2, N, 7, N, 6, N, 9] 



// Output: false 
// Explanation: Since the node to the right of node with data 7 has lesser value 6, hence it is not a valid BST.
// Input: root = [10, 5, 20, N, N, 9, 25]


// Output: false
// Explanation: The node with data 9 present in the right subtree has lesser key value than root node 10.

//Solution 1:-

#include<iostream>
#include<vector>
#include<climits>
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
  
  void inorder(Node *root, vector<int>&ans)
  {
      if(!root)
      return ;
      
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
  
    bool isBST(Node* root) {
        vector<int>ans;
        inorder(root,ans);
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]<=ans[i-1])
            return 0;
        }
        
        return 1;
        
    }
};

//Solution 2:-

class Solution {
  public:
  
  bool bst(Node *root,int &prev)
  {
      if(!root)
      return 1;
      
      bool l= bst(root->left,prev);
      if(l==0)
      return 0;
      
      if(root->data<=prev)
      return 0;
      
      prev=root->data;
      
      return bst(root->right,prev);
  }
  
    bool isBST(Node* root) {
        
        int prev=INT_MIN;
        return bst(root,prev);
        
    }
};