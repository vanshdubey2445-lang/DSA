// Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, where edges[i] = [u, v] denotes an undirected edge between vertex u and vertex v, given two vertices src and dest, find the length of the shortest path from src to dest. If there is no path between src and dest, return -1.

// Note: All edges have a unit weight of 1.

// Examples :

// Input: V = 9, edges[][] = [[0, 1], [0, 3], [1, 2], [3, 4], [4, 5], [2, 6], [5, 6], [6, 7], [6, 8], [7, 8]], src = 0, dest = 8
// Output: 4
// Explanation: One of the shortest paths from vertex 0 to vertex 8 is 0 -> 1 -> 2 -> 6 -> 8, which contains 4 edges.

// Input: V = 4, edges[][]= [[0, 3], [1, 3]], src = 3, dest = 2
// Output: -1
// Explanation: There is no path between vertices 3 and 2.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<int>adj[V];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>dist(V,-1);
        vector<bool>visited(V,0);
        
        queue<int>q;
        q.push(src);
        dist[src]=0;
        visited[src]=1;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int j=0;j<adj[node].size();j++)
            {
            if(visited[adj[node][j]])
            continue;
            
            visited[adj[node][j]]=1;
            q.push(adj[node][j]);
            dist[adj[node][j]]=dist[node]+1;
            
            }
        }
        
        return dist[dest];
    }
};