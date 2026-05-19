#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next, *prev;

    Node(int value)
    {
        data=value;
        next=NULL;
        prev=NULL;
    }
};

class Dequeue
{
    Node *front, *rear;
    public:

    Dequeue()
    {
        front=rear=NULL;
    }

    void pushfront(int x)
    {
        if(front==NULL)
        {
            front=rear=new Node(x);
            cout<<"Pushed "<<x<<" in front of dequeue\n";
            return ;
        }

        else
        {
            Node *temp= new Node(x);
            temp->next=front;
            front->prev=temp;
            front=temp;
            cout<<"Pushed "<<x<<" in front of dequeue\n";
            return ;
        }
    }

    void pushback(int x)
    {
        if(front==NULL)
        {
            front=rear=new Node(x);
            cout<<"Pushed "<<x<<" in back of dequeue\n";
            return ;
        }

        else
        {
            Node *temp=new Node(x);
            rear->next=temp;
            temp->prev=rear;
            rear=temp;
            cout<<"Pushed "<<x<<" in back of dequeue\n";
            return ;
        }
    }

    void popfront()
    {
        if(front==NULL)
        {
            cout<<"Dequeue underflow\n"; 
            return ;
        }

        else
        {
            Node *temp=front;
            cout<<"Popped "<<temp->data<<" from the front of dequeue\n";
            front=front->next;
            delete temp;

            if(front)
            front->prev=NULL;

            else
            rear=NULL;
        }

    }

    void popback()
    {
        if(front==NULL)
        {
            cout<<"Dequeue underflow\n";
            return ;
        }

        else
        {
            Node *temp=rear;
            cout<<"Popped "<<temp->data<<" from the back of dequeue\n";
            rear=rear->prev;
            delete temp;

            if(rear)
            rear->prev=NULL;

            else
            front=NULL;
        }
    }

    int start()
    {
        if(front==NULL)
        return -1;

        else
        {
            return front->data;
        }
    }

    int end()
    {
        if(front==NULL)
        return -1;

        else
        {
            return rear->data;
        }
    }
};

int main()
{
    //examples;
    Dequeue d;
    d.pushfront(7);
    d.pushback(790);
    d.pushfront(56);
    d.pushfront(79);
    d.pushfront(37);
    d.popfront();
    d.popback();
    cout<<d.start()<<endl;
    cout<<d.end()<<endl;


}