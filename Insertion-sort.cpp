// Given an array arr[] of positive integers.The task is to complete the insertsort() function which is used to implement Insertion Sort.

// Examples:

// Input: arr[] = [4, 1, 3, 9, 7]
// Output: [1, 3, 4, 7, 9]
// Explanation: The sorted array will be [1, 3, 4, 7, 9].
// Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// Explanation: The sorted array will be [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].
// Input: arr[] = [4, 1, 9]
// Output: [1, 4, 9]
// Explanation: The sorted array will be [1, 4, 9].

//Solution:-

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        for(int i=1;i<arr.size();i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            swap(arr[j],arr[j-1]);
            else 
            break;
        }
        
    }
    }
};