// Given an array arr of lowercase strings, find if the strings can be chained together to form a circle.

// A string x can be chained together with another string y if the last character of x is the same as the first character of y.
// If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.
// Examples :

// Input: arr = ["for", "geek", "rig", "kaf"]
// Output: true
// Explanation: These strings can be chained as "for" -> "rig" -> "geek" -> "kaf" to form a circle.
// Input: arr = ["abc", "bcd", "cdf"]
// Output: false
// Explanation: These strings can't form a circle.
// Constraints: 
// 1 ≤ arr.size() ≤ 10^4
// 1 ≤ length of strings ≤ 20

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(n)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  
  void dfs(int node,vector<int>adj[], vector<bool>&visited)
  {
      visited[node]=1;
      for(int j=0;j<adj[node].size();j++)
      {
          if(!visited[adj[node][j]])
          dfs(adj[node][j],adj,visited);
      }   
      
  }
  
  
    bool isCircle(vector<string> &arr) {
        
        int n=arr.size();
        vector<int>adj[26];
        vector<int>indeg(26,0);vector<int>outdeg(26,0);
        
        for(int i=0;i<n;i++)
        {
            string temp=arr[i];
            int u=temp[0]-'a';
            int v=temp[temp.size()-1]-'a';
            
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(indeg[i]!=outdeg[i])
            return 0;
        }
        
        vector<bool>visited(26,0);
        dfs(arr[0][0]-'a',adj,visited);
        
        
    for(int i=0;i<26;i++)
    {
       if(indeg[i] && !visited[i]) 
       return 0;
    }
    
    return 1;
    
    
    }
};