// Given a singly linked list whose elements are sorted in ascending order, construct a height-balanced Binary Search Tree (BST) containing the same elements as the linked list. A height-balanced BST is defined as a binary tree in which the depth difference between the left and right subtrees of every node is at most 1.

// It is guaranteed that the linked list does not contain duplicate values.
// The middle element would always be the root. In case of even elements, pick the root as second mid as root.
// You need to return root of the tree, the preorder traversal is printed by the driver code to test your result.
// Examples:

// Input: Linked List: 1->2->3->4->5->6->7

// Output: 4 2 1 3 6 5 7
// Explanation: The BST formed using elements of the linked list is shown below.
       
// Hence, the preorder traversal of the tree is 4 2 1 3 6 5 7.
// Input: Linked List : 1->2->3
       
// Output: 2 1 3
// Explanation: The BST formed using elements of the linked list is -
        
// Hence, the preorder traversal of this tree is 2 1 3.

//Solution:-

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class LNode {
public:
    int data;
    LNode* next;

    LNode(int x) {
        data = x;
        next = nullptr;
    }
};

// Tree Node
class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  public:
  
  TNode *build(vector<int>&tree,int start,int end)
  {
      if(start>end)
      return NULL;
      
      int mid=start+(end-start+1)/2;
      
      TNode *root=new TNode(tree[mid]);
      root->left=build(tree,start,mid-1);
      root->right=build(tree,mid+1,end);
      
      return root;
  }
    TNode *sortedListToBST(LNode *head) {
        
        vector<int>tree;
        while(head)
        {
            tree.push_back(head->data);
            head=head->next;
        }
        
        return build(tree,0,tree.size()-1);
    }
};