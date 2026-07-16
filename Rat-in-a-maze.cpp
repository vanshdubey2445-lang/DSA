// Given a binary matrix maze[][] of size n × n containing values 0 and 1, find all possible paths for a rat to travel from the source cell (0, 0) to the destination cell (n - 1, n - 1). The rat can move in four directions: up(U), down(D), left(L), and right(R).

// 1 represents an open cell through which the rat can move.
// 0 represents a blocked cell that cannot be traversed.
// The rat can move only through open cells and cannot visit the same cell more than once in a path. Return all valid paths as strings consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.

// Note: Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

// Examples:

// Input: maze[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).

// Input: maze[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists as the destination cell (1, 1) is blocked.

//solution:-

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
  
  int row[4]={-1,1,0,0};
  int col[4]={0,0,-1,1};
  string dir="UDLR";
  
  bool valid(int i, int j,  int n)
  {
      return i>=0&&j>=0&&i<n&&j<n;
  }
  
      void total(vector<vector<int>>&matrix, int i, int j, int n, string&path, vector<string>&ans, vector<vector<bool>>&visited)
  {
         if(i==n-1&&j==n-1)
         {
             ans.push_back(path);
             return;
         }
         
         visited[i][j]=1;
         
         for(int k=0;k<4;k++)
         {
             if(valid(i+row[k],j+col[k],n)&&(matrix[i+row[k]][j+col[k]])&&!(visited[i+row[k]][j+col[k]]))
            {
                path.push_back(dir[k]);
                total(matrix,i+row[k],j+col[k],n,path,ans,visited);
                path.pop_back();
            }    
         }
         
         visited[i][j]=0;
         
         
         
         
         
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n=maze.size();
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        vector<string>ans;
        string path;
        
        if(maze[0][0]==0||maze[n-1][n-1]==0)
        return ans;
        
        total(maze,0,0,n,path,ans,visited);
        
        sort(ans.begin(),ans.end());
            return ans;
        
    }
};