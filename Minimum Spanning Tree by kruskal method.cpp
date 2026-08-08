// Given a weighted, undirected, and connected graph with V vertices and a 2D array edges[][], where each element edges[i] = [u, v, w] represents an edge between vertices u and v with weight w, return the sum of the weights of all edges in the graph's Minimum Spanning Tree (MST).

// Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
 
// Output: 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.
// Input: V = 2, E = 1, Edges = [[0 1 5]]

 

// Output: 5 
// Explanation: Only one Spanning Tree is possible which has a weight of 5.
// Constraints:
// 2 ≤ V ≤ 1000
// V-1 ≤ E ≤ (V*(V-1))/2
// 1 ≤ w ≤ 1000
// The graph is connected and doesn't contain self-loops & multiple edges.

// Expected Complexities
// Time Complexity: O((V + E) log V)
// Auxiliary Space: O(V + E)

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  int findparent(int u,vector<int>&parent)
  {
      if(u==parent[u])
      return u;
      
      return parent[u]=findparent(parent[u],parent);
  }
  
  void unionbyrank(int u , int v , vector<int>&parent, vector<int>&rank)
  {
      int pu=findparent(u,parent);
      int pv=findparent(v,parent);
      
      if(rank[pu]>rank[pv])
      parent[pv]=pu;
      
      else if(rank[pv]>rank[pu])
      parent[pu]=pv;
      
      else
      {
          parent[pv]=pu;
          rank[pu]++;
      }
  }
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<int>>adj[V];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<pair<int,pair<int,int>>>temp;
        for(int i=0;i<V;i++)
        for(int j=0;j<adj[i].size();j++)
        temp.push_back({adj[i][j][1],{i,adj[i][j][0]}});
        
        
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());
        // for(int i=0;i<V;i++)
        // for(int j=0;j<adj[i].size();j++)
        // p.push({adj[i][j][1],{i,adj[i][j][0]}});
        
        vector<int>parent(V);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++)
         parent[i]=i;
        
        int cost=0;
        int e=0;
        while(!p.empty())
        {
            int wt=p.top().first;
            int u=p.top().second.first;
            int v=p.top().second.second;
            p.pop();
            
            if(findparent(u,parent)!=findparent(v,parent))
            {
                cost+=wt;
                unionbyrank(u,v,parent,rank);
                e++;
            }
            
            if(e==V-1)
            break;
        }
        
        return cost;
    }
};