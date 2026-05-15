#include<iostream>
using namespace std;



//here there are two methods in which the comment one is traditional and the other one is circular queue;

class queue
{
    int *arr;
    int front,rear;
    int size;
    public:

    queue(int n)
    {
        arr=new int[n];
        front=rear=-1;
        size=n;
    }

    bool isempty()
   { return front==-1;}

   bool isfull()
   {
    //return rear==size-1;
    return (rear+1)%size==front;
   }

   void push(int x)
   {
    if(isempty())
    {
        cout<<"Pushed "<< x <<" into the queue"<<endl;
        front=rear=0;
        arr[0]=x;
        return ;
    }

    else if(isfull())
    {
        cout<<"queue overflow"<<endl;
        return ;
    }

    else
    {   //rear=rear+1;
        rear=(rear+1)%size;
        arr[rear]=x;
        cout<<"Pushed "<< x <<" into the queue\n";
    }

   }

   void pop()
   {
    if(isempty())
    {
        cout<<"queue underflow"<<endl;
        return;
    }

    else 
    {
        if(front==rear)
        {
            cout<<"Popped "<< arr[front] <<" from the queue\n";
            front=rear=-1;
        }

        else
        {
            cout<<"Popped "<< arr[front] <<" from the queue\n";
            //front=front+1;
            front=(front+1)%size;
        }

    }
   }

   int start()
   {
    if(isempty())
    {
        cout<<"queue is empty"<<endl;
        return -1;
    }

    else
    return arr[front];

   }


};