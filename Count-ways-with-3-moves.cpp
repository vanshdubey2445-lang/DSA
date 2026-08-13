// A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Return the of count how many possible ways the child can run up the stairs.

// Examples:

// Input: n = 3
// Output: 4
// Explanation: The following are 4 different ways
// 1 step + 1 step + 1 step 
// 1 step + 2 steps 
// 2 steps + 1 step 
// 3 steps
// Input: n = 4
// Output: 7
// Explanation: Below are the 7 ways to reach 4th step:
// 1 step + 1 step + 1 step + 1 step
// 1 step + 2 steps + 1 step
// 2 step + 1 step + 1 step
// 1 step + 1 step + 2 steps
// 2 steps + 2 steps
// 3 steps + 1 step
// 1 step + 3 steps
// Input: n = 1
// Output: 1
// Constraints:
// 1 ≤ n ≤ 30

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(1)

#include<iostream>
#include<vector>
using namespace std;

//method1:-> by finding the no of ways from 0 to nth node;
//Solution:1->

class Solution {
  public:
  
    int count(int i,int n)
    {
        if(i==n)
        return 1;
        
        if(i>n)
        return 0;
        
        return count(i+1,n)+count(i+2,n)+count(i+3,n);
    }
    int countWays(int n) {
        return count(0,n);
    }
};


//Solution:2:->dp starts

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
        
        return dp[i]=count(i+1,n,dp)+count(i+2,n,dp)+count(i+3,n,dp);
    }
    int countWays(int n) {
        vector<int>dp(n+3,-1);
        return count(0,n,dp);
    }
};


//Solution:3:->
class Solution {
  public:
  
int countWays(int n) {

        vector<int>dp(n+3,-1);
        dp[n]=1;
        dp[n+1]=0;
        dp[n+2]=0;
        
        for(int i=n-1;i>=0;i--)
        dp[i]=dp[i+1]+dp[i+2]+dp[i+3];
        
        return dp[0];
        
    }
};


//Solution:4:-> Space optimization:->
class Solution {
  public:
  
    int countWays(int n) {
        
        int curr;
        int prev=1,prev2=0,prev3=0;
        
        for(int i=n-1;i>=0;i--)
        {
            curr=prev+prev2+prev3;
            prev3=prev2;
            prev2=prev;
            prev=curr;
        }
        
        return curr;
        
    }
};


// method:->2 no of ways to 5th from 0th node
//Solution:-1:->

class Solution {
  public:
  
    int ways(int n)
    {
        if(n<=1)
        return 1;
        
        if(n==2)
        return 2;
        
        return ways(n-1)+ways(n-2)+ways(n-3);
    }
    
    int countWays(int n) {
        // your code here
        return ways(n);
        
    }
};


//Solution:2:-> Dp:->
class Solution {
  public:
  
    int ways(int n,vector<int>&dp)
    {
        if(n<=1)
        return 1;
        
        if(n==2)
        return 2;
        
        if(dp[n]!=-1)
        return dp[n];
        
        return dp[n]=ways(n-1,dp)+ways(n-2,dp)+ways(n-3,dp);
    }
    
    int countWays(int n) {
        // your code here
        vector<int>dp(n+1,-1);
        return ways(n,dp);
        
    }
};


//Solution:3:->
class Solution {
  public:
  
int countWays(int n) {
        // your code here
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        
        return dp[n];
        
    }
};


// Solution:4:->
class Solution {
  public:
  
    
    
    int countWays(int n) {
        // your code here
        if(n<=1)
        return 1;
        
        if(n==2)
        return 2;
        
        int curr;
        int prev=2,prev2=1,prev3=1;
        
        for(int i=3;i<=n;i++)
        {
            curr=prev+prev2+prev3;
            prev3=prev2;
            prev2=prev;
            prev=curr;
        }
        
        return curr;
        
    }
};