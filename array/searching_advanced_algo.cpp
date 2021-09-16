#include<iostream>
using namespace std;
int *arr,pivot=0;
int searching(int data,int f,int l);
void display(int f,int l);
int main()
{
	arr=new int[10];
	for(int i=0;i<10;i++)
	{
		cin>>arr[i];
	}
	int a;
	cin>>a;
	searching(a,0,10);
}
int searching(int data,int f,int l)
{
	int i=f,j=l-1,min,max,k=i,n=j;
	pivot=(l+f)/2;
	if((l-f)<=5)
	{
		for(int m=f;m<l;m++)
		{
			if(arr[m]==data)
			{
				cout<<"Value Found at index : "<<m<<"\n";
			}
		}
	}
	while(arr[i]!=arr[pivot])
	{
		while(arr[i]>arr[pivot])
		{
			i++;
		}
		while(arr[j]<arr[pivot])
		{
			j--;
		}
		swap(arr[n],arr[k]);
	}
	display(f,l);
	if(data>arr[pivot])
	{
		searching(data,pivot,l);
	}
	else if(data<arr[pivot])
	{
		searching(data,f,pivot);
	}
}
void display(int f,int l)
{
	for(int i=f;i<l;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
