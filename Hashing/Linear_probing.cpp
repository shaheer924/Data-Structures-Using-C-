#include<iostream>
using namespace std;
int size=0;
class hashing{
public:
	int *hashtable,index;
	hashing()
	{
		hashtable=new int[size];
		for(int i=0;i<size;i++)
		{
			hashtable[i]=0;
		}
	}
	void insertion(int data)
	{
		index=data%size;
		while(hashtable[index]!=0)
		{
			index++;
			if(index>size-1)
			{
				cout<<"Hash Table Is Full No Place is Vacant \n";
				break;
			}	
		}
		hashtable[index]=data;
	}
	void searching(int data)
	{
		index=data%size;
		while(hashtable[index]!=data)
		{
			index++;
			if(index>size-1)
			{
				cout<<"Data Not Found \n";
				break;
			}
		}
		if(hashtable[index]==data)
			cout<<"At Index : "<<index<<"\nFound Data : "<<hashtable[index]<<"\n";
	}
	void delete_data(int data)
	{
		index=data%size;
		while(hashtable[index]!=data)
		{
			index++;
			if(index>size-1)
			{
				cout<<"Data Not Found \n";
				break;
			}
		}
		if(hashtable[index]==data)
		{
			hashtable[index]=0;
		}
	}
	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<"Index "<<i+1<<"\n"<<"Value : "<<hashtable[i]<<"\n";
		}
	}
};
int main()
{
	int arr[]={50,700,76,85,92,73,101};
	size=sizeof(arr)/sizeof(int);
	hashing h;
	for(int i=0;i<size;i++)
	{
		h.insertion(arr[i]);
	}
	h.display();
	cout<<endl<<endl;
	h.searching(85);
	cout<<endl<<endl;
	h.delete_data(85);
	cout<<endl<<endl;
	h.display();
}
