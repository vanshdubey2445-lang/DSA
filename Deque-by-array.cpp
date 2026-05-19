#include<iostream>
using namespace std;

class Dequeue
{
    int front,rear,size;
    int *arr;
    public:
    Dequeue(int n)
    {
        size=n;
        arr=new int[n];
        front=rear=-1;
    }

    bool empty()
    {
        return front==-1;
    }

    bool full()
    {
        return (rear+1)%size==front;
    }

    void pushfront(int x)
    {
        if(empty())
        {
            front=rear=0;
            cout<<"Pushed "<<x<<" in front\n";
            arr[0]=x;
            return ;
        }

        else if(full())
        {
            cout<<"Dequeue overflow\n";
            return ;
        }

        else
        {
            front=(front-1+size)%size;
            arr[front]=x;
            cout<<"Pushed "<<x<<" in front\n";
            return ;
        }
    }

    void pushback(int x)
    {
        if(empty())
        {
            front=rear=0;
            cout<<"Pushed "<<x<<" in back\n";
            arr[0]=x;
            return ;
        }

        else if(full())
        return ;

        else
        {
            rear=(rear+1)%size;
            arr[rear]=x;
            cout<<"Pushed "<<x<<" in back\n";
            return ;
        }
    }

    void popfront()
    {
        if(empty())
        {
            cout<<"Dequeue underflow\n";
            return ;
        }

        else
        {
            cout<<"Popped "<<arr[front]<<" from dequeue\n"; 
            if(front==rear)
            front=rear=-1;

            else
            front=(front+1)%size;
        }
    }

     void popback()
    {
        if(empty())
        {
            cout<<"Dequeue underflow\n";
            return ;
        }

        else
        {
            cout<<"Popped "<<arr[rear]<<" from dequeue\n";

            if(front==rear)
            front=rear=-1;

            else
            rear=(rear-1+size)%size;
        }
    }

    int start()
    {
        if(empty())
        return -1;

        return arr[front];
    }

    
    int end()
    {
        if(empty())
        return -1;

        return arr[rear];
    }    
};

int main()
{
    //example;
    Dequeue d(5);
    d.pushfront(65);
    d.pushback(7);
    d.pushfront(5);
    d.popfront();
    d.popback();
    cout<<d.start()<<endl;
    cout<<d.end()<<endl;


}