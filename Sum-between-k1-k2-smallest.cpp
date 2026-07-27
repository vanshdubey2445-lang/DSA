// Given an array arr[] of positive integers and two integers k1 and k2, find the sum of all array elements whose values lie between the k1-th smallest and the k2-th smallest (both k1th and k2th smallest are not included) of the array.

// Examples :

// Input: arr[] = [20, 8, 22, 4, 12, 10, 14], k1 = 3, k2 = 6
// Output: 26
// Explanation: 3rd smallest is 10 and 6th smallest is 20. Sum of all between k1-th and k2-th is 12 + 14 = 26.
// Input: arr[] = [1, 2, 3, 4, 5], k1 = 1, k2 = 5
// Output: 9
// Explanation: 1st smallest is 1 and 5th smallest is 5. Sum of all between k1-th and k2-th is 2 + 3 + 4 = 9.
// Input: arr[] = [5, 6, 7], k1 = 2, k2 = 3
// Output: 0
// Explanation: The 2nd smallest is 6 and the 3rd smallest is 7. Since there are no strictly between 6 and 7, the required sum is 0.

//solution:-

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        
        int n=arr.size();
        int s=0,v=0;
        priority_queue<int>p;
        priority_queue<int>q;
        
        for(int i=0;i<k1;i++)
        p.push(arr[i]);
        
        for(int j=0;j<k2-1;j++)
        q.push(arr[j]);
        
        for(int i=k1;i<n;i++)
        {
            if(arr[i]<p.top())
            {
                p.pop();
                p.push(arr[i]);
            }
        }
        
        for(int j=k2-1;j<n;j++)
        {
            if(arr[j]<q.top())
            {
                q.pop();
                q.push(arr[j]);
            }
        }
        
        while(!p.empty())
        {
            s+=p.top();
            p.pop();
        }
        
        while(!q.empty())
        {
            v+=q.top();
            q.pop();
        }
        
        return v-s;
    }
};