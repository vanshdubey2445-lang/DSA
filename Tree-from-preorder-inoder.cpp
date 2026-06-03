// Given two arrays representing the inorder and preorder traversals of a binary tree, your task is to construct the binary tree and return its root.

// Note: The inorder and preorder traversals contain unique values, and every value present in the preorder traversal is also found in the inorder traversal.

// Examples:

// Input: inorder[] = [3, 1, 4, 0, 5, 2], preorder[] = [0, 1, 3, 4, 2, 5]
// Output: [0, 1, 2, 3, 4, 5]
// Explanation: The tree will look like

// Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
// Output: [1, 4, 3, 5, N, N, N, 2]
// Explanation: The tree will look like

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
  
  int find(vector<int>in,int target,int start,int end)
  {
      for(int i=start;i<=end;i++)
      {
          if(in[i]==target)
          return i;
      }
      return -1;
  }
  
  Node *tree(vector<int>in,vector<int>pre,int instart,int inend, int index)
  {
      if(instart>inend)
      return NULL;
      
      Node *root=new Node(pre[index]);
      int pos=find(in,pre[index],instart,inend);
      
      root->left=tree(in,pre,instart,pos-1,index+1);
      root->right=tree(in,pre,pos+1,inend,index+(pos-instart)+1);
      
      return root;
  }
    Node *buildTree(vector<int> &in, vector<int> &pre) {
        
        return tree(in,pre,0,pre.size()-1,0);
    }
};