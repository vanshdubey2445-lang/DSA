// Given a binary tree, find the sum of values of all the nodes. 

// Examples:

// Input: root = [15, 10, 20, 8, 12, 16, 25]

// Output: 106
// Explanation: The sum of all the nodes is 15 + 10 + 20 + 8 + 12 + 16 + 25 = 106
// .
// Input: root = [1, 3, 2]

// Output: 6
// Explanation: The sum of all the nodes is 1 + 2 + 3 = 6.
// Input: root = [1, 2, N, 4, N]

// Output: 7
// Explanation: The sum of all the nodes is 1 + 2 + 4 = 7.

//solution:-


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
  
//   int sum(Node *root, int &count)
//   {
//       if(root==NULL)
//       return 0;
      
//       count+=root->data;
//       sum(root->left,count);
//       sum(root->right,count);
      
//       return count;
//   }

int total(Node *root)
{
    if(root==NULL)
    return 0;
    
    return root->data + total(root->left) + total(root->right);
}
    int sumBT(Node* root) {
        
        //int count=0;
        //sum(root,count);
        
        total(root);
    }
};