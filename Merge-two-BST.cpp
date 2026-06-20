// You are given the root of two BSTs, you have to merge this two BST and return the in-order traversal of the new BST.

// Examples: 

// Input: root1 = [3, 1, 5], root2 = [4, 2, 6]

// Output: [1, 2, 3, 4, 5, 6]
// Explanation: After merging and sorting the two BST we get [1, 2, 3, 4, 5, 6].
// Input: root1 = [8, 2, 10, 1, N], root2 = [5, 3, N, 0, N] 

// Output: [0, 1, 2, 3, 5, 8, 10]
// Explanation: After merging and sorting the two BST we get [0, 1, 2, 3, 5, 8, 10].

//Solution:-

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
  public:
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
  
  void inorder(Node *root,vector<int>&ans)
  {
      if(!root)
      return ;
      
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
    vector<int> merge(Node *r1, Node *r2) {
        
        vector<int>ans1;
        vector<int>ans2;
        inorder(r1,ans1);
        inorder(r2,ans2);
        vector<int>ans;
        int i=0,j=0;
        
        while(i<ans1.size() && j<ans2.size())
        {
            if(ans1[i]<ans2[j])
            ans.push_back(ans1[i++]);
            else
            ans.push_back(ans2[j++]);
        }
        
        while(i<ans1.size())
        ans.push_back(ans1[i++]);
        
        while(j<ans2.size())
        ans.push_back(ans2[j++]);
        
        
        return ans;
    }
};