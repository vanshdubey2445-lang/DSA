// Given a sorted array arr[] and a number target, find the number of occurrences of target in given array. 

// Examples:

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4
// Explanation: target = 2 occurs 4 times in the given array so the output is 4.
// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
// Output: 0
// Explanation: target = 4 is not present in the given array so the output is 0.
// Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
// Output: 3
// Explanation: target = 12 occurs 3 times in the given array so the output is 3.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& nums, int k) {
        // code here
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
        
        if(first==-1)
        return 0;
        else
        return (last-first)+1;
        
        
        
    }
};