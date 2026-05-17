// Given a queue q containing integer elements, your task is to reverse the queue.

// Examples:

// Input: q[] = [5, 10, 15, 20, 25]
// Output: [25, 20, 15, 10, 5]
// Explanation: After reversing the given elements of the queue, the resultant queue will be 25 20 15 10 5.
// Input: q[] = [1, 2, 3, 4, 5]
// Output: [5, 4, 3, 2, 1]
// Explanation: After reversing the given elements of the queue, the resultant queue will be 5 4 3 2 1.
// Constraints:
// 1 ≤ q.size() ≤ 103
// 0 ≤ q[i] ≤ 105

//solution:-

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        
        stack<int>st;
        while(!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
    }
};