// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int k) {
        
        int start=0,end=nums.size()-1,mid,first=-1,last=-1;
        
        while(start<=end)
        {
            mid=start+(end-start)/2;

            if(nums[mid]==k)
            {
                first=mid;
                end=mid-1;
            }
            else if(nums[mid]<k)
            start=mid+1;

            else 
            end=mid-1;
        }

         start=0;end=nums.size()-1;

         while(start<=end)
        {
            mid=start+(end-start)/2;

            if(nums[mid]==k)
            {
                last=mid;
                start=mid+1;
            }
            else if(nums[mid]<k)
            start=mid+1;

            else 
            end=mid-1;
        }

        vector<int>a(2);
        a[0]=first;
        a[1]=last;

        return a;

        
    }
};