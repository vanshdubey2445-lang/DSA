// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//solution:-

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        int prefixsum=0;
        m[0]=1;
        int total=0;

        for(int i=0;i<n;i++)
        {
            prefixsum+=nums[i];
            if(m.count(prefixsum-k))
            {
                total+=m[prefixsum-k];
                m[prefixsum]++;
            }

            else
            m[prefixsum]++;

        }

        return total;
    }
};