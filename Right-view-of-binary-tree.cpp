// Given the root of a binary Tree. Return the right view of the binary tree. The right view of a Binary Tree is the set of nodes visible when the tree is viewed from the right side.

// Examples :

// Input: root = [1, 2, 3, N, N, 4, 5]
//      2_2
// Output: [1, 3, 5]
// Input: root = [1, 2, 3, 4, N, N, N, N, 5]
//      Right-view-in-binary-tree-1
// Output: [1, 3, 4, 5]

// Input: root = [3]    
// Output: [3]

//solution:-

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Here i have solved it by two methods:-
//1.By level order traversal
//2.By Recurison
//the commented lines is the code of level order traversal

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
  
  void lview(Node *root, int lvl, vector<int>&ans)
  {
      if(!root)return ;
      
      if(lvl==ans.size())
      ans.push_back(root->data);
      
      lview(root->right,lvl+1,ans);
      lview(root->left,lvl+1,ans);
      
  }
  
    vector<int> rightView(Node *root) {
        //  code here
        vector<int>ans;
        int lvl=0;
        
        lview(root, lvl, ans);
        
        
        // if(!root)
        // return ans;
        
        // queue<Node*>q;
        // q.push(root);
        
        // while(!q.empty())
        // {
        //     int n=q.size();
        //     ans.push_back(q.front()->data);
            
        //     while(n--)
        //     {
        //         Node *temp= q.front();
        //         q.pop();
                
        //         if(temp->right)
        //         q.push(temp->right);
                
        //         if(temp->left)
        //         q.push(temp->left);
        //     }
        // }
        
        return ans;
    }
};