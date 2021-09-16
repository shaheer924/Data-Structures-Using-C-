#include<iostream>
using namespace std;
void display();
int *binary_tree;
int main()
{
	int check,index;
	binary_tree=new int[8];
	for(int i=1;i<8;i++)
	{
		cin>>binary_tree[i];
		if(i==1)
		{
			continue;
		}
		check=i;
		index=check/2;
		while(binary_tree[check]<binary_tree[index])
		{
			if(index==0)
			{
				break;
			}
			swap(binary_tree[check],binary_tree[index]);
			check=index;
			index=check/2;	
		}
		display();
	}
}
void display()
{
	for(int i=1;i<8;i++)
	{
		cout<<binary_tree[i]<<" ";
	}
	cout<<"\n";
}
