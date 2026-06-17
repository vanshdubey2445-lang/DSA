//  Given a Binary Search Tree, find sum of k smallest nodes in it. You may assume that k is always smaller than or equal to size of the tree.
// Examples:

// Input: k = 3
 
// Output: 22
// Explanation: Sum of 3 smallest elements are: 4 + 8 + 10 = 22
// Input: k = 2
  
// Output: 9
// Explanation: The sum of two smallest elements is 4+5=9

//Solution:-

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void ksum(Node *root,int &sum,int &k)
{
    if(!root)
    return;
    
    ksum(root->left,sum,k);
    k--;
    
    if(k>=0)
    sum+=root->data;
    
    if(k<=0)
    return;
    
    ksum(root->right,sum,k);
}

int sum(Node* root, int k) {
    
    int sum=0;
    ksum(root,sum,k);
    return sum;
}