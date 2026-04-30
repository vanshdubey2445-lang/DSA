// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

//Solution:-
#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& height) {

        int n=height.size(),i;
        vector<int>right(n);
        vector<int>left(n);
        stack<int>st;

        //for next smallest right;
        for(i=0;i<n;i++)
        {
            while(!st.empty()&&height[st.top()]>height[i])
            {
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty())
        {
            right[st.top()]=n;
            st.pop();
        }

        //for next smallest left;

        for(i=n-1;i>=0;i--)
        {
            while(!st.empty()&&height[st.top()]>height[i])
            {
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty())
        {
            left[st.top()]=-1;
            st.pop();
        }

        int ans=0;

        for(i=0;i<n;i++)
        {
            ans=max(ans,height[i]*(right[i]-left[i]-1));
        }
        return ans;
        
    }
};

// But this was the approach where we are traversing the histogram thrice, so it can't be an optimised approach.

//The optimised approach:-

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
};