// You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

// let x be the sum of all elements currently in your array.
// choose index i, such that 0 <= i < n and set the value of arr at index i to x.
// You may repeat this procedure as many times as needed.
// Return true if it is possible to construct the target array from arr, otherwise, return false.

 

// Example 1:

// Input: target = [9,3,5]
// Output: true
// Explanation: Start with arr = [1, 1, 1] 
// [1, 1, 1], sum = 3 choose index 1
// [1, 3, 1], sum = 5 choose index 2
// [1, 3, 5], sum = 9 choose index 0
// [9, 3, 5] Done
// Example 2:

// Input: target = [1,1,1,2]
// Output: false
// Explanation: Impossible to create target array from [1,1,1,1].
// Example 3:

// Input: target = [8,5]
// Output: true

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//Solution:-

class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<long long>p;
        long long sum=0;
        for(long long i=0;i<target.size();i++)
        {
            p.push(target[i]);
            sum+=target[i];
        }

        long long maxelem,remsum,elem;
        while(p.top()!=1)
        {
            maxelem=p.top();
            p.pop();
            remsum=sum-maxelem;

            if(remsum<=0 || remsum >=maxelem)
            return 0;

           // elem=maxelem-remsum;//tle occured
           elem=maxelem % remsum;
           if(elem==0)
        {
            if(remsum!=1)
            return 0;

            else
            return 1;
        }

            sum=remsum+elem;
            p.push(elem);
        }

        return 1;
    }
};