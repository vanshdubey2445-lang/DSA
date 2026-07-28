// Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

// The median is defined as follows:

// 1. Odd number of elements: The median is the middle element when the current set of numbers is sorted.
// 2. Even number of elements: The median is the arithmetic mean (average) of the two middle elements when the current set of numbers is sorted.

// Examples:

// Input: arr[] = [5, 15, 1, 3, 2, 8]
// Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
// Explanation: 
// After reading 1st element of stream – 5 -> median = 5.0
// After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
// After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
// After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
// After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
// After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0
// Input: arr[] = [2, 2, 2, 2]
// Output: [2.0, 2.0, 2.0, 2.0]
// Explanation: 
// After reading 1st element of stream – 2 -> median = 2.0
// After reading 2nd element of stream – 2, 2 -> median = (2+2)/2 = 2.0
// After reading 3rd element of stream – 2, 2, 2 -> median = 2.0
// After reading 4th element of stream – 2, 2, 2, 2 ->  median = (2+2)/2 = 2.0

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//Solution:-

class Solution {
  public:
    
   priority_queue<int>left;
   priority_queue<int,vector<int>,greater<int>>right;
   
   
  void balanceheap()
  {
      if(right.size()>left.size())
      {
          left.push(right.top());
          right.pop();
      }
   
      else
      {
          if(left.size()-1>right.size())
          {
              right.push(left.top()); 
              left.pop();
          }
      }
  }
  
  
  void insert(int &x)
  {
     if(left.empty())
      {
          left.push(x);
          return ;
      }
      
      if(x>left.top())
      right.push(x);
      
      else
      left.push(x);
      
      balanceheap();
  }
  
  double median()
  {
      if(left.size()>right.size())
      return left.top();
      
      else
      {
          double ans=left.top()+right.top();
          ans/=2;
          return ans;
      }
      
  }
  
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double>a;
        
        for(int i=0;i<arr.size();i++)
        {
            insert(arr[i]);
            a.push_back(median());
        }
        
        return a;
    }
    
};
