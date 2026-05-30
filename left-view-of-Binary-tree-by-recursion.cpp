// Given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

// Note: If the tree is empty, return an empty list.

// Examples :

// Input: root = [1, 2, 3, 4, 5, N, N]

// Output:[1, 2, 4]
// Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

// Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]

// Output: [1, 2, 4, 5]
// Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.

//Solution:-

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
  
  void lview(Node *root, int lvl, vector<int>&ans)
  {
      if(!root)return ;
      
      if(lvl==ans.size())
      ans.push_back(root->data);
      
      lview(root->left,lvl+1,ans);
      lview(root->right,lvl+1,ans);
      
  }
    vector<int> leftView(Node *root) {
        
        vector<int>ans;
        int lvl=0;
        
        lview(root, lvl, ans);
        return ans;
    }

};