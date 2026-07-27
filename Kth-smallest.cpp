// Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.
// Note: The kth smallest element is determined based on the sorted order of the array.

// Examples :

// Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
// Output: 5
// Explanation: 4th smallest element in the given array is 5.
// Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
// Output: 7
// Explanation: 3rd smallest element in the given array is 7.

//solution:-

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        
        priority_queue<int>p;
        for(int i=0;i<k;i++)
        p.push(arr[i]);
        
        for(int i=k;i<arr.size();i++)
        {
            if(arr[i]<p.top())
            {
                p.pop();
                p.push(arr[i]);
            }
        }
        
        return p.top();
    }
};