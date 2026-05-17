// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

// Example 1:

// Input
// ["MyStack", "push", "push", "top", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 2, 2, false]

// Explanation
// MyStack myStack = new MyStack();
// myStack.push(1);
// myStack.push(2);
// myStack.top(); // return 2
// myStack.pop(); // return 2
// myStack.empty(); // return False
 
// solution:-

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class MyStack {
public:

    queue<int>q1;
    queue<int>q2;

    MyStack() {
        
    }

    bool empty() {
        return q1.empty()&&q2.empty();
    }
    
    void push(int x) {
        if(empty())
        q1.push(x);

        else if(q1.empty())
        q2.push(x);

        else
        q1.push(x);
    }
    
    int pop() {
        if(empty())
        return 0;

        else if(q1.empty())
        {
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int e=q2.front();
            q2.pop();
            return e;
        }

        else
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int e=q1.front();
            q1.pop();
            return e;
        }
    }
    
    int top() {
        if(empty())
        return 0;
        else if(q1.empty())
        return q2.back();
        else
        return q1.back();
        
    }
    
};
