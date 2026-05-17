#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    q.push(15);
    q.push(57);
    q.push(95);
    q.push(85);
    int n=q.size();
    while(n--)
    {
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
}