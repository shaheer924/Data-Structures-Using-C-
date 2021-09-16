#include<iostream>
#define size 10
using namespace std;
class stacks{
	public:
		int *stack,top;
		stacks()
		{
			top=-1;
			stack=new int[size];
			for(int i=0;i<size;i++)
			{
				stack[i]=0;
			}
		}
		int push(int data)
		{
			if(top==size)
			{
				cout<<"Stack Is Full \n ";
				return -1;
			}
			top++;
			stack[top]=data;
		}
		int pop()
		{
			int ret=0;
			ret=stack[top];
			top--;
			return ret;
		}
		void display()
		{
			for(int i=top;i>=0;i--)
			{
				cout<<stack[i]<<"->";
			}
			cout<<"X\n";
		}
		bool isempty()
		{
			if(top==-1)
			{
				return true;
			}
			else {
				return false;
			}
		}
		bool isfull()
		{
			if(top==size-1)
			{
				return true;
			}
			else {
				return false;
			}
		}
};
void addition(int n1,int n2)
{
	stacks s1,s2,result;
	int a,arr[10]={-1},cnt=-1;
	cout<<"Stack 1\n";
	while(n1>0)
	{
		a=n1%10;
		n1=n1/10;
		cnt++;
		arr[cnt]=a;
	}
	for(int i=cnt;i>=0;i--)
	{
		//cout<<"Pushing Element : "<<arr[i]<<endl;
		s1.push(arr[i]);
	}
	s1.display();
	cout<<"\n";
	cnt=-1;
	cout<<"Stack 2\n";
	while(n2>0)
	{
		a=n2%10;
		n2=n2/10;
		cnt++;
		arr[cnt]=a;
	}
	for(int i=cnt;i>=0;i--)
	{
		//cout<<"Pushing Element : "<<arr[i]<<endl;
		s2.push(arr[i]);
	}
	s2.display();
	
	int carry=0,num1,num2,sum,final;
	cnt=-1;
	
	while(s1.top!=-1 || s2.top!=-1)
	{
		num1=s1.pop();
		num2=s2.pop();
		sum=num1+num2+carry;
		cout<<"\n"<<carry<<"Sum : "<<sum;
		final=sum%10;
		result.push(final);
		carry=sum/10;
	}
	cout<<"\n";
	result.display();
}
int main()
{
	addition(2001,7000);
}
