// You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

// Note: The graph is indexed with 0-based indexing.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
// Output: true
// Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

// Vertex 0: Color 1
// Vertex 1: Color 2
// Vertex 2: Color 2
// Vertex 3: Color 3
// Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
// Output: false
// Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
// Constraints:
// 1 ≤ V ≤ 10
// 1 ≤ E = edges.size() ≤ (V*(V-1))/2
// 0 ≤ edges[i][j] ≤ V-1
// 1 ≤ m ≤ V

// Expected Complexities
// Time Complexity: O(V * m ^ V)
// Auxiliary Space: O(V + E)

#include<iostream>
#include<vector>
using namespace std;

//by a different approach to traverse each node
class Solution {
  public:
  
  bool dfs(int node ,vector<int>&color, bool graph[101][101], int m,int v)
  {
      for(int i=0;i<m;i++)
      {
          bool possible=1;
          for(int j=0;j<v;j++)
          {
              if(graph[node][j] && color[j]==i)
              {
                  possible=0;
                  break;
              }
          }
      
      
      if(possible==0)
      continue;
      
      color[node]=i;
      
      possible=1;
      for(int j=0;j<v;j++)
      {
          if(graph[node][j] && color[j]==-1)
          {
              if(!dfs(j,color,graph,m,v))
              {
                  possible=0;
                  break;
              }
          }
      }
      
      if(possible)
      return 1;
      
      color[node]=-1;
      }
      
      return 0;
      
      
  }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        bool graph[101][101] ={false};
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            graph[u][v]=true;
            graph[v][u]=true;
        }
        
        vector<int>color(v,-1);
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1 && !dfs(i,color,graph,m,v))
            return 0;
        }
        
        return 1;
        
    }
};

//solution:2:-> by analysing all the colours how can we colour the node following the condidtions also;
class Solution {
  public:
  
  bool find(int node, bool graph[101][101],int n,int m, vector<int>&col) 
  {
      
      if(node==n)
      return 1;
      
      for(int i=0;i<m;i++)
      {
          bool possible=1;
          for(int j=0;j<n;j++)
          {
              if(graph[node][j] && col[j]==i)
              {
                  possible=0;
                  break;
              }
          }
          
          if(possible)
          {
              col[node]=i;
              if(find(node+1,graph,n,m,col))
              return 1;
              col[node]=-1;
          }
      }
      
     return 0;
  }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        bool graph[101][101] ={false};
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            graph[u][v]=true;
            graph[v][u]=true;
        }
        
        vector<int>color(v,-1);
        return find(0,graph,v,m,color);
    }
};