// You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

// Note : A subarray is a continuous part of an array.

// Examples:

// Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
// Output: 11
// Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.
// Input: arr[] = [-2, -4]
// Output: -2
// Explanation: The subarray [-2] has the largest sum -2.
// Input: arr[] = [5, 4, 1, 7, 8]
// Output: 25
// Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.

//solution:-

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        
        int i,Maxi=INT_MIN,Prefix=0,n=arr.size();
        
        for(i=0;i<n;i++)
        {
            Prefix+=arr[i];
            Maxi=max(Prefix,Maxi);
            if(Prefix<0)
            Prefix=0;
            
        }
        return Maxi;
                
                
    }
};