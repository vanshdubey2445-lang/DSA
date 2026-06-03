// Given two arrays representing the inorder and postorder traversals of a binary tree, your task is to construct the binary tree and return its root.

// Note: The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.

// Examples:

// Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, N, 8]
// Explanation: For the given inorder and postorder traversal of tree the resultant binary tree will be:

// Input: inorder[] = [9, 5, 2, 3, 4], postorder[] = [5, 9, 3, 4, 2]
// Output: [2, 9, 4, N, 5, 3]
// Explanation: The resultant binary tree will be: 


//Solution:-

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
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
  
  Node *tree(vector<int>in,vector<int>post,int instart,int inend,int index)
  {
      if(instart>inend)
      return NULL;
      
      Node *root= new Node(post[index]);
      int pos=find(in,post[index],instart,inend);
      
      root->right=tree(in,post,pos+1,inend,index-1);
      root->left=tree(in,post,instart,pos-1,index-(inend-pos)-1);
      
      return root;
  }
    Node *buildTree(vector<int> &in, vector<int> &post) {
        
        int n=post.size();
       return tree(in,post,0,n-1,n-1);
    }
};