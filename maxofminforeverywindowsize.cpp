// You are given an integer array arr[], the task is to find the maximum of minimum values for every window size k where 1≤ k ≤ arr.size().

// For each window size k, consider all contiguous subarrays of length k, determine the minimum element in each subarray, and then take the maximum among all these minimums.

// Return the results as an array, where the element at index i represents the answer for window size i+1.

// Examples :

// Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
// Output: [70, 30, 20, 10, 10, 10, 10] 
// Explanation: 
// Window size 1: minimums are [10, 20, 30, 50, 10, 70, 30], maximum of minimums is 70.
// Window size 2: minimums are [10, 20, 30, 10, 10, 30], maximum of minimums is 30.
// Window size 3: minimums are [10, 20, 10, 10, 10], maximum of minimums is 20.
// Window size 4–7: minimums are [10, 10, 10, 10], maximum of minimums is 10.
// Input: arr[] = [10, 20, 30]
// Output: [30, 20, 10]
// Explanation: 
// Window size 1: minimums of  [10], [20], [30], maximum of minimums is 30.
// Window size 2: minimums of [10, 20], [20,30], maximum of minimums is 20.
// Window size 3: minimums of [10,20,30], maximum of minimums is 10.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 106

//solution:-

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n=arr.size();
        vector<int>ans(n,0);
        stack<int>st;
    
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>arr[i])
            {
                int index=st.top();
                st.pop();
                
                if(st.empty())
                {
                   int  range=i;
                    ans[range-1]=max(ans[range-1],arr[index]);
                }
                
                else
                {
                     int range=i-st.top()-1;
                    ans[range-1]=max(ans[range-1],arr[index]);
                }
            }
            
            st.push(i);
        }
        
        while(!st.empty())
        {
            int index=st.top();
            st.pop();
            
            if(st.empty())
            {
                int range=n;
                ans[range-1]=max(ans[range-1],arr[index]);
            }
            
            else
            {
                int range=n-st.top()-1;
                ans[range-1]=max(ans[range-1],arr[index]);
            }
        }
        
        for(int i=n-2;i>=0;i--)
        ans[i]=max(ans[i],ans[i+1]);
        
        
        return ans;
    }
};
