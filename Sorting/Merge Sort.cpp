#include<iostream>
#include<windows.h>
using namespace std;
int *arr;
int size;
int merge_sort(int first,int last);
int merge(int first,int midpoint,int last);
void insertion_sort(int first,int last);
void display();


int main()
{
	cin>>size;
	arr=new int[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=rand()%100+1;
	}
	display();
	merge_sort(0,size);
	display();
}
int merge_sort(int first,int last)
{
	int midpoint;
	if((last-first) <= 5)
	{
		insertion_sort(first,last);
	}
	else
	{
		midpoint=(first+last)/2;
		merge_sort(first,midpoint);
		merge_sort(midpoint,last);
		merge(first,midpoint,last);
	}
}
int merge(int first,int midpoint,int last)
{
	int temp[last]={0},min1,min2;
	for(int i=0;i<midpoint-first;i++)
	{
		min1=arr[i];
		for(int j=i;j<midpoint;j++)
		{
			if(min1>arr[j])
			{
				min1=arr[j];
			}
		}
		
		min2=arr[midpoint+i];
		for(int j=midpoint;j<last;j++)
		{
			if(min2>arr[j])
			{
				min2=arr[j];
			}
		}
		if(min1<min2)
		{
			temp[i]=min1;
		}
		else{
			temp[i]=min2;
		}
	}
	for(int i=first,j=0;i<last,j=last-first;i++,j++)
	{
		arr[i]=temp[j];
	}
}
void insertion_sort(int first,int last)
{
	int j,k;
	for(int i=first;i<last;i++)
	{
		j=i-1;
		k=i;
		while(arr[j]>arr[k])
		{
			if(j==first || k==first)
			{
				break;
			}
			if(arr[k]<arr[j])
			{
				swap(arr[k],arr[j]);
			}
			j--;
			k--;
		}
	}
	display();
}
void display()
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
