// You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find the total maximum profit earned by completing those jobs.

// Examples :

// Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20 + 40).
// Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
// Output: [2, 127]
// Explanation: Job1 and Job3 can be done with maximum profit of 127 (100 + 27).
// Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
// Output: [3, 100]
// Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
// Constraints:
// 1 ≤ deadline.size() = profit.size() ≤ 105
// 1 ≤ deadline[i] ≤ deadline.size()
// 1 ≤ profit[i] ≤ 500

// Expected Complexities
// Time Complexity: O(n log n)
// Auxiliary Space: O(n)

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//Solution:1:->
class Solution { //which i got runtime error due to t.c=o(n^2);
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        
        vector<pair<int,int>> jobs;
        
        for(int i=0;i<deadline.size();i++)
        jobs.push_back({profit[i],deadline[i]});
        
        sort(jobs.begin(),jobs.end(),greater<pair<int,int>>());
        
        
        int maxi=0;
        for(int i=0;i<deadline.size();i++)
        maxi=max(maxi,deadline[i]);
        
        vector<int>ans(2,0);
        
        vector<bool>task(maxi+1,0);
        
        for(int i=0;i<jobs.size();i++)
        {
            int p=jobs[i].first;
            int d=jobs[i].second;
            
            for(int j=d;j>0;j--)
            {
                if(!task[j])
                {
                    task[j]=1;
                    ans[0]++;
                    ans[1]+=p;
                    break;
                }
            }
        }
        
        return ans;
    }
};

//Solution:2->
class Solution {
  public:
  
  int find(int num, vector<int>&parent)
  {
      if(num==parent[num])
      return num;
      
      return parent[num]=find(parent[num],parent);
  }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        
        vector<pair<int,int>> jobs;
        
        for(int i=0;i<deadline.size();i++)
        jobs.push_back({profit[i],deadline[i]});
        
        sort(jobs.begin(),jobs.end(),greater<pair<int,int>>());
        
        
        int maxi=0;
        for(int i=0;i<deadline.size();i++)
        maxi=max(maxi,deadline[i]);
        
        vector<int>ans(2,0);
        
        vector<int>parent(maxi+1);
        for(int i=0;i<=maxi;i++)
        parent[i]=i;
        
        
        
        for(int i=0;i<jobs.size();i++)
        { 
            int slot=find(jobs[i].second,parent);

            if(slot>0)
            {
                ans[0]++;
                ans[1]+=jobs[i].first;
                parent[slot]=slot-1;
            }
        }
        
        return ans;
    }
};
