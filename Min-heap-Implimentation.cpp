#include<iostream>
using namespace std;

class minheap
{
    int *arr;
    int size;
    int totalsize;
    public:

    minheap(int n)
    {
        arr=new int[n];;
        size=0;
        totalsize=n;
    }

    void heapify(int index)
    {
        int smallest=index;
        int left=2*index+1;
        int right=2*index+2;

        if(left<size && arr[left]<arr[smallest])
        smallest=left;

        if(right<size && arr[right]<arr[smallest])
        smallest=right;

        if(smallest!=index)
        {
            swap(arr[index],arr[smallest]);
            heapify(smallest);
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
        while(index>0 && arr[(index-1)/2] > arr[index])
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
    minheap h1(6);
    h1.insert(12);
    h1.insert(2);
    h1.insert(21);
    h1.insert(10);
    h1.insert(23);
    h1.insert(19);
    h1.Delete();
    h1.print();
}