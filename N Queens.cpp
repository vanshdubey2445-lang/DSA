// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 
#include<iostream>
#include<vector>
using namespace std;


//Solution:-1:-> for checking the diagonals separately
class Solution {
public:
bool check(int n,vector<string>&board,int i,int j)
{
    int row=i;
    int col=j;
    while(row>-1 && col>-1)
    {
        if(board[row][col]=='Q')
        return 0;
        row--,col--;
    }

    row=i,col=j;

    while(row>-1 && col<n)
    {
        if(board[row][col]=='Q')
        return 0;
        row--,col++;
    }

    return 1;
}

void find(int row, int n,vector<vector<string>>&ans,vector<string>&board, vector<bool>&col)
{
    if(row==n)
    {
        ans.push_back(board);
        return;
    }
    
    for(int j=0;j<n;j++)
    {
        if(col[j]==0 && check(n,board,row,j))
        {
            col[j]=1;
            board[row][j]='Q';
            find(row+1,n,ans,board,col);
            col[j]=0;
            board[row][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        board[i].push_back('.');
        vector<bool>col(n,0);

        find(0,n,ans,board,col);

        return ans;
    }
};

//Solution:-2->  for making an array to make our work in o(1) time.
class Solution {
public:
bool check(int n,vector<string>&board,int i,int j)
{
    int row=i;
    int col=j;
    while(row>-1 && col>-1)
    {
        if(board[row][col]=='Q')
        return 0;
        row--,col--;
    }

    row=i,col=j;

    while(row>-1 && col<n)
    {
        if(board[row][col]=='Q')
        return 0;
        row--,col++;
    }

    return 1;
}

void find(int row, int n,vector<vector<string>>&ans,vector<string>&board, vector<bool>&col,vector<bool>&left, vector<bool>&right)
{
    if(row==n)
    {
        ans.push_back(board);
        return;
    }
    
    for(int j=0;j<n;j++)
    {
        if(col[j]==0 && left[n-1+j-row]==0 && right[row+j]==0)
        {
            col[j]=1;
            board[row][j]='Q';
            left[n-1+j-row]=1;
            right[row+j]=1;
            find(row+1,n,ans,board,col,left,right);
            col[j]=0;
            board[row][j]='.';
            left[n-1+j-row]=0;
            right[row+j]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        board[i].push_back('.');
        vector<bool>col(n,0);
        vector<bool>left(2*n-1,0);//left diagonal
        vector<bool>right(2*n-1,0);//right diagonal

        find(0,n,ans,board,col,left,right);

        return ans;
    }
};

