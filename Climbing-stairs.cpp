// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 

// Constraints:

// 1 <= n <= 45

#include<iostream>
#include<vector>
using namespace std;

//Solution:-1:-> time limit exceeded
class Solution {
public:
    int count(int i,int n)
    {
        if(i==n)
        return 1;

        if(i>n)
        return 0;

        return count(i+1,n)+count(i+2,n);
    }

    int climbStairs(int n) {
        return count(0,n);
    }
};

//Solution:2->dp->
class Solution {
public:
    int count(int i,int n,vector<int>&dp)
    {
        if(i==n)
        return 1;

        if(i>n)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        return dp[i]=count(i+1,n,dp)+count(i+2,n,dp);
    }

    int climbStairs(int n) {

        vector<int>dp(n+2,-1);

        return count(0,n,dp);
    }
};


//Solution:->3:-//dp->bottom up approach
class Solution {
public:
    
    int climbStairs(int n) {

        vector<int>dp(n+2,-1);

        dp[n]=1;
        dp[n+1]=0;

        for(int i=n-1;i>=0;i--)
        dp[i]=dp[i+1]+dp[i+2];

        return dp[0];
    }
};

//Solution:-4:-> space optimization
class Solution {
public:
    
    int climbStairs(int n) {

       int curr,next=1,next2=0;

       for(int i=n-1;i>=0;i--)
       {
            curr=next+next2;
            next2=next;
            next=curr;
       }

       return curr;
    }
};

//Method 2:- by applying logic of no.of ways to reach 5th pos from 0th pos
//Solution:1:->TLE
class Solution {
public:

    int count(int i)
    {
        if(i<=1)
        return 1;

        return count(i-1)+count(i-2);
    }
    int climbStairs(int n) {
        
        return count(n);
    }
};

//Solution:2:->//dp
class Solution {
public:

    int count(int i,vector<int>&dp)
    {
        if(i<=1)
        return 1;

        if(dp[i]!=-1)
        return dp[i];

        return dp[i]= count(i-1,dp) + count(i-2,dp);
    }
    int climbStairs(int n) {
        
        vector<int>dp(n+1,-1);
        return count(n,dp);
    }
};

//Solution:3:->bottom to top
class Solution {
public:

    
    int climbStairs(int n) {
        
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];

        return dp[n];
    }
};

//Solution:4:->Space optimization
class Solution {
public:

    
    int climbStairs(int n) {
        
       int curr=1, prev=1, prev2=1;

        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }

        return curr;
    }
};