// Given a square matrix of size n x n, return the transpose matrix of the given matrix.

// The transpose of a matrix is obtained by converting all the rows to columns and all the columns to rows.

// Examples:

// Input: mat[][] = [[1, 1, 1, 1],
//                  [2, 2, 2, 2],
//                  [3, 3, 3, 3],
//                  [4, 4, 4, 4]]
// Output: [[1, 2, 3, 4],
//         [1, 2, 3, 4],
//         [1, 2, 3, 4],
//         [1, 2, 3, 4]]
// Explanation: Converting rows into columns and columns into rows.
// Input: mat[][] =  [[1, 2],
//                   [9, -2]]
// Output: [[1, 9],
//         [2, -2]]
// Explanation: Converting rows into columns and columns into rows.

//Solution:-

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        
        int n=mat.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        return mat;
           
        
    }
};