// Given a square chessboard of size (n x n), the initial position and target position of Knight are given. Find out the minimum steps a Knight will take to reach the target position.

// Note: The initial and the target position coordinates of Knight have been given according to 1-base indexing.

// Examples:

// Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
// Output: 1
// Explanation:
// Knight takes 1 step to reach from 
// (3, 3) to (1 ,2).
// Input: n = 6, knightPos[] = [4, 5],targetPos[] = [1, 1]
// Output: 3
// Explanation:

// Knight takes 3 step to reach from 
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
// Constraints:
// 1 <= n<= 1000
// 1 <= knightpos ≤ [x, y], targertpos[x, y] ≤  n 

// Expected Complexities
// Time Complexity: O(n^2)
//  Auxiliary Space: O(n^2)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
  
  int row[8]={2,2,-2,-2,1,-1,1,-1};
  int col[8]={1,-1,1,-1,2,2,-2,-2};
  
  bool valid(int i,int j, int N)
  {
      return i>=0 && j>=0 && i<N && j<N;
  }
  
    int minStepToReachTarget(vector<int>& knightpos, vector<int>& targetpos, int n) {
        // Code here
        
        knightpos[0]--;
        knightpos[1]--;
        targetpos[0]--;
        targetpos[1]--;
        
        //base case
        if(targetpos[0]==knightpos[0] && targetpos[1]==knightpos[1])
        return 0;
        
        queue<pair<int,int>>q;
        vector<vector<bool>>chess(n,vector<bool>(n,0));
        q.push({knightpos[0],knightpos[1]});
        chess[knightpos[0]][knightpos[1]]=1;
        
        int step=0;
        while(!q.empty())
        {
            int count=q.size();
            while(count--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(int k=0;k<8;k++)
                {
                    int a=i+row[k];
                    int b=j+col[k];
                    
                    if(valid(a,b,n) && !chess[a][b])
                    {
                        if(a==targetpos[0] && b==targetpos[1])
                        return step+1;
                        
                        chess[a][b]=1;
                        q.push({a,b});
                    }
                }
            }
            
            step++;
        }
        
        return -1;
    }
};