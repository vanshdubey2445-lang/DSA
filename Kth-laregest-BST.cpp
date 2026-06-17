// Given a Binary Search Tree. Your task is to complete the function which will return the kth largest element without doing any modification in the Binary Search Tree.

// Examples:

// Input:
//       4
//     /   \
//    2     9
// k = 2 
// Output: 4
// Explanation: 2nd Largest element in BST is 4
// Input:
//        9
//         \ 
//           10
// k = 1
// Output: 10
// Explanation: 1st Largest element in BST is 10
// Input:
//       4
//     /   \
//    2     9
// k = 3 
// Output: 2
// Explanation: 3rd Largest element in BST is 2

//Solution:-

#include<iostream>
#include<vector>    
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
  void klargest(Node *root,int &sum,int &k)
  {
      if(!root)
      return ;
      
      klargest(root->right,sum,k);
      k--;
      if(k==0)
      sum=root->data;
      
      if(k<=0)
      return ;
      
      klargest(root->left,sum,k);
  }
    int kthLargest(Node *root, int k) {
        
        int sum=0;
        klargest(root,sum,k);
        return sum;
    }
};