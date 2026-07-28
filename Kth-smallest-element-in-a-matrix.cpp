// Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Examples:
// Input: mat[][] = [[16, 28, 60, 64], k = 3
//                 [22, 41, 63, 91],
//                 [27, 50, 87, 93],
//                 [36, 78, 87, 94]]
// Output: 27
// Explanation: 27 is the 3rd smallest element.
// Input: mat[][] = [[10, 20, 30, 40], k = 7
//                 [15, 25, 35, 45],
//                 [24, 29, 37, 48],
//                 [32, 33, 39, 50]] 
// Output: 30
// Explanation: 30 is the 7th smallest element.

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//solution:-

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n=mat.size();
        vector<pair<int,pair<int,int>>>temp;
        
        for(int i=0;i<n;i++)
        {
            temp.push_back(make_pair(mat[i][0],make_pair(i,0)));
        }
        //create min heap;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());
        
        int ans;
        pair<int,pair<int,int>>element;
        int i,j;
        
        while(k--)
        {
            element=p.top();
            p.pop(); 
            ans=element.first;
            i=element.second.first;
            j=element.second.second;
            
            if(j+1<n)
            p.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
        }
        
        return ans;
        
        
    }
};
