// You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Examples:

// Input: 
// grid[][] = [['X', 'X', 'X', 'X'], 
//           ['X', 'O', 'X', 'X'], 
//           ['X', 'O', 'O', 'X'], 
//           ['X', 'O', 'X', 'X'], 
//           ['X', 'X', 'O', 'O']]
// Output: 
// [['X', 'X', 'X', 'X'], 
// ['X', 'X', 'X', 'X'], 
// ['X', 'X', 'X', 'X'], 
// ['X', 'X', 'X', 'X'], 
// ['X', 'X', 'O', 'O']]
// Explanation: We only changed those 'O' that are surrounded by 'X'
// Input: 
// grid[][] = [['X', 'O', 'X', 'X'], 
//           ['X', 'O', 'X', 'X'], 
//           ['X', 'O', 'O', 'X'], 
//           ['X', 'O', 'X', 'X'], 
//           ['X', 'X', 'O', 'O']]
// Output: 
// [['X', 'O', 'X', 'X'], 
// ['X', 'O', 'X', 'X'], 
// ['X', 'O', 'O', 'X'], 
// ['X', 'O', 'X', 'X'], 
// ['X', 'X', 'O', 'O']]
// Explanation: There's no 'O' that's surround by 'X'.
// Input: 
// grid[][] = [['X', 'X', 'X'], 
//           ['X', 'O', 'X'], 
//           ['X', 'X', 'X']]
// Output: 
// [['X', 'X', 'X'], 
// ['X', 'X', 'X'], 
// ['X', 'X', 'X']]
// Explanation: There's only one 'O' that's surround by 'X'.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {  //bfs traversal
  public:
  int r,c;
  int row[4]={1,-1,0,0};
  int col[4]={0,0,1,-1};
  
  bool valid(int i,int j)
  {
      return i>=0 && i<r && j>=0 && j<c;
  }
  
    void fill(vector<vector<char>>& grid) {
        // Code here
        r=grid.size();
        c=grid[0].size();
        
        queue<pair<int,int>>q;
        
        //first row
        for(int j=0;j<c;j++)
        {
            if(grid[0][j]=='O')
            {
                q.push(make_pair(0,j));
                grid[0][j]='T';
            }
        }
        
        //first col
        for(int i=1;i<r;i++)
        {
            if(grid[i][0]=='O')
            {
                q.push(make_pair(i,0));
                grid[i][0]='T';
            }
        }
        
        //last row
        for(int j=1;j<c;j++)
        {
            if(grid[r-1][j]=='O')
            {
                q.push(make_pair(r-1,j));
                grid[r-1][j]='T';
            }
        }
        
        //last col
        for(int i=1;i<r-1;i++)
        {
            if(grid[i][c-1]=='O')
            {
                q.push(make_pair(i,c-1));
                grid[i][c-1]='T';
            }
        }
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                if(valid(i+row[k],j+col[k]) && grid[i+row[k]][j+col[k]]=='O')
                {
                    grid[i+row[k]][j+col[k]]='T';
                    q.push(make_pair(i+row[k],j+col[k]));
                }
            }
        }
        
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]=='O')
            grid[i][j]='X';
            
            else if(grid[i][j]=='T')
            grid[i][j]='O';
        }
        
        
    }
};