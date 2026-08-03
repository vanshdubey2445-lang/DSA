// Given a matrix mat[][], where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cell have fresh oranges
// 2 : Cell have rotten oranges

// Determine the minimum time required so that all the oranges become rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

// Note: If it is impossible to rot every orange then simply return -1.

// Examples:

// Input: mat[][] = [[2, 1, 0, 2, 1], [1, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
// Output: 2
// Explanation: 

// Oranges at positions (0,0), (0,3), (1,3), and (2,3) will rot adjacent fresh oranges in successive time frames.
// All fresh oranges become rotten after 2 units of time.
// Input: mat[][] = [[2, 1, 0, 2, 1], [0, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
// Output: -1
// Explanation: Oranges at positions (0,0), (0,3), (1,3), and (2,3) rot some fresh oranges,
// but the fresh orange at (2,0) can never be reached, so not all oranges can rot.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {   //By bfs traversal
  public:
  
  int row[4]={1,-1,0,0};
  int col[4]={0,0,1,-1};
  int r;
  int c;
  
  bool valid(int i,int j)
  {
      return i>=0 && i<r && j>=0 && j<c;
  }
  
 int orangesRot(vector<vector<int>>& mat) {
        
        r=mat.size();
        c=mat[0].size();
        
        queue<pair<int,int>>q;
        int fresh=0;
        
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]==2)
            q.push(make_pair(i,j));
            
            else if(mat[i][j]==1)
            fresh++;
        }
        
        if(fresh==0)
        return 0;
        
        int timer=0;
        
        while(!q.empty())
        {
            timer++;
            int curr=q.size();
            
            while(curr--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    if(valid(i+row[k],j+col[k]) && mat[i+row[k]][j+col[k]]==1)
                    {
                        mat[i+row[k]][j+col[k]]=2;
                        q.push(make_pair(i+row[k],j+col[k]));
                    }
                }
            }
        }
        
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(mat[i][j]==1)
        return -1;
        
        return timer-1;
    }
};