#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left , *right;
    Node(int value)
    {
        data=value;
        left=right=NULL;
    }
};

int main()
{
    queue<Node*>q;
    int x,l,r;
    cout<<"Enter the root element: ";
    cin>>x;

    Node *root=new Node(x);
    q.push(root);

    while(!q.empty())
    {
        Node *temp= q.front();
        q.pop();
        cout<<"\nEnter the left child of "<<temp->data<<" :";
         cin>>l;
        cout<<"\nEnter the right child of "<<temp->data<<" :";
        cin>>r;
        
        if(l!=-1)
        {
            temp->left=new Node(l);
            q.push(temp->left);
        }

        if(r!=-1)
        {
            temp->right=new Node(r);
            q.push(temp->right);
        }
    }

}