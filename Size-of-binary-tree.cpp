// Given the root of a binary tree, return the size of the tree. The size of a binary tree is the total number of nodes in the tree.

// Examples:

// Input:      

// Output:  3
// Explanation: There are 3 nodes in the given binary tree, so its size is 3.
// Input:

// Output: 6
// Explanation: There are 6 nodes in the given binary tree, so its size is 6.

//solution:-
//here i have use two methods to solve this question with two diiferent functions.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
//   int totalnode(Node *root)
//   {
//       if(root==NULL)
//       return 0;
      
//       return 1 + totalnode(root->left) + totalnode(root->right);
//   }

void total(Node *root, int &count)
{
    if(root==NULL)
    return;
    
    count++;
    total(root->left,count);
    total(root->right,count);
}
    int getSize(Node* root) {

        //totalnode(root);
        int count=0;
        total(root, count);
        return count;
    }
};