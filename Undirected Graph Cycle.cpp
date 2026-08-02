// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

// Note: The graph can have multiple component.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation: 
 
// 1 -> 2 -> 0 -> 1 is a cycle.
// Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
// Output: false
// Explanation: 
 
// No cycle in the graph.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Solution 1:- //DFS traversal

class Solution {
  public:
  
  bool dfs(int node,int parent,vector<vector<int>>&edges,vector<bool>&visited)
  {
      visited[node]=1;
      
      for(int i=0;i<edges[node].size();i++)
      {
          if(parent==edges[node][i])
          continue;
          
          if(visited[edges[node][i]])
          return 1;
          
          if(dfs(edges[node][i],node,edges,visited))
          return 1;
      }
      
      return 0;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool>visited(V,0);
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,-1,adj,visited))
                return 1;
            }
        }
        
        return 0;
    }
};


//Solution 2:- BFS traversal

class Solution {
  public:
  
  bool bfs(int vertex,vector<vector<int>>& adj,vector<bool>&visited)
  {
      visited[vertex]=1;
      queue<pair<int,int>>q;
      q.push(make_pair(vertex,-1));
      
      while(!q.empty())
      {
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          
          for(int i=0;i<adj[node].size();i++)
          {
              if(parent==adj[node][i])
              continue;
              
              if(visited[adj[node][i]])
              return 1;
              
              visited[adj[node][i]]=1;
              q.push(make_pair(adj[node][i],node));
          }
      }
      
      return 0;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool>visited(V,0);
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(bfs(i,adj,visited))
                return 1;
            }
        }
        
        return 0;
    }
};