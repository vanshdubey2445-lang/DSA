// Given a Binary Tree of size n, You have to count leaves in it. For example, there are two leaves in the following tree


 

// Examples:

// Input:
// Given Tree is  

// Output: 3
// Explanation: Three leaves are 3, 5 and 1.
// Input:
// Given Tree is

// Output: 4
// Explanation: Four leaves are 20, 40, 65 and 80.
// Input:
// Given Tree is  

// Output: 3
// Explanation: Three leaves are 20, 27 and 40.

//solution:-

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    
    // void countleaf(Node *root, int &count)
    // {
    //     if(root==NULL)
    //     return ;
        
    //     if(!root->left && !root->right)
    //     {
    //         count++;
    //         return;
    //     }
        
    //     countleaf(root->left,count);
    //     countleaf(root->right,count);
    // }
    
    int countleaf(Node *root)
    {
        if(root==NULL)
        return 0;
        
         if(!root->left && !root->right)
         return 1;
         
         return countleaf(root->left)+countleaf(root->right);
    }
    
    int countLeaves(Node* root) {
        
        // int count=0;
        // countleaf(root , count);
        // return count;
        
        countleaf(root);
        
    }
};