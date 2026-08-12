// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

 

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
// Example 3:

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

// Constraints:

// 0 <= n <= 30

#include<iostream>
#include<vector>
using namespace std;

//1st method:->
class Solution {
public:
    int fib(int n) {
      
      if(n<=1)
      return n;

      return fib(n-1)+fib(n-2);

        
    }
};

//2nd method:-> here Dynamic Programming starts..
class Solution {
public:

    int fibo(int n,vector<int>&dp)
    {
        if(n<=1)
        return n;

        if(dp[n]!=-1)
        return dp[n];

        return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return fibo(n,dp);


    }
};


//3rd Method:->
class Solution {
public:

    int fib(int n) {

        if(n<=1)
        return n;

        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];

        return dp[n];

    }
};


//4th method:->
class Solution {
public:

    int fib(int n) {

        if(n<=1)
        return n;

        int curr,prev=0,prev2=1;

        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev=prev2;     
            prev2=curr;
        }

        return curr;


    }
};