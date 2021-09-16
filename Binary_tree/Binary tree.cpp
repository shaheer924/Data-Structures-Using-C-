#include<iostream>
#include<windows.h>
using namespace std;
class binary_tree{
	public:
		int *binary_t,size,i;
		binary_tree()
		{
			binary_t=new int[100];
			size=1,i=0;
		}
		int push(int data)
		{
			i++;
			int check,index;
			binary_t[i]=data;
			if(i==1)
			{
				return 1;		
			}
			index=i;
			check=index/2;
			while(binary_t[check]>binary_t[index])
			{
				if(check==0)
				{
					break;
				}
				swap(binary_t[check],binary_t[index]);
				index=check;
				check=index/2;
			}
			size++;
			display();
		}
		int pop()
		{
			binary_t[1]=0;
			int index=1,c1=0,c2=0;
			c1=2*index;
			c2=2*index+1;
			while(binary_t[c1]!=0 || binary_t[c2]!=0)
			{
				if(binary_t[c1]<binary_t[c2])
				{
					swap(binary_t[index],binary_t[c1]);
					index=c1;
					c1=2*index;
					c2=2*index+1;
				}
				else{
					swap(binary_t[index],binary_t[c2]);
					index=c2;
					c1=2*index;
					c2=2*index+1;
				}
			}
		}
		void display()
		{
			for(int i=1;i<=size;i++)
			{
				cout<<binary_t[i]<<" ";
			}
			cout<<"\n";
		}
};
int main()
{
	int a;
	binary_tree bt;
	for(int i=0;i<7;i++)
	{
		cin>>a;
		bt.push(a);	
	}
	bt.display();
	cout<<endl;
	bt.pop();
	cout<<endl;
	bt.display();
}
