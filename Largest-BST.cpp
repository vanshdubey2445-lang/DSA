// You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

// Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

// Examples :

// Input: root = [5, 2, 4, 1, 3]
// Root-to-leaf-path-sum-equal-to-a-given-number-copy
// Output: 3
// Explanation:The following sub-tree is a BST of size 3
// Balance-a-Binary-Search-Tree-3-copy
// Input: root = [6, 7, 3, N, 2, 2, 4]

// Output: 3
// Explanation: The following sub-tree is a BST of size 3:

//Solution 1:- the longer one......

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
  
  class box
  {
      public:
      bool bst;
      int size,max,min;
      
      box(int data)
      {
          bst=1;
          size=1;
          min=data;
          max=data;
      }
  };
  
  box * find(Node *root,int &totalsize)
  {
      if(!root->left && !root->right)
      {
          totalsize=max(totalsize,1);
          return new box(root->data);
      }
      
      else if(!root->left && root->right)
      {
          box * head=find(root->right,totalsize);
          if(head->bst && head->min > root->data)
          {
              head->size++;
              head->min=root->data;
              totalsize=max(totalsize,head->size);
              return head;
          }
          
          else
          {
             head->bst=0;
             return head;
          }
      }
      
      else if(root->left && !root->right)
      {
          box *head=find(root->left,totalsize);
          if(head->bst && head->max < root->data)
          {
              head->size++;
              head->max=root->data;
              totalsize=max(totalsize,head->size);
              return head;
          }
          
          else
          {
              head->bst=0;
              return head;
          }
      }
      
      else 
      {
          box *left=find(root->left,totalsize);
          box *right=find(root->right,totalsize);
          
          if(left->bst && right->bst && left->max <root->data && right->min >root->data)
          {
              box *head=new box(root->data);
              head->size+=left->size+right->size;
              head->max=right->max;
              head->min=left->min;
              totalsize=max(totalsize,head->size);
              return head;
          }
          
          else
          {
              left->bst=0;
              return left;
          }
      }
  }
    int largestBst(Node *root) {
        
        int totalsize=0;
        find(root,totalsize);
        return totalsize;
    }
};

//Solution 2:- the shorter one....

class Solution {
  public:
  
  class box
  {
      public:
      bool bst;
      int size,max,min;
      
      box()
      {
          bst=1;
          size=0;
          min=INT_MAX;
          max=INT_MIN;
      }
  };
  
  box *find(Node *root, int &totalsum)
  {
      if(!root)
      {
          return new box();
      }
      
      box *left=find(root->left,totalsum);
      box *right=find(root->right,totalsum);
      
      if(left->bst && right->bst && left->max <root->data && right->min>root->data)
      {
          box *head=new box();
          head->size=1+left->size+right->size;
          head->min=min(root->data,left->min);
          head->max=max(root->data,right->max);
          totalsum=max(totalsum,head->size);
          return head;
      }
      
      else
      {
          left->bst=0;
          return left;
      }
  }
    int largestBst(Node *root) {
    
        int totalsum=0;
        find(root,totalsum);
        return totalsum;
    }
};
