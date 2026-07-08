// Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.

// Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

// Examples:

// Input: arr[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.
// Input: arr[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.
// Constraints:
// 2 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 108
// 2 ≤ k ≤ arr.size()

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Solution 1:-

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        
        int start=1,end,mid,ans;
        
        sort(stalls.begin(),stalls.end());
        end= stalls[stalls.size()-1]-stalls[0];
        
        while(start<=end)
        {
            mid=start+(end-start)/2;
            
            int count =1,pos=stalls[0];
            for(int i=1;i<stalls.size();i++)
            {
                if(pos+mid<=stalls[i])
                {
                    count++;
                    pos=stalls[i];
                }
            }
            
            if(count<k)
            end=mid-1;
            else
            {
                ans=mid;
                start=mid+1;
            }
            
        }
        
        return ans;
        
    }
};