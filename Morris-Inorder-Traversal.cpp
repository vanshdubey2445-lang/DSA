// Given a binary tree. Find the inorder traversal of the tree without using recursion.

// Examples

// Input:  

// Output: 4 2 5 1 3
// Explanation: Inorder traversal (Left->Root->Right) of the tree is [4, 2, 5, 1, 3].
// Input:

// Output: 1 7 10 8 6 10 5 6
// Explanation: Inorder traversal (Left->Root->Right) of the tree is [1, 7, 10, 8, 6, 10, 5, 6].

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
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>ans;
        while(root)
        {
            if(!root->left)
            {
                ans.push_back(root->data);
                root=root->right;
            }
            
            else
            {
                Node *curr=root->left;
                while(curr->right&&curr->right!=root)
                curr=curr->right;
                
                if(curr->right==NULL)
                {
                    curr->right=root;
                    root=root->left;
                }
                
                else
                {
                    curr->right=NULL;
                    ans.push_back(root->data);
                    root=root->right;
                }
                
            }
            
        }
        
        return ans;
        
    }
};