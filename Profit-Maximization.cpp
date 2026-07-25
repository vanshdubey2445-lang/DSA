// Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

// Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.



// Problem Constraints
// 1 <= |A| <= 100000

// 1 <= B <= 1000000



// Input Format
// First argument is the array A.

// Second argument is integer B.



// Output Format
// Return one integer, the answer to the problem.



// Example Input
// Input 1:

// A = [2, 3]
// B = 3
// Input 2:

// A = [1, 4]
// B = 2


// Example Output
// Output 1:

// 7
// Output 2:

// 7

// solution:-

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int Solutionsolve(vector<int> &A, int B) {
    int sum=0;
    priority_queue<int>p;
    for(int i=0;i<A.size();i++)
    p.push(A[i]);
    
    while(B&&(!p.empty()))
    {
        sum+=p.top();
        
        if(p.top()-1)
        p.push(p.top()-1);
        
        p.pop();
        B--;
    }
    
    return sum;
}