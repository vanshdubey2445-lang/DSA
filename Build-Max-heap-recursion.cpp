#include<iostream>
using namespace std;

void heapify(int arr[],int index,int size)
{
    int largest=index;
    int left= 2*index+1;
    int right=2*index+2;

    if(left<size && arr[left]>arr[largest])
    largest=left;
    if(right<size && arr[right]>arr[largest])
    largest=right;

    if(largest!=index)
    {
        swap(arr[index],arr[largest]);
        heapify(arr,largest,size);
    }


}

void buildmaxheap(int arr[],int n)
{
    //step down
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,i,n);
    }
}

void printheap(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";      

    cout<<endl; 
}

int main()
{
    int arr[]={10,3,8,9,5,13,18,14,11,70};
     buildmaxheap(arr,10);
     printheap(arr,10);

}