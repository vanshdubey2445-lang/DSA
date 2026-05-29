// Given a binary tree (having distinct node values)root and two node values. Check whether or not the two nodes with values a and b are cousins.
// Note: Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Examples:

// Input:
//       1
//     /   \
//    2     3
// a = 2, b = 3
// Output: false
// Explanation: Here, nodes 2 and 3 are at the same level but have same parent nodes.
// Input:
//        1
//      /   \ 
//     2     3
//    /       \
//   5         4 
// a = 5, b = 4
// Output: True
// Explanation: Here, nodes 5 and 4 are at the same level and have different parent nodes. Hence, they both are cousins. 
// Input:
//           10
//         /    \
//       5       15
//      / \     /  \
//     3   7   12   20
// a = 7, b = 12
// Output: True
// Explanation: Here, nodes 7 and 12 are at the same level and have different parent nodes. Hence, they both are cousins. 

//solution:-

#include<iostream>
#include<queue>
using namespace std;

//here there are two methods in which the comments of method is a method that is not valid for every cases.


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
    // Function to check if two nodes are cousins in a tree
    bool parent(Node *root, int a, int b)
    {
        if(root==NULL)
        return 0;
        
        if(root->left && root->right)
        {
            if(root->left->data==a && root->right->data==b)
            return 1;
            
            if(root->right->data==a && root->left->data==b)
            return 1;
        }
            return parent(root->left,a,b) || parent(root->right,a,b);
        
    }
    
    bool isCousins(Node* root, int a, int b) {
        // write code here
        if(a==b)
        return false;
        
        queue<Node *>q;
        q.push(root);
        //int l1=-1,l2=-1;
        
        bool found1=false;
        bool found2=false;
        
       // int lvl=0;
        
        while(!q.empty())
        {
            int n=q.size();
            
            while(n--)
            {
                Node *temp=q.front();
                q.pop();
                
                if(temp->data==a)
                //l1=lvl;
                found1=true;
                
                if(temp->data==b)
                //l2=lvl; 
                found2=true;
                
                if(temp->left)
                q.push(temp->left);
                
                if(temp->right)
                q.push(temp->right);
            
            }
            
           // lvl++;
            
            // if(l1!=l2)
            // return 0;
            
            // if(l1!=-1)
            // break;
            
            if(found1&&found2)
            return !parent(root,a,b);
            
            if(found1||found2)
            return false;
            
        }
        
        //return !parent(root,a,b);
        return false;
        
    }
};