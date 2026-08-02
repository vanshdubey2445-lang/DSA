// Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

// Examples:

// Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
// [3, 2, 1, 0]
// [1, 2, 3, 0]
// [2, 3, 1, 0]
// Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]

// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
// [4, 5, 0, 1, 2, 3]
// [5, 2, 4, 0, 1, 3]

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

//Solution:-1->DFS traversal
class Solution {
  public:
  
  void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s)
  {
      visited[node]=1;
      
      for(int j=0;j<adj[node].size();j++)
      {
          if(!visited[adj[node][j]])
          dfs(adj[node][j],adj,visited,s);
      }
      
      s.push(node);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        stack<int>s;
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            dfs(i,adj,visited,s);
        }
        
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};


//Solution:- 2-> BFS Traversal->kahn's algorithm
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int>ans;
        vector<int>indeg(V,0);
        queue<int>q;
        
        for(int i=0;i<V;i++)
        for(int j=0;j<adj[i].size();j++)
        indeg[adj[i][j]]++;
        
        for(int i=0;i<V;i++)
        if(!indeg[i])
        q.push(i);
            
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                ans.push_back(node);
                
                for(int j=0;j<adj[node].size();j++)
                {
                    indeg[adj[node][j]]--;
                    if(indeg[adj[node][j]]==0)
                    q.push(adj[node][j]);
                }
            }
            
            return ans;
        
    }
};