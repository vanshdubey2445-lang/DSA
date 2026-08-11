// Given n tasks numbered from 0 to n - 1 and a list of p prerequisite pairs pre[][], where each pair [a, b] means that task b must be completed before task a, determine whether it is possible to complete all the tasks.

// Return true if all tasks can be finished; otherwise, return false.

// Examples:

// Input: n = 4, pre[][] = [[1,0],[2,1],[3,2]]
// Output: true
// Explanation: To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1, and to do task 3 you should have finished task 2. So it is possible.
// Input: n = 2, pre[][] = [[1,0],[0,1]]
// Output: false
// Explanation: To do task 1 you should have completed task 0, and to do task 0 you should have finished task 1. So it is impossible.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    bool isPossible(int n, vector<pair<int, int>>& pre) { //bfs trversal
        // code here
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i].second].push_back(pre[i].first);
            indeg[pre[i].first]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        if(!indeg[i])
        q.push(i);
        
        int count=0;   //to check the topological sort
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            
            for(int j=0;j<adj[node].size();j++)
            {
                indeg[adj[node][j]]--;
                if(!indeg[adj[node][j]])
                q.push(adj[node][j]);
            }
        }
        
        return count==n;
    }
};