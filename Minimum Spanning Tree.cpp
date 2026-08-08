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
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj[V];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>p;
        vector<bool>mst(V,0);
        vector<int>parent(V);
        
        int cost=0;
        p.push({0,{0,-1}});
        
        while(!p.empty())
        {
            int wt=p.top().first;
            int node=p.top().second.first;
            int par=p.top().second.first;
            p.pop();
            
            if(!mst[node])
            {
                mst[node]=1;
                cost+=wt;
                parent[node]=par;
                
                for(int j=0;j<adj[node].size();j++)
                {
                    if(!mst[adj[node][j][0]])
                    {
                        p.push({adj[node][j][1],{adj[node][j][0],node}});
                    }
                }
            }
        }
        
        return cost;
    }
};