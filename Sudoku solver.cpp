// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

 

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

bool check(int k,vector<vector<char>>&board,int i,int j)
{
    char c='0'+k;
    for(int col=0;col<9;col++)
    {
        if(board[i][col]==c)
        return 0;
    }

    for(int row=0;row<9;row++)
    {
        if(board[row][j]==c)
        return 0;
    }
    
    int row= i/3*3,col=j/3*3;

    for(int a=0;a<3;a++)
    for(int b=0;b<3;b++)
    {
        if(board[a+row][b+col]==c)
        return 0;
    }

    return 1;
}
bool find(int i,int j,vector<vector<char>>&board)
{
    if(i==9)
    return 1;

    if(j==9)
    return find(i+1,0,board);

    if(board[i][j]!='.')
    return find(i,j+1,board);

    for(int k=1;k<10;k++)
    {
        if(check(k,board,i,j))
        {
            board[i][j]='0'+k;
            if(find(i,j+1,board))
            return 1;
            board[i][j]='.';
        }
    }

    return 0;
}
    void solveSudoku(vector<vector<char>>& board) {
        find(0,0,board);
    }
};