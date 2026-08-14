// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

#include<iostream>
#include<vector>
using namespace std;

// Solution:1:-> By taking extra spaces 
class Solution {
public:

    int robb(vector<int>&nums)
    {
        int n=nums.size();

        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0],nums[1]);

        int curr,prev=max(nums[0],nums[1]),prev2=nums[0];

        for(int i=2;i<n;i++)
        {
            curr=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curr;
        }

        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0],nums[1]);
        
        vector<int>a1(n-1);
        vector<int>a2(n-1);

        for(int i=0;i<n-1;i++)
        a1[i]=nums[i];

        for(int i=1;i<n;i++)
        a2[i-1]=nums[i];

        int curr1=robb(a1);
        int curr2=robb(a2);

        return max(curr1,curr2);
    }
};


// Solution:2:->Without taking any extra spaces
class Solution {
public:

int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0],nums[1]);

        int curr1,prev=max(nums[0],nums[1]),prev2=nums[0];
        curr1=prev;
        for(int i=2;i<n-1;i++)
        {
            curr1=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curr1;
        }

        int curr2;
        prev=max(nums[1],nums[2]),prev2=nums[1];
        curr2=prev;
        for(int i=3;i<n;i++)
        {
            curr2=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curr2;
        }

        return max(curr1,curr2);
    }
};