// Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Examples :

// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
// Input: val[] = [500], wt[] = [30], capacity = 10
// Output: 166.670000
// Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.
// Constraints:
// 1 ≤ val.size = wt.size ≤ 105
// 1 ≤ capacity ≤ 109
// 1 ≤ val[i], wt[i] ≤ 104

// Expected Complexities
// Time Complexity: O(n log n)
// Auxiliary Space: O(n)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int w) {
        // code here
        int n=val.size();
         vector<pair<double,int>>iteam;
         
         for(int i=0;i<n;i++)
         {
             double ratio=val[i];
             ratio/=wt[i];
             iteam.push_back({ratio,i});
         }
         
         sort(iteam.begin(),iteam.end(),greater<pair<double,int>>());
         
         double profit=0;
         int i=0;
         
         while(w && i<n)
         {
             int a=iteam[i].second;
             if(w>=wt[a])
             {
                 profit+=val[a];
                 w-=wt[a];
             }
             
             else
             {
                 
                 profit+=iteam[i].first*w;
                 w=0;
             }
             
             i++;
         }
         
         return profit;
    }
};