// Implement a class SpecialStack that supports following operations:

// push(x) – Insert an integer x into the stack.
// pop() – Remove the top element from the stack.
// peek() – Return the top element from the stack. If the stack is empty, return -1.
// getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
// isEmpty() –  Return true if stack is empty, else false
// There will be a sequence of queries queries[][]. The queries are represented in numeric form:

// 1 x : Call push(x)
// 2:  Call pop()
// 3: Call peek()
// 4: Call getMin()
// 5: Call isEmpty()
// The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), getMin(), isEmpty() operations.
// You only need to implement the above five functions.

// Examples:

// Input: q = 7, queries[][] = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
// Output: [3, 2, 1]
// Explanation: 
// push(2): Stack is [2]
// push(3): Stack is [2, 3]
// peek(): Top element is 3
// pop(): Removes 3, stack is [2]
// getMin(): Minimum element is 2
// push(1): Stack is [2, 1]
// getMin(): Minimum element is 1
// Input: q = 4, queries[][] = [[1, 4], [1, 2], [4], [3], [5]]
// Output: [2, 2, false]
// Explanation: 
// push(4): Stack is [4]
// push(2): Stack is [4, 2]
// getMin(): Minimum element is 2
// peek(): Top element is 2
// isEmpty(): false
// Constraints:
// 1 ≤ q ≤ 105
// 0 ≤ values on the stack ≤ 109

//Solution:-

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// i did this question using two methods by taking two stacks and by one stack.

class SpecialStack {
  public:
  
  stack<int>st1;
 // stack<int>st2;
    SpecialStack() {
        // Define Stack
        
        
    }

    void push(int x) {
        // Add an element to the top of Stack
        if(st1.empty())
        {
            st1.push(x*101+x);
            // st2.push(x);
        }
        else
        {
            st1.push(x*101+min(x,st1.top()%101));
            //st2.push(min(x,st2.top()));
        }
    }

    void pop() {
        // Remove the top element from the Stack
        st1.pop();
        // st2.pop();
        
    }

    int peek() {
        // Returns top element of the Stack
        if(st1.empty())
        return -1;
        else
        {
            int element=st1.top()/101;
            return element;
        }
    
        
    }

    bool isEmpty() {
        // Check if stack is empty
        if(st1.empty())
        return true;
        else
        return false;
    }

    int getMin() {
        // Finds minimum element of Stack
        if(st1.empty())
        return -1;
        
        else
        return st1.top()%101;
    }
};