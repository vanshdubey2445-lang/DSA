// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

// Examples:

// Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]


// Output: 3
// Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 
// Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]

// Output: 1
// Explanation: All of the nodes are connected to each other. So, there's only one SCC.
// Input: V = 2, E = 1, edges[][] = [[0, 1]]
// Output: 2
// Constraints:
// 1 ≤ V ≤ 106
// 0 ≤ E ≤ 106
// 0 ≤ edges[i][0], edges[i][1] < V

 

// Expected Complexities
// Time Complexity: O(V + E)
// Auxiliary Space: O(V + E)

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
  
  void topological(int node,vector<vector<int>> &adj ,vector<bool>&visited,stack<int>&s)
  {
      visited[node]=1;
      for(int j=0;j<adj[node].size();j++)
      {
          if(!visited[adj[node][j]])
          topological(adj[node][j],adj,visited,s);
      }
      
      s.push(node);
      
  }
  
  void dfs(int node,vector<vector<int>>&adj2,vector<bool>&visited)
  {
      visited[node]=1;
      
      for(int j=0;j<adj2[node].size();j++)
      {
          if(!visited[adj2[node][j]])
          dfs(adj2[node][j],adj2,visited);
      }
  }
  
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        
        stack<int>s;
        vector<bool>visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            topological(i,adj,visited,s);
        }
        
        vector<vector<int>>adj2(V);
        
        for(int i=0;i<V;i++)
        for(int j=0;j<adj[i].size();j++)
        {
            int u=i;
            int v=adj[i][j];
            
            adj2[v].push_back(u);
        }
        
        for(int i=0;i<V;i++)
        visited[i]=0;
        
        int scc=0;
        
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            if(!visited[node])
            {
                scc++;
                dfs(node,adj2,visited);
            }
        }
        
        return scc;
    }
};