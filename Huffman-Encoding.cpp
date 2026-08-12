// Given a string s of distinct characters and their corresponding frequency f[ ] i.e. character s[i] has f[i] frequency.

// Build the Huffman tree and return all the huffman codes in preorder traversal of the tree.

// Note: While merging, if two nodes have the same value (frequency), then the node whose subtree contains the character that appears earlier in the string s will be taken on the left of the Binary Tree and the other one to the right. Otherwise, the node with smaller value will be taken on the left of the subtree and the other one to the right.

// Examples:

// Input: s = "abcdef", f[] = [5, 9, 12, 13, 16, 45]
// Output: [0, 100, 101, 1100, 1101, 111]
// Explanation:

// HuffmanCodes will be:
// f : 0
// c : 100
// d : 101
// a : 1100
// b : 1101
// e : 111
// Constraints:
// 1 ≤ s.size() = f.size() ≤ 26

// Expected Complexities
// Time Complexity: O(n log n)
// Auxiliary Space: O(n)

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  class Node
  {
      public:
      int freq;
      char c;
      int index;
      Node *left,*right;
      
      Node(int frequency,char name,int i)
      {
          freq=frequency;
          c=name;
          index=i;
          left=right=NULL;
          
      }
  };
  
  class comp{
      public:
      bool operator()(Node *a , Node *b)
      {
          if(a->freq != b->freq)
          return a->freq > b->freq;
          
          return a->index > b->index;
      }
  };
  
  void preorder(Node* root,string &temp,vector<string>&ans)
  {
      if(!root)
      return ;
      
      if(!root->left && !root->right)
      {
          ans.push_back(temp);
          return;
      }
      
      temp.push_back('0');
      preorder(root->left,temp,ans);
      temp.pop_back();
      
      temp.push_back('1');
      preorder(root->right,temp,ans);
      temp.pop_back();
      
  }
  
    vector<string> huffmanCodes(string &s, vector<int> f) {
        
        priority_queue<Node *,vector<Node *>,comp>p;
        int n= s.size();
        
        if(n==1)
        return {"0"};
        
        
        for(int i=0;i<s.size();i++)
        {
            p.push(new Node(f[i],s[i],i));
        }
        
        while(p.size()>1)
        {
            Node *first=p.top();
            p.pop();
            
            Node *second=p.top();
            p.pop();
            
            int newindex=min(first->index , second->index);
            
            Node *root=new Node(first->freq+second->freq,'$',newindex);
            root->left=first;
            root->right=second;
            p.push(root);
        }
        
        Node*root=p.top();
        p.pop();
        
        vector<string>ans;
        string temp;
        
        preorder(root,temp,ans);
        
        return ans;
    }
};