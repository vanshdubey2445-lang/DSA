// Given an integer n representing a target value and an infinite supply of coins of denominations 1, 2, 5, and 10, find the minimum number of coins required to make the value n.

// Examples:

// Input: n = 39
// Output: 6
// Explanation: 39 can be formed using 3 coins of 10 rupees, 1 coin of 5 rupees and 2 coins of 2 rupees so minimum coins required are 6.
// Input: n = 121
// Output: 13
// Explanation: 121 can be formed using 12 coins of 10 rupees and 1 coin of 1 rupees.
// Constraints:

// 1 ≤ n ≤ 106
// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(1)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int findMin(int n) {
        // code here
        int coin[]={10,5,2,1};
        int notes=0, i=0;
        int coins=0;
        
        while(n)
        {
            notes=n/coin[i];
            
            while(notes--)
            coins++;
            
            n%=coin[i];
            i++;
        }
        
        return coins;
    }
    
};