// Given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v. Return all the articulation points (or cut vertices) in the graph. An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph. 

// The given graph may be disconnected, i.e., it may consist of more than one connected component. 
// If no such point exists, return {-1}.
// Examples :

// Input: V = 5, edges[][] = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]

// Output: [1, 4]
// Explanation: Removing the vertex 1 or 4 will disconnects the graph as-
   
// Input: V = 4, edges[][] = [[0, 1], [0, 2]]
// Output: [0]
// Explanation: Removing the vertex 0 will increase the number of disconnected components to 3.  
// Constraints:
// 1 ≤ V, E ≤ 104

// Expected Complexities
// Time Complexity: O(V + E)
// Auxiliary Space: O(V)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  
  void dfs(int node,int parent,vector<int>adj[], vector<int>&disc,vector<int>&low, vector<bool>&visited, vector<bool>&art,int &count)
 {
     visited[node]=1;
     disc[node]=low[node]=count;
     int child=0;
     
     for(int j=0;j<adj[node].size();j++)
     {
         int neib=adj[node][j];
         
         if(neib==parent)
         continue;
         
         else if(visited[neib])
         low[node]=min(low[node],disc[neib]);
         
         else
         {
             child++;
             count++;
             
             dfs(neib,node,adj,disc,low,visited,art,count);
             
             if(disc[node]<=low[neib] && parent!=-1)
             art[node]=1;
             
             low[node]=min(low[node],low[neib]);
         }
     }
     
     if(child>1 && parent==-1)
     art[node]=1;
 } 
 
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>art(V,0);
        vector<int>disc(V);
        vector<int>low(V);
        vector<bool>visited(V,0);
        int count=0;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            dfs(i,-1,adj,disc,low,visited,art,count);
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(art[i])
            ans.push_back(i);
            
        }
        
        if(ans.size()==0)
        ans.push_back(-1);
        
        return ans;
        
    }
};