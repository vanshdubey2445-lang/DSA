#include<iostream>
using namespace std;

class maxheap
{
    int *arr;
    int size;
    int totalsize;
    public:

    maxheap(int n)
    {
        arr=new int[n];;
        size=0;
        totalsize=n;
    }

    void heapify(int index)
    {
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;

        if(left<size && arr[index]<arr[left])
        largest=left;

        if(right<size && arr[index]<arr[right])
        largest=right;

        if(largest!=index)
        {
            swap(arr[index],arr[largest]);
            heapify(largest);
        }
    }

    // insert into the heap

    void insert(int value)
    {
        if(size==totalsize)
        {
            cout<<"Heap Overflow"<<endl;
            return;
        }

        arr[size]=value;
        int index=size;
        size++;

        //compare child with its parent
        while(index>0 && arr[(index-1)/2] < arr[index])
        {
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        };

        cout<<arr[index]<<" is inserted into the heap"<<endl;
    }

    void Delete()
    {
        if(size==0)
        {
            cout<<"Heap underflow"<<endl;
            return ;
        }

        cout<<arr[0]<<" is deleted from the heap"<<endl;
        arr[0]=arr[size-1];
        size--;

        if(size==0)
        return;

        heapify(0);
    }

    void print()
    {
        for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";

        cout<<endl;
    }


};

int main()
{
    maxheap h1(2);
    h1.insert(4);
    h1.insert(14);
    h1.insert(11);
    h1.Delete();
    h1.print();
}