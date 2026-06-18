// Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. The output will be inorder traversal of the constructed BST.

// Examples:

// Input: post[] = [1, 7, 5, 50, 40, 10]
// Output: [1, 5, 7, 10, 40, 50]
// Explanation:
// The BST for the given post order traversal is:
  
// Thus the inorder traversal of BST is: 1 5 7 10 40 50.
// Input: post[] = [2, 1, 3, 5]
// Output: [1, 2, 3, 5]
// Explanation:
// The BST for the given post order traversal is:
// 420046836  

//Solution:-

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
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
  
  Node *bst(vector<int>&post,int &index,int lower,int upper)
  {
      if(index==-1||post[index]<lower||post[index]>upper)
      return NULL;
      
      Node *root=new Node(post[index--]);
      root->right=bst(post,index,root->data,upper);
      root->left=bst(post,index,lower,root->data);
      
      return root;
  }
  
    Node* constructTree(vector<int>& post) {
        
        int index=post.size()-1;
        int lower=INT_MIN;
        int upper=INT_MAX;
        Node *root=bst(post,index,lower,upper);
        return root;
    }
};