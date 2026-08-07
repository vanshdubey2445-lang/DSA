// An Eulerian Path is a path in graph that visits every edge exactly once. An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. Given an undirected graph with V nodes, and E edges, with adjacency list adj , where adj[i] stores all the nodes that have an edge with i, return 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, return 1, otherwise, return 0.

// Examples

// Input: 

// Output: 2
// Explanation: 
// Following is an eulerian circuit in the mentioned graph
// 1 -> 2 -> 0 -> 1
// Input: 

// Output: 1
// Explanation: 
// Following is an eulerian path in the mentioned graph
// 1 -> 0 -> 2
// Constraints:
// 1 ≤ V, E ≤ 104
// 0 ≤ adj[i][j] ≤ V-1

// Expected Complexities
// Time Complexity: O(V + E)
// Auxiliary Space: O(V)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
  void dfs(int node,vector<vector<int>>& adj,vector<bool>&visited)
  {
      visited[node]=1;
      
      for(int j=0;j<adj[node].size();j++)
      {
          if(!visited[adj[node][j]])
          dfs(adj[node][j],adj,visited);
      }
  }
  
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        vector<int>deg(V,0);
        int odd=0;
        
        for(int i=0;i<V;i++)
        {
            deg[i]=adj[i].size();
            if(deg[i]%2)
            odd++;
        }
        
        if(odd!=0 && odd!=2)
        return 0;
        
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(deg[i])
            {
                dfs(i,adj,visited);
                break;
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(deg[i] && !visited[i])
            return 0;
        }
          
          if(odd==0)
          return 2;
          else
          return 1;
          
    }
};