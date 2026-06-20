// Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original Binary search tree(BST).
 
// Examples :
// Input: root = [10, 5, 8, 2, 20]
     
// Output: 1
       

// Explanation: The nodes 20 and 8 were swapped. 
// Input: root = [5, 10, 20, 2, 8]
     
// Output: 1 
     
// Explanation: The nodes 10 and 5 were swapped.

//Solution:-

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    void correctBST(Node* root) {
    
        Node *curr=NULL;
        Node *first=NULL;
        Node *second=NULL;
        Node *last=NULL,*present=NULL;
        
        while(root)
        {
            if(!root->left)
            {
                last=present;
                present=root;
                if(last && last->data>present->data)
                {
                    if(!first)
                    first=last;
                    second=present;
                }
                root=root->right;
            }
            
            else
            {
                curr=root->left;
                while(curr->right && curr->right!=root)
                curr=curr->right;
                
                if(!curr->right)
                {
                    curr->right=root;
                    root=root->left;
                }
                
                else
                {
                    curr->right=NULL;
                    last=present;
                    present=root;
                    
                    if(last && last->data>present->data)
                    {
                        if(!first)
                        first=last;
                        second=present;
                    }
                    root=root->right;
                }
            }
        }
        
        int num=first->data;
        first->data=second->data;
        second->data=num;
    }
};