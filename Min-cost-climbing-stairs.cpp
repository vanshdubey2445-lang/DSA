// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

 

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.
 

// Constraints:

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

#include<iostream>
#include<vector>
using namespace std;

// Solution:1:->TLE
class Solution {
public:

    int ways(int n,vector<int>&cost)
    {
        if(n<=1)
        return 0;

        return min(cost[n-1]+ways(n-1,cost),cost[n-2]+ways(n-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        return ways(n,cost);
    }
};


//Solution:2:->dp
class Solution {
public:

    int ways(int n,vector<int>&cost,vector<int>&dp)
    {
        if(n<=1)
        return 0;

        if(dp[n]!=-1)
        return dp[n];

        return dp[n]=min(cost[n-1]+ways(n-1,cost,dp),cost[n-2]+ways(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return ways(n,cost,dp);
    }
};


// Solution:3:-> Bottom to top appraoch
class Solution {
public:

int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[0]=0,dp[1]=0;

        for(int i=2;i<=n;i++)
        dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);

        return dp[n];
    }
};


//Solution:4:-> space optimization
class Solution {
public:

int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int curr,prev=0,prev1=0;

        for(int i=2;i<=n;i++)
        {
            curr=min(cost[i-1]+prev,cost[i-2]+prev1);
            prev1=prev;
            prev=curr;
        }

        return curr;
    }
};