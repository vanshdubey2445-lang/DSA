// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= rows, cols <= 200
// matrix[i][j] is '0' or '1'.

//solution:-

#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class Solution {
public:

int largestRectangleArea(vector<int>& height) {
        stack<int>st;
        int n=height.size(),i,index,ans=0;
        for(i=0;i<n;i++)
        {
            while(!st.empty()&&height[st.top()]>height[i])
            {
                index=st.top();
                st.pop();
                if(!st.empty())
                ans=max(ans,height[index]*(i-st.top()-1));
                else
                ans=max(ans,height[index]*(i));
            }

            st.push(i);
        }

        while(!st.empty())
        {
            index=st.top();
            st.pop();
            if(!st.empty())
            ans=max(ans,height[index]*(n-st.top()-1));
            else
            ans=max(ans,height[index]*(n));
        }

        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>height(col,0);

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='0')
                height[j]=0;
                else
                height[j]+=1;
            }
            ans=max(ans,largestRectangleArea(height));
        }
        return ans;
        
    }
};