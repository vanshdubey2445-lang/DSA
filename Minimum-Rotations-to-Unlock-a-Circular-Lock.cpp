// Given two positive integers r and d of the same length, representing the current and desired lock configurations, respectively, where each digit corresponds to a circular ring numbered from 0 to 9, find the minimum number of rotations required to transform r into d.

// In one operation, a ring can be rotated by one position either clockwise or anticlockwise.
// The rings are circular, so 9 wraps to 0 and 0 wraps to 9.
// Examples:

// Input: r = 222, d = 333
// Output: 3
// Explaination: Each digit 2 can be changed to 3 in one rotation. Therefore, the minimum total rotations required are 1 + 1 + 1 = 3.
// Input: r = 2345, d = 5432
// Output: 8
// Explaination: The minimum rotations required for the corresponding digit pairs (2, 5), (3, 4), (4, 3), and (5, 2) are 3, 1, 1, and 3, respectively. Therefore, the minimum total rotations required are 3 + 1 + 1 + 3 = 8.
// Constraints:
// 1 ≤ r, d ≤ 109

// Expected Complexities
// Time Complexity: O(log r)
// Auxiliary Space: O(1)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int rotationCount(int r, int d) {
        // code here
        int ans=0;
        int first,second;
        while(r>0 || d>0)
        {
            first=r%10;
            second=d%10;
            r/=10;
            d/=10;
            ans+=min(abs(first-second),10-abs(first-second));
        }
        
        return ans;
    }
};