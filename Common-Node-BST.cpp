// Given the roots r1 and r2 of two Binary Search Trees (BSTs), find all nodes that are present in both trees (the intersection of the two BSTs).

// Return the common node values in sorted order.

// Examples:

// Input: r1 = [5, 1, 10, 0, 4, 7, N, N, N, N, N, N, 9], r2 = [10, 7, 20, 4, 9, N, N]
       
// Output: [4, 7, 9, 10]
// Input: r1 = [10, 2, 11, 1, 3, N, N], r2 = [2, 1, 3]

//  Output: [1, 2, 3]

//Solution:-
#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> findCommon(Node* r1, Node* r2) {
        
        vector<int>ans;
        stack<Node *>s1,s2;
        
        while(r1)
        {
            s1.push(r1);
            r1=r1->left;
        }
        
        while(r2)
        {
            s2.push(r2);
            r2=r2->left;
        }
        
        while(!s1.empty() && !s2.empty())
        {
            if(s1.top()->data==s2.top()->data)
            {
                ans.push_back(s1.top()->data);
                r1=s1.top()->right;
                s1.pop();
                
                r2=s2.top()->right;
                s2.pop();
            }
            
            else if(s1.top()->data>s2.top()->data)
            {
                r2=s2.top()->right;
                s2.pop();
            }
            
            else
            {
                r1=s1.top()->right;
                s1.pop();
            }
            
            while(r1)
            {
                s1.push(r1);
                r1=r1->left;
            }
            
            while(r2)
            {
                s2.push(r2);
                r2=r2->left;
            }
        }
        
        return ans;
    }
};