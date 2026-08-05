// Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E weighted directed edges represented by a 2D array edges[][], where edges[i] = [u, v, wt] denotes a directed edge from vertex u to vertex v with weight wt, find the shortest distance from the source vertex 0 to every other vertex.

// Return an array of size V, where the i-th element represents the shortest distance from the source vertex 0 to vertex i. If a vertex is not reachable from the source, return -1 for that vertex.

// Examples :

// Input: V = 4, edges = [[0,1,2], [0,2,1]]
// Output: [0, 2, 1, -1]
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
// Input: V = 6, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
// Output: [0, 2, 3, 6, 1, 5]
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

class Solution {
  public:
  
  void dfs(int node,vector<pair<int,int>>adj[],stack<int>&s,vector<bool>&visited)
  {
      visited[node]=1;
      for(int i=0;i<adj[node].size();i++)
      {
          if(!visited[adj[node][i].first])
          dfs(adj[node][i].first,adj,s,visited);
      }
      
      s.push(node);
  }
  
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            
            adj[u].push_back(make_pair(v,weight));
        }
        
        vector<int>dist(V,INT_MAX);
        stack<int>s1;
        vector<bool>visited(V,0);
        dfs(0,adj,s1,visited);
        dist[0]=0;
        
        while(!s1.empty())
        {
            int node=s1.top();
            s1.pop();
            
            for(int j=0;j<adj[node].size();j++)
            {
                int neigh=adj[node][j].first;
                int weight=adj[node][j].second;
                
                dist[neigh]=min(dist[neigh],weight+dist[node]);
            }
        }
        
        for(int i=0;i<V;i++)
        if(dist[i]==INT_MAX)
        dist[i]=-1;
        
        return dist;
    }
};