#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

class Queue
{
    Node *front;
    Node *rear;
    public:
    Queue()
    {
        front=rear=NULL;
    }

    bool isempty()
    {
        return front==NULL;
    }

    void push(int x)
    {
        if(isempty())
        {
            cout<<"Pushed "<<x<<" into the queue\n";
            front=new Node(x);
            rear=front;
            return;
        }

        else
        {
            rear->next=new Node(x);
            if(rear->next==NULL)
            {
                cout<<"Queue is overflow\n";
                return;
            }
            cout<<"Pushed "<<x<<" into the queue\n";
            rear=rear->next;

        }
    }

    void pop()
    {
        if(isempty())
        {
            cout<<"Queue underflow\n";
            return ;
        }

        else{

            cout<<"Popped "<<front->data<<" out of the queue\n";
            Node *temp= front;
            front=front->next;
            delete temp;
        }
    }

    int start()
    {
        if(isempty())
        {
            cout<<"Queue is empty\n";
            return -1;
        }

        else{

            return front->data;
        }
    }

};
