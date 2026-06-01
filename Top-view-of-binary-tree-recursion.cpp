// You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Note:

// Return the nodes from the leftmost node to the rightmost node.
// If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
// Examples:

// Input: root = [1, 2, 3]
// Output: [2, 1, 3]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
// Input: root = [10, 20, 30, 40, 60, 90, 100]
// Output: [40, 20, 10, 30, 100]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.

//Solution:-

#include<iostream>
#include<vector>
#include<queue>
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
 void find(Node *root, int pos, int &l, int &r)
 {
     if(!root)
     return ;
     
     l=min(l,pos);
     r=max(r,pos);
     
     find(root->left,pos-1,l,r);
     find(root->right,pos+1,l,r);
 }
 
 void tview(Node *root, int pos, vector<int>&ans,vector<int>&level,int l)
 {
     if(!root)
     return;
     
     if(level[pos]>l)
     {
         ans[pos]=root->data;
         level[pos]=l;
     }
     
     tview(root->left,pos-1,ans,level,l+1);
     tview(root->right,pos+1,ans,level,l+1);
     
 }
  
    vector<int> topView(Node *root) {
        
        int l=0, r=0;
        find(root,0,l,r);
        vector<int>ans(r-l+1);
        vector<int>level(r-l+1,INT_MAX);
        tview(root,-1*l,ans,level,0);
        
        return ans;
    }
};