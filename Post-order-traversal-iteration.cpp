// Given a binary tree. Find the postorder traversal of the tree without using recursion. Return a list containing the postorder traversal of the tree, calculated without using recursion.

// Examples :

// Input:
//            1
//          /   \
//         2     3
//       /  \
//      4    5

// Output: 4 5 2 3 1
// Explanation: Postorder traversal (Left->Right->Root) of the tree is 4 5 2 3 1.
// Input:
//              8
//           /      \
//         1          5
//          \       /   \
//           7     10    6
//            \   /
//             10 6

// Output: 10 7 1 6 10 6 5 8 
// Explanation: Postorder traversal (Left->Right->Root) of the tree is 10 7 1 6 10 6 5 8 .

//solution:-

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
class Solution {
  public:
    vector<int> postOrder(Node* root) {
        
        stack<Node *>s;
        s.push(root);
        vector<int>ans;
        
        while(!s.empty())
        {
            Node *temp=s.top();
            s.pop();
            ans.push_back(temp->data);
            
            if(temp->left)
            s.push(temp->left);
            
            if(temp->right)
            s.push(temp->right);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};