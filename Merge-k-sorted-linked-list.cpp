// Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.

// Examples:

// Input:
   
// Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
// Explanation: The arr[] has 3 sorted linked list of size 3, 3, 1.
// 1st list: 1 -> 3 -> 7
// 2nd list: 2 -> 4 -> 8
// 3rd list: 9
// The merged list will be: 
    
// Input:
   
// Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
// Explanation: The arr[] has 3 sorted linked list of size 2, 1, 3.
// 1st list: 1 -> 3
// 2nd list: 8
// 3rd list: 4 -> 5 -> 6
// The merged list will be: 
    
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//Solution 1:-
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
  
  Node *merge (Node *head1,Node *head2)
  {
      Node *head=new Node(0);
      Node *tail=head;
      
      while(head1&&head2)
      {
          if(head1->data<=head2->data)
          {
              tail->next=head1;
              head1=head1->next;
              tail=tail->next;
              tail->next=NULL;
          }
          
          else
          {
              tail->next=head2;
              head2=head2->next;
              tail=tail->next;
              tail->next=NULL;
          }
      }
      
      if(head1)
      tail->next=head1;
      else
      tail->next=head2;
      
      return head->next;
  }
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node *head=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            head=merge(head,arr[i]);
        }
        return head;
        
    }
};

//Solution 2:-
class Solution {
  public:
  
  Node *merge(Node *head1,Node*head2)
  {
      Node *head=new Node(0);
      Node *tail=head;
      
      while(head1&&head2)
      {
          if(head1->data<=head2->data)
          {
              tail->next=head1;
              head1=head1->next;
              tail=tail->next;
              tail->next=NULL;
          }
          
          else
          {
              tail->next=head2;
              head2=head2->next;
              tail=tail->next;
              tail->next=NULL;
          }
      }
      
      if(head1)
      tail->next=head1;
      else
      tail->next=head2;
      
      return head->next;
  }
  
  Node *mergesort(vector<Node*>arr,int start,int end)
  {
      if(start>=end)
      return arr[start];
      
      int mid=start+(end-start)/2;
    //   mergesort(arr,start,mid);
    //   mergesort(arr,mid+1,end);
    
    Node *left= mergesort(arr,start,mid);
    Node *right= mergesort(arr,mid+1,end);
       
       // arr[start]=merge(arr[start],arr[mid+1]);
       
       return merge(left,right);
  }
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
       return mergesort(arr,0,arr.size()-1);
        //return arr[0];
        
    }
};


//Solution 3:-
class Solution {
  public:
  
  class compare
  {
      public:
      bool operator()(Node *a,Node *b)
      {
          return a->data > b->data;
          //always works in reverse phenomenon in case of heap;
      }
  };
  
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        //min heap creation;
        int k=arr.size();
    priority_queue<Node*,vector<Node*>,compare> p(arr.begin(),arr.end()); 
    
    Node *root=new Node(0);
    Node *tail=root;
    Node *temp;
    
    while(!p.empty())
    {
        temp=p.top();
        p.pop();
        tail->next=temp;
        tail=tail->next;
        if(temp->next)
        p.push(temp->next);
    }
    
    return root->next;
    
    }
};