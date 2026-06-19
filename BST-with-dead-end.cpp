// You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

// Your task is to determine whether the BST contains a dead end.

// Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

// Examples:

// Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

// Output: true
// Explanation: Node 1 is a Dead End in the given BST.
// Input: root[] = [8, 7, 10, 2, N, 9, 13]

// Output: true
// Explanation: Node 9 is a Dead End in the given BST.

//Solution:-

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node
{
    public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
  bool dead(Node *root,int lower,int upper)
  {
      if(!root)
      return 0;
      
      if(!root->left && !root->right)
      {
          if(root->data-lower==1 && upper-root->data==1)
          return 1;
          
          else
          return 0;
      }
      
     return dead(root->left,lower,root->data)||dead(root->right,root->data,upper);
  }
    bool isDeadEnd(Node *root) {
        
        int lower=0;
        int upper=INT_MAX;
       return dead(root,lower,upper);
    }
};