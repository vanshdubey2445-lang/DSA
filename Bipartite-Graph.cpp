// Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

// A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

// All edges connect vertices from one set to vertices in the other set.
// No edges exist between vertices within the same set.
// Examples:

// Input: V = 3, edges[][] = [[0, 1], [1,2]]
// Bipartite-Graph
// Output: true
// Explanation: The given graph can be colored in two colors so, it is a bipartite graph.
// Input: V = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]




// Output: false 
// Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs. 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Solution 1:- //BFS traversal

class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>c(V,-1);
        queue<int>q;
        q.push(0);
        c[0]=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int i=0;i<adj[node].size();i++)
            {
                if(c[adj[node][i]]==-1)
                {
                    c[adj[node][i]]=(c[node]+1)%2;
                    q.push(adj[node][i]);
                }
                
                else
                {
                    if(c[node]==c[adj[node][i]])
                    return 0;
                }
            }
        }
        
        return 1; 
    }
};


//Solution:- 2->DFS traversal
class Solution {
  public:
  
  bool dfs(int node,vector<vector<int>>&adj,vector<int>&c)
  {
      for(int i=0;i<adj[node].size();i++)
      {
          if(c[adj[node][i]]==-1)
          {
              c[adj[node][i]]=(c[node]+1)%2;
              
              if(!dfs(adj[node][i],adj,c)) //if it doesnt return true
              return 0;
          }
          
          else
          {
              if(c[node]==c[adj[node][i]])
              return 0;
          }
          
      }
      
      return 1;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>c(V,-1);
        c[0]=0;
        return dfs(0,adj,c);
    }
};