
// Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

// Find the maximum number of chocolates that kid can eat in A units of time.

// NOTE: 

// floor() function returns the largest integer less than or equal to a given number.
// Return your answer modulo 109+7


// Problem Constraints
// 1 <= A <= 105
// 1 <= |B| <= 105
// 1 <= Bi <= INT_MAX


// Input Format
// First argument is an integer A.

// Second argument is an integer array B of size N.



// Output Format
// Return an integer denoting the maximum number of chocolates that kid can eat in A units of time.



// Example Input
// Input 1:

//  A = 3
//  B = [6, 5]
// Input 2:

//  A = 5
//  b = [2, 4, 6, 8, 10]


// Example Output
// Output 1:

//  14
// Output 2:

//  33

//solution:-

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int Solutionnchoc(int A, vector<int> &B) {
    
    int n=B.size();
    priority_queue<int>p;
    for(int i=0;i<n;i++)
    p.push(B[i]);
    
    long long choclate=0;
    while(A&&(!p.empty()))
    {
        choclate+=p.top();
        if(p.top()/2)
        p.push(p.top()/2);
        
        p.pop();
        A--;
    
    }
    
    return choclate % 1000000007;
    
}
