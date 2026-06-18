// Given an array arr[ ] consisting of distinct integers, check if the given array can represent preorder traversal of a BST.

// Examples :

// Input: arr[] = [2, 4, 3]
// Output: true
// Explaination: Given arr[] can represent preorder traversal of following BST:
 
// Input: arr[] = [2, 4, 1]
// Output: false
// Explaination: Given arr[] cannot represent preorder traversal of a BST.

//Solution:-

#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;

//solution 1:-(Stack)

class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        
        int n=arr.size();
        stack<int>lower,upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int left,right;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<lower.top())
            return 0;
            
            while(arr[i]>upper.top())
            {
                lower.pop();
                upper.pop();
            }
            
            int left=lower.top();
            int right=upper.top();
            lower.pop();
            upper.pop();
            
            //right
            lower.push(arr[i]);
            upper.push(right);
            
            //left
            lower.push(left);
            upper.push(arr[i]);
        }
        
        return 1; 
        
    }
};

//Solution 2:-(Recursion)

class Solution {
  public:
  
  void bst(vector<int>&arr,int &index,int lower,int upper,int n)
  {
      if(index==n||arr[index]<lower||arr[index]>upper)
      return ;
      
      int val=arr[index++];
      
      bst(arr,index,lower,val,n);
      bst(arr,index,val,upper,n);
      
  }
  
    bool canRepresentBST(vector<int> &arr) {
        
        int n=arr.size();
        int index=0;
        bst(arr,index,INT_MIN,INT_MAX,n);
        
        return index==n;
    }
};