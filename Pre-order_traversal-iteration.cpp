// Given a Binary tree. Find the preorder traversal of the tree without using recursion.


// Examples:

// Input: root = [1, 2, 3, 4, 5]

// Output: [1, 2, 4, 5, 3]
// Explanation:
// Preorder traversal (Root->Left->Right) of
// the tree is 1 2 4 5 3.
// Input: root = [8, 1, 5, N, 7, 10, 6, N, 10, 6]

// Output: [8, 1, 7, 10, 5, 10, 6, 6] 
// Explanation:
// Preorder traversal (Root->Left->Right) 
// of the tree is 8 1 7 10 5 10 6 6.

//solution:-

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
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        
        stack<Node*>s;
        s.push(root);
        vector<int>ans;
        while(!s.empty())
        {
            Node *temp=s.top();
            s.pop();
            ans.push_back(temp->data);
            
            if(temp->right)
            s.push(temp->right);
            
            if(temp->left)
            s.push(temp->left);
        }
        
        return ans;
    }
};