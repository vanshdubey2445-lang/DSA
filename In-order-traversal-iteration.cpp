// Given a binary tree. Find the inorder traversal of the tree without using recursion.

// Examples

// Input:  

// Output: 4 2 5 1 3
// Explanation: Inorder traversal (Left->Root->Right) of the tree is [4, 2, 5, 1, 3].
// Input:

// Output: 1 7 10 8 6 10 5 6
// Explanation: Inorder traversal (Left->Root->Right) of the tree is [1, 7, 10, 8, 6, 10, 5, 6].

#include<iostream>
#include<vector>
#include<stack>
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
        stack<Node*>s;
        stack<bool>visited;
        visited.push(0);
        s.push(root);
        vector<int>ans;
        
        while(!s.empty())
        {
            Node *temp=s.top();
            s.pop();
            bool flage=visited.top();
            visited.pop();
            
            if(!flage)
            {
                if(temp->right)
                {
                    s.push(temp->right);
                    visited.push(0);
                }
                
                s.push(temp);
                visited.push(1);
                
                if(temp->left)
                {
                    s.push(temp->left);
                    visited.push(0);
                }
            }
            
            else
            ans.push_back(temp->data);
        }
        
        return ans;
        
    }
};