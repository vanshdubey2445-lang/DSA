// Given the root of a Binary Tree, find the vertical traversal of the tree starting from the leftmost level to the rightmost level.

// Note: If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, N, 8, N, 9, N, 10, 11, N]
                    
// Output: [[4], [2], [1, 5, 6, 11], [3, 8, 9], [7], [10]]
// Explanation: The below image shows the horizontal distances used to print vertical traversal starting from the leftmost level to the rightmost level.
     
// Input: root = [1, 2, 3, 4, 5, N, 6]
     
// Output: [[4], [2], [1, 5], [3], [6]]
// Explanation: From left to right the vertical order will be [[4], [2], [1, 5], [3], [6]]

#include<iostream>
#include<vector>
#include<queue>
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
  
  int find(Node *root,int pos,int &l,int &r)
  {
      if(!root)
      return NULL;
      
      l=min(l,pos);
      r=max(r,pos);
      
      find(root->left,pos-1,l,r);
      find(root->right,pos+1,l,r);
  }
    vector<vector<int>> verticalOrder(Node *root) {
        
        int l=0,r=0;
        int pos=find(root,0,l,r);
        vector<vector<int>>positive(r+1);
        vector<vector<int>>negative(abs(l)+1);
        queue<Node*>q;
        queue<int>index;
        q.push(root);
        index.push(0);
        
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            pos=index.front();
            index.pop();
            
            if(pos>=0)
            positive[pos].push_back(temp->data);
            else
            negative[abs(pos)].push_back(temp->data);
            
            if(temp->left)
            {
                q.push(temp->left);
                index.push(pos-1);
            }
            
            if(temp->right)
            {
                q.push(temp->right);
                index.push(pos+1);
            }
            
        }
            vector<vector<int>>ans;
            
            for(int i=abs(l);i>=1;i--)
            ans.push_back(negative[i]);
            
            for(int i=0;i<=r;i++)
            ans.push_back(positive[i]);
        
        return ans;
        
    }
};