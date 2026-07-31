// You are given an array arr[] of integers. Find the total count of subarrays with their sum equal to 0.

// Examples:

// Input: arr[] = [0, 0, 5, 5, 0, 0]
// Output: 6
// Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].
// Input: arr[] = [6, -1, -3, 4, -2, 2, 4, 6, -12, -7]
// Output: 4
// Explanation: The 4 subarrays are [-1, -3, 4], [-2, 2], [2, 4, 6, -12], 
// and [-1, -3, 4, -2, 2]
// Input: arr[] = [0]
// Output: 1
// Explanation: The only subarray is [0].

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
    
    int n=arr.size();
    int total=0;
    //prefix sum and count
    unordered_map<int,int>m;
    int prefixsum=0;
    m[0]=1;
    
    for(int i=0;i<n;i++)
    {
        prefixsum+=arr[i];
        if(m.count(prefixsum))
        {
            total+=m[prefixsum];
            m[prefixsum]++;
        }
        
        else
        m[prefixsum]=1;
    }
    
    return total;
    }
};

   //trying by my own logic;
   //int n=arr.size();
    //     vector<int>pre;
    //     pre[0]=arr[0];
    //     for(int i=1;i<n;i++)
    //     {
    //         pre[i]+=pre[i-1]+arr[i];
    //     }
        
    //     for(int i=0;i<n;i++)
    //     {
            
    //     }
    // }
    