// You are given n courses, labeled from 0 to n - 1 and a 2d array prerequisites[][] where prerequisites[i] = [x, y] indicates that we need to take course  y first if we want to take course x.

// Find the ordering of courses we should take to complete all the courses.

// Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. The Driver code will print true if you return any correct order of courses else it will print false. 

// Examples:

// Input: n = 3, prerequisites[][] = [[1, 0], [2, 1]]
// Output: true
// Explanation: To take course 1, you must finish course 0. To take course 2, you must finish course 1. So the only valid order is [0, 1, 2].
// Input: n = 4, prerequisites[][] = [[2, 0], [2, 1], [3, 2]]
// Output: true
// // Explanation: Course 2 requires both 0 and 1. Course 3 requires course 2. Hence, both [0, 1, 2, 3] and [1, 0, 2, 3] are valid.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &pre) {//bfs traversal
        // code here
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        if(!indeg[i])
        q.push(i);
        vector<int>ans;
        vector<int>temp;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(int j=0;j<adj[node].size();j++)
            {
                indeg[adj[node][j]]--;
                if(!indeg[adj[node][j]])
                q.push(adj[node][j]);
            }

        }
        
        return ans.size()==n? ans :temp;
        
        
    }
};