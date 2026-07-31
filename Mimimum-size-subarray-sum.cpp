// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//solution:-

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total=INT_MAX;
        int start=0,end=0,n=nums.size(),sum=0;

        while(end<n)
        {
            sum+=nums[end];
            
            while(sum>=target && start<=end)
            {
                total=min(total,end-start+1);
                sum-=nums[start++];
            }

            end++;
        }
        
        return total==INT_MAX ? 0: total;
    }
};