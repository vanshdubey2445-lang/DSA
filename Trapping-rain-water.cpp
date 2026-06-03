// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

int trap(vector<int>& height) 
{
   int n=height.size(),water=0,index=0;
   int maxleft=0,maxright=0,maxheight=height[0];

   //we are firstly finding for the bigger element;
   for(int i=1;i<n;i++)
   {
     if(maxheight<height[i])
     {
        maxheight=height[i];
        index=i;
     }
   }

   //for maximum height on left side;

   for(int i=0;i<index;i++)
   {
    if(maxleft>height[i])
    water+=maxleft-height[i];
    else
    maxleft=height[i];
   }

   //for maximum height on right side;

   for(int i=n-1;i>index;i--)
   {
    if(maxright>height[i])
    water+=maxright-height[i];
    else
    maxright=height[i];
   }

   return water;

}
};
