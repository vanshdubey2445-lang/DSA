// Given a binary matrix mat[][] of size n × m containing values 0 and 1, and a source cell src[] and destination cell dest[], find the minimum number of steps required to reach the destination cell from the source cell. From any cell, you can move to its adjacent cells in the up, down, left, and right directions.

// 1 represents a traversable cell.
// 0 represents a blocked cell that cannot be visited.
// If the destination cannot be reached from the source, return -1.

// Examples:

// Input: mat[][] = {{1, 1, 1, 1},{1, 1, 0, 1},{1, 1, 1, 1},{1, 1, 0, 0},{1, 0, 0, 1}}, src[] = {0, 1}, dest[] = {2, 2}
// Output: 3
// Explanation:From (0,1), the minimum number of steps to reach (2,2) is 3.
  
// Input: mat[][] = {{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 0},{1, 0, 1, 0, 1}}, src[] = {0, 0}, dest[] = {3, 4}
// Output:-1
// Explanation:From (0,0), the destination (3,4) cannot be reached because all possible paths are blocked by 0 cells, so no valid route exists.
 
// Constraints:

// 1 ≤ n, m ≤ 500
// grid[i][j] == 0 or grid[i][j] == 1
// The source and destination cells are always inside the given matrix.
// Expected Complexities
// Time Complexity: O(n * m)
// Auxiliary Space: O(n * m)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
  
  int row[4]={1,-1,0,0};
  int col[4]={0,0,1,-1};
  
  bool valid(int i,int j,int n,int m)
  {
      return i>=0 && j>=0 && i<n && j<m;
  }
  
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        
        int c,d;
        c=src[0];
        d=src[1];
        int e=dest[0],f=dest[1];
        
        if(mat[c][d]==0 || mat[e][f]==0)
        return -1;
        
         if(c==e && d==f)
         return 0;
        
        //queue<pair<int,pair<int,int>>>q;
        queue<pair<int,int>>q;
        //q.push({c,{d,0}});
        q.push({c,d});
        int N=mat.size();
        int M=mat[0].size();
        //vector<vector<bool>>visited(N,vector<bool>(M,0));
        mat[c][d]=0;
        int step=0;
        
        while(!q.empty())
        {
            int count=q.size();
            while(count--)
            {
            int i=q.front().first;
            int j=q.front().second;
            //int step=q.front().second.second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int a= i+row[k];
                int b= j+col[k];
                
                if(valid(a,b,N,M) && mat[a][b])
                {
                    if(a==e && b== f)
                    return step+1;
                    
                    mat[a][b]=0;
                    q.push({a,b});
                    
                }
            }
        }
        step++;
    }
        
        return -1;
    }
};