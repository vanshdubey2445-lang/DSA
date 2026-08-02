// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]



// Output: true
// Explanation: The diagram clearly shows a cycle 0 → 1 → 2 → 0
// Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]


// Output: false
// Explanation: no cycle in the graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Solution:-1->dfs traversal
class Solution {
  public:
  
  bool dfs(int node,vector<vector<int>>&adj,vector<bool>&path,vector<bool>&visited)
  {
      path[node]=1;
      visited[node]=1;
      
      for(int i=0;i<adj[node].size();i++)
      {
          if(path[adj[node][i]])
          return 1;
          
          if(visited[adj[node][i]])
          continue;
          
          if(dfs(adj[node][i],adj,path,visited))
          return 1;
      }
      
      path[node]=0;
      return 0;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
         vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && dfs(i,adj,path,visited))
            return 1;
        }
        
        return 0; 

    }
};


//Solution:-2->bfs traversal->kahn's algorithm
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
         vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        vector<int>indeg(V,0);
        // vector<int>ans;
        queue<int>q;
        int count=0;  //to remove the extra space for using the ans array
        
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
            //ans.push_back(node);
            count++;
            
            for(int i=0;i<adj[node].size();i++)
            {
                indeg[adj[node][i]]--;
                if(!indeg[adj[node][i]])
                q.push(adj[node][i]);
            }
        }
        
       // int count=ans.size();
        if(count!=V)
        return 1;
        else
        return 0;
        
    }
};