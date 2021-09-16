#include<iostream>
using namespace  std;

class Heap
{
	public:
		
	int *arr;
	int capacity;
	int size;
	
	Heap()
	{
		capacity=20;
		arr=new int[capacity];
		arr[20]=0;
		size=0;
	}
	int parent(int i)
	{
		if(i<0 || i>=size)
		return -1;
		return (i-2)/2;
	}
	
	int leftchild(int i)
	{
		int left=2*i+1;
		if(left>=size)
		return -1;
		return left;
	}
	
	int rightchild(int i)
	{
		int right=2*i+2;
		if(right>=size)
		return -1;
		return right;
	}
	
	void insert(int k)
	{
		int i;
		if(size==capacity)
		{
			cout<<"Heap Full";
			return;
		}
		size++;
		i=size-1;
		arr[i]=k;
		while(i!=0 && arr[i]<arr[parent(i)])
		{
			swap(arr[i],arr[(parent(i))]);
			i=i-2;
		}
	}
	
	void heapsort(int a[], int n)
	{
		for(int i=n/2-1;i>=0;i--)
		{
			maxheapify(arr,n,i);	
		}
	
		for(int i=n-1;i>=0;i--)
		{
			swap(arr[0],arr[i]);
			maxheapify(arr,i,0);
		}
	}

	void maxheapify(int arr[],int n, int i)
	{
		int largest=i;
		int l=2*i+1;
		int r=2*i+2;
		
		if(l<n && arr[l]>arr[largest])//if left child is greater than root
		largest=l;
			
		if(r<n && arr[r]>arr[largest])//if right child is greater than root
		largest=r;
		
		if(largest!=i){
			swap(arr[i],arr[largest]);
			maxheapify(arr, n,largest);
		}	
	}
	
	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<arr[i]<<" ";
		}
	}
};

int main()
{
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	Heap h;
	for(int i=0;i<10;i++)
	{
	h.insert(a[i]);
	}
	h.heapsort(a,10);
	h.display();	
}
