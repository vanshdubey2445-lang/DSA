// Given a Binary tree. Find the preorder traversal of the tree without using recursion.

// Follow up: Try solving this with O(1) auxiliary space.


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
        left = right = NULL;
    }
};
class Solution {
  public:
    vector<int> preOrder(Node* root) {
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
                    ans.push_back(root->data);
                    curr->right=root;
                    root=root->left;
                }
                
                else
                {
                    curr->right=NULL;
                    root=root->right;
                }
                
            }
            
        }
        
        return ans;
        
    }
};